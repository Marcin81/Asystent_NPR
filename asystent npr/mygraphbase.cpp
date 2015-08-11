/*
License: GPL 
Owner: Marcin Brysz
Contact: unemployed81@gmail.com / bryszmarcin@gmail.com
Version: 1.3 Beta
*/
#include "mygraphbase.h"

MyGraphBase::MyGraphBase( QWidget* parent )
  : QGraphicsView( parent ),
    maxPeriod( 39 )
{
    mScene = new QGraphicsScene(this);
    mScene->setItemIndexMethod(QGraphicsScene::NoIndex);
    setScene(mScene);
    setCacheMode(CacheBackground);
    setViewportUpdateMode(BoundingRectViewportUpdate);
    setRenderHint(QPainter::Antialiasing);
    setTransformationAnchor(AnchorUnderMouse);
    setResizeAnchor(AnchorViewCenter);
    minWayToLastPoint = 30;

    scaleView(qreal(0.9));
    // Akceptuj upuszcanie obiektu do widgetu
    setAcceptDrops(true);
    mViewScale = qreal(0.9);
}

MyGraphBase::~MyGraphBase()
{

}

QRectF MyGraphBase::getArea() const
{
  QRectF sceneRect = this->sceneRect();
  return QRectF( sceneRect.x(), sceneRect.y(),
                 sceneRect.width() - 20,  sceneRect.height() );
}

void MyGraphBase::scaleView(qreal scaleFactor)
{
  qreal factor = matrix().scale(scaleFactor, scaleFactor).mapRect(QRectF(0, 0, 1, 1)).width();
  if (factor < 0.07 || factor > 100)
    return;

  scale(scaleFactor, scaleFactor);
  mViewScale = scaleFactor;
}
