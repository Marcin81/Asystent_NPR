/*
License: GPL 
Owner: Marcin Brysz
Contact: unemployed81@gmail.com / bryszmarcin@gmail.com
Version: 1.3 Beta
*/
#ifndef QTARBZIP2DECOMPRESSOR_H
#define QTARBZIP2DECOMPRESSOR_H
#include "qmydecompressor.h"

class QTarBZip2Decompressor : public QMyDecompressor
{
protected:
 	virtual bool decompressToFiles();
public:
	QTarBZip2Decompressor( const QString& pathSrc, const QString& ArchiveFileName, const QString& pathDest, QObject* parent = 0 );
	
	virtual ~QTarBZip2Decompressor();
};

#endif // QTARBZIP2DECOMPRESSOR_H
