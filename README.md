# AECU V2.0 – Real-Time Embedded Control Unit

An advanced embedded control system developed using C and FreeRTOS.

## Project Overview

AECU is an educational automotive-inspired embedded control unit designed to explore real-time systems, sensor management and control algorithms.

## Technologies

- Embedded C
- STM32
- FreeRTOS
- STM32 HAL
- CAN Bus
- PID Control
- ADC and PWM

## System Architecture

- Sensor Acquisition
- Signal Processing
- PID Controller
- CAN Communication
- Fault Management
- Safety Management

## RTOS Tasks

| Task | Function |
|---|---|
| SensorTask | Sensor acquisition |
| ControlTask | PID and PWM control |
| CanTxTask | CAN telemetry |
| CanRxTask | CAN command reception |

## Development Status

- [x] Initial RTOS architecture
- [x] ADC sensor acquisition code
- [x] PID controller prototype
- [x] PWM control prototype
- [x] CAN communication prototype
- [ ] Hardware validation
- [ ] Watchdog integration
- [ ] Automated testing
- [ ] Runtime performance analysis

## Hardware

Target platform: STM32 NUCLEO-F401RE

## Project Status

Educational development prototype. Hardware validation and further testing are required.

## Author
OSTIM Technical University Electrical & Electronics Engineering Student Gani Kahraman Aslan 2026 Ankara Turkey
