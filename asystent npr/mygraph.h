/*
License: GPL 
Owner: Marcin Brysz
Contact: unemployed81@gmail.com / bryszmarcin@gmail.com
Version: 1.3 Beta
*/
#ifndef MYGRAPH_H
#define MYGRAPH_H

#include <QtGui/QGraphicsView>
#include "moveablepoint.h"
#include <QtCore/QList>
#include <QtGui/QGraphicsScene>
#include "mygraphbase.h"
#include <boost/tuple/tuple.hpp>
#include <cmath>

class Mygraph : public MyGraphBase
{
  Q_OBJECT
public:
  Mygraph( QWidget* parent = 0 );
  virtual ~Mygraph();

  void setTemperatureObjectName( const QStringList& objectName );
  const QStringList getTemperatureObjectName() const { return temperatureStr; }

  void save( QDataStream& ds );
  void load( QDataStream& ds );

  float getTemperature() const;

  QList< MoveablePoint* > getPoints() const { return points; }
  const int getStepWay() const
  {
  const float step = minWayToLastPoint / 3;
  return std::ceil( step );
  }
  void clear();
protected:
  QList< MoveablePoint* > points;
  QStringList temperatureStr;

  void drawBackground(QPainter *painter, const QRectF &rect);
  void dragEnterEvent( QDragEnterEvent* event );
  void dragMoveEvent(QDragMoveEvent *event);
  void dropEvent( QDropEvent * event );
  void eraseAndCleanUp( MoveablePoint* p );
  void addPoint( const QPointF& mypos, const QColor& pointColor, const QColor& pointColorBorderColor );

  QString getTempSuppfix() const { return QString( "˚C" ); }

  boost::tuple< QColor /* pointColor */, QColor /*pointColorBorderColor */> getColors( const QString& objName ) const;


protected slots:
  void deletePointSlot();
  void graphChangeSlot();
};

#endif // MYGRAPH_H
