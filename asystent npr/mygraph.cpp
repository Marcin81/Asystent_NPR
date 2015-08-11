/*
License: GPL 
Owner: Marcin Brysz
Contact: unemployed81@gmail.com / bryszmarcin@gmail.com
Version: 1.3 Beta
*/
#include "mygraph.h"
#include <boost/scoped_ptr.hpp>

Mygraph::Mygraph( QWidget* parent )
  : MyGraphBase( parent )
{
    mScene->setSceneRect(0, -600, 1190, 600);
    setMinimumSize(1250, 700);
}

Mygraph::~Mygraph()
{

}

void Mygraph::drawBackground(QPainter *painter, const QRectF &rect)
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

    painter->fillRect( area, gradient);

    painter->setBrush(Qt::NoBrush);
    painter->drawRect( area );

    QLineF lineX( sceneRect.bottomLeft(), sceneRect.bottomRight() );
    QLineF lineY( sceneRect.bottomLeft(), QPointF( sceneRect.topLeft().x(), sceneRect.topLeft().y() - 20 ) );

    painter->setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter->drawLine(lineX);
    painter->drawLine(lineY);

    const double Pi = 3.14159265358979323846264338327950288419717;
    const double TwoPi = 2.0 * Pi;
    const int arrowSize = -10;
    const int step = 10;

    double angleY = ::acos(lineY.dx() / lineY.length());
     if (lineY.dy() >= 0)
         angleY = TwoPi - angleY;

     QPointF arrowYP1 = QPointF( lineY.p2().x(), lineY.p2().y() + step )
      + QPointF(sin(angleY + Pi / 3) * arrowSize,
                cos(angleY + Pi / 3) * arrowSize);

     QPointF arrowYP2 = QPointF( lineY.p2().x(), lineY.p2().y() + step )
      + QPointF(sin(angleY + Pi - Pi / 3) * arrowSize,
                cos(angleY + Pi - Pi / 3) * arrowSize);

     double angleX = ::acos(lineX.dx() / lineX.length());
     if (lineX.dy() >= 0)
         angleX = TwoPi - angleX;

     QPointF arrowXP1 = QPointF( lineX.p2().x() - step, lineX.p2().y() )
      + QPointF(sin(angleX + Pi / 3) * arrowSize,
                cos(angleX + Pi / 3) * arrowSize);

     QPointF arrowXP2 = QPointF( lineX.p2().x() - step, lineX.p2().y() )
      + QPointF(sin(angleX + Pi - Pi / 3) * arrowSize,
                cos(angleX + Pi - Pi / 3) * arrowSize);

     painter->setPen(QPen(Qt::black, 5, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
     painter->drawPolygon(QPolygonF() << lineX.p2() << arrowXP1 << arrowXP2 );
     painter->drawPolygon(QPolygonF() << lineY.p2() << arrowYP1 << arrowYP2 );
     painter->setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    // Draw horizontal line into area:
    const int skip = minWayToLastPoint;
    const int howMany = (area.topLeft().y() * (-1) ) / skip;
    int tempSkip = skip;
    tempSkip -= skip;
    float temperature = 38.00;
    const float leftMarginLegend = 80.00;
    for( int i = 0; i <= howMany; i++ ) {
      QPointF startPoint(area.topLeft().x(), area.topRight().y() - tempSkip );
      QPointF endPoint(area.topRight().x(), area.topRight().y() - tempSkip );
      QLineF line( startPoint, endPoint );
      const QString myText = QString::number( temperature, 'f', 2 ) + getTempSuppfix();
      if( myText == QString( "36.60" + getTempSuppfix() ) ) {
        const int penWidth = painter->pen().width();
        QPen pen, orgPen = painter->pen();
        pen.setWidth( penWidth + 2 );
        painter->setPen( pen );
        painter->drawLine( line );
        painter->setPen( orgPen );
      } else
        painter->drawLine( line );
      // Draw temp:

      temperature -= 0.1;
      painter->drawText( startPoint.x() - leftMarginLegend, startPoint.y(), myText );
      //------------
      tempSkip -= skip;
    } //for

    // Draw vertical line into area:
    // We know -> max period for waman is equal 39:
    tempSkip = skip;
    QPointF dayPoint( area.topLeft().x() + 20, area.topLeft().y() - 10 );
    for( int i = 1; i <= maxPeriod; i++ ) {
      QPointF startPoint( area.topLeft().x() + tempSkip, area.topLeft().y() );
      QPointF endPoint( area.bottomLeft().x() + tempSkip, area.bottomLeft().y() );
      painter->drawLine( startPoint, endPoint );
      // Draw days:
      painter->drawText( dayPoint, QString::number( i ) );
      dayPoint.setX( dayPoint.x() + skip );
      //--------------
      tempSkip += skip;
    } // for

}

void Mygraph::dragEnterEvent( QDragEnterEvent* event )
{
    if (event->mimeData()->hasFormat( "application/x-dnditemdata") ) {
        event->setDropAction( Qt::MoveAction );
        event->accept();
    }
}
// Moze miec znaczenie w implementacji pod windowsa lub inne platformy:
void Mygraph::dragMoveEvent(QDragMoveEvent *event)
{
    if (event->mimeData()->hasFormat( "application/x-dnditemdata") ) {
        event->setDropAction( Qt::MoveAction );
        event->accept();
    }
}

boost::tuple< QColor /* pointColor */, QColor /*pointColorBorderColor */>
Mygraph::getColors( const QString& objName ) const
{
  if( temperatureStr[0] == objName )// w ustach
    return boost::make_tuple( QColor( Qt::yellow ), QColor( Qt::darkYellow ) );
  else if( temperatureStr[1] == objName ) // w pochwie
    return boost::make_tuple( QColor( 135, 206, 250 ), QColor( 65, 105, 225 ));
  //if( temperatureStr[2] == objName ) // w odbycie
    return boost::make_tuple( QColor( 209, 146, 117 ), QColor( 139, 58, 58 ) );
}

void Mygraph::dropEvent( QDropEvent* event )
{
  const QPointF mypos(  mapToScene( event->pos() ) );
  if( !getArea().contains( mypos )
    || ( points.size() == maxPeriod ) ) {
    event->ignore();
    return;
  }

  if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        QByteArray itemData = event->mimeData()->data("application/x-dnditemdata");
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);

        QString objectName;
        dataStream >> objectName;
        if(  !temperatureStr.contains( objectName )
          || objectName.isEmpty() ) {
          event->ignore();
          return;
        }

      if( !points.empty() ) {
        MoveablePoint* mp = points.last();
        boost::shared_ptr< QPointF > previewPoint( mp->getPointPosition() );

        // Zabezpieczenie przed dodawaniem punktu poza obszar sceny:
        const int maxLongArea = minWayToLastPoint + previewPoint.get()->x();
        if( maxLongArea >= getArea().bottomRight().x() ) {
          event->ignore();
          return;
        }
      } // if
      boost::tuple< QColor, QColor > colors = getColors( objectName );
      addPoint( mypos, colors.get<0>(), colors.get<1>() );
      event->acceptProposedAction();
      emit createPoint();

  } else {
      event->ignore();
  }

}

