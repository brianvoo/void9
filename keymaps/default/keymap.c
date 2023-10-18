#include QMK_KEYBOARD_H

// Tap Dance Declarations
enum tap_dances {
  ENT_5 = 0,
  ZERO_2
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* LAYER 0
 * ,-----------------------.
 * |   7   |   8   |   9   |
 * |-------+-------+-------|
 * |   4   | 5/ENT |   6   | Dbl Tap 5 for Enter
 * |-------+-------+-------|
 * | 1/FN1 |  2/0  | 3/FN2 | 1/FN1 = Hold 1 for FN1   -   2/0 = Dbl Tap 7 for 0  -  3/FN2 = Hold 3 for FN2
 * `-----------------------'
 */
[0] = LAYOUT(
  KC_7,         KC_8,         KC_9,
  KC_4,         TD(ENT_5),    KC_6,
  LT(1, KC_1),  TD(ZERO_2),   LT(2, KC_3)
),

/* FN1
 * ,-----------------------.
 * |  DEL  |   UP  |  BSPC |
 * |-------+-------+-------|
 * |  LEFT |  DOWN | RIGHT |
 * |-------+-------+-------|
 * |       |  SPC  |  ENT  |
 * `-----------------------'
 */
[1] = LAYOUT(
  KC_DEL,   KC_UP,   KC_BSPC,
  KC_LEFT,  KC_DOWN, KC_RGHT,
  KC_TRNS,  KC_SPC,  KC_ENT
),

/* FN2
 * ,-----------------------.
 * |  ESC  |   +   |  BSPC |
 * |-------+-------+-------|
 * |   -   |   *   |   /   |
 * |-------+-------+-------|
 * |   .   |   0   |       |
 * `-----------------------'
 */
[2] = LAYOUT(
  KC_ESC,   KC_PLUS, KC_BSPC,
  KC_MINS,  KC_ASTR, KC_SLSH,
  KC_DOT,   KC_0,    KC_TRNS
),

};

tap_dance_action_t tap_dance_actions[] = {
  [ENT_5] = ACTION_TAP_DANCE_DOUBLE(KC_5, KC_ENT),
  [ZERO_2] = ACTION_TAP_DANCE_DOUBLE(KC_2, KC_0)
};


void matrix_init_user(void) {
}
