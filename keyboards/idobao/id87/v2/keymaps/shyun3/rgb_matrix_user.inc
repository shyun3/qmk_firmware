RGB_MATRIX_EFFECT(underglow_only)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static bool underglow_only(effect_params_t* params) {
    const RGB rgb = hsv_to_rgb(rgb_matrix_get_hsv());

    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    for (int i = led_min; i <= led_max; ++i) {
        RGB_MATRIX_TEST_LED_FLAGS();
        if (HAS_FLAGS(g_led_config.flags[i], LED_FLAG_UNDERGLOW)) {
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        } else {
            rgb_matrix_set_color(i, 0, 0, 0);
        }
    }

    return rgb_matrix_check_finished_leds(led_max);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS

// vim: ft=c
