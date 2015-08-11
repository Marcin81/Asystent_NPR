/*
License: GPL 
Owner: Marcin Brysz
Contact: unemployed81@gmail.com / bryszmarcin@gmail.com
Version: 1.3 Beta
*/
#include "moveablepoint.h"

#include <QtGui/QGraphicsScene>
#include <QtGui/QWheelEvent>
#include <cmath>
#include <QtCore/QLineF>

MoveablePoint::~MoveablePoint()
{

}

MoveablePoint::MoveablePoint( QGraphicsScene* scene, const QRectF& area,
                 boost::shared_ptr<QPointF> nowPosition,
                 boost::shared_ptr<QPointF> last_Point,
                 boost::shared_ptr<QPointF> next_Point,
                 const QColor& pointColor,
                 const QColor& pointColorBorderColor,
                 const QColor& lineColor,
                 const QColor& graphLineColor,
                 const int minWayToLastPoint )
  : lastPoint( last_Point ),
    position( nowPosition ),
    nextPoint( next_Point ),
    areaRect( area ),
    mDay( 0 )
{
  Q_UNUSED( scene );
  if( lastPoint.get() && ( lastPoint.get()->y() > 0 ) )
    lastPoint.get()->setY( lastPoint.get()->y() * (-1) );
  if( position.get() && ( position.get()->y() > 0 ) )
    position.get()->setY( position.get()->y() * (-1) );
  if( nextPoint.get() && ( nextPoint.get()->y() > 0 ) )
    nextPoint.get()->setY( nextPoint.get()->y() * (-1) );

  MoveablePoint::pointColor = pointColor;
  MoveablePoint::pointColorBorderColor = pointColorBorderColor;
  MoveablePoint::lineColor = lineColor;
  MoveablePoint::graphLineColor = graphLineColor;

  MoveablePoint::minWayToLastPoint = minWayToLastPoint;

  setFlag(ItemIsMovable);
  setCacheMode(DeviceCoordinateCache);
  setZValue(1);
  setPos( *position );
  updateToolTip();
  updateDay();
}

void MoveablePoint::setLineColor( const QColor& lineColor )
{
  MoveablePoint::lineColor = lineColor;
}

void MoveablePoint::setPointColor( const QColor& pointColor )
{
  MoveablePoint::pointColor = pointColor;
}

void MoveablePoint::setMinWayToLastPoint( const int minWayToLastPoint )
{
  MoveablePoint::minWayToLastPoint = minWayToLastPoint;
}

QRectF MoveablePoint::boundingRect() const
{
  // Only one point!
  qreal adjust = 2;
  return QRectF(-10 - adjust, -10 - adjust, 23 + adjust, 23 + adjust);
}

QPainterPath MoveablePoint::shape() const
{
  QPainterPath path;
  path.addEllipse(-10, -10, 20, 20);
  return path;
}

void MoveablePoint::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *)
{
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::darkGray);
    painter->drawEllipse(-3, -3, 10, 10);

    QRadialGradient gradient(-1, -1, 10);
    if (option->state & QStyle::State_Sunken) {
        gradient.setCenter(3, 3);
        gradient.setFocalPoint(3, 3);
        gradient.setColorAt(1, pointColor.light(120));
        gradient.setColorAt(0, pointColorBorderColor.light(120));
    } else {
        gradient.setColorAt(0, pointColor);
        gradient.setColorAt(1, pointColorBorderColor);
    }
    painter->setBrush(gradient);
    painter->setPen(QPen(lineColor, 0));
    painter->drawEllipse(-10, -10, 20, 20);
}

void MoveablePoint::updateDay()
{
  const float len = pos().x() - areaRect.bottomLeft().x();
  const float day = len / getMinWayToLastPoint();
  mDay = std::ceil( day );
}

 void MoveablePoint::updateToolTip()
{
 const float len = areaRect.bottomLeft().y() - pos().y();
 const int count = static_cast< int >( len / getMinWayToLastPoint() );
 const float res = 36.00 + ( count * 0.1 );
 const QString tp = QString::number( res, 'f', 2 ) + getTempSuppfix();
 setToolTip( tp );
}

