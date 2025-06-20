#ifndef DIO_H
#define DIO_H

// This file is part of the AUTOSAR standard.
#include "Std_Types.h"

#define DIO_PORT_A 0
#define DIO_PORT_B 1
#define DIO_PORT_C 2
#define DIO_PORT_D 3

#define DIO_GET_PORT(ChannelID) \
    (((ChannelID) < 16) ? GPIOA : \
    (((ChannelID) < 32) ? GPIOB : \
    (((ChannelID) < 48) ? GPIOC : \
    (((ChannelID) < 64) ? GPIOD : NULL))))
#define DIO_GetPin(ChannelId) ((uint16_t)(1U << ((ChannelId) % 16)))
#define DIO_CHANNEL(GPIO_Port, Pin) \
    ((GPIO_Port) * 16 + (Pin))
#define DIO_CHANNEL_A0 (DIO_CHANNEL(DIO_PORT_A, 0))
#define DIO_CHANNEL_A1 (DIO_CHANNEL(DIO_PORT_A, 1))
#define DIO_CHANNEL_A2 (DIO_CHANNEL(DIO_PORT_A, 2))
#define DIO_CHANNEL_A3 (DIO_CHANNEL(DIO_PORT_A, 3))
#define DIO_CHANNEL_A4 (DIO_CHANNEL(DIO_PORT_A, 4))
#define DIO_CHANNEL_A5 (DIO_CHANNEL(DIO_PORT_A, 5))
#define DIO_CHANNEL_A6 (DIO_CHANNEL(DIO_PORT_A, 6))
#define DIO_CHANNEL_A7 (DIO_CHANNEL(DIO_PORT_A, 7))
#define DIO_CHANNEL_A8 (DIO_CHANNEL(DIO_PORT_A, 8))
#define DIO_CHANNEL_A9 (DIO_CHANNEL(DIO_PORT_A, 9))
#define DIO_CHANNEL_A10 (DIO_CHANNEL(DIO_PORT_A, 10))
#define DIO_CHANNEL_A11 (DIO_CHANNEL(DIO_PORT_A, 11))
#define DIO_CHANNEL_A12 (DIO_CHANNEL(DIO_PORT_A, 12))
#define DIO_CHANNEL_A13 (DIO_CHANNEL(DIO_PORT_A, 13))
#define DIO_CHANNEL_A14 (DIO_CHANNEL(DIO_PORT_A, 14))
#define DIO_CHANNEL_A15 (DIO_CHANNEL(DIO_PORT_A, 15))

#define DIO_CHANNEL_B0 (DIO_CHANNEL(DIO_PORT_B, 0))
#define DIO_CHANNEL_B1 (DIO_CHANNEL(DIO_PORT_B, 1))
#define DIO_CHANNEL_B2 (DIO_CHANNEL(DIO_PORT_B, 2))
#define DIO_CHANNEL_B3 (DIO_CHANNEL(DIO_PORT_B, 3))
#define DIO_CHANNEL_B4 (DIO_CHANNEL(DIO_PORT_B, 4))
#define DIO_CHANNEL_B5 (DIO_CHANNEL(DIO_PORT_B, 5))
#define DIO_CHANNEL_B6 (DIO_CHANNEL(DIO_PORT_B, 6))
#define DIO_CHANNEL_B7 (DIO_CHANNEL(DIO_PORT_B, 7))
#define DIO_CHANNEL_B8 (DIO_CHANNEL(DIO_PORT_B, 8))
#define DIO_CHANNEL_B9 (DIO_CHANNEL(DIO_PORT_B, 9))
#define DIO_CHANNEL_B10 (DIO_CHANNEL(DIO_PORT_B, 10))
#define DIO_CHANNEL_B11 (DIO_CHANNEL(DIO_PORT_B, 11))
#define DIO_CHANNEL_B12 (DIO_CHANNEL(DIO_PORT_B, 12))
#define DIO_CHANNEL_B13 (DIO_CHANNEL(DIO_PORT_B, 13))
#define DIO_CHANNEL_B14 (DIO_CHANNEL(DIO_PORT_B, 14))
#define DIO_CHANNEL_B15 (DIO_CHANNEL(DIO_PORT_B, 15))

