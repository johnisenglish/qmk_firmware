#include "dactyl-manuform.h"
#include "action_layer.h"
#include "eeconfig.h"
#include "quantum.h"
// #include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

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


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = KEYMAP_5x6(
  // left hand
   KC_ESC,    KC_1,    KC_2,    KC_3,   KC_4,   KC_5, 
   KC_GRV,    KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,
   KC_TAB,    KC_A,    KC_S,    KC_D,   KC_F,   KC_G,
   KC_LSHIFT, KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,
                             KC_BSPC, KC_DEL,
                                 KC_ENTER, KC_SPC,
                                   MO(_DN_L), MO(_UP_L),
                                   MO(_SMSL), MO(_SM_L),
  // right hand
    KC_6,    KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS,
    KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,    KC_EQL,
    KC_H,    KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT, 
    KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSHIFT,
                       KC_BSPC, KC_DEL,
                KC_SPC, KC_ENTER,
        MO(_UP_R), MO(_DN_R),
        MO(_SM_R), MO(_SMSR)),
[_UP_L] = KEYMAP_5x6(
  // left hand
    _______,   KC_PAST, KC_7,    KC_8,    KC_9,    KC_LCBR,
    _______,   KC_EQL,  KC_4,    KC_5,    KC_6,    KC_LBRC,
    _______,   KC_MINS, KC_1,    KC_2,    KC_3,    KC_LPRN,
    MO(_UPSL), KC_BSLS, KC_0,    KC_COMM, KC_DOT,  KC_LABK,
                        _______,  _______,
                              _______, _______,
                                   _______, _______,
                                   _______, _______,
  // right hand
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
                        _______, _______,
                  _______, _______,
        _______, _______,
        _______, _______),
[_UP_R] = KEYMAP_5x6(
  // left hand
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
                        _______,  _______,
                              _______, _______,
                                   _______, _______,
                                   _______, _______,
  // right hand
    KC_RCBR, KC_7,    KC_8,    KC_9,    KC_PAST, _______,
    KC_RBRC, KC_4,    KC_5,    KC_6,    KC_EQL,  _______,
    KC_RPRN, KC_1,    KC_2,    KC_3,    KC_MINS, CTL_QUO,
    KC_RABK, KC_0,    _______, _______, KC_BSLS, MO(_UPSR),
                       _______,  _______,
                  _______,  _______,
        _______, _______,
        _______, _______),
[_UPSL] = KEYMAP_5x6(
  // left hand
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, KC_PSCR, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
                        _______,  _______,
                              _______, _______,
                                   _______, _______,
                                   _______, _______,
  // right hand
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
                        _______, _______,
                  _______, _______,
        _______, _______,
        _______, _______),
[_UPSR] = KEYMAP_5x6(
  // left hand
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
                        _______,  _______,
                              _______, _______,
                                   _______, _______,
                                   _______, _______,
  // right hand
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, CTL_QUO,
    _______, _______, _______, _______, _______, MO(_UPSR),
                       _______,  _______,
                  _______,  _______,
        _______, _______,
        _______, _______),
[_DN_L] = KEYMAP_5x6(
  // left hand
    KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,
    _______, LCTL(KC_Q), KC_PGUP, KC_UP, KC_PGDN, KC_HOME,
    _______, LCTL(KC_A), KC_LEFT, KC_DOWN, KC_RGHT, KC_END,
    MO(_DNSL), _______, _______, _______, _______, _______,
                        _______,  _______,
                              _______, _______,
                                   _______, _______,
                                   _______, _______,
  // right hand
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
                        _______, _______,
                  _______, _______,
        _______, _______,
        _______, _______),
[_DN_R] = KEYMAP_5x6(
  // left hand
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
                        _______,  _______,
                              _______, _______,
                                   _______, _______,
                                   _______, _______,
  // right hand
    KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,   KC_F11,
    KC_HOME, KC_PGUP, KC_UP, KC_PGDN, _______, _______,
    KC_END, KC_LEFT, KC_DOWN, KC_RGHT,   _______, CTL_QUO,
    _______, _______, _______, _______, _______, MO(_DNSR),
                       _______,  _______,
                  _______,  _______,
        _______, _______,
        _______, _______),
[_DNSL] = KEYMAP_5x6(
  // left hand
    _______, _______, _______, _______, _______, _______,
    _______, _______, KC_WH_U, KC_MS_U, KC_WH_D, KC_BTN2,
    _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN1,
    MO(_DNSL), _______, _______, _______, _______, _______,
                        _______,  _______,
                              _______, _______,
                                   _______, _______,
                                   _______, _______,
  // right hand
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
                        _______, _______,
                  _______, _______,
        _______, _______,
        _______, _______),
[_DNSR] = KEYMAP_5x6(
  // left hand
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
                        _______,  _______,
                              _______, _______,
                                   _______, _______,
                                   _______, _______,
  // right hand
    _______, _______, _______, _______, _______, _______,
    KC_BTN2, KC_WH_U, KC_MS_U, KC_WH_D, _______, _______,
    KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_R, _______, CTL_QUO,
    KC_BTN3, _______, _______, _______, _______, MO(_DNSR),
                       _______,  _______,
                  _______,  _______,
        _______, _______,
        _______, _______),
[_EX_L] = KEYMAP_5x6(
  // left hand
    LGUI(S(KC_Q)), _______,    LGUI(KC_7), LGUI(KC_8), LGUI(KC_9), _______,
    LGUI(KC_GRV), KC_MNXT, LGUI(KC_4), LGUI(KC_5), LGUI(KC_6), KC_VOLU,
    _______, KC_MPLY, LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), KC_MUTE,
    _______, LCTL(KC_Z), LGUI(KC_X), LGUI(KC_C), LGUI(KC_D), KC_VOLD,
                        _______,  _______,
                              _______, _______,
                                   _______, _______,
                                   _______, _______,
  // right hand
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
                        _______, _______,
                  _______, _______,
        _______, _______,
        _______, _______),
[_EX_R] = KEYMAP_5x6(
  // left hand
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
                        _______,  _______,
                              _______, _______,
                                   _______, _______,
                                   _______, _______,
  // right hand
    _______, RGUI(KC_7), RGUI(KC_8), RGUI(KC_9), KC_PAST, RGUI(S(KC_Q)),
    KC_VOLU, RGUI(KC_4), RGUI(KC_5), RGUI(KC_6), KC_MNXT, _______,
    KC_MUTE, RGUI(KC_1), RGUI(KC_2), RGUI(KC_3), KC_MPLY, _______,
    KC_VOLD, RGUI(KC_0), RGUI(KC_C), RGUI(KC_D), KC_MPRV, _______,
                       _______,  _______,
                  _______,  _______,
        _______, _______,
        _______, _______),
[_SM_L] = KEYMAP_5x6(
  // left hand
    RESET, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
                        _______, _______,
                              _______, _______,
                                   _______, _______,
                                   _______, _______,
  // right hand
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
                        _______, _______,
                  _______, _______,
        _______, _______,
        _______, _______),
[_SM_R] = KEYMAP_5x6(
  // left hand
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
                        _______,  _______,
                              _______, _______,
                                   _______, _______,
                                   _______, _______,
  // right hand
    _______, _______, _______, _______, _______, RESET,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,
                        _______, _______,
                  _______, _______,
        _______, _______,
        _______, _______),
};


void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}
