/*
License: GPL 
Owner: Marcin Brysz
Contact: unemployed81@gmail.com / bryszmarcin@gmail.com
Version: 1.3 Beta
*/
#include "interpretationbymucus.h"
#include <boost/lambda/lambda.hpp>
#include <boost/lambda/bind.hpp>
#include <algorithm>
#include "imagepoint.h"
#include <QtCore/QtDebug>

InterpretationByMucus::InterpretationByMucus( MygraphSupplement* mygraphSupplement )
  : InterpretationNPR()
{
  mGraphSupplemnet = mygraphSupplement;
}

InterpretationByMucus::~InterpretationByMucus()
{

}

// po zakonczeniu miesiaczki:
boost::tuple< int, QPointF > InterpretationByMucus::beginPhase1() const
{
  using namespace boost::lambda;
  QList< ImagePoint* > points = mGraphSupplemnet->getPoints();

  if( points.empty() )
    return boost::make_tuple( -1, QPointF() );

  std::stable_sort( points.begin(), points.end(), bind( &ImagePoint::getDay, _1 ) < bind( &ImagePoint::getDay, _2 ) );
  QList< ImagePoint* >::const_iterator it = std::find_if( points.begin(), points.end(),
             bind( &ImagePoint::toolTip, _1 ) == QObject::trUtf8(  "Okres" ) );
  if( it != points.end() ) {
    ImagePoint* p1 = (*it);
    // koloruj od lewej krawedzi przy "begin"
    const QPointF pn = QPointF( p1->pos().x(), p1->pos().y()  );
    return boost::make_tuple( p1->getDay() + 1, pn );
  }
  return boost::make_tuple( -1, QPointF() ); // equal not found
}

// Ostatni suchy dzień:
boost::tuple< int, QPointF > InterpretationByMucus::endPhase1() const
{
  using namespace boost::lambda;
  QList< ImagePoint* > points = mGraphSupplemnet->getPoints();
  if( points.empty() )
    return boost::make_tuple( -1, QPointF() );
  std::stable_sort( points.begin(), points.end(), bind( &ImagePoint::getDay, _1 ) < bind( &ImagePoint::getDay, _2 ) );

  QList< ImagePoint* >::const_iterator it = std::find_if( points.begin(), points.end(),
    (
        ( bind( &ImagePoint::toolTip, _1 ) == QObject::trUtf8(  "Śluz przeźroczysty" )  )
        || ( bind( &ImagePoint::toolTip, _1 ) == QObject::trUtf8(  "Śluz nieprzeźroczysty" )  )
        || ( bind( &ImagePoint::toolTip, _1 ) == QObject::trUtf8(  "Śluz rozciągliwy" )  )
        || ( bind( &ImagePoint::toolTip, _1 ) == QObject::trUtf8(  "Śluz nierozciągliwy" )  )
        || ( bind( &ImagePoint::toolTip, _1 ) == QObject::trUtf8(  "Śluz mętny" )  )
        || ( bind( &ImagePoint::toolTip, _1 ) == QObject::trUtf8(  "Śluz lepki" )  )
        || ( bind( &ImagePoint::toolTip, _1 ) == QObject::trUtf8(  "Śluz obfity" )  )
        || ( bind( &ImagePoint::toolTip, _1 ) == QObject::trUtf8(  "Śluz skąpy" )  )
        || ( bind( &ImagePoint::toolTip, _1 ) == QObject::trUtf8(  "Śluz gęsty" )  )
        || ( bind( &ImagePoint::toolTip, _1 ) == QObject::trUtf8(  "Śluz rzadki" )  )
        || ( bind( &ImagePoint::toolTip, _1 ) == QObject::trUtf8(  "Uczucie wilgotności" )  )
        || ( bind( &ImagePoint::toolTip, _1 ) == QObject::trUtf8(  "Uczucie mokrości" )  )
     ));

  if( it != points.end() ) {
    ImagePoint* p1 = (*it);
    // Koloruj do prawej krawedzi (przy end):
    const QPointF pn = QPointF( p1->pos().x() + p1->getMeshStep(), p1->pos().y() );
    return boost::make_tuple( p1->getDay() - 1, pn );
  }
  return boost::make_tuple( -1, QPointF() ); // equal not found
}
boost::tuple< int, QPointF > InterpretationByMucus::beginPhase2() const
{
  return boost::make_tuple( -1, QPointF() );
}

