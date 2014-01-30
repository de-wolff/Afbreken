/*
 * KernStaart.h
 *
 *  Created on: Jan 19, 2014
 *      Author: jaap
 */

#ifndef KERNSTAART_H_
#define KERNSTAART_H_
#include <vector>
#include <array>
#include <set>

#include "Kernen.h"
#include "Staarten.h"
#include "EnumComparer.h"
#include "VectorComparer.h"

using namespace std;

namespace Afbreken
{
// #define KERNSTAART_SIZE 21
  class KernStaart
  {
  public:
    static bool Find(Staarten_e  staart, Kernen_e  kern);
  private:
    /*
    vector<Staarten_e> operator [](int index);
    static short Cardinaliteit[];
    VectorComparer<Staarten_e, EnumComparer<Staarten_e> > _Comparer;
    set<vector<Staarten_e>, VectorComparer<Staarten_e, EnumComparer<Staarten_e> > > _Ordered;
*/
    static set<Staarten_e> _Value[KERNEN_SIZE];


  };

} /* namespace Afbreken */
#endif /* KERNSTAART_H_ */
