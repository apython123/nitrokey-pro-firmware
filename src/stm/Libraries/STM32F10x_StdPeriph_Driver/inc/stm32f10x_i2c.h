/*
 * Author: Copyright (C) STMicroelectronics
 *                                              MCD Application Team            Date:   04/06/2009
 *
 * This file is part of Nitrokey.
 *
 * Nitrokey is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * Nitrokey is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Nitrokey. If not, see <http://www.gnu.org/licenses/>.
 */

/* Define to prevent recursive inclusion ------------------------------------- */
#ifndef __STM32F10x_I2C_H
#define __STM32F10x_I2C_H

/* Includes ------------------------------------------------------------------ */
#include "stm32f10x.h"

/** @addtogroup StdPeriph_Driver
  * @{
  */

/** @addtogroup I2C
  * @{
  */

/** @defgroup I2C_Exported_Types
  * @{
  */

/**
  * @brief  I2C Init structure definition
  */

typedef struct
{
    uint16_t I2C_Mode;
    uint16_t I2C_DutyCycle;
    uint16_t I2C_OwnAddress1;
    uint16_t I2C_Ack;
    uint16_t I2C_AcknowledgedAddress;
    uint32_t I2C_ClockSpeed;
} I2C_InitTypeDef;

/**
  * @}
  */


/** @defgroup I2C_Exported_Constants
  * @{
  */

#define IS_I2C_ALL_PERIPH(PERIPH) (((*(uint32_t*)&(PERIPH)) == I2C1_BASE) || \
                                   ((*(uint32_t*)&(PERIPH)) == I2C2_BASE))
/** @defgroup I2C_modes
  * @{
  */

#define I2C_Mode_I2C                    ((uint16_t)0x0000)
#define I2C_Mode_SMBusDevice            ((uint16_t)0x0002)
#define I2C_Mode_SMBusHost              ((uint16_t)0x000A)
#define IS_I2C_MODE(MODE) (((MODE) == I2C_Mode_I2C) || \
                           ((MODE) == I2C_Mode_SMBusDevice) || \
                           ((MODE) == I2C_Mode_SMBusHost))
/**
  * @}
  */

/** @defgroup I2C_duty_cycle_in_fast_mode
  * @{
  */

#define I2C_DutyCycle_16_9              ((uint16_t)0x4000)
#define I2C_DutyCycle_2                 ((uint16_t)0xBFFF)
#define IS_I2C_DUTY_CYCLE(CYCLE) (((CYCLE) == I2C_DutyCycle_16_9) || \
                                  ((CYCLE) == I2C_DutyCycle_2))
/**
  * @}
  */

/** @defgroup I2C_cknowledgementy
  * @{
  */

#define I2C_Ack_Enable                  ((uint16_t)0x0400)
#define I2C_Ack_Disable                 ((uint16_t)0x0000)
#define IS_I2C_ACK_STATE(STATE) (((STATE) == I2C_Ack_Enable) || \
                                 ((STATE) == I2C_Ack_Disable))
/**
  * @}
  */

/** @defgroup I2C_transfer_direction
  * @{
  */

#define  I2C_Direction_Transmitter      ((uint8_t)0x00)
#define  I2C_Direction_Receiver         ((uint8_t)0x01)
#define IS_I2C_DIRECTION(DIRECTION) (((DIRECTION) == I2C_Direction_Transmitter) || \
                                     ((DIRECTION) == I2C_Direction_Receiver))
/**
  * @}
  */

/** @defgroup I2C_acknowledged_address_defines
  * @{
  */

#define I2C_AcknowledgedAddress_7bit    ((uint16_t)0x4000)
#define I2C_AcknowledgedAddress_10bit   ((uint16_t)0xC000)
#define IS_I2C_ACKNOWLEDGE_ADDRESS(ADDRESS) (((ADDRESS) == I2C_AcknowledgedAddress_7bit) || \
                                             ((ADDRESS) == I2C_AcknowledgedAddress_10bit))
/**
  * @}
  */

/** @defgroup I2C_registers
  * @{
  */

