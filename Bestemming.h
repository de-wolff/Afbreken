/*
 * Bestemming.h
 *
 *  Created on: Jan 29, 2014
 *      Author: jaap
 */

#ifndef BESTEMMING_H_
#define BESTEMMING_H_
#include <set>
#include <iostream>
#include "Letter.h"

using namespace std;

namespace Afbreken
{

  class Bestemming: set<positie>
  {
  public:
    Bestemming();
    Bestemming(const Bestemming &src);
	void Dump(const string & woord, const WoordDeel & wd, const string & hyphen, ostream & dest);
	bool Add(positie pos);
    void Remove(positie pos);
    positie operator[](positie pos);
  };

} /* namespace Afbreken */
#endif /* BESTEMMING_H_ */
