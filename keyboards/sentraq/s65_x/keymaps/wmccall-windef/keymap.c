#include QMK_KEYBOARD_H

#define _BL 0   // Windows layer
#define _BFL 1  // Windows layer Fn Layer
#define _BLD 4  // Windows layer - Dvorak
#define _BFLD 5 // Windows layer Fn Layer - Dvorak

#define _ML 2   // Mac Layer
#define _MFL 3  // Mac Fn Layer
#define _MLD 6  // Mac Layer - Dvorak
#define _MFLD 7 // Mac Fn Layer - Dvorak

// Macro to perform ctrl + alt + del
#define KC_CAD LALT(LCTL(KC_DEL))

// Macro to perform ctrl + shift + esc
#define KC_CSE LSFT(LCTL(KC_ESC))

// Macro to sleep mac (ctrl + shift + power)
#define KC_MAC_SLEEP LSFT(LCTL(KC_PWR))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* 0: Windows layer
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
   * │GE │1 !│2 @│3 #│4 $│5 %│6 ^│7 &│8 *│9 (│0 )│- _│= +│Bksp   │Del│
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
   * │Tab  │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │[ {│] }│\ |  │Ins│
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
   * │ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │; :│' "│Enter   │PUp│
   * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
   * │Shift   │ Z │ X │ C │ V │ B │ N │ M │, <│. >│/ ?│Shift │Up │PDn│
   * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
   * │Ctrl│GUI │Alt │Space                   │Alt│Fn │Ctl│Lft│Dwn│Rgt│
   * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
   */

  /* 0: Windows layer */
  [_BL] = LAYOUT_65_ansi(
    KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,  \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC, KC_RBRC, KC_BSLS, KC_INS , \
    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,          KC_ENT,  KC_PGUP, \
    KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH, KC_RSFT, KC_UP,   KC_PGDN, \
    KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                             KC_RALT, MO(_BFL), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT  \
  ),


  /* 1: Windows Fn layer
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
   * │ ~ │F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│       │slp│
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
   * │     │   │   │   │   │   │   │   │   │   │   │rv-│rv+│RGBtg│blt│
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
   * │      │   │   │   │   │   │   │   │   │   │rh-│rh+│ RGBmod │bl+│
   * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
   * │        │   │   │   │   │   │   │   │   │rs+│rs-│ Play │VUp│bl-│
   * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
   * │Rset│    │    │                        │_ML│   │_BL│Prv│VDn│Nxt│
   * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
   */

   /* 1: Windows Fn layer */
  [_BFL] = LAYOUT_65_ansi(
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,   KC_F12,  _______, KC_SLEP, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_VAD,  RGB_VAI, RGB_TOG, BL_TOGG, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_HUD, RGB_HUI,           RGB_MOD, BL_INC , \
    KC_CSE ,          _______, _______, _______, _______, _______, _______, _______, _______, RGB_SAD, RGB_SAI,  KC_MPLY, KC_VOLU, BL_DEC , \
    RESET  , _______, KC_CAD ,                   _______,                            TO(_ML), _______, TO(_BLD), KC_MPRV, KC_VOLD, KC_MNXT  \
  ),

  /* 4: Windows layer - DVORAK
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
   * │GE │1 !│2 @│3 #│4 $│5 %│6 ^│7 &│8 *│9 (│0 )│[ {│] }│Bksp   │Del│
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
   * │Tab  │' "│, <│. >│ P │ Y │ F │ G │ C │ R │ L │/ ?│= +│\ |  │Ins│
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
   * │ Caps │ A │ O │ E │ U │ I │ D │ H │ T │ N │ S │- _│Enter   │PUp│
   * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
   * │Shift   │; :│ Q │ J │ K │ X │ B │ M │ W │ V │ Z │Shift │Up │PDn│
   * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
   * │Ctrl│GUI │Alt │Space                   │Alt│Fn │Ctl│Lft│Dwn│Rgt│
   * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
   */

  /* 4: Windows layer - DVORAK */
  [_BLD] = LAYOUT_65_ansi(
    KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,      KC_LBRC, KC_RBRC, KC_BSPC, KC_DEL,  \
    KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,      KC_SLSH, KC_EQL,  KC_BSLS, KC_INS,  \
    KC_CAPS, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,      KC_MINS,          KC_ENT,  KC_PGUP, \
    KC_LSFT,          KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,      KC_Z,    KC_RSFT, KC_UP,   KC_PGDN, \
    KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                             KC_RALT, MO(_BFLD), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT  \
  ),


  /* 5: Windows Fn layer - DVORAK
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
   * │ ~ │F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│       │slp│
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
   * │     │   │   │   │   │   │   │   │   │   │   │rv-│rv+│RGBtg│blt│
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
   * │      │   │   │   │   │   │   │   │   │   │rh-│rh+│ RGBmod │bl+│
   * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
   * │        │   │   │   │   │   │   │   │   │rs+│rs-│ Play │VUp│bl-│
   * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
   * │Rset│    │    │                        │_ML│   │_BL│Prv│VDn│Nxt│
   * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
   */

   /* 5: Windows Fn layer - DVORAK */
  [_BFLD] = LAYOUT_65_ansi(
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_SLEP, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_VAD, RGB_VAI, RGB_TOG, BL_TOGG, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_HUD, RGB_HUI,          RGB_MOD, BL_INC,  \
    KC_CSE ,          _______, _______, _______, _______, _______, _______, _______, _______, RGB_SAD, RGB_SAI, KC_MPLY, KC_VOLU, BL_DEC,  \
    RESET  , _______, KC_CAD ,                   _______,                            TO(_ML), _______, TO(_BL), KC_MPRV, KC_VOLD, KC_MNXT  \
  ),



  /* 2: Mac layer
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
   * │ ~ │1 !│2 @│3 #│4 $│5 %│6 ^│7 &│8 *│9 (│0 )│- _│= +│Bksp   │Del│
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
   * │Tab  │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │[ {│] }│\ |  │Ins│
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
   * │ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │; :│' "│Enter   │PUp│
   * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
   * │Shift   │ Z │ X │ C │ V │ B │ N │ M │, <│. >│/ ?│Shift │Up │PDn│
   * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
   * │Ctrl│Alt │GUI │Space                   │Alt│Fn │Ctl│Lft│Dwn│Rgt│
   * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
   */

  /* 2: Mac layer */
  [_ML] = LAYOUT_65_ansi(
    KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,  \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC, KC_RBRC, KC_BSLS, KC_INS,  \
    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,          KC_ENT,  KC_PGUP, \
    KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH, KC_RSFT, KC_UP,   KC_PGDN, \
    KC_LCTL, KC_LALT, KC_LGUI,                    KC_SPC,                            KC_RALT, MO(_MFL), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT \
  ),


  /* 3: Mac Fn layer
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
   * │Esc│F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│Cmd+Del│Slp│
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
   * │     │   │   │   │   │   │   │   │   │   │   │rv-│rv+│RGBtg│blt│
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
   * │      │   │   │   │   │   │   │   │   │   │rh-│rh+│ RGBmod │bl+│
   * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
   * │        │   │   │   │   │   │   │   │   │rs+│rs-│ Play │VUp│bl-│
   * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
   * │Rset│    │    │                        │_ML│   │_BL│Prv│VDn│Nxt│
   * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
   */

   /* 3: Mac Fn layer */
  [_MFL] = LAYOUT_65_ansi(
    KC_GRV , KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,  KC_F12,  G(KC_BSPC), KC_MAC_SLEEP, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, RGB_VAD, RGB_VAI, RGB_TOG,    BL_TOGG, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  RGB_HUD, RGB_HUI,          RGB_MOD,    BL_INC , \
    _______,          _______, _______, _______, _______, _______, _______, _______, _______,  RGB_SAD, RGB_SAI, KC_MPLY, KC_VOLU,    BL_DEC , \
    RESET  , _______, _______,                   _______,                            TO(_MLD), _______, TO(_BL), KC_MPRV, KC_VOLD,    KC_MNXT  \
  ),

  /* 6: Mac layer - DVORAK
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
   * │GE │1 !│2 @│3 #│4 $│5 %│6 ^│7 &│8 *│9 (│0 )│[ {│] }│Bksp   │Del│
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
   * │Tab  │' "│, <│. >│ P │ Y │ F │ G │ C │ R │ L │/ ?│= +│\ |  │Ins│
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
   * │ Caps │ A │ O │ E │ U │ I │ D │ H │ T │ N │ S │- _│Enter   │PUp│
   * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
   * │Shift   │; :│ Q │ J │ K │ X │ B │ M │ W │ V │ Z │Shift │Up │PDn│
   * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
   * │Ctrl│Alt │GUI │Space                   │Alt│Fn │Ctl│Lft│Dwn│Rgt│
   * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
   */

  /* 6: Mac layer - DVORAK */
  [_MLD] = LAYOUT_65_ansi(
    KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,      KC_LBRC, KC_RBRC, KC_BSPC, KC_DEL,  \
    KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,      KC_SLSH, KC_EQL,  KC_BSLS, KC_INS , \
    KC_CAPS, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,      KC_MINS,          KC_ENT,  KC_PGUP, \
    KC_LSFT,          KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,      KC_Z,    KC_RSFT, KC_UP,   KC_PGDN, \
    KC_LCTL, KC_LALT, KC_LGUI,                   KC_SPC,                             KC_RALT, MO(_MFLD), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT  \
  ),


  /* 7: Mac fn layer - DVORAK
   * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
   * │ ~ │F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│       │Slp│
   * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
   * │     │   │   │   │   │   │   │   │   │   │   │rv-│rv+│RGBtg│blt│
   * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
   * │      │   │   │   │   │   │   │   │   │   │rh-│rh+│ RGBmod │bl+│
   * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
   * │        │   │   │   │   │   │   │   │   │rs+│rs-│ Play │VUp│bl-│
   * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
   * │Rset│    │    │                        │_ML│   │_BL│Prv│VDn│Nxt│
   * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
   */

   /* 7: Mac fn layer - DVORAK */
  [_MFLD] = LAYOUT_65_ansi(
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_MAC_SLEEP, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_VAD, RGB_VAI, RGB_TOG, BL_TOGG, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_HUD, RGB_HUI,          RGB_MOD, BL_INC , \
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, RGB_SAD, RGB_SAI, KC_MPLY, KC_VOLU, BL_DEC , \
    RESET  , _______, _______,                   _______,                            TO(_ML), _______, TO(_BL), KC_MPRV, KC_VOLD, KC_MNXT  \
  ),
};
