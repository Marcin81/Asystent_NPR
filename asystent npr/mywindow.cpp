/*
License: GPL 
Owner: Marcin Brysz
Contact: unemployed81@gmail.com / bryszmarcin@gmail.com
Version: 1.3 Beta
*/
#include <QtGui/QPrinter>
#include <QtGui/QProgressDialog>
#include <QtGui/QPrintPreviewDialog>
#include <QtGui/QPageSetupDialog>
#include <QtCore/QtDebug>
#include "mywindow.h"
#include "interpretationbymucus.h"
#include "interpretationbytemperature.h"
#include "imagepoint.h"
#include "ui_about.h"
#ifndef Q_WS_WIN
#include "qzipdecompressor.h"
#include "qtarbzip2decompressor.h"
#endif
#include <QtWebKit/QWebView>
#include <QtGui/QStyleFactory>
#include <boost/foreach.hpp>

MyWindow::MyWindow( const QStringList& temperatures,  QTranslator& qtTranslator,
  QTranslator& nprTranslator )
  : mQtTranslator( &qtTranslator ),
    mNprTranslator( &nprTranslator )
{
  mArchDep = 0;
  addNextFertilities();
  //---------------------------------------------------
  mTemperatures = temperatures;
  mMainWindow =  boost::shared_ptr< Ui_MainWindow > ( new Ui_MainWindow );
  mMainWindow->setupUi( this );
  mMainWindow->tabWidget->setTabToolTip( 0, mMainWindow->tabWidget->tabText( 0 ) ); 

  QActionGroup* group = new QActionGroup( this );
  mMainWindow->actionWindowsNormalStyle->setVisible( false );
  mMainWindow->actionWindowsXPStyle->setVisible( false );
  mMainWindow->actionWindowsVistaStyle->setVisible( false );
  mMainWindow->actionMacStyle->setVisible( false );
#ifdef Q_WS_WIN
  group->addAction( mMainWindow->actionWindowsVistaStyle );
  group->addAction( mMainWindow->actionWindowsXPStyle );
  group->addAction( mMainWindow->actionWindowsNormalStyle );
  mMainWindow->actionWindowsNormalStyle->setVisible( true );
  mMainWindow->actionWindowsXPStyle->setVisible( true );
  mMainWindow->actionWindowsVistaStyle->setVisible( true );

  connect( mMainWindow->actionWindowsNormalStyle, SIGNAL(toggled(bool)), this, SLOT( changeStyle() ) );  
  connect( mMainWindow->actionWindowsVistaStyle, SIGNAL(toggled(bool)), this, SLOT( changeStyle() ) );
  connect( mMainWindow->actionWindowsXPStyle, SIGNAL(toggled(bool)), this, SLOT( changeStyle() ) );

#endif  
#ifdef Q_WS_MAC
  group->addAction( mMainWindow->actionMacStyle );
  mMainWindow->actionMacStyle->setVisible( true );
  connect( mMainWindow->actionMacStyle, SIGNAL(toggled(bool)), this, SLOT( changeStyle() ) );
#endif
  group->addAction( mMainWindow->actionPlastiqueStyle );
  group->addAction( mMainWindow->actionCleanlooksStyle );

  connect( mMainWindow->actionPlastiqueStyle, SIGNAL(toggled(bool)), this, SLOT( changeStyle() ) );
  connect( mMainWindow->actionCleanlooksStyle, SIGNAL(toggled(bool)), this, SLOT( changeStyle() ) );
  
  const QString styleName = QApplication::style()->objectName();
  if( styleName != trUtf8( "macintosh (aqua)" ) ) {
    MyWindow::changeStyle( "Plastique" );
    mMainWindow->actionPlastiqueStyle->setChecked( true );
    QApplication::setPalette( QApplication::style()->standardPalette() );
  } else {
     mMainWindow->actionMacStyle->setChecked( true );
  }
  
  //---------------------------------------------------
  Ui_ViewWidget* vw1 = new Ui_ViewWidget;
  vw1->setupUi( mMainWindow->pageTab1 );
  mViewWidgets.push_back( boost::shared_ptr< MyViewWidget > ( new MyViewWidget( vw1, 1, false, this ) ) );
  //----------------------------------------------------
  connectNeedSaveGraphs( 0 );
  //----------------------------------------------------
  setLocale( vw1->dateObservation );
  vw1->dateObservation->setDate( QDate::currentDate() );
  //---------------------------------------------------
  mMainWindow->tabWidget->setMovable( true );
  mMainWindow->tabWidget->setTabsClosable( true );

  connect( mMainWindow->actionZoomIn, SIGNAL( triggered() ), this, SLOT(zoomIn()) );

  connect( mMainWindow->actionZoomOut, SIGNAL( triggered() ), this, SLOT(zoomOut()) );

  mViewWidgets[ 0].get()->getViewWidget()->graphicsView->setTemperatureObjectName( temperatures );
  mViewWidgets[ 0 ].get()->getViewWidget()->graphSupplement->ignorePointName( temperatures );
  scaleView = mViewWidgets[ 0 ].get()->getViewWidget()->graphicsView->getScaleView();
  //---------------------------------------------------
  connect( mMainWindow->actionSave, SIGNAL(triggered()), this, SLOT(save()) );
  connect( mMainWindow->actionSaveAs, SIGNAL(triggered()), this, SLOT(saveAs()) );
  connect( mMainWindow->actionLoad, SIGNAL(triggered()), this, SLOT( load()) );
  //---------------------------------------------------

  getDefaultGraphicsSupplementGeometry();
  getDefaultGraphicsViewGeometry();
  getDefaultVerticalLayoutGeometry();

  //---------------------------------------------------
  preparePrinter();
  //---------------------------------------------------
  connect( mMainWindow->actionClosePageTab, SIGNAL(triggered()), this, SLOT(removePageTab()) );
  connect( mMainWindow->actionAddPageTab, SIGNAL(triggered()), this, SLOT(addPageTab()) );
  connect( mMainWindow->tabWidget, SIGNAL( currentChanged ( int ) ), this, SLOT(configMenuScale(int)) );
  connect( mMainWindow->tabWidget, SIGNAL( tabCloseRequested ( int ) ), this, SLOT(removePageTab( int )) );
  //---------------------------------------------------
  connect( mMainWindow->actionInterpretationGraph, SIGNAL(triggered()), this, SLOT(interpretationGraph()) );
  //--------------------------------------------------------------------
  mMucusActions = new QActionGroup( this );
  mMucusActions->addAction( mMainWindow->actionPresenceOfMucusByFiveDays );
  mMucusActions->addAction( mMainWindow->actionPresenceOfMucus );
  //--------------------------------------------------------------------
  mLanguageActions = new QActionGroup( this );
  mLanguageActions->addAction( mMainWindow->actionPolishLanguage );
  mLanguageActions->addAction( mMainWindow->actionEnglishLanguage );
  //--------------------------------------------------------------------
  connect( mMainWindow->actionCleanGraph, SIGNAL(triggered()),
           this, SLOT(clean()) );
  //--------------------------------------------------------------------
  connect( mMainWindow->actionAutointerpretation, SIGNAL(toggled(bool)),
           mMainWindow->actionInterpretationGraph, SLOT(setDisabled(bool)) );
  connect( mMainWindow->actionAutointerpretation, SIGNAL(toggled(bool)),
           mMainWindow->actionCleanGraph, SLOT(setDisabled(bool)) );
  //--------------------------------------------------------------------
  connect( mMainWindow->actionAutointerpretation, SIGNAL(toggled(bool)),
           this, SLOT(autointerpretationGraphs(bool)) );
  //--------------------------------------------------------------------
  connect( mMainWindow->actionCleanTabPage, SIGNAL(triggered() ), this, SLOT(clearView()) );
  //--------------------------------------------------------------------
  connect( mMainWindow->actionAbout, SIGNAL(triggered()), this, SLOT( showAbout() ) );
  //--------------------------------------------------------------------
  connect( mLanguageActions, SIGNAL(triggered(QAction*)), this, SLOT(updateTranslation()) );
  //--------------------------------------------------------------------
  if( QLocale::system().name() == "pl_PL" )
    mMainWindow->actionPolishLanguage->setChecked(true);
  else
    mMainWindow->actionEnglishLanguage->setChecked(true);

  //--------------------------------------------------------------------
#ifndef Q_WS_WIN
  connect(mMainWindow->actionHelp, SIGNAL(triggered() ), this, SLOT( help() ) );
#else
  connect( mMainWindow->actionHelp, SIGNAL(triggered()), this, SLOT(showHelpAssistant()));
#endif
  //--------------------------------------------------------------------
  QRect geo = QApplication::desktop()->geometry();
  const int heighFive = QApplication::desktop()->height() / 5;
  geo.setHeight( geo.height() - heighFive );
  geo.setY(70);
  setGeometry( geo );
  setObjectName(QString::fromUtf8( "MyWindow" ) );
}

