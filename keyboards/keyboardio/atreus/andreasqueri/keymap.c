// Copyright (C) 2019, 2020  Keyboard.io, Inc
//
// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

#define LA_SYM  MO(SYM)
#define LA_ACT  MO(ACT)
#define CTL_TAB MT(MOD_LCTL,KC_TAB)
#define ALT_ENT MT(MOD_LALT,KC_ENT)
#define O_GUI   OSM(MOD_LGUI)
#define O_ALT   OSM(MOD_LALT)
#define O_SHFT  OSM(MOD_LSFT)
#define O_CTRL  OSM(MOD_LCTL)
#define INV_TAB S(KC_TAB)
#define BACK    A(KC_LEFT)
#define FORW    A(KC_RIGHT)
#define CUT     C(KC_X)
#define UNDO    C(KC_Z)
#define PASTE   C(KC_V)
#define COPY    C(KC_C)


enum layer_names {
  DEF,
  ACT,
  SYM,
  FUN,
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [DEF] = LAYOUT( 
		 KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
		 KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
		 KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LGUI,  KC_LGUI,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_QUOTE,
		 KC_ESC,  KC_NO,   KC_NO,   CTL_TAB, KC_LSFT, LA_ACT,   LA_SYM,   KC_SPC,  ALT_ENT, KC_NO,   KC_NO,   KC_RCTL),

  [ACT] = LAYOUT(
		 KC_ESC,  QK_REP,  BACK,    FORW,    KC_PGUP,                     KC_NO,   INV_TAB, KC_UP,   KC_TAB,  KC_NO,
		 O_GUI,   O_ALT,   O_SHFT,  O_CTRL,  KC_PGDN,                     KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL,
		 UNDO,    CUT,     COPY,    PASTE,   MOD_LGUI,KC_LGUI,  KC_LGUI,  KC_NO,   KC_HOME, KC_NO,   KC_END,  KC_NO,
		 KC_ESC,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,  KC_TRNS,  KC_ENT,  KC_NO,   KC_NO,   KC_NO,   KC_NO),
  
  [SYM] = LAYOUT(
		 KC_BSLS,  KC_1,   KC_2,    KC_3,    KC_SLSH,                     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
		 KC_LBRC,  KC_4,   KC_5,    KC_6,    KC_RBRC,                     KC_NO,   O_CTRL,  O_SHFT,  O_ALT,   O_GUI,
		 KC_GRAVE, KC_7,   KC_8,    KC_9,    KC_0,    KC_LGUI,  KC_LGUI,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
		 KC_NO,    KC_NO,  KC_NO,   KC_NO,   KC_MINUS,KC_EQUAL, KC_TRNS,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO),

  [FUN] = LAYOUT(
		 KC_F13,   KC_F1,  KC_F2,   KC_F3,   KC_F10,                      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
		 KC_F14,   KC_F4,  KC_F5,   KC_F6,   KC_F11,                      KC_NO,   O_CTRL,  O_SHFT,  O_ALT,   O_GUI,
		 KC_F15,   KC_F7,  KC_F8,   KC_F9,   KC_F12,  KC_LGUI,  KC_LGUI,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
		 KC_NO,    KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_TRNS,  KC_TRNS,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO),

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, ACT, SYM, FUN);
}
