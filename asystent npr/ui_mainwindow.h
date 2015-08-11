/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
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

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionTemperature;
    QAction *actionFeeling;
    QAction *actionRemnant;
    QAction *actionZoomIn;
    QAction *actionZoomOut;
    QAction *actionLoad;
    QAction *actionSave;
    QAction *actionPrint;
    QAction *actionPrintToPDF;
    QAction *actionAutoScale;
    QAction *actionPrintPreview;
    QAction *actionPageSetting;
    QAction *actionAddPageTab;
    QAction *actionClosePageTab;
    QAction *actionPrintPreviews;
    QAction *actionPrintAllToPDF;
    QAction *actionInterpretationGraph;
    QAction *actionCleanGraph;
    QAction *actionAutointerpretation;
    QAction *actionPresenceOfMucus;
    QAction *actionPresenceOfMucusByFiveDays;
    QAction *actionObservationCervix;
    QAction *actionCleanTabPage;
    QAction *actionAbout;
    QAction *actionHelp;
    QAction *actionPolishLanguage;
    QAction *actionEnglishLanguage;
    QAction *actionWindowsStyle;
    QAction *actionWindowsVistaStyle;
    QAction *actionWindowsXPStyle;
    QAction *actionCDEStyle;
    QAction *actionCleanlooksStyle;
    QAction *actionGTKStyle;
    QAction *actionMacStyle;
    QAction *actionMotifStyle;
    QAction *actionPlastiqueStyle;
    QAction *actionWindowsNormalStyle;
    QAction *actionSaveAs;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QTabWidget *tabWidget;
    QWidget *pageTab1;
    QMenuBar *menubar;
    QMenu *menuWindows;
    QMenu *menuSettings;
    QMenu *menuLanguage;
    QMenu *menuFile;
    QMenu *menuTabPages;
    QMenu *menuInterpretation;
    QMenu *menuFerlityOfPeriod;
    QMenu *menuHelp;
    QMenu *menuStyle;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1279, 915);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Light, brush1);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush1);
        QBrush brush2(QColor(127, 127, 127, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush2);
        QBrush brush3(QColor(170, 170, 170, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush1);
        QBrush brush4(QColor(255, 255, 220, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        MainWindow->setPalette(palette);
        MainWindow->setContextMenuPolicy(Qt::NoContextMenu);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/thermometer-48x48.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setIconSize(QSize(48, 48));
        MainWindow->setUnifiedTitleAndToolBarOnMac(false);
        actionTemperature = new QAction(MainWindow);
        actionTemperature->setObjectName(QString::fromUtf8("actionTemperature"));
        actionTemperature->setCheckable(true);
        actionTemperature->setChecked(false);
        actionFeeling = new QAction(MainWindow);
        actionFeeling->setObjectName(QString::fromUtf8("actionFeeling"));
        actionFeeling->setCheckable(true);
        actionFeeling->setChecked(false);
        actionRemnant = new QAction(MainWindow);
        actionRemnant->setObjectName(QString::fromUtf8("actionRemnant"));
        actionRemnant->setCheckable(true);
        actionRemnant->setChecked(false);
        actionZoomIn = new QAction(MainWindow);
        actionZoomIn->setObjectName(QString::fromUtf8("actionZoomIn"));
        actionZoomIn->setEnabled(true);
        actionZoomOut = new QAction(MainWindow);
        actionZoomOut->setObjectName(QString::fromUtf8("actionZoomOut"));
        actionZoomOut->setEnabled(false);
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName(QString::fromUtf8("actionLoad"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionPrint = new QAction(MainWindow);
        actionPrint->setObjectName(QString::fromUtf8("actionPrint"));
        actionPrintToPDF = new QAction(MainWindow);
        actionPrintToPDF->setObjectName(QString::fromUtf8("actionPrintToPDF"));
        actionAutoScale = new QAction(MainWindow);
        actionAutoScale->setObjectName(QString::fromUtf8("actionAutoScale"));
        actionAutoScale->setCheckable(true);
        actionAutoScale->setChecked(true);
        actionPrintPreview = new QAction(MainWindow);
        actionPrintPreview->setObjectName(QString::fromUtf8("actionPrintPreview"));
        actionPageSetting = new QAction(MainWindow);
        actionPageSetting->setObjectName(QString::fromUtf8("actionPageSetting"));
        actionAddPageTab = new QAction(MainWindow);
        actionAddPageTab->setObjectName(QString::fromUtf8("actionAddPageTab"));
        actionClosePageTab = new QAction(MainWindow);
        actionClosePageTab->setObjectName(QString::fromUtf8("actionClosePageTab"));
        actionPrintPreviews = new QAction(MainWindow);
        actionPrintPreviews->setObjectName(QString::fromUtf8("actionPrintPreviews"));
        actionPrintAllToPDF = new QAction(MainWindow);
        actionPrintAllToPDF->setObjectName(QString::fromUtf8("actionPrintAllToPDF"));
        actionInterpretationGraph = new QAction(MainWindow);
        actionInterpretationGraph->setObjectName(QString::fromUtf8("actionInterpretationGraph"));
        actionCleanGraph = new QAction(MainWindow);
        actionCleanGraph->setObjectName(QString::fromUtf8("actionCleanGraph"));
        actionAutointerpretation = new QAction(MainWindow);
        actionAutointerpretation->setObjectName(QString::fromUtf8("actionAutointerpretation"));
        actionAutointerpretation->setCheckable(true);
        actionAutointerpretation->setChecked(false);
        actionAutointerpretation->setEnabled(true);
        actionPresenceOfMucus = new QAction(MainWindow);
        actionPresenceOfMucus->setObjectName(QString::fromUtf8("actionPresenceOfMucus"));
        actionPresenceOfMucus->setCheckable(true);
        actionPresenceOfMucusByFiveDays = new QAction(MainWindow);
        actionPresenceOfMucusByFiveDays->setObjectName(QString::fromUtf8("actionPresenceOfMucusByFiveDays"));
        actionPresenceOfMucusByFiveDays->setCheckable(true);
        actionPresenceOfMucusByFiveDays->setChecked(true);
        actionObservationCervix = new QAction(MainWindow);
        actionObservationCervix->setObjectName(QString::fromUtf8("actionObservationCervix"));
        actionObservationCervix->setCheckable(true);
        actionCleanTabPage = new QAction(MainWindow);
        actionCleanTabPage->setObjectName(QString::fromUtf8("actionCleanTabPage"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName(QString::fromUtf8("actionHelp"));
        actionHelp->setEnabled(true);
        actionPolishLanguage = new QAction(MainWindow);
        actionPolishLanguage->setObjectName(QString::fromUtf8("actionPolishLanguage"));
        actionPolishLanguage->setCheckable(true);
        actionPolishLanguage->setEnabled(true);
        actionEnglishLanguage = new QAction(MainWindow);
        actionEnglishLanguage->setObjectName(QString::fromUtf8("actionEnglishLanguage"));
        actionEnglishLanguage->setCheckable(true);
        actionEnglishLanguage->setEnabled(true);
        actionWindowsStyle = new QAction(MainWindow);
        actionWindowsStyle->setObjectName(QString::fromUtf8("actionWindowsStyle"));
        actionWindowsVistaStyle = new QAction(MainWindow);
        actionWindowsVistaStyle->setObjectName(QString::fromUtf8("actionWindowsVistaStyle"));
        actionWindowsVistaStyle->setCheckable(true);
        actionWindowsVistaStyle->setEnabled(true);
        actionWindowsXPStyle = new QAction(MainWindow);
        actionWindowsXPStyle->setObjectName(QString::fromUtf8("actionWindowsXPStyle"));
        actionWindowsXPStyle->setCheckable(true);
        actionWindowsXPStyle->setEnabled(true);
        actionCDEStyle = new QAction(MainWindow);
        actionCDEStyle->setObjectName(QString::fromUtf8("actionCDEStyle"));
        actionCleanlooksStyle = new QAction(MainWindow);
        actionCleanlooksStyle->setObjectName(QString::fromUtf8("actionCleanlooksStyle"));
        actionCleanlooksStyle->setCheckable(true);
        actionGTKStyle = new QAction(MainWindow);
        actionGTKStyle->setObjectName(QString::fromUtf8("actionGTKStyle"));
        actionGTKStyle->setCheckable(true);
        actionGTKStyle->setEnabled(false);
        actionMacStyle = new QAction(MainWindow);
        actionMacStyle->setObjectName(QString::fromUtf8("actionMacStyle"));
        actionMacStyle->setCheckable(true);
        actionMacStyle->setChecked(false);
        actionMotifStyle = new QAction(MainWindow);
        actionMotifStyle->setObjectName(QString::fromUtf8("actionMotifStyle"));
        actionPlastiqueStyle = new QAction(MainWindow);
        actionPlastiqueStyle->setObjectName(QString::fromUtf8("actionPlastiqueStyle"));
        actionPlastiqueStyle->setCheckable(true);
        actionWindowsNormalStyle = new QAction(MainWindow);
        actionWindowsNormalStyle->setObjectName(QString::fromUtf8("actionWindowsNormalStyle"));
        actionWindowsNormalStyle->setCheckable(true);
        actionSaveAs = new QAction(MainWindow);
        actionSaveAs->setObjectName(QString::fromUtf8("actionSaveAs"));
        actionSaveAs->setEnabled(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setUsesScrollButtons(false);
        pageTab1 = new QWidget();
        pageTab1->setObjectName(QString::fromUtf8("pageTab1"));
        tabWidget->addTab(pageTab1, QString());

        horizontalLayout_2->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1279, 22));
        menuWindows = new QMenu(menubar);
        menuWindows->setObjectName(QString::fromUtf8("menuWindows"));
        menuSettings = new QMenu(menubar);
        menuSettings->setObjectName(QString::fromUtf8("menuSettings"));
        menuLanguage = new QMenu(menuSettings);
        menuLanguage->setObjectName(QString::fromUtf8("menuLanguage"));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuTabPages = new QMenu(menubar);
        menuTabPages->setObjectName(QString::fromUtf8("menuTabPages"));
        menuInterpretation = new QMenu(menubar);
        menuInterpretation->setObjectName(QString::fromUtf8("menuInterpretation"));
        menuFerlityOfPeriod = new QMenu(menuInterpretation);
        menuFerlityOfPeriod->setObjectName(QString::fromUtf8("menuFerlityOfPeriod"));
        menuFerlityOfPeriod->setContextMenuPolicy(Qt::ActionsContextMenu);
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuStyle = new QMenu(menubar);
        menuStyle->setObjectName(QString::fromUtf8("menuStyle"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuWindows->menuAction());
        menubar->addAction(menuSettings->menuAction());
        menubar->addAction(menuTabPages->menuAction());
        menubar->addAction(menuInterpretation->menuAction());
        menubar->addAction(menuStyle->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuWindows->addAction(actionTemperature);
        menuWindows->addAction(actionFeeling);
        menuWindows->addAction(actionObservationCervix);
        menuWindows->addAction(actionRemnant);
        menuWindows->addSeparator();
        menuWindows->addAction(actionAbout);
        menuSettings->addAction(menuLanguage->menuAction());
        menuSettings->addSeparator();
        menuSettings->addAction(actionZoomIn);
        menuSettings->addAction(actionZoomOut);
        menuLanguage->addAction(actionPolishLanguage);
        menuLanguage->addAction(actionEnglishLanguage);
        menuFile->addAction(actionLoad);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSaveAs);
        menuFile->addSeparator();
        menuFile->addAction(actionPageSetting);
        menuFile->addSeparator();
        menuFile->addAction(actionAutoScale);
        menuFile->addSeparator();
        menuFile->addAction(actionPrintPreview);
        menuFile->addAction(actionPrintPreviews);
        menuFile->addSeparator();
        menuFile->addAction(actionPrintToPDF);
        menuFile->addAction(actionPrintAllToPDF);
        menuFile->addSeparator();
        menuFile->addAction(actionPrint);
        menuTabPages->addAction(actionCleanTabPage);
        menuTabPages->addSeparator();
        menuTabPages->addAction(actionAddPageTab);
        menuTabPages->addAction(actionClosePageTab);
        menuInterpretation->addAction(actionInterpretationGraph);
        menuInterpretation->addAction(actionCleanGraph);
        menuInterpretation->addSeparator();
        menuInterpretation->addAction(menuFerlityOfPeriod->menuAction());
        menuInterpretation->addSeparator();
        menuInterpretation->addAction(actionAutointerpretation);
        menuFerlityOfPeriod->addAction(actionPresenceOfMucus);
        menuFerlityOfPeriod->addAction(actionPresenceOfMucusByFiveDays);
        menuHelp->addAction(actionHelp);
        menuStyle->addAction(actionWindowsNormalStyle);
        menuStyle->addAction(actionWindowsXPStyle);
        menuStyle->addAction(actionWindowsVistaStyle);
        menuStyle->addAction(actionCleanlooksStyle);
        menuStyle->addAction(actionMacStyle);
        menuStyle->addAction(actionPlastiqueStyle);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Asystent NPR", 0, QApplication::UnicodeUTF8));
        actionTemperature->setText(QApplication::translate("MainWindow", "Rodzaj \305\233luzu", 0, QApplication::UnicodeUTF8));
        actionTemperature->setShortcut(QApplication::translate("MainWindow", "Ctrl+R", 0, QApplication::UnicodeUTF8));
        actionFeeling->setText(QApplication::translate("MainWindow", "Odczucie nawil\305\274enia przedsionka pochwy", 0, QApplication::UnicodeUTF8));
        actionFeeling->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", 0, QApplication::UnicodeUTF8));
        actionRemnant->setText(QApplication::translate("MainWindow", "Pozosta\305\202e oznaczenia", 0, QApplication::UnicodeUTF8));
        actionRemnant->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        actionZoomIn->setText(QApplication::translate("MainWindow", "Powi\304\231ksz", 0, QApplication::UnicodeUTF8));
        actionZoomIn->setShortcut(QApplication::translate("MainWindow", "Ctrl++", 0, QApplication::UnicodeUTF8));
        actionZoomOut->setText(QApplication::translate("MainWindow", "Zmniejsz", 0, QApplication::UnicodeUTF8));
        actionZoomOut->setShortcut(QApplication::translate("MainWindow", "Ctrl+-", 0, QApplication::UnicodeUTF8));
        actionLoad->setText(QApplication::translate("MainWindow", "Wczytaj", 0, QApplication::UnicodeUTF8));
        actionLoad->setShortcut(QApplication::translate("MainWindow", "Ctrl+L", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("MainWindow", "Zapisz", 0, QApplication::UnicodeUTF8));
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        actionPrint->setText(QApplication::translate("MainWindow", "Drukuj", 0, QApplication::UnicodeUTF8));
        actionPrint->setShortcut(QApplication::translate("MainWindow", "Ctrl+D", 0, QApplication::UnicodeUTF8));
        actionPrintToPDF->setText(QApplication::translate("MainWindow", "Drukuj do PDF", 0, QApplication::UnicodeUTF8));
        actionPrintToPDF->setShortcut(QApplication::translate("MainWindow", "Ctrl+E", 0, QApplication::UnicodeUTF8));
        actionAutoScale->setText(QApplication::translate("MainWindow", "Autoskalowanie", 0, QApplication::UnicodeUTF8));
        actionAutoScale->setShortcut(QApplication::translate("MainWindow", "Ctrl+A", 0, QApplication::UnicodeUTF8));
        actionPrintPreview->setText(QApplication::translate("MainWindow", "Podgl\304\205d wydruku", 0, QApplication::UnicodeUTF8));
        actionPrintPreview->setShortcut(QApplication::translate("MainWindow", "Ctrl+P", 0, QApplication::UnicodeUTF8));
        actionPageSetting->setText(QApplication::translate("MainWindow", "Ustawienia strony", 0, QApplication::UnicodeUTF8));
        actionPageSetting->setShortcut(QApplication::translate("MainWindow", "Ctrl+U", 0, QApplication::UnicodeUTF8));
        actionAddPageTab->setText(QApplication::translate("MainWindow", "Dodaj", 0, QApplication::UnicodeUTF8));
        actionAddPageTab->setShortcut(QApplication::translate("MainWindow", "Ctrl+T", 0, QApplication::UnicodeUTF8));
        actionClosePageTab->setText(QApplication::translate("MainWindow", "Zamknij", 0, QApplication::UnicodeUTF8));
        actionClosePageTab->setShortcut(QApplication::translate("MainWindow", "Ctrl+W", 0, QApplication::UnicodeUTF8));
        actionPrintPreviews->setText(QApplication::translate("MainWindow", "Podgl\304\205d wydruk\303\263w", 0, QApplication::UnicodeUTF8));
        actionPrintAllToPDF->setText(QApplication::translate("MainWindow", "Drukuj wszystkie do PDF", 0, QApplication::UnicodeUTF8));
        actionInterpretationGraph->setText(QApplication::translate("MainWindow", "Interpretuj wykres", 0, QApplication::UnicodeUTF8));
        actionInterpretationGraph->setShortcut(QApplication::translate("MainWindow", "Ctrl+I", 0, QApplication::UnicodeUTF8));
        actionCleanGraph->setText(QApplication::translate("MainWindow", "Wyczy\305\233\304\207 wykres", 0, QApplication::UnicodeUTF8));
        actionCleanGraph->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", 0, QApplication::UnicodeUTF8));
        actionAutointerpretation->setText(QApplication::translate("MainWindow", "Autointerpretacja", 0, QApplication::UnicodeUTF8));
        actionPresenceOfMucus->setText(QApplication::translate("MainWindow", "Obecno\305\233\304\207 \305\233luzu", 0, QApplication::UnicodeUTF8));
        actionPresenceOfMucusByFiveDays->setText(QApplication::translate("MainWindow", "Obecno\305\233\304\207 \305\233luzu przez 5 dni", 0, QApplication::UnicodeUTF8));
        actionObservationCervix->setText(QApplication::translate("MainWindow", "Obserwacja szyjki macicy", 0, QApplication::UnicodeUTF8));
        actionObservationCervix->setShortcut(QApplication::translate("MainWindow", "Ctrl+B", 0, QApplication::UnicodeUTF8));
        actionCleanTabPage->setText(QApplication::translate("MainWindow", "Wyczy\305\233\304\207", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindow", "O programie...", 0, QApplication::UnicodeUTF8));
        actionHelp->setText(QApplication::translate("MainWindow", "Pomoc", 0, QApplication::UnicodeUTF8));
        actionHelp->setShortcut(QApplication::translate("MainWindow", "F1", 0, QApplication::UnicodeUTF8));
        actionPolishLanguage->setText(QApplication::translate("MainWindow", "Polski", 0, QApplication::UnicodeUTF8));
        actionEnglishLanguage->setText(QApplication::translate("MainWindow", "Angielski", 0, QApplication::UnicodeUTF8));
        actionWindowsStyle->setText(QApplication::translate("MainWindow", "Windows", 0, QApplication::UnicodeUTF8));
        actionWindowsVistaStyle->setText(QApplication::translate("MainWindow", "Windows Vista", 0, QApplication::UnicodeUTF8));
        actionWindowsXPStyle->setText(QApplication::translate("MainWindow", "Windows XP", 0, QApplication::UnicodeUTF8));
        actionCDEStyle->setText(QApplication::translate("MainWindow", "CDE", 0, QApplication::UnicodeUTF8));
        actionCleanlooksStyle->setText(QApplication::translate("MainWindow", "Cleanlooks", 0, QApplication::UnicodeUTF8));
        actionGTKStyle->setText(QApplication::translate("MainWindow", "GTK", 0, QApplication::UnicodeUTF8));
        actionMacStyle->setText(QApplication::translate("MainWindow", "Macintosh (aqua)", 0, QApplication::UnicodeUTF8));
        actionMotifStyle->setText(QApplication::translate("MainWindow", "Motif", 0, QApplication::UnicodeUTF8));
        actionPlastiqueStyle->setText(QApplication::translate("MainWindow", "Plastique", 0, QApplication::UnicodeUTF8));
        actionWindowsNormalStyle->setText(QApplication::translate("MainWindow", "Windows", 0, QApplication::UnicodeUTF8));
        actionSaveAs->setText(QApplication::translate("MainWindow", "Zapisz jako", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(pageTab1), QApplication::translate("MainWindow", "Zak\305\202adka 1", 0, QApplication::UnicodeUTF8));
        menuWindows->setTitle(QApplication::translate("MainWindow", "Okna", 0, QApplication::UnicodeUTF8));
        menuSettings->setTitle(QApplication::translate("MainWindow", "Ustawienia", 0, QApplication::UnicodeUTF8));
        menuLanguage->setTitle(QApplication::translate("MainWindow", "J\304\231zyk", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "Plik", 0, QApplication::UnicodeUTF8));
        menuTabPages->setTitle(QApplication::translate("MainWindow", "Zak\305\202adki", 0, QApplication::UnicodeUTF8));
        menuInterpretation->setTitle(QApplication::translate("MainWindow", "Interpretacja", 0, QApplication::UnicodeUTF8));
        menuFerlityOfPeriod->setTitle(QApplication::translate("MainWindow", "Okres p\305\202odno\305\233ci", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Pomoc", 0, QApplication::UnicodeUTF8));
        menuStyle->setTitle(QApplication::translate("MainWindow", "Style", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
