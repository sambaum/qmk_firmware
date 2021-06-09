#pragma once

#include "quantum.h"
#include "action.h"
#include "version.h"

// Custom keycodes (for macros)
enum custom_keycodes {
    ATEN = SAFE_RANGE,
    DOLLAR,
    MA_4,
    MA_ENT, // used for } on ANSI board
    MA_BSLS,
    MA_EQL,
    MA_MINS,
    MA_SCLN, // ö
    MA_QUOT, // ä
    MA_LBRC, // ü
    ALTPGUP,
    ALTPGDN,
    ALTTAB,
    NEW_SAFE_RANGE  //use "NEW_SAFE_RANGE" for keymap specific codes
};

// Layers
#define _BASE 0
#define _SPACEFN 1
#define _SFN 1
#define _TABFN 2
#define _FN 3
#define _NUMPAD 5
#define _NUM 5
#define _GAMING 6
#define _BRACKETS 7
#define _SPECCHAR 8
#define _SCR 8

// Aliases
#define EN_U S(C(KC_U)) // Enpass copy user
#define EN_O LCA(KC_O)  // Enpass global key
#define EN_P S(C(KC_P)) // Enpass copy password
#define CLIPT LCA(KC_V) // Left Control + Alt + V (Clipboard manager paste by typing)
#define LCA_PAU LCA(KC_PAUS) // Toggle fullscreen in RDP sessions
#define PREVTAB LCTL(KC_PGUP) // Previous tab
#define NEXTTAB LCTL(KC_PGDN) // Next tab
#define COLON LSFT(KC_DOT)
#define LOCK LGUI(KC_L) // Lock PC
#define LT_Q LT(_NUMPAD, KC_Q)
#define LT_Z LT(_BRACKETS, KC_Z)
#define LT_W LT(_SPECCHAR, KC_W)
#define AHKTYPE LCAG(KC_V)
// Numpad
#define DIVIDE LSFT(KC_7)
#define MULPLY LSFT(KC_3)
#define PLUS LSFT(KC_1)
#define MINUS KC_SLSH
// Brackets
#define LCBR RALT(KC_QUOT)
#define RCBR RALT(KC_BSLS)
#define LSBR RALT(KC_LBRC)
#define RSBR RALT(KC_RBRC)
#define LABK KC_NUBS
#define RABK LSFT(KC_NUBS)
// Windows
#define LGUI1 LGUI(KC_1)
#define LGUI2 LGUI(KC_2)
#define LGUI3 LGUI(KC_3)
#define LGUI4 LGUI(KC_4)
#define LGUI5 LGUI(KC_5)
#define LGUI6 LGUI(KC_6)
#define LGUI7 LGUI(KC_7)
#define LGUI8 LGUI(KC_8)
#define LGUI9 LGUI(KC_9)
#define VDNEW C(G(KC_D))
#define VDLEFT C(G(KC_LEFT))
#define VDRGHT C(G(KC_RGHT))
#define VDREM C(G(KC_F4))