void MoveablePoint::alignDownRight( QPointF alignPoint, QPointF pos )
{
  QPointF p = pos;
  pos = p;
  // dla X
  int setx = -1;
  int sety = 1;
  for( int i = minWayToLastPoint; i <= areaRect.bottomRight().x(); i+= minWayToLastPoint ) {
    if( alignPoint.x() <= i )
      alignPoint.setX( i );

    if( p.x() <= i ) {
      setx = i;
      break;
    } //if

  } // for

  // Dla Y
  for( int i = areaRect.topLeft().y(); i <= areaRect.bottomLeft().y(); i+= minWayToLastPoint ) {
    if( alignPoint.y() <= i )
      alignPoint.setY( i );

    if( p.y() <= i ) {
      sety = i;
      break;
    } //if

  } // for

  const float step = minWayToLastPoint / 3;
  const int stepWay = std::ceil( step );

  if( ( nextPoint.get() &&
        pos.x() <= ( nextPoint.get()->x() - minWayToLastPoint + stepWay )  )
    || !nextPoint.get()
    ) {
    *position.get() = alignPoint;
    setPos( alignPoint );
  }

  if( ( lastPoint.get() && ( pos.x() >= ( lastPoint.get()->x() + minWayToLastPoint - stepWay ) ) )
    && ( nextPoint.get() &&
        ( pos.x() <= nextPoint.get()->x() - minWayToLastPoint + stepWay ) )
    ) {

    if(setx > -1)
      p.setX( setx );

    if(sety < 1)
      p.setY( sety );

    *position.get() = p;
    setPos( p );

  } //if

}

inline const int MoveablePoint::getStepWay() const
{
  const float step = minWayToLastPoint / 3;
  return std::ceil( step );
}

void MoveablePoint::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
  bool noAlign = false;
  const QPointF mypos( mapToParent( event->pos() ) );
  if( !areaRect.contains( mypos ) )
    noAlign = true;

  const int stepWay = getStepWay();

  if( lastPoint.get() && ( mypos.x() <= ( lastPoint.get()->x() + minWayToLastPoint - stepWay ) ) )
    noAlign = true;

  if( nextPoint.get() &&
    ( mypos.x() ) >= nextPoint.get()->x() - minWayToLastPoint + stepWay )
    noAlign = true;

  if( !noAlign )
    alignDownRight( *position.get(), mypos );
  beginEdge->update();
  endEdge->update();
  updateToolTip();
  updateDay();
  update();
  QGraphicsItem::mouseReleaseEvent(event);
  emit stateChange();
}

void MoveablePoint::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
  const QPointF mypos( mapToParent( event->pos() ) );
  if( !areaRect.contains( mypos ) ) {
    update();
    beginEdge->update();
    endEdge->update();
    event->accept();
    return;
  }

  const int stepWay = getStepWay();

  if( lastPoint.get() && ( mypos.x() <= ( lastPoint.get()->x() + minWayToLastPoint - stepWay ) ) ) {
    update();
    beginEdge->update();
    endEdge->update();
    event->accept();
    return;
  }

  if( nextPoint.get() && ( mypos.x() ) >= nextPoint.get()->x() - minWayToLastPoint + stepWay ) {
    update();
    beginEdge->update();
    endEdge->update();
    event->accept();
    return;
  }

  position.get()->setX( mypos.x() );
  position.get()->setY( mypos.y() );

  setPos( mapToScene( event->pos() ) );
  
  update();
  beginEdge->update();
  endEdge->update();
  QGraphicsItem::mouseMoveEvent(event);
}

void MoveablePoint::setPreviewPoint( const boost::shared_ptr<QPointF> point )
{
  lastPoint = point;
  beginEdge->setSourceNode( lastPoint );
  update();
}

void MoveablePoint::setPointPosition( const boost::shared_ptr<QPointF> point )
{
  position = point;
  beginEdge->setDestNode( position );
  endEdge->setSourceNode( position );
  update();
}

void MoveablePoint::setNextPoint( const boost::shared_ptr<QPointF> point )
{
  nextPoint = point;
  endEdge->setDestNode( nextPoint );
  update();
}

void MoveablePoint::mousePressEvent( QGraphicsSceneMouseEvent* event )
{
  if( event->buttons() & Qt::RightButton )
    emit deletePointSignal();

  QGraphicsItem::mousePressEvent(event);
}

void MoveablePoint::setGraphLineColor( const QColor& graphLineColor )
{
  MoveablePoint::graphLineColor = graphLineColor;
}

void MoveablePoint::setPointColorBorderColor( const QColor& pointColorBorderColor )
{
  MoveablePoint::pointColorBorderColor = pointColorBorderColor;
}

float MoveablePoint::getTemp() const
{
  QString temp = toolTip();
  temp = temp.section( getTempSuppfix(), 0 ,0 );
  return temp.toFloat();
}

