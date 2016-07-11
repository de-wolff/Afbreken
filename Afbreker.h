/*
 * Afbreker.h
 *
 *  Created on: Jan 19, 2014
 *      Author: jaap
 */

#ifndef AFBREKER_H_
#define AFBREKER_H_

#include "Letter.h"
#include "Koppen.h"
#include "Kernen.h"
#include "Staarten.h"
#include "KopKern.h"
#include "KernStaart.h"
#include "Bestemmingen.h"

namespace Afbreken
{
  typedef struct
  {
    byte woordlengte;
    vector<byte> afbreekstack;
    int afbreekstackptr;
    int afbreekstackmax;
  } AfbreekParams;


  class Afbreker
  {

  public:
    bool breek_af(const WoordDeel &wd, Bestemmingen &PositieBestemmingen);

  private:
    void afbreekpositie(byte bestemming, Bestemming *pPositieBestemming);
    positie afbreekposities(const WoordDeel &wd, byte pos, Bestemmingen &PositieBestemmingen);
    void bepaal_afbreekpunten(const WoordDeel &wd, Bestemmingen &PositieBestemmingen);
    bool bepaal_afbreking(const WoordDeel &wd, byte pos, Bestemmingen &PositieBestemmingen, AfbreekParams &params);
    void correcties(const WoordDeel &wd, Bestemmingen &PositieBestemmingen);



    Koppen _Koppen;
    Staarten _Staarten;
    Kernen _Kernen;
    KernStaart _KernStaart;
    KopKern _KopKern;


  };

} /* namespace Afbreken */
#endif /* AFBREKER_H_ */
