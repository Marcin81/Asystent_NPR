/*
License: GPL 
Owner: Marcin Brysz
Contact: unemployed81@gmail.com / bryszmarcin@gmail.com
Version: 1.3 Beta
*/
#include <QtGui/QApplication>
#include <QtCore/QTranslator>
#include <QtCore/QTextCodec>
#include <QtGui/QHBoxLayout>
#include "dragwidget.h"
#include "hidetoolwindow.h"
#include "mywindow.h"
#include <boost/tuple/tuple.hpp>
#include <boost/assign/list_of.hpp>
#include <QtCore/QtDebug>
#include <QtGui/QMessageBox>

int main(int argc, char *argv[])
{
  QTextCodec::setCodecForCStrings( QTextCodec::codecForName( "UTF-8" ) );
  QTranslator qtTranslator;
  QTranslator nprTranslator;
  QApplication app(argc, argv );
  //! QMessageBox::warning( 0, "argc:", QString::number( argc ), QMessageBox::Ok );
  // When you try open new instance of app without argument
  // Quit new instance of this application when we run a new instance this application
  if( QCoreApplication::instance() && (argc ==1) )
    app.quit();
 // Dokoncz, zawsze jest instancja jak jedna aplikacja zostaje uruchomiona jednak niezaleznie od parametrow przekazanych w 2 wywolaniu argc == 1, why skoro powinna wynosic 2 ?
  // moze polecenie open w tym wypadku trzeba parametryzowac inaczej ?
// open -a "/Users/marcinbrysz/programowanie/Qt 4.5/asystent npr/Asystent NPR.app" --args dupa
  // Open new pageTab:
  if( argc > 1 && QCoreApplication::instance() ) {
    QStringList ls = QCoreApplication::arguments();
    ls.removeFirst();
    QMessageBox::warning( 0, "kupa", ls.join( " "), QMessageBox::Ok );
    QCoreApplication* lastApp = QCoreApplication::instance();
    MyWindow* lastMyWindow = lastApp->findChild< MyWindow* >( "MyWindow" );
    if( lastMyWindow ) {
      // check: is file exist and is file has got suppfix .npr
      lastMyWindow->addPageTab();
    } // if
  }  

  //QMessageBox::warning( 0, "sas", QString::number( argc ), QMessageBox::Ok );
  //ale przez wskaznik "starej" aplikacji, i znajdz odpowiednie dziecko
  
  // Open in this pageTab -> when first instance is starting
  if( !QCoreApplication::instance() && (argc > 1) ) {
    
  }
  
  app.setApplicationName( QObject::trUtf8( "Asystent NPR" ) );
  app.setApplicationVersion( QObject::trUtf8( "Wersja 1.4 beta" ) );
  
  if( QLocale::system().name() == "pl_PL" ) {
    qtTranslator.load( ":/translations/qt_pl.qm" );
    nprTranslator.load( ":/translations/metody_naturalne_pl.qm" );
  } else {
    qtTranslator.load( ":/translations/qt_uk.qm" );
    nprTranslator.load( ":/translations/metody_naturalne_uk.qm" );  
  }

  app.installTranslator( &nprTranslator );
  app.installTranslator( &qtTranslator );

// Kopia potrzebna do generowania tłumaczeń:
//-----------------------------------------
//  QStringList temperatures;
//  temperatures << "Temperature in lips" << "Temperature in vagina" << "Temperature in anus";
//  std::list< boost::tuple< QString, QString, QString > > mucusNames =
//    boost::assign::list_of
//      ( boost::make_tuple(
//          QObject::trUtf8( "Śluz przeźroczysty" ),
//          QString( ":/images/CyanFull.png" ),
//          QString( "przezroczysty" ) )
//      )
//
//      ( boost::make_tuple(
//          QObject::trUtf8( "Śluz nieprzeźroczysty" ),
//          QString( ":/images/BlueFull.png" ),
//          QString( "nieprzezroczysty" ) )
//      )
//
//      ( boost::make_tuple(
//         QObject::trUtf8( "Śluz rozciągliwy" ),
//         QString( ":/images/YellowFull.png" ),
//         QString( "rozciagliwy" ) )
//      )
//
//      ( boost::make_tuple(
//         QObject::trUtf8( "Śluz nierozciągliwy" ),
//         QString( ":/images/BrownFull.png" ),
//         QString( "nierozciagliwy" ) )
//      )
//
//      ( boost::make_tuple(
//         QObject::trUtf8( "Śluz mętny" ),
//         QString( ":/images/WhiteFull.png" ),
//         QString( "metny" ) )
//      )
//
//      ( boost::make_tuple(
//         QObject::trUtf8( "Śluz lepki" ),
//         QString( ":/images/OrangeFull.png" ),
//         QString( "lepki" ) )
//      )
//
//      ( boost::make_tuple(
//         QObject::trUtf8( "Śluz obfity" ),
//         QString( ":/images/RedFull.png" ),
//         QString( "obfity" ) )
//      )
//
//      ( boost::make_tuple(
//         QObject::trUtf8( "Śluz skąpy" ),
//         QString( ":/images/WhiteEmpty.png" ),
//         QString( "skapy" ) )
//      )
//
//      ( boost::make_tuple(
//         QObject::trUtf8( "Śluz gęsty" ),
//         QString( ":/images/PurpleFull.png" ),
//         QString( "gensty" ) )
//      )
//
//      ( boost::make_tuple(
//         QObject::trUtf8( "Śluz rzadki" ),
//         QString( ":/images/PurpleEmpty.png" ),
//         QString( "rzadki" ) )
//      );
//
//  //----------------------------------------------
//  std::list< boost::tuple< QString, QString, QString > > feelingNames =
//    boost::assign::list_of
//      ( boost::make_tuple(
//         QObject::trUtf8( "Uczucie suchości" ),
//         QString( ":/images/BlankYellow48.png" ),
//         QString( "sucho" ) )
//      )
//
//      ( boost::make_tuple(
//         QObject::trUtf8( "Uczucie wilgotności" ),
//         QString( ":/images/BlankOlive48.png" ),
//         QString( "wilgotno" ) )
//      )
//
//      ( boost::make_tuple(
//         QObject::trUtf8( "Uczucie mokrości" ),
//         QString( ":/images/BlankGreen48.png" ),
//         QString( "mokro" ) )
//      )
//
//      ( boost::make_tuple(
//         QObject::trUtf8( "Okres" ),
//         QString( ":/images/blood-48x48.png" ),
//         QString( "okres" ) )
//      )
//
//      ( boost::make_tuple(
//         QObject::trUtf8( "Napięcie powierzchniowe piersi" ),
//         QString( ":/images/BlankBlue48.png" ),
//         QString( "napiecie_piersi" ) )
//      )
//
//      ( boost::make_tuple(
//         QObject::trUtf8( "Inna godzina pomiaru" ),
//         QString( ":/images/Berry.png" ),
//         QString( "inna_godzina_pomiaru" ) )
//      );
//  //-----------------------------------------------
//  std::list< boost::tuple< QString, QString, QString > > otherNames =
//      boost::assign::list_of
//      ( boost::make_tuple(
//         QObject::trUtf8( "Zmęczenie" ),
//         QString( ":/images/I-am-tired-48x48.png" ),
//         QString( "zmeczenie" ) )
//      )
//
//      ( boost::make_tuple(
//         QObject::trUtf8( "Migrena" ),
//         QString( ":/images/Sweet-angel.png" ),
//         QString( "migrena" ) )
//      )
//
//      ( boost::make_tuple(
//         QObject::trUtf8( "Ból brzucha" ),
//         QString( ":/images/follow-the-sign-48x48.png" ),
//         QString( "bol_brzucha" ) )
//      )
//
//      ( boost::make_tuple(
//         QObject::trUtf8( "Upławy" ),
//         QString( ":/images/Pudently.png" ),
//         QString( "uplawy" ) )
//      )
//
//      ( boost::make_tuple(
//         QObject::trUtf8( "Współżycie" ),
//         QString( ":/images/ThumbsUp.png" ),
//         QString( "wspolzycie" ) )
//      )
//
//      ( boost::make_tuple(
//         QObject::trUtf8( "Pozostałość nasienia" ),
//         QString( ":/images/Whoa-48x48.png" ),
//         QString( "pozostalosc_nasienia" ) )
//      )
//
//      ( boost::make_tuple(
//         QObject::trUtf8( "Biegunka" ),
//         QString( ":/images/ate-someting-bad-48x48.png" ),
//         QString( "biegunka" ) )
//      )
//
//      ( boost::make_tuple(
//         QObject::trUtf8( "Choroba" ),
//         QString( ":/images/h3_48.png" ),
//         QString( "choroba" ) )
//      )
//
//      ( boost::make_tuple(
//         QObject::trUtf8( "Gorączka" ),
//         QString( ":/images/Sick.png" ),
//         QString( "goraczka" ) )
//      )
//
//      ( boost::make_tuple(
//         QObject::trUtf8( "Niedobór snu" ),
//         QString( ":/images/feel-sick-48x48.png" ),
//         QString( "niedobor_snu" ) )
//      )
//
//      ( boost::make_tuple(
//         QObject::trUtf8( "Zmiana klimatu" ),
//         QString( ":/images/Cool.png" ),
//         QString( "zmiana_klimatu" ) )
//      );
//
//  //-----------------------------------------
//  std::list< boost::tuple< QString, QString, QString > > uterusNames =
//    boost::assign::list_of
//      ( boost::make_tuple(
//          QObject::trUtf8( "Szyjka zamknięta" ),
//          QString( ":/images/Mr.Zhong-cute-s_48.png" ),
//          QString( "szyka_zamknieta" ) )
//      )
//
//      ( boost::make_tuple(
//          QObject::trUtf8( "Szyjka otwarta" ),
//          QString( ":/images/Mr.Zhong-laughing-s_48.png" ),
//          QString( "szyjka_otwarta" ) )
//      )
//
//      ( boost::make_tuple(
//         QObject::trUtf8( "Szyjka opuszczona" ),
//         QString( ":/images/Mr.Zhong-punished-s_48.png" ),
//         QString( "szyjka_opuszczona" ) )
//      )
//
//      ( boost::make_tuple(
//         QObject::trUtf8( "Szyjka uniesiona" ),
//         QString( ":/images/Mr.Zhong-suffering-s_48.png" ),
//         QString( "szyjka_uniesiona" ) )
//      )
//
//      ( boost::make_tuple(
//         QObject::trUtf8( "Szyjka twarda" ),
//         QString( ":/images/Mr.Zhong-huffy-s_48.png" ),
//         QString( "szyjka_twarda" ) )
//      )
//
//      ( boost::make_tuple(
//         QObject::trUtf8( "Szyjka miękka" ),
//         QString( ":/images/Mr.Zhong-awkward-s_48.png" ),
//         QString( "szyjka_miekka" ) )
//      );
//
//  //-----------------------------------------
//  std::list< boost::tuple< QString, QString, QString > > temperaturesNames =
//    boost::assign::list_of
//     ( boost::make_tuple(
//        QObject::trUtf8( "Temperatura w ustach" ),
//        QString( ":/images/thermometer-48x48.png" ),
//        QString( temperatures[0] ) )
//      )
//
//     ( boost::make_tuple(
//        QObject::trUtf8( "Temperatura w pochwie" ),
//        QString( ":/images/thermometer-48x48.png" ),
//        QString( temperatures[1] ) )
//      )
//
//     ( boost::make_tuple(
//        QObject::trUtf8( "Temperatura w odbycie" ),
//        QString( ":/images/thermometer-48x48.png" ),
//        QString( temperatures[2] ) )
//      );
  //-----------------------------------------
  QStringList temperatures;
  temperatures << "Temperature in lips" << "Temperature in vagina" << "Temperature in anus";
  std::list< boost::tuple< QString, QString, QString > > mucusNames =
    boost::assign::list_of
      ( boost::make_tuple(
          QString( "Śluz przeźroczysty" ),
          QString( ":/images/CyanFull.png" ),
          QString( "przezroczysty" ) )
      )

      ( boost::make_tuple(
          QString( "Śluz nieprzeźroczysty" ),
          QString( ":/images/BlueFull.png" ),
          QString( "nieprzezroczysty" ) )
      )

      ( boost::make_tuple(
         QString( "Śluz rozciągliwy" ),
         QString( ":/images/YellowFull.png" ),
         QString( "rozciagliwy" ) )
      )

      ( boost::make_tuple(
         QString( "Śluz nierozciągliwy" ),
         QString( ":/images/BrownFull.png" ),
         QString( "nierozciagliwy" ) )
      )

      ( boost::make_tuple(
         QString( "Śluz mętny" ),
         QString( ":/images/WhiteFull.png" ),
         QString( "metny" ) )
      )

      ( boost::make_tuple(
         QString( "Śluz lepki" ),
         QString( ":/images/OrangeFull.png" ),
         QString( "lepki" ) )
      )

      ( boost::make_tuple(
         QString( "Śluz obfity" ),
         QString( ":/images/RedFull.png" ),
         QString( "obfity" ) )
      )

      ( boost::make_tuple(
         QString( "Śluz skąpy" ),
         QString( ":/images/WhiteEmpty.png" ),
         QString( "skapy" ) )
      )

      ( boost::make_tuple(
         QString( "Śluz gęsty" ),
         QString( ":/images/PurpleFull.png" ),
         QString( "gensty" ) )
      )

      ( boost::make_tuple(
         QString( "Śluz rzadki" ),
         QString( ":/images/PurpleEmpty.png" ),
         QString( "rzadki" ) )
      );

  //----------------------------------------------
  std::list< boost::tuple< QString, QString, QString > > feelingNames =
    boost::assign::list_of
      ( boost::make_tuple(
         QString( "Uczucie suchości" ),
         QString( ":/images/BlankYellow48.png" ),
         QString( "sucho" ) )
      )

      ( boost::make_tuple(
         QString( "Uczucie wilgotności" ),
         QString( ":/images/BlankOlive48.png" ),
         QString( "wilgotno" ) )
      )

      ( boost::make_tuple(
         QString( "Uczucie mokrości" ),
         QString( ":/images/BlankGreen48.png" ),
         QString( "mokro" ) )
      )

      ( boost::make_tuple(
         QString( "Okres" ),
         QString( ":/images/blood-48x48.png" ),
         QString( "okres" ) )
      )

      ( boost::make_tuple(
         QString( "Napięcie powierzchniowe piersi" ),
         QString( ":/images/BlankBlue48.png" ),
         QString( "napiecie_piersi" ) )
      )

      ( boost::make_tuple(
         QString( "Inna godzina pomiaru" ),
         QString( ":/images/Berry.png" ),
         QString( "inna_godzina_pomiaru" ) )
      );
  //-----------------------------------------------
  std::list< boost::tuple< QString, QString, QString > > otherNames =
      boost::assign::list_of
      ( boost::make_tuple(
         QString( "Zmęczenie" ),
         QString( ":/images/I-am-tired-48x48.png" ),
         QString( "zmeczenie" ) )
      )

      ( boost::make_tuple(
         QString( "Migrena" ),
         QString( ":/images/Sweet-angel.png" ),
         QString( "migrena" ) )
      )

      ( boost::make_tuple(
         QString( "Ból brzucha" ),
         QString( ":/images/follow-the-sign-48x48.png" ),
         QString( "bol_brzucha" ) )
      )

      ( boost::make_tuple(
         QString( "Upławy" ),
         QString( ":/images/Pudently.png" ),
         QString( "uplawy" ) )
      )

      ( boost::make_tuple(
         QString( "Współżycie" ),
         QString( ":/images/ThumbsUp.png" ),
         QString( "wspolzycie" ) )
      )

      ( boost::make_tuple(
         QString( "Pozostałość nasienia" ),
         QString( ":/images/Whoa-48x48.png" ),
         QString( "pozostalosc_nasienia" ) )
      )

      ( boost::make_tuple(
         QString( "Biegunka" ),
         QString( ":/images/ate-someting-bad-48x48.png" ),
         QString( "biegunka" ) )
      )

      ( boost::make_tuple(
         QString( "Choroba" ),
         QString( ":/images/h3_48.png" ),
         QString( "choroba" ) )
      )

      ( boost::make_tuple(
         QString( "Gorączka" ),
         QString( ":/images/Sick.png" ),
         QString( "goraczka" ) )
      )

      ( boost::make_tuple(
         QString( "Niedobór snu" ),
         QString( ":/images/feel-sick-48x48.png" ),
         QString( "niedobor_snu" ) )
      )

      ( boost::make_tuple(
         QString( "Zmiana klimatu" ),
         QString( ":/images/Cool.png" ),
         QString( "zmiana_klimatu" ) )
      );

  //-----------------------------------------
  std::list< boost::tuple< QString, QString, QString > > uterusNames =
    boost::assign::list_of
      ( boost::make_tuple(
          QString( "Szyjka zamknięta" ),
          QString( ":/images/Mr.Zhong-cute-s_48.png" ),
          QString( "szyka_zamknieta" ) )
      )

      ( boost::make_tuple(
          QString( "Szyjka otwarta" ),
          QString( ":/images/Mr.Zhong-laughing-s_48.png" ),
          QString( "szyjka_otwarta" ) )
      )

      ( boost::make_tuple(
         QString( "Szyjka opuszczona" ),
         QString( ":/images/Mr.Zhong-punished-s_48.png" ),
         QString( "szyjka_opuszczona" ) )
      )

      ( boost::make_tuple(
         QString( "Szyjka uniesiona" ),
         QString( ":/images/Mr.Zhong-suffering-s_48.png" ),
         QString( "szyjka_uniesiona" ) )
      )

      ( boost::make_tuple(
         QString( "Szyjka twarda" ),
         QString( ":/images/Mr.Zhong-huffy-s_48.png" ),
         QString( "szyjka_twarda" ) )
      )

      ( boost::make_tuple(
         QString( "Szyjka miękka" ),
         QString( ":/images/Mr.Zhong-awkward-s_48.png" ),
         QString( "szyjka_miekka" ) )
      );

  //-----------------------------------------
  std::list< boost::tuple< QString, QString, QString > > temperaturesNames =
    boost::assign::list_of
     ( boost::make_tuple(
        QString( "Temperatura w ustach" ),
        QString( ":/images/thermometer-48x48.png" ),
        QString( temperatures[0] ) )
      )

     ( boost::make_tuple(
        QString( "Temperatura w pochwie" ),
        QString( ":/images/thermometer-48x48.png" ),
        QString( temperatures[1] ) )
      )

     ( boost::make_tuple(
        QString( "Temperatura w odbycie" ),
        QString( ":/images/thermometer-48x48.png" ),
        QString( temperatures[2] ) )
      );
  
  MyWindow mainwindow( temperatures,  qtTranslator, nprTranslator );
  mainwindow.show();

  //------------------------------------------------------
  Qt::WindowFlags windowFlags = Qt::Tool | Qt::WindowTitleHint
    | Qt::CustomizeWindowHint | Qt::WindowMaximizeButtonHint
    | Qt::WindowSystemMenuHint;
  const int height = QApplication::desktop()->height();
  
  HideToolWindow mucusWidget( mucusNames, QString( "Rodzaj śluzu" ),
                              QSize( 280, 700 ), QPoint( 900, 50 ),
                              &mainwindow, windowFlags );
  //------------------------------------------------------
  HideToolWindow feelingWidget( feelingNames,
                                QString( "Odczucie nawilżenia przedsionka pochwy" ),
                                QSize( 385, 420 ), QPoint( 700, 220 ),
                                &mainwindow, windowFlags );

  HideToolWindow otherWidget( otherNames, QString( "Pozostałe oznaczenia" ),
                               QSize( 290, 695 ), QPoint( 50, 50 ),
                               &mainwindow, windowFlags );
  //------------------------------------------------------
  HideToolWindow uterusWidget( uterusNames, QString( "Obserwacja szyjki macicy" ),
                         QSize( 290, 420 ), QPoint( 310, 220 ),
                         &mainwindow, windowFlags );
  //------------------------------------------------------
  HideToolWindow temperatureWidget( temperaturesNames, QString( "Temperatura" ),
                         QSize( 280, 210 ), QPoint( 310, 220 ),
                         &mainwindow, windowFlags );
  //------------------------------------------------------
  const int heightFive = height - (height/5);
  if( mucusWidget.height() > heightFive )
    mucusWidget.setFixedHeight( heightFive );

  //------------------------------------------------------
  if( feelingWidget.height() > heightFive ) 
    feelingWidget.setFixedHeight( heightFive );

  //------------------------------------------------------
  if( temperatureWidget.height() > heightFive ) 
    temperatureWidget.setFixedHeight( heightFive );
  
  //------------------------------------------------------
  if( otherWidget.height() > heightFive )
    otherWidget.setFixedHeight( heightFive );

  //------------------------------------------------------
  if( uterusWidget.height() > heightFive )
    uterusWidget.setFixedHeight( heightFive );

  //------------------------------------------------------
  mainwindow.connect( mainwindow.getMainWindow()->actionFeeling,
                      SIGNAL(triggered(bool)),
                      &feelingWidget, SLOT( setVisible( bool ) ) );

  mainwindow.connect( &feelingWidget, SIGNAL( hideWidget( bool ) ),
                      mainwindow.getMainWindow()->actionFeeling,
                      SLOT( setChecked( bool ) ) );
  //------------------------------------------------------
  mainwindow.connect( mainwindow.getMainWindow()->actionTemperature,
                      SIGNAL(triggered(bool)),
                      &temperatureWidget, SLOT( setVisible( bool ) ) );

  mainwindow.connect( &temperatureWidget, SIGNAL( hideWidget( bool ) ),
                      mainwindow.getMainWindow()->actionTemperature,
                      SLOT( setChecked( bool ) ) );  
  //------------------------------------------------------
  mainwindow.connect( mainwindow.getMainWindow()->actionMucus,
                      SIGNAL(triggered(bool)),
                      &mucusWidget, SLOT( setVisible( bool ) ) );

  mainwindow.connect( &mucusWidget, SIGNAL( hideWidget( bool ) ),
                      mainwindow.getMainWindow()->actionMucus,
                      SLOT( setChecked( bool ) ) );
  //------------------------------------------------------
  mainwindow.connect( mainwindow.getMainWindow()->actionObservationCervix,
                      SIGNAL(triggered(bool)),
                      &uterusWidget, SLOT( setVisible( bool ) ) );

  mainwindow.connect( &uterusWidget, SIGNAL( hideWidget( bool ) ),
                      mainwindow.getMainWindow()->actionObservationCervix,
                      SLOT( setChecked( bool ) ) );
  //------------------------------------------------------
  mainwindow.connect( mainwindow.getMainWindow()->actionRemnant,
                      SIGNAL(triggered(bool)),
                      &otherWidget, SLOT( setVisible( bool ) ) );

  mainwindow.connect( &otherWidget, SIGNAL( hideWidget( bool ) ),
                      mainwindow.getMainWindow()->actionRemnant,
                      SLOT( setChecked( bool ) ) );
  //------------------------------------------------------
  QObject::connect( &mainwindow, SIGNAL( languageChange() ),
                    &mucusWidget, SLOT( updateTranslation() ) );
  QObject::connect( &mainwindow, SIGNAL( languageChange() ),
                    &feelingWidget, SLOT( updateTranslation() ) );
  QObject::connect( &mainwindow, SIGNAL( languageChange() ),
                    &otherWidget, SLOT( updateTranslation() ) );
  QObject::connect( &mainwindow, SIGNAL( languageChange() ),
                    &uterusWidget, SLOT( updateTranslation() ) );
  QObject::connect( &mainwindow, SIGNAL( languageChange() ),
                    &temperatureWidget, SLOT( updateTranslation() ) );
  //------------------------------------------------------
  return app.exec();
}
