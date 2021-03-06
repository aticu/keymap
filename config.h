#ifndef CONFIG_USER_H
#define CONFIG_USER_H

    #include "../../config.h"

    // Use the space cadet shift with a German keyboard layout.
    #define LSPO_KEY KC_8
    #define RSPC_KEY KC_9

    // Enable n-key-rollover by default.
    #define FORCE_NKRO

    // Responsive mouse.
    #undef MOUSEKEY_DELAY
    #undef MOUSEKEY_WHEEL_DELAY
    #define MOUSEKEY_DELAY 0
    #define MOUSEKEY_WHEEL_DELAY 0

    // Configure leader key
    #define LEADER_PER_KEY_TIMING
    #define LEADER_TIMEOUT 250

    // Make the space cadet feature more accessible.
    #define DISABLE_SPACE_CADET_ROLLOVER

    // To avoid frustration.
    #define PREVENT_STUCK_MODIFIERS

    // Recommended by Ergodox EZ readme
    #ifndef QMK_KEYS_PER_SCAN
        #define QMK_KEYS_PER_SCAN 4
    #endif
#endif
