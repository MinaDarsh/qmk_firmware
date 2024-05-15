#include QMK_KEYBOARD_H
#include <stdarg.h>

enum custom_keycodes {
	MAINLYR = SAFE_RANGE,	// Main Layer Key
	MCROLYR,				// Macro Layer Key
	MC_STOP,				// EOL aid
	MC_REIN,				// Reinforcements
	MC_SPLY, 				// Resupply
	MC_SEAF,				// SEAF Artillery
	MC_ERAR, 				// Eagle Rearm
	MC_ESTR,				// Eagle Strafing Run
	MC_EAIR,				// Eagle Airstrike
	MC_ECLB,				// Eagle Cluster Bomb
	MC_ENPM,				// Eagle Napalm Airstrike
	MC_ESMK,				// Eagle Smoke Strike
	MC_E110,				// Eagle 110MM Rocket Pods
	MC_E500,				// Eagle Big KABLOOEY!
	MC_WMGN,				// Machine Gun
	MC_WAMR,				// Anti-Material Rifle
	MC_WSTW,				// Stalwart
	MC_WEAT,				// Expendable Anti-Tank
	MC_WRCR,				// Recoilles Rifle
	MC_WFLT,				// Flammenwerfer!
	MC_WATC,				// Autocannon
	MC_WRLG,				// Railgun
	MC_WSPR,				// Spear
	MC_WGRN,				// Grenade Launcher
	MC_WLSR,				// Laser Cannon
	MC_WARC,				// Arc Thrower
	MC_OGTB,				// Orbital Gatling Barrage
	MC_OABR,				// Orbital Airburst Strike
	MC_O120,				// Orbital 120MM HE Barrage
	MC_O380,				// Orbital 380MM HE Barrage
	MC_OWKB,				// Orbital Walking Barrage
	MC_OLSR,				// Orbital Lasers
	MC_ORCS,				// Orbital Railcannon Strike
	MC_OPRS,				// Orbital Precision Strike
	MC_OGAS,				// Orbital Gas Strike
	MC_OEMS,				// Orbital EMS Strike
	MC_OSMK,				// Orbital Smoke Strike
	MC_PJMP,				// Jump Pack
	MC_PSPL,				// Supply Pack
	MC_PSHG,				// Shield Generator Pack
	MC_DMIN,				// Anti-Personnel Minefield
	MC_DSGR,				// Shield Generator Relay
	MC_DSTT,				// Tesla Tower
	MC_DGTS,				// Gatling Sentry
	MC_DACS,				// Autocannon Sentry
	MC_DRKT,				// Rocket Sentry
	MC_DMTR,				// Mortar Sentry
	MC_DEMS,				// EMS Mortar Sentry
	MC_EXOS,				// Exosuit
};

enum custom_layers {
	MAIN,
	MCRO,
	FUNC
};