#define I2C_Register_CR1                ((uint8_t)0x00)
#define I2C_Register_CR2                ((uint8_t)0x04)
#define I2C_Register_OAR1               ((uint8_t)0x08)
#define I2C_Register_OAR2               ((uint8_t)0x0C)
#define I2C_Register_DR                 ((uint8_t)0x10)
#define I2C_Register_SR1                ((uint8_t)0x14)
#define I2C_Register_SR2                ((uint8_t)0x18)
#define I2C_Register_CCR                ((uint8_t)0x1C)
#define I2C_Register_TRISE              ((uint8_t)0x20)
#define IS_I2C_REGISTER(REGISTER) (((REGISTER) == I2C_Register_CR1) || \
                                   ((REGISTER) == I2C_Register_CR2) || \
                                   ((REGISTER) == I2C_Register_OAR1) || \
                                   ((REGISTER) == I2C_Register_OAR2) || \
                                   ((REGISTER) == I2C_Register_DR) || \
                                   ((REGISTER) == I2C_Register_SR1) || \
                                   ((REGISTER) == I2C_Register_SR2) || \
                                   ((REGISTER) == I2C_Register_CCR) || \
                                   ((REGISTER) == I2C_Register_TRISE))
/**
  * @}
  */

/** @defgroup I2C_SMBus_alert_pin_level
  * @{
  */

#define I2C_SMBusAlert_Low              ((uint16_t)0x2000)
#define I2C_SMBusAlert_High             ((uint16_t)0xDFFF)
#define IS_I2C_SMBUS_ALERT(ALERT) (((ALERT) == I2C_SMBusAlert_Low) || \
                                   ((ALERT) == I2C_SMBusAlert_High))
/**
  * @}
  */

/** @defgroup I2C_PEC_position
  * @{
  */

#define I2C_PECPosition_Next            ((uint16_t)0x0800)
#define I2C_PECPosition_Current         ((uint16_t)0xF7FF)
#define IS_I2C_PEC_POSITION(POSITION) (((POSITION) == I2C_PECPosition_Next) || \
                                       ((POSITION) == I2C_PECPosition_Current))
/**
  * @}
  */

/** @defgroup I2C_interrupts_definition
  * @{
  */

#define I2C_IT_BUF                      ((uint16_t)0x0400)
#define I2C_IT_EVT                      ((uint16_t)0x0200)
#define I2C_IT_ERR                      ((uint16_t)0x0100)
#define IS_I2C_CONFIG_IT(IT) ((((IT) & (uint16_t)0xF8FF) == 0x00) && ((IT) != 0x00))
/**
  * @}
  */

/** @defgroup I2C_interrupts_definition
  * @{
  */

#define I2C_IT_SMBALERT                 ((uint32_t)0x01008000)
#define I2C_IT_TIMEOUT                  ((uint32_t)0x01004000)
#define I2C_IT_PECERR                   ((uint32_t)0x01001000)
#define I2C_IT_OVR                      ((uint32_t)0x01000800)
#define I2C_IT_AF                       ((uint32_t)0x01000400)
#define I2C_IT_ARLO                     ((uint32_t)0x01000200)
#define I2C_IT_BERR                     ((uint32_t)0x01000100)
#define I2C_IT_TXE                      ((uint32_t)0x06000080)
#define I2C_IT_RXNE                     ((uint32_t)0x06000040)
#define I2C_IT_STOPF                    ((uint32_t)0x02000010)
#define I2C_IT_ADD10                    ((uint32_t)0x02000008)
#define I2C_IT_BTF                      ((uint32_t)0x02000004)
#define I2C_IT_ADDR                     ((uint32_t)0x02000002)
#define I2C_IT_SB                       ((uint32_t)0x02000001)

#define IS_I2C_CLEAR_IT(IT) ((((IT) & (uint16_t)0x20FF) == 0x00) && ((IT) != (uint16_t)0x00))

#define IS_I2C_GET_IT(IT) (((IT) == I2C_IT_SMBALERT) || ((IT) == I2C_IT_TIMEOUT) || \
                           ((IT) == I2C_IT_PECERR) || ((IT) == I2C_IT_OVR) || \
                           ((IT) == I2C_IT_AF) || ((IT) == I2C_IT_ARLO) || \
                           ((IT) == I2C_IT_BERR) || ((IT) == I2C_IT_TXE) || \
                           ((IT) == I2C_IT_RXNE) || ((IT) == I2C_IT_STOPF) || \
                           ((IT) == I2C_IT_ADD10) || ((IT) == I2C_IT_BTF) || \
                           ((IT) == I2C_IT_ADDR) || ((IT) == I2C_IT_SB))
