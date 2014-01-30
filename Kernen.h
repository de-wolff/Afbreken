/*
 * Kernen.h
 *
 *  Created on: Jan 18, 2014
 *      Author: jaap
 */

#ifndef KERNEN_H_
#define KERNEN_H_
#include "Letter.h"
#include "EnumComparer.h"
#include "VectorComparer.h"

namespace Afbreken
{

  typedef enum {
    kn_a, kn_e, kn_i, kn_o, kn_u, kn_y, kn_aa, kn_ai, kn_au, kn_ee, kn_eeu,
    kn_ei, kn_eu, kn_ie, kn_ieu, kn_ij, kn_oe, kn_oo, kn_ou, kn_ui, kn_uu
  } Kernen_e;
#define KERNEN_SIZE 21
  class Kernen
  {

  public:
    Kernen();
    Kernen_e Find(const Letter &l, bool &ok);

  private:
    EnumComparer<Letter> _Comparer;
    map<Letter, Kernen_e, EnumComparer<Letter> > _Ordered;
   static Letter _Value[KERNEN_SIZE];
  };




};
#endif /* KERNEN_H_ */
