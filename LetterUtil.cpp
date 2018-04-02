/*
 * LetterUtil.cpp
 *
 *  Created on: Jan 18, 2014
 *      Author: jaap
 */

#include "LetterUtil.h"

namespace Afbreken
{

  const Letter Klinkers[] =
    { _a, _e, _i, _o, _u, _y, _aa, _ai, _au, _ee, _eeu, _ei, _eu, _ie, _ieu,
        _ij, _oe, _oo, _ou, _ui, _uu };
  const Letter MedeKlinkers[] =
    { _b, _c, _d, _f, _g, _h, _j, _k, _l, _m, _n, _p, _q, _r, _s, _t, _v, _w,
        _x, _z, _ch };
  const Letter __ =
    { _afbreek };

  bool
  LetterUtil::NaarKleineLetter(char &c)
  {
    if (((c >= 'A') && (c <= 'Z'))
        || ((c >= (char) 0xC0) && (c <= (char) 0xDF)))
      {
        c += 32;
        return true;
      }
    return false;
  }

  char
  LetterUtil::NaarHoofdLetter(char c)
  {
        return (char)(c - 32);
  }

  /*
   Om geen last te hebben van hoofdletters en trema's converteren we woorden
   naar een "woorddeel", waarin we tweeklanken vervangen door hun eigen symbolen.
   Trema's worden hierdoor overbodig. Hoofdletters verwijderen we, maar kunnen
   later weer teruggezet worden omdat de conversieroutine een set teruggeeft
   met de posities die hoofdletter waren.*/
  WoordDeel
  LetterUtil::string2WoordDeel(string str)
  {
    char letter1, letter2, letter3, letter4;
    unsigned int i;
    WoordDeel result;
    string woord;
    //Converteer woord naar kleine letters.
    for (i = 0; i < str.length(); i++)
      {
        char c = str[i];
		NaarKleineLetter(c);
        woord += c;
      }
    // Maak er een woordddeel van.
    i = 0;
    while (i < woord.length())
      {
        positie lengte = woord.length();
        letter1 = woord[i];
		//Verwijder trema's.
		switch (letter1)
		{
		case (char)0xC4: //Ä
		case (char)0xE4: //ä
			letter1 = 'a';
			break;
		case (char)0xCB: //Ë
		case (char)0xEB: //ë
			letter1 = 'e';
			break;
		case (char)0xCF: //Ï
		case (char)0xEF: //ï
			letter1 = 'i';
			break;
		case (char)0XD6: //Ö
		case (char)0XF6: //ö
			letter1 = 'o';
			break;
		case (char)0XDC: //Ü
		case (char)0XFC: //ü
			letter1 = 'u';
			break;
		};
        letter2 = i + 1 < lengte ? woord[i + 1] : '0';
        letter3 = i + 2 < lengte ? woord[i + 2] : '0';
        letter4 = i + 3 < lengte ? woord[i + 3] : '0';
        if ((letter1 == 'i') && (letter2 == 'e') && (letter3 == 'u')
            && (letter4 == 'w'))
          {
            // De ieu wordt alleen gedetecteerd als er een w op volgt, anders
            // wordt in woorden als serieus onterecht een ieu gedetecteerd.
            result.insert(result.end(), _ieu);
            result.insert(result.end(), _w);
            i += 4;
          }
        else if ((letter1 == 'a') && (letter2 == 'a') && (letter3 == 'i'))
          {
            // Handel aai speciaal af om te voorkomen dat in woorden als zaaien
            // een _ai of _ie wordt gedetecteerd.
            result.insert(result.end(), _aa);
            result.insert(result.end(), _i);
            i += 3;
          }
        else if ((letter1 == 'a') && (letter2 == 'i') && (letter3 == 'j'))
          {
            //Handel aij speciaal af om te voorkomen dat in woorden als naijlen
            //een _ai wordt gedetecteerd.
            result.insert(result.end(), _a);
            result.insert(result.end(), _ij);
            i += 3;
          }
        else if ((letter1 == 'e') && (letter2 == 'e') && (letter3 == 'u'))
          {
            result.insert(result.end(), _eeu);
            i += 3;
          }
        else if ((letter1 == 'i') && (letter2 == 'e') && (letter3 == 'e'))
          {
            //Handel iee speciaal af om te voorkomen dat _ie + _e gedetecteerd
            //wordt, dit dient _i+_ee te zijn.
            result.insert(result.end(), _i);
            result.insert(result.end(), _ee);
            i += 3;
          }
        else if ((letter1 == 'i') && (letter2 == 'e') && (letter3 == 'u'))
          {
            //De ieu als in nieuw is hierboven al afgevangen, dus we hebben te
            // maken met een _i+_eu als in serieus.
            result.insert(result.end(), _i);
            result.insert(result.end(), _eu);
            i += 3;
          }
        else if ((letter1 == 'o') && (letter2 == 'e') && (letter3 == 'i'))
          {
            //Handel oei speciaal af om te voorkomen dat in woorden als bloeien
            // een _ie wordt gedetecteerd.
            result.insert(result.end(), _oe);
            result.insert(result.end(), _i);
            i += 3;
          }
        else if ((letter1 == 'o') && (letter2 == 'o') && (letter3 == 'i'))
          {
            //Handel ooi speciaal af om te voorkomen dat in woorden als vlooien
            //een _ie wordt gedetecteerd.
            result.insert(result.end(), _oo);
            result.insert(result.end(), _i);
            i += 3;
          }
        else if ((letter1 == 'q') && (letter2 == 'u') && (letter3 == 'i'))
          {
            //Handel qui speciaal af om te voorkomen dat een _ui gedetecteerd
            // wordt.
            result.insert(result.end(), _q);
            result.insert(result.end(), _u);
            result.insert(result.end(), _i);
            i += 3;
          }
        else if ((letter1 == 'a') && (letter2 == 'a'))
          {
            result.insert(result.end(), _aa);
            i += 2;
          }
        else if ((letter1 == 'a') && (letter2 == 'i'))
          {
            result.insert(result.end(), _ai);
            i += 2;
          }
        else if ((letter1 == 'a') && (letter2 == 'u'))
          {
            result.insert(result.end(), _au);
            i += 2;
          }
        else if ((letter1 == 'c') && (letter2 == 'h'))
          {
            result.insert(result.end(), _ch);
            i += 2;
          }
        else if ((letter1 == 'e') && (letter2 == 'e'))
          {
            result.insert(result.end(), _ee);
            i += 2;
          }
        else if ((letter1 == 'e') && (letter2 == 'i'))
          {
            result.insert(result.end(), _ei);
            i += 2;
          }
        else if ((letter1 == 'e') && (letter2 == 'u'))
          {
            result.insert(result.end(), _eu);
            i += 2;
          }
        else if ((letter1 == 'i') && (letter2 == 'e'))
          {
            result.insert(result.end(), _ie);
            i += 2;
          }
        else if ((letter1 == 'i') && (letter2 == 'j'))
          {
            result.insert(result.end(), _ij);
            i += 2;
          }
        else if ((letter1 == 'o') && (letter2 == 'e'))
          {
            result.insert(result.end(), _oe);
            i += 2;
          }
        else if ((letter1 == 'o') && (letter2 == 'o'))
          {
            result.insert(result.end(), _oo);
            i += 2;
          }
        else if ((letter1 == 'o') && (letter2 == 'u'))
          {
            result.insert(result.end(), _ou);
            i += 2;
          }
        else if ((letter1 == 'u') && (letter2 == 'i'))
          {
            result.insert(result.end(), _ui);
            i += 2;
          }
        else if ((letter1 == 'u') && (letter2 == 'u'))
          {
            result.insert(result.end(), _uu);
            i += 2;
          }
        else if (letter1 == '.')
          {
            result.insert(result.end(), _afbreek);
            i++;
          }
        else
          {
            result.insert(result.end(), (Letter) ((char) _a + letter1 - 'a'));
            i++;
          }

      }
    return result;
  }

