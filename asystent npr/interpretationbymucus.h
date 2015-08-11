/*
License: GPL 
Owner: Marcin Brysz
Contact: unemployed81@gmail.com / bryszmarcin@gmail.com
Version: 1.3 Beta
*/
#ifndef INTERPRETATIONBYMUCUS_H
#define INTERPRETATIONBYMUCUS_H
#include "mygraphsupplement.h"
#include "interpretationnpr.h"

class InterpretationByMucus : public InterpretationNPR
{
  MygraphSupplement* mGraphSupplemnet;
public:
  InterpretationByMucus( MygraphSupplement* mygraphSupplement );
  virtual ~InterpretationByMucus();

  boost::tuple< int, QPointF > beginPhase1() const;
  boost::tuple< int, QPointF > beginPhase2() const;
  boost::tuple< int, QPointF > beginPhase2( const bool withFive ) const;
  boost::tuple< int, QPointF > beginPhase3() const;

  boost::tuple< int, QPointF > endPhase1() const;
  boost::tuple< int, QPointF > endPhase2() const;
  boost::tuple< int, QPointF > endPhase3() const;
};

#endif // INTERPRETATIONBYMUCUS_H
