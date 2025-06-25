#ifndef STD_TYPES_H
#define STD_TYPES_H
// This file is part of the AUTOSAR standard.
#include <stdint.h>

/* ==============================================
    *version information
  *=================================================/
 * @brief th�ng tin v? phi�n b?n c?a Std_Types.h
 * @details c�c d?nh nghia v? vi?c phi�n b?n gi�p d? d�ng qu?n l� v� b?o tr� m� ngu?n.
 * @note This file is part of the AUTOSAR standard and should be used in compliance with the AUTOSAR guidelines.
**********************************************/
#define STD_TYPES_SW_MAJOR_VERSION  1U
#define STD_TYPES_SW_MINOR_VERSION  0U
#define STD_TYPES_SW_PATCH_VERSION  0U
#define DIO_VENDOR_ID 0x123
#define DIO_MODULE_ID 0x234
/* ==============================================================
 * Standard Return Types
 *===============================================================/
 * @brief  ki?u tr? v? ti�u chu?n trong AUTOSAR.
 * @details �u?c s? d?ng d? b�o c�o k?t qu? c?a c�c h�m trong AUTOSAR, v?i c�c gi� tr? nhu E_OK v� E_NOT_OK
 * @note This file is part of the AUTOSAR standard and should be used in compliance with the AUTOSAR guidelines.
*/
typedef uint8_t Std_ReturnType;
#define E_OK        0x00U
#define E_NOT_OK    0x01U
/*============================================================
 * Standard Boolean Values
 *===========================================================/
 * @brief  �?nh nghia gi� tr? logic cao v� logic th?p.
 * @details �u?c s? d?ng d? bi?u di?n tr?ng th�i c?a c�c bi?n, v?i c�c gi� tr? nhu STD_HIGH v� STD_LOW.
 * @note This file is part of the AUTOSAR standard and should be used in compliance with the AUTOSAR guidelines.
*/
#define STD_HIGH    0x01
#define STD_LOW     0x00

/* ===========================================================
 * Standard NULL Pointer Definition
 * ===========================================================*/
/********************************************************* 
 * @brief  �?nh nghia con tr? NULL.
 * @details �u?c s? d?ng d? bi?u th? r?ng m?t con tr? kh�ng tr? d?n b?t k? d?a ch? h?p l? n�o.
 * @note This file is part of the AUTOSAR standard and should be used in compliance with the AUTOSAR guidelines.
**********************************************************/
#ifndef NULL
#define NULL ((void *)0)
#endif
/*
 * ===========================================================
 * Standard Type Definitions
 * ===========================================================*/
/*************************************************************** 
 * @brief  �?nh nghia c�c ki?u d? li?u ti�u chu?n trong AUTOSAR.
 * @details Bao g?m c�c ki?u d? li?u nguy�n th?y nhu uint8_t, sint16_t, vuint32_t, vuint64_t, vfloat32_t, vfloat64_t.
 * @note This file is part of the AUTOSAR standard and should be used in compliance with the AUTOSAR guidelines.
****************************************************************/
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned long uint32_t;
typedef unsigned long long uint64_t;
typedef signed char sint8_t;
typedef signed short sint16_t;
typedef signed long sint32_t;
typedef signed long long sint64_t;

typedef float float32_t;
typedef double float64_t;

typedef volatile uint8_t vuint8_t;
typedef volatile uint16_t vuint16_t;
typedef volatile uint32_t vuint32_t;
typedef volatile uint64_t vuint64_t;
typedef volatile sint8_t vsint8_t;
typedef volatile sint16_t vsint16_t;
typedef volatile sint32_t vsint32_t;
typedef volatile sint64_t vsint64_t;
/*
    * ===========================================================
    * Standard Boolean Type Definition
    * ===========================================================
    */
/******************************************************************* 
 * @typedef boolean
 * @brief ki?u d? li?u boolean
 * @details S? d?ng bi?u di?n gi� tr? d�ng/sai trong AUTOSAR.
 * @note This file is part of the AUTOSAR standard and should be used in compliance with the AUTOSAR guidelines.
********************************************************************/

typedef uint8_t boolean;

#ifndef TRUE
    #define TRUE  1U
#endif
#ifndef FALSE
    #define FALSE 0U
#endif
/*
    * ===========================================================
    * Standard Version Information Structure
    * ===========================================================
    */
/*******************************************************************
 * @struct Std_VersionInfoType
 * @brief C?u tr�c ch?a th�ng tin phi�n b?n c?a m?t module trong AUTOSAR.
 * @details Bao g?m c�c tru?ng nhu vendorID, moduleID, major, minor v� patch d? qu?n l� phi�n b?n.
 * @note This file is part of the AUTOSAR standard and should be used in compliance with the AUTOSAR guidelines.
*********************************************************************/
typedef struct {
    uint16_t vendorID;
    uint16_t moduleID;
    uint8_t sw_major_version;
    uint8_t sw_minor_version;
    uint8_t sw_patch_version;
} Std_VersionInfoType;
/*
    * ===========================================================
    * Standard Error Reporting
    * ===========================================================
    */
/*******************************************************************
 * @macro Det_ReportError
 * @brief Macro d? b�o c�o l?i trong AUTOSAR.
 * @details �u?c s? d?ng d? ghi l?i c�c l?i x?y ra trong qu� tr�nh th?c thi c?a h? th?ng, v?i c�c tham s? nhu moduleId, instanceId, apiId v� errorId.
 * @note This file is part of the AUTOSAR standard and should be used in compliance with the AUTOSAR guidelines.
********************************************************************/
#define Det_ReportError(moduleId, instanceId, apiId, errorId) 
/*
    * ===========================================================
    * Standard Status Definitions
    * ===========================================================
    */
/*******************************************************************
 * @macro STD_ACTIVE, STD_IDLE, STD_ON, STD_OFF
 * @brief C�c d?nh nghia tr?ng th�i ti�u chu?n trong AUTOSAR.
 * @details �u?c s? d?ng d? bi?u di?n tr?ng th�i ho?t d?ng, nh�n r?i, b?t v� t?t c?a c�c th�nh ph?n trong h? th?ng.
 * @note This file is part of the AUTOSAR standard and should be used in compliance with the AUTOSAR guidelines.
********************************************************************/

#define STD_ACTIVE  0x01U
#define STD_IDLE    0x00U

#define STD_ON      0x01U
#define STD_OFF     0x00U

#endif
