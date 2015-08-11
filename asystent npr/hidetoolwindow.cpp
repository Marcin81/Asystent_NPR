/*
License: GPL 
Owner: Marcin Brysz
Contact: unemployed81@gmail.com / bryszmarcin@gmail.com
Version: 1.3 Beta
*/
#include "hidetoolwindow.h"
#include <QtGui/QScrollArea>
#include <QtGui/QGridLayout>
#include "dragwidget.h"
#include <boost/foreach.hpp>
#include <QtGui/QtGui>

HideToolWindow::HideToolWindow( const std::list< boost::tuple< QString, QString, QString > >& pointNames,
  const QString& title, const QSize& size, const QPoint& pos, QWidget* parent, Qt::WindowFlags f )
  : QWidget( parent, f ),
    mFont( "Verdana", 14 ),
    mTitle( title )
{
  mFont.setStyleStrategy( QFont::PreferQuality );
  mFont.setStyle( QFont::StyleNormal );
  mFont.setWeight( QFont::Normal );
  mFont.setBold( false );
  mFont.setItalic( false );
  drag = new DragWidget( this );
  typedef boost::tuple< QString, QString, QString > Tup3;

  #ifndef Q_WS_MAC
  mFont.setPointSize(8);
  #endif
  BOOST_FOREACH( Tup3 tup , pointNames )
    drag->addLabels( tup.get<0>(), tup.get<1>(), tup.get<2>(), mFont );

  const int margin = 70;
  setMaximumSize( size.width() + margin, size.height() + margin );
  resize( size.width() + margin, size.height() + margin);
  mHlayout = new QHBoxLayout;
  mArea = new QScrollArea( this );
  drag->resize( size );

  mHlayout->addWidget( mArea );

  mArea->setWidget( drag );
  mArea->setFrameShape(QFrame::NoFrame);
  drag->setFrameShape(QFrame::NoFrame);
  setLayout(mHlayout);
  const std::string str = mTitle.toStdString();
  setWindowTitle( QObject::trUtf8( str.c_str() ) );
  move( pos );
}

HideToolWindow::~HideToolWindow()
{

}

void HideToolWindow::updateTranslation()
{  
  const std::string str = mTitle.toStdString();
  setWindowTitle( QApplication::translate( "MainWindow", str.c_str(), 0, QApplication::UnicodeUTF8) );
  drag->updateTranslation();
}

void HideToolWindow::setVisible( bool on )
{
  QWidget::setVisible( on );
  emit hideWidget( on );
}

