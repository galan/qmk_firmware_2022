#include QMK_KEYBOARD_H
#include "keymap_german.h"

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

#define I______ KC_NO    // N/A

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

/*
KC_QUOT = ",
KC_GRV = ~.
KC_BSLS = |\
KC_SCLN = :;
KC_SLSH = ?/
KC_COMM = <,
KC_DOT = >.
DE_DOT = .:
KC_TILD = °
DE_CIRC = ^°
KC_EXLM = !
KC_AT = "
KC_EQL
KC_LCBR
KC_LPRN

`'|#'*+ ~ \ {}[]() € µ @ PRINT DRUCK ROLLEN PAUSE
VOL+ VOL- MUTE PAUSE PREV NEXT

EINF ENTF POS1 ENDE PG_UP PG_DOWN
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  DE_1,    DE_2,    DE_3,    DE_4,    DE_5,                               DE_6,    DE_7,    DE_8,    DE_9,    DE_0,    KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, DE_Q,    DE_W,    DE_E,    DE_R,    DE_T,                               DE_Z ,   DE_U,    DE_I,    DE_O,    DE_P,    DE_DOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, DE_A,    DE_S,    DE_D,    DE_F,    DE_G,                               DE_H,    DE_J,    DE_K,    DE_L,    DE_UE,   KC_LGUI,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LGUI, DE_Y,    DE_X,    DE_C,    DE_V,    DE_B,    KC_LALT,          KC_DEL,  DE_N,    DE_M,    DE_OE,   DE_AE,   DE_SS,   KC_LALT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    LOWER,   KC_LCTL, KC_TAB,                    KC_ENT,  KC_SPC,  RAISE
  //                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, DE_AT,   DE_DEG,  DE_EURO, DE_CIRC, DE_MICR,                            DE_SLSH, KC_7,    KC_8,    KC_9,    DE_MINS, DE_COMM,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, DE_GRV,  DE_SS,   DE_UNDS, DE_HASH, DE_TILD,                            DE_ASTR, KC_4,    KC_5,    KC_6,    DE_PLUS, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, DE_ACUT, KC_LCTL, DE_PIPE, DE_QUES, DE_EXLM, KC_RALT,          _______, KC_0,    KC_1,    KC_2,    KC_3,    KC_DEL,  _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, KC_0
  //                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_VOLU, KC_END,  KC_UP,   KC_HOME, KC_PGUP,                            DE_LCBR, DE_RCBR, DE_LABK, DE_RABK, KC_PAUS, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_VOLD, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                            DE_LPRN, DE_RPRN, DE_SLSH, DE_BSLS, KC_PSCR, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_INS,  KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_RALT,          _______, DE_LBRC, DE_RBRC, DE_SUP2, DE_SUP3, KC_SLCK, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
  //                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     I______, I______, I______, I______, I______, I______,                            I______, I______, I______, I______, I______, RESET,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     I______, I______, I______, I______, I______, I______,                            I______, I______, RGB_VAI, RGB_SAI, RGB_HUI, RGB_TOG,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     I______, I______, I______, I______, I______, I______,                            I______, I______, RGB_VAD, RGB_SAD, RGB_HUD, RGB_MOD,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     I______, I______, I______, I______, I______, I______, I______,          I______, I______, I______, I______, I______, I______, KC_X,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    I______, I______, I______,                   I______, _______, I______
  //                               └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
}