#define DIO_CHANNEL_C0 (DIO_CHANNEL(DIO_PORT_C, 0))
#define DIO_CHANNEL_C1 (DIO_CHANNEL(DIO_PORT_C, 1))
#define DIO_CHANNEL_C2 (DIO_CHANNEL(DIO_PORT_C, 2))
#define DIO_CHANNEL_C3 (DIO_CHANNEL(DIO_PORT_C, 3))
#define DIO_CHANNEL_C4 (DIO_CHANNEL(DIO_PORT_C, 4))
#define DIO_CHANNEL_C5 (DIO_CHANNEL(DIO_PORT_C, 5))
#define DIO_CHANNEL_C6 (DIO_CHANNEL(DIO_PORT_C, 6))
#define DIO_CHANNEL_C7 (DIO_CHANNEL(DIO_PORT_C, 7))
#define DIO_CHANNEL_C8 (DIO_CHANNEL(DIO_PORT_C, 8))
#define DIO_CHANNEL_C9 (DIO_CHANNEL(DIO_PORT_C, 9))
#define DIO_CHANNEL_C10 (DIO_CHANNEL(DIO_PORT_C, 10))
#define DIO_CHANNEL_C11 (DIO_CHANNEL(DIO_PORT_C, 11))
#define DIO_CHANNEL_C12 (DIO_CHANNEL(DIO_PORT_C, 12))
#define DIO_CHANNEL_C13 (DIO_CHANNEL(DIO_PORT_C, 13))
#define DIO_CHANNEL_C14 (DIO_CHANNEL(DIO_PORT_C, 14))
#define DIO_CHANNEL_C15 (DIO_CHANNEL(DIO_PORT_C, 15))


#define DIO_CHANNEL_D0 (DIO_CHANNEL(DIO_PORT_D, 0))
#define DIO_CHANNEL_D1 (DIO_CHANNEL(DIO_PORT_D, 1))
#define DIO_CHANNEL_D2 (DIO_CHANNEL(DIO_PORT_D, 2))
#define DIO_CHANNEL_D3 (DIO_CHANNEL(DIO_PORT_D, 3))
#define DIO_CHANNEL_D4 (DIO_CHANNEL(DIO_PORT_D, 4))
#define DIO_CHANNEL_D5 (DIO_CHANNEL(DIO_PORT_D, 5))
#define DIO_CHANNEL_D6 (DIO_CHANNEL(DIO_PORT_D, 6))
#define DIO_CHANNEL_D7 (DIO_CHANNEL(DIO_PORT_D, 7))
#define DIO_CHANNEL_D8 (DIO_CHANNEL(DIO_PORT_D, 8))
#define DIO_CHANNEL_D9 (DIO_CHANNEL(DIO_PORT_D, 9))
#define DIO_CHANNEL_D10 (DIO_CHANNEL(DIO_PORT_D, 10))
#define DIO_CHANNEL_D11 (DIO_CHANNEL(DIO_PORT_D, 11))
#define DIO_CHANNEL_D12 (DIO_CHANNEL(DIO_PORT_D, 12))
#define DIO_CHANNEL_D13 (DIO_CHANNEL(DIO_PORT_D, 13))
#define DIO_CHANNEL_D14 (DIO_CHANNEL(DIO_PORT_D, 14))
#define DIO_CHANNEL_D15 (DIO_CHANNEL(DIO_PORT_D, 15))



typedef uint8_t Dio_ChannelType;
typedef uint8_t Dio_PortType;
typedef uint8_t Dio_LevelType;

typedef struct 
{
    Dio_PortType port;
    uint16_t mask;
    uint8_t offset;
}
 Dio_ChannelGroupType;
typedef uint8_t Dio_LevelType;
typedef uint16_t Dio_PortLevelType;

void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelID);
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level);
Dio_PortLevelType DIO_ReadPort(Dio_PortType PortId);
Dio_PortLevelType DIO_ReadChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr);
void Dio_WriteChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr, Dio_PortLevelType Level);
Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr);
void Dio_GetVersionInfo(Std_VersionInfoType* versioninfo);
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId);
void Dio_MaskedWritePort(Dio_PortType PortId, Dio_PortLevelType Level, Dio_PortLevelType Mask);

#endif
