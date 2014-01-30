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



#if 0

  var positie_bestemmingen:array[1,127,0,7] of byte;
      woordlengte:byte;
      afbreekstack:array[1,127] of byte;
      afbreekstackptr,afbreekstackmax:0,127;


  int zoekBoom(WoordDeel wd, int start, const basischeck *&boom)

  /*Zoek een woorddeel op in een trie en geef de bijbehorende waarde indien gevonden, anders 0.*/

  {
      int n,i;
      long l;
      char *p;

    l=1;
    int result=0;
    i=start+byte(wd[0]);
    while (boom[i].basis+long(wd[l])>=0) and (l<wd.length()) do
      {
        n=trie[i].basis+long(wd[l]);
        inc(l);
        if (n>high(trie)) or (trie[n].check<>trie[i].basis) then
          exit;
        i=n;
      };

    n=trie[i].basis+byte(__);
    if (n>high(trie)) or (trie[n].check<>n) then
      exit;
    zoekBoom=trie[n].basis;
  };

  function zoek_kop(const wd:woorddeel;var kop_ok:boolean):koppen;

  var v:integer;

  {
    v=zoekBoom(wd,koppenBoom_start,koppenBoom);
    kop_ok=v<0;
    if kop_ok then
      zoek_kop=koppen(-v-1);
  };

  function zoek_kern(const WoordDeel &wd, kern_ok:boolean):kernen;

  var v:integer;

  {
    v=zoekBoom(wd,kernenBoom_start,kernenBoom);
    kern_ok=v<0;
    if kern_ok then
      zoek_kern=kernen(-v-1);
  };

  bool zoek_staart(const WoordDeel &wd, bool &staart_ok)
  {

    int v;
    v=zoekBoom(wd,staartenBoom_start,staartenBoom);
    staart_ok=v<0;
    if (staart_ok)
      return Staarten(-v-1);
  };


  bool zoek_zwart_woord(const WoordDeel &wd)

  /*Kijk of dit woorddeel in de lijst van zwarte lettergreepcombinaties
   voorkomt.*/
  {

    byte l,h,m;
    bool  klgl;
    byte i;
    Letter c;

    l=low(zwarte_woorden);
    h=high(zwarte_woorden);
    do
      {
      m=zwarte_woorden((byte(h)+byte(l)) div 2);
      klgl=true;

      for i=1 to wd.lengte do
        {
          c=zwarte_woorden_letters[m,i];
          if wd.letters[i]<>c then
            {
              klgl=wd.letters[i]<c;
              break;
            };
        };
      if klgl then
        h=m
      else
        l=succ(m);
      }
    while (l!=h)

    bool result=true;
    for i=low(zwarte_woorden_letters[l]) to high(zwarte_woorden_letters[l]) do
      {
        if (i<wd.length())
          c=wd.letters[i]
        else
          c=__;
        if (c!=zwarte_woorden_letters[l,i])
          {
            return false;
          };
      };
  };

#endif

  void Afbreker::afbreekpositie(byte bestemming, Bestemming *pPositieBestemming)
  {
//    writeln('Van ',basis,' naar ',bestemming);
//    inc(positie_bestemmingen[basis,0]);
    pPositieBestemming->Add(bestemming);
  };

#define UpdatePosition() \
  Bestemming *pNextBestemming = new Bestemming(*pPositieBestemming);\
  afbreekpositie(pos, pPositieBestemming);\
  afbreekposities(wd, pos, PositieBestemmingen);\
  pPositieBestemming = PositieBestemmingen.Add(pNextBestemming);\
  delete pNextBestemming;\


  positie Afbreker::afbreekposities(const WoordDeel &wd, byte pos, Bestemmingen &PositieBestemmingen)
  {
//    Bestemmingen localBestemmingen(PositieBestemmingen);
    Bestemming *pPositieBestemming = PositieBestemmingen.Last();
    Kernen_e kern;
    Staarten_e  staart;
    Koppen_e kop;
    bool  kop_ok = false,kern_ok = false,staart_ok = false;
    WoordDeel kopwd, staartwd, kernwd;
    byte orgpos;
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

  byte positie;
//  byte l,h;
//  byte i;
//  byte queue[16];
  set<byte> ingevoegd;

    positie=0;
    ingevoegd.insert(ingevoegd.end(),0);
 //   l=0;
 //   h=1;
 //   queue[0]=0;
    Bestemming HulpBestemming;
    PositieBestemmingen.Add(&HulpBestemming);
    afbreekposities(wd,positie, PositieBestemmingen);
#if 0
    while (l != h)
      {
        /*Verwijder*/
        positie=queue[l++];
        if (l>15) l=0;
        afbreekposities(wd,positie, PositieBestemmingen);
        for (i=0 ; i< PositieBestemming[0]; i++)
        {
          if (ingevoegd.find(PositieBestemmingen[i]) == ingevoegd.end())
          {
            /*Voeg in op stack.*/
            queue[h]=PositieBestemming[i];
            ingevoegd.insert(ingevoegd.end(),queue[h++]);
            if (h>15) h=0;
           }
        }
        PositieBestemmingen.Add(PositieBestemming);
      }
#endif
  }