MyWindow::~MyWindow()
{

}
void MyWindow::connectNeedSaveGraphs( const int& pIndex )
{
connect( mViewWidgets[ pIndex ].get()->getViewWidget()->graphSupplement,
  SIGNAL( graphChange() ), mViewWidgets[ pIndex ].get(), SLOT( needSave() ) );
connect( mViewWidgets[ pIndex ].get()->getViewWidget()->graphicsView,
  SIGNAL( graphChange() ), mViewWidgets[ pIndex ].get(), SLOT( needSave() ) );
connect( mViewWidgets[ pIndex ].get(), SIGNAL(changeTabTitle()), this, SLOT(updateTabTitle()));
}

void MyWindow::changeStyle()
{
  QAction *action = qobject_cast<QAction*>( sender() ); 
  if( action ) {
#ifdef Q_WS_WIN
    if( action->text() == trUtf8( "Windows" ) )
      QApplication::setStyle( new QWindowsStyle );
    if( action->text() == trUtf8( "Windows XP" ) )
      QApplication::setStyle( new QWindowsXPStyle );
    if( action->text() == trUtf8( "Windows Vista" ) )
      QApplication::setStyle( new QWindowsVistaStyle );
#endif
#ifdef Q_WS_MAC
    if( action->text() == trUtf8( "Macintosh (aqua)" ) )
      QApplication::setStyle( new QMacStyle );
#endif
    if( action->text() == trUtf8( "Cleanlooks" ) )
      QApplication::setStyle( new QCleanlooksStyle );
    if( action->text() == trUtf8( "Plastique" ) )
      QApplication::setStyle( new QPlastiqueStyle );
        
     QApplication::setPalette( QApplication::style()->standardPalette() );
  } // if
  
}
#ifndef Q_WS_WIN
void MyWindow::help()
{
	mMainWindow->actionHelp->setEnabled(false);
  mMainWindow->menuLanguage->setEnabled( false );
	//-----------------------------------------------  
	QProgressDialog pd( this );
	pd.hide();
  pd.setCancelButton( 0 ); // No cancel button
	pd.setLabelText( trUtf8( "Dekompresja systemu pomocy." ) );
	pd.setGeometry( 200, 400, 800, 300 );
	pd.setRange( 1, 5 );

  pd.setWindowFlags( Qt::Tool );
	pd.setAutoClose( true );
	pd.show();
	pd.setValue( 2 );

	const QString zipFile = QCoreApplication::applicationDirPath() + QDir::separator()
    + trUtf8( "help_pl.tar.bz2" );

	if( !QFile::exists( zipFile ) ) {
		if( !QFile::copy( trUtf8( ":/help_pl.tar.bz2" ), zipFile ) ) {
			pd.close();
			QMessageBox::critical( this, trUtf8( "Error" ),
        trUtf8( "Błąd. Nie można skopiować pliku pomocy z zasobów na dysk." ));
			mMainWindow->actionHelp->setEnabled(true);
			return;
		}
	}
  
  pd.setValue( 3 );
  // obiekt trzeba potem zniszczyc, lub stanie sie to dopiero po zamknieciu aplikacji
//  mArchDep = new QZipDecompressor( QCoreApplication::applicationDirPath(),
//                    trUtf8( "help_pl.zip" ), QCoreApplication::applicationDirPath(), this );
  mArchDep = new QTarBZip2Decompressor( QCoreApplication::applicationDirPath(),
                                        trUtf8( "help_pl.tar.bz2" ),
                                        QCoreApplication::applicationDirPath(), this );  
  
	pd.setValue( 4 );
  
  connect( mArchDep, SIGNAL(decompressFinishSignal()), this, SLOT(showHelpAssistant()) );
  connect( mArchDep, SIGNAL(showErrorSignal()), this, SLOT( showHelpDecompressError() ) );
  connect( mArchDep, SIGNAL(finished()), this, SLOT( deleteThread() ) );
  connect( mArchDep, SIGNAL(finished()), this, SLOT( deleteHelpArchive() ) );
  mArchDep->start( QThread::NormalPriority );
	pd.setValue( 5 );
	//---------------------------------------------------
}
#endif
void MyWindow::showHelpAssistant()
{
	QMainWindow* helpWin = new QMainWindow;
  //--------------------------------------------------------------------
  connect( this, SIGNAL( beforeClose() ), helpWin, SLOT(close()));
  //--------------------------------------------------------------------
  
  helpWin->setWindowTitle( trUtf8( "Asystent pomocy" ) );
	helpWin->setGeometry( geometry() );
  QWebView* webView = new QWebView( helpWin );
  helpWin->setCentralWidget( webView );
	helpWin->setAttribute( Qt::WA_DeleteOnClose, true );
  connect( helpWin, SIGNAL(destroyed()), this, SLOT( showHelpAction() ) );
  connect( helpWin, SIGNAL(destroyed()), this, SLOT( showLanguageMenu() ) );
  
	const QString path = QCoreApplication::applicationDirPath() + QDir::separator()
    + trUtf8( "Asystent_NPR" ) + QDir::separator() + QString( "index.html" );

  webView->load( QUrl::fromLocalFile( path ) );
  helpWin->show();
}
#ifndef Q_WS_WIN
void MyWindow::deleteThread()
{
  if( mArchDep ) {
    mArchDep->quit();
    delete mArchDep;
    mArchDep = 0;
  } // if
}

