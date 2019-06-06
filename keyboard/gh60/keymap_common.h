/*
Copyright 2012,2013 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef KEYMAP_COMMON_H
#define KEYMAP_COMMON_H

#include <stdint.h>
#include <stdbool.h>
#include <avr/pgmspace.h>
#include "keycode.h"
#include "action.h"
#include "action_macro.h"
#include "report.h"
#include "host.h"
#include "print.h"
#include "debug.h"
#include "keymap.h"
#include "action_layer.h"

/*
extern const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS];
extern const uint16_t fn_actions[];
extern const uint16_t fn_actions_1[];
extern const uint16_t fn_actions_2[];
extern const uint16_t fn_actions_3[];
*/

/* GH60 keymap definition macro
 * K2C, K31 and  K3C are extra keys for ISO
 */
#define KEYMAP( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, K2D, \
    K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D, \
    K40, K41, K42, K43, K44, K45, K46, K47, K48, K49, K4A, K4B, K4C, K4D  \
) { \
    { KC_##K00, KC_##K01, KC_##K02, KC_##K03, KC_##K04, KC_##K05, KC_##K06, KC_##K07, KC_##K08, KC_##K09, KC_##K0A, KC_##K0B, KC_##K0C, KC_##K0D }, \
    { KC_##K10, KC_##K11, KC_##K12, KC_##K13, KC_##K14, KC_##K15, KC_##K16, KC_##K17, KC_##K18, KC_##K19, KC_##K1A, KC_##K1B, KC_##K1C, KC_##K1D }, \
    { KC_##K20, KC_##K21, KC_##K22, KC_##K23, KC_##K24, KC_##K25, KC_##K26, KC_##K27, KC_##K28, KC_##K29, KC_##K2A, KC_##K2B, KC_##K2C, KC_##K2D }, \
    { KC_##K30, KC_##K31, KC_##K32, KC_##K33, KC_##K34, KC_##K35, KC_##K36, KC_##K37, KC_##K38, KC_##K39, KC_##K3A, KC_##K3B, KC_##K3C, KC_##K3D }, \
    { KC_##K40, KC_##K41, KC_##K42, KC_##K43, KC_##K44, KC_##K45, KC_##K46, KC_##K47, KC_##K48, KC_##K49, KC_##K4A, KC_##K4B, KC_##K4C, KC_##K4D }  \
}

/* ANSI valiant. No extra keys for ISO */
#define KEYMAP_ANSI( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, K2D, \
    K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D, \
    K40, K41, K42, K43, K44, K45, K46, K47, K48, K49, K4A, K4B, K4C, K4D  \
) KEYMAP( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, K2D, \
    K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D, \
    K40, K41, K42, K43, K44, K45, K46, K47, K48, K49, K4A, K4B, K4C, K4D  \
)


#define KEYMAP_HHKB( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, K2D, \
    K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D, \
    K40, K41, K42, K43, K44, K45, K46, K47, K48, K49, K4A, K4B, K4C, K4D  \
) KEYMAP( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, K2D, \
    K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D, \
    K40, K41, K42, K43, K44, K45, K46, K47, K48, K49, K4A, K4B, K4C, K4D  \
)

#endif


const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    
    /* 0: dvorak */
    KEYMAP(GRV,    1,   2,   3,    4,   5,  F5,HOME,   6,   7,   8,   9,   0,BSPC, \
           TAB, QUOT,COMM, DOT,    P,   Y,LBRC,RBRC,   F,   G,   C,   R,   L,BSLS, \
           FN0,    A,   O,   E,    U,   I,SLSH, EQL,   D,   H,   T,   N,   S,MINS, \
           LSFT,SCLN,   Q,   J,    K,   X, ESC, ESC,   B,   M,   W,   V,   Z,RSFT, \
           CAPS,LCTL, FN0,LALT, LGUI, SPC,BSPC, ENT, SPC,RGUI,RALT, FN5, FN1,RCTL),

    /* 1: qwerty */
    KEYMAP(TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
           TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
           TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
           TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS, \
           TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS),

    /* 2: navigation */
    KEYMAP(FN19,  F1,  F2,  F3,  F4,  F5,TRNS,FN25,  F6,  F7,  F8,  F9, F10,TRNS, \
           TRNS,CAPS,FN11,FN14,  NO,  NO,TRNS,TRNS,FN16,PGUP,  UP,PGDN,  NO,TRNS, \
           TRNS,  NO, FN9,  NO,FN10,  NO,TRNS,TRNS,TRNS,LEFT,DOWN,RGHT,  NO,TRNS, \
           TRNS,FN23,FN22,FN12, FN8,FN21,TRNS,TRNS,HOME,TRNS,TRNS, END,  NO,TRNS, \
           TRNS,MUTE,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,PAUS),

    /* 3: numbers */
    KEYMAP( FN4,  F1,  F2,  F3,  F4,  F5,TRNS,TRNS,  F6,  F7,  F8,  F9, F10, FN6, \
           TRNS,FN12,FN13,FN14,FN15,FN16,TRNS,TRNS,FN11, FN7, FN8,SCLN,SCLN,TRNS, \
           TRNS,   1,   2,   3,   4,   5,TRNS,TRNS,   6,   7,   8,   9,   0,TRNS, \
           TRNS,BSLS,FN17,LBRC,RBRC,FN18,TRNS,TRNS, FN9,FN10,TRNS,TRNS,TRNS,TRNS, \
           TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,PDOT,TRNS,TRNS),

};

const uint16_t PROGMEM fn_actions[] = {
    // layer functions
    [0] = ACTION_LAYER_MOMENTARY(2), 			// navigation
    [1] = ACTION_LAYER_TOGGLE(1), 			// qwerty
    [2] = ACTION_LAYER_MOMENTARY(3),			// numbers
    [6] = ACTION_MODS_KEY(MOD_LALT,KC_F4),		// alt f4
    [7] = ACTION_MODS_KEY(MOD_LCTL | MOD_LALT, KC_DEL), // UNUSED ctrl alt del     
    [5] = ACTION_LAYER_TOGGLE(2), 			// navigation
    [13] = ACTION_MODS_KEY(MOD_LSFT, KC_SCLN),
    [8] = ACTION_LAYER_SET_CLEAR(0), 			// clear all layers
    [9] = ACTION_MODS_KEY(MOD_LCTL, KC_C), 		// copy
    [10] = ACTION_MODS_KEY(MOD_LCTL, KC_V), 		// paste
    [11] = ACTION_MODS_KEY(MOD_LCTL | MOD_LSFT, KC_ESC),// task manager
    [12] = ACTION_MODS_KEY(MOD_LCTL, KC_Z), 		// undo
};

const uint16_t PROGMEM fn_actions_1[] = {
    // 0-5 are reserved for layer 0 functions
};

const uint16_t PROGMEM fn_actions_2[] = {
    // 0-5 are reserved for layer 0 functions

    // windows key shortcuts
    [13] = ACTION_MODS_KEY(MOD_RGUI, KC_E), 		// open computer
    [14] = ACTION_MODS_KEY(MOD_RGUI, KC_R), 		// run
    [15] = ACTION_MODS_KEY(MOD_RGUI, KC_UP), 		// gui up
    [16] = ACTION_MODS_KEY(MOD_RGUI, KC_LEFT), 		// gui left
    [17] = ACTION_MODS_KEY(MOD_RGUI, KC_DOWN), 		// gui down
    [18] = ACTION_MODS_KEY(MOD_RGUI, KC_RIGHT), 	// gui right 
    [11] = ACTION_MODS_KEY(MOD_RGUI, KC_D), 		// desktop
    [7] = ACTION_MODS_KEY(MOD_RGUI, KC_R), 		// run
    [8] = ACTION_MODS_KEY(MOD_RGUI, KC_E), 		// my computer
    [9] = ACTION_MODS_KEY(MOD_RGUI, KC_S), 		// search
    [10] = ACTION_MODS_KEY(MOD_RGUI, KC_T), 		// cycle tabs
    [6] = ACTION_LAYER_TOGGLE(1), 			// qwerty
    [12] = ACTION_MODS_KEY(MOD_RGUI, KC_M), 		// minimize all
    [13] = ACTION_MODS_KEY(MOD_RGUI, KC_A), 		// UNUSED action center / shifted - 
    [19] = ACTION_MODS_KEY(MOD_LCTL | MOD_LALT, KC_DEL),// ctl alt del
    // word
    [20] = ACTION_MODS_KEY(MOD_LCTL, KC_C), 		// copy
    [21] = ACTION_MODS_KEY(MOD_LCTL, KC_V), 		// paste
    [22] = ACTION_MODS_KEY(MOD_LCTL, KC_X), 		// cut
    [23] = ACTION_MODS_KEY(MOD_LCTL, KC_Z), 		// undo
    [24] = ACTION_MODS_KEY(MOD_LCTL, KC_Y), 		// redo
    [25] = ACTION_MODS_KEY(MOD_LCTL | MOD_RGUI, KC_F4), // close virtual desktop
};

const uint16_t PROGMEM fn_actions_3[] = {
    // 0-5 are reserved for layer 0 functions
    // number actions
    [12] = ACTION_MODS_KEY(MOD_LSFT, KC_1),
    [13] = ACTION_MODS_KEY(MOD_LSFT, KC_2),
    [14] = ACTION_MODS_KEY(MOD_LSFT, KC_3),
    [15] = ACTION_MODS_KEY(MOD_LSFT, KC_4),
    [16] = ACTION_MODS_KEY(MOD_LSFT, KC_5),
    [11] = ACTION_MODS_KEY(MOD_LSFT, KC_6),
    [7] = ACTION_MODS_KEY(MOD_LSFT, KC_7),
    [8] = ACTION_MODS_KEY(MOD_LSFT, KC_8),
    [9] = ACTION_MODS_KEY(MOD_LSFT, KC_9),
    [10] = ACTION_MODS_KEY(MOD_LSFT, KC_0),
    [6] = ACTION_LAYER_TOGGLE(0), 			// qwerty
    [17] = ACTION_MODS_KEY(MOD_LSFT, KC_BSLS),
    [18] = ACTION_MODS_KEY(MOD_LSFT, KC_MINS),
};


#define FN_ACTIONS_SIZE     (sizeof(fn_actions)   / sizeof(fn_actions[0]))
#define FN_ACTIONS_1_SIZE   (sizeof(fn_actions_1) / sizeof(fn_actions_1[0]))
#define FN_ACTIONS_2_SIZE   (sizeof(fn_actions_2) / sizeof(fn_actions_2[0]))
#define FN_ACTIONS_3_SIZE   (sizeof(fn_actions_3) / sizeof(fn_actions_3[0]))

/*
 * translates Fn keycode to action
 * for some layers, use different translation table
 */
action_t keymap_fn_to_action(uint8_t keycode)
{
    uint8_t layer = biton32(layer_state);

    action_t action;
    action.code = ACTION_NO;

    if (layer == 1 && FN_INDEX(keycode) < FN_ACTIONS_1_SIZE) {
        action.code = pgm_read_word(&fn_actions_1[FN_INDEX(keycode)]);
    }

    if (layer == 2 && FN_INDEX(keycode) < FN_ACTIONS_2_SIZE) {
        action.code = pgm_read_word(&fn_actions_2[FN_INDEX(keycode)]);
    }

    if (layer == 3 && FN_INDEX(keycode) < FN_ACTIONS_3_SIZE) {
        action.code = pgm_read_word(&fn_actions_3[FN_INDEX(keycode)]);
    }

    // by default, use fn_actions from default layer 0
    // this is needed to get mapping for same key, that was used switch to some layer,
    // to have possibility to switch layers back
    if (action.code == ACTION_NO && FN_INDEX(keycode) < FN_ACTIONS_SIZE) {
        action.code = pgm_read_word(&fn_actions[FN_INDEX(keycode)]);
    }

    return action;
}