/**
  * @}
  */

/** @defgroup I2C_flags_definition
  * @{
  */

/**
  * @brief  SR2 register flags
  */

#define I2C_FLAG_DUALF                  ((uint32_t)0x00800000)
#define I2C_FLAG_SMBHOST                ((uint32_t)0x00400000)
#define I2C_FLAG_SMBDEFAULT             ((uint32_t)0x00200000)
#define I2C_FLAG_GENCALL                ((uint32_t)0x00100000)
#define I2C_FLAG_TRA                    ((uint32_t)0x00040000)
#define I2C_FLAG_BUSY                   ((uint32_t)0x00020000)
#define I2C_FLAG_MSL                    ((uint32_t)0x00010000)

/**
  * @brief  SR1 register flags
  */

#define I2C_FLAG_SMBALERT               ((uint32_t)0x10008000)
#define I2C_FLAG_TIMEOUT                ((uint32_t)0x10004000)
#define I2C_FLAG_PECERR                 ((uint32_t)0x10001000)
#define I2C_FLAG_OVR                    ((uint32_t)0x10000800)
#define I2C_FLAG_AF                     ((uint32_t)0x10000400)
#define I2C_FLAG_ARLO                   ((uint32_t)0x10000200)
#define I2C_FLAG_BERR                   ((uint32_t)0x10000100)
#define I2C_FLAG_TXE                    ((uint32_t)0x10000080)
#define I2C_FLAG_RXNE                   ((uint32_t)0x10000040)
#define I2C_FLAG_STOPF                  ((uint32_t)0x10000010)
#define I2C_FLAG_ADD10                  ((uint32_t)0x10000008)
#define I2C_FLAG_BTF                    ((uint32_t)0x10000004)
#define I2C_FLAG_ADDR                   ((uint32_t)0x10000002)
#define I2C_FLAG_SB                     ((uint32_t)0x10000001)

#define IS_I2C_CLEAR_FLAG(FLAG) ((((FLAG) & (uint16_t)0x20FF) == 0x00) && ((FLAG) != (uint16_t)0x00))

#define IS_I2C_GET_FLAG(FLAG) (((FLAG) == I2C_FLAG_DUALF) || ((FLAG) == I2C_FLAG_SMBHOST) || \
                               ((FLAG) == I2C_FLAG_SMBDEFAULT) || ((FLAG) == I2C_FLAG_GENCALL) || \
                               ((FLAG) == I2C_FLAG_TRA) || ((FLAG) == I2C_FLAG_BUSY) || \
                               ((FLAG) == I2C_FLAG_MSL) || ((FLAG) == I2C_FLAG_SMBALERT) || \
                               ((FLAG) == I2C_FLAG_TIMEOUT) || ((FLAG) == I2C_FLAG_PECERR) || \
                               ((FLAG) == I2C_FLAG_OVR) || ((FLAG) == I2C_FLAG_AF) || \
                               ((FLAG) == I2C_FLAG_ARLO) || ((FLAG) == I2C_FLAG_BERR) || \
                               ((FLAG) == I2C_FLAG_TXE) || ((FLAG) == I2C_FLAG_RXNE) || \
                               ((FLAG) == I2C_FLAG_STOPF) || ((FLAG) == I2C_FLAG_ADD10) || \
                               ((FLAG) == I2C_FLAG_BTF) || ((FLAG) == I2C_FLAG_ADDR) || \
                               ((FLAG) == I2C_FLAG_SB))
/**
  * @}
  */

/** @defgroup I2C_Events
  * @{
  */

/**
  * @brief  EV1
  */

#define  I2C_EVENT_SLAVE_TRANSMITTER_ADDRESS_MATCHED       ((uint32_t)0x00060082)   /* TRA, BUSY, TXE and ADDR flags */
#define  I2C_EVENT_SLAVE_RECEIVER_ADDRESS_MATCHED          ((uint32_t)0x00020002)   /* BUSY and ADDR flags */
#define  I2C_EVENT_SLAVE_TRANSMITTER_SECONDADDRESS_MATCHED ((uint32_t)0x00860080)   /* DUALF, TRA, BUSY and TXE flags */
#define  I2C_EVENT_SLAVE_RECEIVER_SECONDADDRESS_MATCHED    ((uint32_t)0x00820000)   /* DUALF and BUSY flags */
#define  I2C_EVENT_SLAVE_GENERALCALLADDRESS_MATCHED        ((uint32_t)0x00120000)   /* GENCALL and BUSY flags */