void MyWindow::deleteHelpArchive()
{
	const QString zipFile = QCoreApplication::applicationDirPath() + QDir::separator()
    + trUtf8( "help_pl.tar.bz2" );
  if( QFile::exists(	zipFile ) )
		QFile::remove( zipFile );
}
    
void MyWindow::showHelpDecompressError()
{ 
  QMessageBox::critical( this, trUtf8( "Error" ),
    trUtf8( "Błąd. Nie można otworzyć pliku pomocy."
              "\n(Problem z dekompresją zasobów)." ) );
		showHelpAction();
}
#endif
// obrazki ktore nie sa wyswietlane to jpeg!, trzeba zbudowac i zlinkowac z jpeg
void MyWindow::updateTranslation()
{
  QLocale locOK;
  qApp->removeTranslator( mNprTranslator );
  qApp->removeTranslator( mQtTranslator );

  if( mMainWindow->actionEnglishLanguage->isChecked() ) {
      const QLocale loc( QLocale::English, QLocale::UnitedKingdom );
      locOK = loc;
      mQtTranslator->load( ":/translations/qt_uk.qm" );
      mNprTranslator->load( ":/translations/metody_naturalne_uk.qm" );
    } else if( mMainWindow->actionPolishLanguage->isChecked() ) {
      const QLocale loc( QLocale::Polish, QLocale::Poland );
      locOK = loc;
      mQtTranslator->load( ":/translations/qt_pl.qm" );
      mNprTranslator->load( ":/translations/metody_naturalne_pl.qm" );
    } //else

    QMainWindow::setLocale( locOK );
    QLocale::setDefault( locOK );
  //-----------------------------------

  qApp->installTranslator( mNprTranslator );
  qApp->installTranslator( mQtTranslator );

  //--------- Update app ----------------
  qApp->setApplicationName( QObject::trUtf8( "Asystent NPR" ) );
  qApp->setApplicationVersion( QObject::trUtf8( "Wersja 1.4 beta" ) );
  //--------- Update menu ---------------
  mMainWindow->retranslateUi( this );
  mMainWindow->tabWidget->setLocale( locOK );

  QString title = mMainWindow->tabWidget->tabText( 0 );
  //--------- Update pageTab -------------
  for( int i = 0; i < mViewWidgets.size(); i++ ) {
    boost::shared_ptr< Ui_ViewWidget > viewWidget = mViewWidgets[ i ].get()->getViewWidget();
    retranslate( viewWidget.get(), locOK );
    viewWidget->retranslateUi( viewWidget->scrollAreaWidgetContents );

    QString text = mMainWindow->tabWidget->tabText( i );
    const QString sep( " " );
    QString number = text.section( sep, 1, 1 );
    title = title.section( sep, 0, 0 ) + sep + number;
    mMainWindow->tabWidget->setTabText( i , title );
    mMainWindow->tabWidget->setTabToolTip( i , title ); 
    viewWidget->graphSupplement->updateTranslation();
  } //for
  emit languageChange();
}
// popraw tlumaczenie na wykresie "Oznaczenia:"
void MyWindow::retranslate( Ui_ViewWidget* viewWidget, const QLocale& loc )
{
  viewWidget->graphicsView->setLocale( loc );
  viewWidget->graphSupplement->setLocale( loc );
  viewWidget->label_description->setLocale( loc );
  viewWidget->dateObservation->setLocale( loc );
  viewWidget->label_hour->setLocale( loc );
  viewWidget->timeEdit->setLocale( loc );
  viewWidget->lineFertility->setLocale( loc );
  viewWidget->labelFertility->setLocale( loc );
  viewWidget->lineNotFertility->setLocale( loc );
  viewWidget->labelNotFertility->setLocale( loc );
  viewWidget->lineMaybeFertility->setLocale( loc );
  viewWidget->labelMaybeFertility->setLocale( loc );
}

void MyWindow::showAbout()
{
  Ui_About about;
  QWidget* w = new QWidget;
  w->setAttribute( Qt::WA_DeleteOnClose, true );
  about.setupUi( w );
  w->setLocale( QLocale() );
  about.closeButton->setLocale( QLocale() );
  about.label->setLocale( QLocale() );
  about.retranslateUi( w );
  w->show();
  w->setWindowModality( Qt::ApplicationModal );
  mMainWindow->actionAbout->setDisabled( true );
  connect( about.closeButton, SIGNAL(clicked()), this, SLOT(showAboutAction()) );
}

void MyWindow::showHelpAction()
{
  //cleanUpHelpFiles();
	mMainWindow->actionHelp->setEnabled( true );
}

