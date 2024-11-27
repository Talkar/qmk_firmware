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
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    WIN_FN,
    TEST_1
};

enum custom_keycodes {
    TUB_1 = SAFE_RANGE,
    TUB_2
};

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

// The number of per-key LEDs on each side of a 5-column Corne.
#define NUM_LEDS_PER_SIDE 43

// keyboards/crkbd/rev1/rev1.c has a hard-coded g_led_config with 27 LEDs, so we
// have to work around this.
#define NUM_LEDS_PER_SIDE_ON_NORMAL_CORNE 43

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_92_iso(
        KC_MUTE,  KC_ESC,   KC_BRID,  KC_BRIU,  KC_MCTL,  KC_LPAD,  RGB_VAD,   RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  KC_INS,   KC_DEL,   KC_MUTE,
        _______,  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,   KC_BSPC,            KC_PGUP,
        _______,  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,    KC_RBRC,                      KC_PGDN,
        _______,  KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,    KC_NUHS,  KC_ENT,             KC_HOME,
        _______,  KC_LSFT,  KC_NUBS,  KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,  KC_UP,
        _______,  KC_LCTL,  KC_LOPT,  KC_LCMD,  MO(MAC_FN),         KC_SPC,                        KC_SPC,             KC_RCMD,  MO(MAC_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [MAC_FN] = LAYOUT_92_iso(
        RGB_TOG,  _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   _______,  _______,  RGB_TOG,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,   _______,  _______,  _______,  _______,  _______,  _______,    _______,                      _______,
        _______,  _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,   _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,  _______,
        _______,  _______,  _______,  _______,  _______,            _______,                       _______,            _______,  _______,    _______,  _______,  _______,  _______),

    [WIN_BASE] = LAYOUT_92_iso(
        QK_BOOT,  KC_CAPS,  KC_F1,      KC_F2,    KC_F3,   KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   KC_INS,   KC_DEL,   QK_BOOT,
        _______,  KC_GRV,   KC_1,       KC_2,     KC_3,    KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,   KC_BSPC,            KC_PGUP,
        _______,  KC_TAB,   KC_Q,       KC_W,     KC_E,    KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,    KC_RBRC,                      KC_PGDN,
        _______,  KC_ESC,   KC_A,       KC_S,     KC_D,    KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,    KC_NUHS,  KC_ENT,             KC_HOME,
        _______,  KC_LSFT,  KC_NUBS,    KC_Z,     KC_X,    KC_C,     KC_V,      KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,  KC_UP,
        _______,  KC_LCTL,  MO(WIN_FN), KC_LWIN,  KC_LALT,           MT(MOD_LSFT, KC_SPC),          LT(TEST_1, KC_SPC), KC_RALT,  MO(WIN_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [WIN_FN] = LAYOUT_92_iso(
        RGB_TOG,  _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RGB_VAD,   RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  _______,  _______,  RGB_TOG,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,   _______,  _______,  _______,  _______,  _______,  _______,    _______,                      _______,
        _______,  _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,   _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,  _______,
        _______,  _______,  _______,  _______,  _______,            _______,                       _______,            _______,  _______,    _______,  _______,  _______,  _______),

    [TEST_1] = LAYOUT_92_iso(
        QK_BOOT,  _______,  _______,     _______,     _______,     _______,     _______,      _______,     _______,     _______,     _______,     _______,     _______,          _______,       _______,  _______,  QK_BOOT,
        _______,  _______,  LSFT(KC_1),  LSFT(KC_2),  LSFT(KC_3),  LSFT(KC_4),  LSFT(KC_5),   LSFT(KC_6),  KC_7,        KC_8,        KC_9,        LSFT(KC_0),  LSFT(KC_MINS),    LSFT(KC_EQL),  _______,            _______,
        _______,  _______,  TUB_1,       TUB_2,       KC_UP,       _______,     _______,      KC_4,        KC_5,        KC_6,        _______,     _______,     _______,          _______,                           _______,
        _______,  _______,  _______,     KC_LEFT,     KC_DOWN,     KC_RGHT,     _______,      KC_1,        KC_2,        KC_3,        _______,     _______,     _______,          _______,       _______,            _______,
        _______,  _______,  _______,     _______,     _______,     _______,     _______,      _______,     KC_0,        _______,     _______,     _______,     _______,          _______,       _______,
        _______,  _______,  _______,     _______,     _______,                  _______,                                _______,                  _______,     _______,          _______,       _______,  _______,  _______),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [MAC_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [MAC_FN]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI), ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [WIN_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [WIN_FN]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI), ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [TEST_1]   = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) }
};
#endif // ENCODER_MAP_ENABLE

// This is a thin wrapper around rgb_matrix_set_color which allows you to put
// the same firmware on both halves of the keyboard (other than a #define for
// `MASTER_LEFT` or `MASTER_RIGHT`) and still have the correct LEDs light up
// regardless of which half has the USB cable in it.
//
// This complexity behind this logic is explained in the comments within the
// function itself.
void set_color_split(uint8_t key_code, uint8_t r, uint8_t g, uint8_t b) {
    // When using defines for MASTER_LEFT and MASTER_RIGHT, is_keyboard_left()
    // will be inaccurate. For example, (is_keyboard_left() &&
    // !is_keyboard_master()) can NEVER be true.
    //
    // See https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
    // for other ways to set handedness. If you use something other than the
    // #defines, then you can just set `is_left` to `is_keyboard_left()`.
#ifdef MASTER_LEFT
    bool is_left = true;
#endif
#ifdef MASTER_RIGHT
    bool is_left = false;
#endif

    bool left_is_master = (is_keyboard_master() && is_left) || (!is_keyboard_master() && !is_left);

    // Note on constants: 23 is the number of LEDs on each side (24) minus 1.
    // 27 is the number of LEDs that the Corne normally has with six columns.

    // Rule #1: you must set the LED based on what the master's range is. So if
    // the USB cable is in the left half, then the range is 0-23, otherwise it's
    // 27-50.

#ifdef CONSOLE_ENABLE
    uprintf("led index: %u, is_left: %u, is_keyboard_left: %u\n", key_code, is_left, is_keyboard_left());
#endif

    // Rule #1
    if (left_is_master && key_code >= NUM_LEDS_PER_SIDE)
        key_code += NUM_LEDS_PER_SIDE_ON_NORMAL_CORNE;
    else if (!left_is_master && key_code < NUM_LEDS_PER_SIDE)
        key_code -= NUM_LEDS_PER_SIDE_ON_NORMAL_CORNE;
    rgb_matrix_set_color(key_code, r, g, b);
}

bool rgb_matrix_indicators_user(void) {
	    switch(get_highest_layer(layer_state|default_layer_state)) {
		    case WIN_BASE:
                rgb_matrix_set_color_all(0,255,0);
                break;
            case TEST_1:
                rgb_matrix_set_color_all(255,0,0);
                set_color_split(17,255,0,255); // Q
                set_color_split(18,255,0,255); // W
                set_color_split(51,0,0,255); // 7
                set_color_split(52,0,0,255); // 8
                set_color_split(53,0,0,255); // 9
                set_color_split(59,0,0,255); // Y
                set_color_split(60,0,0,255); // U
                set_color_split(61,0,0,255); // I
                set_color_split(67,0,0,255); // H
                set_color_split(68,0,0,255); // J
                set_color_split(69,0,0,255); // K
                set_color_split(76,0,0,255); // N
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
        case TUB_1: if(record->event.pressed == false){ tap_with_altgr(KC_7); } return false;
        case TUB_2: if(record->event.pressed == false){ tap_with_altgr(KC_0); } return false;
    }
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
  return true;
return true;
}
