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
    CMNT,
    DC_CMNT,
    MD_CODE,
    GAME_U,
    GAME_D,
    GAME_L,
    GAME_R,
    GAME_TG,
    GRAVE,
    CIRCUMF,
    NUM_0,
    NUM_1,
    NUM_2,
    NUM_3,
    NUM_4,
    NUM_5,
    NUM_6,
    NUM_7,
    NUM_8,
    NUM_9,
    NUM_DIV,
    NUM_MUL,
    NUM_ADD,
    NUM_SUB,
    NUM_ENT,
    NUM_COM,
    NUM_DOT,
    NUM_TG
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
 *   | LCtrl| Lead | AltGr| Left | Right|                                       |  Up  | Down | ~L1  | RCtrl| Hyper|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | C/P  | Close|       | Home | End  |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | App  |       | Alt  |      |      |
 *                                 | Space| Esc  |------|       |------| Tab  |Enter |
 *                                 |      |      | GUI  |       | GUI  |      |      |
 *                                 `--------------------'       `--------------------'
 */
[BASE] = LAYOUT_ergodox(
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
                                  KC_UP,  KC_DOWN,LR_SYMB,KC_RCTL,          KC_HYPR,
             KC_HOME, KC_END,
             KC_LALT,
             KC_LGUI, KC_TAB, KC_ENT
),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 | NumTgl |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   `  |   @  |   <  |   >  |   ´  |  {   |           |  }   |   /  |   7  |   8  |   9  |   *  |   ->   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  //  |  /// |   '  |   \  |  ``` |------|           |------|   .  |   4  |   5  |   6  |   +  |   =>   |
 * |--------+------+------+------+------+------|  [   |           |  ]   |------+------+------+------+------+--------|
 * |        |   ~  |   €  |  ^/° |   ^  |   |  |      |           |      |   ,  |   1  |   2  |   3  |   -  |        |
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
[SYMB] = LAYOUT_ergodox(
       // left hand
       KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,
       KC_TRNS, GRAVE,   DE_AT,   DE_LESS, DE_MORE, DE_ACUT, DE_LCBR,
       KC_TRNS, CMNT,    DC_CMNT, DE_QUOT, DE_BSLS, MD_CODE,
       KC_TRNS, DE_TILD, DE_EURO, DE_CIRC, CIRCUMF, DE_PIPE, DE_LBRC,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  NUM_TG,
       DE_RCBR, NUM_DIV, NUM_7,   NUM_8,   NUM_9,   NUM_MUL, ARROW,
                NUM_DOT, NUM_4,   NUM_5,   NUM_6,   NUM_ADD, EQARROW,
       DE_RBRC, NUM_COM, NUM_1,   NUM_2,   NUM_3,   NUM_SUB, KC_TRNS,
                         KC_TRNS, KC_TRNS, KC_TRNS, NUM_0,   KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |Ply/Ps| Prev | Next |      |      |      |           |   0  |   1  |   2  |   3  |   4  |   5  |   6    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |  Esc |  Tab |   Q  |   W  |   E  |   R  |   T    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|   I  |   A  |   S  |   D  |   F  | Enter  |
 * |--------+------+------+------+------+------| Print|           |   H  |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |   M  |   Y  |   X  |   C  |   V  | LShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |ArrTgl|      | Mute | VolDn| VolUp|                                       |   B  |   N  |   U  |   O  |   G  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |   P  |   L  |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | Wh_up|       |   K  |      |      |
 *                                 | Lclk | Rclk |------|       |------| Ctrl |  Alt |
 *                                 |      |      |Wh_dwn|       | Space|      |      |
 *                                 `--------------------'       `--------------------'
 */
[GAME] = LAYOUT_ergodox(
    // left hand
       KC_TRNS, KC_MPLY, KC_MPRV, KC_MNXT, KC_NO,   KC_NO,      KC_NO,
       KC_NO,   KC_NO,   KC_NO,   KC_MS_U, KC_NO,   KC_NO,      KC_NO,
       KC_NO,   KC_NO,   KC_MS_L, KC_MS_D, KC_MS_R, KC_NO,
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_PSCREEN,
       GAME_TG, KC_NO,   KC_MUTE, KC_VOLD, KC_VOLU,
                                           KC_NO,   KC_NO,
                                                    KC_WH_U,
                                  KC_BTN1, KC_BTN2, KC_WH_D,
    // right hand
       DE_0,       DE_1,    DE_2,      DE_3,      DE_4,      DE_5,    DE_6,
       KC_ESC,     KC_TAB,  DE_Q,      GAME_U,    DE_E,      DE_R,    DE_T,
                   DE_I,    GAME_L,    GAME_D,    GAME_R,    DE_F,    KC_ENT,
       DE_H,       DE_M,    DE_Y,      DE_X,      DE_C,      DE_V,    KC_LSFT,
                            DE_B,      DE_N,      DE_U,      DE_O,    DE_G,
       DE_P,    DE_L,
       DE_K,
       KC_SPC,  KC_LCTL, KC_LALT
),
/* Keymap 3: Plover
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Ext lyr|      |      |      |      |      | Base |           |      |      |      |      |      |      |        |
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

// *** Toggle mechanism for having two-purpose keys ***
struct toggle_key_state {
    uint8_t use_first_key;
    uint8_t keys_pressed;
};
static struct toggle_key_state game_keys;
static struct toggle_key_state numpad_keys;

// Switches the toggle mechanism of the given class to use the other variant
void switch_toggle_key(keyrecord_t *record, struct toggle_key_state *state) {
    if(!record->event.pressed) {
        ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
            if(state->keys_pressed == 0) {
                state->use_first_key = !state->use_first_key;
            }
        }
    }
}

// Handles a keypress for the given toggle key class
void handle_toggle_key(keyrecord_t *record, struct toggle_key_state *state, uint16_t first_key, uint16_t second_key) {
    if(record->event.pressed) {
        ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
            state->keys_pressed += 1;
            if(state->use_first_key) {
                register_code(first_key);
            } else {
                register_code(second_key);
            }
        }
    } else {
        ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
            state->keys_pressed -= 1;
            if(state->use_first_key) {
                unregister_code(first_key);
            } else {
                unregister_code(second_key);
            }
        }
    }
}

void toggle_steno(void) {
    uint8_t layer = get_highest_layer(layer_state);

    if (layer != PLVR) {
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
    case CMNT:
        if(!record->event.pressed) {
            send_string("//");
        }
        break;
    case DC_CMNT:
        if(!record->event.pressed) {
            send_string("///");
        }
        break;
    case MD_CODE:
        if(!record->event.pressed) {
            send_string("` ` ` ");
        }
        break;
    case GAME_U:
        handle_toggle_key(record, &game_keys, KC_UP, DE_W);
        break;
    case GAME_D:
        handle_toggle_key(record, &game_keys, KC_DOWN, DE_S);
        break;
    case GAME_L:
        handle_toggle_key(record, &game_keys, KC_LEFT, DE_A);
        break;
    case GAME_R:
        handle_toggle_key(record, &game_keys, KC_RGHT, DE_D);
        break;
    case GAME_TG:
        switch_toggle_key(record, &game_keys);
        break;
    case GRAVE:
        if(!record->event.pressed) {
            send_string("` ");
        }
        break;
    case CIRCUMF:
        if(!record->event.pressed) {
            send_string("^ ");
        }
        break;
    case NUM_0:
        handle_toggle_key(record, &numpad_keys, DE_0, KC_P0);
        break;
    case NUM_1:
        handle_toggle_key(record, &numpad_keys, DE_1, KC_P1);
        break;
    case NUM_2:
        handle_toggle_key(record, &numpad_keys, DE_2, KC_P2);
        break;
    case NUM_3:
        handle_toggle_key(record, &numpad_keys, DE_3, KC_P3);
        break;
    case NUM_4:
        handle_toggle_key(record, &numpad_keys, DE_4, KC_P4);
        break;
    case NUM_5:
        handle_toggle_key(record, &numpad_keys, DE_5, KC_P5);
        break;
    case NUM_6:
        handle_toggle_key(record, &numpad_keys, DE_6, KC_P6);
        break;
    case NUM_7:
        handle_toggle_key(record, &numpad_keys, DE_7, KC_P7);
        break;
    case NUM_8:
        handle_toggle_key(record, &numpad_keys, DE_8, KC_P8);
        break;
    case NUM_9:
        handle_toggle_key(record, &numpad_keys, DE_9, KC_P9);
        break;
    case NUM_DIV:
        handle_toggle_key(record, &numpad_keys, DE_SLSH, KC_PSLS);
        break;
    case NUM_MUL:
        handle_toggle_key(record, &numpad_keys, DE_ASTR, KC_PAST);
        break;
    case NUM_ADD:
        handle_toggle_key(record, &numpad_keys, DE_PLUS, KC_PPLS);
        break;
    case NUM_SUB:
        handle_toggle_key(record, &numpad_keys, DE_MINS, KC_PMNS);
        break;
    case NUM_ENT:
        handle_toggle_key(record, &numpad_keys, KC_ENT, KC_PENT);
        break;
    case NUM_COM:
        handle_toggle_key(record, &numpad_keys, DE_COMM, KC_PCMM);
        break;
    case NUM_DOT:
        handle_toggle_key(record, &numpad_keys, DE_DOT, KC_PDOT);
        break;
    case NUM_TG:
        switch_toggle_key(record, &numpad_keys);
        break;
    }
    return true;
};

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
            if(numpad_keys.use_first_key) {
                ergodox_right_led_3_on();
            } else {
                ergodox_right_led_3_off();
            }
            break;
        case GAME:
            ergodox_right_led_1_off();
            ergodox_right_led_2_on();
            if(game_keys.use_first_key) {
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

        SEQ_ONE_KEY(KC_L) {
            register_code(KC_LCTL);
            register_code(KC_LALT);

            register_code(KC_F2);
            unregister_code(KC_F2);
            _delay_ms(50);
            register_code(KC_F1);
            unregister_code(KC_F1);

            unregister_code(KC_LALT);
            unregister_code(KC_LCTL);
        }
        SEQ_ONE_KEY(KC_P) {
            toggle_steno();
        }
    }

};