void MyWindow::showLanguageMenu()
{
  mMainWindow->menuLanguage->setEnabled( true );
}

void MyWindow::showAboutAction()
{
  mMainWindow->actionAbout->setEnabled( true );
}

void MyWindow::autointerpretationGraphs( const bool& on ) {
  for( int i = 0; i < mViewWidgets.size(); i++ )
    autointerpretationGraphs( on, i );
}

void MyWindow::autointerpretationGraphs( const bool& on, const int& cIndex ) {
    boost::shared_ptr< Ui_ViewWidget > vw = mViewWidgets[ cIndex ].get()->getViewWidget();
    if( vw.get() ) {
      QList< MoveablePoint* > mpoints = vw->graphicsView->getPoints();
      QList< ImagePoint* > ipoints = vw->graphSupplement->getPoints();
      if( on ) {
        connect( vw->graphicsView, SIGNAL(createPoint()), this, SLOT(interpretationGraph()) );
        connect( vw->graphSupplement, SIGNAL(createPoint()), this, SLOT(interpretationGraph()) );
      } else {
        disconnect( vw->graphicsView, SIGNAL(createPoint()), this, SLOT(interpretationGraph()) );
        disconnect( vw->graphSupplement, SIGNAL(createPoint()), this, SLOT(interpretationGraph()) );
      } //else

      for( QList< MoveablePoint* >::const_iterator it = mpoints.begin();
        it != mpoints.end(); it++ ) {
        if( on )
          myPointsConnect( *it );
        else
          myPointsDisconnect( *it );

      } //for
      //----------------------------------------------------
      for( QList< ImagePoint* >::const_iterator it = ipoints.begin();
        it != ipoints.end(); it++ ) {
        if( on )
          myPointsConnect( *it );
        else
          myPointsDisconnect( *it );
      } //for

    } //if
}

void MyWindow::myPointsConnect( MoveablePoint* mp )
{
  connect( mp, SIGNAL( deletePointSignal() ), this, SLOT( interpretationGraph() ) );
  connect( mp, SIGNAL( stateChange() ), this, SLOT( interpretationGraph() ) );
}

void MyWindow::myPointsDisconnect( MoveablePoint* mp )
{
  disconnect( mp, SIGNAL( deletePointSignal() ), this, SLOT( interpretationGraph() ) );
  disconnect( mp, SIGNAL( stateChange() ), this, SLOT( interpretationGraph() ) );
}

void MyWindow::myPointsConnect( ImagePoint* ip )
{
  connect( ip, SIGNAL( deletePointSignal() ), this, SLOT( interpretationGraph() ) );
  connect( ip, SIGNAL( stateChange() ), this, SLOT( interpretationGraph() ) );
}

void MyWindow::myPointsDisconnect( ImagePoint* ip )
{
  disconnect( ip, SIGNAL( deletePointSignal() ), this, SLOT( interpretationGraph() ) );
  disconnect( ip, SIGNAL( stateChange() ), this, SLOT( interpretationGraph() ) );
}

void MyWindow::addNextFertilities()
{
  RectOFFertilities rectMaybeFertility;
  rectMaybeFertility.get<0>() = 0;
  rectMaybeFertility.get<1>() = 0;

  RectOFFertilities rectNotFertility;
  rectNotFertility.get<0>() = 0;
  rectNotFertility.get<1>() = 0;

  RectOFFertilities rectFertility;
  rectFertility.get<0>() = 0;
  rectFertility.get<1>() = 0;

  mFertilities.push_back( boost::make_tuple( rectMaybeFertility, rectFertility, rectNotFertility ) );
}

void MyWindow::clean()
{
  const int cIndex = mMainWindow->tabWidget->currentIndex();
  if( cIndex < 0 )
    return;
  mViewWidgets[ cIndex ].get()->getViewWidget()->scrollAreaWidgetContents->setEnabled( false );
  cleanImpl( mFertilities[ cIndex ].get<0>()/*rectMaybeFertility*/, cIndex );
  cleanImpl( mFertilities[ cIndex ].get<1>()/*rectNotFertility*/, cIndex );
  cleanImpl( mFertilities[ cIndex ].get<2>()/*rectFertility*/, cIndex );
  mViewWidgets[ cIndex ].get()->getViewWidget()->scrollAreaWidgetContents->setEnabled( true );
}

void MyWindow::setLocale( QDateEdit* dt )
{
  if( mMainWindow->actionEnglishLanguage->isChecked() ) {
      const QLocale loc( QLocale::English, QLocale::UnitedKingdom );
      dt->setLocale( loc );
    } else if( mMainWindow->actionPolishLanguage->isChecked() ) {
      const QLocale loc( QLocale::Polish, QLocale::Poland );
      dt->setLocale( loc );
    } //else

}

const QLocale MyWindow::getLocale() const
{
    if( mMainWindow->actionEnglishLanguage->isChecked() )
      return QLocale( QLocale::English, QLocale::UnitedKingdom );
    return QLocale( QLocale::Polish, QLocale::Poland );
}

void MyWindow::preparePrinter()
{
  mPrinter = new QPrinter( QPrinterInfo::defaultPrinter() , QPrinter::HighResolution );
  mPrinter->setOrientation( QPrinter::Landscape );
  //---------------------------------------------------

  connect( mMainWindow->actionPageSetting, SIGNAL(triggered()), this, SLOT(pageSetup()) );
  connect( mMainWindow->actionPrintPreview, SIGNAL(triggered()), this, SLOT(printPreview()) );
  connect( mMainWindow->actionPrintToPDF, SIGNAL(triggered()), this, SLOT(printToPDF() ) );

  connect( mMainWindow->actionPrintAllToPDF, SIGNAL(triggered()), this, SLOT(printAllToPDF() ) );
  connect( mMainWindow->actionPrintPreviews, SIGNAL(triggered()), this, SLOT(printPreviews()) );

  connect( mMainWindow->actionPrint, SIGNAL(triggered()), this, SLOT(printerConfiguration()) );

  connect( mMainWindow->actionAutoScale, SIGNAL(toggled(bool)), mMainWindow->actionPrintToPDF,
           SLOT(setEnabled(bool)) );
  connect( mMainWindow->actionAutoScale, SIGNAL(toggled(bool)), mMainWindow->actionPrintPreview,
           SLOT(setEnabled(bool)) );
  connect( mMainWindow->actionAutoScale, SIGNAL(toggled(bool)), mMainWindow->actionPrintPreviews,
           SLOT(setEnabled(bool)) );
  connect( mMainWindow->actionAutoScale, SIGNAL(toggled(bool)), mMainWindow->actionPrintAllToPDF,
           SLOT(setEnabled(bool)) );
}

