/*
License: GPL 
Owner: Marcin Brysz
Contact: unemployed81@gmail.com / bryszmarcin@gmail.com
Version: 1.3 Beta
*/
#include "mygraphsupplement.h"
#include <QtGui/QDragEnterEvent>
#include "imagepoint.h"
#include <QtGui/QLabel>
#include <QtCore/QtDebug>
#include <boost/bind/bind.hpp>
#include <algorithm>
#include <QtGui/QApplication>

MygraphSupplement::MygraphSupplement( QWidget* parent )
  : MyGraphBase( parent )
{
    mScene->setSceneRect(0, -180, 1190, 180);
    setMinimumSize(1250, 210);
    //mBackGroundText = trUtf8( "Oznaczenia:" );
    //setUpdatesEnabled( true );
    //setViewportUpdateMode( QGraphicsView::FullViewportUpdate );// aby odswierzyl tlumaczenie "oznaczenia:"
}

MygraphSupplement::~MygraphSupplement()
{

}

void MygraphSupplement::drawBackground(QPainter *painter, const QRectF &rect)
{
    Q_UNUSED(rect);

    // Shadow
    QRectF sceneRect = this->sceneRect();

    QRectF rightShadow(sceneRect.right(), sceneRect.top() + 5, 5, sceneRect.height());
    QRectF bottomShadow(sceneRect.left() + 5, sceneRect.bottom(), sceneRect.width(), 5);
    if (rightShadow.intersects(rect) || rightShadow.contains(rect))
  painter->fillRect(rightShadow, Qt::white);
    if (bottomShadow.intersects(rect) || bottomShadow.contains(rect))
  painter->fillRect(bottomShadow, Qt::white);

    QRectF area = getArea();
    // Fill
    QLinearGradient gradient(area.topLeft(), area.bottomRight());

    gradient.setColorAt(0, Qt::white);
    gradient.setColorAt(1, Qt::lightGray);

    painter->fillRect(area, gradient);

    painter->setBrush(Qt::NoBrush);
    painter->drawRect( area );

    painter->setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    const int howMany = (area.topLeft().y() * (-1) ) / minWayToLastPoint;
    int tempSkip = minWayToLastPoint;
    tempSkip -= minWayToLastPoint;

    for( int i = 0; i <= howMany; i++ ) {
      QPointF startPoint(area.topLeft().x(), area.topRight().y() - tempSkip );
      QPointF endPoint(area.topRight().x(), area.topRight().y() - tempSkip );
      QLineF line( startPoint, endPoint );
      painter->drawLine( line );
      tempSkip -= minWayToLastPoint;
    } //for

    // Draw vertical line into area:
    // We know -> max period for waman is equal 44 (was 39)
    tempSkip = minWayToLastPoint;
    QPointF dayPoint( area.topLeft().x() + 10, area.topLeft().y() - 10 );
    painter->drawText( QPoint( area.topLeft().x() - 80, area.topLeft().y() + 80 ), /*mBackGroundText*//*trUtf8( "Oznaczenia:" ) */
                       QApplication::translate("MygraphSupplement", "Oznaczenia:", 0, QApplication::UnicodeUTF8 ) );
    for( int i = 1; i <= maxPeriod; i++ ) {
      QPointF startPoint( area.topLeft().x() + tempSkip, area.topLeft().y() );
      QPointF endPoint( area.bottomLeft().x() + tempSkip, area.bottomLeft().y() );
      painter->drawLine( startPoint, endPoint );
      // Draw days:
      painter->drawText( dayPoint, QString::number( i ) );
      dayPoint.setX( dayPoint.x() + minWayToLastPoint );
      //--------------
      tempSkip += minWayToLastPoint;
    } // for

}

void MygraphSupplement::dragEnterEvent( QDragEnterEvent* event )
{
  if( event->mimeData()->hasFormat( "application/x-dnditemdata") ) {
    event->setDropAction( Qt::MoveAction );
    event->accept();
  }
}

// Moze miec znaczenie w implementacji pod windowsa lub inne platformy:
void MygraphSupplement::dragMoveEvent(QDragMoveEvent *event)
{
  if( event->mimeData()->hasFormat( "application/x-dnditemdata") ) {
    event->setDropAction( Qt::MoveAction );
    event->accept();
  }
}
    
