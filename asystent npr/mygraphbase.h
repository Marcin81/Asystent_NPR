/*
License: GPL 
Owner: Marcin Brysz
Contact: unemployed81@gmail.com / bryszmarcin@gmail.com
Version: 1.3 Beta
*/
#ifndef MYGRAPHBASE_H
#define MYGRAPHBASE_H

#include <QtGui/QGraphicsView>
#include <QtCore/QDataStream>

class MyGraphBase : public QGraphicsView
{
  Q_OBJECT
public:
  MyGraphBase( QWidget* parent = 0 );
  virtual ~MyGraphBase();

  virtual QRectF getArea() const;
  const int getPeriod() const { return maxPeriod; }
  const qreal getScaleView() const { return mViewScale; }
  void scaleView(qreal scaleFactor);

  virtual void save( QDataStream& ds ) = 0;
  virtual void load( QDataStream& ds ) = 0;

  QGraphicsScene* getScene() const { return mScene; }
protected:
  QGraphicsScene* mScene;
  int minWayToLastPoint;
  const int maxPeriod;
  qreal mViewScale;
 signals:
  void createPoint();
  void graphChange();
};

#endif // MYGRAPHBASE_H