/**
  * @brief  EV2
  */

#define  I2C_EVENT_SLAVE_BYTE_RECEIVED                     ((uint32_t)0x00020040)   /* BUSY and RXNE flags */

/**
  * @brief  EV3
  */

#define  I2C_EVENT_SLAVE_BYTE_TRANSMITTED                  ((uint32_t)0x00060084)   /* TRA, BUSY, TXE and BTF flags */

/**
  * @brief  EV4
  */

#define  I2C_EVENT_SLAVE_STOP_DETECTED                     ((uint32_t)0x00000010)   /* STOPF flag */

/**
  * @brief  EV5
  */

#define  I2C_EVENT_MASTER_MODE_SELECT                      ((uint32_t)0x00030001)   /* BUSY, MSL and SB flag */

/**
  * @brief  EV6
  */

#define  I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED        ((uint32_t)0x00070082)   /* BUSY, MSL, ADDR, TXE and TRA flags */
#define  I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED           ((uint32_t)0x00030002)   /* BUSY, MSL and ADDR flags */

/**
  * @brief  EV7
  */

#define  I2C_EVENT_MASTER_BYTE_RECEIVED                    ((uint32_t)0x00030040)   /* BUSY, MSL and RXNE flags */

/**
  * @brief  EV8
  */

#define I2C_EVENT_MASTER_BYTE_TRANSMITTING                 ((uint32_t)0x00070080)   /* TRA, BUSY, MSL, TXE flags */

/**
  * @brief  EV8_2
  */

#define  I2C_EVENT_MASTER_BYTE_TRANSMITTED                 ((uint32_t)0x00070084)   /* TRA, BUSY, MSL, TXE and BTF flags */

/**
  * @brief  EV9
  */

#define  I2C_EVENT_MASTER_MODE_ADDRESS10                   ((uint32_t)0x00030008)   /* BUSY, MSL and ADD10 flags */

/**
  * @brief  EV3_2
  */

#define  I2C_EVENT_SLAVE_ACK_FAILURE                       ((uint32_t)0x00000400)   /* AF flag */

#define IS_I2C_EVENT(EVENT) (((EVENT) == I2C_EVENT_SLAVE_TRANSMITTER_ADDRESS_MATCHED) || \
                             ((EVENT) == I2C_EVENT_SLAVE_RECEIVER_ADDRESS_MATCHED) || \
                             ((EVENT) == I2C_EVENT_SLAVE_TRANSMITTER_SECONDADDRESS_MATCHED) || \
                             ((EVENT) == I2C_EVENT_SLAVE_RECEIVER_SECONDADDRESS_MATCHED) || \
                             ((EVENT) == I2C_EVENT_SLAVE_GENERALCALLADDRESS_MATCHED) || \
                             ((EVENT) == I2C_EVENT_SLAVE_BYTE_RECEIVED) || \
                             ((EVENT) == (I2C_EVENT_SLAVE_BYTE_RECEIVED | I2C_FLAG_DUALF)) || \
                             ((EVENT) == (I2C_EVENT_SLAVE_BYTE_RECEIVED | I2C_FLAG_GENCALL)) || \
                             ((EVENT) == I2C_EVENT_SLAVE_BYTE_TRANSMITTED) || \
                             ((EVENT) == (I2C_EVENT_SLAVE_BYTE_TRANSMITTED | I2C_FLAG_DUALF)) || \
                             ((EVENT) == (I2C_EVENT_SLAVE_BYTE_TRANSMITTED | I2C_FLAG_GENCALL)) || \
                             ((EVENT) == I2C_EVENT_SLAVE_STOP_DETECTED) || \
                             ((EVENT) == I2C_EVENT_MASTER_MODE_SELECT) || \
                             ((EVENT) == I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED) || \
                             ((EVENT) == I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED) || \
                             ((EVENT) == I2C_EVENT_MASTER_BYTE_RECEIVED) || \
                             ((EVENT) == I2C_EVENT_MASTER_BYTE_TRANSMITTED) || \
                             ((EVENT) == I2C_EVENT_MASTER_BYTE_TRANSMITTING) || \
                             ((EVENT) == I2C_EVENT_MASTER_MODE_ADDRESS10) || \
                             ((EVENT) == I2C_EVENT_SLAVE_ACK_FAILURE))
