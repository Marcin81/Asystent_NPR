/*
License: GPL 
Owner: Marcin Brysz
Contact: unemployed81@gmail.com / bryszmarcin@gmail.com
Version: 1.3 Beta
*/
#ifndef MOVEABLEPOINT_H
#define MOVEABLEPOINT_H

#include <QtGui/QtGui>
#include <QtGui/QGraphicsItem>
#include "edge.h"

QT_BEGIN_NAMESPACE
class QGraphicsSceneMouseEvent;
QT_END_NAMESPACE

class MoveablePoint : public QObject, public QGraphicsItem
{
  Q_OBJECT
public:
   template < typename TEdge >
   static MoveablePoint create( QGraphicsScene* scene, const QRectF& area,
                 boost::shared_ptr<QPointF> nowPosition,
                 boost::shared_ptr<QPointF> last_Point,
                 boost::shared_ptr<QPointF> next_Point,
                 const QColor& pointColor = Qt::yellow,
                 const QColor& pointColorBorderColor = Qt::darkYellow,
                 const QColor& lineColor = Qt::black,
                 const QColor& graphLineColor = Qt::darkRed,
                 const int minWayToLastPoint = 30 )
   {
      MoveablePoint mp( scene, area, nowPosition, last_Point, next_Point,
                    pointColor, pointColorBorderColor, lineColor,
                    graphLineColor, graphLineColor, minWayToLastPoint );
      mp.addEdges< TEdge >( scene );
      return mp;
   }

   template < typename TEdge >
   static MoveablePoint* createPointer( QGraphicsScene* scene, const QRectF& area,
                 boost::shared_ptr<QPointF> nowPosition,
                 boost::shared_ptr<QPointF> last_Point,
                 boost::shared_ptr<QPointF> next_Point,
                 const QColor& pointColor = Qt::yellow,
                 const QColor& pointColorBorderColor = Qt::darkYellow,
                 const QColor& lineColor = Qt::black,
                 const QColor& graphLineColor = Qt::darkRed,
                 const int minWayToLastPoint = 30 )
   {
      MoveablePoint* mp = new MoveablePoint( scene, area, nowPosition, last_Point,
                                             next_Point, pointColor,
                                             pointColorBorderColor, lineColor,
                                             graphLineColor, minWayToLastPoint );
      mp->addEdges< TEdge >( scene );
      return mp;
   }

  virtual ~MoveablePoint();
protected:
  QColor pointColorBorderColor;
  QColor pointColor;
  QColor lineColor;
  QColor graphLineColor;

  int minWayToLastPoint;

  boost::shared_ptr<QPointF> lastPoint;
  boost::shared_ptr<QPointF> position;
  boost::shared_ptr<QPointF> nextPoint;

  EdgeBase* beginEdge;
  EdgeBase* endEdge;

  QRectF areaRect;
  int mDay;
public:
  EdgeBase* getBeginEdge() { return beginEdge; }
  EdgeBase* getEndEdge() { return endEdge; }

  void setPointColor( const QColor& pointColor );
  void setLineColor( const QColor& lineColor );
  void setGraphLineColor( const QColor& graphLineColor );
  void setPointColorBorderColor( const QColor& pointColorBorderColor );

  void setMinWayToLastPoint( const int minWayToLastPoint );
  const int getMinWayToLastPoint() const { return minWayToLastPoint; }

  const QColor getPointColor() const { return pointColor; }
  const QColor getLineColor() const { return lineColor; }
  const QColor getGraphLineColor() const { return graphLineColor; }
  const QColor getPointColorBorderColor() const { return pointColorBorderColor; }

  const boost::shared_ptr<QPointF> getPreviewPoint() const { return lastPoint; }
  const boost::shared_ptr<QPointF> getPointPosition() const { return position; }
  const boost::shared_ptr<QPointF> getNextPoint() const { return nextPoint; }

  void setPreviewPoint( const boost::shared_ptr<QPointF> point );
  void setPointPosition( const boost::shared_ptr<QPointF> point );
  void setNextPoint( const boost::shared_ptr<QPointF> point );

  void alignDownRight( QPointF alignPoint, QPointF pos );
  float getTemp() const;
  int getDay() const { return mDay; }
protected:
  QRectF boundingRect() const;
  QPainterPath shape() const;

  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

  void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
  void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
  void mousePressEvent( QGraphicsSceneMouseEvent* event );

   void updateToolTip();
   void updateDay();
   inline const int getStepWay() const;

   QString getTempSuppfix() const { return QString( "˚C" ); }


  template < typename TEdge >
  void addEdges( QGraphicsScene* scene )
  {
    beginEdge = new TEdge( lastPoint, position, graphLineColor );
    endEdge =  new TEdge( position, nextPoint, graphLineColor );

    scene->addItem( beginEdge );
    scene->addItem( endEdge );
  }

   MoveablePoint( QGraphicsScene* scene, const QRectF& area,
                 boost::shared_ptr<QPointF> nowPosition,
                 boost::shared_ptr<QPointF> last_Point,
                 boost::shared_ptr<QPointF> next_Point,
                 const QColor& pointColor = Qt::yellow,
                 const QColor& pointColorBorderColor = Qt::darkYellow,
                 const QColor& lineColor = Qt::black,
                 const QColor& graphLineColor = Qt::darkRed,
                 const int minWayToLastPoint = 30 );
signals:
  void deletePointSignal();
  void stateChange();
};

#endif // MOVEABLEPOINT_H
