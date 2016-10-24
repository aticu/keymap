#include "ergodox.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "keymap_german.h"
#include "keymap_plover.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys
#define PLVR 3 //steno using plover

#define COPYPASTE M(0) // Macro 0: The copy paste key
#define STENO M(1) // Macro 1: Switch to steno layer and activate plover
#define CLOSE M(2) //Macro 2: Close the currently opened window

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Del    |   1  |   2  |   3  |   4  |   5  | Steno|           | Close|   6  |   7  |   8  |   9  |   0  |   ß    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | ~L1    |   Q  |   W  |   E  |   R  |   T  |  "   |           |  +   |   Z  |   U  |   I  |   O  |   P  |   Ü    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | BkSp   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   Ö  |   Ä    |
 * |--------+------+------+------+------+------|  #   |           |  /   |------+------+------+------+------+--------|
 * | LSh/(  |   Y  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   -  | RSh/)  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | ~L1  |   ´  |   <  | Left | Right|                                       |  Up  | Down | AltGr| RCtrl| ~L2  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | C/P  | LCtrl|       | Home | End  |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | App  |       | GUI  |      |      |
 *                                 | Space| Esc  |------|       |------| Tab  |Enter |
 *                                 |      |      | Alt  |       | Alt  |      |      |
 *                                 `--------------------'       `--------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        DE_DELETE,      DE_1,         DE_2,   DE_3,   DE_4,   DE_5,   STENO,
        KC_FN1,         DE_Q,         DE_W,   DE_E,   DE_R,   DE_T,   DE_DQOT,
        KC_BSPC,        DE_A,         DE_S,   DE_D,   DE_F,   DE_G,
        KC_LSPO,        DE_Y,         DE_X,   DE_C,   DE_V,   DE_B,   DE_HASH,
        KC_FN1,         DE_ACUT,      DE_LESS,KC_LEFT,KC_RGHT,
                                                 COPYPASTE,   KC_LCTL,
                                                               KC_APP,
                                            KC_SPC, KC_ESC,   KC_LALT,
        // right hand
             CLOSE,       DE_6,   DE_7,   DE_8,   DE_9,   DE_0,             DE_SS,
             DE_PLUS,     DE_Z,   DE_U,   DE_I,   DE_O,   DE_P,             DE_UE,
                          DE_H,   DE_J,   DE_K,   DE_L,   DE_OE,            DE_AE,
             DE_SLSH,     DE_N,   DE_M,   DE_COMM,DE_DOT, DE_MINS,          KC_RSPC,
                                  KC_UP,  KC_DOWN,DE_ALGR,KC_RCTL,          KC_FN2,
             KC_HOME, KC_END,
             KC_LGUI,
             KC_LALT, KC_TAB, KC_ENT
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   <  |   >  |   |  |  [   |           |  ]   |   =  |   7  |   8  |   9  |   *  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   #  |   $  |   '  |   \  |   0  |------|           |------|   .  |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|  {   |           |  }   |------+------+------+------+------+--------|
 * |        |  F11 |   ^  |   %  |   &  |   ~  |      |           |      |   ,  |   1  |   2  |   3  |  F12 |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |   0  |      |      |
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
[SYMB] = KEYMAP(
       // left hand
       KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,
       KC_TRNS, DE_EXLM, DE_AT,   DE_LESS, DE_MORE, DE_PIPE, DE_LBRC,
       KC_TRNS, DE_HASH, DE_DLR,  DE_QUOT, DE_BSLS, DE_0,
       KC_TRNS, KC_F11,  DE_CIRC, DE_PERC, DE_AMPR, DE_TILD, DE_LCBR,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_TRNS,
       DE_RBRC, DE_EQL,  DE_7,    DE_8,    DE_9,    DE_ASTR, KC_TRNS,
                DE_DOT,  DE_4,    DE_5,    DE_6,    DE_PLUS, KC_TRNS,
       DE_RCBR, DE_COMM, DE_1,    DE_2,    DE_3,    KC_F12,  KC_TRNS,
                         KC_TRNS, KC_TRNS, DE_0,    KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | Lclk | Btn4 |------|       |------| Btn5 | Rclk |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = KEYMAP(
    // left hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_BTN1, KC_BTN4, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_BTN5, KC_BTN2
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
[PLVR] = KEYMAP(
    // left hand
       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   STENO,
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
    [2] = ACTION_LAYER_TAP_TOGGLE(MDIA)                // FN2 - Momentary Layer 2 (Media)
};

static uint16_t paste_key_timer;

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case 0: //Copy/paste
            if (record->event.pressed) { //when the key is pressed
                paste_key_timer = timer_read(); //start a timer to differentiate a tap and a hold
            }
            else { //when the key is released, decide what to do
                if(timer_elapsed(paste_key_timer) > 200) { //holding is more than 200ms
                    return MACRO(D(LCTL), T(C), U(LCTL), END); //copy when held
                }
                else {
                    return MACRO(D(LCTL), T(V), U(LCTL), END); //paste when tapped
                }
            }
            break;
        case 1:; //Steno
            uint8_t layer = biton32(layer_state);

            if (record->event.pressed) { //when the key is pressed, toggle plover and layer
                if (layer != PLVR) //Switch the layer
                    layer_on(PLVR);
                else
                    layer_off(PLVR);

                register_code(PV_LP);
                register_code(PV_LH);
                register_code(PV_LR);
                register_code(PV_O);
                register_code(PV_RL);
                register_code(PV_RG);
            }
            else { //when the key is released, finish toggling plover
                unregister_code(PV_LP);
                unregister_code(PV_LH);
                unregister_code(PV_LR);
                unregister_code(PV_O);
                unregister_code(PV_RL);
                unregister_code(PV_RG);
            }
            break;
        case 2: //Close
            if(!record->event.pressed)
                return MACRO(D(LALT), T(F4), U(LALT), END);
            break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
    uint8_t on = 0;
    uint8_t steps = 10;
    uint8_t increase = LED_BRIGHTNESS_HI / steps;
    
    for(int i = 0; i < 10; ++i) {
        if(on)
            ergodox_led_all_set(i * increase);
        else
            ergodox_led_all_off();
        on = !on;
        wait_ms(10);
    }
};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 3:
            ergodox_right_led_3_on();
        default:
            // none
            break;
    }

};