// Śluz przez 5 dni bez zakłocen:
boost::tuple< int, QPointF > InterpretationByMucus::beginPhase2( const bool withFive ) const
{
  using namespace boost::lambda;
  QList< ImagePoint* > points = mGraphSupplemnet->getPoints();
  if( points.empty() )
    return boost::make_tuple( -1, QPointF() );
  std::stable_sort( points.begin(), points.end(), bind( &ImagePoint::getDay, _1 ) < bind( &ImagePoint::getDay, _2 ) );
  QList< ImagePoint* >::const_iterator it = std::find_if( points.begin(), points.end(),
    (
        ( bind( &ImagePoint::toolTip, _1 ) == QObject::trUtf8(  "Śluz przeźroczysty" )  )
        || ( bind( &ImagePoint::toolTip, _1 ) == QObject::trUtf8(  "Śluz nieprzeźroczysty" )  )
        || ( bind( &ImagePoint::toolTip, _1 ) == QObject::trUtf8(  "Śluz rozciągliwy" )  )
        || ( bind( &ImagePoint::toolTip, _1 ) == QObject::trUtf8(  "Śluz nierozciągliwy" )  )
        || ( bind( &ImagePoint::toolTip, _1 ) == QObject::trUtf8(  "Śluz mętny" )  )
        || ( bind( &ImagePoint::toolTip, _1 ) == QObject::trUtf8(  "Śluz lepki" )  )
        || ( bind( &ImagePoint::toolTip, _1 ) == QObject::trUtf8(  "Śluz obfity" )  )
        || ( bind( &ImagePoint::toolTip, _1 ) == QObject::trUtf8(  "Śluz skąpy" )  )
        || ( bind( &ImagePoint::toolTip, _1 ) == QObject::trUtf8(  "Śluz gęsty" )  )
        || ( bind( &ImagePoint::toolTip, _1 ) == QObject::trUtf8(  "Śluz rzadki" )  )
     ));

  if( it != points.end() ) {
    ImagePoint* p1 = (*it);
    int count = 0;
    // koloruj do lewej krawedzi przy begin: (do prawej przy end)
    const QPointF pos( p1->pos().x() /*- p1->getMeshStep()*/, p1->pos().y() );
    //qDebug() << "beginPhase2(): " << p1->toolTip();

    if( withFive ) {
      const int five = 5;
      for( int i = 0; i < five; i++, it++ ) {
        if( it == points.end() )
          break;
        ImagePoint* p = (*it);
        if( !p )
          break;
        if( ( p->toolTip() == QObject::trUtf8(  "Śluz przeźroczysty" ) )
          || ( p->toolTip() == QObject::trUtf8(  "Śluz nieprzeźroczysty" ) )
          || ( p->toolTip() == QObject::trUtf8(  "Śluz rozciągliwy" ) )
          || ( p->toolTip() == QObject::trUtf8(  "Śluz nierozciągliwy" ) )
          || ( p->toolTip() == QObject::trUtf8(  "Śluz mętny" ) )
          || ( p->toolTip() == QObject::trUtf8(  "Śluz lepki" ) )
          || ( p->toolTip() == QObject::trUtf8(  "Śluz obfity" ) )
          || ( p->toolTip() == QObject::trUtf8(  "Śluz skąpy" ) )
          || ( p->toolTip() == QObject::trUtf8(  "Śluz gęsty" ) )
          || ( p->toolTip() == QObject::trUtf8(  "Śluz rzadki" ) ) )
          count++;
      } //for
      return ( ( count >= five ) ? boost::make_tuple( p1->getDay(), pos  ) : boost::make_tuple( -1,   QPointF() ) );
    } //if withFive
    else {

      return boost::make_tuple( p1->getDay(), pos  );
    } // else
  }
  return boost::make_tuple( -1, QPointF() ); // equal not found
}

boost::tuple< int, QPointF > InterpretationByMucus::beginPhase3() const
{
  return boost::make_tuple( -1, QPointF() );
}

boost::tuple< int, QPointF > InterpretationByMucus::endPhase2() const
{
  return boost::make_tuple( -1, QPointF() );
}

boost::tuple< int, QPointF > InterpretationByMucus::endPhase3() const
{
  return boost::make_tuple( -1, QPointF() );
}
