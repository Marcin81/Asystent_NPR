/*
License: GPL 
Owner: Marcin Brysz
Contact: unemployed81@gmail.com / bryszmarcin@gmail.com
Version: 1.3 Beta
*/
#ifndef DRAGWIDGET_H
#define DRAGWIDGET_H

#include <QtGui/QFrame>

QT_BEGIN_NAMESPACE
class QDragEnterEvent;
class QDropEvent;
class QLabel;
QT_END_NAMESPACE

class DragWidget : public QFrame
{
public:
    DragWidget(QWidget *parent=0);

    void addLabels( const QString& text, const QString& pixmapPath,
                    const QString& objectName, const QFont& font );

    void updateTranslation();
protected:
    int startX;
    int startY;
    int skipX;
    int skipY;
    QString sep;
    QList< QLabel* > labels;

    void mousePressEvent(QMouseEvent *event);
};

#endif
