/*
 * main.cpp
 *
 *  Created on: Jan 15, 2014
 *      Author: jaap
 */
#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#include "Afbreker.h"
#include "LetterUtil.h"

using namespace Afbreken;


void doe_woord(const string woord, const char *hyphen, ostream &str)
{
  set<positie> Hl;
  Afbreker afbreker;
  Bestemmingen bestemmingen;
  LetterUtil lu;
  WoordDeel wd = lu.string2WoordDeel(woord, Hl);
  afbreker.breek_af(wd, bestemmingen);
  bestemmingen[0].Dump(wd, Hl, hyphen, str);

}


const char* getCmdOption(const char ** begin, const char ** end, const std::string & option)
{
    const char ** itr = std::find(begin, end, option);
    if (itr != end && ++itr != end)
    {
        return *itr;
    }
    return 0;
}

bool cmdOptionExists(const char** begin, const char** end, const std::string& option)
{
    return std::find(begin, end, option) != end;
}

int main(int argc, const char * argv[]) {

  if(cmdOptionExists(argv, argv+argc, "-h"))
  {
      cout << "gebuik:" << endl;
      cout << argv[0] << " [-s spatie] [-k koppelstreep]" << endl;
      cout << " waarbij" << endl;
      cout << " spatie alle spaties vervangt" << endl;
      cout << " en koppelteken op de plaats komt waar een koppelteken kan staan" << endl;

      exit(1);
  }

  const char * space = " ";
  if(cmdOptionExists(argv, argv+argc, "-s"))
  {
      space = getCmdOption(argv, argv + argc, "-s");
  }
  const char * hyphen = "-";
  if(cmdOptionExists(argv, argv+argc, "-k"))
  {
      hyphen = getCmdOption(argv, argv + argc, "-k");
  }
  string myString;
  char myChar;
  char line[256];
  while (!cin.eof())
  {

      int i = 0;
      cin.getline(line, 255);
      myChar = line[i++];
      while ((i < 255) && (myChar != '\0') )
      {
          myString.clear();
        while ((myChar < 64) && (i < 255) && (myChar != '\0') )
       {
        if (myChar < 64)
        {
          if (myChar == ' ')
            {
              cout << space;
            }
          else
            {
              cout << myChar;
            }
        }
        myChar = line[i++];
      }
      while ((myChar >= 64) && (i < 255) && (myChar != '\0') )
      {
          myString+= myChar;
          myChar = line[i++];
      }
      doe_woord(myString , hyphen, cout);
        }
      cout << endl << flush;
  }
  cout << flush;
}

