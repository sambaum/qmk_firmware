#include QMK_KEYBOARD_H
#include "sambaum.h"
#include "keymap_german_ch.h"
#include "sendstring_german_ch.h"

#include "drivers/issi/is31fl3733.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_65_ansi(
        KC_GESC,             KC_1,    KC_2,     KC_3,    MA_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    MA_MINS, MA_EQL,  KC_BSPC, KC_DEL,
        LT(_TABFN, KC_TAB),  LT_Q,    LT_W,     KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    MA_LBRC, KC_RBRC, MA_BSLS, KC_PSCR,
        KC_LCTL,             KC_A,    KC_S,     KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    MA_SCLN, MA_QUOT,          MA_ENT,  KC_PGUP,
        KC_LSFT,             LT_Z,    KC_X,     KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_PGDN,
        LCTL_T(KC_CAPS),     KC_LGUI, KC_LALT,                             LT(_SPACEFN, KC_SPC),      KC_RALT, MO(_FN), MO(_SFN),KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_SPACEFN] = LAYOUT_65_ansi(
        _______,             KC_F1,   KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12 , _______, KC_MUTE,
        KC_PGDN,             LCA_PAU, _______,  ALTPGUP, KC_BTN2, _______, _______, KC_HOME, KC_UP  , KC_END , _______, KC_LBRC, _______, TG(_NUM),KC_INS,
        _______,             _______, PREVTAB,  ALTPGDN, NEXTTAB, _______, KC_PGUP, KC_LEFT, KC_DOWN, KC_RGHT, KC_SCLN, KC_QUOT,          _______, KC_HOME,
        _______,                      _______,  _______, _______, CLIPT,   KC_SPC,  KC_PGDN, KC_BTN3, _______, _______, _______, _______, KC_VOLU, KC_END,
        _______,             _______, _______,                             _______,                   _______, _______, _______, _______, KC_VOLD, KC_MPLY
    ),

    [_TABFN] = LAYOUT_65_ansi(
        LOCK,                KC_SLEP, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,             _______, _______,  _______, _______, _______, _______, EN_U,    KC_UP  , EN_O,    EN_P,    _______, _______, _______, _______,
        _______,             _______, _______,  _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,          _______, _______,
        _______,                      _______,  _______, _______, AHKTYPE, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,             _______, _______,                             _______,                   _______, _______, _______, _______, _______, _______
    ),

    [_FN] = LAYOUT_65_ansi(
        RESET,               _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_SLCK,
        _______,             _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_NLCK,
        _______,             _______, _______,  _______, S1_DEC,  S1_INC,  S2_DEC,  S2_INC,  _______, _______, _______, _______,          _______, KC_PAUS,
        _______,                      EF_DEC,  EF_INC,   H1_DEC,  H1_INC,  H2_DEC,  H2_INC,  BR_DEC,  BR_INC,  ES_DEC,  ES_INC,  _______, _______, TG(_GAMING),
        _______,             _______, _______,                             _______,                   _______, _______, _______, _______, _______, _______
    ),

    [_NUMPAD] = LAYOUT_65_ansi(
        TG(_NUM),            XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,
        _______,             XXXXXXX, MO(_SCR), XXXXXXX, XXXXXXX, XXXXXXX, DIVIDE,  KC_7,    KC_8,    KC_9,    MINUS,   XXXXXXX, XXXXXXX, TG(_NUM),_______,
        _______,             XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, MULPLY,  KC_4,    KC_5,    KC_6,    PLUS,    COLON,            _______, _______,
        _______,                      XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_1,    KC_2,    KC_3,    KC_DOT,  _______, _______, _______,
        _______,             _______, KC_SPC,                              KC_0,                      _______, _______, _______, _______, _______, _______
    ),

    [_SPECCHAR] = LAYOUT_65_ansi(
        TG(_NUM),            XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,
        _______,             XXXXXXX, _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, S(KC_7), S(KC_8), S(KC_9), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        _______,             XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, S(KC_4), S(KC_5), S(KC_6), XXXXXXX, XXXXXXX,          _______, _______,
        _______,                      XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, S(KC_1), S(KC_2), S(KC_3), XXXXXXX, _______, _______, _______,
        _______,             _______, XXXXXXX,                             S(KC_0),                   _______, _______, _______, _______, _______, _______
    ),

    [_BRACKETS] = LAYOUT_65_ansi(
        _______,             XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,
        _______,             XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LSBR,    RSBR,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        _______,             XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LCBR,    RCBR,    XXXXXXX, XXXXXXX, XXXXXXX,          _______, _______,
        _______,                      XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LABK,    RABK,    XXXXXXX, XXXXXXX, _______, _______, _______,
        _______,             _______, _______,                             XXXXXXX,                   _______, _______, _______, _______, _______, _______
    ),

    [_GAMING] = LAYOUT_65_ansi(
        _______,             _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        KC_TAB,              KC_Q,    _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        KC_LCTL,             KC_A,    _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        KC_LSFT,                      _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,             _______, _______,                             _______,                   _______, _______, _______, _______, _______, _______
    )

};

///////////////////// LED BEGIN /////////////////////
/*
    {  1-1,  5-1,  9-1, 13-1, 17-1, 21-1, 25-1, 29-1, 33-1, 37-1, 41-1, 45-1, 49-1, 53-1, 1+64-1 },
    {  2-1,  6-1, 10-1, 14-1, 18-1, 22-1, 26-1, 30-1, 34-1, 38-1, 42-1, 46-1, 50-1,  255, 2+64-1 },
    {  3-1,  7-1, 11-1, 15-1, 19-1, 23-1, 27-1, 31-1, 35-1, 39-1, 43-1, 47-1, 54-1, 55-1, 5+64-1 },
    {  4-1,  255,  8-1, 12-1, 16-1, 20-1, 24-1, 28-1, 32-1, 36-1, 40-1, 44-1, 51-1, 52-1, 3+64-1 },
    { 57-1, 58-1, 59-1,  255,  255,  255, 60-1,  255,  255, 48-1, 62-1, 63-1, 64-1, 56-1, 4+64-1 }
*/



///////////////////// LED END /////////////////////

