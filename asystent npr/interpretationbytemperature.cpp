/*
License: GPL 
Owner: Marcin Brysz
Contact: unemployed81@gmail.com / bryszmarcin@gmail.com
Version: 1.3 Beta
*/
#include "interpretationbytemperature.h"
#include <boost/lambda/lambda.hpp>
#include <boost/lambda/bind.hpp>
#include <algorithm>
#include <QtCore/QtDebug>
#include <boost/bind/bind.hpp>

InterpretationByTemperature::InterpretationByTemperature( Mygraph* mygraph )
  : InterpretationNPR()
{
  mGraph = mygraph;
}

InterpretationByTemperature::~InterpretationByTemperature()
{

}

boost::tuple< int, QPointF > InterpretationByTemperature::beginPhase1() const
{
  // Po zakonczeniu miesiaczki
  using namespace boost::lambda;
  QList< MoveablePoint* > points = mGraph->getPoints();
  // Wyrazne przejscie temperatury z poziomu nizszego na wyższy:
  // (pierwsza wyższa temperaura ), co znaczy "wyrazne" ?
  if( points.empty() )
    return boost::make_tuple( -1, QPointF() );

  const float temp1 = (*points.begin() )->getTemp();
  QList< MoveablePoint* >::const_iterator it = std::find_if(
      points.begin(), points.end(), bind( &MoveablePoint::getTemp, ::_1 ) > temp1 );
  if( it != points.end() ) {
    MoveablePoint* mp = (*it);
    // koloruj od lewej krawedzi przy "begin"
    return boost::make_tuple( mp->getDay(), mp->pos() );
  }
  return boost::make_tuple( -1, QPointF() );
}

boost::tuple< int, QPointF > InterpretationByTemperature::beginPhase2() const
{
  return boost::make_tuple( -1, QPointF() );
}

boost::tuple< int, QPointF > InterpretationByTemperature::endPhase1() const
{
  return boost::make_tuple( -1, QPointF() );
}

boost::tuple< int, QPointF > InterpretationByTemperature::endPhase2() const
{
  using namespace boost::lambda;
  boost::tuple< int, QPointF > ret = beginPhase3();
  if( ret.get<0>() == -1 )
    return ret;
  ret.get<0>()  = ret.get<0>() -1;
  QList< MoveablePoint* > points = mGraph->getPoints();

  if( points.empty() )
    return boost::make_tuple( -1, QPointF() );

  QList< MoveablePoint* >::const_iterator it = std::find_if( points.begin(), points.end(), bind( &MoveablePoint::pos, ::_1 ) == ret.get<1>() );

  if( it != points.end() ) {
    MoveablePoint* p = (*it);
    ret.get<0>() = ret.get<0>() - 1;
    // koloruj przy prawej krawedzi dla "end"
    QPointF pos( p->pos().x(), p->pos().y() );
    ret.get<1>() = pos;
    return ret;
  }
  return boost::make_tuple( -1, QPointF() );
}

boost::tuple< int, QPointF > InterpretationByTemperature::beginPhase3() const
{
  //3 kolejne wyzsze niezaklocone po 6 nizszych
  QList< MoveablePoint* > hp = threeHigh();
  if( hp.isEmpty() )
    return boost::make_tuple( -1, QPointF() );
  return boost::make_tuple( hp[2]->getDay() + 1, hp[2]->pos() );
}

boost::tuple< int, QPointF > InterpretationByTemperature::endPhase3() const
{
  QList< MoveablePoint* > points = mGraph->getPoints();
  QList< MoveablePoint* > highs = threeHigh();
  if( highs.isEmpty() || points.isEmpty() )
    return boost::make_tuple( -1, QPointF() );

  const int day = points.last()->getDay();
  QPointF pos = points.last()->pos();
  return ( highs.isEmpty() ? boost::make_tuple( -1, QPointF() ) : boost::make_tuple( day , pos ) );
}

