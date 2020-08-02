/* Copyright 2018 'mechmerlin'
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#define _BL 0    // Base Layer
#define _BFL 1   // Base Fn Layer
#define _ML 2    // Mac Layer
#define _MFL 3   // Mac Fn Layer

// Macro to perform ctrl + alt + del
#define KC_CAD LALT(LCTL(KC_DEL))

// Macro to perform ctrl + shift + esc
#define KC_CSE LSFT(LCTL(KC_ESC))

// Macro to sleep mac (ctrl + shift + power)
#define KC_MAC_SLEEP LSFT(LCTL(KC_PWR))

bool caps_is_active = false;
uint32_t desired = 13;

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: Base Layer (Default Layer)
   * ,----------------------------------------------------------------.
   * |Esc | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |Del |
   * |----------------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |PgUp|
   * |----------------------------------------------------------------|
   * |CAPS   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |PgDn|
   * |----------------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up| Ins|
   * |----------------------------------------------------------------|
   * |Ctrl|Win |Alt |        Space          |Alt| FN|Ctrl|Lef|Dow|Rig |
   * `----------------------------------------------------------------'
   */
[_BL] = LAYOUT_65_ansi(
  KC_GESC,    KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS, KC_EQL, KC_BSPC,KC_DEL, \
  KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC, KC_RBRC,KC_BSLS,KC_PGUP, \
  KC_CAPS, KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,         KC_ENT,KC_PGDN,  \
  KC_LSFT,         KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,   KC_RSFT,KC_UP,KC_INS, \
  KC_LCTL, KC_LGUI,KC_LALT,                KC_SPC,                        KC_RALT,MO(_BFL),KC_RCTRL, KC_LEFT,KC_DOWN,KC_RGHT),

  /* Keymap _BFL: Base Function Layer
   * ,----------------------------------------------------------------.
   * | ~ | F1|F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|       |slp |
   * |----------------------------------------------------------------|
   * |     |   |   |   |   |   |   |   |   |   |   |rv-|rv+|RGBtg|    |
   * |----------------------------------------------------------------|
   * |      |   |   |   |   |   |   |   |   |   |rh-|rh+| RGBmod |    |
   * |----------------------------------------------------------------|
   * |        |   |   |   |   |   |   |   |   │rs-│rs+│pl/pse|vup|mute|
   * |----------------------------------------------------------------|
   * |TMgr|    | CAD|                       |_ML|   |_BL |prv|vdn| nxt|
   * `----------------------------------------------------------------'
   */
[_BFL] = LAYOUT_65_ansi(
   KC_GRV,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9, KC_F10, KC_F11, KC_F12,_______,KC_SLEP, \
  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,RGB_VAD, RGB_VAI, RGB_TOG,_______, \
  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,RGB_HUD,RGB_HUI,          RGB_MOD,_______, \
  _______,_______,_______,_______,_______,_______,_______,_______,_______,RGB_SAD,RGB_SAI,KC_MPLY, KC_VOLU,KC_MUTE, \
   KC_CSE,_______, KC_CAD,                 _______,               TO(_ML),_______,TO(_BL),KC_MPRV, KC_VOLD, KC_MNXT),

/* Keymap _ML: Mac Layer
   * ,----------------------------------------------------------------.
   * |Esc | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |Del |
   * |----------------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |PgUp|
   * |----------------------------------------------------------------|
   * |CAPS   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |PgDn|
   * |----------------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up| Ins|
   * |----------------------------------------------------------------|
   * |Ctrl|Alt |Alt |        Space          |Alt| FN|Ctrl|Lef|Dow|Rig |
   * `----------------------------------------------------------------'
   */
[_ML] = LAYOUT_65_ansi(
  KC_GESC,    KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS, KC_EQL, KC_BSPC,KC_DEL, \
  KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC, KC_RBRC,KC_BSLS,KC_PGUP, \
  KC_CAPS, KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,         KC_ENT,KC_PGDN,  \
  KC_LSFT,         KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,   KC_RSFT,KC_UP,KC_INS, \
  KC_LCTL, KC_LALT,KC_LGUI,                KC_SPC,                        KC_RALT,MO(_MFL),KC_RCTRL, KC_LEFT,KC_DOWN,KC_RGHT),

  /* Keymap _MFL: Mac Function Layer
   * ,----------------------------------------------------------------.
   * | ~ | F1|F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|Cmd+Del|PWR |
   * |----------------------------------------------------------------|
   * |     |   |   |   |   |   |   |   |   |   |   |rv-|rv+|RGBtg|    |
   * |----------------------------------------------------------------|
   * |      |   |   |   |   |   |   |   |   |   |rh-|rh+| RGBmod |    |
   * |----------------------------------------------------------------|
   * |        |   |   |   |   |   |   |   |   │rs-│rs+│pl/pse|vup|mute|
   * |----------------------------------------------------------------|
   * |    |    |    |                       |_ML|   |_BL |prv|vdn| nxt|
   * `----------------------------------------------------------------'
   */
[_MFL] = LAYOUT_65_ansi(
   KC_GRV,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9, KC_F10, KC_F11, KC_F12,G(KC_BSPC),KC_PWR , \
  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,RGB_VAD, RGB_VAI, RGB_TOG,_______, \
  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,RGB_HUD,RGB_HUI,          RGB_MOD,_______, \
  _______,_______,_______,_______,_______,_______,_______,_______,_______,RGB_SAD,RGB_SAI,KC_MPLY, KC_VOLU,KC_MUTE, \
  _______,_______,_______,                 _______,               TO(_ML),_______,TO(_BL),KC_MPRV, KC_VOLD, KC_MNXT),
};

void update_lights(void){
  if(caps_is_active){
    if(rgblight_get_mode() == 1){
      desired = 13;
    }else{
      desired = rgblight_get_mode();
    }
    rgblight_mode(1);
  }else{
    rgblight_mode(desired);
  }
}

bool set_caps(void){
  bool is_different = false;
  if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) {
    if(!caps_is_active){
      is_different = true;
    }
    caps_is_active = true;
  } else {
    if(caps_is_active){
      is_different = true;
    }
    caps_is_active = false;
  }
  return is_different;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case KC_CAPS:
        if (record->event.pressed) {
            // caps_is_active = !caps_is_active;
            // update_lights();
        }
        break;
    }
    return true;
};

void matrix_init_user(void) {
  // rgblight_mode(desired);
  set_caps();
  update_lights();
}

void matrix_scan_user(void) {
  if(set_caps()){
    update_lights();
  }
}

void led_set_user(uint8_t usb_led) {

}
