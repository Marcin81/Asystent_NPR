/*
License: GPL 
Owner: Marcin Brysz
Contact: unemployed81@gmail.com / bryszmarcin@gmail.com
Version: 1.3 Beta
*/
#ifndef EDGE_H
#define EDGE_H

#include <QtGui/QGraphicsItem>
#include <boost/smart_ptr/shared_ptr.hpp>

class EdgeBase : public QGraphicsItem
{
public:
  EdgeBase( boost::shared_ptr<QPointF> sourceNode,
            boost::shared_ptr<QPointF> destNode, const QColor& color = Qt::darkRed );
    virtual ~EdgeBase() = 0;

    boost::shared_ptr<QPointF> sourceNode() const;
    virtual void setSourceNode( boost::shared_ptr<QPointF> node) = 0;

    boost::shared_ptr<QPointF> destNode() const;
    virtual void setDestNode( boost::shared_ptr<QPointF> node) = 0;

protected:
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) = 0;

  boost::shared_ptr<QPointF> source;
  boost::shared_ptr<QPointF> dest;
  QColor lineColor;
};

class Edge : public EdgeBase
{
public:
    Edge( boost::shared_ptr<QPointF> sourceNode,
          boost::shared_ptr<QPointF> destNode, const QColor& color = Qt::darkRed );
    virtual ~Edge();

    boost::shared_ptr<QPointF> sourceNode() const;
    void setSourceNode( boost::shared_ptr<QPointF> node);

    boost::shared_ptr<QPointF> destNode() const;
    void setDestNode( boost::shared_ptr<QPointF> node);

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};

#endif
