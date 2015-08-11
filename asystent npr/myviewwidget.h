/*
License: GPL 
Owner: Marcin Brysz
Contact: unemployed81@gmail.com / bryszmarcin@gmail.com
Version: 1.3 Beta
*/
#ifndef MYVIEWWIDGET_H
#define MYVIEWWIDGET_H
#include <boost/utility.hpp>
#include <boost/shared_ptr.hpp>
#include "ui_viewwidget.h"
#include <QtCore/QString>
#include <QtCore/QObject>

class MyViewWidget : public QObject, private boost::noncopyable
{
  Q_OBJECT
  boost::shared_ptr< Ui_ViewWidget > mViewWidget;
  int mScaleCount;
  bool mReset;
  QString mFileName;
  bool mNeedSave;
public:
  MyViewWidget( Ui_ViewWidget* viewWidget, const int& scaleCount, const bool& reset, QObject* parent = 0 );
  MyViewWidget( boost::shared_ptr< Ui_ViewWidget > viewWidget, const int& scaleCount, const bool& reset, QObject* parent = 0 );
  ~MyViewWidget();
  
  boost::shared_ptr< Ui_ViewWidget > getViewWidget() { return mViewWidget; }
  int getScaleCount() const { return mScaleCount; }
  bool getReset() const { return mReset; }
  QString getFileName() const { return mFileName; }
  
  void setReset( const bool& reset );
  void setViewWidget( Ui_ViewWidget* viewWidget, const bool& pNeedSave  = false );
  void setScaleCount( const int& scaleCount );
  void setFileName( const QString& filename );
  
  bool isNeedSave() const { return mNeedSave; }
  void setNeedSave( const bool& pNeedSave );
public slots:
  void needSave();
signals:
  void changeTabTitle();
};

#endif // MYVIEWWIDGET_H
