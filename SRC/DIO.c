#include "stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h" 
#include "DIO.h"

Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelID) {
    GPIO_TypeDef* GPIO_Port;   /**< Con tr? d?n c?ng GPIO */
    uint16_t GPIO_Pin;         /**< Ch�n GPIO c?n d?c tr?ng th�i */

    // X�c d?nh c?ng GPIO tuong ?ng v?i ChannelID
    GPIO_Port = DIO_GET_PORT(ChannelID);

    // N?u kh�ng t�m th?y c?ng GPIO h?p l?, tr? v? tr?ng th�i th?p (STD_LOW)
    if (GPIO_Port == NULL) {
        return STD_LOW;
    }

    // X�c d?nh ch�n GPIO tuong ?ng v?i ChannelID
    GPIO_Pin = DIO_GetPin(ChannelID);

    // �?c tr?ng th�i c?a ch�n GPIO
    if (GPIO_ReadInputDataBit(GPIO_Port, GPIO_Pin) == Bit_SET) {
        return STD_HIGH;        /* N?u ch�n c� m?c logic cao, tr? v? STD_HIGH */
    } else {
        return STD_LOW;         /* N?u ch�n c� m?c logic th?p, tr? v? STD_LOW */
    }
}

void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
    GPIO_TypeDef *GPIO_Port;
    uint16_t GIPO_Pin;

    GPIO_Port = DIO_GET_PORT(ChannelId);
    if(GPIO_Port == NULL)
    {
        return; // Handle error appropriately
    }
    GIPO_Pin = DIO_GetPin(ChannelId);
    
    if(Level == STD_HIGH)
    {
        GPIO_SetBits(GPIO_Port, GIPO_Pin);
    }
    else
    {
        GPIO_ResetBits(GPIO_Port, GIPO_Pin);
    }
}
Dio_PortLevelType DIO_ReadPort(Dio_PortType PortId)
{
    GPIO_TypeDef *GPIO_Port;

    GPIO_Port = DIO_GET_PORT(PortId);
    if(GPIO_Port == NULL)
    {
        return 0; // Return a default value or handle error appropriately
    }
    return(Dio_PortLevelType)GPIO_ReadInputData(GPIO_Port) ;
}
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level)
{
    GPIO_TypeDef *GPIO_Port;

    GPIO_Port = DIO_GET_PORT(PortId);
    if(GPIO_Port == NULL)
    {
        Det_ReportError(DIO_MODULE_ID, 0, DIO_WRITEPORT_ID, DIO_E_PARAM_INVALID_PORT);
        return; // Handle error appropriately
    }
    
    GPIO_Write(GPIO_Port, Level);
}
Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr)
{
    GPIO_TypeDef *GPIO_Port;
    uint16_t mask;
    uint8_t offset;

    if(ChannelGroupIdPtr == NULL)
    {
        return 0; // Return a default value or handle error appropriately
    }

    GPIO_Port = DIO_GET_PORT(ChannelGroupIdPtr->port);
    if(GPIO_Port == NULL)
    {
        return 0; // Return a default value or handle error appropriately
    }
    
    mask = ChannelGroupIdPtr->mask;
    offset = ChannelGroupIdPtr->offset;

    return (Dio_PortLevelType)((GPIO_ReadInputData(GPIO_Port) & mask) >> offset);
}

void Dio_WriteChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr, Dio_PortLevelType Level)
{
    GPIO_TypeDef *GPIO_Port;
    uint16_t mask;
    uint8_t offset;

    if(ChannelGroupIdPtr == NULL)
    {
        return; // Handle error appropriately
    }

    GPIO_Port = DIO_GET_PORT(ChannelGroupIdPtr->port);
    if(GPIO_Port == NULL)
    {
        return; // Handle error appropriately
    }
    
    mask = ChannelGroupIdPtr->mask;
    offset = ChannelGroupIdPtr->offset;

    Dio_PortLevelType currentLevel = GPIO_ReadInputData(GPIO_Port) & ~mask;
    currentLevel |= (Level << offset) & mask;

    GPIO_Write(GPIO_Port, currentLevel);
}
void Dio_GetVersionInfo(Std_VersionInfoType* versioninfo)
{
    if(versioninfo == NULL)
    {
        return; // Handle error appropriately
    }

    versioninfo->vendorID = DIO_VENDOR_ID;
    versioninfo->moduleID = DIO_MODULE_ID;
    versioninfo->sw_major_version = STD_TYPES_SW_MAJOR_VERSION;
    versioninfo->sw_minor_version = STD_TYPES_SW_MINOR_VERSION;
    versioninfo->sw_patch_version = STD_TYPES_SW_PATCH_VERSION;
}
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId)
{
    GPIO_TypeDef *GPIO_Port;
    uint16_t GIPO_Pin;

    GPIO_Port = DIO_GET_PORT(ChannelId);
    if(GPIO_Port == NULL)
    {
        return STD_LOW; // Return a default value or handle error appropriately
    }
    GIPO_Pin = DIO_GetPin(ChannelId);

   GPIO_Port ->ODR ^= GIPO_Pin;
}
void Dio_MaskedWritePort(Dio_PortType PortId, Dio_PortLevelType Level, Dio_PortLevelType Mask)
{
    GPIO_TypeDef *GPIO_Port;

    GPIO_Port = DIO_GET_PORT(PortId);
    if(GPIO_Port == NULL)
    {
        return; // Handle error appropriately
    }
    
    Dio_PortLevelType currentLevel = GPIO_ReadInputData(GPIO_Port) & ~Mask;
    currentLevel |= (Level & Mask);

    GPIO_Write(GPIO_Port, currentLevel);
}