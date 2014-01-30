/*
 * Letter.h
 *
 *  Created on: Jan 18, 2014
 *      Author: jaap
 */

#ifndef LETTER_H_
#define LETTER_H_
#include <vector>
#include <set>

using namespace std;

namespace Afbreken
{


  typedef struct basischeck {
    long basis, check;
  } basischeck;



  typedef enum
  {
    _afbreek,
    _a,
    _b,
    _c,
    _d,
    _e,
    _f,
    _g,
    _h,
    _i,
    _j,
    _k,
    _l,
    _m,
    _n,
    _o,
    _p,
    _q,
    _r,
    _s,
    _t,
    _u,
    _v,
    _w,
    _x,
    _y,
    _z,
    _aa,
    _ai,
    _au,
    _ee,
    _eeu,
    _ei,
    _eu,
    _ie,
    _ieu,
    _ij,
    _oe,
    _oo,
    _ou,
    _ui,
    _uu,
    _ch
  } Letter;

  typedef unsigned char byte;
  typedef byte positie;


  typedef vector<Letter> WoordDeel;

  class Letters {
  public:
    static bool IsMedeKlinker(Letter l);
    static bool IsKlinker(Letter l);
    static bool IsDubbelKlinker(Letter l);
  private:
    static set<Letter> _MedeKlinkers;
    static set<Letter> _Klinkers;
    static set<Letter> _DubbelKlinkers;
  };
  extern const Letter __;

};

#endif /* LETTER_H_ */
