#ifndef SX1278_HW_H
#define SX1278_HW_H

#include <stdint.h>

// Define the structure for SX1278 hardware interface
typedef struct {
    int reset_pin; // GPIO pin for reset
    int dio0_pin;  // GPIO pin for DIO0
    int nss_pin;   // GPIO pin for NSS (Chip Select)
} SX1278_hw_t;

void SX1278_hw_init(SX1278_hw_t *hw);
void SX1278_hw_SetNSS(SX1278_hw_t *hw, int value);
void SX1278_hw_Reset(SX1278_hw_t *hw);
void SX1278_hw_SPICommand(SX1278_hw_t *hw, uint8_t cmd);
uint8_t SX1278_hw_SPIReadByte(SX1278_hw_t *hw);
void SX1278_hw_DelayMs(uint32_t msec);
int SX1278_hw_GetDIO0(SX1278_hw_t *hw);

#endif // SX1278_HW_H
