#include "sambaum.h"

////////////// Tapping Term BEGIN //////////////
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_NUBS):
            return 125;
        case LT(_TABFN, KC_TAB):
        	return 200;
        case LT(_SPACEFN, KC_SPC):
            return 350;
        default:
            return 499;
    }
}
////////////// Tapping Term END //////////////


////////////// Tapping Force Hold BEGIN //////////////
// With TAPPING_FORCE_HOLD, the second press will be interpreted as a RShift,
// allowing to use it as a modifier shortly after having used it as a tap.
// A SINGLE_HOLD will be "- + SHIFT" and not "--"
bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RSFT_T(KC_SLSH):
        case LT(_SPACEFN, KC_SPC):
            return true;
        default:
            return false;
    }
}
////////////// Tapping Force Hold END //////////////


///////////////////// Macros BEGIN /////////////////////
bool is_LALT_active = false;


__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

  case MA_4:
    if (record->event.pressed) {
      // when keycode is pressed
      if ((keyboard_report->mods & MOD_BIT (KC_LSFT))) {
        unregister_code(KC_LSFT);
        tap_code(KC_BSLS);
        register_code(KC_LSFT);
      } else if ((keyboard_report->mods & MOD_BIT (KC_RSFT))) {
        unregister_code(KC_RSFT);
        tap_code(KC_BSLS);
        register_code(KC_RSFT);
      }
      else {
        register_code(KC_4);
      }
    } else {
      // when keycode is released
      unregister_code(KC_4);
    }
    break;

	case MA_EQL:
	  if (record->event.pressed) {
		// when keycode is pressed
		if ((keyboard_report->mods & MOD_BIT (KC_RALT))) {
			tap_code(KC_EQL);
			unregister_code(KC_RALT);
			tap_code(KC_SPC);
			register_code(KC_RALT);
		} else {
			tap_code(KC_EQL);
			tap_code(KC_SPC);
		}
	} else {
		// when keycode is released
	}
	break;

	case MA_MINS:
	  if (record->event.pressed) {
		// when keycode is pressed
		if ((keyboard_report->mods & MOD_BIT (KC_RALT))) {
			tap_code(KC_MINS);
			unregister_code(KC_RALT);
			tap_code(KC_SPC);
			register_code(KC_RALT);
		} else {
			register_code(KC_MINS);
		}
	} else {
		// when keycode is released
		unregister_code(KC_MINS);
	}
	break;

  case MA_ENT:
    if (record->event.pressed) {
      if ((keyboard_report->mods & MOD_BIT (KC_RALT))) {
        register_code(KC_BSLS);
      } else {
        register_code(KC_ENT);
      }
    } else {
      unregister_code(KC_BSLS);
      unregister_code(KC_ENT);
    }
    break;

  case MA_BSLS:
    if (record->event.pressed) {
      // when keycode is pressed
      if ((keyboard_report->mods & MOD_BIT (KC_LSFT))) {
        unregister_code(KC_LSFT);
        register_code(KC_RALT);
        SEND_STRING(SS_DELAY(50)); //RDP
        tap_code(KC_NUBS);
        unregister_code(KC_RALT);
        register_code(KC_LSFT);
      } else if ((keyboard_report->mods & MOD_BIT (KC_RSFT))) {
        unregister_code(KC_RSFT);
        register_code(KC_RALT);
        SEND_STRING(SS_DELAY(50)); //RDP
        tap_code(KC_NUBS);
        unregister_code(KC_RALT);
        register_code(KC_RSFT);
      }
      else {
      register_code(KC_RALT);
      SEND_STRING(SS_DELAY(50)); //RDP
      register_code(KC_7);
      }
    } else {
      // when keycode is released
      unregister_code(KC_7);
      unregister_code(KC_RALT);
    }
    break;

  // ö
  case MA_SCLN:
    if (record->event.pressed) {
      // when keycode is pressed
      if ((keyboard_report->mods & MOD_BIT (KC_LSFT))) {
        unregister_code(KC_LSFT);
        tap_code(KC_RBRC);
        register_code(KC_LSFT);
        tap_code(KC_O);
      } else if ((keyboard_report->mods & MOD_BIT (KC_RSFT))) {
        unregister_code(KC_RSFT);
        tap_code(KC_RBRC);
        register_code(KC_RSFT);
        tap_code(KC_O);
      }
      else {
      register_code(KC_SCLN);
      }
    } else {
      // when keycode is released
      unregister_code(KC_SCLN);
    }
    break;

  // ä
  case MA_QUOT:
    if (record->event.pressed) {
      // when keycode is pressed
      if ((keyboard_report->mods & MOD_BIT (KC_LSFT))) {
        unregister_code(KC_LSFT);
        tap_code(KC_RBRC);
        register_code(KC_LSFT);
        tap_code(KC_A);
      } else if ((keyboard_report->mods & MOD_BIT (KC_RSFT))) {
        unregister_code(KC_RSFT);
        tap_code(KC_RBRC);
        register_code(KC_RSFT);
        tap_code(KC_A);
      }
      else {
      register_code(KC_QUOT);
      }
    } else {
      // when keycode is released
      unregister_code(KC_QUOT);
    }
    break;

  // ü
  case MA_LBRC:
    if (record->event.pressed) {
      // when keycode is pressed
      if ((keyboard_report->mods & MOD_BIT (KC_LSFT))) {
        unregister_code(KC_LSFT);
        tap_code(KC_RBRC);
        register_code(KC_LSFT);
        tap_code(KC_U);
      } else if ((keyboard_report->mods & MOD_BIT (KC_RSFT))) {
        unregister_code(KC_RSFT);
        tap_code(KC_RBRC);
        register_code(KC_RSFT);
        tap_code(KC_U);
      }
      else {
      register_code(KC_LBRC);
      }
    } else {
      // when keycode is released
      unregister_code(KC_LBRC);
    }
    break;

  case ATEN:
    if (record->event.pressed) {
      // when keycode is pressed
      tap_code(KC_SLCK);
      tap_code(KC_SLCK);
      tap_code(KC_ENT);
    } else {
      // when keycode is released
    }
    break;

   case ALTPGUP:
     if (record->event.pressed) {
       is_LALT_active = true;
       register_code(KC_LALT);
       SEND_STRING(SS_DELAY(50)); //RDP
       register_code(KC_PGUP);
     } else {
       unregister_code(KC_PGUP);
     }
     break;

   case ALTPGDN:
     if (record->event.pressed) {
       is_LALT_active = true;
       register_code(KC_LALT);
       SEND_STRING(SS_DELAY(50)); //RDP
       register_code(KC_PGDN);
     } else {
       unregister_code(KC_PGDN);
     }
     break;

   case ALTTAB:
     if (record->event.pressed) {
       is_LALT_active = true;
       register_code(KC_LALT);
       register_code(KC_TAB);
     } else {
       unregister_code(KC_TAB);
     }
     break;

   default:
     return true;
  }
  return true;
};

void matrix_scan_user(void) {

	uint8_t layer = biton32(layer_state);

	if (is_LALT_active) {
		if (layer == _BASE) {
			unregister_code(KC_LALT);
			is_LALT_active = false;
		}
	}

}

///////////////////// Macros END /////////////////////


///////////////////// LED BEGIN /////////////////////
//void rgb_matrix_indicators_user(void) {
//led_t led_state = host_keyboard_led_state();
//  switch (biton32(layer_state)) {
//  }
//}
///////////////////// LED END /////////////////////


////////////// SUSPENDED STATE BEGIN //////////////
//void suspend_power_down_user(void) {
//    rgb_matrix_set_suspend_state(true);
//}
//void suspend_wakeup_init_user(void) {
//    rgb_matrix_set_suspend_state(false);
//}
////////////// SUSPENDED STATE END ////////////////
