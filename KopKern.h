/*
 * KopKern.h
 *
 *  Created on: Jan 19, 2014
 *      Author: jaap
 */

#ifndef KOPKERN_H_
#define KOPKERN_H_
#include <map>
#include <set>

#include "Kernen.h"
#include "Koppen.h"
#include "EnumComparer.h"
#include "VectorComparer.h"

using namespace std;
namespace Afbreken
{

  class KopKern
  {
  public:
    static bool Find(Koppen_e  kop, Kernen_e  kern);
  private:
    /*
    vector<Kernen_e> operator [](int index);
    static short Cardinaliteit[];
    const int TotaalLettergrepen;
    VectorComparer<Kernen_e, EnumComparer<Kernen_e> > _Comparer;
    map<vector<Kernen_e>, Koppen_e VectorComparer<Kernen_e, EnumComparer<Kernen_e> > > _Ordered;
    */
    static set<Kernen_e> _Value[KOPPEN_SIZE];
  };

} /* namespace Afbreken */
#endif /* KOPKERN_H_ */
