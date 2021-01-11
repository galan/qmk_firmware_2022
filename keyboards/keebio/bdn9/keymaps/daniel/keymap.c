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
        | Knob 1: Vol Dn/Up |                  | Knob 2: Zoom in/out |
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
        | Knob 1: Vol Dn/Up |                  | Knob 2: Zoom in/out |
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
        |        |       |      |
        |        |       |      |
        |        |       |      |
     */
    [2] = LAYOUT(
        _______, MO(6)  , _______,
        _______, _______, _______,
        _______, _______, _______
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
        _______, _______, _______,
        _______, _______, _______
    ),

    /*
        |        |       |      |
        |        |       |      |
        |        |       |      |
     */
    [5] = LAYOUT(
        _______, MO(6)  , _______,
        _______, _______, _______,
        _______, _______, _______
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
void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == _LEFT) {
        if (clockwise) {
            tap_code(KC_VOLU);
            //rgb_matrix_set_color(0, 0xff, 0xff, 0x0ff);
        } else {
            tap_code(KC_VOLD);
            //rgb_matrix_set_color(0, 0x00, 0x00, 0x00);
        }
    }
    //else if (index == _MIDDLE) {
    //    if (clockwise) {
    //        tap_code(KC_DOWN);
    //    } else {
    //        tap_code(KC_UP);
    //    }
    //}
    else if (index == _RIGHT) {
        if (clockwise) {
            tap_code16(LCTL(KC_PPLS));
            //tap_code(KC_PGDN);
            //rgb_matrix_set_color(1, 0xff, 0xff, 0x0ff);
        } else {
            tap_code16(LCTL(KC_PMNS));
            //tap_code(KC_PGUP);
            //rgb_matrix_set_color(1, 0x00, 0x00, 0x00);
        }
    }
}

