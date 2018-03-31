/*
 * EnumComparer.h
 *
 *  Created on: Jan 24, 2014
 *      Author: jaap
 */

#ifndef ENUMCOMPARER_H_
#define ENUMCOMPARER_H_

using namespace std;

namespace Afbreken
{
  template <typename T>
  class EnumComparer
  {
  public:

    bool operator ()(const T &item1, const T &item2) const
    {
      return ((int)item1 < (int)item2);
    }

  };

} /* namespace Afbreken */
#endif /* ENUMCOMPARER_H_ */