/*
  bool geen_zwarte_lijst(WoordDeel wd)
  {
    WoordDeel z;
    byte i,j,van,naar;

    for i=afbreekstackptr downto 2 do
      {
        if (z.size() != 0)
        {
          z.insert(z.end(), __);
        }
        van=afbreekstack[i-1];
        naar=afbreekstack[i]-1;
        for (j=van; van < naar; van++)
          {
            z.insert(wd[j]);
          };
        if (zoek_zwart_woord(z))
        {
          return false;
        }
      }
    return true;
  }
*/
  bool Afbreker::bepaal_afbreking(const WoordDeel &wd, byte pos, Bestemmingen &PositieBestemmingen, AfbreekParams &params)
  {

    byte i;
    params.afbreekstack.insert(params.afbreekstack.end(), pos);
    bool result = false;
//    if geen_zwarte_lijst(wd) then
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
#if 0
    for( i=0; i < wd.size(); i++)
      {
        if (PositieBestemmingen[i][0]>=2)
          {
            wissel=high_wissel;
            /*In principe eindigt een lettergreep niet op een dubbele klinker,
             behalve in woorden als menuutje, verwissel daarom de posities
             als de eerste positie naar een medeklinker die volgt op een
             dubbele klinker wijst.*/
            if ((Letters::IsMedeKlinker(wd[PositieBestemmingen[i][1]])) &&
                (!((wd[PositieBestemmingen[i][1]]==_t)) &&
                    (wd[PositieBestemmingen[i][2]]==_j)) &&
               (PositieBestemmingen[i][1]+1==PositieBestemmingen[i][2]) &&
               (Letters::IsDubbelKlinker(wd[PositieBestemmingen[i][1]-1])))
              {
                wissel=2;
              }
            /*In woorden als bloeien, zaaien, enz., verkiezen we bloei-en boven
             bloe-i-en. Zorg daarom dat de tweelettergrepige variant vooraan staat.*/
            if ((PositieBestemmingen[i][1]+1==PositieBestemmingen[i][2]) &&
               (wd[PositieBestemmingen[i][1]]==_i) &&
                (Letters::IsDubbelKlinker(wd[PositieBestemmingen[i][1]-1])))
              {
                wissel=2;
                /*Indien de gewenste wissel dood loopt, kiezen we de eerstvolgende
                 positie als wissel. Dit voorkomt dat in woorden als nooit, zaait,
                 de lettergreep "nooi" de eerste keus is en omdat een losse t geen
                 lettergreep kan zijn, het oorspronkelijke noo-it alsnog de eerste
                 keus wordt.*/
                while ((PositieBestemmingen[PositieBestemmingen[i][wissel]][0]==0) &&
                      (PositieBestemmingen[i][0]>wissel)) wissel++;
              };
/*
            if (wissel!=high_wissel)
              {
                t=PositieBestemmingen[i][wissel];
                PositieBestemmingen[i][wissel]=PositieBestemmingen[i][1];
                PositieBestemmingen[i][1]=t;
              }
              */
          }
      }
#endif
  }

  bool Afbreker::breek_af(const WoordDeel &wd, Bestemmingen &PositieBestemmingen)
  {

//     fillchar(positie_bestemmingen,sizeof(positie_bestemmingen),0);
     AfbreekParams params;
     Bestemming bestemming;
     PositieBestemmingen.Add(&bestemming);
     PositieBestemmingen.Add(&bestemming);
     bepaal_afbreekpunten(wd, PositieBestemmingen);
     correcties(wd, PositieBestemmingen);
//     return bepaal_afbreking(wd,1, PositieBestemmingen, params);
     return true;
  }



} /* namespace Afbreken */
