# 📟 Microcontroladores_ECA409_Franca

Repositório de apoio para a disciplina **ECA409 – Microcontroladores**, ministrada pelo Prof. Rodrigo França.

Este projeto consiste na implementação de uma aplicação embarcada utilizando o **Raspberry Pi Pico** e o **Pico SDK (C)**, com foco em controle de temporização, comunicação UART e sistemas reativos.

---

## 🎯 Desafio Prático

Desenvolver um sistema embarcado capaz de controlar dinamicamente a frequência de piscar do LED onboard (**GPIO 25**) por meio de comandos recebidos via **UART**.

---

## 🧠 Objetivo

Implementar um sistema onde:

- O LED pisca continuamente utilizando **repeating timer**
- A frequência de piscar pode ser ajustada **em tempo real via UART**
- O sistema informa periodicamente ao usuário a frequência atual

---

## ⚙️ Requisitos Funcionais

O sistema deve:

- 📡 Utilizar **UART** para recepção de comandos
- ⏱️ Utilizar **repeating timer** para controle do LED
- 🔁 Permitir ajuste de frequência no intervalo de **1 Hz a 100 Hz**
- 🔼🔽 Incremento/decremento de **±5 Hz por comando**

### 📥 Comandos via UART

| Comando     | Ação                          |
|------------|-------------------------------|
| `ligar`     | Inicia o piscar do LED        |
| `desligar`  | Para o piscar do LED          |
| `aumentar`  | Incrementa a frequência       |
| `diminuir`  | Decrementa a frequência       |

---

## 📤 Saída do Sistema

A cada **1 segundo**, o sistema deve enviar via UART:

- Frequência atual do LED (em Hz)
- Caso esteja desligado → enviar `0 Hz`

---

## ⚠️ Restrições Técnicas

- ❌ **Proibido usar `sleep_ms`** para controle principal
- ✅ Uso obrigatório de **repeating timer**
- 📡 UART deve ser **não bloqueante**
- 🔒 O sistema deve garantir:
  - Limite mínimo: **1 Hz**
  - Limite máximo: **100 Hz**
  - Robustez contra comandos inválidos
- 🔄 Alterações de frequência devem ocorrer **sem reinicialização**

---

## 🧪 Critérios de Avaliação

Serão considerados:

- Uso correto da **UART**
- Implementação do **repeating timer**
- Parsing adequado dos comandos
- Organização e clareza do código
- Tratamento de entradas inválidas
- Controle correto dos limites de frequência
- Estrutura geral do projeto

---

## 📦 Entrega

- 👥 Trabalho em grupos de **2 a 3 alunos**
- 📄 Inserir no topo do `main.c`:
  - Nome completo
  - RA de todos os integrantes

### 📁 Submissão

- Pasta completa do projeto (VSCode)
- Projeto **compilável e funcional**
- Compactado em `.zip`

---

## 💡 Dicas e Boas Práticas

- ⚙️ Ao criar o projeto no VSCode, habilite:

- 🧩 Evite alterar diretamente a frequência do repeating timer  
→ Prefira usar um sistema interno de contagem (ticks)

- 🔁 Utilize **um único repeating timer** para:
- Controle do LED
- Envio periódico da frequência

---

## 🚫 Observações Finais

- ❗ Uso de **repeating timer é obrigatório**
- ❗ Não utilizar bibliotecas externas além do Pico SDK