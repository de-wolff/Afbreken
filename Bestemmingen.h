/*
 * Bestemmingen.h
 *
 *  Created on: Jan 29, 2014
 *      Author: jaap
 */

#ifndef BESTEMMINGEN_H_
#define BESTEMMINGEN_H_
#include <vector>
#include "Bestemming.h"

using namespace std;
namespace Afbreken
{

  class Bestemmingen: public vector<Bestemming>
  {
  public:
    Bestemmingen();
    Bestemmingen(const Bestemmingen &src);
    Bestemmingen &operator =(const Bestemmingen &src);
    void Dump(const string &word, const WoordDeel &wd, const char *hyphen, ostream &dest);
    Bestemming *Add(const Bestemming *b);
    Bestemming *Last();
    Bestemming &operator[](size_t index);
  private:
    static Bestemming _dummy;
  };

} /* namespace Afbreken */
#endif /* BESTEMMINGEN_H_ */
