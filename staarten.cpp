#include "Letter.h"
#include "Staarten.h"

namespace Afbreken
{


  Staarten::Staarten():_Ordered(_Comparer)
  {
    for (int i = 0; i < STAARTEN_SIZE ; i++)
      {
        Staarten_e e = (Staarten_e)i;
        vector<Letter> l = _Value[i];
        pair<vector<Letter> , Staarten_e>p(l,e);
        _Ordered.insert(p);
      }
  }

  Staarten_e Staarten::Find(const vector<Letter> &wd, bool &ok)
  {
    map<vector<Letter>, Staarten_e, VectorComparer<Letter, EnumComparer<Letter> > >::iterator i = _Ordered.find(wd);
    ok = (i != _Ordered.end());
    if (ok)
      {
        return i->second;
      }
    return (Staarten_e)0;
  }


  vector<Letter> Staarten::_Value[STAARTEN_SIZE] = {
  { _b },
  { _b, _d },
  { _b, _s},
  { _b, _t },
  { _c },
  { _c, _k },
  { _c, _k, _t  },
  { _c, _s },
  { _c, _s, _t },
  { _c, _t },
  { _c, _t, _s },
  { _c, _t, _s, _t },
  { _d },
  { _d, _s },
  { _d, _s, _t },
  { _d, _t },
  { _f },
  { _f, _d },
  { _f, _d, _s },
  { _f, _d, _s, _t },
  { _f, _d, _t },
  { _f, _f },
  { _f, _s },
  { _f, _s, _t },
  { _f, _t },
  { _f, _t, _s },
  { _f, _t, _s, _t },
  { _g },
  { _g, _d },
  { _g, _d, _s, _t },
  { _g, _d, _t },
  { _g, _n },
  { _g, _s },
  { _g, _s, _t },
  { _g, _t },
  { _h },
  { _h, _n },
  { _h, _n, _d },
  { _i },
  { _i, _d},
  { _i, _d, _s, _t },
  { _i, _g },
  { _i, _l },
  { _i, _n },
  { _i, _n, _d },
  { _i, _n, _t },
  { _i, _r },
  { _i, _r, _s },
  { _i, _r, _s, _t },
  { _i, _r, _t },
  { _i, _s },
  { _i, _s, _d },
  { _i, _s, _t },
  { _i, _t },
  { _j },
  { _j, _s },
  { _k },
  { _k, _s },
  { _k, _s, _t },
  { _k, _t },
  { _k, _t, _s, _t },
  { _l },
  { _l, _d },
  { _l, _d, _s },
  { _l, _d, _s, _t },
  { _l, _d, _t },
  { _l, _f },
  { _l, _f, _d },
  { _l, _f, _d, _s, _t },
  { _l, _f, _s },
  { _l, _f, _t },
  { _l, _f, _t, _s },
  { _l, _g },
  { _l, _g, _d },
  { _l, _g, _d, _s, _t },
  { _l, _g, _t },
  { _l, _k },
  { _l, _k, _s },
  { _l, _k, _s, _t },
  { _l, _k, _t },
  { _l, _k, _t, _s, _t },
  { _l, _l },
  { _l, _l, _s },
  { _l, _m },
  { _l, _m, _d },
  { _l, _m, _s },
  { _l, _m, _s, _t },
  { _l, _m, _t },
  { _l, _p },
  { _l, _p, _s },
  { _l, _p, _s, _t },
  { _l, _p, _t },
  { _l, _s },
  { _l, _s, _d },
  { _l, _s, _t },
  { _l, _t },
  { _l, _t, _s },
  { _m },
  { _m, _b },
  { _m, _b, _t },
  { _m, _b, _t, _s },
  { _m, _d },
  { _m, _d, _s },
  { _m, _d, _s, _t },
  { _m, _d, _t },
  { _m, _f },
  { _m, _p },
  { _m, _p, _s },
  { _m, _p, _s, _t },
  { _m, _p, _t },
  { _m, _p, _t, _s, _t },
  { _m, _s },
  { _m, _s, _j },
  { _m, _s, _j, _t },
  { _m, _s, _t },
  { _m, _t },
  { _n },
  { _n, _c },
  { _n, _c, _t },
  { _n, _d },
  { _n, _d, _s },
  { _n, _d, _s, _t },
  { _n, _d, _t },
  { _n, _g },
  { _n, _g, _d },
  { _n, _g, _d, _s, _t },
  { _n, _g, _s },
  { _n, _g, _s, _t },
  { _n, _g, _t },
  { _n, _k },
  { _n, _k, _s },
  { _n, _k, _s, _t },
  { _n, _k, _t },
  { _n, _s },
  { _n, _s, _d },
  { _n, _s, _t },
  { _n, _t },
  { _n, _t, _s },
  { _n, _t, _s, _t },
  { _n, _x },
  { _n, _ch },
  { _p },
  { _p, _s },
  { _p, _s, _t },
  { _p, _t },
  { _p, _t, _s },
  { _p, _t, _s, _t },
  { _r },
  { _r, _c },
  { _r, _c, _t },
  { _r, _d },
  { _r, _d, _s },
  { _r, _d, _s, _t },
  { _r, _d, _t },
  { _r, _f },
  { _r, _f, _d },
  { _r, _f, _d, _s, _t },
  { _r, _f, _s, _t },
  { _r, _f, _t },
  { _r, _f, _t, _s, _t },
  { _r, _g },
  { _r, _g, _d },
  { _r, _g, _d, _s, _t },
  { _r, _g, _s },
  { _r, _g, _s, _t },
  { _r, _g, _t },
  { _r, _k },
  { _r, _k, _s },
  { _r, _k, _s, _t },
  { _r, _k, _t },
  { _r, _k, _t, _s, _t },
  { _r, _l },
  { _r, _l, _d },
  { _r, _l, _t },
  { _r, _m },
  { _r, _m, _d },
  { _r, _m, _d, _s, _t },
  { _r, _m, _s },
  { _r, _m, _s, _t },
  { _r, _m, _t },
  { _r, _n },
  { _r, _n, _d },
  { _r, _n, _d, _s, _t },
  { _r, _n, _s },
  { _r, _n, _s, _t },
  { _r, _n, _t },
  { _r, _p },
  { _r, _p, _s },
  { _r, _p, _s, _t },
  { _r, _p, _t },
  { _r, _s },
  { _r, _s, _d },
  { _r, _s, _t },
  { _r, _s, _ch },
  { _r, _t },
  { _r, _t, _s },
  { _r, _t, _s, _t },
  { _r, _v },
  { _r, _w },
  { _r, _w, _d },
  { _r, _w, _s, _t },
  { _r, _w, _t },
  { _r, _z },
  { _r, _ch },
  { _r, _ch, _t },
  { _s },
  { _s, _c },
  { _s, _d },
  { _s, _h },
  { _s, _h, _t },
  { _s, _j },
  { _s, _k },
  { _s, _k, _s },
  { _s, _k, _s, _t },
  { _s, _p },
  { _s, _p, _t },
  { _s, _t },
  { _s, _t, _s },
  { _s, _ch },
  { _s, _ch, _t },
  { _t },
  { _t, _h },
  { _t, _s },
  { _t, _s, _j },
  { _t, _s, _t },
  { _t, _s, _ch },
  { _t, _z },
  { _v },
  { _w },
  { _w, _d },
  { _w, _d, _s },
  { _w, _d, _s, _t },
  { _w, _n },
  { _w, _n, _s },
  { _w, _s },
  { _w, _s, _t },
  { _w, _t },
  { _x },
  { _x, _t },
  { _z },
  { _ch },
  { _ch, _s },
  { _ch, _t },
  { _ch, _t, _s },
  { _ch, _t, _s, _t }
};

}

/* End. */
