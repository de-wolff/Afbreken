/*
 * Afbreker.cpp
 *
 *  Created on: Jan 19, 2014
 *      Author: jaap
 */
#include <set>
#include "Afbreker.h"

namespace Afbreken
{

  using namespace std;


  void Afbreker::afbreekpositie(positie bestemming, Bestemming *pPositieBestemming)
  {
    pPositieBestemming->Add(bestemming);
  };

#define UpdatePosition() \
  Bestemming *pNextBestemming = new Bestemming(*pPositieBestemming);\
  afbreekpositie(pos, pPositieBestemming);\
  afbreekposities(wd, pos, PositieBestemmingen);\
  pPositieBestemming = PositieBestemmingen.Add(pNextBestemming);\
  delete pNextBestemming;\


  positie Afbreker::afbreekposities(const WoordDeel &wd, positie pos, Bestemmingen &PositieBestemmingen)
  {
//    Bestemmingen localBestemmingen(PositieBestemmingen);
    Bestemming *pPositieBestemming = PositieBestemmingen.Last();
    Kernen_e kern = kn_a;
    Staarten_e  staart = st_b;
    Koppen_e kop = kp_b;
    bool  kop_ok = false,kern_ok = false,staart_ok = false;
    WoordDeel kopwd, staartwd, kernwd;
    positie orgpos;
    orgpos=pos;
    /*Bepaal de kop.*/
    // _MedeKlinkers.
    if ((pos<wd.size()) && ( Letters::IsMedeKlinker(wd[pos])))
    {
      while ((pos<wd.size()) && ( Letters::IsMedeKlinker(wd[pos])))
      {
        kopwd.insert(kopwd.end(), wd[pos++]);
      }
      /*Na een q komt een u en deze functioneert als medeklinker
      (Bijv. quad: kop== qu, kern=a staart=d.*/
      if ((kopwd.size()>0) &&
          (kopwd[kopwd.size() - 1] ==_q) &&
         (pos<=wd.size() - 1) &&
         (wd[pos]==_u))
      {
        kopwd.insert(kopwd.end(), wd[pos++]);
      }
      if (kopwd.size()!=0)
      {
        kop=_Koppen.Find(kopwd,kop_ok);
        if (! kop_ok)
          {
            return 0;
          }
        /*Twee speciale uitzonderingen:
         * De kop pj kan alleen komen na een staart die eindigt op m,
           dit zorgt dat pop-je en boom-pje beiden goed afgebroken
           worden.
         * De kop kj kan alleen komen na een staart die eindigt op n,
           dit zorgt dat boek-je en kettin-kje beiden goed afgebroken
           worden.
           */
        if (((kop==kp_pj) && ((orgpos==0) || (wd[orgpos-1]!=_m))) ||
            ((kop==kp_kj) && ((orgpos==0) || (wd[orgpos-1]!=_n))))
          {
            return 0;
          }
      }
    }
    /*Kern: Maximaal 1 klinker.*/
    if ((pos<wd.size()) && (Letters::IsKlinker(wd[pos])))
    {
      kernwd.insert(kernwd.end(),wd[pos++]);
    }
    if (kernwd.size() != 1)
    {
      return 0;
    }
    kern=_Kernen.Find(kernwd[0],kern_ok);
    /*Ongeldige combinatie kop en kern? Adios.*/
    if ((!kern_ok) || (!KopKern::Find(kop,kern)))
      {
      return 0;
      }


    /*Een lettergreep zonder staart is mogelijk...*/
    UpdatePosition();

    /*Staart: 0 of meer medeklinkers, maar in sommige woorden wordt een i als
     medeklinker gebruikt (bijv. bloei).*/
    if ((pos<wd.size()) && (wd[pos - 1]==_i))
    {
      staartwd.insert(staartwd.end(),wd[pos++]);
      staart=_Staarten.Find(staartwd,staart_ok);
      if ((staart_ok) && (_KernStaart.Find(staart, kern)))
      {
          UpdatePosition();
      }
    }
    while ((pos<wd.size()) && (Letters::IsMedeKlinker(wd[pos])))
    {
      staartwd.insert(staartwd.end(), wd[pos++]);
      staart=_Staarten.Find(staartwd,staart_ok);
      if ((staart_ok) && (_KernStaart.Find(staart, kern)))
      {
          UpdatePosition();
      }
    }
    return pos;
  }

  void Afbreker::bepaal_afbreekpunten(const WoordDeel &wd, Bestemmingen &PositieBestemmingen)
  {

    Afbreken::positie positie;
    set<Afbreken::positie> ingevoegd;

    positie=0;
    ingevoegd.insert(ingevoegd.end(),0);
    Bestemming HulpBestemming;
    PositieBestemmingen.Add(&HulpBestemming);
    afbreekposities(wd,positie, PositieBestemmingen);
  }

  bool Afbreker::bepaal_afbreking(const WoordDeel &wd, positie pos, Bestemmingen &PositieBestemmingen, AfbreekParams &params)
  {

	  positie i;
    params.afbreekstack.insert(params.afbreekstack.end(), pos);
    bool result = false;
      if (pos>params.woordlengte)
        {
          result=true;
          params.afbreekstackmax = params.afbreekstackptr-1;
        }
      else
        for (i=0; i < PositieBestemmingen[pos][0]; i++)
          {
            if (bepaal_afbreking(wd,PositieBestemmingen[pos][i],PositieBestemmingen, params))
              {
                result=true;
                break;
              };
          };
      params.afbreekstackptr--;
      return result;
  }

  void Afbreker::correcties(const WoordDeel &wd, Bestemmingen &PositieBestemmingen)
  {
    Bestemmingen::iterator iter;
    for (iter=PositieBestemmingen.begin(); iter !=  PositieBestemmingen.end(); iter++)
      {
        if ((*iter)[wd.size()] == 0)
          {
            PositieBestemmingen.erase(iter);
            iter = PositieBestemmingen.begin();
          }
      }
    for (iter=PositieBestemmingen.begin(); iter !=  PositieBestemmingen.end(); iter++)
      {
        iter->Remove(wd.size());
      }
    PositieBestemmingen.erase(PositieBestemmingen.begin());
  }

  bool Afbreker::breek_af(const WoordDeel &wd, Bestemmingen &PositieBestemmingen)
  {

     AfbreekParams params;
     Bestemming bestemming;
     PositieBestemmingen.Add(&bestemming);
     PositieBestemmingen.Add(&bestemming);
     bepaal_afbreekpunten(wd, PositieBestemmingen);
     correcties(wd, PositieBestemmingen);
     return true;
  }



} /* namespace Afbreken */
