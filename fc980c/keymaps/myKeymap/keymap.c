/*
Copyright 2017 Balz Guenat

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
#define MY_TAPPING_TERM 40

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_NUM, KC_INS, KC_PGUP, KC_PGDN,
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_DEL, KC_PSLS, KC_PAST, KC_PMNS,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_P7, KC_P8, KC_P9, KC_PPLS,
        KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_P4, KC_P5, KC_P6,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_P1, KC_P2, KC_P3, KC_PENT,
        KC_LCTL, KC_LGUI, KC_F13, LT(1,KC_SPC), KC_F14 , KC_RCTL, KC_F24, KC_LEFT, KC_DOWN, KC_RGHT, KC_P0, KC_PDOT),
    [1] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_UP, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),
    [2] = LAYOUT(
        KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_NUM, KC_INS, KC_PGUP, KC_PGDN,
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_DEL, KC_PSLS, KC_PAST, KC_PMNS,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, KC_P7, KC_P8, KC_P9, KC_PPLS,
        KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, KC_P4, KC_P5, KC_P6,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_P1, KC_P2, KC_P3, KC_PENT,
        KC_LCTL, KC_LGUI, KC_F13, KC_SPC, KC_F14 , KC_RCTL, KC_F24, KC_LEFT, KC_DOWN, KC_RGHT, KC_P0, KC_PDOT)
};

static bool kc2flg = false;
static bool kc6flg = false;
static bool kc7flg = false;
static bool kc8flg = false;
static bool kc9flg = false;
static bool kc0flg = false;
static bool kcMINSflg = false;
static bool kcEQLflg = false;
static bool kcLBRCflg = false;
static bool kcRBRCflg = false;
static bool kcBSLSflg = false;
static bool kcSCLNflg = false;
static bool kcQUOTflg = false;
static bool kcGRVflg = false;
static long int  r_delay = 0;
static bool lshift = false;
static bool rshift = false;
static bool alt = false;
static bool isPressedFn = false;
static bool isMac = false;

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    switch(keycode){
        case KC_F24:
            isPressedFn = record->event.pressed;
            return false;
        case KC_W:
            if(isPressedFn) {
                if (record->event.pressed) {
                    layer_on(0);
                    isMac = false;
                }
            }
        case KC_M:
            if(isPressedFn) {
               if (record->event.pressed) {
                    layer_on(2);
                    isMac = true;
                }
            }
    }

    if (isMac) return true;

    if (record->event.pressed) {
        lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
        rshift = keyboard_report->mods & MOD_BIT(KC_RSFT);
        alt = keyboard_report->mods & MOD_BIT(KC_LALT) || keyboard_report->mods & MOD_BIT(KC_RALT);
    }
    switch (keycode) {
        case KC_F13:
            if (record->event.pressed) {
                register_code(KC_LALT);
                register_code(keycode);
                unregister_code(keycode);
            }
            else {
                unregister_code(KC_LALT);
                register_code(KC_F13);
                unregister_code(KC_F13);
                r_delay = 0;
            }
            return false;
        case KC_F14:
            if (record->event.pressed) {
                register_code(KC_RALT);
                register_code(keycode);
                unregister_code(keycode);
            }
            else {
                unregister_code(KC_RALT);
                register_code(KC_F14);
                unregister_code(KC_F14);
                r_delay = 0;
            }
            return false;
        case KC_2:
            if (record->event.pressed) {
                kc2flg = true;
                if (lshift || rshift) {
                    if (lshift) unregister_code(KC_LSFT);
                    if (rshift) unregister_code(KC_RSFT);
                    register_code(KC_LBRC);
                    unregister_code(KC_LBRC);
                    if (lshift) register_code(KC_LSFT);
                    if (rshift) register_code(KC_RSFT);

                }
                else {
                    register_code(KC_2);
                    unregister_code(KC_2);
                }
            }
            else {
                kc2flg = false;
                r_delay = 0;
            }
            return false;
        case KC_6:
            if (record->event.pressed) {
                kc6flg = true;
                if (lshift || rshift) {
                    if (lshift) unregister_code(KC_LSFT);
                    if (rshift) unregister_code(KC_RSFT);
                    register_code(KC_EQL);
                    unregister_code(KC_EQL);
                    if (lshift) register_code(KC_LSFT);
                    if (rshift) register_code(KC_RSFT);
                }
                else {
                    register_code(KC_6);
                    unregister_code(KC_6);
                }
            }
            else {
                kc6flg = false;
                r_delay = 0;
            }
            return false;
        case KC_7:
            if (record->event.pressed) {
                kc7flg = true;
                if (lshift || rshift) {
                    if (lshift) unregister_code(KC_LSFT);
                    if (rshift) unregister_code(KC_RSFT);
                    register_code(KC_LSFT);
                    register_code(KC_6);
                    unregister_code(KC_6);
                    unregister_code(KC_LSFT);
                    if (lshift) register_code(KC_LSFT);
                    if (rshift) register_code(KC_RSFT);
                }
                else {
                    register_code(KC_7);
                    unregister_code(KC_7);
                }
            }
            else {
                kc7flg = false;
                r_delay = 0;
            }
            return false;
        case KC_8:
            if (record->event.pressed) {
                kc8flg = true;
                if (lshift || rshift) {
                    if (lshift) unregister_code(KC_LSFT);
                    if (rshift) unregister_code(KC_RSFT);
                    register_code(KC_LSFT);
                    register_code(KC_QUOT);
                    unregister_code(KC_QUOT);
                    unregister_code(KC_LSFT);
                    if (lshift) register_code(KC_LSFT);
                    if (rshift) register_code(KC_RSFT);
                }
                else {
                    register_code(KC_8);
                    unregister_code(KC_8);
                }
            }
            else {
                kc8flg = false;
                r_delay = 0;
            }
            return false;
        case KC_9:
            if (record->event.pressed) {
                kc9flg = true;
                if (lshift || rshift) {
                    if (lshift) unregister_code(KC_LSFT);
                    if (rshift) unregister_code(KC_RSFT);
                    register_code(KC_LSFT);
                    register_code(KC_8);
                    unregister_code(KC_8);
                    unregister_code(KC_LSFT);
                    if (lshift) register_code(KC_LSFT);
                    if (rshift) register_code(KC_RSFT);
                }
                else {
                    register_code(KC_9);
                    unregister_code(KC_9);
                }
            }
            else {
                kc9flg = false;
                r_delay = 0;
            }
            return false;
        case KC_0:
            if (record->event.pressed) {
                kc0flg = true;
                if (lshift || rshift) {
                    if (lshift) unregister_code(KC_LSFT);
                    if (rshift) unregister_code(KC_RSFT);
                    register_code(KC_LSFT);
                    register_code(KC_9);
                    unregister_code(KC_9);
                    unregister_code(KC_LSFT);
                    if (lshift) register_code(KC_LSFT);
                    if (rshift) register_code(KC_RSFT);
                }
                else {
                    register_code(KC_0);
                    unregister_code(KC_0);
                }
            }
            else {
                kc0flg = false;
                r_delay = 0;
            }
            return false;
        case KC_MINS:
            if (record->event.pressed) {
                kcMINSflg = true;
                if (lshift || rshift) {
                    if (lshift) unregister_code(KC_LSFT);
                    if (rshift) unregister_code(KC_RSFT);
                    register_code(KC_LSFT);
                    register_code(KC_INT1);
                    unregister_code(KC_INT1);
                    unregister_code(KC_LSFT);
                    if (lshift) register_code(KC_LSFT);
                    if (rshift) register_code(KC_RSFT);
                }
                else {
                    register_code(KC_MINS);
                    unregister_code(KC_MINS);
                }
            }
            else {
                kcMINSflg = false;
                r_delay = 0;
            }
            return false;
        case KC_EQL:
            if (record->event.pressed) {
                kcEQLflg = true;
                if (lshift || rshift) {
                    if (lshift) unregister_code(KC_LSFT);
                    if (rshift) unregister_code(KC_RSFT);
                    register_code(KC_LSFT);
                    register_code(KC_SCLN);
                    unregister_code(KC_SCLN);
                    unregister_code(KC_LSFT);
                    if (lshift) register_code(KC_LSFT);
                    if (rshift) register_code(KC_RSFT);
                }
                else {
                    register_code(KC_LSFT);
                    register_code(KC_MINS);
                    unregister_code(KC_MINS);
                    unregister_code(KC_LSFT);
                }
            }
            else {
                kcEQLflg = false;
                r_delay = 0;
            }
            return false;
        case KC_LBRC:
            if (record->event.pressed) {
                kcLBRCflg = true;
                if (lshift || rshift) {
                    if (lshift) unregister_code(KC_LSFT);
                    if (rshift) unregister_code(KC_RSFT);
                    register_code(KC_LSFT);
                    register_code(KC_RBRC);
                    unregister_code(KC_RBRC);
                    unregister_code(KC_LSFT);
                    if (lshift) register_code(KC_LSFT);
                    if (rshift) register_code(KC_RSFT);
                }
                else {
                    register_code(KC_RBRC);
                    unregister_code(KC_RBRC);
                }
            }
            else {
                kcLBRCflg = false;
                r_delay = 0;
            }
            return false;
        case KC_RBRC:
            if (record->event.pressed) {
                kcRBRCflg = true;
                if (lshift || rshift) {
                    if (lshift) unregister_code(KC_LSFT);
                    if (rshift) unregister_code(KC_RSFT);
                    register_code(KC_LSFT);
                    register_code(KC_NUHS);
                    unregister_code(KC_NUHS);
                    unregister_code(KC_LSFT);
                    if (lshift) register_code(KC_LSFT);
                    if (rshift) register_code(KC_RSFT);
                }
                else {
                    register_code(KC_NUHS);
                    unregister_code(KC_NUHS);
                }
            }
            else {
                kcRBRCflg = false;
                r_delay = 0;
            }
            return false;
        case KC_BSLS:
            if (record->event.pressed) {
                kcBSLSflg = true;
                if (lshift || rshift) {
                    if (lshift) unregister_code(KC_LSFT);
                    if (rshift) unregister_code(KC_RSFT);
                    register_code(KC_LSFT);
                    register_code(KC_INT3);
                    unregister_code(KC_INT3);
                    unregister_code(KC_LSFT);
                    if (lshift) register_code(KC_LSFT);
                    if (rshift) register_code(KC_RSFT);
                }
                else {
                    register_code(KC_INT1);
                    unregister_code(KC_INT1);
                }
            }
            else {
                kcBSLSflg = false;
                r_delay = 0;
            }
            return false;
        case KC_SCLN:
            if (record->event.pressed) {
                kcSCLNflg = true;
                if (lshift || rshift) {
                    if (lshift) unregister_code(KC_LSFT);
                    if (rshift) unregister_code(KC_RSFT);
                    register_code(KC_QUOT);
                    unregister_code(KC_QUOT);
                    if (lshift) register_code(KC_LSFT);
                    if (rshift) register_code(KC_RSFT);
                }
                else {
                    register_code(KC_SCLN);
                    unregister_code(KC_SCLN);
                }
            }
            else {
                kcSCLNflg = false;
                r_delay = 0;
            }
            return false;
        case KC_QUOT:
            if (record->event.pressed) {
                kcQUOTflg = true;
                if (lshift || rshift) {
                    if (lshift) unregister_code(KC_LSFT);
                    if (rshift) unregister_code(KC_RSFT);
                    register_code(KC_LSFT);
                    register_code(KC_2);
                    unregister_code(KC_2);
                    unregister_code(KC_LSFT);
                    if (lshift) register_code(KC_LSFT);
                    if (rshift) register_code(KC_RSFT);
                }
                else {
                    register_code(KC_LSFT);
                    register_code(KC_7);
                    unregister_code(KC_7);
                    unregister_code(KC_LSFT);
                }
            }
            else {
                kcQUOTflg = false;
                r_delay = 0;
            }
            return false;
        case KC_GRV:
            if (record->event.pressed) {
                kcGRVflg = true;
                if (lshift || rshift) {
                    if (lshift) unregister_code(KC_LSFT);
                    if (rshift) unregister_code(KC_RSFT);
                    register_code(KC_LSFT);
                    register_code(KC_EQL);
                    unregister_code(KC_EQL);
                    unregister_code(KC_LSFT);
                    if (lshift) register_code(KC_LSFT);
                    if (rshift) register_code(KC_RSFT);
                }
                else if (alt) {
                        unregister_code(KC_LALT);
                        unregister_code(KC_RALT);
                        tap_code(KC_ESC);
                        register_code(KC_LALT);
                }
                else {
                    register_code(KC_LSFT);
                    register_code(KC_LBRC);
                    unregister_code(KC_LBRC);
                    unregister_code(KC_LSFT);
                }
            }
            else {
                kcGRVflg = false;
                r_delay = 0;
            }
            return false;
        case KC_CAPS:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_CAPS);
                unregister_code(KC_CAPS);
                unregister_code(KC_LSFT);
            }
            return false;
    }
    return true;
}

void matrix_scan_user(void) {
    if(isMac) return;
    
    if (kc2flg) {
        if (r_delay > MY_TAPPING_TERM && r_delay % 2 == 0) {
            lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
            rshift = keyboard_report->mods & MOD_BIT(KC_RSFT);
            if (lshift || rshift) {
                if (lshift) unregister_code(KC_LSFT);
                if (rshift) unregister_code(KC_RSFT);
                register_code(KC_LBRC);
                unregister_code(KC_LBRC);
                if (lshift) register_code(KC_LSFT);
                if (rshift) register_code(KC_RSFT);
            }
            else {
                register_code(KC_2);
                unregister_code(KC_2);
            }
        }
        r_delay++;
    }
    else if (kc6flg) {
        if (r_delay > MY_TAPPING_TERM && r_delay % 2 == 0) {
            lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
            rshift = keyboard_report->mods & MOD_BIT(KC_RSFT);
            if (lshift || rshift) {
                if (lshift) unregister_code(KC_LSFT);
                if (rshift) unregister_code(KC_RSFT);
                register_code(KC_EQL);
                unregister_code(KC_EQL);
                if (lshift) register_code(KC_LSFT);
                if (rshift) register_code(KC_RSFT);
            }
            else {
                register_code(KC_6);
                unregister_code(KC_6);
            }
        }
        r_delay++;
    }
    else if (kc7flg) {
        if (r_delay > MY_TAPPING_TERM && r_delay % 2 == 0) {
            lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
            rshift = keyboard_report->mods & MOD_BIT(KC_RSFT);
            if (lshift || rshift) {
                if (lshift) unregister_code(KC_LSFT);
                if (rshift) unregister_code(KC_RSFT);
                register_code(KC_LSFT);
                register_code(KC_6);
                unregister_code(KC_6);
                unregister_code(KC_LSFT);
                if (lshift) register_code(KC_LSFT);
                if (rshift) register_code(KC_RSFT);
            }
            else {
                register_code(KC_7);
                unregister_code(KC_7);
            }
        }
        r_delay++;
    }
    else if (kc8flg) {
        if (r_delay > MY_TAPPING_TERM && r_delay % 2 == 0) {
            lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
            rshift = keyboard_report->mods & MOD_BIT(KC_RSFT);
            if (lshift || rshift) {
                if (lshift) unregister_code(KC_LSFT);
                if (rshift) unregister_code(KC_RSFT);
                register_code(KC_LSFT);
                register_code(KC_QUOT);
                unregister_code(KC_QUOT);
                unregister_code(KC_LSFT);
                if (lshift) register_code(KC_LSFT);
                if (rshift) register_code(KC_RSFT);
            }
            else {
                register_code(KC_8);
                unregister_code(KC_8);
            }
        }
        r_delay++;
    }
    else if (kc9flg) {
        if (r_delay > MY_TAPPING_TERM && r_delay % 2 == 0) {
            lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
            rshift = keyboard_report->mods & MOD_BIT(KC_RSFT);
            if (lshift || rshift) {
                if (lshift) unregister_code(KC_LSFT);
                if (rshift) unregister_code(KC_RSFT);
                register_code(KC_LSFT);
                register_code(KC_8);
                unregister_code(KC_8);
                unregister_code(KC_LSFT);
                if (lshift) register_code(KC_LSFT);
                if (rshift) register_code(KC_RSFT);
            }
            else {
                register_code(KC_9);
                unregister_code(KC_9);
            }
        }
        r_delay++;
    }
    else if (kc0flg) {
        if (r_delay > MY_TAPPING_TERM && r_delay % 2 == 0) {
            lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
            rshift = keyboard_report->mods & MOD_BIT(KC_RSFT);
            if (lshift || rshift) {
                if (lshift) unregister_code(KC_LSFT);
                if (rshift) unregister_code(KC_RSFT);
                register_code(KC_LSFT);
                register_code(KC_9);
                unregister_code(KC_9);
                unregister_code(KC_LSFT);
                if (lshift) register_code(KC_LSFT);
                if (rshift) register_code(KC_RSFT);
            }
            else {
                register_code(KC_0);
                unregister_code(KC_0);
            }
        }
        r_delay++;
    }
    else if (kcMINSflg) {
        if (r_delay > MY_TAPPING_TERM && r_delay % 2 == 0) {
            lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
            rshift = keyboard_report->mods & MOD_BIT(KC_RSFT);
            if (lshift || rshift) {
                if (lshift) unregister_code(KC_LSFT);
                if (rshift) unregister_code(KC_RSFT);
                register_code(KC_LSFT);
                register_code(KC_INT1);
                unregister_code(KC_INT1);
                unregister_code(KC_LSFT);
                if (lshift) register_code(KC_LSFT);
                if (rshift) register_code(KC_RSFT);
            }
            else {
                register_code(KC_MINS);
                unregister_code(KC_MINS);
            }
        }
        r_delay++;
    }
    else if (kcEQLflg) {
        if (r_delay > MY_TAPPING_TERM && r_delay % 2 == 0) {
            lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
            rshift = keyboard_report->mods & MOD_BIT(KC_RSFT);
            if (lshift || rshift) {
                if (lshift) unregister_code(KC_LSFT);
                if (rshift) unregister_code(KC_RSFT);
                register_code(KC_LSFT);
                register_code(KC_SCLN);
                unregister_code(KC_SCLN);
                unregister_code(KC_LSFT);
                if (lshift) register_code(KC_LSFT);
                if (rshift) register_code(KC_RSFT);
            }
            else {
                register_code(KC_LSFT);
                register_code(KC_MINS);
                unregister_code(KC_MINS);
                unregister_code(KC_LSFT);
            }
        }
        r_delay++;
    }
    else if (kcLBRCflg) {
        if (r_delay > MY_TAPPING_TERM && r_delay % 2 == 0) {
            lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
            rshift = keyboard_report->mods & MOD_BIT(KC_RSFT);
            if (lshift || rshift) {
                if (lshift) unregister_code(KC_LSFT);
                if (rshift) unregister_code(KC_RSFT);
                register_code(KC_LSFT);
                register_code(KC_RBRC);
                unregister_code(KC_RBRC);
                unregister_code(KC_LSFT);
                if (lshift) register_code(KC_LSFT);
                if (rshift) register_code(KC_RSFT);
            }
            else {
                register_code(KC_RBRC);
                unregister_code(KC_RBRC);
            }
        }
        r_delay++;
    }
    else if (kcRBRCflg) {
        if (r_delay > MY_TAPPING_TERM && r_delay % 2 == 0) {
            lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
            rshift = keyboard_report->mods & MOD_BIT(KC_RSFT);
            if (lshift || rshift) {
                if (lshift) unregister_code(KC_LSFT);
                if (rshift) unregister_code(KC_RSFT);
                register_code(KC_LSFT);
                register_code(KC_NUHS);
                unregister_code(KC_NUHS);
                unregister_code(KC_LSFT);
                if (lshift) register_code(KC_LSFT);
                if (rshift) register_code(KC_RSFT);
            }
            else {
                register_code(KC_NUHS);
                unregister_code(KC_NUHS);
            }
        }
        r_delay++;
    }
    else if (kcBSLSflg) {
        if (r_delay > MY_TAPPING_TERM && r_delay % 2 == 0) {
            lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
            rshift = keyboard_report->mods & MOD_BIT(KC_RSFT);
            if (lshift || rshift) {
                if (lshift) unregister_code(KC_LSFT);
                if (rshift) unregister_code(KC_RSFT);
                register_code(KC_LSFT);
                register_code(KC_INT3);
                unregister_code(KC_INT3);
                unregister_code(KC_LSFT);
                if (lshift) register_code(KC_LSFT);
                if (rshift) register_code(KC_RSFT);
            }
            else {
                register_code(KC_INT1);
                unregister_code(KC_INT1);
            }
        }
        r_delay++;
    }
    else if (kcSCLNflg) {
        if (r_delay > MY_TAPPING_TERM && r_delay % 2 == 0) {
            lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
            rshift = keyboard_report->mods & MOD_BIT(KC_RSFT);
            if (lshift || rshift) {
                if (lshift) unregister_code(KC_LSFT);
                if (rshift) unregister_code(KC_RSFT);
                register_code(KC_QUOT);
                unregister_code(KC_QUOT);
                if (lshift) register_code(KC_LSFT);
                if (rshift) register_code(KC_RSFT);
            }
            else {
                register_code(KC_SCLN);
                unregister_code(KC_SCLN);
            }
        }
        r_delay++;
    }
    else if (kcQUOTflg) {
        if (r_delay > MY_TAPPING_TERM && r_delay % 2 == 0) {
            lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
            rshift = keyboard_report->mods & MOD_BIT(KC_RSFT);
            if (lshift || rshift) {
                if (lshift) unregister_code(KC_LSFT);
                if (rshift) unregister_code(KC_RSFT);
                register_code(KC_LSFT);
                register_code(KC_2);
                unregister_code(KC_2);
                unregister_code(KC_LSFT);
                if (lshift) register_code(KC_LSFT);
                if (rshift) register_code(KC_RSFT);
            }
            else {
                register_code(KC_LSFT);
                register_code(KC_7);
                unregister_code(KC_7);
                unregister_code(KC_LSFT);
            }
        }
        r_delay++;
    }
    else if (kcGRVflg) {
        if (r_delay > MY_TAPPING_TERM && r_delay % 2 == 0) {
            lshift = keyboard_report->mods & MOD_BIT(KC_LSFT);
            rshift = keyboard_report->mods & MOD_BIT(KC_RSFT);
            if (lshift || rshift) {
                if (lshift) unregister_code(KC_LSFT);
                if (rshift) unregister_code(KC_RSFT);
                register_code(KC_LSFT);
                register_code(KC_EQL);
                unregister_code(KC_EQL);
                unregister_code(KC_LSFT);
                if (lshift) register_code(KC_LSFT);
                if (rshift) register_code(KC_RSFT);
            }
            else {
                register_code(KC_LSFT);
                register_code(KC_LBRC);
                unregister_code(KC_LBRC);
                unregister_code(KC_LSFT);
            }
        }
        r_delay++;
    }
}
