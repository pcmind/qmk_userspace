#include QMK_KEYBOARD_H

#include "quantum.h"
#include "keymap_portuguese.h"
#include "sm_td.h"

#define _BASE0 0
#define _AROWS1 1
#define _NUMBER2 2
#define _MOUSE3 3
#define _SYMB4 4
#define _FUNC5 5
#define _GAME6 6
 

enum my_keycodes {
  CKC_A = SAFE_RANGE,
  CKC_S,
  CKC_D,
  CKC_F,
  CKC_J,
  CKC_K,
  CKC_L,
  CKC_SCLN,

  CKC_SPC,
  CKC_TAB,
  CKC_ENT,
  CKC_BSPC,

  MYTD_CTRL,
  MYTD_SHFT
};

/**
toto
* implement tap dance fo MYTD_SHFT and MYTD_CTRL
MYTD_SHFT: on tap: send OSM right shift
           on hold: activate layer _FUNC5
MYTD_CTRL: on tap: send left control
             on hold: activate layer _FUNC5

unused 2 key should alos ativate TG(_FUNC5) toggle layer _FUNC5

combos missing:
CKC_SPC + CKC_BSPC = MO(_FUNC5)
KC_E + KC_R = PT_LCBR // { 
KC_U + KC_I = PT_RCBR // }
KC_C + KC_V = PT_LPRN // (
KC_M + KC_COMM = PT_RPRN // )
KC_W + KC_E = PT_LABK // <
KC_I + KC_O = PT_RABK // >
KC_X + KC_C = PT_LBRC // [
KC_COMM + KC_DOT = PT_RBRC // ]
*/

int threshold = 1;


const uint16_t PROGMEM combo_MTFUNC[] = {CKC_SPC, CKC_BSPC, COMBO_END}; // {
const uint16_t PROGMEM combo_LCBR[] = {KC_E, KC_R, COMBO_END}; // {
const uint16_t PROGMEM combo_RCBR[] = {KC_U, KC_I, COMBO_END}; // }
const uint16_t PROGMEM combo_LPRN[] = {KC_C, KC_V, COMBO_END}; // (
const uint16_t PROGMEM combo_RPRN[] = {KC_M, KC_COMM, COMBO_END}; // )
const uint16_t PROGMEM combo_LABK[] = {KC_W, KC_E, COMBO_END}; // <
const uint16_t PROGMEM combo_RABK[] = {KC_I, KC_O, COMBO_END}; // >
const uint16_t PROGMEM combo_LBRC[] = {KC_X, KC_C, COMBO_END}; // [
const uint16_t PROGMEM combo_RBRC[] = {KC_COMM, KC_DOT, COMBO_END}; // ]


combo_t key_combos[] = {
   COMBO(combo_MTFUNC, MO(_FUNC5)),
   COMBO(combo_LCBR, PT_LCBR),
   COMBO(combo_RCBR, PT_RCBR),
   COMBO(combo_LPRN, PT_LPRN),
   COMBO(combo_RPRN, PT_RPRN),
   COMBO(combo_LABK, PT_LABK),
   COMBO(combo_RABK, PT_RABK),
   COMBO(combo_LBRC, PT_LBRC),
   COMBO(combo_RBRC, PT_RBRC)
};





const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [_BASE0] = LAYOUT_split_3x6_3_ex2(
  //,---------------------------------------------------------------------------------------------.  ,------------------------------------------------------------------------------------------------.
      KC_ESC,  KC_Q,        KC_W,         KC_E,         KC_R,          KC_T,         KC_NO,           KC_NO,        KC_Y,          KC_U,         KC_I,         KC_O,           KC_P,       KC_DEL, 
  //|--------+------------+-------------+--------------+--------------+-------------+-------------.  ,-------------+--------------+--------------+-------------+--------------+-----------+-----------|
      KC_BSPC, CKC_A,       CKC_S,         CKC_D,       CKC_F,          KC_G,        KC_NO,           KC_NO,        KC_H,         CKC_J,          CKC_K,         CKC_L,        CKC_SCLN,    KC_NUHS, 
  //|--------+------------+-------------+--------------+--------------+-------------+-------------.  ,-------------+--------------+--------------+-------------+--------------+-----------+-----------|
      KC_LGUI, KC_Z,       KC_X,         KC_C,           KC_V,          KC_B,                                       KC_N,          KC_M,          KC_COMM,      KC_DOT,        KC_SLSH,    KC_RGUI, 
  //|--------+------------+-------------+--------------+--------------+-------------+-------------.  ,-------------+--------------+--------------+-------------+--------------+-----------+-----------|
                                                        MYTD_CTRL,        CKC_SPC,     CKC_TAB,          CKC_ENT,     CKC_BSPC,    MYTD_SHFT
                                                     //`------------------------------------------'  `------------------------------------------'
),