void MygraphSupplement::ignorePointName( const QStringList& pNames )
{
  mIgnorePointNames = pNames;
}

void MygraphSupplement::dropEvent( QDropEvent * event )
{
  if( points.size() == (maxPeriod * 6) ) {// 6 is a number of row
    event->ignore();
    return;
  }

  const QPointF mypos( mapToScene( event->pos() ) );
  QRectF area = getImageArea();
  if( !area.contains( mypos )
    || ( points.size() == maxPeriod ) ) {
    event->ignore();
    return;
  }

  if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
    QByteArray itemData = event->mimeData()->data("application/x-dnditemdata");
    QDataStream dataStream(&itemData, QIODevice::ReadOnly);

    QString objName;
    QString resName;
    QString toolTip;
    dataStream >> objName >> resName >> toolTip;

    if( mIgnorePointNames.contains( objName )
      || objName.isEmpty()
      || resName.isEmpty()
      || toolTip.isEmpty() ) {
      event->ignore();
      return;
    }

    addImagePoint( mypos, boost::make_tuple( objName, resName, toolTip ) );
    // daj konekta ze state change
    event->acceptProposedAction();
    emit createPoint();
  } else {
      event->ignore();
  }

}

void MygraphSupplement::updateTranslation()
{
  using boost::bind;
  setLocale( QLocale() );
  //mBackGroundText = trUtf8( "Oznaczenia:" );
  std::for_each( points.begin(), points.end(), boost::bind( &ImagePoint::updateTranslation, _1 ) );
  //Obejscie:
  hide();
  show();
}

void MygraphSupplement::addImagePoint( const QPointF& mypos, const Tup3& nameAndResToolTip, const bool ignoreAlign )
{
  const int Y = ( mypos.y() > 0 ) ? ( mypos.y() * (-1) ) : mypos.y();

  QPixmap pixmap( nameAndResToolTip.get<1>() );
  pixmap = pixmap.scaled( minWayToLastPoint, minWayToLastPoint );
  QRectF area = getImageArea();
  ImagePoint* ip = new ImagePoint( /*mScene,*/ area, mypos, pixmap, nameAndResToolTip );

  const int X = ( mypos.x() >= minWayToLastPoint + area.bottomLeft().x() )
                       ? mypos.x() : ( 2* minWayToLastPoint );

  mScene->addItem( ip );
  if( !ignoreAlign )
    ip->alignDownRight( QPointF( X, Y), mypos );
  ip->show();
  //ip->updateTranslation();// w kontruktorze chyba tłumaczenia nie działają
  ip->update();
  points.push_back( ip );
  connect( ip, SIGNAL(deletePointSignal()), this, SLOT(deletePointSlot()) );
  connect( ip, SIGNAL(stateChange()), this, SLOT( stateChangeSlot() ));
  emit graphChange();
}

void MygraphSupplement::stateChangeSlot()
{
  emit graphChange();
}

void MygraphSupplement::deletePointSlot()
{
  ImagePoint* p = qobject_cast< ImagePoint* >( sender() );
  if( !p )
    return;
  mScene->removeItem( p );
  points.removeOne( p );
  update();
  emit graphChange();
}

void MygraphSupplement::save( QDataStream& ds )
{
  ds << points.size();
  for( int i = 0; i < points.size(); i++ )
    ds << points[i]->pos() << points[i]->getObjectName()
         << points[i]->getResourceName() << points[i]->toolTip();

}

void MygraphSupplement::clear()
{
  mScene->clear();
  points.clear();
}

void MygraphSupplement::load( QDataStream& ds )
{
  clear();
  int pSize = 0;
  ds >> pSize;

  for( int i = 0; i < pSize; i++ ) {
    QPointF pf;
    ds >> pf;
    QString objName;
    ds >> objName;
    QString resName;
    ds >> resName;
    QString tp;
    ds >> tp;
    addImagePoint( pf, boost::make_tuple( objName, resName, tp ), true );
  } // for
}

QRectF MygraphSupplement::getImageArea() const
{
  QRectF myarea = getArea();
  myarea.setHeight( myarea.height() - minWayToLastPoint );
  myarea.setWidth( myarea.width() - 20 );
  return myarea;
}
