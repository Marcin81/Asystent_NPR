/*
License: GPL 
Owner: Marcin Brysz
Contact: unemployed81@gmail.com / bryszmarcin@gmail.com
Version: 1.3 Beta
*/
#include <QtGui/QtGui>
#include "dragwidget.h"

DragWidget::DragWidget(QWidget *parent)
    : QFrame(parent),
      startX( 20 ),
      startY( 20 ),
      skipX(70),
      skipY(15),
      sep( "@@@" )
{
    setMinimumSize(310, 200);
    setFrameStyle(QFrame::Sunken | QFrame::StyledPanel);
}

void DragWidget::addLabels( const QString& text, const QString& pixmapPath,
                            const QString& objectName, const QFont& font )
{
    QLabel *pixLabel = new QLabel(this);
    pixLabel->setPixmap( QPixmap( pixmapPath) );
    pixLabel->move( startX, startY );
    pixLabel->show();
    pixLabel->setObjectName( objectName );
    pixLabel->setAccessibleDescription( pixmapPath + sep + text );
    pixLabel->setScaledContents( true );
    
    const std::string tmp = text.toStdString();
    QLabel *label = new QLabel( QObject::trUtf8( tmp.c_str() ), this);
    label->move( startX + skipX, startY + skipY );
    label->setAlignment( Qt::AlignLeft | Qt::AlignVCenter );
    label->setFont( font );
   /* #ifdef Q_WS_WIN
    setMinimumSize((label->width()*4 )+100, 200);
    label->setFixedWidth( (label->width()*4 )+100 );
    #else
    label->setFixedWidth( label->width() + ( width()/2) + 50 );
    #endif*/
    #ifdef Q_WS_MAC
    label->setFixedWidth( label->width() + ( width()/2) + 50 );
    #else
    setMinimumSize((label->width()*4 )+100, 200);
    label->setFixedWidth( (label->width()*4 )+100 );
    #endif
    label->show();
    label->setAccessibleDescription( text );
    label->setScaledContents( true );
    labels.push_back( label );
    startY += skipX;
}

void DragWidget::updateTranslation()
{
  for( QList< QLabel* >::iterator it = labels.begin();
  it != labels.end(); it++) {
    QLabel* l = (*it);
    l->setLocale( QLocale() );
    QString tmp = l->accessibleDescription();
    const std::string str = tmp.toStdString();
    l->setText( QObject::trUtf8( str.c_str() ) );
  } //for
}

void DragWidget::mousePressEvent(QMouseEvent *event)
{
    const QPoint mypos( event->pos() );
    QLabel *child = static_cast<QLabel*>(childAt( mypos ) );
    if (!child)
        return;

    if( !child->pixmap() )
      return;
    QPixmap pixmap = *child->pixmap();
    if( pixmap.isNull() )
      return;
    QString temp = child->accessibleDescription();
    QByteArray itemData;
    QDataStream dataStream(&itemData, QIODevice::WriteOnly);
    dataStream << child->objectName() << temp.section( sep, 0, 0 ) << temp.section( sep, 1, 1 );
//! [1]

//! [2]
    QMimeData *mimeData = new QMimeData;
    mimeData->setData("application/x-dnditemdata", itemData);
//! [2]
        
//! [3]
    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimeData);
    drag->setPixmap(pixmap);
    drag->setHotSpot(event->pos() - child->pos());
//! [3]

    QPixmap tempPixmap = pixmap;
    QPainter painter;
    painter.begin(&tempPixmap);
    painter.fillRect(pixmap.rect(), QColor(127, 127, 127, 127));
    painter.end();

    child->setPixmap(tempPixmap);

    if (drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction) == Qt::MoveAction)
        child->close();
    else {
        child->show();
        child->setPixmap(pixmap);
    }
}

