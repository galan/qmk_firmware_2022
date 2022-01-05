/* Copyright 2019 Danny Nguyen <danny@keeb.io>
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

enum encoder_names {
  _LEFT,
  _RIGHT,
  //_MIDDLE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
        | Knob 1: Vol Dn/Up | MOD              | Knob 2: Zoom in/out |
        | Press: Mute       | Layer select     | Press: Zoom reset   |
        | Left              | Space            | Right               |
        | Media Previous    | Media Play/Pause | Media Next          |
     */
    [0] = LAYOUT(
        KC_MUTE, MO(6),   LCTL(KC_P0),
        KC_LEFT, KC_SPC,  KC_RGHT,
        KC_MPRV, KC_MPLY, KC_MNXT
    ),

    /*
        | Knob 1: Vol Dn/Up | MOD              | Knob 2: Zoom in/out |
        | Press: Mute       | Layer select     | Press: Zoom reset   |
        | 3                 | 6                | 8                   |
        | Media Previous    | 0                | Media Next          |
     */
    [1] = LAYOUT(
        KC_MUTE, MO(6)  , LCTL(KC_P0),
        KC_3,    KC_6,    KC_8,
        KC_MPRV, KC_0,    KC_MNXT
    ),

    /*
        |                     | MOD          |                 |
        | Toggle mark as read | Prev article | Close select    |
        | Read Later (flag)   | Next article | Open in new tab |
     */
    [2] = LAYOUT(
        _______, MO(6)  , _______,
        KC_M   , KC_K   , KC_O,
        KC_S   , KC_J   , KC_V
    ),

    /*
        |        |       |      |
        |        |       |      |
        |        |       |      |
     */
    [3] = LAYOUT(
        _______, MO(6)  , _______,
        _______, _______, _______,
        _______, _______, _______
    ),

    /*
        |        |       |      |
        |        |       |      |
        |        |       |      |
     */
    [4] = LAYOUT(
        _______, MO(6)  , _______,
        KC_SPC,  KC_UP,   KC_ENT,
        KC_LEFT, KC_DOWN, KC_RGHT
    ),

    /*
        | RGB Hue       |         | RGB Saturation |
        | RGB Mode Next | Val Inc | Speed Inc      |
        | RGB Mode Prev | Val Dev | Speed Dec      |
     */
    [5] = LAYOUT(
        _______, MO(6)  , _______,
        RGB_MOD, RGB_VAI, RGB_SPI,
        RGB_RMOD,RGB_VAD, RGB_SPD
    ),

    /*
        |        |       |      |
        |        |       |      |
        |        |       |      |
     */
    [6] = LAYOUT(
        _______, _______, _______,
        DF(3)  , DF(4)  , DF(5)  ,
        DF(0)  , DF(1)  , DF(2)
    ),

};

// https://www.reddit.com/r/olkb/comments/bauj0t/can_you_change_encoders_output_using_layers_qmk/
// Also: "get_highest_layer(layer_state | default_layer_state) to match the behavior of the normal keymap lookup"
// https://discord.com/channels/440868230475677696/473506116718952450/858264227861233664
// https://discord.com/channels/440868230475677696/473506116718952450/858277319499317269
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == _LEFT) {
        if (get_highest_layer(default_layer_state) == 5) {
            if (clockwise) {
                rgblight_increase_hue();
            } else {
                rgblight_decrease_hue();
            }
        } else {
            // Volume up/down (mute/unmute on press)
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
        }
    }

    else if (index == _RIGHT) {
        if (get_highest_layer(default_layer_state) == 5) {
            if (clockwise) {
                rgblight_increase_sat();
            } else {
                rgblight_decrease_sat();
            }
        } else {
            // Zoom in/out for most applications (reset on press)
            if (clockwise) {
                tap_code16(LCTL(KC_PPLS));
            } else {
                tap_code16(LCTL(KC_PMNS));
            }
        }
    }
    return true;
}

