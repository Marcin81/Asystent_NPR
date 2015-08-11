/*
 *  QTarBZip2Decompressor.cpp
 *  Asystent NPR
 *
 *  Created by Marcin Brysz on 09-10-01.
 *  Copyright 2009 Marcin Brysz. All rights reserved.
 *
 */
/*
License: GPL 
Owner: Marcin Brysz
Contact: unemployed81@gmail.com / bryszmarcin@gmail.com
Version: 1.3 Beta
*/
#include "qtarbzip2decompressor.h"
#include <QtCore/QDir>
#include <QtCore/QFile>
#include <QtCore/QDebug>
#include <libtar.h>
#include <bzlib.h>

//#include <sys/types.h>
//#include <sys/stat.h>
#include <fcntl.h>
//#include <stdlib.h>
//#include <unistd.h>
#include <boost/scoped_array.hpp>
    
QTarBZip2Decompressor::QTarBZip2Decompressor( const QString& pathSrc, const QString& ArchiveFileName, const QString& pathDest, QObject* parent )
  : QMyDecompressor( pathSrc, ArchiveFileName, pathDest, parent ) 
{
	
}

QTarBZip2Decompressor::~QTarBZip2Decompressor()
{

}

bool QTarBZip2Decompressor::decompressToFiles()
{
	QString root = mPathSrc + QDir::separator()  + mArchiveFileName;
  const std::string tbz2Filename = root.toStdString();
  const std::string extractTo = mPathDest.toStdString();

  FILE *tbz2File = fopen(tbz2Filename.c_str(), "rb");
  int bzError;

 const int BUF_SIZE = 10000;
// char* buf = new char[BUF_SIZE];
 boost::scoped_array< char > buf ( new char[BUF_SIZE] );
  BZFILE *pBz = BZ2_bzReadOpen(&bzError, tbz2File, 0, 0, 0, 0);

  if ( bzError != BZ_OK ) {
    qDebug() << "bzError != BZ_OK";
    BZ2_bzReadClose( &bzError, pBz );
    //delete[] buf;
    return false;
  }

  const QString tarFilename = root.section( ".bz2", 0, 0 );
  QFile tbz2FileTmp( tarFilename );
  if( !tbz2FileTmp.open( QIODevice::WriteOnly ) ) {
    BZ2_bzReadClose( &bzError, pBz );
    //delete[] buf;
    return false;
  }
  
  bzError = BZ_OK;
  while ( bzError == BZ_OK ) {
    ssize_t bytesRead = BZ2_bzRead ( &bzError, pBz, buf.get(), BUF_SIZE );
    if ( bzError == BZ_OK )
//      fwrite (buf , 1 , bytesRead , tbz2FileTmp );
    tbz2FileTmp.write( buf.get(), bytesRead );
  }
  BZ2_bzReadClose ( &bzError, pBz );

  const std::string tarFilename2 = tarFilename.toStdString();
 TAR *pTar;
 tar_open(&pTar, const_cast< char* > ( tarFilename2.c_str() ), NULL, O_RDONLY, 0644, TAR_GNU);
 tar_extract_all( pTar, const_cast< char* > ( extractTo.c_str()  ) );
 close(tar_fd(pTar));
 QFile::remove( tarFilename );
 //delete[] buf;

return true;
}


