// Copyright 2021 a (@trwnh on Github)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "rgb_matrix_map.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     Prt           Rotary(Mute)
//      ~        1        2        3        4        5        6        7        8        9        0         -       (=)	     BackSpc           Del
//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]        \                 PgUp
//      Caps     A        S        D        F        G        H        J        K        L        ;        "                 Enter             PgDn
//      Sh_L              Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       End
//      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right


    // The FN key by default maps to a momentary toggle to layer 1 to provide access to the QK_BOOT key (to put the board into bootloader mode). Without
    // this mapping, you have to open the case to hit the button on the bottom of the PCB (near the USB cable attachment) while plugging in the USB
    // cable to get the board into bootloader mode - definitely not fun when you're working on your QMK builds. Remove this and put it back to KC_RGUI
    // if that's your preference.
    //
    // To put the keyboard in bootloader mode, use FN+backslash. If you accidentally put it into bootloader, you can just unplug the USB cable and
    // it'll be back to normal when you plug it back in.
    //
    // This keyboard defaults to 6KRO instead of NKRO for compatibility reasons (some KVMs and BIOSes are incompatible with NKRO).
    // Since this is, among other things, a "gaming" keyboard, a key combination to enable NKRO on the fly is provided for convenience.
    // Press Fn+N to toggle between 6KRO and NKRO. This setting is persisted to the EEPROM and thus persists between restarts.
    [0] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR,          KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGDN,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(1),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [1] = LAYOUT(
        _______, KC_MYCM, KC_WHOM, KC_CALC, KC_MSEL, KC_MPRV, KC_MNXT, KC_MPLY, KC_MSTP, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______,          _______,
        _______, RGB_TOG, RGB_MOD, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, RGB_VAI, RGB_SAI, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_BOOT,            _______,
        _______, RGB_VAD, RGB_SAD, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          RGB_HUI, RGB_HUD, _______, _______, _______, NK_TOGG, _______, _______, _______, _______,          _______, RGB_MOD, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, RGB_SPD, RGB_RMOD, RGB_SPI
    ),
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] =  { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [1] =  { ENCODER_CCW_CW(KC_BRIGHTNESS_DOWN, KC_BRIGHTNESS_UP) },
};
#endif
// clang-format on

// RGB led number layout, function of the key

//  67, led 01   0, ESC    6, F1      12, F2      18, F3   23, F4   28, F5      34, F6   39, F7   44, F8      50, F9   56, F10   61, F11    66, F12    69, Prt       Rotary(Mute)   68, led 12
//  70, led 02   1, ~      7, 1       13, 2       19, 3    24, 4    29, 5       35, 6    40, 7    45, 8       51, 9    57, 0     62, -_     78, (=+)   85, BackSpc   72, Home       71, led 13
//  73, led 03   2, Tab    8, Q       14, W       20. E    25, R    30, T       36, Y    41, U    46, I       52, O    58, P     63, [{     89, ]}     93, \|        75, PgUp       74, led 14
//  76, led 04   3, Caps   9, A       15, S       21, D    26, F    31, G       37, H    42, J    47, K       53, L    59, ;:    64, '"                96, Enter     86, PgDn       77, led 15
//  80, led 05   4, Sh_L   10, Z      16, X       22, C    27, V    32, B       38, N    43, M    48, ,<      54, .<   60, /?               90, Sh_R   94, Up        82, End        81, led 16
//  83, led 06   5, Ct_L   11,Win_L   17, Alt_L                     33, SPACE                     49, Alt_R   55, FN             65, Ct_R   95, Left   97, Down      79, Right      84, led 17
//  87, led 07                                                                                                                                                                      88, led 18
//  91, led 08   

