/*
License: GPL 
Owner: Marcin Brysz
Contact: unemployed81@gmail.com / bryszmarcin@gmail.com
Version: 1.3 Beta
*/
#ifndef HIDETOOLWINDOW_H
#define HIDETOOLWINDOW_H
#include <QtGui/QWidget>
#include <QtGui/QFont>
#include "dragwidget.h"
#include <boost/tuple/tuple.hpp>
#include <list>

class Drag;
class QHBoxLayout;
class QScrollArea;

class HideToolWindow : public QWidget
{
  Q_OBJECT
  QFont mFont;
  QString mTitle;
  DragWidget* drag;
  QHBoxLayout *mHlayout;
  QScrollArea* mArea;
public:
  HideToolWindow( const std::list< boost::tuple< QString, QString, QString > >& pointNames,
    const QString& title, const QSize& size, const QPoint& pos, QWidget* parent = 0, Qt::WindowFlags f = 0 );

  virtual ~HideToolWindow();

public slots:
  virtual void setVisible( bool on );
  void updateTranslation();
signals:
  void hideWidget( bool on );
};

#endif // HIDETOOLWINDOW_H