void process_dynamic_macro(uint16_t key, ...) {
	va_list vaList;
	va_start(vaList, key);
	uint16_t next = key;

	register_code(KC_LCTL);
	while (next != MC_STOP) {
		wait_ms(TAP_CODE_DELAY);
		tap_code(next);
		next = va_arg(vaList, uint16_t);
	}
	wait_ms(TAP_CODE_DELAY);
	unregister_code(KC_LCTL);
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[MAIN] = LAYOUT(
		KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_HOME, KC_UP,   KC_END, 
		KC_DEL,  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_LEFT, KC_DOWN, KC_RGHT,
		         KC_INS,  KC_PSCR, KC_PAUS, KC_SCRL, KC_SPC,  KC_CAPS, KC_PGUP, KC_PGDN),

	[MCRO] = LAYOUT(
		MC_REIN, MC_WATC, MC_WFLT, MC_WARC, MC_WEAT, MC_WRLG, MC_PJMP, MC_PSHG, KC_UP,   MC_EXOS,
		MC_SPLY, MC_SEAF, MC_E500, MC_OLSR, MC_ORCS, MC_DSGR, MC_DSTT, KC_LEFT, KC_DOWN, KC_RGHT,
				 MC_ERAR, MC_ESTR, MC_E110, MC_DACS, KC_SPC,  MC_DRKT, MC_DEMS, MC_DMTR),

	[FUNC] = LAYOUT(
		QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MCROLYR, XXXXXXX, 
		XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MAINLYR, XXXXXXX, 
				 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX)

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	if (record->event.pressed) {
		switch (keycode) {
		case KC_SPC:
			layer_on(FUNC);
			return true;
		case MCROLYR:
			layer_on(MCRO);
			break;
		case MAINLYR:
			layer_off(MCRO);
			break;
		case MC_REIN:
			process_dynamic_macro(KC_UP, KC_DOWN, KC_RGHT, KC_LEFT, KC_UP, MC_STOP);
			break;
		case MC_SPLY:
			process_dynamic_macro(KC_DOWN, KC_DOWN, KC_UP, KC_RGHT, MC_STOP);
			break;
		case MC_SEAF:
			process_dynamic_macro(KC_RGHT, KC_UP, KC_UP, KC_DOWN, MC_STOP);
			break;
		case MC_ERAR:
			process_dynamic_macro(KC_UP, KC_UP, KC_LEFT, KC_UP, KC_RGHT, MC_STOP);
			break;
		case MC_ESTR:
			process_dynamic_macro(KC_UP, KC_UP, KC_RGHT, MC_STOP);
			break;
		case MC_EAIR:
			process_dynamic_macro(KC_UP, KC_RGHT, KC_DOWN, KC_RGHT, MC_STOP);
			break;
		case MC_ECLB:
			process_dynamic_macro(KC_UP, KC_RGHT, KC_DOWN, KC_DOWN, KC_RGHT, MC_STOP);
			break;
		case MC_ENPM:
			process_dynamic_macro(KC_UP, KC_RGHT, KC_DOWN, KC_UP, MC_STOP);
			break;
		case MC_ESMK:
			process_dynamic_macro(KC_UP, KC_RGHT, KC_UP, KC_DOWN, MC_STOP);
			break;
		case MC_E110:
			process_dynamic_macro(KC_UP, KC_RGHT, KC_UP, KC_LEFT, MC_STOP);
			break;
		case MC_E500:
			process_dynamic_macro(KC_UP, KC_RGHT, KC_DOWN, KC_DOWN, KC_DOWN, MC_STOP);
			break;
		case MC_WMGN:
			process_dynamic_macro(KC_DOWN, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, MC_STOP);
			break;
		case MC_WAMR:
			process_dynamic_macro(KC_DOWN, KC_LEFT, KC_RGHT, KC_UP, KC_DOWN, MC_STOP);
			break;
		case MC_WSTW:
			process_dynamic_macro(KC_DOWN, KC_LEFT, KC_DOWN, KC_UP, KC_UP, KC_LEFT, MC_STOP);
			break;
		case MC_WEAT:
			process_dynamic_macro(KC_DOWN, KC_DOWN, KC_LEFT, KC_UP, KC_RGHT, MC_STOP);
			break;
		case MC_WRCR:
			process_dynamic_macro(KC_DOWN, KC_LEFT, KC_RGHT, KC_RGHT, KC_LEFT, MC_STOP);
			break;
		case MC_WFLT:
			process_dynamic_macro(KC_DOWN, KC_LEFT, KC_UP, KC_DOWN, KC_UP, MC_STOP);
			break;
		case MC_WATC:
			process_dynamic_macro(KC_DOWN, KC_LEFT, KC_DOWN, KC_UP, KC_UP, KC_RGHT, MC_STOP);
			break;
		case MC_WRLG:
			process_dynamic_macro(KC_DOWN, KC_RGHT, KC_LEFT, KC_DOWN, KC_UP, KC_LEFT, KC_RGHT, MC_STOP);
			break;
		case MC_WSPR:
			process_dynamic_macro(KC_DOWN, KC_DOWN, KC_UP, KC_DOWN, KC_DOWN, MC_STOP);
			break;
		case MC_WGRN:
			process_dynamic_macro(KC_DOWN, KC_LEFT, KC_UP, KC_LEFT, KC_DOWN, MC_STOP);
			break;
		case MC_WLSR:
			process_dynamic_macro(KC_DOWN, KC_LEFT, KC_DOWN, KC_UP, KC_LEFT, MC_STOP);
			break;
		case MC_WARC:
			process_dynamic_macro(KC_DOWN, KC_RGHT, KC_DOWN, KC_UP, KC_LEFT, KC_LEFT, MC_STOP);
			break;
		case MC_OGTB:
			process_dynamic_macro(KC_RGHT, KC_DOWN, KC_LEFT, KC_UP, KC_UP, MC_STOP);
			break;
		case MC_OABR:
			process_dynamic_macro(KC_RGHT, KC_RGHT, KC_RGHT, MC_STOP);
			break;
		case MC_O120:
			process_dynamic_macro(KC_RGHT, KC_RGHT, KC_DOWN, KC_LEFT, KC_RGHT, KC_DOWN, MC_STOP);
			break;
		case MC_O380:
			process_dynamic_macro(KC_RGHT, KC_DOWN, KC_UP, KC_UP, KC_LEFT, KC_DOWN, KC_DOWN, MC_STOP);
			break;
		case MC_OWKB:
			process_dynamic_macro(KC_RGHT, KC_DOWN, KC_RGHT, KC_DOWN, KC_RGHT, KC_DOWN, MC_STOP);
			break;
		case MC_OLSR:
			process_dynamic_macro(KC_RGHT, KC_DOWN, KC_UP, KC_RGHT, KC_DOWN, MC_STOP);
			break;
		case MC_ORCS:
			process_dynamic_macro(KC_RGHT, KC_UP, KC_DOWN, KC_DOWN, KC_RGHT, MC_STOP);
			break;
		case MC_OPRS:
			process_dynamic_macro(KC_RGHT, KC_RGHT, KC_UP, MC_STOP);
			break;
		case MC_OGAS:
			process_dynamic_macro(KC_RGHT, KC_RGHT, KC_DOWN, KC_RGHT, MC_STOP);
			break;
		case MC_OEMS:
			process_dynamic_macro(KC_RGHT, KC_RGHT, KC_LEFT, KC_DOWN, MC_STOP);
			break;
		case MC_OSMK:
			process_dynamic_macro(KC_RGHT, KC_RGHT, KC_DOWN, KC_UP, MC_STOP);
			break;
		case MC_PJMP:
			process_dynamic_macro(KC_DOWN, KC_UP, KC_UP, KC_DOWN, KC_UP, MC_STOP);
			break;
		case MC_PSPL:
			process_dynamic_macro(KC_DOWN, KC_LEFT, KC_DOWN, KC_UP, KC_UP, KC_DOWN, MC_STOP);
			break;
		case MC_PSHG:
			process_dynamic_macro(KC_DOWN, KC_UP, KC_LEFT, KC_RGHT, KC_LEFT, KC_RGHT, MC_STOP);
			break;
		case MC_DMIN:
			process_dynamic_macro(KC_DOWN, KC_LEFT, KC_UP, KC_RGHT, MC_STOP);
			break;
		case MC_DSGR:
			process_dynamic_macro(KC_DOWN, KC_DOWN, KC_LEFT, KC_RGHT, KC_LEFT, KC_RGHT, MC_STOP);
			break;
		case MC_DSTT:
			process_dynamic_macro(KC_DOWN, KC_UP, KC_RGHT, KC_UP, KC_LEFT, KC_RGHT, MC_STOP);
			break;
		case MC_DGTS:
			process_dynamic_macro(KC_DOWN, KC_UP, KC_RGHT, KC_LEFT, MC_STOP);
			break;
		case MC_DACS:
			process_dynamic_macro(KC_DOWN, KC_UP, KC_RGHT, KC_UP, KC_LEFT, KC_UP, MC_STOP);
			break;
		case MC_DRKT:
			process_dynamic_macro(KC_DOWN, KC_UP, KC_RGHT, KC_RGHT, KC_LEFT, MC_STOP);
			break;
		case MC_DMTR:
			process_dynamic_macro(KC_DOWN, KC_UP, KC_RGHT, KC_RGHT, KC_DOWN, MC_STOP);
			break;
		case MC_DEMS:
			process_dynamic_macro(KC_DOWN, KC_UP, KC_RGHT, KC_DOWN, KC_RGHT, MC_STOP);
			break;
		case MC_EXOS:
			process_dynamic_macro(KC_LEFT, KC_DOWN, KC_RGHT, KC_UP, KC_LEFT, KC_DOWN, KC_DOWN, MC_STOP);
			break;
		}
	} else {
		if (keycode == KC_SPC) {
			layer_off(FUNC);
			return true;
		}
	}
	return true;
}