#ifdef RGB_MATRIX_ENABLE
	static void set_rgb_caps_leds_on(void);
	static void set_rgb_caps_leds_off(void);

	static void set_rgb_caps_leds_on() 
	{
		// Set sides and capslock to red
		rgb_matrix_set_color( 3, 255, 255, 255);	// Caps
		
		// arrow keys
		rgb_matrix_set_color( 94, 255, 255, 255);	// Up
		rgb_matrix_set_color( 97, 255, 255, 255);	// Down
		rgb_matrix_set_color( 95, 255, 255, 255);	// Left
		rgb_matrix_set_color( 79, 255, 255, 255);	// Right

		// Left side rainbow
		rgb_matrix_set_color(67, 255, 255, 255);	// Left LED 01
		rgb_matrix_set_color(70, 255, 255, 255);	// Left LED 02
		rgb_matrix_set_color(73, 255, 255, 255);	// Left LED 03
		rgb_matrix_set_color(76, 255, 255, 255);	// Left LED 04
		rgb_matrix_set_color(80, 255, 255, 255);	// Left LED 05
		rgb_matrix_set_color(83, 255, 255, 255);	// Left LED 06
		rgb_matrix_set_color(87, 255, 255, 255);	// Left LED 07
		rgb_matrix_set_color(91, 255, 255, 255);	// Left LED 08

		// Right side rainbow
		rgb_matrix_set_color(68, 255, 255, 255);	// Right LED 12
		rgb_matrix_set_color(71, 255, 255, 255);	// Right LED 13
		rgb_matrix_set_color(74, 255, 255, 255);	// Right LED 14
		rgb_matrix_set_color(77, 255, 255, 255);	// Right LED 15
		rgb_matrix_set_color(81, 255, 255, 255);	// Right LED 16
		rgb_matrix_set_color(84, 255, 255, 255);	// Right LED 17
		rgb_matrix_set_color(88, 255, 255, 255);	// Right LED 18
		rgb_matrix_set_color(92, 255, 255, 255);	// Right LED 19
	}

	static void set_rgb_caps_leds_off() 
	{
		// Set sides and capslock to black
		rgb_matrix_set_color( 3, 0, 0, 0);	// Caps
		
		// arrow keys
		rgb_matrix_set_color( 94, 0,   0,   0);	// Up
		rgb_matrix_set_color( 97, 0,   0,   0);	// Down
		rgb_matrix_set_color( 95, 0,   0,   0);	// Left
		rgb_matrix_set_color( 79, 0,   0,   0);	// Right

		// Left side rainbow
		rgb_matrix_set_color(67, 0,   0,   0);	// Left LED 01
		rgb_matrix_set_color(70, 0,   0,   0);	// Left LED 02
		rgb_matrix_set_color(73, 0,   0,   0);	// Left LED 03
		rgb_matrix_set_color(76, 0,   0,   0);	// Left LED 04
		rgb_matrix_set_color(80, 0,   0,   0);	// Left LED 05
		rgb_matrix_set_color(83, 0,   0,   0);	// Left LED 06
		rgb_matrix_set_color(87, 0,   0,   0);	// Left LED 07
		rgb_matrix_set_color(91, 0,   0,   0);	// Left LED 08

		// Right side rainbow
		rgb_matrix_set_color(68, 0,   0,   0);	// Right LED 12
		rgb_matrix_set_color(71, 0,   0,   0);	// Right LED 13
		rgb_matrix_set_color(74, 0,   0,   0);	// Right LED 14
		rgb_matrix_set_color(77, 0,   0,   0);	// Right LED 15
		rgb_matrix_set_color(81, 0,   0,   0);	// Right LED 16
		rgb_matrix_set_color(84, 0,   0,   0);	// Right LED 17
		rgb_matrix_set_color(88, 0,   0,   0);	// Right LED 18
		rgb_matrix_set_color(92, 0,   0,   0);	// Right LED 19
	}

	void rgb_matrix_indicators_user(void) 
	{
		if (host_keyboard_led_state().caps_lock) 
		{
			set_rgb_caps_leds_on();
		} 
		else 
		{
			if (rgb_matrix_get_flags() == LED_FLAG_NONE)
			{
				set_rgb_caps_leds_off();
			}
		}
	}

#endif // RGB_MATRIX_ENABLE