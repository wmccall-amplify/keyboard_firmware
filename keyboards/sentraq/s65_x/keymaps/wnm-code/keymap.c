#include QMK_KEYBOARD_H

#define _BL 0
#define _FL 1
#define _AL 2
#define _ML 3

#define FL_CAPS LT(_FL, KC_CAPS) // Tap to toggle caps lock and hold to activate function layer

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* 0: Main layer
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
   * │GE │1 !│2 @│3 #│4 $│5 %│6 ^│7 &│8 *│9 (│0 )│- _│= +│Bksp   │Del│
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
   * │Tab  │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │[ {│] }│\ |  │PUp│
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
   * │FnCaps│ A │ S │ D │ F │ G │ H │ J │ K │ L │; :│' "│Enter   │PDn│
   * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
   * │Shift   │ Z │ X │ C │ V │ B │ N │ M │, <│. >│/ ?│Shift │Up │End│
   * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
   * │Ctrl│GUI │Alt │Space                   │Alt│Fn │Ctl│Lft│Dwn│Rgt│
   * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
   */

  /* 0: ANSI qwerty */
  [_BL] = LAYOUT_65_ansi(
    KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,  \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP, \
    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGDN, \
    KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_END,  \
    KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                             KC_RALT, MO(_FL), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT  \
  ),


  /* 1: Fn layer
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
   * │PWR│F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│ reset │slp│
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
   * │     │   │   │   │   │   │   │   │   │   │   │rv-│rv+│RGBtg│blt│
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
   * │      │   │   │   │   │   │   │   │   │   │rh-│rh+│ RGBmod │bl+│
   * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
   * │        │   │   │   │   │   │   │   │   │rs+│rs-│      │VUp│bl-│
   * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
   * │    │    │    │                        │_AL│   │_BL│Mut│VDn│Ply│
   * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
   */

  [_FL] = LAYOUT_65_ansi(
    KC_PWR,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  RESET  , KC_SLEP, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_VAD, RGB_VAI, RGB_TOG, BL_TOGG, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_HUD, RGB_HUI,          RGB_MOD, BL_INC , \
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, RGB_SAD, RGB_SAI, KC_TRNS, KC_VOLU, BL_DEC , \
    _______, _______, _______,                   _______,                            TO(_AL), _______, TO(_BL), KC_MUTE, KC_VOLD, KC_MPLY  \
  ),


  /* 2: Mac layer
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
   * │GE │1 !│2 @│3 #│4 $│5 %│6 ^│7 &│8 *│9 (│0 )│- _│= +│Bksp   │Del│
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
   * │Tab  │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │[ {│] }│\ |  │PUp│
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
   * │FnCaps│ A │ S │ D │ F │ G │ H │ J │ K │ L │; :│' "│Enter   │PDn│
   * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
   * │Shift   │ Z │ X │ C │ V │ B │ N │ M │, <│. >│/ ?│Shift │Up │End│
   * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
   * │Ctrl│Alt │GUI │Space                   │Alt│Fn │Ctl│Lft│Dwn│Rgt│
   * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
   */

  /* 2: Mac ANSI qwerty */
  [_AL] = LAYOUT_65_ansi(
    KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,  \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP, \
    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGDN, \
    KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_END,  \
    KC_LCTL, KC_LALT, KC_LGUI,                    KC_SPC,                             KC_RALT, MO(_ML), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT  \
  ),


  /* 3: Mac Fn layer
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
   * │   │F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│ reset │PWR│
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
   * │     │   │   │   │   │   │   │   │   │   │   │rv-│rv+│RGBtg│blt│
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
   * │      │   │   │   │   │   │   │   │   │   │rh-│rh+│ RGBmod │bl+│
   * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
   * │        │   │   │   │   │   │   │   │   │rs+│rs-│      │VUp│bl-│
   * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
   * │    │    │    │                        │_AL│   │_BL│Mut│VDn│Ply│
   * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
   */

  [_ML] = LAYOUT_65_ansi(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  RESET  , KC_PWR , \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_VAD, RGB_VAI, RGB_TOG, BL_TOGG, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_HUD, RGB_HUI,          RGB_MOD, BL_INC , \
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, RGB_SAD, RGB_SAI, KC_TRNS, KC_VOLU, BL_DEC , \
    _______, _______, _______,                   _______,                            TO(_AL), _______, TO(_BL), KC_MUTE, KC_VOLD, KC_MPLY  \
  ),
};
