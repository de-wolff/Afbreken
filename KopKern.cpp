/*
 * KopKern.cpp
 *
 *  Created on: Jan 19, 2014
 *      Author: jaap
 */
#include "KopKern.h"

using namespace std;
namespace Afbreken
{
  bool KopKern::Find(Koppen_e  kop, Kernen_e  kern)
  {
    int nKop = (int)kop;
    if (nKop >= KOPPEN_SIZE) return true;
    const set<Kernen_e> &rkern = _Value[nKop];
    return (rkern.find(kern) != rkern.end());
  }

/*
  vector<Kernen_e>  KopKern::operator [](int index)
  {
    return _Value[index];
  }


  short KopKern::Cardinaliteit[]=
      {0x051A,0x04BF,0x051A,0x0515,0x040E,0x0465,0x0515,0x007B
      ,0x04DA,0x0311,0x0515,0x046A,0x002D,0x0452,0x051A,0x04E7
      ,0x01E6,0x04E2,0x051B,0x04D4,0x050D,0x0092,0x04CC,0x0495
      ,0x04CE,0x032F,0x051A,0x051A,0x051B,0x0515,0x0187,0x0092
      ,0x0497,0x04C2,0x0281,0x02FC,0x051A,0x0092,0x0515,0x03DA
      ,0x0092,0x0269,0x02FB,0x0341,0x0098,0x037F,0x0092,0x03EA
      ,0x0484,0x04B7,0x045D,0x04BA,0x0177,0x0478,0x0098,0x04F1
      ,0x0092,0x0497,0x0113,0x04EF,0x012A,0x014A,0x0113,0x03D5
      ,0x007A,0x0515,0x043F,0x01B0,0x027E,0x0092,0x04FA,0x011D
      ,0x010D,0x01BD,0x0515,0x0491,0x0491,0x04C5,0x00BA,0x036B
      ,0x01BD,0x04F6,0x03D0,0x047F,0x00E3,0x0208};
*/
  set<Kernen_e> KopKern::_Value[KOPPEN_SIZE ]={
      {kn_a,kn_e,kn_i,kn_o,kn_u,kn_y,kn_aa,kn_ai,kn_au,kn_ee,kn_eeu,kn_ei,kn_eu,kn_ie,kn_ij,kn_oe,kn_oo,kn_ou,kn_ui,kn_uu},
      {kn_a,kn_e,kn_i,kn_o,kn_u,kn_y,kn_aa,kn_au,kn_ee,kn_ei,kn_eu,kn_ie,kn_ij,kn_oe,kn_oo,kn_ou},
      {kn_a,kn_e,kn_i,kn_o,kn_u,kn_y,kn_aa,kn_ai,kn_au,kn_ee,kn_eeu,kn_ei,kn_eu,kn_ie,kn_ij,kn_oe,kn_oo,kn_ou,kn_ui,kn_uu},
      {kn_a,kn_e,kn_i,kn_o,kn_u,kn_y,kn_aa,kn_ai,kn_au,kn_ee,kn_ei,kn_eu,kn_ie,kn_ij,kn_oe,kn_oo,kn_ou,kn_ui,kn_uu},
      {kn_a,kn_e,kn_i,kn_o,kn_u,kn_y,kn_aa,kn_ai,kn_au,kn_ie,kn_oo,kn_ou,kn_ui},
      {kn_a,kn_e,kn_i,kn_o,kn_u,kn_y,kn_aa,kn_ee,kn_ie,kn_oe,kn_oo,kn_ou,kn_ui},
      {kn_a,kn_e,kn_i,kn_o,kn_u,kn_y,kn_aa,kn_ai,kn_au,kn_ee,kn_ei,kn_eu,kn_ie,kn_ij,kn_oe,kn_oo,kn_ou,kn_ui,kn_uu},
      {kn_i},
      {kn_a,kn_e,kn_i,kn_o,kn_u,kn_y,kn_aa,kn_ai,kn_au,kn_ee,kn_ei,kn_eu,kn_ie,kn_ij,kn_oe,kn_oo,kn_ui},
      {kn_a,kn_e,kn_i,kn_o,kn_aa,kn_ee,kn_ei,kn_ij},
      {kn_a,kn_e,kn_i,kn_o,kn_u,kn_y,kn_aa,kn_ai,kn_au,kn_ee,kn_ei,kn_eu,kn_ie,kn_ij,kn_oe,kn_oo,kn_ou,kn_ui,kn_uu},
      {kn_a,kn_e,kn_i,kn_o,kn_u,kn_y,kn_ai,kn_au,kn_ee,kn_eu,kn_ie,kn_oe,kn_oo,kn_ou,kn_ui},
      {kn_ui},
      {kn_a,kn_e,kn_i,kn_o,kn_u,kn_aa,kn_au,kn_ee,kn_ei,kn_eu,kn_ie,kn_ij,kn_ou,kn_ui},
      {kn_a,kn_e,kn_i,kn_o,kn_u,kn_y,kn_aa,kn_ai,kn_au,kn_ee,kn_eeu,kn_ei,kn_eu,kn_ie,kn_ij,kn_oe,kn_oo,kn_ou,kn_ui,kn_uu},
      {kn_a,kn_e,kn_i,kn_o,kn_u,kn_y,kn_aa,kn_au,kn_ee,kn_ei,kn_eu,kn_ie,kn_ij,kn_oe,kn_oo,kn_ui,kn_uu},
      {kn_i,kn_o,kn_ei,kn_oe,kn_oo,kn_ui},
      {kn_a,kn_e,kn_i,kn_o,kn_u,kn_aa,kn_ai,kn_au,kn_ee,kn_ei,kn_eu,kn_ie,kn_ij,kn_oe,kn_oo,kn_ou,kn_ui},
      {kn_a,kn_e,kn_i,kn_o,kn_u,kn_y,kn_aa,kn_ai,kn_au,kn_ee,kn_ei,kn_eu,kn_ie,kn_ieu,kn_ij,kn_oe,kn_oo,kn_ou,kn_ui,kn_uu},
      {kn_a,kn_e,kn_i,kn_o,kn_u,kn_aa,kn_au,kn_ee,kn_ei,kn_eu,kn_ie,kn_ij,kn_oe,kn_oo,kn_ou,kn_ui},
      {kn_a,kn_e,kn_i,kn_o,kn_u,kn_y,kn_aa,kn_au,kn_ee,kn_ei,kn_eu,kn_ie,kn_ieu,kn_ij,kn_oe,kn_oo,kn_ou,kn_ui,kn_uu},
      {kn_e},
      {kn_a,kn_e,kn_i,kn_o,kn_u,kn_y,kn_aa,kn_au,kn_ee,kn_ei,kn_eu,kn_ie,kn_ij,kn_oe,kn_oo,kn_ui},
      {kn_a,kn_e,kn_i,kn_o,kn_u,kn_aa,kn_au,kn_ee,kn_eu,kn_ie,kn_ij,kn_oe,kn_oo,kn_ui},
      {kn_a,kn_e,kn_i,kn_o,kn_u,kn_y,kn_aa,kn_au,kn_ee,kn_eu,kn_ie,kn_ieu,kn_ij,kn_oe,kn_oo,kn_ui,kn_uu},
      {kn_a,kn_e,kn_i,kn_o,kn_aa,kn_ee,kn_ie,kn_ij},
      {kn_a,kn_e,kn_i,kn_o,kn_u,kn_y,kn_aa,kn_ai,kn_au,kn_ee,kn_eeu,kn_ei,kn_eu,kn_ie,kn_ij,kn_oe,kn_oo,kn_ou,kn_ui,kn_uu},
      {kn_a,kn_e,kn_i,kn_o,kn_u,kn_y,kn_aa,kn_ai,kn_au,kn_ee,kn_eeu,kn_ei,kn_eu,kn_ie,kn_ij,kn_oe,kn_oo,kn_ou,kn_ui,kn_uu},
      {kn_a,kn_e,kn_i,kn_o,kn_u,kn_y,kn_aa,kn_ai,kn_au,kn_ee,kn_ei,kn_eu,kn_ie,kn_ieu,kn_ij,kn_oe,kn_oo,kn_ou,kn_ui,kn_uu},
      {kn_a,kn_e,kn_i,kn_o,kn_u,kn_y,kn_aa,kn_ai,kn_au,kn_ee,kn_ei,kn_eu,kn_ie,kn_ij,kn_oe,kn_oo,kn_ou,kn_ui,kn_uu},
      {kn_e,kn_i,kn_u},
      {kn_e},
      {kn_a,kn_e,kn_i,kn_o,kn_u,kn_aa,kn_ai,kn_au,kn_ee,kn_ei,kn_eu,kn_ie,kn_oe,kn_oo,kn_ui},
      {kn_a,kn_e,kn_i,kn_o,kn_u,kn_aa,kn_ai,kn_au,kn_ee,kn_ei,kn_eu,kn_ie,kn_ij,kn_oe,kn_oo,kn_ui},
      {kn_a,kn_e,kn_i,kn_o,kn_y,kn_eu},
      {kn_a,kn_e,kn_i,kn_o,kn_aa,kn_ai,kn_ee,kn_eu},
      {kn_a,kn_e,kn_i,kn_o,kn_u,kn_y,kn_aa,kn_ai,kn_au,kn_ee,kn_eeu,kn_ei,kn_eu,kn_ie,kn_ij,kn_oe,kn_oo,kn_ou,kn_ui,kn_uu},
      {kn_e},
      {kn_a,kn_e,kn_i,kn_o,kn_u,kn_y,kn_aa,kn_ai,kn_au,kn_ee,kn_ei,kn_eu,kn_ie,kn_ij,kn_oe,kn_oo,kn_ou,kn_ui,kn_uu},
      {kn_a,kn_e,kn_i,kn_o,kn_u,kn_y,kn_aa,kn_ee,kn_oo,kn_ou,kn_uu},
      {kn_e},
      {kn_a,kn_i,kn_o,kn_u,kn_ee},
      {kn_a,kn_e,kn_i,kn_o,kn_u,kn_ee},
      {kn_a,kn_e,kn_i,kn_o,kn_u,kn_ee,kn_oo},
      {kn_a},
      {kn_a,kn_e,kn_i,kn_o,kn_aa,kn_ee,kn_ei,kn_ie,kn_oe,kn_ou},
      {kn_e},
      {kn_a,kn_e,kn_i,kn_o,kn_u,kn_y,kn_aa,kn_ai,kn_ee,kn_ie,kn_oo},
      {kn_a,kn_e,kn_i,kn_o,kn_u,kn_aa,kn_ee,kn_eeu,kn_eu,kn_ie,kn_ij,kn_oe,kn_oo,kn_ui},
      {kn_a,kn_e,kn_i,kn_o,kn_u,kn_y,kn_aa,kn_ee,kn_eu,kn_ie,kn_ij,kn_oe,kn_oo,kn_ou,kn_ui},
      {kn_a,kn_e,kn_i,kn_o,kn_u,kn_aa,kn_au,kn_ee,kn_eeu,kn_eu,kn_ij,kn_oe,kn_oo,kn_ui},
      {kn_a,kn_e,kn_i,kn_o,kn_u,kn_aa,kn_ee,kn_eu,kn_ie,kn_ij,kn_oe,kn_oo,kn_ou,kn_ui,kn_uu},
      {kn_e,kn_i,kn_ee,kn_ij},
      {kn_a,kn_e,kn_i,kn_o,kn_u,kn_aa,kn_ee,kn_eeu,kn_ei,kn_eu,kn_ie,kn_oe,kn_oo,kn_ui},
      {kn_a},
      {kn_a,kn_e,kn_i,kn_o,kn_u,kn_y,kn_aa,kn_ee,kn_ei,kn_eu,kn_ie,kn_ij,kn_oe,kn_oo,kn_ou,kn_ui,kn_uu},
      {kn_e},
      {kn_a,kn_e,kn_i,kn_o,kn_u,kn_y,kn_aa,kn_ee,kn_eu,kn_ie,kn_ij,kn_oe,kn_oo,kn_ui},
      {kn_a,kn_i},
      {kn_a,kn_e,kn_i,kn_o,kn_u,kn_aa,kn_au,kn_ee,kn_ei,kn_eu,kn_ie,kn_ij,kn_oe,kn_oo,kn_ou,kn_ui,kn_uu},
      {kn_a,kn_e},
      {kn_e,kn_i,kn_ie},
      {kn_a,kn_i},
      {kn_a,kn_e,kn_i,kn_o,kn_aa,kn_ee,kn_eeu,kn_ei,kn_ie,kn_ij,kn_oe,kn_oo},
      {kn_u},
      {kn_a,kn_e,kn_i,kn_o,kn_u,kn_y,kn_aa,kn_ai,kn_au,kn_ee,kn_ei,kn_eu,kn_ie,kn_ij,kn_oe,kn_oo,kn_ou,kn_ui,kn_uu},
      {kn_a,kn_e,kn_i,kn_o,kn_u,kn_y,kn_aa,kn_au,kn_ee,kn_ie,kn_oo,kn_ou,kn_ui},
      {kn_a,kn_i,kn_o},
      {kn_a,kn_e,kn_i,kn_o,kn_oe},
      {kn_e},
      {kn_a,kn_e,kn_i,kn_o,kn_u,kn_y,kn_aa,kn_ai,kn_au,kn_ee,kn_ei,kn_eu,kn_ie,kn_ij,kn_oe,kn_oo,kn_ou,kn_ui},
      {kn_a,kn_aa,kn_ee},
      {kn_e,kn_i},
      {kn_e,kn_i,kn_aa,kn_ee,kn_ij},
      {kn_a,kn_e,kn_i,kn_o,kn_u,kn_y,kn_aa,kn_ai,kn_au,kn_ee,kn_ei,kn_eu,kn_ie,kn_ij,kn_oe,kn_oo,kn_ou,kn_ui,kn_uu},
      {kn_a,kn_e,kn_i,kn_o,kn_u,kn_aa,kn_ee,kn_ei,kn_eu,kn_ie,kn_ij,kn_oe,kn_oo,kn_ou},
      {kn_a,kn_e,kn_i,kn_o,kn_u,kn_aa,kn_ee,kn_ei,kn_eu,kn_ie,kn_ij,kn_oe,kn_oo,kn_ou},
      {kn_a,kn_e,kn_i,kn_o,kn_u,kn_y,kn_aa,kn_au,kn_ee,kn_ei,kn_ie,kn_ij,kn_oe,kn_oo,kn_ou,kn_ui},
      {kn_i,kn_ee},
      {kn_a,kn_e,kn_i,kn_o,kn_aa,kn_ee,kn_ie,kn_ij,kn_oe},
      {kn_a,kn_e,kn_i,kn_y},
      {kn_a,kn_e,kn_i,kn_o,kn_u,kn_y,kn_aa,kn_ee,kn_eeu,kn_ei,kn_eu,kn_ie,kn_ij,kn_oe,kn_oo,kn_ou,kn_ui,kn_uu},
      {kn_a,kn_e,kn_i,kn_o,kn_aa,kn_ee,kn_ei,kn_ie,kn_ij,kn_oe,kn_oo},
      {kn_a,kn_e,kn_i,kn_o,kn_u,kn_y,kn_aa,kn_au,kn_ee,kn_eu,kn_ie,kn_ij,kn_oo,kn_ou,kn_uu},
      {kn_o,kn_oo},
      {kn_e,kn_i,kn_o,kn_y,kn_oo}
};
  /*
const int KopKern::TotaalLettergrepen=73775;
*/


} /* namespace Afbreken */
