/*
 *  QMyDecompressor.cpp
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
#include "qmydecompressor.h"
#include <QtCore/QDir>
#include <QtCore/QFile>
#include <QtCore/QDebug>

QMyDecompressor::QMyDecompressor( const QString& pathSrc, const QString& ArchiveFileName, const QString& pathDest, QObject* parent )
  : QThread( parent ), 
    mPathSrc( pathSrc ),
  	mArchiveFileName( ArchiveFileName ),
    mPathDest( pathDest )
{
	
}

QMyDecompressor::~QMyDecompressor()
{

}

void QMyDecompressor::run()
{
  const bool isOK = decompressToFiles();
  if ( isOK )
    emit decompressFinishSignal();
  else 
    emit showErrorSignal();
}

void QMyDecompressor::setDestPath( const QString& pathSrc )
{
  mPathSrc = pathSrc;
}

void QMyDecompressor::setSrcPath( const QString& pathDest )
{
  mPathDest = pathDest;
}

void QMyDecompressor::setArchiveFileName( const QString& ArchiveFileName )
{
  mArchiveFileName = ArchiveFileName;
}

