/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

#include QMK_KEYBOARD_H
#include <stdio.h>
#include "keymap_french.h"
#include "sendstring_french.h"

/* IDEAS:
 * Leader key function by app. Ex: <$>mn for new mail ou $dw for deleting current word
*/ 
enum custom_keycodes {
    PRENOM = SAFE_RANGE,
    NOM,
    POL1,
    POL2,
    POL3,
    HELLO1,
    CP_WSEARCH,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case PRENOM:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING("Nicolas");
        } else {
            // when keycode is released
        }
        break;

    case NOM:
        if (record->event.pressed) {
            // when keycode QMKURL is pressed
            SEND_STRING("Capon");
        } else {
            // when keycode is released
        }
        break;

    case POL1:
        if (record->event.pressed) {
           SEND_STRING("Bien cordialement,\nNicolas Capon");
           SEND_STRING(SS_LCTL("\n"));
        }
        break;

    case POL2:
        if (record->event.pressed) {
           SEND_STRING("Bien `a toi,\nNicolas");
           SEND_STRING(SS_LCTL("\n"));
        }
        break;

    case POL3:
        if (record->event.pressed) {
           SEND_STRING("Bien `a vous,\nNicolas");
        }
        break;

    case HELLO1:
        if (record->event.pressed) {
           SEND_STRING("Bonjour,\n");
        }
        break;

    case CP_WSEARCH:
        if (record->event.pressed) {
           // Open new browser tab, paste and search
           SEND_STRING(SS_LCTL("t") SS_DELAY(100) SS_LCTL("v") SS_TAP(X_ENTER));        }
        break;
    }
    return true;
};

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    // To enable layer switch when key is tapped then tap-holded without repeating the letter
    switch (keycode) {
        case LT(6, FR_M):
            return true;
        default:
            return false;
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	// French letters
	[0] = LAYOUT_split_3x6_3(
 KC_BTN1, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MS_WH_UP,
 C_S_T(KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, LT(6, FR_M), LT(5, FR_QUOT),
 KC_BTN2, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, FR_DOT, LT(5,FR_COMM), FR_COLN, LT(4,FR_DLR), KC_MS_WH_DOWN,
 KC_LGUI, LCTL_T(KC_BSPC), KC_SPC, LT(1,KC_ENT), LSFT_T(KC_TAB), LALT_T(KC_TAB)),
	// French symbols
	[1] = LAYOUT_split_3x6_3(
 FR_AMPR, FR_AT, FR_EXLM, FR_LBRC, FR_RBRC, FR_PIPE, FR_HASH, FR_7, FR_8, FR_9, FR_BSLS, KC_DEL,
 FR_SCLN, FR_ASTR, FR_DQUO, FR_LPRN, FR_RPRN, FR_SLSH, FR_EQL, FR_4, FR_5, FR_6, FR_PLUS, FR_GRV,
 FR_TILD, FR_PERC, FR_MINS, FR_LCBR, FR_RCBR, FR_UNDS, FR_0, FR_1, FR_2, FR_3, FR_QUES, TO(2),
 FR_LABK, FR_RABK, KC_SPC, KC_ENT, LSFT_T(KC_BSPC), LALT_T(KC_TAB)),
	// English letters
	[2] = LAYOUT_split_3x6_3(
 LALT_T(KC_BSPC), KC_A, KC_Z, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_DEL,
 C_S_T(KC_ESC), KC_Q, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_M, KC_QUOT,
 KC_NO, KC_W, KC_X, KC_C, KC_V, KC_B, KC_N, KC_DOT, LCTL_T(KC_COMM), KC_COLN, LT(4,KC_DLR), KC_TRNS,
 KC_LGUI, LCTL_T(KC_BSPC), KC_SPC, LT(3,KC_ENT), LSFT_T(KC_BSPC), LALT_T(KC_TAB)),
	// English symbols
	[3] = LAYOUT_split_3x6_3(
 KC_AMPR, KC_AT, KC_EXLM, KC_LBRC, KC_RBRC, KC_PIPE, KC_HASH, KC_7, KC_8, KC_9, KC_BSLS, KC_CIRC,
 KC_SCLN, KC_ASTR, KC_DQUO, KC_LPRN, KC_RPRN, KC_SLSH, KC_EQL, KC_4, KC_5, KC_6, KC_PLUS, KC_GRV,
 KC_TILD, KC_PERC, KC_MINS, KC_LCBR, KC_RCBR, KC_UNDS, KC_0, KC_1, KC_2, KC_3, KC_QUES, TO(0),
 KC_LT, KC_GT, KC_SPC, KC_NO, LSFT_T(KC_BSPC), LALT_T(KC_TAB)),
	// Functions keys and arrows
	[4] = LAYOUT_split_3x6_3(
 KC_NO, KC_PGUP, KC_AT, KC_UP, KC_DLR, KC_PERC, KC_F12, KC_F7, KC_F8, KC_F9, KC_NO, RGB_HUI,
 KC_LCTL, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO, KC_F11, KC_F4, KC_F5, KC_F6, KC_NO, RGB_TOG,
 KC_LSFT, KC_PSCR, KC_NO, KC_NO, LCTL(KC_LALT), KC_NO, KC_F10, KC_F1, KC_F2, KC_F3, KC_NO, RGB_HUD,
 KC_LGUI, LCTL_T(KC_SPC), KC_SPC, KC_ENT, KC_TRNS, KC_RALT),
	// Desktop Navigation & Macros
	[5] = LAYOUT_split_3x6_3(
 KC_PRINT_SCREEN, KC_FIND, LCA(KC_LEFT), LGUI(KC_2), LCA(KC_RIGHT), KC_F11, KC_ACL0, KC_ACL1, KC_ACL2, KC_NO, KC_NO, KC_NO,
 HELLO1, KC_WBAK, LCTL(LGUI(KC_LEFT)), POL1, LCTL(LGUI(KC_RIGHT)), LCTL(KC_F11), RGB_TOG, RGB_HUI, RCS(KC_K), RGB_VAI, KC_NO, KC_NO, 
 KC_WREF, CP_WSEARCH, LSFT(KC_DELETE), LCTL(KC_INSERT), LSFT(KC_INSERT), KC_WSCH, RGB_MOD, RGB_HUD, KC_NO, RGB_VAD, RGB_SAD, KC_NO, 
 POL1, POL2, KC_MAIL, KC_ENT, LALT(KC_TAB), LCA(KC_TAB)),
	// French accents
	[6] = LAYOUT_split_3x6_3(
 FR_SUP2, FR_AGRV, FR_EGRV, FR_EACU, FR_DIAE, FR_CIRC, FR_GRV, FR_UGRV, KC_NO, KC_NO, KC_NO, KC_NO,
 KC_NO, KC_NO, KC_NO, FR_AMPR, FR_EURO, FR_PND, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
 KC_NO, KC_NO, KC_NO, FR_CCED, FR_SECT, FR_DEG, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
 KC_LGUI, KC_TRNS, KC_SPC, KC_ENT, KC_TRNS, KC_RALT)
    // TODO: Layer for coding
};


#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return OLED_ROTATION_270;
}
#define L_FR 0
#define L_FR_SYMB 1
#define L_EN 2
#define L_EN_SYMB 3
#define L_FN 4
#define L_MOUSE 5
#define L_ACCENT 6

