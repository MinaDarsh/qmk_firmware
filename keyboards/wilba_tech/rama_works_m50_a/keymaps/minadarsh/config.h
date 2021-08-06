#pragma once

// undefining original settings of main config
#undef PRODUCT
#undef RGB_BACKLIGHT_DISABLE_WHEN_USB_SUSPENDED
#undef RGB_BACKLIGHT_DISABLE_AFTER_TIMEOUT
#undef RGB_BACKLIGHT_COLOR_1
#undef RGB_BACKLIGHT_COLOR_2

#define PRODUCT Mina\x0027s M50-A

#define TAPPING_TERM 175

// disable backlight when USB suspended (PC sleep/hibernate/shutdown)
#define RGB_BACKLIGHT_DISABLE_WHEN_USB_SUSPENDED 1

// disable backlight after timeout in minutes, 0 = no timeout
#define RGB_BACKLIGHT_DISABLE_AFTER_TIMEOUT 5

// the default color1 and color2
#define RGB_BACKLIGHT_COLOR_1 { .h = 198, .s = 204 }
#define RGB_BACKLIGHT_COLOR_2 { .h = 127, .s = 154 }
