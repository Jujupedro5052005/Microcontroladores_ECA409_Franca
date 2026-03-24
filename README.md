# Microcontroladores_ECA409_Franca
Repositorio de teste para aula ECA409, para estudo de Microcontroladores, do professor rodrigo França

## Desafio pratico proposto

Desenvolver uma aplicação embarcada utilizando o Raspberry Pi Pico e o Pico SDK, na linguagem C, que permita o controle dinâmico da frequência de piscar do LED onboard (GPIO 25) por meio de comandos recebidos via UART.

Objetivo
Implementar um sistema em que o LED onboard pisque continuamente utilizando repeating timer, com a frequência de oscilação sendo ajustada em tempo real a partir de comandos enviados pela interface UART.

Além disso, o sistema deve informar periodicamente ao usuário a frequência atual de operação.

Requisitos Funcionais
O sistema deve:

Utilizar UART para recepção de comandos.
Utilizar repeating timer para controle do piscar do LED.
Permitir controle da frequência de piscar no intervalo de:
1 Hz até 100 Hz
Trabalhar com incremento/decremento de:
5 Hz por comando
Interpretar os seguintes comandos recebidos via UART:
"ligar" → inicia o piscar do LED
"desligar" → interrompe o piscar do LED
"aumentar" → incrementa a frequência
"diminuir" → decrementa a frequência
A cada 1 segundo, enviar ao usuário (via UART) a:
Frequência atual do LED, em Hz
Se estiver desligado, enviar 0 Hz
Restrições Técnicas
O controle do LED deve ser feito exclusivamente via timer repetitivo (não utilizar sleep_ms para controle principal).
A comunicação UART deve ser tratada de forma não bloqueante.
A aplicação deve garantir:
Limites mínimo e máximo de frequência
Estabilidade do sistema mesmo com comandos inválidos
O sistema deve ser capaz de atualizar a frequência em tempo de execução, sem reinicialização.
Critérios de Avaliação
Serão avaliados:

Correta utilização da UART
Implementação adequada do repeating timer
Tratamento de entrada de dados (parsing de comandos)
Organização e clareza do código
Robustez contra entradas inválidas
Controle correto dos limites de frequência
Estrutura geral do projeto
Entrega
Os alunos devem:

O trabalho pode ser realizado em grupos de 2 a 3 alunos.
Inserir no código (em comentário no topo do main.c ou equivalente):
Nome completo e RA de todos os integrantes do grupo
Entregar:
Toda a pasta do projeto do VSCode
O projeto deve estar funcional e compilável
Compactar a pasta em um arquivo .zip
Observações e Sugestões
Lembrem-se de iniciar o projeto do Pico no VSCode com a opção "Console over USB (disables other USB use)" habilitada, para possibilitar a comunicação via UART pelo USB.
Sugestão: em vez de alterar diretamente a frequência do repeating timer, considerem implementar um mecanismo interno de contagem de tempo (contador/ticks) dentro do callback para gerenciar a frequência do LED.
Tentem utilizar o mesmo repeating timer tanto para:
Controle do piscar do LED
Envio da frequência atual a cada 1 segundo
Observações Finais
Não serão aceitas soluções que não utilizem timer repetitivo.
Não será permitido o uso de bibliotecas externas além do Pico SDK.
