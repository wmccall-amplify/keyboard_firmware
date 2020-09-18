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

#define DEFAULT_RGB_MODE 13

#define DEFAULT_CAPS_MODE 5
#define DEFAULT_CAPS_HUE 12
#define DEFAULT_CAPS_SAT 255
#define DEFAULT_CAPS_VAL 255
#define DEFAULT_CAPS_HSV DEFAULT_CAPS_HUE, DEFAULT_CAPS_SAT, DEFAULT_CAPS_VAL

// rgblight_setrgb_range(r, g, b, start, end)
uint32_t desired_mode = 13;

uint32_t desired_hue = 160;
uint32_t desired_saturation = 100;
uint32_t desired_value = 100;

uint32_t rgb_tog_value = 100;

bool hue_up = false;
bool hue_down = false;
bool val_up = false;
bool val_down = false;
bool sat_up = false;
bool sat_down = false;

uint32_t clock_step = 0;

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  QMKURL,
  CUS_VAI,
  CUS_VAD,
  CUS_HUI,
  CUS_HUD,
  CUS_SAI,
  CUS_SAD,
  CUS_TOG,
  CUS_MOD,
  CUS_RMOD
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
   * |RESET |   |   |   |   |   |   |   |   |   |rh-|rh+| RGBmod |rmod|
   * |----------------------------------------------------------------|
   * |        |   |   |   |   |   |   |   |   │rs-│rs+│pl/pse|vup|mute|
   * |----------------------------------------------------------------|
   * |TMgr|    | CAD|                       |_ML|   |_BL |prv|vdn| nxt|
   * `----------------------------------------------------------------'
   */
[_BFL] = LAYOUT_65_ansi(
   KC_GRV,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9, KC_F10, KC_F11, KC_F12,_______,KC_SLEP, \
  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,CUS_VAD, CUS_VAI, CUS_TOG,_______, \
  RESET  ,_______,_______,_______,_______,_______,_______,_______,_______,_______,CUS_HUD,CUS_HUI,          RGB_MOD,RGB_RMOD, \
  _______,_______,_______,_______,_______,_______,_______,_______,_______,CUS_SAD,CUS_SAI,KC_MPLY, KC_VOLU,KC_MUTE, \
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
   * |RESET |   |   |   |   |   |   |   |   |   |rh-|rh+| RGBmod |rmod|
   * |----------------------------------------------------------------|
   * |        |   |   |   |   |   |   |   |   │rs-│rs+│pl/pse|vup|mute|
   * |----------------------------------------------------------------|
   * |    |    |    |                       |_ML|   |_BL |prv|vdn| nxt|
   * `----------------------------------------------------------------'
   */
[_MFL] = LAYOUT_65_ansi(
   KC_GRV,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9, KC_F10, KC_F11, KC_F12,G(KC_BSPC),KC_PWR, \
  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,CUS_VAD, CUS_VAI, CUS_TOG,_______, \
  RESET  ,_______,_______,_______,_______,_______,_______,_______,_______,_______,CUS_HUD,CUS_HUI,          RGB_MOD,RGB_RMOD, \
  _______,_______,_______,_______,_______,_______,_______,_______,_______,CUS_SAD,CUS_SAI,KC_MPLY, KC_VOLU,KC_MUTE, \
  _______,_______,_______,                 _______,               TO(_ML),_______,TO(_BL),KC_MPRV, KC_VOLD, KC_MNXT),
};

void save_cur_hsv(void){
  desired_hue = rgblight_get_hue();
  desired_saturation = rgblight_get_sat();
  desired_value = rgblight_get_val();
}

void update_lights(void){
  if(caps_is_active){
    desired_mode = rgblight_get_mode();
    save_cur_hsv();
    rgblight_mode(DEFAULT_CAPS_MODE);
    rgblight_sethsv(DEFAULT_CAPS_HSV);
  }else{
    rgblight_mode(desired_mode);
    rgblight_sethsv(desired_hue, desired_saturation, desired_value);
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
    // short new_mod = 0;
    switch (keycode) {
      case CUS_HUI:
        hue_up = record->event.pressed;
        break;
      case CUS_HUD:
        hue_down = record->event.pressed;
        break;
      case CUS_VAI:
        val_up = record->event.pressed;
        break;
      case CUS_VAD:
        val_down = record->event.pressed;
        break;
      case CUS_SAI:
        sat_up = record->event.pressed;
        break;
      case CUS_SAD:
        sat_down = record->event.pressed;
        break;
      case CUS_TOG:
        if(record->event.pressed){
          short cur_val = rgblight_get_val();
          if(cur_val == 0){
            rgblight_sethsv(rgblight_get_hue(), rgblight_get_sat(), rgb_tog_value);
          }else{
            rgb_tog_value = cur_val;
            rgblight_sethsv(rgblight_get_hue(), rgblight_get_sat(), 0);
          }
        }
    }
    return true;
}

void matrix_init_user(void) {
  set_caps();
  update_lights();
}

void matrix_scan_user(void) {
  clock_step = (clock_step + 1)%50;
  if(set_caps()){
    update_lights();
  }
  short new_hue = rgblight_get_hue();
  short new_val = rgblight_get_val();
  short new_sat = rgblight_get_sat();
  short delta = 3;
  if(clock_step == 0){
    if(hue_up){
      new_hue += 1;
    }
    if(hue_down){
      new_hue -= 1;
    }
    if(val_up){
      new_val += delta;
      if (new_val >= RGBLIGHT_LIMIT_VAL) new_val = RGBLIGHT_LIMIT_VAL;
    }
    if(val_down){
      new_val -= delta;
      if (new_val <= 0) new_val = 0;
    }
    if(sat_up){
      new_sat += delta;
      if (new_sat >= 255) new_sat = 255;
    }
    if(sat_down){
      new_sat -= delta;
      if (new_sat <= 0) new_sat = 0;
    }
    rgblight_sethsv(new_hue, new_sat, new_val);
  }
}

void led_set_user(uint8_t usb_led) {

}