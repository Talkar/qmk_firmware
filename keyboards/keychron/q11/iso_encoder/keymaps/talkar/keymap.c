/* Copyright 2023 @ Keychron (https://www.keychron.com)
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
#include <stdlib.h>  // For itoa()
#include "print.h"

enum layers{
    GAMING_BASE,
    GAMING_FN,
    DEV_BASE,
    DEV_FN
};

enum custom_keycodes {
    TUB_1 = SAFE_RANGE,
    TUB_2,
    SPECIAL_E
};

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

#define NUM_LEDS_ON_LEFT_SIDE 43

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [GAMING_BASE] = LAYOUT_92_iso(
        KC_MUTE,  KC_CAPS,  KC_F1,         KC_F2,    KC_F3,   KC_F4,    KC_F5,     KC_F6,                    KC_F7,    KC_F8,    KC_F9,       KC_F10,   KC_F11,     KC_F12,   KC_INS,   KC_DEL,   KC_MUTE,
        _______,  KC_GRV,   KC_1,          KC_2,     KC_3,    KC_4,     KC_5,      KC_6,                     KC_7,     KC_8,     KC_9,        KC_0,     KC_MINS,    KC_EQL,   KC_BSPC,            KC_PGUP,
        _______,  KC_TAB,   KC_Q,          KC_W,     KC_E,    KC_R,     KC_T,      KC_Y,                     KC_U,     KC_I,     KC_O,        KC_P,     KC_LBRC,    KC_RBRC,                      KC_PGDN,
        _______,  KC_ESC,   KC_A,          KC_S,     KC_D,    KC_F,     KC_G,      KC_H,                     KC_J,     KC_K,     KC_L,        KC_SCLN,  KC_QUOT,    KC_NUHS,  KC_ENT,             KC_HOME,
        _______,  KC_LSFT,  MO(GAMING_FN), KC_Z,     KC_X,    KC_C,     KC_V,      KC_B,                     KC_N,     KC_M,     KC_COMM,     KC_DOT,   KC_SLSH,              KC_RSFT,  KC_UP,
        _______,  KC_LCTL,  MO(GAMING_FN), KC_LWIN,  KC_LALT, KC_SPC,                                        LT(GAMING_FN, KC_SPC), KC_RALT,  MO(GAMING_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [GAMING_FN] = LAYOUT_92_iso(
        XXXXXXX,  XXXXXXX,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,                       KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,   XXXXXXX,  XXXXXXX,  XXXXXXX,
        XXXXXXX,  XXXXXXX,  KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,   KC_EQL,                       KC_7,     KC_8,     KC_9,     XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,  XXXXXXX,  KC_P,     KC_O,     KC_I,     KC_U,     KC_Y,      KC_4,                         KC_5,     KC_6,     XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,                      XXXXXXX,
        XXXXXXX,  KC_CAPS,  KC_SCLN,  KC_L,     KC_K,     KC_J,     KC_H,      KC_1,                         KC_2,     KC_3,     XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,            XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_SLSH,  KC_DOT,   KC_COMM,  KC_M,      KC_N,                         KC_0,     XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,              XXXXXXX,  XXXXXXX,
        XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                                                    XXXXXXX, XXXXXXX,  XXXXXXX,     XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX),

 /*    [DEV_BASE] = LAYOUT_92_iso(
        QK_BOOT,  KC_CAPS,    KC_F1,      KC_F2,    KC_F3,   KC_F4,    KC_F5,     KC_F6,                    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   KC_INS,   KC_DEL,   QK_BOOT,
        _______,  MO(DEV_FN), KC_1,       KC_2,     KC_3,    KC_4,     KC_5,      KC_6,                     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,   KC_BSPC,            KC_PGUP,
        _______,  KC_TAB,     KC_Q,       KC_W,     KC_E,    KC_R,     KC_T,      KC_Y,                     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,    KC_RBRC,                      KC_PGDN,
        _______,  KC_ESC,     KC_A,       KC_S,     KC_D,    KC_F,     KC_G,      KC_H,                     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,    KC_NUHS,  KC_ENT,             KC_HOME,
        _______,  KC_LSFT,    MO(DEV_FN), KC_Z,     KC_X,    KC_C,     KC_V,      KC_B,                     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              LSFT(KC_COMM),  KC_UP,
        _______,  KC_LCTL,    MO(DEV_FN), KC_LWIN,  KC_LALT,           KC_SPC,                                        KC_SPC, KC_RALT,  MO(DEV_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),
*/

   [DEV_BASE] = LAYOUT_92_iso(
        QK_BOOT,  KC_CAPS,    KC_F1,      KC_F2,    KC_F3,   KC_F4,    KC_F5,     KC_F6,                    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   KC_INS,   KC_DEL,   QK_BOOT,
        _______,  MO(DEV_FN), KC_1,       KC_2,     KC_3,    KC_4,     KC_5,      KC_6,                     KC_7,     KC_8,     KC_9,     KC_0,    KC_MINS,     KC_EQL,   KC_BSPC,            KC_PGUP,
        _______,  KC_TAB,     KC_Q,       KC_W,     KC_F,    KC_P,     KC_B,                                KC_J,     KC_L,     KC_U,     KC_Y,     LSFT(KC_COMM), KC_LBRC,    KC_RBRC,         KC_PGDN,
        _______,  KC_ESC,     KC_A,       KC_R,     KC_S,    KC_T,     KC_G,                                KC_M,     KC_N,     KC_E,     KC_I,  KC_O,    KC_SCLN, KC_QUOT, KC_ENT,           KC_HOME,
        _______,  KC_LSFT,    MO(DEV_FN), KC_Z,       KC_X,     KC_C,    KC_D,     KC_V,                  KC_SLSH,  KC_K,     KC_H,  KC_COMM,   KC_DOT,              LSFT(KC_COMM),  KC_UP,
        _______,  KC_LCTL,    MO(DEV_FN), KC_LWIN,  KC_LALT,           KC_SPC,                                        LT(DEV_FN, KC_SPC), KC_RALT,  MO(DEV_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [DEV_FN] = LAYOUT_92_iso(
        QK_BOOT,  _______,  KC_BRID,     KC_BRIU,       KC_MPRV,     KC_MNXT,     KC_BRID,                  KC_BRIU,     KC_MPRV,     KC_MPLY,     KC_MNXT,     KC_MUTE,     KC_VOLD,          KC_VOLU,       _______,  _______,  QK_BOOT,
        _______,  _______,  KC_7,        KC_8,          KC_9,        KC_0,        LSFT(KC_5),               LSFT(KC_6),  KC_7,        KC_8,        KC_9,        LSFT(KC_0),  LALT(KC_INS),     LSFT(KC_EQL),  _______,            _______,
        _______,  _______,  TUB_1,       TUB_2,         SPECIAL_E,   LSFT(KC_9),  _______,                  KC_PGDN,        KC_END,   KC_HOME,        KC_PGUP,     _______,     _______,          _______,                           _______,
        _______,  _______,  KC_NUBS,     LSFT(KC_NUBS), LCA(KC_NUBS),LSFT(KC_7),  _______,                  KC_LEFT,        KC_DOWN,  KC_UP,      KC_RIGHT,  _______,     _______,          _______,       _______,            _______,
        _______,  _______,  _______,     LCA(KC_8),   LCA(KC_9),     _______,     _______, _______,         _______,        _______,     _______,     _______,     _______,          _______,       _______,
        _______,  _______,  _______,     _______,       _______,                  _______,                                            _______,                  _______,     _______,          _______,       _______,  _______,  _______),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [GAMING_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [GAMING_FN]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI), ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [DEV_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [DEV_FN]   = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) }
};
#endif // ENCODER_MAP_ENABLE

