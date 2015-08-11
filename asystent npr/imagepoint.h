/*
License: GPL 
Owner: Marcin Brysz
Contact: unemployed81@gmail.com / bryszmarcin@gmail.com
Version: 1.3 Beta
*/
#ifndef IMAGEPOINT_H
#define IMAGEPOINT_H

#include <QtGui/QGraphicsPixmapItem>
#include <QtGui/QPixmap>
#include <boost/tuple/tuple.hpp>

class QGraphicsScene;
class QLocale;

typedef boost::tuple< QString, QString, QString > Tup3;

class ImagePoint : public QObject, public QGraphicsPixmapItem
{
  Q_OBJECT
public:
  ImagePoint( const QRectF& area,
                 const QPointF& position, const QPixmap& pixmap,
                 const Tup3& nameAndResToolTip, const int meshStep = 30 );
  virtual ~ImagePoint();

  void alignDownRight( QPointF alignPoint, QPointF pos );

  const QString getResourceName() const { return nameAndResToolTip.get<1>(); }
  const QString getObjectName() const { return nameAndResToolTip.get<0>(); }
  int getDay() const { return mDay; }
  const int getMeshStep() const { return mMeshStep; }
public slots:
  void updateTranslation();
protected:

  void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
  void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
  void mousePressEvent( QGraphicsSceneMouseEvent* event );

  void updateDay();
private:
  const int mMeshStep;

  QRectF mAreaRect;
  Tup3 nameAndResToolTip;
  int mDay;
signals:
  void deletePointSignal();
  void stateChange();
  //void createPoint();
};

#endif // IMAGEPOINT_H
