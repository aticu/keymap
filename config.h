#ifndef CONFIG_USER_H
#define CONFIG_USER_H

    #include "../../config.h"

    //Use the space cadet shift with a German keyboard layout.
    #undef LSPO_KEY
    #undef RSPC_KEY
    #define LSPO_KEY KC_8
    #define RSPC_KEY KC_9

    //Enable n-key-rollover by default.
    #define FORCE_NKRO

    //Responsive mouse.
    #undef MOUSEKEY_DELAY
    #undef MOUSEKEY_WHEEL_DELAY
    #define MOUSEKEY_DELAY 0
    #define MOUSEKEY_WHEEL_DELAY 0
#endif