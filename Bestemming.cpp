/*
 * Bestemming.cpp
 *
 *  Created on: Jan 29, 2014
 *      Author: jaap
 */
#include "Bestemming.h"
#include "LetterUtil.h"

namespace Afbreken
{
  Bestemming::Bestemming()
    {

    }
  Bestemming::Bestemming(const Bestemming &src):set<positie>(src)
    {

    }

  bool Bestemming::Add(positie pos)
  {
     return insert(pos).second;
  }

  void Bestemming::Remove(positie pos)
  {
    erase(pos);
  }

  void Bestemming::Dump(const WoordDeel &wd, set<positie>  &hoofdLetters, const char *hyphen, ostream &dest)
  {
    size_t  j = 0;
    positie l = 0;
    for (iterator i = begin(); i != end(); i++)
      {
        while (j < *i)
          {
            string str = LetterUtil::Letter2string(wd[j++]);
            string::iterator iter;
            for (iter=str.begin(); iter != str.end(); iter++)
              {
                if (hoofdLetters.find(l++) != hoofdLetters.end())
                  {
                    dest <<  LetterUtil::NaarHoofdLetter(*iter);

                  }
                else
                  {
                    dest << *iter;
                  }
              }
          }
        dest <<  hyphen;
      }
    while (j < wd.size())
      {
        string str = LetterUtil::Letter2string(wd[j++]);
        string::iterator iter;
        for (iter=str.begin(); iter != str.end(); iter++)
          {
            if (hoofdLetters.find(l++) != hoofdLetters.end())
              {
                dest <<  LetterUtil::NaarHoofdLetter(*iter);

              }
            else
              {
                dest << *iter;
              }
          }
      }
  }

  positie Bestemming::operator[](positie pos)
  {
    iterator f = find(pos);
    if (f == end()) return 0;
    return *f;
  }

} /* namespace Afbreken */
