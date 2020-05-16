#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "keymap_german.h"
#include "keymap_plover.h"
#include <util/atomic.h>
#include <sendstring_german.h>

#define TAP_TIME 100

// *** Define layers ***
#define BASE 0 // Default layer
#define SYMB 1 // Symbols
#define GAME 2 // Gaming and media keys
#define PLVR 3 // Stenography using plover

// *** Define macro keys ***
enum custom_keycodes {
    COPYPASTE = SAFE_RANGE,
    STENO,
    CLOSE,
    UNDOREDO,
    ARROW,
    EQARROW,
    GAME_U,
    GAME_D,
    GAME_L,
    GAME_R,
    GAME_TG
};

// *** Define key aliases ***
#define LR_SYMB KC_FN1 // Switch to the symbol layer
#define LR_GAME KC_FN2 // Switch to the gaming layer

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | ~L2    |   1  |   2  |   3  |   4  |   5  | Del  |           | U/R  |   6  |   7  |   8  |   9  |   0  |   ß    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | ~L1    |   Q  |   W  |   E  |   R  |   T  |  "   |           |  +   |   Z  |   U  |   I  |   O  |   P  |   Ü    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   Ö  |   Ä    |
 * |--------+------+------+------+------+------|  /   |           |  #   |------+------+------+------+------+--------|
 * | LSh/(  |   Y  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   -  | RSh/)  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LCtrl| Lead | AltGr| Left | Right|                                       |  Up  | Down | ~L1  | RCtrl| Play |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | C/P  | Close|       | Home | End  |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | App  |       | Alt  |      |      |
 *                                 | Space| Esc  |------|       |------| Tab  |Enter |
 *                                 |      |      | GUI  |       | GUI  |      |      |
 *                                 `--------------------'       `--------------------'
 */
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        LR_GAME,        DE_1,         DE_2,   DE_3,   DE_4,   DE_5,   KC_DELETE,
        LR_SYMB,        DE_Q,         DE_W,   DE_E,   DE_R,   DE_T,   DE_DQOT,
        KC_BSPC,        DE_A,         DE_S,   DE_D,   DE_F,   DE_G,
        KC_LSPO,        DE_Y,         DE_X,   DE_C,   DE_V,   DE_B,   DE_SLSH,
        KC_LCTL,        KC_LEAD,      KC_RALT,KC_LEFT,KC_RGHT,
                                                 COPYPASTE,     CLOSE,
                                                               KC_APP,
                                            KC_SPC, KC_ESC,   KC_LGUI,
        // right hand
             UNDOREDO,    DE_6,   DE_7,   DE_8,   DE_9,   DE_0,             DE_SS,
             DE_PLUS,     DE_Z,   DE_U,   DE_I,   DE_O,   DE_P,             DE_UE,
                          DE_H,   DE_J,   DE_K,   DE_L,   DE_OE,            DE_AE,
             DE_HASH,     DE_N,   DE_M,   DE_COMM,DE_DOT, DE_MINS,          KC_RSPC,
                                  KC_UP,  KC_DOWN,LR_SYMB,KC_RCTL,          KC_MPLY,
             KC_HOME, KC_END,
             KC_LALT,
             KC_LGUI, KC_TAB, KC_ENT
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   ´    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   `  |   @  |   <  |   >  |   %  |  {   |           |  }   |   /  |   7  |   8  |   9  |   *  |   ->   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   #  |   $  |   '  |   \  |   =  |------|           |------|   .  |   4  |   5  |   6  |   +  |   =>   |
 * |--------+------+------+------+------+------|  [   |           |  ]   |------+------+------+------+------+--------|
 * |        |   ~  |   €  |   &  |   ^  |   |  |      |           |      |   ,  |   1  |   2  |   3  |   -  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |   0  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
       KC_TRNS, DE_GRV,  DE_AT,   DE_LESS, DE_MORE, DE_PERC, DE_LCBR,
       KC_TRNS, DE_HASH, DE_DLR,  DE_QUOT, DE_BSLS, DE_EQL,
       KC_TRNS, DE_TILD, DE_EURO, DE_AMPR, DE_CIRC, DE_PIPE, DE_LBRC,
       KC_TRNS, KC_TRNS, DE_EURO, KC_TRNS, KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  DE_ACUT,
       DE_RCBR, KC_PSLS, KC_P7,   KC_P8,   KC_P9,   KC_PAST, ARROW,
                DE_DOT,  KC_P4,   KC_P5,   KC_P6,   KC_PPLS, EQARROW,
       DE_RBRC, DE_COMM, KC_P1,   KC_P2,   KC_P3,   KC_PMNS, KC_TRNS,
                         KC_TRNS, KC_TRNS, KC_TRNS, KC_P0,   KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      | Calc | Sleep|           |ArrTgl|   1  |   2  |   3  |   4  |   5  |   6    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |  Esc |  Tab |   Q  |   W  |   E  |   R  |   T    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | Prev |MsLeft|MsDown|MsRght| Next |------|           |------|   I  |   A  |   S  |   D  |   F  | Enter  |
 * |--------+------+------+------+------+------| Print|           |   H  |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |   M  |   Y  |   X  |   C  |   V  | LShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      | Mute | VolDn| VolUp|                                       |   B  |   N  |   U  |   O  |   G  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | Wh_up|       |      |      |      |
 *                                 | Lclk | Rclk |------|       |------| Ctrl |  Alt |
 *                                 |      |      |Wh_dwn|       | Space|      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[GAME] = LAYOUT_ergodox(
    // left hand
       KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_CALC,    KC_SLEP,
       KC_NO,   KC_NO,   KC_NO,   KC_MS_U, KC_NO,   KC_NO,      KC_NO,
       KC_NO,   KC_MPRV, KC_MS_L, KC_MS_D, KC_MS_R, KC_MNXT,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_PSCREEN,
       KC_NO,   KC_NO,   KC_MUTE, KC_VOLD, KC_VOLU,
                                           KC_NO,   KC_NO,
                                                    KC_WH_U,
                                  KC_BTN1, KC_BTN2, KC_WH_D,
    // right hand
       GAME_TG,    DE_1,    DE_2,      DE_3,      DE_4,      DE_5,    DE_6,
       KC_ESC,     KC_TAB,  DE_Q,      GAME_U,    DE_E,      DE_R,    DE_T,
                   DE_I,    GAME_L,    GAME_D,    GAME_R,    DE_F,    KC_ENT,
       DE_H,       DE_M,    DE_Y,      DE_X,      DE_C,      DE_V,    KC_LSFT,
                            DE_B,      DE_N,      DE_U,      DE_O,    DE_G,
       KC_NO,   KC_NO,
       KC_NO,
       KC_SPC,  KC_LCTL, KC_LALT
),
/* Keymap 3: Plover
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      | Base |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   #  |   #  |   #  |   #  |   #  |   #  |           |  #   |  #   |  #   |  #   |  #   |  #   |   #    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |   T  |   P  |   H  |      |------|           |------|      |  F   |  P   |  L   |  T   |   D    |
 * |--------+   S  +------+------+------+   *  |   *  |           |  *   |  *   +------+------+------+------+--------|
 * |        |      |   K  |   W  |   R  |      |      |           |      |      |  R   |  B   |  G   |  S   |   Z    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |   A  |   O  |------|       |------|  E   |  U   |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// Plover
[PLVR] = LAYOUT_ergodox(
    // left hand
       STENO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,   PV_NUM,  PV_NUM,  PV_NUM,  PV_NUM,  PV_NUM,  PV_NUM,
       KC_NO,   PV_LS,   PV_LT,   PV_LP,   PV_LH,   PV_STAR,
       KC_NO,   PV_LS,   PV_LK,   PV_LW,   PV_LR,   PV_STAR, PV_STAR,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                           KC_NO,   KC_NO,
                                                    KC_NO,
                                  PV_A,    PV_O,    KC_NO,
    // right hand
       KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       PV_NUM,   PV_NUM,  PV_NUM,  PV_NUM,  PV_NUM,  PV_NUM,  PV_NUM,
                 PV_STAR, PV_RF,   PV_RP,   PV_RL,   PV_RT,   PV_RD,
       PV_STAR,  PV_STAR, PV_RR,   PV_RB,   PV_RG,   PV_RS,   PV_RZ,
                          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,   KC_NO,  
       KC_NO,  
       KC_NO,   PV_E,    PV_U
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB),               // FN1 - Momentary Layer 1 (Symbols)
    [2] = ACTION_LAYER_TAP_TOGGLE(GAME)                // FN2 - Momentary Layer 2 (Media)
};

static uint16_t paste_key_timer;
static uint16_t undo_key_timer;
static uint8_t game_keys_pressed = 0;
static uint8_t game_use_arrow_keys = 0;

void handle_game_key(keyrecord_t *, uint16_t, uint16_t);

void toggle_steno(void) {
    uint8_t layer = biton32(layer_state);

    if (layer != PLVR) { //Switch the layer
        layer_on(PLVR);
    } else {
        layer_off(PLVR);
    }

    register_code(PV_LP);
    register_code(PV_LH);
    register_code(PV_LR);
    register_code(PV_O);
    register_code(PV_RL);
    register_code(PV_RG);
    unregister_code(PV_LP);
    unregister_code(PV_LH);
    unregister_code(PV_LR);
    unregister_code(PV_O);
    unregister_code(PV_RL);
    unregister_code(PV_RG);
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
    case COPYPASTE:
        if (record->event.pressed) {
            paste_key_timer = timer_read(); //start a timer to differentiate a tap and a hold
        } else {
            if(timer_elapsed(paste_key_timer) > TAP_TIME) {
                SEND_STRING(SS_LCTL("c")); //copy when held
            } else {
                SEND_STRING(SS_LCTL("v")); //paste when tapped
            }
        }
        break;
    case STENO:
        if(!record->event.pressed) {
            toggle_steno();
        }
        break;
    case CLOSE:
        if(!record->event.pressed) {
            SEND_STRING(SS_LALT(SS_TAP(X_F4)));
        }
        break;
    case UNDOREDO:
        if (record->event.pressed) {
            undo_key_timer = timer_read(); //start a timer to differentiate a tap and a hold
        } else {
            if(timer_elapsed(undo_key_timer) > TAP_TIME) {
                send_string(SS_LCTL("y")); //redo when held
            } else {
                send_string(SS_LCTL("z")); //undo when tapped
            }
        }
        break;
    case ARROW:
        if(!record->event.pressed) {
            send_string("->");
        }
        break;
    case EQARROW:
        if(!record->event.pressed) {
            send_string("=>");
        }
        break;
    case GAME_U:
        handle_game_key(record, KC_UP, DE_W);
        break;
    case GAME_D:
        handle_game_key(record, KC_DOWN, DE_S);
        break;
    case GAME_L:
        handle_game_key(record, KC_LEFT, DE_A);
        break;
    case GAME_R:
        handle_game_key(record, KC_RGHT, DE_D);
        break;
    case GAME_TG:
        if(!record->event.pressed) {
            ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
                if(game_keys_pressed == 0) {
                    game_use_arrow_keys = !game_use_arrow_keys;
                }
            }
        }
        break;
    }
    return true;
};

void handle_game_key(keyrecord_t *record, uint16_t arrow_key, uint16_t letter_key) {
    if(record->event.pressed) {
        ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
            game_keys_pressed += 1;
            if(game_use_arrow_keys) {
                register_code(arrow_key);
            } else {
                register_code(letter_key);
            }
        }
    } else {
        ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
            game_keys_pressed -= 1;
            if(game_use_arrow_keys) {
                unregister_code(arrow_key);
            } else {
                unregister_code(letter_key);
            }
        }
    }
}

LEADER_EXTERNS();

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    uint8_t layer = get_highest_layer(layer_state);

    ergodox_board_led_off();
    switch (layer) {
        case BASE:
            ergodox_right_led_1_off();
            ergodox_right_led_2_off();
            ergodox_right_led_3_off();
            break;
        case SYMB:
            ergodox_right_led_1_on();
            ergodox_right_led_2_off();
            ergodox_right_led_3_off();
            break;
        case GAME:
            ergodox_right_led_1_off();
            ergodox_right_led_2_on();
            if(game_use_arrow_keys) {
                ergodox_right_led_3_on();
            } else {
                ergodox_right_led_3_off();
            }
            break;
        case PLVR:
            ergodox_right_led_1_off();
            ergodox_right_led_2_off();
            ergodox_right_led_3_on();
            break;
        default:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
    }

    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        SEQ_ONE_KEY(KC_S) {
            toggle_steno();
        }
    }

};
