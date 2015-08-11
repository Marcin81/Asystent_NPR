/*
License: GPL 
Owner: Marcin Brysz
Contact: unemployed81@gmail.com / bryszmarcin@gmail.com
Version: 1.3 Beta
*/
#ifndef INTERPRETATIONBYTEMPERATURE_H
#define INTERPRETATIONBYTEMPERATURE_H
#include "mygraph.h"
#include "interpretationnpr.h"

class InterpretationByTemperature : public InterpretationNPR
{
  Mygraph* mGraph;
public:
  InterpretationByTemperature( Mygraph* mygraph );
  virtual ~InterpretationByTemperature();

  boost::tuple< int, QPointF > beginPhase1() const;
  boost::tuple< int, QPointF > beginPhase2() const;
  boost::tuple< int, QPointF > beginPhase3() const;

  boost::tuple< int, QPointF > endPhase1() const;
  boost::tuple< int, QPointF > endPhase2() const;
  boost::tuple< int, QPointF > endPhase3() const;
protected:
  QList< MoveablePoint* > sixLow() const;
  QList< MoveablePoint* > threeHigh() const;
};

#endif // INTERPRETATIONBYTEMPERATURE_H
