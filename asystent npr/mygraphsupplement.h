/*
License: GPL 
Owner: Marcin Brysz
Contact: unemployed81@gmail.com / bryszmarcin@gmail.com
Version: 1.3 Beta
*/
#ifndef MYGRAPHSUPPLEMENT_H
#define MYGRAPHSUPPLEMENT_H

#include <QtGui/QGraphicsView>
#include "mygraphbase.h"
#include <QtCore/QList>
#include <boost/tuple/tuple.hpp>

class ImagePoint;
class QDragEnterEvent;
class QDropEvent;
class QPainter;

typedef boost::tuple< QString, QString, QString > Tup3;

class MygraphSupplement : public MyGraphBase
{
  Q_OBJECT
  //QString mBackGroundText;
public:
  MygraphSupplement( QWidget* parent = 0 );
  virtual ~MygraphSupplement();

  void ignorePointName( const QStringList& pNames );
  void save( QDataStream& ds );
  void load( QDataStream& ds );
  QList< ImagePoint* > getPoints() const { return points; }
  void clear();
  void updateTranslation();
protected:
  QList< ImagePoint* > points;
  QStringList mIgnorePointNames;

  void drawBackground(QPainter *painter, const QRectF &rect);
  void dragEnterEvent( QDragEnterEvent* event );
  void dragMoveEvent(QDragMoveEvent *event);
  void dropEvent( QDropEvent * event );

  void addImagePoint( const QPointF& mypos, const Tup3& nameAndResToolTip, const bool ignoreAlign = false );
  QRectF getImageArea() const;
protected slots:
  void deletePointSlot();
  void stateChangeSlot();
};

#endif // MYGRAPHSUPPLEMENT_H
