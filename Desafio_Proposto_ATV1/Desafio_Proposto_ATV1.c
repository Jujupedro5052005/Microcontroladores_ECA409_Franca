#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "ws2812.pio.h"

#define IS_RGBW false
#define NUM_PIXELS 1
#define WS2812_PIN 16

static inline uint32_t urgb_u32(uint8_t r, uint8_t g, uint8_t b) {
    return ((uint32_t)(r) << 8) |
           ((uint32_t)(g) << 16) |
           (uint32_t)(b);
}

void put_pixel(PIO pio, int sm, uint32_t pixel_grb) {
    pio_sm_put_blocking(pio, sm, pixel_grb << 8u);
}

int main() {
    stdio_init_all();

    PIO pio = pio0;
    int sm = 0;

    uint offset = pio_add_program(pio, &ws2812_program);
    ws2812_program_init(pio, sm, offset, WS2812_PIN, 800000, IS_RGBW);

    while (true) {
        put_pixel(pio, sm, urgb_u32(0, 255, 0)); // vermelho
        sleep_ms(500);

        put_pixel(pio, sm, urgb_u32(0, 0, 0));   // apagado
        sleep_ms(500);
    }
}