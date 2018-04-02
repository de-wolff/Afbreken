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

  void Bestemming::Dump(const string &woord, const WoordDeel &wd, const string &hyphen, ostream &dest)
  {
    size_t  j = 0;
    positie l = 0;
	string::const_iterator iter = woord.begin();
	for (iterator i = begin(); i != end(); i++)
    {
		positie curpos;
        while (j < *i)
          {
            positie pos = LetterUtil::Letter2size(wd[j++]);
            for (curpos = 0; curpos < pos; curpos++)
              {
                    dest << *iter++;
              }
          }
        dest <<  hyphen;
	}
	while (iter != woord.end())
	{
		dest << *iter++;
	}
  }

  positie Bestemming::operator[](positie pos)
  {
    iterator f = find(pos);
    if (f == end()) return 0;
    return *f;
  }

} /* namespace Afbreken */