[_AROWS1] = LAYOUT_split_3x6_3_ex2(
  //,------------------------------------------------------------------------------------------------.  ,------------------------------------------------------------------------------------------------.
	  KC_ESC,    KC_NO,       KC_NO,       LCA(KC_LEFT),   LCA(KC_RGHT),  KC_NO,       LCG(KC_LEFT),    KC_NO,        LCS(KC_Z),     LCTL(KC_V),    LCTL(KC_C),   LCTL(KC_X),    LCTL(KC_Z), KC_DEL,
  //|-----------+------------+-------------+--------------+--------------+-------------+-------------.  ,-------------+--------------+--------------+-------------+--------------+-----------+-----------|
	  KC_NO,     KC_LALT,     KC_LCTL,     KC_LCTL,       KC_LSFT,       KC_NO,        LCG(KC_RGHT),    KC_NO,        KC_CAPS,       KC_LEFT,       KC_DOWN,       KC_UP,        KC_RGHT,    KC_NO,
  //|-----------+------------+-------------+--------------+--------------+-------------+-------------.  ,-------------+--------------+--------------+-------------+--------------+-----------+-----------|
	  KC_NO,     LCTL(KC_Z),  LCTL(KC_X),   LCTL(KC_C),    LCTL(KC_V),    LCS(KC_Z),                                   KC_INS,        KC_HOME,       KC_PGDN,      KC_PGUP,       KC_END,     KC_NO, 
  //|-----------+------------+-------------+--------------+--------------+-------------+-------------.  ,-------------+--------------+--------------+-------------+--------------+-----------+-----------|
	                                                    KC_TRNS,        KC_NO,       KC_TRNS,          KC_TRNS,      KC_TRNS,      KC_TRNS
                                                     //`------------------------------------------'  `------------------------------------------'
),
[_NUMBER2] = LAYOUT_split_3x6_3_ex2(

  //,------------------------------------------------------------------------------------------------.  ,------------------------------------------------------------------------------------------------.
     KC_ESC,     KC_PDOT,      KC_7,         KC_8,         KC_9,          KC_PSLS,      KC_NO,            KC_NO,       KC_NO,         KC_NO,          KC_NO,       KC_NO,           KC_NO,    KC_DEL, 
  //|-----------+------------+-------------+--------------+--------------+-------------+-------------.  ,-------------+--------------+--------------+-------------+--------------+-----------+-----------|
     KC_NO,      KC_SLSH,     KC_4,         KC_5,           KC_6,         KC_PPLS,       KC_NO,           KC_NO,        KC_NO,        KC_RSFT,       KC_RCTL,      KC_LALT,       KC_RGUI,    KC_NO,
  //|-----------+------------+-------------+--------------+--------------+-------------+-------------.  ,-------------+--------------+--------------+-------------+--------------+-----------+-----------|
     KC_NO,      RSFT(KC_0),  KC_1,         KC_2,          KC_3,          LSFT(KC_LBRC),                               KC_NO,         KC_NO,         KC_NO,         KC_RALT,       KC_NO,        KC_NO,       
  //|-----------+------------+-------------+--------------+--------------+-------------+-------------.  ,-------------+--------------+--------------+-------------+--------------+-----------+-----------|
                                                        KC_TRNS,       KC_0,         KC_DOT,          KC_NO,         KC_NO,         KC_NO
                                                     //`------------------------------------------'  `------------------------------------------'
),

