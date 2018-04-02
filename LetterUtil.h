/*
 * LetterUtil.h
 *
 *  Created on: Jan 18, 2014
 *      Author: jaap
 */

#ifndef LETTERUTIL_H_
#define LETTERUTIL_H_
#include <string>
#include <list>

#include "Letter.h"

using namespace std;

namespace Afbreken {

class LetterUtil {
public :
	static WoordDeel string2WoordDeel(string str);
	static const char *Letter2string(const Letter &l);
	static positie Letter2size(const Letter &l);
	static string WoordDeel2string(const WoordDeel &wd);
	static string WoordDeel2Letters(const WoordDeel &wd, unsigned char MinLen);
	static bool NaarKleineLetter(char &c);
	static char NaarHoofdLetter(char c);
};

} /* namespace Afbreken */
#endif /* LETTERUTIL_H_ */
