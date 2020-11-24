#include "gh80_3000.h"

// Optional override functions below.
// You can leave any or all of these undefined.
// These are only required if you want to perform custom actions.

void matrix_init_kb(void) {
    // put your keyboard start-up code here
    // runs once when the firmware starts up

    matrix_init_user();
    led_init_ports();
}

void led_init_ports(void) {
    setPinOutput(B5);
    writePinHigh(B5);
    setPinOutput(B6);
    writePinHigh(B6);
    setPinOutput(B7);
    writePinHigh(B7);
}

bool led_update_kb(led_t led_state) {
    if(led_update_user(led_state)) {
        writePin(B5, !led_state.num_lock);
        writePin(B6, !led_state.caps_lock);
        writePin(B7, !led_state.scroll_lock);
    }

    return true;
}
