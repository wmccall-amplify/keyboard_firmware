#ifndef DISABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
RGB_MATRIX_EFFECT(BAND_PINWHEEL_SAT)
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

bool BAND_PINWHEEL_SAT(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);

  HSV hsv = { rgb_matrix_config.hue, 0, rgb_matrix_config.val };
  uint8_t time = scale16by8(g_rgb_counters.tick, rgb_matrix_config.speed / 2);
  for (uint8_t i = led_min; i < led_max; i++) {
    RGB_MATRIX_TEST_LED_FLAGS();
    int16_t dx = g_led_config.point[i].x - 112;
    int16_t dy = g_led_config.point[i].y - 32;
    hsv.s = rgb_matrix_config.sat - time - atan2_8(dy, dx) * 3;
    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
  }
  return led_max < DRIVER_LED_TOTAL;
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif // DISABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