  positie LetterUtil::Letter2size(const Letter &l)
  {
	  switch (l)
	  {
	  case _aa:
	  case _ai:
	  case _au:
	  case _ee:
	  case _ei:
	  case _eu:
	  case _ie:
	  case _ij:
	  case _oe:
	  case _oo:
	  case _ou:
	  case _ui:
	  case _uu:
	  case _ch:
		  return 2;
	  case _eeu:
	  case _ieu:
		  return 3;
	  case _afbreek:
		  return 0;
	  }
	  return 1;
  }

  const char *LetterUtil::Letter2string(const Letter &l)
  {
        switch (l)
          {
        case _a:
          return "a";
          break;
        case _b:
          return "b";
        case _c:
          return "c";
        case _d:
          return "d";
        case _e:
          return "e";
        case _f:
          return "f";
        case _g:
          return "g";
        case _h:
          return "h";
        case _i:
          return "i";
        case _j:
          return "j";
        case _k:
          return "k";
        case _l:
          return "l";
        case _m:
          return "m";
        case _n:
          return "n";
        case _o:
          return "o";
        case _p:
          return "p";
        case _q:
          return "q";
        case _r:
          return "r";
        case _s:
          return "s";
        case _t:
          return "t";
        case _u:
          return "u";
        case _v:
          return "v";
        case _w:
          return "w";
        case _x:
          return "x";
        case _y:
          return "y";
        case _z:
          return "z";
        case _aa:
          return "aa";
        case _ai:
          return "ai";
        case _au:
          return "au";
        case _ee:
          return "ee";
        case _eeu:
          return "eeu";
        case _ei:
          return "ei";
        case _eu:
          return "eu";
        case _ie:
          return "ie";
        case _ieu:
          return "ieu";
        case _ij:
          return "ij";
        case _oe:
          return "oe";
        case _oo:
          return "oo";
        case _ou:
          return "ou";
        case _ui:
          return "ui";
        case _uu:
          return "uu";
        case _ch:
          return "ch";
        case _afbreek:
          return"_";
          }
    return "?";
  }

  string
  LetterUtil::WoordDeel2string(const WoordDeel &wd)
  {
    string result;
    for (WoordDeel::const_iterator i = wd.begin(); i != wd.end(); i++)
      {
        result += Letter2string(*i);
      }
    return result;
  }

  string
  LetterUtil::WoordDeel2Letters(const WoordDeel &wd, unsigned char MinLen)
  {
    string result;
    for (WoordDeel::const_iterator i = wd.begin(); i != wd.end(); i++)
      {
        result += '_';
        result += Letter2string(*i);
      }
    while (result.length() < MinLen)
      {
        result += ",__";
      }
    return result;
  }

}/* namespace Afbreken */
