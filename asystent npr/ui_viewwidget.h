/********************************************************************************
** Form generated from reading UI file 'viewwidget.ui'
**
** Created: Tue Oct 27 10:27:13 2009
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!

** License: GPL 
** Owner: Marcin Brysz
** Contact: unemployed81@gmail.com / bryszmarcin@gmail.com
** Version: 1.3 Beta

********************************************************************************/

#ifndef UI_VIEWWIDGET_H
#define UI_VIEWWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDateEdit>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QScrollArea>
#include <QtGui/QSpacerItem>
#include <QtGui/QTimeEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "mygraph.h"
#include "mygraphsupplement.h"

QT_BEGIN_NAMESPACE

class Ui_ViewWidget
{
public:
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QWidget *printWidget;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    MygraphSupplement *graphSupplement;
    Mygraph *graphicsView;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacerLeft;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayoutObservation;
    QLabel *label_description;
    QSpacerItem *horizontalSpacer;
    QDateEdit *dateObservation;
    QHBoxLayout *horizontalLayoutObservation_2;
    QLabel *label_hour;
    QSpacerItem *horizontalSpacer1;
    QTimeEdit *timeEdit;
    QHBoxLayout *horizontalLayoutFertility;
    QFrame *lineFertility;
    QSpacerItem *horizontalSpacer2;
    QLabel *labelFertility;
    QHBoxLayout *horizontalLayoutNotFertility;
    QFrame *lineNotFertility;
    QSpacerItem *horizontalSpacer3;
    QLabel *labelNotFertility;
    QHBoxLayout *horizontalLayoutMaybeFertility;
    QFrame *lineMaybeFertility;
    QSpacerItem *horizontalSpacer4;
    QLabel *labelMaybeFertility;
    QSpacerItem *horizontalSpacerRight;

