/*
License: GPL 
Owner: Marcin Brysz
Contact: unemployed81@gmail.com / bryszmarcin@gmail.com
Version: 1.3 Beta
*/
#include "myviewwidget.h"

MyViewWidget::MyViewWidget( Ui_ViewWidget* viewWidget, const int& scaleCount,
  const bool& reset, QObject* parent )
  : QObject( parent ),
    mViewWidget( viewWidget ),
    mScaleCount( scaleCount ),
    mReset( reset ),
    mNeedSave( false )
{
  
}

MyViewWidget::MyViewWidget( boost::shared_ptr< Ui_ViewWidget > viewWidget,
  const int& scaleCount, const bool& reset, QObject* parent )
  : QObject( parent ),
    mViewWidget( viewWidget ),
    mScaleCount( scaleCount ),
    mReset( reset ),
    mNeedSave( false)
{
  
}

MyViewWidget::~MyViewWidget()
{
  
}

void MyViewWidget::setReset( const bool& reset )
{
  mReset = reset;
}

void MyViewWidget::setViewWidget( Ui_ViewWidget* viewWidget, const bool& needSave )
{
  mViewWidget.reset( viewWidget );
  mNeedSave = needSave;
}

void MyViewWidget::setScaleCount( const int& scaleCount )
{
  mScaleCount = scaleCount;  
}

void MyViewWidget::setFileName( const QString& filename )
{
  mFileName = filename;
}

void MyViewWidget::needSave()
{
  mNeedSave = true;
  emit changeTabTitle();
}

void MyViewWidget::setNeedSave( const bool& pNeedSave )
{
  mNeedSave = pNeedSave;
}