void MyWindow::printAllToPDF()
{
  printToPDF( true );
}

 void MyWindow::printPreviews( QPrinter* preview )
 {
  Q_UNUSED( preview );
  print( 5.04, true );
 }

 void MyWindow::printPreview( QPrinter* preview )
 {
  Q_UNUSED( preview );
  print();
 }

void MyWindow::pageSetup()
{
  QPageSetupDialog pageSetupDialog( mPrinter, this );
  pageSetupDialog.exec();
}

void MyWindow::printPreview()
{
  QPrintPreviewDialog printPreviewDialog( mPrinter, this,
                                            Qt::WindowMaximizeButtonHint
                                          | Qt::WindowCloseButtonHint
                                          | Qt::CustomizeWindowHint );
  connect( &printPreviewDialog, SIGNAL(paintRequested(QPrinter *)), this, SLOT(printPreview( QPrinter*) ) );
  //----------------------------------------------------------
  printPreviewDialog.setGeometry( geometry() );
  printPreviewDialog.exec() ;
}

void MyWindow::printPreviews()
{
  QPrintPreviewDialog printPreviewDialog( mPrinter, this,
                                          Qt::WindowMaximizeButtonHint
                                        | Qt::WindowCloseButtonHint
                                        | Qt::CustomizeWindowHint );
  connect( &printPreviewDialog, SIGNAL(paintRequested(QPrinter *)), this, SLOT(printPreviews( QPrinter*) ) );
  //----------------------------------------------------------
  printPreviewDialog.setGeometry( geometry() );
  printPreviewDialog.exec();
}

void MyWindow::printerConfiguration()
{
  QPrintDialog printDialog( mPrinter, this );
  printDialog.addEnabledOption(QAbstractPrintDialog::PrintPageRange);
  printDialog.addEnabledOption(QAbstractPrintDialog::PrintCollateCopies);
  if( printDialog.exec() == QDialog::Accepted )
    print();
}

void MyWindow::printToPDF( const bool& isForEach )
{
  QString fileName = QFileDialog::getSaveFileName( this, trUtf8("Eksport do formatu PDF"), QDir::homePath(), "*.pdf");
    if (!fileName.isEmpty()) {
      if (QFileInfo(fileName).suffix().isEmpty())
        fileName.append(".pdf");
      mPrinter->setOutputFormat( QPrinter::PdfFormat );
      mPrinter->setOutputFileName(fileName);
      print( 10.0, isForEach ); // 1000% dla pdf
      mPrinter->setOutputFormat( QPrinter::NativeFormat );
     }
}

void MyWindow::print( const qreal& scale, const bool& isForEach )
{
  const int cIndex = mMainWindow->tabWidget->currentIndex();
  if( cIndex < 0 )
    return;
    QPainter painter( mPrinter );
    painter.save();
    if( mMainWindow->actionAutoScale->isChecked() )
      painter.scale( scale, scale );
    if( isForEach ) {
      //Dlatego ze jest juz jedna strona:
      mViewWidgets[ 0 ].get()->getViewWidget()->printWidget->render( &painter );
      for( int i = 1; i < mViewWidgets.size(); i++ ) {
        mPrinter->newPage();
        mViewWidgets[ i ].get()->getViewWidget()->printWidget->render( &painter );
      } //for
    } else {
      mViewWidgets[ cIndex ].get()->getViewWidget()->printWidget->render( &painter );
    } // else
    painter.restore();
    // Przeskaluj 504% i jest dobrze na A4
}

void MyWindow::zoomIn()
{
  const int cIndex = mMainWindow->tabWidget->currentIndex();
  if( cIndex < 0 )
    return;
  int scaleCount = mViewWidgets[ cIndex ].get()->getScaleCount();
  scaleCount++;
  mViewWidgets[ cIndex ].get()->setScaleCount( scaleCount );
  zoom( 1/scaleView );
}

void MyWindow::zoomOut()
{
 const int cIndex = mMainWindow->tabWidget->currentIndex();
  if( cIndex < 0 )
    return;
  int scaleCount = mViewWidgets[ cIndex ].get()->getScaleCount();
  scaleCount--;
  mViewWidgets[ cIndex ].get()->setScaleCount( scaleCount );
  zoom( scaleView );
}

void MyWindow::zoom( const qreal& newScale )
{
  const int cIndex = mMainWindow->tabWidget->currentIndex();
  if( cIndex < 0 )
    return;

  mMainWindow->tabWidget->setEnabled( false );
  mViewWidgets[ cIndex ].get()->getViewWidget()->graphicsView->scaleView( newScale );
  mViewWidgets[ cIndex ].get()->getViewWidget()->graphSupplement->scaleView( newScale );
  const int scaleCount = mViewWidgets[ cIndex ].get()->getScaleCount();
  switch( scaleCount ) {
    case 1:
      setScale( getDefaultVerticalLayoutGeometry(),
                getDefaultGraphicsViewGeometry(),
                getDefaultGraphicsSupplementGeometry() );
      mMainWindow->actionZoomOut->setEnabled( false );
      mMainWindow->actionZoomIn->setEnabled( true );
    break;

    case 2:
      setScale( QRect( 12, 22, 1450, 1000 ),  QRect( 12, 330, 1450, 700 ), QRect( 12, 600, 1450, 270) );
      mMainWindow->actionZoomOut->setEnabled( true );
      mMainWindow->actionZoomIn->setEnabled( true );
    break;

    case 3:
     setScale( QRect( 12, 22, 1650, 1300),  QRect( 12, 460, 1450, 800 ), QRect( 12, 700, 1450, 300 ) );
      mMainWindow->actionZoomIn->setEnabled( false );
      mMainWindow->actionZoomOut->setEnabled( true );
    break;
  }

  //------------------------------------------------------
   mMainWindow->tabWidget->setEnabled( true );
}

void MyWindow::setScale( const QRect& geo, const QRect& geoV,  const QRect& geoS )
{
  const int cIndex = mMainWindow->tabWidget->currentIndex();
  if( cIndex < 0 )
    return;
  //------------------------------------------------------
  mViewWidgets[ cIndex ].get()->getViewWidget()->verticalLayout->setGeometry( geo );

  mViewWidgets[ cIndex ].get()->getViewWidget()->graphicsView->setFixedHeight( geoV.height() );
  mViewWidgets[ cIndex ].get()->getViewWidget()->scrollAreaWidgetContents->setFixedWidth( geo.width() );
  mViewWidgets[ cIndex ].get()->getViewWidget()->graphicsView->setGeometry( geoV );
  //-------------------------------------------------------
  mViewWidgets[ cIndex ].get()->getViewWidget()->graphSupplement->setFixedHeight( geoS.height() );
  mViewWidgets[ cIndex ].get()->getViewWidget()->graphSupplement->setGeometry( geoS );
  mViewWidgets[ cIndex ].get()->getViewWidget()->graphicsView->move( geoV.x(), geoV.y() );
}

QRect MyWindow::getDefaultGraphicsViewGeometry() const
{
  static QRect geoV = mViewWidgets[ 0 ].get()->getViewWidget()->graphicsView->geometry();
  return geoV;
}

QRect MyWindow::getDefaultVerticalLayoutGeometry() const
{
  static QRect geo = mViewWidgets[ 0 ].get()->getViewWidget()->verticalLayout->geometry();
  return geo;
}

QRect MyWindow::getDefaultGraphicsSupplementGeometry() const
{
  static QRect geoS = mViewWidgets[ 0 ].get()->getViewWidget()->graphSupplement->geometry();
  return geoS;
}

void MyWindow::saveImpl( QList< boost::shared_ptr< MyViewWidget > >& pViewWidgets, const int& cIndex, const bool& isSaveUs )
{
  pViewWidgets[ cIndex ].get()->getViewWidget()->scrollAreaWidgetContents->setEnabled( false );
  QString filename = pViewWidgets[ cIndex ].get()->getFileName();
  if( filename.isEmpty() || isSaveUs )
    filename = QFileDialog::getSaveFileName( this,
      trUtf8("Zapis pliku"), QDir::homePath(), trUtf8("Pliki npr (*.npr)") );
  
  if( filename.isEmpty() ) {
    pViewWidgets[ cIndex ].get()->getViewWidget()->scrollAreaWidgetContents->setEnabled( true );
    return;
  }
  
  if( !filename.endsWith( ".npr" ) )
    filename += ".npr";
  
  QFile file( filename );
  if( !file.open( QIODevice::WriteOnly ) ) {
    QMessageBox::critical( this, trUtf8("Błąd"), trUtf8("Wystąpił błąd zapisu do pliku."), QMessageBox::Close );
    pViewWidgets[ cIndex ].get()->getViewWidget()->scrollAreaWidgetContents->setEnabled( true );
    return;
  } // if
  
  pViewWidgets[ cIndex ].get()->setFileName( filename );
  QByteArray arb;
  QDataStream ds( &arb, QIODevice::WriteOnly );
  pViewWidgets[ cIndex ].get()->getViewWidget()->graphicsView->save( ds );
  pViewWidgets[ cIndex ].get()->getViewWidget()->graphSupplement->save( ds );
  ds << pViewWidgets[ cIndex ].get()->getViewWidget()->dateObservation->date();
  const QDateTime dt = pViewWidgets[ cIndex ].get()->getViewWidget()->timeEdit->dateTime();
  ds << dt;
  file.write( qCompress( arb, 8 ) );
  //--------------------------------------------------------------------
  updateTabTitleWithOutStar( cIndex );
  mViewWidgets[ cIndex ].get()->setNeedSave( false );  //--------------------------------------------------------------------
  pViewWidgets[ cIndex ].get()->getViewWidget()->scrollAreaWidgetContents->setEnabled( true );
}

void MyWindow::updateTabTitleWithStar( const int& cIndex )
{
  QString tabTitle = mMainWindow->tabWidget->tabText( cIndex );
  if( !tabTitle.endsWith( "*") ) {
    tabTitle.append( "*" );
    mMainWindow->tabWidget->setTabText( cIndex, tabTitle );
  }
}

void MyWindow::save( const bool& isSaveUs )
{
  const int cIndex = mMainWindow->tabWidget->currentIndex();
  if( cIndex < 0 )
    return;
  saveImpl( mViewWidgets, cIndex, isSaveUs );
}

void MyWindow::saveAs()
{
  save( true );
}

void MyWindow::load()
{
  const int cIndex = mMainWindow->tabWidget->currentIndex();
  if( cIndex < 0 )
    return;
  mViewWidgets[ cIndex ].get()->getViewWidget()->scrollAreaWidgetContents->setEnabled( false );
  const QString filename = QFileDialog::getOpenFileName( this,
     trUtf8("Odczyt pliku"), QDir::homePath(), trUtf8("Pliki npr (*.npr)") );
  
  if( filename.isEmpty() ) {
    mViewWidgets[ cIndex ].get()->getViewWidget()->scrollAreaWidgetContents->setEnabled( true );
    return;
  }
  
  updateTabTitleWithOutStar( cIndex );
  mViewWidgets[ cIndex ].get()->setNeedSave( false );
  
  QFile file( filename );
  if( !file.open( QIODevice::ReadOnly ) ) {
    QMessageBox::critical( this, trUtf8("Błąd"), trUtf8("Wystąpił błąd odczytu pliku."), QMessageBox::Close );
    mViewWidgets[ cIndex ].get()->getViewWidget()->scrollAreaWidgetContents->setEnabled( true );
    return;
  } // if

  mViewWidgets[ cIndex ].get()->setFileName( filename );
  clean();
  if( mMainWindow->actionAutointerpretation->isChecked() )
    autointerpretationGraphs( false, cIndex );
  //----------------------------------------------------
  QByteArray bar( qUncompress( file.readAll() ) );
  QDataStream ds( bar );
  mViewWidgets[ cIndex ].get()->getViewWidget()->graphicsView->load( ds );
  mViewWidgets[ cIndex ].get()->getViewWidget()->graphSupplement->load( ds );
  QDate tDate;
  ds >> tDate;
  mViewWidgets[ cIndex ].get()->getViewWidget()->dateObservation->setDate( tDate );
  QDateTime dTime;
  ds >> dTime;
  mViewWidgets[ cIndex ].get()->getViewWidget()->timeEdit->setDateTime( dTime );
  //----------------------------------------------------
  if( mMainWindow->actionAutointerpretation->isChecked() )
    autointerpretationGraphs( true, cIndex );
  
  //--------------------------------------------------------------------
  updateTabTitleWithOutStar( cIndex );
  mViewWidgets[ cIndex ].get()->setNeedSave( false );
  //--------------------------------------------------------------------
  mViewWidgets[ cIndex ].get()->getViewWidget()->scrollAreaWidgetContents->setEnabled( true );
}

void MyWindow::addPageTab()
{
  QWidget* pageTab =  new QWidget();
  //! pageTab->setAttribute( Qt::WA_DeleteOnClose, true );
  QString title = mMainWindow->tabWidget->tabText( 0 );

  const QString sep( " " );
  title = title.section( sep, 0, 0 ) + sep + QString::number( mViewWidgets.size() + 1 );
  const int lastIndex = mMainWindow->tabWidget->count();
  mMainWindow->tabWidget->addTab( pageTab, title ); // Bez smart_prt - rodzic posprzata
  mMainWindow->tabWidget->setTabToolTip( lastIndex, title ); 
  //----------------------------------------------------
  const bool isAutoIntrpet = mMainWindow->actionAutointerpretation->isChecked();
  if( isAutoIntrpet )
    autointerpretationGraphs( isAutoIntrpet, lastIndex );

  //----------------------------------------------------
  boost::shared_ptr< Ui_ViewWidget > viewWidget = boost::shared_ptr< Ui_ViewWidget > ( new Ui_ViewWidget );
  viewWidget->setupUi( pageTab );

  mViewWidgets.push_back( boost::shared_ptr< MyViewWidget > ( new MyViewWidget( viewWidget, 1, false, this ) ) );
  const int newIndex = mViewWidgets.size() - 1;
  //----------------------------------------------------
  connectNeedSaveGraphs( newIndex );
  //----------------------------------------------------
  
  
  mViewWidgets[ newIndex ].get()->getViewWidget()->graphicsView->setTemperatureObjectName( mTemperatures );
  mViewWidgets[ newIndex ].get()->getViewWidget()->graphSupplement->ignorePointName( mTemperatures );
  mMainWindow->tabWidget->setCurrentWidget( pageTab );
  //----------------------------------------------------
  setLocale(  viewWidget->dateObservation );
  viewWidget->dateObservation->setDate( QDate::currentDate() );
  addNextFertilities();
  retranslate( viewWidget.get(), QLocale() );
}

void MyWindow::removePageTab( const int& pageIndex )
{
  if( ( mViewWidgets.size() > 1 )  && ( pageIndex > 0 ) ) {
    mMainWindow->tabWidget->setCurrentIndex( pageIndex - 1 );
    mMainWindow->tabWidget->removeTab( pageIndex );
    mViewWidgets.removeAt( pageIndex );
    eraseFertility( pageIndex );
  } //if
}

void MyWindow::eraseFertility( const int cIndex )
{
  cleanImpl( mFertilities[ cIndex ].get< 0 >() , cIndex);
  cleanImpl( mFertilities[ cIndex ].get< 1 >(), cIndex );
  cleanImpl( mFertilities[ cIndex ].get< 2 >(), cIndex );
  mFertilities.removeAt( cIndex );
}

void MyWindow::removePageTab()
{
  const int cIndex = mMainWindow->tabWidget->currentIndex();
  removePageTab( cIndex );
}

void MyWindow::configMenuScale( const int& pageIndex )
{
  if( pageIndex < 0 )
    return;
  const int scaleCount = mViewWidgets[ pageIndex ].get()->getScaleCount();
  switch( scaleCount ) {
    case 1:
      mMainWindow->actionZoomIn->setEnabled( true ); // Powieksz dostepne
      mMainWindow->actionZoomOut->setEnabled( false ); // Pomniejsz niedostepne
    break;
    case 2:
      mMainWindow->actionZoomIn->setEnabled( true ); // Powieksz dostepne
      mMainWindow->actionZoomOut->setEnabled( true ); // Pomniejsz dostepne
    break;
    case 3:
      mMainWindow->actionZoomIn->setEnabled( false ); // Powieksz niedostepne
      mMainWindow->actionZoomOut->setEnabled( true ); // Pomniejsz dostepne
    break;
  }

}

void MyWindow::interpretationGraph()
{
  clean();
  const int cIndex = mMainWindow->tabWidget->currentIndex();
  if( cIndex < 0 )
    return;
  mViewWidgets[ cIndex ].get()->getViewWidget()->scrollAreaWidgetContents->setEnabled( false );
  //-------------------------------
  InterpretationByTemperature it( mViewWidgets[ cIndex ].get()->getViewWidget()->graphicsView );
  InterpretationByMucus im( mViewWidgets[ cIndex ].get()->getViewWidget()->graphSupplement );

  const boost::tuple< int, QPointF > b1 = it.beginPhase1();
  const boost::tuple< int, QPointF > b1too = im.beginPhase1();
  boost::tuple< int, QPointF > e1 = im.endPhase1();
  boost::tuple< int, QPointF > p1b;

  if( b1.get<0>() > -1 )
    p1b = b1;
  if( b1too.get<0>() > -1 )
    p1b = b1too;
  if( ( b1too.get<0>() > -1 ) && ( b1.get<0>() > -1 ) ) {
    if ( b1.get<0>() < b1too.get<0>() )
      p1b = b1;
    else p1b = b1too;
  } //if
  //-----------------------------
  const QPalette pal1 =  mViewWidgets[ cIndex ].get()->getViewWidget()->lineMaybeFertility->palette();

  //-----------------------------
  const bool withFive = mMainWindow->actionPresenceOfMucusByFiveDays->isChecked();
  boost::tuple< int, QPointF > b2 = im.beginPhase2( withFive );
  const boost::tuple< int, QPointF > e2 = it.endPhase2();

  const QPalette pal2 =  mViewWidgets[ cIndex ].get()->getViewWidget()->lineFertility->palette();
  //-----------------------------
  // Gdy faza 1 konczy się poxniej niz zaczyna faza 2
  if( ( e1.get<0>() > b2.get<0>() )
    || ( qRound( e1.get<1>().x() ) > qRound( b2.get<1>().x() ) )
    ) {
    const int meshWay = mViewWidgets[ cIndex ].get()->getViewWidget()->graphicsView->getStepWay();
    e1.get<0>() = b2.get<0>() - 1;
    QPointF pp = e1.get<1>();
    pp.setX( qRound( b2.get<1>().x() ) - meshWay );
    e1.get<1>() = pp;
  } //if
  //-----------------------------
  const boost::tuple< int, QPointF > b3 = it.beginPhase3();
  const boost::tuple< int, QPointF > e3 = it.endPhase3();

  const QPalette pal3 =  mViewWidgets[ cIndex ].get()->getViewWidget()->lineNotFertility->palette();
  //-----------------------------

  createPhase( p1b, e1, pal1, cIndex, mFertilities[ cIndex ].get<0>()/*rectMaybeFertility*/ );
  createPhase( b2, e2, pal2, cIndex, mFertilities[ cIndex ].get<1>()/*rectFertility*/ );
  createPhase( b3, e3, pal3, cIndex, mFertilities[ cIndex ].get<2>()/*rectNotFertility*/ );

  mViewWidgets[ cIndex ].get()->getViewWidget()->scrollAreaWidgetContents->setEnabled( true );
}

