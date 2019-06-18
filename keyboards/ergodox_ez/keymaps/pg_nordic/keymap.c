#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "keymap_nordic.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   §½   |   1  |   2  |   3  |   4  |   5  | PRSC |           | Play |   6  |   7  |   8  |   9  |   0  |   +    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Caps   |   Q  |   W  |   E  |   R  |   T  |  L2  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   Å    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Del    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  | Æ/L2 | Ø/Gui  |
 * |--------+------+------+------+------+------| AltGR|           | Esc  |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |-/Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *  |Less/L1| Alt  |CtlAlt| Left | Right|                                       |  Up  | Down |   {  |   }  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       |   [  |  ]   |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | '*   |       |  "   |        |      |
 *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
 *                                 |      |ace   | ¨~^  |       | ´`|  |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        NO_HALF,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_PSCREEN,
        KC_CAPS,        KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   TG(MDIA),
        KC_DELT,        KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,        CTL_T(KC_Z),  KC_X,   KC_C,   KC_V,   KC_B,   KC_ALGR,
        LT(SYMB,NO_LESS),QK_LALT,LALT(QK_LCTL),  KC_LEFT,KC_RGHT,
                                              ALT_T(KC_APP),  KC_LGUI,
                                                              NO_APOS,
                                               KC_SPC,KC_BSPC,NO_QUOT,
        // right hand
             KC_MPLY,     KC_6,   KC_7,  KC_8,   KC_9,   KC_0,             NO_PLUS,
             TG(SYMB),    KC_Y,   KC_U,  KC_I,   KC_O,   KC_P,             NO_AM,
                          KC_H,   KC_J,  KC_K,   KC_L,   LT(MDIA, KC_SCLN),GUI_T(KC_QUOT),
             KC_ESC,KC_N,   KC_M,  KC_COMM,KC_DOT, CTL_T(KC_SLSH),   KC_RSFT,
                                  KC_UP, KC_DOWN,NO_LCBR,NO_RCBR,          KC_FN1,
             NO_LBRC,        NO_RBRC,
             NO_QUO2,
             NO_ACUT,KC_TAB, KC_ENT
    ),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   "  |   #  |   ¤  |   %  |      |           |      |   &  |   /  |   (  |   )  |   =  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  LCtrl  |   ¡  |   @  |   £  |   $  |   ½  |------|           |------|   ¥  |   {  |   [  |   ]  |   }  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift  |   '* |   <  |   >  |   \  |   *  |      |           |      |   ¨  |   ^  |   ~  |   ´  |   `  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM  |      |      | HOME | END  |                                       | PgUp | PgDn |   0  |   |  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat|      |       |Toggle|Solid |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Bright|Bright|      |       |      |ScrolD|ScrolU|
 *                                 |ness- |ness+ |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       VRSN,   KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       //KC_TRNS,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
       KC_TRNS,LSFT(KC_1),LSFT(KC_2),LSFT(KC_3),LSFT(KC_4),LSFT(KC_5),KC_TRNS,
       //KC_LCTRL,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
       KC_LCTRL,ALGR(KC_1),ALGR(KC_2),ALGR(KC_3),ALGR(KC_4),ALGR(KC_5),
       KC_LSFT,NO_APOS,NO_LESS,NO_GRTR,ALGR(NO_LESS),LSFT(NO_APOS),KC_TRNS,
          EPRM,KC_TRNS,KC_TRNS,KC_HOME,KC_END,
                                       RGB_MOD,KC_TRNS,
                                               KC_TRNS,
                               RGB_VAD,RGB_VAI,KC_SLEP,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       //KC_TRNS, KC_UP,   KC_7,   KC_8,    KC_9,    KC_ASTR, KC_F12,
       KC_TRNS,LSFT(KC_6),LSFT(KC_7),LSFT(KC_8),LSFT(KC_9),LSFT(KC_0),KC_F12,
                ALGR(KC_6),ALGR(KC_7),ALGR(KC_8),ALGR(KC_9),ALGR(KC_0),KC_TRNS,
       KC_TRNS, NO_QUOT, LSFT(NO_QUOT), ALGR(NO_QUOT), NO_ACUT, LSFT(NO_ACUT), KC_TRNS,
                         KC_PGUP,KC_PGDN,  KC_0,    ALGR(NO_ACUT),  KC_TRNS,
       RGB_TOG, RGB_SLD,
       KC_TRNS,
       KC_WAKE, KC_MS_WH_DOWN, KC_MS_WH_UP
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |ScrolL| MsUp |ScrolR|      |      |           |      |      |   7  |   8  |   9  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |   4  |   5  |   6  |      |  Play  |
 * |--------+------+------+------+------+------|      |           |Brwser|------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |Back  |      |   1  |   2  |   3  |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Prev | Next |                                       |ScrolD|ScrolU|   0  |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 | Lclk | Rclk |      |       |      |VolDn |VolUp |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       | Mute |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_WH_LEFT, KC_MS_U, KC_MS_WH_RIGHT, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_BTN1, KC_BTN2, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_7, KC_8, KC_9, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_4, KC_5, KC_6, KC_TRNS, KC_MPLY,
       KC_WBAK,  KC_TRNS, KC_1, KC_2, KC_3, KC_TRNS, KC_TRNS,
                          KC_MS_WH_UP, KC_MS_WH_DOWN, KC_0, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_MUTE, KC_VOLD, KC_VOLU
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      break;
    case 1:
      if (record->event.pressed) { // For resetting EEPROM
        eeconfig_init();
      }
      break;
  }
  return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      default:
        break;
    }

  return state;
};
