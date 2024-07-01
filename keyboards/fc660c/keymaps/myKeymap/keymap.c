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
static long int r_delay = 0;
static bool shift = false;
static bool alt = false;
static bool isEnableRepeat = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
        KC_GRV, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL, KC_BSPC,     KC_DEL,
        KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,KC_BSLS,     KC_DEL,
        KC_LCTL, KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,     KC_ENT,
        KC_LSFT,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_RSFT,     KC_UP,
        KC_LCTL,KC_LGUI,KC_LALT,          LT(2,KC_SPC),                 KC_RALT,KC_RCTL,MO(1),      KC_LEFT,KC_DOWN,KC_RGHT
    ),
  [1] = LAYOUT(
        _______,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12, _______,     _______,
        _______,_______,_______,_______,_______,_______,_______,_______,KC_PSCR,KC_SCRL,KC_PAUS,_______,_______,_______,     _______,
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,     _______,
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,     _______,
        _______,_______,_______,                _______,                _______,_______,_______,       _______,_______,_______
    ),
  [2] = LAYOUT(
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,     _______,
        _______,_______,_______,_______,_______,_______,_______,KC_BSPC,KC_UP,  KC_DEL, _______,_______,_______,_______,     _______,
        _______,_______,_______,_______,_______,_______,KC_HOME,KC_LEFT,KC_DOWN,KC_RGHT,KC_END, _______,     _______,
        _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,     _______,
        _______,_______,_______,                _______,                _______,_______,_______,       _______,_______,_______
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (record->event.pressed) {
        shift = keyboard_report->mods & MOD_BIT(KC_LSFT) || keyboard_report->mods & MOD_BIT(KC_RSFT);
        alt = keyboard_report->mods & MOD_BIT(KC_LALT) || keyboard_report->mods & MOD_BIT(KC_RALT);
    }
    switch (keycode) {
        case KC_LALT:
            if (record->event.pressed) {
                register_code(keycode);
                tap_code(KC_F13);
            }
            else {
                unregister_code(keycode);
                tap_code(KC_F13);
                r_delay = 0;
            }
            return false;
        case KC_RALT:
            if (record->event.pressed) {
                register_code(keycode);
                tap_code(KC_F14);
            }
            else {
                unregister_code(keycode);
                tap_code(KC_F14);
                r_delay = 0;
            }
            return false;
        case KC_2:
            if (record->event.pressed) {
                kc2flg = true;
                if(shift){
                unregister_code(KC_LSFT);
                unregister_code(KC_RSFT);
                tap_code(KC_LBRC);
                register_code(KC_LSFT);
                return false;
                }
                return true;
            }
            else {
                kc2flg = false;
                r_delay = 0;
            }
            break;
        case KC_6:
            if (record->event.pressed && shift) {
                kc6flg = true;
                unregister_code(KC_LSFT);
                unregister_code(KC_RSFT);
                tap_code(KC_EQL);
                register_code(KC_LSFT);
                return false;
            }
            else {
                kc6flg = false;
                r_delay = 0;
            }
            break;
        case KC_7:
            if (record->event.pressed && shift) {
                tap_code(KC_6);
                return false;
            }
            else {
                kc7flg = false;
                r_delay = 0;
            }
            break;
        case KC_8:
            if (record->event.pressed && shift) {
                kc8flg = true;
                tap_code(KC_QUOT);
                return false;
            }
            else {
                kc8flg = false;
                r_delay = 0;
            }
            break;
        case KC_9:
            if (record->event.pressed && shift) {
                kc9flg = true;
                tap_code(KC_8);
                return false;
            }
            else {
                kc9flg = false;
                r_delay = 0;
            }
            break;
        case KC_0:
            if (record->event.pressed && shift) {
                kc0flg = true;
                tap_code(KC_9);
                return false;
            }
            else {
                kc0flg = false;
                r_delay = 0;
            }
            break;
        case KC_MINS:
            if (record->event.pressed && shift) {
                kcMINSflg = true;
                tap_code(KC_INT1);
                return false;
            }
            else {
                kcMINSflg = false;
                r_delay = 0;
            }
            break;
        case KC_EQL:
            if (record->event.pressed) {
                kcEQLflg = true;
                if (shift) {
                    tap_code(KC_SCLN);
                }
                else {
                    register_code(KC_LSFT);
                    tap_code(KC_MINS);
                    unregister_code(KC_LSFT);
                }
                return false;
            }
            else {
                kcEQLflg = false;
                r_delay = 0;
            }
            break;
        case KC_LBRC:
            if (record->event.pressed) {
                kcLBRCflg = true;
                tap_code(KC_RBRC);
                return false;
            }
            else {
                kcLBRCflg = false;
                r_delay = 0;
            }
            break;
        case KC_RBRC:
            if (record->event.pressed) {
                kcRBRCflg = true;
                tap_code(KC_NUHS);
                return false;
            }
            else {
                kcRBRCflg = false;
                r_delay = 0;
            }
            break;
        case KC_BSLS:
            if (record->event.pressed) {
                kcBSLSflg = true;
                if (shift) {
                    tap_code(KC_INT3);
                }
                else {
                    tap_code(KC_INT1);
                }
                return false;
            }
            else {
                kcBSLSflg = false;
                r_delay = 0;
            }
            break;
        case KC_SCLN:
            if (record->event.pressed && shift) {
                kcSCLNflg = true;
                unregister_code(KC_LSFT);
                unregister_code(KC_RSFT);
                tap_code(KC_QUOT);
                register_code(KC_LSFT);
                return false;
            }
            else {
                kcSCLNflg = false;
                r_delay = 0;
            }
            break;
        case KC_QUOT:
            if (record->event.pressed) {
                kcQUOTflg = true;
                if (shift) {
                    tap_code(KC_2);
                }
                else {
                    register_code(KC_LSFT);
                    tap_code(KC_7);
                    unregister_code(KC_LSFT);
                }
                return false;
            }
            else {
                kcQUOTflg = false;
                r_delay = 0;
            }
            break;
        case KC_GRV:
            if (record->event.pressed) {
                kcGRVflg = true;
                if (shift) {
                    tap_code(KC_EQL);
                }
                else if (alt) {
                    unregister_code(KC_LALT);
                    unregister_code(KC_RALT);
                    tap_code(KC_ESC);
                    register_code(KC_LALT);
                }
                else {
                    register_code(KC_LSFT);
                    tap_code(KC_LBRC);
                    unregister_code(KC_LSFT);
                }
                return false;
            }
            else {
                kcGRVflg = false;
                r_delay = 0;
            }
            break;
        case KC_CAPS:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                tap_code(KC_CAPS);
                unregister_code(KC_LSFT);
            }
            else {
                return false;
            }
    }
    return true;
}

