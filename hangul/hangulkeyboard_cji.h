#ifndef __HANGULKEYBOARD_CJI_H__
#define __HANGULKEYBOARD_CJI_H__

/* FYI : [Hangul Jamo](http://jrgraphix.net/r/Unicode/1100-11FF) */

static const ucschar hangul_keyboard_table_cji[HANGUL_KEYBOARD_TABLE_SIZE] = {
    ['1'] = 0x1175,     /* ㅣ (jungseong i) */
    ['2'] = 0x119e,     /* . (jungseong araea) */
    ['3'] = 0x1173,     /* ㅡ (jungseong eu) */
    ['4'] = 0x1100,	/* ㄱ, ㅋ (choseong kiyeok) */
    ['5'] = 0x1102,     /* ㄴ, ㄹ (choseong nieun) */
    ['6'] = 0x1103,     /* ㄷ, ㅌ (choseong tikeut) */
    ['7'] = 0x1107,     /* ㅂ, ㅍ (choseong pieuph) */
    ['8'] = 0x1109,     /* ㅅ, ㅎ (choseong sios) */
    ['9'] = 0x110c,     /* ㅈ, ㅊ (choseong cieuc) */
    ['*'] = 0x0000,
    ['0'] = 0x110b,	/* ㅇ,ㅁ  (choseong ieung )*/
    ['#'] = 0x0000,
};

#define KSEQ(P, F) (((P << 16) & 0xffff0000) | (F & 0xffff))
#define CJI_ROTATE2(K, C) \
	{ KSEQ(K, K), C }, { KSEQ(C, K), K },
#define CJI_ROTATE3(K, C1, C2) \
	{ KSEQ(K, K), C1}, { KSEQ(C1, K), C2 }, { KSEQ(C2, K), K },

static const HangulCombinationItem hangul_combination_table_cji[] = {
  CJI_ROTATE2(0x119e, 0x11a2) 		// . , ..

  CJI_ROTATE3(0x1100, 0x110f, 0x1101)	// ㄱ, ㅋ, ㄲ
  CJI_ROTATE2(0x1102, 0x1105)		// ㄴ, ㄹ
  CJI_ROTATE3(0x1103, 0x1110, 0x1104)	// ㄷ, ㅌ, ㄸ
  CJI_ROTATE3(0x1107, 0x1111, 0x1108)	// ㅂ, ㅍ, ㅃ
  CJI_ROTATE3(0x1109, 0x1112, 0x110a)	// ㅅ, ㅎ, ㅆ
  CJI_ROTATE2(0x110b, 0x110b) 		// ㅇ, ㅁ
  CJI_ROTATE3(0x110c, 0x110e, 0x110d)	// ㅈ, ㅊ, ㅉ

  // { 0x11001100, 0x1101 }, /* choseong  kiyeok + kiyeok  = ssangkiyeok   */
  // { 0x11031103, 0x1104 }, /* choseong  tikeut + tikeut  = ssangtikeut   */
  // { 0x11071107, 0x1108 }, /* choseong  pieup  + pieup   = ssangpieup    */
  // { 0x11091109, 0x110a }, /* choseong  sios   + sios    = ssangsios     */
  // { 0x110c110c, 0x110d }, /* choseong  cieuc  + cieuc   = ssangcieuc    */

  CJI_ROTATE3(0x11a8, 0x11a9, 0x11bf)	// ㄱ, ㄲ, ㅋ
  CJI_ROTATE2(0x11ab, 0x11af)		// ㄴ, ㄹ
  CJI_ROTATE3(0x11ae, 0x0000, 0x11c0)	// ㄷ, ㄸ, ㅌ // TODO: 종성 ㄸ 없음!!
  CJI_ROTATE3(0x11b8, 0x0000, 0x11c1)	// ㅂ, ㅃ, ㅍ // TODO: 종성 ㅃ 없음!!
  CJI_ROTATE3(0x11ba, 0x11bb, 0x11c2)	// ㅅ, ㅆ, ㅎ
  CJI_ROTATE2(0x11bc, 0x11b7) 		// ㅇ, ㅁ
  CJI_ROTATE3(0x11bd, 0x0000, 0x11c2)	// ㅈ, ㅉ, ㅊ // TODO: 종성 ㅉ 없음!!

  { 0x11a811a8, 0x11a9 }, /* jongseong kiyeok + kiyeok  = ssangekiyeok  */
  { 0x11a811ba, 0x11aa }, /* jongseong kiyeok + sios    = kiyeok-sois   */
  { 0x11ab11bd, 0x11ac }, /* jongseong nieun  + cieuc   = nieun-cieuc   */
  { 0x11ab11c2, 0x11ad }, /* jongseong nieun  + hieuh   = nieun-hieuh   */
  { 0x11af11a8, 0x11b0 }, /* jongseong rieul  + kiyeok  = rieul-kiyeok  */
  { 0x11af11b7, 0x11b1 }, /* jongseong rieul  + mieum   = rieul-mieum   */
  { 0x11af11b8, 0x11b2 }, /* jongseong rieul  + pieup   = rieul-pieup   */
  { 0x11af11ba, 0x11b3 }, /* jongseong rieul  + sios    = rieul-sios    */
  { 0x11af11c0, 0x11b4 }, /* jongseong rieul  + thieuth = rieul-thieuth */
  { 0x11af11c1, 0x11b5 }, /* jongseong rieul  + phieuph = rieul-phieuph */
  { 0x11af11c2, 0x11b6 }, /* jongseong rieul  + hieuh   = rieul-hieuh   */
  { 0x11b811ba, 0x11b9 }, /* jongseong pieup  + sios    = pieup-sios    */
  { 0x11ba11ba, 0x11bb }, /* jongseong sios   + sios    = ssangsios     */

#if 1
  { 0x1175119e, 0x1161 }, /* ㅣ + .  = ㅏ */
  { 0x11611175, 0x1162 }, /* ㅏ + ㅣ = ㅐ */
  { 0x1161119e, 0x1163 }, /* ㅏ + .  = ㅑ */
  { 0x11631175, 0x1164 }, /* ㅑ + ㅣ = ㅒ */
  { 0x119e1175, 0x1165 }, /* .  + ㅣ = ㅓ */
  { 0x11651175, 0x1166 }, /* ㅓ + ㅣ = ㅔ */
  { 0x11a21175, 0x1167 }, /* .. + ㅣ = ㅕ */
  { 0x11671175, 0x1168 }, /* ㅕ + ㅣ = ㅖ */
  { 0x119e1173, 0x1169 }, /* .  + ㅡ = ㅗ */
  /* 0x116a ~ 0x116c */
  { 0x11a21173, 0x116d }, /* .. + ㅡ = ㅛ */

  { 0x1173119e, 0x116e }, /* ㅡ + .  = ㅜ */
  { 0x116e119e, 0x1172 }, /* ㅜ + .  = ㅠ */
  { 0x11721175, 0x116f }, /* ㅠ + ㅣ = ㅝ */

  // copied form default table
  { 0x11691161, 0x116a }, /* jungseong o      + a       = wa            */
  { 0x11691162, 0x116b }, /* jungseong o      + ae      = wae           */
  { 0x11691175, 0x116c }, /* jungseong o      + i       = oe            */
  { 0x116e1165, 0x116f }, /* jungseong u      + eo      = weo           */
  { 0x116e1166, 0x1170 }, /* jungseong u      + e       = we            */
  { 0x116e1175, 0x1171 }, /* jungseong u      + i       = wi            */
  { 0x11731175, 0x1174 }, /* jungseong eu     + i       = yi            */
#endif

};

#endif