void Mygraph::setTemperatureObjectName( const QStringList& objectName )
{
  temperatureStr = objectName;
}

void Mygraph::deletePointSlot()
{
  MoveablePoint* p = qobject_cast< MoveablePoint* >( sender() );
  if( !p )
    return;
  const int index = points.indexOf( p );

  if( index > 0 ) { // Jest poprzedni
    MoveablePoint* p1 = points[ index - 1 ];
    if( !p->getNextPoint().get() ) { // Nie ma następnego
      p1->setNextPoint( boost::shared_ptr<QPointF>() );
      eraseAndCleanUp( p );
    } else { // Jest następny
      MoveablePoint* p2 = points[index + 1];
      p1->setNextPoint( p2->getPointPosition() );
      p2->setPreviewPoint( p1->getPointPosition() );
      eraseAndCleanUp( p );
    } // else
  } else { // Nie ma poprzedniego
    if( p->getNextPoint().get() ) { // Jest następny

      MoveablePoint* p2 = points[ index + 1 ];
      p2->setPreviewPoint( p->getPreviewPoint() );

      eraseAndCleanUp( p );
    } else { // Nie ma następnego - jeden punkt tylko
      eraseAndCleanUp( p );
    } // else

  } // else
}

void Mygraph::eraseAndCleanUp( MoveablePoint* p )
{
  mScene->removeItem( p->getBeginEdge() );
  mScene->removeItem( p->getEndEdge() );
  mScene->removeItem( p );
  points.removeOne( p );
  update();
  emit graphChange();
}