[_MOUSE3] = LAYOUT_split_3x6_3_ex2(
  //,------------------------------------------------------------------------------------------------.  ,------------------------------------------------------------------------------------------------.
     KC_ESC,      KC_NO,      KC_NO,       LCTL(KC_E),      KC_NO,        KC_NO,        KC_TRNS,          KC_NO,        LCS(KC_Z),    LCTL(KC_V),    LCTL(KC_C),   LCTL(KC_X),     LCTL(KC_Z),  KC_NO, 
  //|-----------+------------+-------------+--------------+--------------+-------------+-------------.  ,-------------+--------------+--------------+-------------+--------------+-----------+-----------|
  KC_NO,         LCTL(KC_A),  KC_NO,        KC_NO,         KC_NO,         KC_NO,        KC_TRNS,         KC_NO,         KC_APP,       MS_LEFT,       MS_DOWN,       MS_UP,         MS_RGHT,    KC_NO,
  //|-----------+------------+-------------+--------------+--------------+-------------+-------------.  ,-------------+--------------+--------------+-------------+--------------+-----------+-----------|
     UG_TOGG,    LCTL(KC_Z),  LCTL(KC_X),    LCTL(KC_C),    LCTL(KC_V),   LCS(KC_Z),                                    KC_NO,         MS_WHLL,       MS_WHLD,      MS_WHLU,      MS_WHLR,    KC_NO,
  //|-----------+------------+-------------+--------------+--------------+-------------+-------------.  ,-------------+--------------+--------------+-------------+--------------+-----------+-----------|
                                                           KC_TRNS,       KC_TRNS,      KC_NO,            MS_BTN3,      MS_BTN1,      MS_BTN2
                                                        //`------------------------------------------'  `------------------------------------------'
),

[_SYMB4] = LAYOUT_split_3x6_3_ex2(
  //,------------------------------------------------------------------------------------------------.  ,------------------------------------------------------------------------------------------------.
     KC_ESC,      KC_GRV,      KC_MINS,     LSFT(KC_RBRC),  KC_RBRC,       LSFT(KC_7),    KC_TRNS,          KC_NO,      KC_QUOT,       KC_BSLS,       LSFT(KC_BSLS),   KC_NO,      KC_NO,     KC_NO,
  //|-----------+------------+-------------+--------------+--------------+-------------+-------------.  ,-------------+--------------+--------------+-------------+--------------+-----------+-----------|
     RALT(KC_E), LSFT(KC_GRV), LSFT(KC_LBRC), LSFT(KC_6),  LSFT(KC_MINS),  LSFT(KC_5),  KC_TRNS,           KC_NO,      KC_NO,         KC_LSFT,       KC_RCTL,      KC_LALT,        KC_RGUI,    KC_NO, 
  //|-----------+------------+-------------+--------------+--------------+-------------+-------------.  ,-------------+--------------+--------------+-------------+--------------+-----------+-----------|
     KC_NO,      RALT(KC_2),  LSFT(KC_1),   LSFT(KC_2),    LSFT(KC_3),    LSFT(KC_4),                                  KC_NO,         KC_NO,          KC_NO,        KC_RALT,      KC_NO,      KC_NO,
  //|-----------+------------+-------------+--------------+--------------+-------------+-------------.  ,-------------+--------------+--------------+-------------+--------------+-----------+-----------|
                                                           KC_TRNS,       KC_TRNS,      KC_TRNS,           KC_NO,      KC_TRNS,       KC_TRNS
                                                        //`------------------------------------------'  `------------------------------------------'
),

