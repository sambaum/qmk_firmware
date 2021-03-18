RGB_MATRIX_EFFECT(custom_blender)
RGB_MATRIX_EFFECT(custom_dark)


#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static bool custom_dark(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);
  rgb_matrix_set_color_all(0x00, 0x00, 0x00);
  return led_max < DRIVER_LED_TOTAL;
}

static bool custom_blender(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);
  #define blender_color 0, 42, 66
  rgb_matrix_set_color_all(0x00, 0x00, 0x00);
  rgb_matrix_set_color(36, blender_color); // K - Soft cut
  rgb_matrix_set_color(30, blender_color); // S - Snap strips
  rgb_matrix_set_color(47, blender_color); // B - Selection box
  rgb_matrix_set_color(33, blender_color); // G - Grab strips
  rgb_matrix_set_color(1, blender_color); // 1 - Select left handle
  rgb_matrix_set_color(2, blender_color); // 2 - Select right handle
  return led_max < DRIVER_LED_TOTAL;
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