void MyWindow::createPhase( const boost::tuple< int, QPointF >& begin,
  const boost::tuple< int, QPointF >& end, const QPalette& pal, const int& cIndex,
  RectOFFertilities& rectFertilityDescription )
{
  if( ( begin.get<0>() > -1 ) && ( end.get<0>() > -1 ) ) {
    QBrush br = pal.brush( QPalette::Active, QPalette::WindowText );
    QColor color = br.color();
    color.setAlphaF( 0.4 );
    br.setColor( color );
    //-----------------------------------------
    const QRectF areaV = mViewWidgets[ cIndex ].get()->getViewWidget()->graphicsView->getArea();
    QGraphicsScene* sceneV = mViewWidgets[ cIndex ].get()->getViewWidget()->graphicsView->getScene();
    //-----------------------------------------
    const QRectF areaS = mViewWidgets[ cIndex ].get()->getViewWidget()->graphSupplement->getArea();
    QGraphicsScene* sceneS = mViewWidgets[ cIndex ].get()->getViewWidget()->graphSupplement->getScene();

    rectFertilityDescription.get<0>() = sceneV->addRect( begin.get<1>().x(), areaV.y(),
      end.get<1>().x() - begin.get<1>().x(), areaV.height(),
                                                            Qt::NoPen, br );

    //-----------------------------------------

    rectFertilityDescription.get<1>() = sceneS->addRect( begin.get<1>().x(), areaS.y(),
                                                            end.get<1>().x() - begin.get<1>().x(),
                                                            areaS.height(), Qt::NoPen, br );

  }
}

void MyWindow::cleanImpl( RectOFFertilities& rectFertilityDescription, const int& cIndex )
{
    if( rectFertilityDescription.get<0>() ) {
      QGraphicsScene* sceneV = mViewWidgets[ cIndex ].get()->getViewWidget()->graphicsView->getScene();
      QGraphicsScene* sceneS = mViewWidgets[ cIndex ].get()->getViewWidget()->graphSupplement->getScene();

      sceneV->removeItem( rectFertilityDescription.get<0>() );
      sceneS->removeItem( rectFertilityDescription.get<1>() );
      rectFertilityDescription.get<0>() = 0;
      rectFertilityDescription.get<1>() = 0;
    }
}

void MyWindow::clearView()
{
  const int cIndex = mMainWindow->tabWidget->currentIndex();
  if( cIndex < 0 )
    return;
  clean();
  updateTabTitleWithOutStar( cIndex );
  mViewWidgets[ cIndex ].get()->setNeedSave( false );
  // Celowo aby nie nadpisac sobie wykresunowym wyczyszczonym:
  mViewWidgets[ cIndex ].get()->setFileName( "" );
  mViewWidgets[ cIndex ].get()->getViewWidget()->graphicsView->clear();
  mViewWidgets[ cIndex ].get()->getViewWidget()->graphSupplement->clear();
}

void MyWindow::changeStyle(const QString &styleName)
{
  QApplication::setStyle(QStyleFactory::create(styleName));
  QApplication::setPalette( QApplication::style()->standardPalette() );
}

void MyWindow::closeEvent( QCloseEvent *event )
{
  QList< boost::shared_ptr< MyViewWidget > > res;
  BOOST_FOREACH( boost::shared_ptr< MyViewWidget > myview, mViewWidgets ) {
      if( myview && myview->isNeedSave() )
        res.push_back( myview );
  } //for_each
  if( !res.isEmpty() ) {
    QMessageBox::StandardButton ret;
    ret = QMessageBox::warning(this, trUtf8( "Uwaga" ),
              trUtf8( "One of some bookmarks has been modified.\n"
                        "Do you want to save your changes?" ),
              QMessageBox::SaveAll | QMessageBox::Discard | QMessageBox::Cancel );
    if( ret == QMessageBox::SaveAll ) {
      saveAll( res );
      event->accept();
      QMainWindow::closeEvent(event);
      emit beforeClose();
      return;
    } else if ( ret == QMessageBox::Cancel ) {
        event->ignore();
        return;
    } else if ( ret == QMessageBox::Discard ) {
        event->accept();
        QMainWindow::closeEvent(event);
        emit beforeClose();
        return;
    } // else
  } //if
  QMainWindow::closeEvent(event);
  emit beforeClose();
}

void MyWindow::saveAll( QList< boost::shared_ptr< MyViewWidget > >& pViewWidgets )
{
  for( int i = 0; i < pViewWidgets.size(); i++)
    saveImpl( pViewWidgets, i, false );
}

void MyWindow::updateTabTitle()
{
  const int cIndex = mMainWindow->tabWidget->currentIndex();
  if( cIndex < 0 )
    return;
  updateTabTitleWithStar( cIndex );
}

void MyWindow::updateTabTitleWithOutStar( const int& cIndex )
{
  QString tabTitle = mMainWindow->tabWidget->tabText( cIndex );
  if( tabTitle.endsWith( "*") ) {
    const int count = tabTitle.size();
    tabTitle.remove( count - 1, 1 );
    mMainWindow->tabWidget->setTabText( cIndex, tabTitle );
  } //if
}
