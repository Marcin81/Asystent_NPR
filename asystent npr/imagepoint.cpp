/*
License: GPL 
Owner: Marcin Brysz
Contact: unemployed81@gmail.com / bryszmarcin@gmail.com
Version: 1.3 Beta
*/
#include "imagepoint.h"
#include <QtGui/QPainter>
#include <QtGui/QGraphicsSceneMouseEvent>
#include <QtCore/QtDebug>
#include <cmath>
#include <QtCore/QLocale>

ImagePoint::ImagePoint( /*QGraphicsScene* scene,*/ const QRectF& area,
  const QPointF& position, const QPixmap& pixmap, const Tup3& nameAndResToolTip, const int meshStep )
  : mAreaRect( area ),
    mMeshStep( meshStep ),
    mDay( 0 )
{
  setPixmap( pixmap );
  ImagePoint::nameAndResToolTip = nameAndResToolTip;
  setFlag(ItemIsMovable);
  setCacheMode(DeviceCoordinateCache);
  setZValue(1);
  setPos( position );
  updateTranslation();
  updateDay();
}

ImagePoint::~ImagePoint()
{

}

void ImagePoint::updateTranslation()
{
  const std::string str = nameAndResToolTip.get<2>().toStdString();
  //qDebug() << "nameAndResToolTip.get<2>(): " << nameAndResToolTip.get<2>();
//  qDebug() << QLocale().name();// Nie tlumaczy jak mam przelaczony na j. ang
//  qDebug() << "QObject::trUtf8( str.c_str() ): " << QObject::trUtf8( str.c_str() );
  setToolTip( QObject::trUtf8( str.c_str() ) );
}

void ImagePoint::updateDay()
{
  const float len = qRound( pos().x() ) - mAreaRect.bottomLeft().x() + mMeshStep;
  const float day = qRound( len ) / mMeshStep;
  mDay = qRound( day );
}

void ImagePoint::alignDownRight( QPointF alignPoint, QPointF pos )
{
  QPointF p = pos;
  pos = p;
  // dla X
  int setx = -1;
  int sety = 1;
  for( int i = mMeshStep; i <= mAreaRect.bottomRight().x(); i+= mMeshStep ) {
    if( alignPoint.x() <= i )
      alignPoint.setX( i );

    if( p.x() <= i ) {
      setx = i;
      break;
    } //if

  } // for

  // Dla Y
  for( int i = mAreaRect.topLeft().y(); i <= mAreaRect.bottomLeft().y(); i+= mMeshStep ) {
    if( alignPoint.y() <= i )
      alignPoint.setY( i );

    if( p.y() <= i ) {
      sety = i;
      break;
    } //if

  } // for

  if( ( pos.x() >= ( mAreaRect.bottomLeft().x() + mMeshStep ) )
    && ( pos.x() <= mAreaRect.bottomRight().x() - mMeshStep ) ) {

  if(setx > -1)
    p.setX( setx );

  if(sety < 1)
    p.setY( sety );
  if( ( setx > -1 ) && ( sety < 1 ) )
   setPos( p );
 } //if

}

void ImagePoint::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
  bool noAlign = false;
  QPointF mypos = mapToParent(event->pos() );
  if( !mAreaRect.contains( mypos ) )
    noAlign = true;
  if( !noAlign )
     alignDownRight( pos(), mypos );
  updateDay();
  update();
  QGraphicsItem::mouseReleaseEvent(event);
  emit stateChange();
}

void ImagePoint::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
  const QPointF mypos( mapToParent( event->pos() ) );
  if( !mAreaRect.contains( mypos ) ) {
    update();
    return;
  }

  setPos( mapToScene( event->pos() ) );
  update();
  QGraphicsItem::mouseMoveEvent(event);
}

void ImagePoint::mousePressEvent( QGraphicsSceneMouseEvent* event )
{
  if( event->buttons() & Qt::RightButton )
    emit deletePointSignal();
  QGraphicsItem::mousePressEvent(event);
}