void matrix_scan_user(void) {
    shift = keyboard_report->mods & MOD_BIT(KC_LSFT) || keyboard_report->mods & MOD_BIT(KC_RSFT);
    isEnableRepeat = r_delay > MY_TAPPING_TERM && r_delay % 6 == 0;
    if (kc2flg){
        if(isEnableRepeat && shift) {
            unregister_code(KC_LSFT);
            unregister_code(KC_RSFT);
            tap_code(KC_LBRC);
            register_code(KC_LSFT);
        }
        r_delay++;
    }
    else if (kc6flg) {
        if(isEnableRepeat && shift){
            unregister_code(KC_LSFT);
            unregister_code(KC_RSFT);
            tap_code(KC_EQL);
            register_code(KC_LSFT);
        }
        r_delay++;
    }
    else if (kc7flg) {
        if(isEnableRepeat && shift) {
            tap_code(KC_6);
        }
        r_delay++;
    }
    else if (kc8flg) {
        if (isEnableRepeat && shift) {
            tap_code(KC_QUOT);
            register_code(KC_LSFT);
        }
        r_delay++;
    }
    else if (kc9flg) {
        if (isEnableRepeat && shift) {
            tap_code(KC_8);
            unregister_code(KC_8);
        }
        r_delay++;
    }
    else if (kc0flg) {
        if (isEnableRepeat && shift) {
            tap_code(KC_9);
        }
        r_delay++;
    }
    else if (kcMINSflg) {
        if (isEnableRepeat && shift) {
            tap_code(KC_INT1);
        }
        r_delay++;
    }
    else if (kcEQLflg) {
        if (isEnableRepeat && shift) {
            tap_code(KC_SCLN);
        }
        r_delay++;
    }
    else if (kcLBRCflg) {
        if (isEnableRepeat && shift) {
            tap_code(KC_RBRC);
        }
        r_delay++;
    }
    else if (kcRBRCflg) {
        if (isEnableRepeat && shift) {
            tap_code(KC_NUHS);
        }
        r_delay++;
    }
    else if (kcBSLSflg) {
        if (isEnableRepeat && shift) {
            tap_code(KC_INT3);
        }
        r_delay++;
    }
    else if (kcSCLNflg) {
        if (isEnableRepeat && shift) {
            unregister_code(KC_LSFT);
            unregister_code(KC_RSFT);
            tap_code(KC_QUOT);
            register_code(KC_LSFT);
        }
        r_delay++;
    }
    else if (kcQUOTflg) {
        if (isEnableRepeat && shift) {
            tap_code(KC_2);
        }
        r_delay++;
    }
    else if (kcGRVflg) {
        if (isEnableRepeat && shift) {
            tap_code(KC_EQL);
        }
        r_delay++;
    }
}