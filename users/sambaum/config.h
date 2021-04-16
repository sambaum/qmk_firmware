
/*
 * If you press a Mod Tap key, tap another key (press and release)
 * and then release the Mod Tap key, all within the tapping term,
 * it will still register the Mod-combo
 */
#define PERMISSIVE_HOLD

// USB Suspended state
#define RGB_DISABLE_WHEN_USB_SUSPENDED true

// Used togehter with tap dance
//#define ONESHOT_TIMEOUT 275

// what is a tap and what is a hold (200 is the default)
// Default is set in the get_tapping_term function
//#define TAPPING_TERM 275

// Enables handling for per key TAPPING_TERM settings
// Note: If defined, there is a problm with LT() and PERMISSIVE_HOLD
// TAPPING_TERM_PER_KEY for LT() must be set to >=500
// The problem is described here: https://github.com/qmk/qmk_firmware/issues/8999
#define TAPPING_TERM_PER_KEY

// Required for RSFT
#define TAPPING_FORCE_HOLD_PER_KEY

// Required for ATEN macro and RDP
#define TAP_CODE_DELAY 30
