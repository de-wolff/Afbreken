/*
 * VectorComparer.h
 *
 *  Created on: Jan 23, 2014
 *      Author: jaap
 */

#ifndef VECTORCOMPARER_H_
#define VECTORCOMPARER_H_
#include <vector>
#include <map>

using namespace std;

namespace Afbreken
{
  template <typename T, typename _Compare = std::less<T> >
  class VectorComparer
  {
  public:
    typedef _Compare key_compare;

    bool operator ()(const vector<T> &item1, const vector<T> &item2)
      {
      // return item1<item2;
      size_t i = 0;
      while(i < item1.size() && i < item2.size() )
        {
          if (item1[i] != item2[i])
          {
            return comp(item1[i],item2[i]);
          }
          i++;
        }
      return (i < item2.size());
      }
    _Compare comp;

  };

} /* namespace Afbreken */
#endif /* VECTORCOMPARER_H_ */