void Mygraph::graphChangeSlot()
{
  emit graphChange();
}

void Mygraph::save( QDataStream& ds )
{
  ds << points.size();
  for( int i = 0; i < points.size(); i++ )
    ds << points[i]->pos()
        << points[i]->getPointColor()
        << points[i]->getPointColorBorderColor();
}

void Mygraph::clear() {
  mScene->clear();
  points.clear();
}

void Mygraph::load( QDataStream& ds )
{
  clear();
  int pSize = 0;
  ds >> pSize;

  for( int i = 0; i < pSize; i++ ) {
    QPointF pf;
    ds >> pf;
    QColor pc;
    ds >> pc;
    QColor pcb;
    ds >> pcb;
    addPoint( pf, pc, pcb );
  } // for

}

float Mygraph::getTemperature() const
{
  QString temp = toolTip();
   temp = temp.remove( getTempSuppfix() );
   bool ok = false;
   return temp.toFloat( &ok );
}

void Mygraph::addPoint( const QPointF& mypos, const QColor& pointColor, const QColor& pointColorBorderColor )
{
  const int Y = ( mypos.y() > 0 ) ? ( mypos.y() * (-1) ) : mypos.y();
  const int stepWay = getStepWay();

  if( points.empty() ) { // Gdy wykres nie ma punktow

     const int X = ( mypos.x() >= minWayToLastPoint + getArea().bottomLeft().x()  - stepWay )
                    ? mypos.x() : ( minWayToLastPoint );
     boost::shared_ptr< QPointF > nowPoint( new QPointF( X, Y ) );
     boost::shared_ptr< QPointF > emptyPoint;
     boost::shared_ptr< QPointF > emptyPointBefore;
     MoveablePoint* mp = MoveablePoint::createPointer< Edge >( mScene, getArea(),
                                              nowPoint, emptyPointBefore, emptyPoint, pointColor, pointColorBorderColor );

     points.push_back( mp );
     mScene->addItem(mp);
     mp->alignDownRight( *nowPoint.get(), mypos );
     connect( mp, SIGNAL(deletePointSignal()), this, SLOT(deletePointSlot()) );
     connect( mp, SIGNAL(stateChange() ), this, SLOT( graphChangeSlot() ) );
  } else { // gdy wykres ma przynajmniej jeden punkt widoczny
     MoveablePoint* mp = points.last();
     boost::shared_ptr< QPointF > previewPoint( mp->getPointPosition() );

    // Zabezpieczenie przed dodawaniem punktu poza obszar sceny:
    const int maxLongArea = minWayToLastPoint + previewPoint.get()->x();

    const int X = ( mypos.x() >= maxLongArea ) ? mypos.x() : maxLongArea;
    boost::shared_ptr< QPointF > nowPoint( new QPointF( X, Y ) );
    boost::shared_ptr< QPointF > emptyNextPoint;
    MoveablePoint* nextmp = MoveablePoint::createPointer< Edge >(
      mScene, getArea(), nowPoint, previewPoint, emptyNextPoint, pointColor, pointColorBorderColor );

    points.push_back( nextmp );
    mScene->addItem( nextmp );
    mp->setNextPoint( nowPoint );
    nextmp->alignDownRight( *nowPoint.get(), mypos );
    connect( nextmp, SIGNAL(deletePointSignal()), this, SLOT(deletePointSlot()) );
    connect( nextmp, SIGNAL(stateChange() ), this, SLOT( graphChangeSlot() ) );
  } // if
  emit graphChange();
}
