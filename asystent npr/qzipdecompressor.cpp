/*
 *  QZipDecompressor.cpp
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
#include "qzipdecompressor.h"
#include <QtCore/QDir>
#include <QtCore/QFile>
#include <zzip/lib.h>
#include <QtCore/QDebug>

QZipDecompressor::QZipDecompressor( const QString& pathSrc, const QString& ArchiveFileName, const QString& pathDest, QObject* parent )
  : QMyDecompressor( pathSrc, ArchiveFileName, pathDest, parent ) 
{
	
}

QZipDecompressor::~QZipDecompressor()
{

}

bool QZipDecompressor::decompressToFiles()
{
	const QString root = mPathSrc + QDir::separator()  + mArchiveFileName;
	const std::string strFName = root.toStdString();

	ZZIP_DIR* dir = zzip_dir_open( strFName.c_str(), 0);
  if( !dir )
		return false;

	
	ZZIP_DIRENT dirent;
	QString lastFileName;
	
	do {
		const int ret = zzip_dir_read( dir, &dirent );
		if( ret == 0 ) {
			zzip_dir_close( dir );
			return ( lastFileName == QString( dirent.d_name ) ) ? true : false;
		}
		const QString path = mPathDest + QDir::separator() + QString( dirent.d_name );

		ZZIP_FILE* fp = zzip_file_open(dir, dirent.d_name, 0);
		
		if (fp) {
			if( lastFileName == QString( dirent.d_name ) )
				break;
			lastFileName = dirent.d_name;
			const std::size_t bufSize = dirent.st_size;
			// Katalog czy plik? katalog kończy się na QDir::separator()
			if( lastFileName.endsWith( QDir::separator() ) ) {
				QDir mydir( mPathDest );
				if( !mydir.mkpath( path ) ) {
					zzip_dir_close( dir );
					return false;
				}
				
			} else { //plik
				char buf[bufSize];
				const zzip_ssize_t len = zzip_file_read(fp, buf, bufSize);
				if( len ) {
          QFile file( path );
          file.open( QIODevice::WriteOnly );
          file.write(buf, len);
					file.close();
				} // if
				zzip_file_close(fp);
			} // else
		} else {
			break;
		} // else
	} while (true);
	zzip_dir_close( dir );
	return true;
}
