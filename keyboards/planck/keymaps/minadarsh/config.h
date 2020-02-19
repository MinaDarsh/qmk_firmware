#pragma once

#ifdef AUDIO_ENABLE
  #define STARTUP_SONG SONG(PLANCK_SOUND)
#endif

#ifdef MOUSEKEY_ENABLE
  #define MK_3_SPEED
  #define MK_C_OFFSET_0 1
  #define MK_C_INTERVAL_0 32
  #define MK_C_OFFSET_1 4
  #define MK_C_INTERVAL_1 16
  #define MK_C_OFFSET_2 32
  #define MK_C_INTERVAL_2 16
  #define MK_W_OFFSET_0 1
  #define MK_W_INTERVAL_0 360
  #define MK_W_OFFSET_1 1
  #define MK_W_INTERVAL_1 120
  #define MK_W_OFFSET_2 1
  #define MK_W_INTERVAL_2 20
#endif
