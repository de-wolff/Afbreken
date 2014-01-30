/*
 * Koppen.h
 *
 *  Created on: Jan 18, 2014
 *      Author: jaap
 */

#ifndef KOPPEN_H_
#define KOPPEN_H_
#include <vector>
#include <map>
#include "Letter.h"
#include "VectorComparer.h"
#include "EnumComparer.h"

using namespace std;
namespace Afbreken
{
  typedef enum {
    kp_b, kp_bl, kp_br, kp_c, kp_cl, kp_cr, kp_d, kp_dh, kp_dr, kp_dw, kp_f,
    kp_fl, kp_fn, kp_fr, kp_g, kp_gl, kp_gn, kp_gr, kp_h, kp_j, kp_k, kp_kj,
    kp_kl, kp_kn, kp_kr, kp_kw, kp_l, kp_m, kp_n, kp_p, kp_ph, kp_pj, kp_pl,
    kp_pr, kp_ps, kp_qu, kp_r, kp_rh, kp_s, kp_sc, kp_scl, kp_scr, kp_sf, kp_sh,
    kp_shr, kp_sj, kp_sjt, kp_sk, kp_sl, kp_sm, kp_sn, kp_sp, kp_spl, kp_spr,
    kp_squ, kp_st, kp_sth, kp_str, kp_sw, kp_sch, kp_schl, kp_schm, kp_schn,
    kp_schr, kp_schw, kp_t, kp_th, kp_thr, kp_tj, kp_tm, kp_tr, kp_ts, kp_tsj,
    kp_tw, kp_v, kp_vl, kp_vr, kp_w, kp_wh, kp_wr, kp_x, kp_z, kp_zw, kp_ch,
    kp_chl, kp_chr
  } Koppen_e;

  class Koppen
  {
  public:
#define KOPPEN_SIZE 86
    Koppen();
    Koppen_e Find(const vector<Letter> &wd, bool &ok);

  private:
    VectorComparer<Letter, EnumComparer<Letter> > _Comparer;
    map<vector<Letter>, Koppen_e, VectorComparer<Letter, EnumComparer<Letter> > > _Ordered;
    static vector<Letter>  _Value[KOPPEN_SIZE];

  };

}


#endif /* KOPPEN_H_ */