QList< MoveablePoint* > InterpretationByTemperature::sixLow() const
{
  using boost::bind;
  QList< MoveablePoint* > points = mGraph->getPoints();
  if( points.isEmpty() )
    boost::make_tuple( -1, QPointF() );

  typedef QList< MoveablePoint* >::const_iterator iteratorP;
  //----------------------
  iteratorP minP = std::min_element( points.begin(), points.end(),
    bind( std::less< float >(),
          bind( &MoveablePoint::getDay, _1 ),
          bind( &MoveablePoint::getDay, _2 )
          ) );

  //--------------------------
  iteratorP maxP = std::min_element( points.begin(), points.end(),
    bind( std::greater< float >(),
          bind( &MoveablePoint::getDay, _1 ),
          bind( &MoveablePoint::getDay, _2 )
          ) );

  if( ( maxP == points.end() )
    || ( minP == points.end() ) )
    return QList< MoveablePoint* >();

  const float minPoint = (*minP)->getTemp();
  const float maxPoint =(*maxP)->getTemp();
  //--------------------------

  for( float fp = minPoint; fp <= maxPoint; fp += 0.1 ) {
    const int six = 7;
    for( int itIndex = 0; itIndex < points.size(); itIndex++) {
      MoveablePoint* p = points[itIndex];
      QList< MoveablePoint* > resTemp;
      // 5 nastepnych musi byc == p.getTemp() lub p.getTEmp() + 0.1
      // i dni musza byc chronologiczne
      const int startIndex = points.indexOf( p );
      const int endIndex= startIndex + six;

      if( endIndex >= points.size()  )
        return QList< MoveablePoint* >();

      for( int i = startIndex; i < endIndex; i++) {
        const bool eT = p->getTemp() == points[i]->getTemp();
        const bool hT = qFuzzyCompare( points[i]->getTemp() - 0.1F, p->getTemp() );
        const bool eD = ( points[i]->getDay() + 1 ) == points[i+1]->getDay();
        if( ( eT && eD ) || ( hT && eD) ) {
          resTemp.push_back( points[i] );
          itIndex = i;
        } else break;
      } //for

      if( resTemp.size() == six -1 )
        return resTemp;

    } // boost foreach
  } // for
  return QList< MoveablePoint* >();
}

// poziom wyzszy od 0.2
QList< MoveablePoint* > InterpretationByTemperature::threeHigh() const
{
  QList< MoveablePoint* > resSix = sixLow();
  if( resSix.isEmpty() )
    return resSix;
  const float highTemp = qRound( resSix[5]->getTemp() );
  // 3 kolejne musza byc powyzej tej temperatury:
  QList< MoveablePoint* > points = mGraph->getPoints();

  if( points.isEmpty() )
    return QList< MoveablePoint* >();

  const int startIndex = points.indexOf( resSix[5] ) + 1;
  int day = resSix[5]->getDay() + 1;
  bool isOK = false;

  QList< MoveablePoint* > res2;
  if( ( startIndex > 0 ) && ( startIndex + 2 < points.size() ) ) {
    for( int i = startIndex; i <= startIndex + 2; i++, day++ ) {

      if( ( qRound( points[i]->getTemp() ) <= highTemp )
        && ( day == points[i]->getDay() ) ) {
        isOK = true;
        res2.push_back( points[i] );
      } else {
        isOK = false;
        break;
      } //else
     } // for
  } else isOK = false;

  if( isOK ) {
    QList< float > pResSix;
    std::transform( resSix.begin(), resSix.end(), std::back_inserter( pResSix ),
                  boost::bind( &MoveablePoint::getTemp, _1 ) );

    if( pResSix.isEmpty() )
      return QList< MoveablePoint* >();

    QList< float >::const_iterator itMaxSix = std::max_element( pResSix.begin(), pResSix.end() );

    if( itMaxSix == pResSix.end() )
      return QList< MoveablePoint* >();

    const float maxSix = *itMaxSix;
  //----------------------
    QList< MoveablePoint* >::const_iterator maxLowiT = std::min_element( res2.begin(), res2.end(),
      bind( std::less< float >(),
        bind( &MoveablePoint::getDay, _1 ),
        bind( &MoveablePoint::getDay, _2 )
        ) );

    if( maxLowiT == res2.end() )
      return QList< MoveablePoint* >();
  //--------------------------
    const float maxLow = (*maxLowiT)->getTemp();
  //--------------------------
    if( qFuzzyCompare( maxSix + 0.2F, maxLow ) )
      return res2;

  } //if
  return QList< MoveablePoint* >();
}
