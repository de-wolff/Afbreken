/*
 * Bestemmingen.cpp
 *
 *  Created on: Jan 29, 2014
 *      Author: jaap
 */

#include "Bestemmingen.h"

namespace Afbreken
{
  Bestemming Bestemmingen::_dummy;

  Bestemmingen::Bestemmingen()
  {
  }

  Bestemmingen::Bestemmingen(const Bestemmingen &src):vector<Bestemming>(src)
  {
  }

  Bestemmingen &Bestemmingen::operator =(const Bestemmingen &src)
  {
    clear();
    for(const_iterator i= src.begin(); i != src.end(); i++)
      {
        insert(end(),*i);
      }
    return *this;
  }


  Bestemming *Bestemmingen::Add(const Bestemming *bestemming)
  {
    iterator i = insert(end(), *bestemming);
    return &*i;
  }


  Bestemming *Bestemmingen::Last()
  {
    if (size() == 0) return NULL;
    return &((vector<Bestemming>*)(this))->operator[](size() - 1);
  }

  Bestemming &Bestemmingen::operator[](size_t index)
  {
    if (index < size())
    {
        return ((vector<Bestemming>*)(this))->operator[](index);
    }
    if (index == size())
    {
        Bestemming b;
        return *Add(&b);
    }
    return _dummy;
  }
  void Bestemmingen::Dump(const string &word, const WoordDeel &wd, const char *hyphen, ostream &dest)
  {
    for (iterator i = begin(); i != end(); i++)
      {
        i->Dump(word, wd, hyphen, dest);
      }
  }


} /* namespace Afbreken */