/**
  * @}
  */

/** @defgroup I2C_own_address1
  * @{
  */

#define IS_I2C_OWN_ADDRESS1(ADDRESS1) ((ADDRESS1) <= 0x3FF)
/**
  * @}
  */

/** @defgroup I2C_clock_speed
  * @{
  */

#define IS_I2C_CLOCK_SPEED(SPEED) (((SPEED) >= 0x1) && ((SPEED) <= 400000))
/**
  * @}
  */

/**
  * @}
  */

/** @defgroup I2C_Exported_Macros
  * @{
  */

/**
  * @}
  */

/** @defgroup I2C_Exported_Functions
  * @{
  */

void I2C_DeInit (I2C_TypeDef * I2Cx);

void I2C_Init (I2C_TypeDef * I2Cx, I2C_InitTypeDef * I2C_InitStruct);

void I2C_StructInit (I2C_InitTypeDef * I2C_InitStruct);

void I2C_Cmd (I2C_TypeDef * I2Cx, FunctionalState NewState);

void I2C_DMACmd (I2C_TypeDef * I2Cx, FunctionalState NewState);

void I2C_DMALastTransferCmd (I2C_TypeDef * I2Cx, FunctionalState NewState);

void I2C_GenerateSTART (I2C_TypeDef * I2Cx, FunctionalState NewState);

void I2C_GenerateSTOP (I2C_TypeDef * I2Cx, FunctionalState NewState);

void I2C_AcknowledgeConfig (I2C_TypeDef * I2Cx, FunctionalState NewState);

void I2C_OwnAddress2Config (I2C_TypeDef * I2Cx, uint8_t Address);

void I2C_DualAddressCmd (I2C_TypeDef * I2Cx, FunctionalState NewState);

void I2C_GeneralCallCmd (I2C_TypeDef * I2Cx, FunctionalState NewState);

void I2C_ITConfig (I2C_TypeDef * I2Cx, uint16_t I2C_IT, FunctionalState NewState);
void I2C_SendData (I2C_TypeDef * I2Cx, uint8_t Data);

uint8_t I2C_ReceiveData (I2C_TypeDef * I2Cx);

void I2C_Send7bitAddress (I2C_TypeDef * I2Cx, uint8_t Address, uint8_t I2C_Direction);
uint16_t I2C_ReadRegister (I2C_TypeDef * I2Cx, uint8_t I2C_Register);

void I2C_SoftwareResetCmd (I2C_TypeDef * I2Cx, FunctionalState NewState);

void I2C_SMBusAlertConfig (I2C_TypeDef * I2Cx, uint16_t I2C_SMBusAlert);

void I2C_TransmitPEC (I2C_TypeDef * I2Cx, FunctionalState NewState);

void I2C_PECPositionConfig (I2C_TypeDef * I2Cx, uint16_t I2C_PECPosition);

void I2C_CalculatePEC (I2C_TypeDef * I2Cx, FunctionalState NewState);

uint8_t I2C_GetPEC (I2C_TypeDef * I2Cx);

void I2C_ARPCmd (I2C_TypeDef * I2Cx, FunctionalState NewState);

void I2C_StretchClockCmd (I2C_TypeDef * I2Cx, FunctionalState NewState);

void I2C_FastModeDutyCycleConfig (I2C_TypeDef * I2Cx, uint16_t I2C_DutyCycle);

uint32_t I2C_GetLastEvent (I2C_TypeDef * I2Cx);

ErrorStatus I2C_CheckEvent (I2C_TypeDef * I2Cx, uint32_t I2C_EVENT);

FlagStatus I2C_GetFlagStatus (I2C_TypeDef * I2Cx, uint32_t I2C_FLAG);

void I2C_ClearFlag (I2C_TypeDef * I2Cx, uint32_t I2C_FLAG);

ITStatus I2C_GetITStatus (I2C_TypeDef * I2Cx, uint32_t I2C_IT);

void I2C_ClearITPendingBit (I2C_TypeDef * I2Cx, uint32_t I2C_IT);

#endif /*__STM32F10x_I2C_H */
/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */
