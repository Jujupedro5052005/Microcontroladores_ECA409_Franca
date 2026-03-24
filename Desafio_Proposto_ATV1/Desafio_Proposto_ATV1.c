#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/time.h" // me da acesso as funcoes de tempo do SDK

#define LED_PIN 25

// funcao chamada pelo repeating timer
bool blink_callback(struct repeating_timer *t){
    // variavel static retem o valor dela entre chamadas da funcao!!! (bem util)
    // como se fosse uma variavel global que so esta funcao pode acessar 
    // esse igual a false so funciona na criacao
    // em outras chamadas, ele apenas pega o valor anterior que ja estava
    static bool led_state = false; 
    
    led_state = !led_state;
    gpio_put(LED_PIN, led_state);

    return true;
}

int main()
{
    stdio_init_all();

    // inicializa gpio
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    // crio um timer de repeticao
    struct repeating_timer timer;

    // cria uma funcao repetitiva em cima do timer criado
    // passo o delay em ms, funcao a ser rodada no callback, contexto de 
    // identificador (usamos NULL) e o endereco do timer
    // dica: CTRL+click tem uma boa documentacao
    add_repeating_timer_ms(1000, blink_callback, NULL, &timer);

    while (true) {
        tight_loop_contents();
    }
    
    return 0;
}