    void setupUi(QWidget *ViewWidget)
    {
        if (ViewWidget->objectName().isEmpty())
            ViewWidget->setObjectName(QString::fromUtf8("ViewWidget"));
        ViewWidget->resize(783, 561);
        gridLayout = new QGridLayout(ViewWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        scrollArea = new QScrollArea(ViewWidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy);
        scrollArea->setAutoFillBackground(false);
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setLineWidth(0);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 759, 537));
        horizontalLayout = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        printWidget = new QWidget(scrollAreaWidgetContents);
        printWidget->setObjectName(QString::fromUtf8("printWidget"));
        gridLayout_3 = new QGridLayout(printWidget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        graphSupplement = new MygraphSupplement(printWidget);
        graphSupplement->setObjectName(QString::fromUtf8("graphSupplement"));
        sizePolicy.setHeightForWidth(graphSupplement->sizePolicy().hasHeightForWidth());
        graphSupplement->setSizePolicy(sizePolicy);
        graphSupplement->setFrameShape(QFrame::NoFrame);
        graphSupplement->setLineWidth(0);
        graphSupplement->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphSupplement->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphSupplement->setRenderHints(QPainter::Antialiasing|QPainter::HighQualityAntialiasing|QPainter::TextAntialiasing);

        gridLayout_2->addWidget(graphSupplement, 1, 0, 1, 1);

        graphicsView = new Mygraph(printWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        graphicsView->setFrameShape(QFrame::NoFrame);
        graphicsView->setLineWidth(0);
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setRenderHints(QPainter::Antialiasing|QPainter::HighQualityAntialiasing|QPainter::TextAntialiasing);

        gridLayout_2->addWidget(graphicsView, 0, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);


        verticalLayout->addWidget(printWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(20, 0, 20, 20);
        horizontalSpacerLeft = new QSpacerItem(70, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacerLeft);

        groupBox = new QGroupBox(scrollAreaWidgetContents);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayoutObservation = new QHBoxLayout();
        horizontalLayoutObservation->setObjectName(QString::fromUtf8("horizontalLayoutObservation"));
        horizontalLayoutObservation->setContentsMargins(15, -1, 15, -1);
        label_description = new QLabel(groupBox);
        label_description->setObjectName(QString::fromUtf8("label_description"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_description->sizePolicy().hasHeightForWidth());
        label_description->setSizePolicy(sizePolicy1);

        horizontalLayoutObservation->addWidget(label_description);

        horizontalSpacer = new QSpacerItem(40, 10, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayoutObservation->addItem(horizontalSpacer);

        dateObservation = new QDateEdit(groupBox);
        dateObservation->setObjectName(QString::fromUtf8("dateObservation"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(dateObservation->sizePolicy().hasHeightForWidth());
        dateObservation->setSizePolicy(sizePolicy2);
        dateObservation->setMinimumSize(QSize(0, 0));
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        font.setKerning(true);
        dateObservation->setFont(font);
        dateObservation->setFocusPolicy(Qt::ClickFocus);
        dateObservation->setWrapping(false);
        dateObservation->setFrame(true);
        dateObservation->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        dateObservation->setReadOnly(false);
        dateObservation->setAccelerated(false);
        dateObservation->setKeyboardTracking(true);
        dateObservation->setDateTime(QDateTime(QDate(2000, 1, 1), QTime(0, 0, 0)));
        dateObservation->setCalendarPopup(true);

        horizontalLayoutObservation->addWidget(dateObservation);


        verticalLayout_2->addLayout(horizontalLayoutObservation);

        horizontalLayoutObservation_2 = new QHBoxLayout();
        horizontalLayoutObservation_2->setObjectName(QString::fromUtf8("horizontalLayoutObservation_2"));
        horizontalLayoutObservation_2->setContentsMargins(15, -1, 15, -1);
        label_hour = new QLabel(groupBox);
        label_hour->setObjectName(QString::fromUtf8("label_hour"));
        sizePolicy1.setHeightForWidth(label_hour->sizePolicy().hasHeightForWidth());
        label_hour->setSizePolicy(sizePolicy1);

        horizontalLayoutObservation_2->addWidget(label_hour);

        horizontalSpacer1 = new QSpacerItem(40, 10, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayoutObservation_2->addItem(horizontalSpacer1);

        timeEdit = new QTimeEdit(groupBox);
        timeEdit->setObjectName(QString::fromUtf8("timeEdit"));
        timeEdit->setFocusPolicy(Qt::ClickFocus);
        timeEdit->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        timeEdit->setTime(QTime(6, 0, 0));

        horizontalLayoutObservation_2->addWidget(timeEdit);


        verticalLayout_2->addLayout(horizontalLayoutObservation_2);

        horizontalLayoutFertility = new QHBoxLayout();
        horizontalLayoutFertility->setObjectName(QString::fromUtf8("horizontalLayoutFertility"));
        horizontalLayoutFertility->setContentsMargins(15, -1, 15, -1);
        lineFertility = new QFrame(groupBox);
        lineFertility->setObjectName(QString::fromUtf8("lineFertility"));
        QPalette palette;
        QBrush brush(QColor(102, 228, 132, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(69, 69, 69, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        lineFertility->setPalette(palette);
        lineFertility->setFrameShadow(QFrame::Plain);
        lineFertility->setLineWidth(5);
        lineFertility->setMidLineWidth(0);
        lineFertility->setFrameShape(QFrame::HLine);

        horizontalLayoutFertility->addWidget(lineFertility);

        horizontalSpacer2 = new QSpacerItem(40, 10, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayoutFertility->addItem(horizontalSpacer2);

        labelFertility = new QLabel(groupBox);
        labelFertility->setObjectName(QString::fromUtf8("labelFertility"));
        sizePolicy1.setHeightForWidth(labelFertility->sizePolicy().hasHeightForWidth());
        labelFertility->setSizePolicy(sizePolicy1);
        labelFertility->setLayoutDirection(Qt::LeftToRight);

        horizontalLayoutFertility->addWidget(labelFertility);


        verticalLayout_2->addLayout(horizontalLayoutFertility);

        horizontalLayoutNotFertility = new QHBoxLayout();
        horizontalLayoutNotFertility->setObjectName(QString::fromUtf8("horizontalLayoutNotFertility"));
        horizontalLayoutNotFertility->setContentsMargins(15, -1, 15, -1);
        lineNotFertility = new QFrame(groupBox);
        lineNotFertility->setObjectName(QString::fromUtf8("lineNotFertility"));
        QPalette palette1;
        QBrush brush2(QColor(228, 108, 127, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        lineNotFertility->setPalette(palette1);
        lineNotFertility->setFrameShadow(QFrame::Plain);
        lineNotFertility->setLineWidth(5);
        lineNotFertility->setMidLineWidth(0);
        lineNotFertility->setFrameShape(QFrame::HLine);

        horizontalLayoutNotFertility->addWidget(lineNotFertility);

        horizontalSpacer3 = new QSpacerItem(40, 10, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayoutNotFertility->addItem(horizontalSpacer3);

        labelNotFertility = new QLabel(groupBox);
        labelNotFertility->setObjectName(QString::fromUtf8("labelNotFertility"));
        sizePolicy1.setHeightForWidth(labelNotFertility->sizePolicy().hasHeightForWidth());
        labelNotFertility->setSizePolicy(sizePolicy1);

        horizontalLayoutNotFertility->addWidget(labelNotFertility);


        verticalLayout_2->addLayout(horizontalLayoutNotFertility);

        horizontalLayoutMaybeFertility = new QHBoxLayout();
        horizontalLayoutMaybeFertility->setObjectName(QString::fromUtf8("horizontalLayoutMaybeFertility"));
        horizontalLayoutMaybeFertility->setContentsMargins(15, -1, 15, -1);
        lineMaybeFertility = new QFrame(groupBox);
        lineMaybeFertility->setObjectName(QString::fromUtf8("lineMaybeFertility"));
        QPalette palette2;
        QBrush brush3(QColor(146, 186, 228, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        lineMaybeFertility->setPalette(palette2);
        lineMaybeFertility->setFrameShadow(QFrame::Plain);
        lineMaybeFertility->setLineWidth(5);
        lineMaybeFertility->setMidLineWidth(0);
        lineMaybeFertility->setFrameShape(QFrame::HLine);

        horizontalLayoutMaybeFertility->addWidget(lineMaybeFertility);

        horizontalSpacer4 = new QSpacerItem(40, 10, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayoutMaybeFertility->addItem(horizontalSpacer4);

        labelMaybeFertility = new QLabel(groupBox);
        labelMaybeFertility->setObjectName(QString::fromUtf8("labelMaybeFertility"));
        sizePolicy1.setHeightForWidth(labelMaybeFertility->sizePolicy().hasHeightForWidth());
        labelMaybeFertility->setSizePolicy(sizePolicy1);

        horizontalLayoutMaybeFertility->addWidget(labelMaybeFertility);


        verticalLayout_2->addLayout(horizontalLayoutMaybeFertility);


        horizontalLayout_2->addWidget(groupBox);

        horizontalSpacerRight = new QSpacerItem(90, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacerRight);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout->addLayout(verticalLayout);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 1);


        retranslateUi(ViewWidget);

        QMetaObject::connectSlotsByName(ViewWidget);
    } // setupUi

    void retranslateUi(QWidget *ViewWidget)
    {
        ViewWidget->setWindowTitle(QApplication::translate("ViewWidget", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        label_description->setText(QApplication::translate("ViewWidget", "Data rozpocz\304\231cia obserwacji:", 0, QApplication::UnicodeUTF8));
        dateObservation->setDisplayFormat(QApplication::translate("ViewWidget", "dd MMMM yyyy", 0, QApplication::UnicodeUTF8));
        label_hour->setText(QApplication::translate("ViewWidget", "Godzina wykonywania pomiaru:", 0, QApplication::UnicodeUTF8));
        labelFertility->setText(QApplication::translate("ViewWidget", "Okres p\305\202odno\305\233ci", 0, QApplication::UnicodeUTF8));
        labelNotFertility->setText(QApplication::translate("ViewWidget", "Okres niep\305\202odno\305\233ci", 0, QApplication::UnicodeUTF8));
        labelMaybeFertility->setText(QApplication::translate("ViewWidget", "Okres wzgl\304\231dnej niep\305\202odno\305\233ci", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ViewWidget: public Ui_ViewWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWWIDGET_H
