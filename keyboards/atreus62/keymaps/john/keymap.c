// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE  0
#define _UP_L  1
#define _UP_R  2
#define _UPSR  3
#define _UPSL  4
#define _DN_L  5
#define _DN_R  6
#define _DNSL  7
#define _DNSR  8
#define _EX_L  9
#define _EX_R  10
#define _SM_L  11
#define _SM_R  12
#define _SMSL  13
#define _SMSR  14
#define _SMML  15
#define _SMMR  16

// Fillers to make layering more clear

#define __ KC_TRNS
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define THMB_UL LT(_UP_L, KC_ENTER)
#define THMB_UR LT(_UP_R, KC_ENTER)
#define THMB_DL LT(_DN_L, KC_SPACE)
#define THMB_DR LT(_DN_R, KC_SPACE)
#define CTL_TAB LCTL_T(KC_TAB)
#define CTL_RHT RCTL_T(KC_RGHT)
#define CTL_QUO RCTL_T(KC_QUOT)
#define GUI_ENT RGUI_T(KC_ENT)
#define GUI_DEL RGUI_T(KC_DELETE)
#define GUI_UP RGUI_T(KC_UP)
#define GUI_TAB RGUI_T(KC_TAB)
#define ALT_TIL LALT_T(KC_GRAVE)
#define ALT_DWN RALT_T(KC_DOWN)
#define ALT_DEL RALT_T(KC_DELETE)
#define ALT_BSP RALT_T(KC_BSPC)
#define SFT_TAB LSFT_T(KC_TAB)
#define SYM_DEL LT(_SM_R, KC_DELETE)
#define SYM_BSP LT(_SM_L, KC_BSPC)
#define H_ALT_A LALT_T(KC_A)
#define H_GUI_E LGUI_T(KC_E)
#define H_SFT_S LSFT_T(KC_S)
#define H_CTL_T LCTL_T(KC_T)
#define H_HYP_G ALL_T(KC_G)
#define EXT_L LT(_EX_L, KC_TAB)
#define EXT_R LT(_EX_R, KC_TAB)
#define ALT_LED ALT_T(KC_LEAD)
#define AGR_LED ALGR_T(KC_LEAD)

#define STAR 0x2605 // ★

