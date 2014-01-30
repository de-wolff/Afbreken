/*
 * Letter.cpp
 *
 *  Created on: Jan 28, 2014
 *      Author: jaap
 */
#include "Letter.h"
#include "Kernen.h"

namespace Afbreken
{
    bool Letters::IsMedeKlinker(Letter l)
    {
      return (_MedeKlinkers.find(l) != _MedeKlinkers.end());
    }
    bool Letters::IsKlinker(Letter l)
    {
      return (_Klinkers.find(l) != _Klinkers.end());
    }
    bool Letters::IsDubbelKlinker(Letter l)
    {
      return (_DubbelKlinkers.find(l) != _DubbelKlinkers.end());
    }

    set<Letter> Letters::_MedeKlinkers = { _b,_c,_d,_f,
        _g,_h,_j,_k,
        _l,_m,_n,_p,
        _q,_r,_s,_t,
        _v,_w,_x,_z,
        _ch
    };
    set<Letter> Letters::_Klinkers = { _a,_e,_i,_o,
        _u,_y,_aa,_ai,
        _au,_ee,_eeu,_ei,
        _eu,_ie,_ieu,_ij,
        _oe,_oo,_ou,_ui,
        _uu };
    set<Letter> Letters::_DubbelKlinkers = { _aa, _ee, _oo, _uu };

}