void oled_render_layer_state(void) {
    switch (get_highest_layer(layer_state)) {
        case L_FR:
            oled_write_ln_P(PSTR("Fr"), false);
            break;
        case L_FR_SYMB:
            oled_write_ln_P(PSTR("Fr S"), false);
            break;
        case L_EN:
            oled_write_ln_P(PSTR("En"), false);
            break;
        case L_EN_SYMB:
            oled_write_ln_P(PSTR("En S"), false);
            break;
        case L_FN:
            oled_write_ln_P(PSTR("Fn"), false);
            break;
        case L_MOUSE:
            oled_write_ln_P(PSTR("Mo"), false);
            break;
        case L_ACCENT:
            oled_write_ln_P(PSTR("Acc"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undefined"), false);
    }
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x80, 0x00, 0xc0, 0xe0, 0xe0, 0x30, 0x00, 0x00, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0xc0, 0xc0, 
0xc0, 0xc0, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x00, 0x00, 0xc0, 0xc0, 0xc0, 
0xc0, 0xc0, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0xc0, 
0xc0, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x40, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x80, 0x80, 0xc0, 0xc0, 0xe0, 0xe0, 0xf0, 0xf0, 0xf8, 0xf8, 0xfc, 0xfc, 0xfe, 0x3e, 
0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x07, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf1, 0xf1, 0xf1, 0xf1, 
0xf1, 0xf1, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0x07, 0x1f, 0x7f, 0xff, 0xff, 0xfe, 
0xf8, 0xe0, 0x80, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 
0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x1f, 0x3f, 0x7f, 0xff, 0xff, 0xfe, 
0xfc, 0xf0, 0xfc, 0xfe, 0xff, 0x7f, 0x3f, 0x1f, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x03, 0x03, 0x07, 0x0f, 0x0f, 0x1f, 0x1f, 0x3f, 0x3e, 
0x7e, 0x7c, 0xfc, 0xfc, 0xfc, 0xf0, 0x80, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 
0xff, 0xff, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x01, 0x07, 0x1f, 
0x7f, 0xff, 0xff, 0xfe, 0xf8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x0f, 0x3f, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xe0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xf0, 0xff, 0xff, 0xff, 
0xff, 0xff, 0x3f, 0x00, 0x00, 0x00, 0x80, 0xc0, 0xe0, 0xf8, 0xfc, 0xfe, 0xff, 0x7f, 0x3f, 0x1f, 
0x07, 0x0f, 0x3f, 0x7f, 0xff, 0xff, 0xfe, 0xfc, 0xf8, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x03, 0x06, 0x00, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 
0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x00, 0x03, 0x03, 0x03, 0x03, 
0x03, 0x03, 0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x01, 0x03, 0x03, 0x03, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x03, 0x03, 0x03, 0x03, 0x01, 
0x01, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x02, 0x00, 0x00, 0x00
    };
    oled_write_raw_P(crkbd_logo, sizeof(crkbd_logo));
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
    } else {
        oled_render_logo();
    }
}
#endif // OLED_DRIVER_ENABLE
