/*
License: GPL 
Owner: Marcin Brysz
Contact: unemployed81@gmail.com / bryszmarcin@gmail.com
Version: 1.3 Beta
*/
#include <QtGui/QPainter>
#include "edge.h"

EdgeBase::EdgeBase( boost::shared_ptr<QPointF> sourceNode,
            boost::shared_ptr<QPointF> destNode, const QColor& color )
    : lineColor( color )
{
    // disable mouse events
    setAcceptedMouseButtons(0);
    source = sourceNode;
    dest = destNode;
}

Edge::Edge( boost::shared_ptr<QPointF> sourceNode,
            boost::shared_ptr<QPointF> destNode, const QColor& color )
    : EdgeBase( sourceNode, destNode, color )
{
    // disable mouse events
    setAcceptedMouseButtons(0);
    source = sourceNode;
    dest = destNode;
}

EdgeBase::~EdgeBase()
{

}

Edge::~Edge()
{
}

boost::shared_ptr<QPointF> EdgeBase::sourceNode() const
{
    return source;
}

void Edge::setSourceNode( boost::shared_ptr<QPointF> node)
{
    source = node;
}

boost::shared_ptr<QPointF> EdgeBase::destNode() const
{
    return dest;
}

void Edge::setDestNode( boost::shared_ptr<QPointF> node)
{
    dest = node;
}

QRectF Edge::boundingRect() const
{
    if (!source.get() || !dest.get() )
        return QRectF();

    qreal penWidth = 1;
    qreal extra = penWidth / 2.0;

    return QRectF(*source.get(), QSizeF(dest.get()->x() - source.get()->x(),
                                      dest.get()->y() - source.get()->y() ) )
        .normalized()
        .adjusted(-extra, -extra, extra, extra);
}

void Edge::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    if (!source.get() || !dest.get() )
        return;

    // Draw the line itself
    QLineF line(*source.get(), *dest.get());
    painter->setPen( QPen(lineColor/*Qt::darkRed*/, 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter->drawLine(line);
}

