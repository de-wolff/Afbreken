#include "Letter.h"
#include "Kernen.h"

namespace Afbreken
{

  Kernen::Kernen():_Ordered(_Comparer)
  {

    for (int i = 0; i < KERNEN_SIZE ; i++)
      {
        Kernen_e e = (Kernen_e)i;
        Letter l = _Value[i];
        pair<Letter , Kernen_e>p(l,e);
        _Ordered.insert(p);
      }

  }
  Kernen_e Kernen::Find(const Letter &l, bool &ok)
  {
    ok = (_Ordered.find(l) != _Ordered.end());
    if (ok)
      {
        return _Ordered[l];
      }
    return (Kernen_e)0;
  }


Letter Kernen::_Value[KERNEN_SIZE] = {
   _a ,
   _e ,
   _i ,
   _o ,
   _u ,
   _y ,
   _aa ,
   _ai ,
   _au ,
   _ee ,
   _eeu ,
   _ei ,
   _eu ,
   _ie ,
   _ieu ,
   _ij ,
   _oe ,
   _oo ,
   _ou ,
   _ui ,
   _uu
};


};
/* End. */
