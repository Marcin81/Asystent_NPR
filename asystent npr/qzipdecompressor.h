/*
 *  QZipDecompressor.h
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
#ifndef QZIPDECOMPRESSOR_H
#define QZIPDECOMPRESSOR_H
#include "qmydecompressor.h"

class QZipDecompressor : public QMyDecompressor
{
 	virtual bool decompressToFiles();
public:
	QZipDecompressor( const QString& pathSrc, const QString& ArchiveFileName, const QString& pathDest, QObject* parent = 0 );
	
	virtual ~QZipDecompressor();
};

#endif //QZIPDECOMPRESSOR_H