void set_color_split(uint8_t key_code, uint8_t r, uint8_t g, uint8_t b) {

#ifdef MASTER_LEFT
    bool is_left = true;
#endif
#ifdef MASTER_RIGHT
    bool is_left = false;
#endif

    bool left_is_master = (is_keyboard_master() && is_left) || (!is_keyboard_master() && !is_left);

#ifdef CONSOLE_ENABLE
    uprintf("led index: %u, is_left: %u, is_keyboard_left: %u\n", key_code, is_left, is_keyboard_left());
#endif

    // Rule #1
    if (left_is_master && key_code >= NUM_LEDS_ON_LEFT_SIDE)
        key_code += NUM_LEDS_ON_LEFT_SIDE;
    else if (!left_is_master && key_code < NUM_LEDS_ON_LEFT_SIDE)
        key_code -= NUM_LEDS_ON_LEFT_SIDE;
    rgb_matrix_set_color(key_code, r, g, b);
}

bool rgb_matrix_indicators_user(void) {
	    switch(get_highest_layer(layer_state|default_layer_state)) {
            case GAMING_BASE:
                rgb_matrix_set_color_all(RGB_GREEN);
                break;
            case GAMING_FN:
		        rgb_matrix_set_color_all(RGB_BLACK);
                set_color_split(9,RGB_BLUE); // 1
                set_color_split(10,RGB_BLUE); // 2
                set_color_split(11,RGB_BLUE); // 3
                set_color_split(12,RGB_BLUE); // 4
                set_color_split(13,RGB_BLUE); // 5
                set_color_split(14,RGB_BLUE); // 6
                set_color_split(17,RGB_RED); // Q
                set_color_split(18,RGB_RED); // W
                set_color_split(19,RGB_RED); // E
                set_color_split(20,RGB_RED); // R
                set_color_split(21,RGB_RED); // T
                set_color_split(23,RGB_MAGENTA); // CAPS
                set_color_split(24,RGB_RED); // A
                set_color_split(25,RGB_RED); // S
                set_color_split(26,RGB_RED); // D
                set_color_split(27,RGB_RED); // F
                set_color_split(28,RGB_RED); // G
                set_color_split(32,RGB_RED); // Z
                set_color_split(33,RGB_RED); // X
                set_color_split(34,RGB_RED); // C
                set_color_split(35,RGB_RED); // V
                set_color_split(36,RGB_RED); // B
                set_color_split(51,RGB_BLUE); // 7
                set_color_split(52,RGB_BLUE); // 8
                set_color_split(53,RGB_BLUE); // 9
                set_color_split(59,RGB_BLUE); // Y
                set_color_split(60,RGB_BLUE); // U
                set_color_split(61,RGB_BLUE); // I
                set_color_split(67,RGB_BLUE); // H
                set_color_split(68,RGB_BLUE); // J
                set_color_split(69,RGB_BLUE); // K
                set_color_split(76,RGB_BLUE); // N

                break;
            case DEV_BASE:
                rgb_matrix_set_color_all(0,220,30);
                break;
            case DEV_FN:
                rgb_matrix_set_color_all(RGB_MAGENTA);
                set_color_split(17,RGB_CHARTREUSE); // Q
                set_color_split(18,RGB_CHARTREUSE); // W
                set_color_split(9,RGB_BLUE); // 1
                set_color_split(10,RGB_BLUE); // 2
                set_color_split(11,RGB_BLUE); // 3
                set_color_split(12,RGB_BLUE); // 4
                set_color_split(19,RGB_GREEN); // E
                set_color_split(20,RGB_GREEN); // R
                set_color_split(24,RGB_YELLOW); // A
                set_color_split(25,RGB_YELLOW); // S
                set_color_split(26,RGB_TEAL); // D
                set_color_split(27,RGB_TEAL); // F
                set_color_split(32,RGB_CHARTREUSE); // Z
                set_color_split(33,RGB_CHARTREUSE); // X
                set_color_split(51,RGB_BLUE); // 7
                set_color_split(52,RGB_BLUE); // 8
                set_color_split(53,RGB_BLUE); // 9
                set_color_split(55,RGB_YELLOW); // +
                set_color_split(59,RGB_BLUE); // Y
                set_color_split(60,RGB_BLUE); // U
                set_color_split(61,RGB_BLUE); // I
                set_color_split(67,RGB_BLUE); // H
                set_color_split(68,RGB_BLUE); // J
                set_color_split(69,RGB_BLUE); // K
                set_color_split(76,RGB_BLUE); // N
                break;
            default: //  for any other layers, or the default layer
                break;
        }
  return false;
}

bool is_pressed(uint16_t mod_keycode){
  return (get_mods() & (MOD_BIT(mod_keycode)));
}

void tap_with_altgr(uint16_t keycode)
{
    bool apply_alt = !is_pressed(KC_RALT);
    if(apply_alt){ register_code(KC_RALT); }
    tap_code(keycode);
    if(apply_alt){ unregister_code(KC_RALT); }
}

// Example keymap or user function where you want to print the indices

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TUB_1: if(record->event.pressed == false) { SEND_STRING(SS_ALGR(SS_TAP(X_7))); } return false;
        case TUB_2: if(record->event.pressed == false){ SEND_STRING(SS_ALGR(SS_TAP(X_0))); } return false;
        case SPECIAL_E:
            if(record->event.pressed ==false)
            {
                if(is_pressed(KC_LSFT))
                {
                    unregister_code(KC_LSFT);
                    tap_code(KC_ENT);
                    register_code(KC_LSFT);
                }
                else
                {
                    tap_code16(LSFT(KC_8));
                }
            }
            return false;
    }

#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
  return true;
return true;
}