void matrix_init_user(void) {
    set_unicode_input_mode(UC_LNX); // REPLACE UC_XXXX with the Unicode Input Mode for your OS. See table below.
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BASE] = LAYOUT(  /* Colemak_dh= */
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    ALT_TIL, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                        KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, ALT_DEL,
    KC_RCTL, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                        KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                        KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_LSFT,
    KC_LCTL, KC_LGUI, KC_LALT, SYM_BSP, GUI_TAB,   THMB_DL, THMB_UL,   THMB_UR, THMB_DR, GUI_TAB,   SYM_DEL, ALT_DWN, GUI_UP,  CTL_RHT
  ),

  [_UP_L] = LAYOUT(
    _______, KC_PAST, KC_7,    KC_8,    KC_9,    KC_LCBR,                   _______, _______, _______, _______, _______, _______,
    _______, KC_EQL,  KC_4,    KC_5,    KC_6,    KC_LBRC,                   _______, _______, _______, _______, _______, _______,
    _______, KC_MINS, KC_1,    KC_2,    KC_3,    KC_LPRN,                   _______, _______, _______, _______, _______, _______,
    MO(_UPSL), KC_BSLS, KC_0,  KC_COMM, KC_DOT,  KC_LABK,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, MO(_EX_L), _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_UP_R] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                   KC_RCBR, KC_7,    KC_8,    KC_9,    KC_PAST, _______,
    _______, _______, _______, _______, _______, _______,                   KC_RBRC, KC_4,    KC_5,    KC_6,    KC_EQL,  _______,
    _______, _______, _______, _______, _______, _______,                   KC_RPRN, KC_1,    KC_2,    KC_3,    KC_MINS, CTL_QUO,
    _______, _______, _______, _______, _______, _______,                   KC_RABK, KC_0,    _______, _______, KC_BSLS, MO(_UPSR),
    _______, _______, _______, _______, _______, _______, _______,  _______, MO(_EX_R), _______, _______, _______, _______, _______
  ),

  [_UPSL] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, KC_PSCR, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    MO(_UPSR), _______, _______, _______, _______, _______,                 _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, MO(_EX_L), _______, _______, _______, _______, _______, _______, _______
  ),

  [_UPSR] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, CTL_QUO,
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, MO(_UPSR),
    _______, _______, _______, _______, _______, _______, _______, MO(_EX_L), _______, _______, _______, _______, _______, _______
  ),

  [_DN_L] = LAYOUT(
    KC_F12,  KC_F1,   KC_F2,   KC_F3,    KC_F4,  KC_F5,                    _______, _______, _______, _______, _______, _______,
    _______, LCTL(KC_Q), KC_PGUP, KC_UP, KC_PGDN, KC_HOME,                    _______, _______, _______, _______, _______, _______,
    _______, LCTL(KC_A), KC_LEFT, KC_DOWN, KC_RGHT, KC_END,                   _______, _______, _______, _______, _______, _______,
    MO(_DNSL), LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_D), LCTL(KC_V),    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, MO(_EX_L), _______, _______, _______, _______, _______, _______, _______
  ),

  [_DN_R] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,   KC_F11,
    _______, _______, _______, _______, _______, _______,                   KC_HOME, KC_PGUP, KC_UP, KC_PGDN, _______, _______,
    _______, _______, _______, _______, _______, _______,                   KC_END, KC_LEFT, KC_DOWN, KC_RGHT,   _______, CTL_QUO,
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, MO(_DNSR),
    _______, _______, _______, _______, _______, _______, _______, MO(_EX_R), _______, _______, _______, _______, _______, _______
  ),

  [_EX_L] = LAYOUT(
    LGUI(S(KC_Q)), _______,    LGUI(KC_7), LGUI(KC_8), LGUI(KC_9), _______,                   _______, _______, _______, _______, _______, RESET,
    LGUI(KC_GRV), KC_MNXT, LGUI(KC_4), LGUI(KC_5), LGUI(KC_6), KC_VOLU,           _______, _______, _______, _______, _______, _______,
    _______, KC_MPLY, LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), KC_MUTE,                   _______, _______, _______, _______, _______, _______,
    _______, LCTL(KC_Z), LGUI(KC_X), LGUI(KC_C), LGUI(KC_D), KC_VOLD,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_EX_R] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                   _______, RGUI(KC_7), RGUI(KC_8), RGUI(KC_9), KC_PAST, RGUI(S(KC_Q)),
    _______, _______, _______, _______, _______, _______,                   KC_VOLU, RGUI(KC_4), RGUI(KC_5), RGUI(KC_6), KC_MNXT, _______,
    _______, _______, _______, _______, _______, _______,                   KC_MUTE, RGUI(KC_1), RGUI(KC_2), RGUI(KC_3), KC_MPLY, _______,
    _______, _______, _______, _______, _______, _______,                   KC_VOLD, RGUI(KC_0), RGUI(KC_C), RGUI(KC_D), KC_MPRV, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_SM_L] = LAYOUT(
    RESET, UC(8543), UC(189), UC(8531), UC(188), UC(8533),                _______, _______, _______, _______, _______, _______,
    _______, UC(952), UC(969), UC(966), UC(960), UC(946),                   _______, _______, _______, _______, _______, _______,
    _______, UC(945), UC(961), UC(963), UC(964), UC(947),                   _______, _______, _______, _______, _______, _______,
    MO(_SMSL), UC(950), UC(967), UC(162), UC(948), UC(8711),                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_SM_R] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                   UC(8537), UC(8528), UC(8539), UC(8529), UC(8530), RESET,
    _______, _______, _______, _______, _______, _______,                   UC(958), UC(955), UC(965), UC(968), UC(177), _______,
    _______, _______, _______, _______, _______, _______,                   UC(956), UC(8470), UC(949), UC(8734), _______, _______,
    _______, _______, _______, _______, _______, _______,                   UC(922), UC(951), UC(8804), UC(8805), UC(247), MO(_SMSR),
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_SMSL] = LAYOUT(
    _______, UC(8265), UC(178), UC(179), UC(163), UC(8733),                 _______, _______, _______, _______, _______, _______,
    UC(65103), UC(920), UC(937), UC(934), UC(928), UC(914),                 _______, _______, _______, _______, _______, _______,
    _______, UC(913), UC(929), UC(931), UC(932), UC(915),                   _______, _______, _______, _______, _______, _______,
    _______, UC(918), UC(935), UC(8364), UC(916), UC(8730),                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_SMSR] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                   UC(8743), _______, UC(10032), UC(11816), UC(11817), _______,
    _______, _______, _______, _______, _______, _______,                   UC(926), UC(923), _______, UC(936), UC(8757), _______,
    _______, _______, _______, _______, _______, _______,                   UC(13186), UC(8470), UC(1013), UC(8747), _______, _______,
    _______, _______, _______, _______, _______, _______,                   UC(954), UC(13185), UC(8810), UC(8811), UC(8756), _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_SMML] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    MO(_UPSR), _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, MO(_EX_L), _______, _______, _______, _______, _______, _______, _______
  ),

  [_SMMR] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, CTL_QUO,
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, MO(_UPSR),
    _______, _______, _______, _______, _______, _______, _______, MO(_EX_R), _______, _______, _______, _______, _______, _______
  ),

  /*
  [_TRNS] = LAYOUT(
    _______,  _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______ ,
    _______,  _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______ ,
    _______,  _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______ ,
    _______,  _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______ ,
    _______,  _______, _______, _______, _______, _______, _______,  _______,  _______, _______, _______, _______, _______, _______
  ),
  */
  };



const uint16_t PROGMEM fn_actions[] = {

};


const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  // MACRODOWN only works in this function
  switch (id) {
  case 0:
    if (record->event.pressed) {
      register_code(KC_RSFT);
    }
    else {
      unregister_code(KC_RSFT);
    }
    break;
  }
  return MACRO_NONE;
};
