/*
License: GPL 
Owner: Marcin Brysz
Contact: unemployed81@gmail.com / bryszmarcin@gmail.com
Version: 1.3 Beta
*/
#ifndef INTERPRETATIONNPR_H
#define INTERPRETATIONNPR_H
#include <boost/tuple/tuple.hpp>
#include <QtCore/QPointF>

class InterpretationNPR
{
public:
  InterpretationNPR();
  virtual ~InterpretationNPR();

  virtual boost::tuple< int /*day */, QPointF > beginPhase1() const = 0;
  virtual boost::tuple< int, QPointF > beginPhase2() const = 0;
  virtual boost::tuple< int, QPointF > beginPhase3() const = 0;

  virtual boost::tuple< int, QPointF > endPhase1() const = 0;
  virtual boost::tuple< int, QPointF > endPhase2() const = 0;
  virtual boost::tuple< int, QPointF > endPhase3() const = 0;
};

#endif // INTERPRETATIONNPR_H
