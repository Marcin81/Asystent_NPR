/*
License: GPL 
Owner: Marcin Brysz
Contact: unemployed81@gmail.com / bryszmarcin@gmail.com
Version: 1.3 Beta
*/
#ifndef QMYDECOMPRESSOR_H
#define QMYDECOMPRESSOR_H
#include <QtCore/QString>
#include <QtCore/QByteArray>
#include <QtCore/QThread>
#include <boost/utility.hpp>

class QMyDecompressor : public QThread, private boost::noncopyable
{
  Q_OBJECT
protected:
	QString mPathSrc;
  QString mPathDest;
	QString mArchiveFileName;
 	virtual bool decompressToFiles() = 0;
public:
	QMyDecompressor( const QString& pathSrc, const QString& ArchiveFileName, const QString& pathDest, QObject* parent = 0 );
	
	virtual ~QMyDecompressor();
  
  void setDestPath( const QString& pathSrc );
  void setSrcPath( const QString& pathDest );
  void setArchiveFileName( const QString& ArchiveFileName );
  
  QString getArchiveFileName() const { return mArchiveFileName; }
  QString getSrcPath() const { return mPathSrc; }
  QString getDestPath() const { return mPathDest; }
  
protected:
	virtual void run();
signals:
  void decompressFinishSignal();
  void showErrorSignal();
};

#endif // QMYDECOMPRESSOR_H