[_FUNC5] = LAYOUT_split_3x6_3_ex2(
  //,------------------------------------------------------------------------------------------------.  ,------------------------------------------------------------------------------------------------.
      KC_TRNS,   KC_F12,      KC_F7,         KC_F8,         KC_F9,          KC_PSCR,       KC_TRNS,        KC_NO,         KC_NO,        KC_NO,         KC_NO,        KC_NO,        KC_NO,       KC_TRNS, 
  //|-----------+------------+-------------+--------------+--------------+-------------+-------------.  ,-------------+--------------+--------------+-------------+--------------+-----------+-----------|
     KC_TRNS,    KC_F11,      KC_F4,        KC_F5,         KC_F6,         KC_INS,       KC_TRNS,          KC_NO,       KC_NO,         KC_RSFT,       KC_RCTL,      KC_LALT,       KC_RGUI,     KC_NO, 
  //|-----------+------------+-------------+--------------+--------------+-------------+-------------.  ,-------------+--------------+--------------+-------------+--------------+-----------+-----------|
     KC_TRNS,    KC_F10,      KC_F1,         KC_F2,        KC_F3,         KC_NO,                                       KC_NO,         KC_NO,          KC_NO,       KC_NO,          KC_NO,      KC_NO, 
  //|-----------+------------+-------------+--------------+--------------+-------------+-------------.  ,-------------+--------------+--------------+-------------+--------------+-----------+-----------|
                                                              KC_NO,       KC_NO,       KC_TRNS,          KC_TRNS,      KC_TRNS,       KC_NO
                                                         //`------------------------------------------'  `------------------------------------------'
),

[_GAME6] = LAYOUT_split_3x6_3_ex2(
  //,------------------------------------------------------------------------------------------------.  ,------------------------------------------------------------------------------------------------.
      KC_ESC,     KC_Q,        KC_W,         KC_E,         KC_R,          KC_T,         KC_NO,            KC_NO,       KC_Y,            KC_U,        KC_I,         KC_O,          KC_P,        KC_DEL, 
  //|-----------+------------+-------------+--------------+--------------+-------------+-------------.  ,-------------+--------------+--------------+-------------+--------------+-----------+-----------|
      KC_BSPC,    KC_A,       KC_S,         KC_D,          KC_F,          KC_G,         KC_NO,            KC_NO,        KC_H,          KC_J,          KC_K,          KC_L,         KC_SCLN,    KC_NUHS,
  //|-----------+------------+-------------+--------------+--------------+-------------+-------------.  ,-------------+--------------+--------------+-------------+--------------+-----------+-----------|
      KC_LGUI,    KC_Z,       KC_X,         KC_C,          KC_V,          KC_B,                                        KC_N,           KC_M,         KC_COMM,       KC_DOT,        KC_SLSH,    KC_RGUI, 
  //|-----------+------------+-------------+--------------+--------------+-------------+-------------.  ,-------------+--------------+--------------+-------------+--------------+-----------+-----------|
                                                            KC_LCTL,      KC_SPC,        LT(3,KC_TAB),    KC_ENT,        KC_BSPC,      KC_RSFT
                                                         //`------------------------------------------'  `------------------------------------------'
)


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
   if (!process_smtd(keycode, record)) {
        return false;
   }

    //user normal key processing

    return true;
}

smtd_resolution on_smtd_action(uint16_t keycode, smtd_action action, uint8_t tap_count) {
    switch (keycode) {
        SMTD_MT_ON_MKEY(CKC_A, KC_A, KC_LEFT_GUI)
        SMTD_MT_ON_MKEY(CKC_S, KC_S, KC_LEFT_ALT)
        SMTD_MT_ON_MKEY(CKC_D, KC_D, KC_LEFT_CTRL)
        SMTD_MT_ON_MKEY(CKC_F, KC_F, KC_LSFT)
        SMTD_MT_ON_MKEY(CKC_SCLN, KC_SCLN, KC_RIGHT_GUI)
        SMTD_MT_ON_MKEY(CKC_L, KC_L, KC_LEFT_ALT)
        SMTD_MT_ON_MKEY(CKC_K, KC_K, KC_RIGHT_CTRL)
        SMTD_MT_ON_MKEY(CKC_J, KC_J, KC_RSFT)
   
        SMTD_LT_ON_MKEY(CKC_SPC, KC_SPC, _AROWS1)
        SMTD_LT_ON_MKEY(CKC_TAB, KC_TAB, _MOUSE3)
        SMTD_LT_ON_MKEY(CKC_ENT, KC_ENT, _SYMB4)
        SMTD_LT_ON_MKEY(CKC_BSPC, KC_BSPC, _NUMBER2)

        SMTD_LT_ON_MKEY(MYTD_CTRL, KC_LCTL, _FUNC5)
        SMTD_LT_ON_MKEY(MYTD_SHFT, KC_RSFT, _FUNC5)
    }

    return SMTD_RESOLUTION_UNHANDLED;
}