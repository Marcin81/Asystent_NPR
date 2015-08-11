/*
License: GPL 
Owner: Marcin Brysz
Contact: unemployed81@gmail.com / bryszmarcin@gmail.com
Version: 1.3 Beta
*/
#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QtGui/QMainWindow>
#include "ui_viewwidget.h"
#include "ui_mainwindow.h"
#include <boost/tuple/tuple.hpp>
#ifdef Q_WS_WIN
  #include <QtGui/QWindowsVistaStyle>
  #include <QtGui/QWindowsXPStyle>
#endif
#ifdef Q_WS_MAC
  #include <QtGui/QMacStyle>
#endif

#include <boost/shared_ptr.hpp>
#include "myviewwidget.h"

class QPrinter;
class QPrintDialog;
class QPageSetupDialog;
class QGraphicsRectItem;
class QActionGroup;
class QMyDecompressor;
// jak skonczysz program dodaj qsettings i zapamietywanie ustawien
// oraz pytanie o zapis przy zamykaniu zakladku lub programu
// zmien biblioteke do kompresji na libbzip2

typedef boost::tuple<QGraphicsRectItem*, QGraphicsRectItem* > RectOFFertilities;
typedef boost::tuple< RectOFFertilities /* rectMaybeFertility*/,
  RectOFFertilities /* rectNotFertility*/,
  RectOFFertilities /* rectFertility*/> ManyRectOFFertilities;

class MyWindow : public QMainWindow
{
  Q_OBJECT
  boost::shared_ptr< Ui_MainWindow > mMainWindow;
  QList< boost::shared_ptr< MyViewWidget > > mViewWidgets;
  qreal scaleView;
  QStringList mTemperatures;
  QPrinter* mPrinter;
  QTranslator* mQtTranslator;
  QTranslator* mNprTranslator;
  QMyDecompressor* mArchDep;
  
  void preparePrinter();
  void setScale( const QRect& geo, const QRect& geoV,  const QRect& geoS );
  void setLocale( QDateEdit* dt );
  void cleanImpl( RectOFFertilities& rectFertilityDescription, const int& cIndex );
  void addNextFertilities();
  void eraseFertility( const int cIndex );

  QRect getDefaultGraphicsViewGeometry() const;
  QRect getDefaultVerticalLayoutGeometry() const;
  QRect getDefaultGraphicsSupplementGeometry() const;

  QList< ManyRectOFFertilities > mFertilities;
  QActionGroup* mMucusActions;
  QActionGroup* mLanguageActions;

  void myPointsConnect( MoveablePoint* mp );
  void myPointsDisconnect( MoveablePoint* mp );
  void myPointsConnect( ImagePoint* ip );
  void myPointsDisconnect( ImagePoint* ip );

  void autointerpretationGraphs( const bool& on, const int& cIndex );

  void zoom( const qreal& newScale );
  void createPhase( const boost::tuple< int, QPointF >& begin, const boost::tuple< int, QPointF >& end, const QPalette& pal, const int& cIndex, RectOFFertilities& rectFertilityDescription );

  void retranslate( Ui_ViewWidget* viewWidget, const QLocale& loc );
  
  void saveImpl( QList< boost::shared_ptr< MyViewWidget > >& pViewWidgets, const int& cIndex, const bool& isSaveUs = false );
  void saveAll( QList< boost::shared_ptr< MyViewWidget > >& pViewWidgets );
  void updateTabTitleWithStar( const int& cIndex );
  void updateTabTitleWithOutStar( const int& cIndex );
protected slots:
  void configMenuScale( const int& pageIndex );
  void showAboutAction();
  void updateTranslation();
	void showHelpAction();
  void showHelpDecompressError();
  void deleteThread();
  void deleteHelpArchive();
  void changeStyle();
  void showHelpAssistant();
  void showLanguageMenu();
  void updateTabTitle();
protected:
    void closeEvent( QCloseEvent *event);
    void connectNeedSaveGraphs( const int& pIndex );
public:
  MyWindow( const QStringList& temperatures, QTranslator& qtTranslator, QTranslator& nprTranslator );
  virtual ~MyWindow();

  boost::shared_ptr< Ui_MainWindow > getMainWindow() { return mMainWindow; }
  static void changeStyle(const QString &styleName);
public slots:
  void zoomIn();
  void zoomOut();
  void save( const bool& isSaveUs = false );
  void saveAs();
  void load();
  void pageSetup();
  void printPreview();
  void printPreviews();
  void printPreview( QPrinter* preview );
  void printPreviews( QPrinter* preview );
  void printerConfiguration();
  void printToPDF( const bool& isForEach = false );
  void printAllToPDF();

  void print( const qreal& scale = 5.04, const bool& isForEach = false );

  void addPageTab();
  void removePageTab();
  void removePageTab( const int& pageIndex );
  void interpretationGraph();
  void autointerpretationGraphs( const bool& on );
  void clean();
  void clearView();
  void showAbout();

  const QLocale getLocale() const;
	void help();
signals:
  void languageChange();
  void beforeClose();
};

#endif // MYWINDOW_H
