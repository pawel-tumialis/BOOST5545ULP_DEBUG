/* ============================================================================
 * Copyright (c) 2008-2012 Texas Instruments Incorporated.
 * 
 *  Redistribution and use in source and binary forms, with or without 
 *  modification, are permitted provided that the following conditions 
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright 
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the 
 *    documentation and/or other materials provided with the   
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
*/


/** @file csl_pll.h
 *
 *  @brief PLL functional layer API header file
 *
 *  Path: \(CSLPATH)/inc
 */

/* ============================================================================
 * Revision History
 * ================
 * 21-Aug-2008 Created
 * 13-Aug-2010 CSL v2.10 release
 * 06-Jul-2011 CSL v2.50 release
 * 13-Sep-2012 CSL v3.00 release
 * 20-Dec-2012 CSL v3.01 release
 * ============================================================================
 */

/** @defgroup CSL_PLL_API PLL
 *
 * @section Introduction
 *
 * @subsection xxx Overview
 *
 * In simpler terms, a PLL compares the frequencies of two signals and produces an error signal
 * which is proportional to the difference between the input frequencies. The error signal is used
 * to drive a voltage-controlled oscillator (VCO) which creates an output frequency.
 * The output frequency is fed through a frequency divider back to the input of the system, producing a
 * negative feedback loop. If the output frequency drifts, the error signal will increase, driving the
 * frequency in the opposite direction so as to reduce the error. Thus the output is locked to the frequency
 * at the other input. This input is called the reference and is derived from a crystal oscillator, which is
 * very stable in frequency.
 *
 * \note:
 *   - The DSP maximum operating frequency is 100MHz @ 1.3V.
 *   - The input to the VCO has to fall between 30KHz and 170KHz.
 * The PLL input clock supports 32KHz to 100MHz input frequency, but the reference divider must ensure that
 * the input to the Phase Detector falls between 30KHz and 170KHz.
 * Refer to the formula in section 10.8.1.4.1, on page 53 of C5505 spec v1.16
 * on how system clock is generated.
 * @subsection References
 */

#ifndef _CSL_PLL_H_
#define _CSL_PLL_H_


#ifdef __cplusplus
extern "C" {
#endif

#include "csl_error.h"
#include "csl_types.h"
#include "soc.h"
#include "csl_general.h"

/**
@defgroup CSL_PLL_SYMBOL  PLL Symbols Defined
@ingroup CSL_PLL_API
*/

/**
@defgroup CSL_PLL_DATASTRUCT  PLL Data Structures
@ingroup CSL_PLL_API
*/

/**
@defgroup CSL_PLL_FUNCTION  PLL Functions
@ingroup CSL_PLL_API
*/

/**
@defgroup CSL_PLL_ENUM PLL Enumerated Data Types
@ingroup CSL_PLL_API
*/

/**
@addtogroup CSL_PLL_SYMBOL
@{
*/

/*****************************************************************************\
*         PLL global macro declarations
\*****************************************************************************/

/** This macro is used inside the function PLL_config to set the timeout value.
    This macro gives flexibility to the User to change the timeout value.    */
#define TIMEOUT0                             (0x0004) //32KHz internal clock for all devices except C5517 (CCR2.CLK_STAT=0)
#define TIMEOUT1                             (0x12c0) //12MHz USB internal C5517 (CCR2.CLK_STAT=0)
#define TIMEOUT2                             (0x2580) //External clock for all devices (CCR2.CLK_STAT=1)



/** PLL cotrol regsiter 2 intiailization value                               */
#define CSL_SYS_CGCR2_INIT_VALUE             (0x0806)

/** PLL DIV 000                                                              */
#define CSL_PLL_DIV_000    (0)
/** PLL DIV 001                                                              */
#define CSL_PLL_DIV_001    (1u)
/** PLL DIV 002                                                              */
#define CSL_PLL_DIV_002    (2u)
/** PLL DIV 003                                                              */
#define CSL_PLL_DIV_003    (3u)
/** PLL DIV 004                                                              */
#define CSL_PLL_DIV_004    (4u)
/** PLL DIV 005                                                              */
#define CSL_PLL_DIV_005    (5u)
/** PLL DIV 006                                                              */
#define CSL_PLL_DIV_006    (6u)
/** PLL DIV 007                                                              */
#define CSL_PLL_DIV_007    (7u)
/** PLL CLOCKIN value                                                        */
#define CSL_PLL_CLOCKIN    (32768u)
/** PLL Control 1 Register                                                   */
#define PLL_CNTL1        *(ioport volatile unsigned *)0x1C20
/** PLL Control 2 Register                                                   */
#define PLL_CNTL2        *(ioport volatile unsigned *)0x1C21
/** PLL Control 3 Register                                                   */
#define PLL_CNTL3        *(ioport volatile unsigned *)0x1C22
/** PLL Control 4 Register                                                   */
#define PLL_CNTL4        *(ioport volatile unsigned *)0x1C23
/**
@}*/

/**
@addtogroup CSL_PLL_SYMBOL
@{*/

/**************************************************************************\
* PLLC global typedef declarations                                         *
\**************************************************************************/

/** Handle to the PLL device*/
typedef struct PLL_Obj* PLL_Handle;

/**
@}*/

/**
@addtogroup CSL_PLL_ENUM
@{*/

/**************************************************************************\
* PLLC global enum declaration                                             *
\**************************************************************************/

/**
 * \brief  PLL instance number
 */
typedef enum
{
	/** PLL hardware instance 0                                             */
    CSL_PLL_INST_0 = (0u),
	/** Invalid PLL hardware instance                                       */
    CSL_PLL_INST_INVALID = (1u)
} CSL_PllInsId;
/**
@}*/

/**
\addtogroup CSL_PLL_DATASTRUCT
@{*/

/**************************************************************************\
*               PLLC global data structures                                *
\**************************************************************************/

/** \brief Config-structure
 *
 *  Used to configure the pll using PLL_config function
 */
#ifdef CHIP_C5517
typedef struct
{

    /** PLL Multiplier register controls the first 16 bits of the
        multiplier */
    Uint16    PLLMR;

    /** PLL  Input Control register controls the MSB of the multiplier
        and the input frequency divider */
    Uint16    PLLICR;

    /** PLL Control Register controls the power down and reset bits */
    Uint16	  PLLCR;

    /** PLL  Output Divider register controls the output dividers */
    Uint16    PLLODR;

} PLL_Config;

#else
typedef struct
{
    /** PLL  Control1 register controls the feed back divider,
        powering up of the pll and stand by mode */
    Uint16    PLLCNTL1;

    /** PLL Input Control register controls the reference divider */
    Uint16    PLLINCNTL;

    /** PLL  Control2 register  controls the bypassing of the pll
        and power management related stuffs */
    Uint16    PLLCNTL2;

    /** PLL output control register controls the output divider */
    Uint16    PLLOUTCNTL;

} PLL_Config;
#endif
/**
@}*/

/**
\addtogroup CSL_PLL_DATASTRUCT
@{*/

 /**
  * \brief This object contains the reference to the instance of pll device
  *
  *  This object is initialized during pll initialization and passed as
  *  the parameter to all CSL APIs
  */
typedef struct PLL_Obj{
	/** This structure is used by PLL_Config function to
	   configure the PLL */
	PLL_Config         *pllConfig;
	/** Instance number of PLL*/
	Uint32             instId;
	/** SysRegsOvly structure address*/
	CSL_SysRegsOvly    sysAddr;

} PLL_Obj;

/**
@}*/


/*****************************************************************************\
 * PLL function declarations                                                  *
\*****************************************************************************/

/** @addtogroup CSL_PLL_FUNCTION
@{*/
/** ============================================================================
 *   @n@b PLL_init
 *   @b Description
 *   @n This is the initialization function for the pll CSL. The function
 *      must be called before calling any other API from this CSL. This
 *      will initialize the PLL object.
 *
 *   @b Arguments
 *   @verbatim
            pllObj          Pointer to PLL object.
            pllInstId       Instance number of the PLL.
    @endverbatim
 *
 *   <b> Return Value </b> CSL_Status
 *   @li                       	       CSL_SOK - Init call is successful
 *   @li                               CSL_ESYS_INVPARAMS- Invalid parameter
 *
 *   <b> Pre Condition </b>
 *   @n  None
 *
 *   <b> Post Condition </b>
 *   @n   PLL object structure is populated
 *
 *   @b Modifies
 *   @n Handle is modified
 *
 *   @b Example
 *   @verbatim
         PLL_Obj                 pllObj;
         CSL_Status              status;
         Uint32                  pllInstId;
         pllInstId = 0;
         status = PLL_init(&pllObj,pllInstId);
     @endverbatim
 *  ============================================================================
 */
CSL_Status PLL_init( PLL_Obj * pllObj,
                     Uint32 pllInstId
);

/** ============================================================================
 *   @n@b PLL_config
 *
 *   @b Description
 *   @n This API is used to configure the PLL
 *
 *   @b Arguments
 *   @verbatim
            hPll            Handle to the pll
            pconfigInfo     pointer to PLL_config structure.
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_Status
 *   @li                    CSL_SOK             - Configuring the pll is successful
 *
 *   @li                    CSL_ESYS_BADHANDLE  - The handle passed is invalid
 *
 *   @li                    CSL_ESYS_INVPARAMS  - The pconfigInfo is NULL
 *
 *   <b> Pre Condition </b>
 *   @n  PLL_init should be successfully called.
 *
 *   <b> Post Condition </b>
 *   @n  Configures the PLL registers.
 *
 *   @b Modifies
 *   @n hPll variable
 *
 *   @b Example
 *   @verbatim
         CSL_Status              status;
         PLL_Obj                 pllObj;
         PLL_Config              configInfo;
         PLL_Handle              hPll;
         Uint32                  pllInstId;
         pllInstId = 0;
         status = PLL_init(&pllObj,pllInstId);
         hPll = &pllObj;
	     .......
         Configure the PLL for 12.288MHz
         configInfo.PLLCNTL1 = 0x82ed;
         configInfo.PLLINCNTL = 0x8000;
         configInfo.PLLCNTL2 = 0x0806;
         configInfo.PLLOUTCNTL = 0x0200;
         status = PLL_config(hPll, &configInfo);
     @endverbatim
 *  ============================================================================
 */

CSL_Status PLL_config(
	           PLL_Handle hPll,
	           PLL_Config *pconfigInfo
);

/** ============================================================================
 *   @n@b PLL_enable
 *
 *   @b Description
 *   @n This API is used to enable the PLL
 *
 *   @b Arguments
 *   @verbatim
            hPll        Handle to the pll
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_Status
 *   @li                    CSL_SOK             -  Enabling the PLL is successful
 *
 *   @li                    CSL_ESYS_BADHANDLE  - The handle passed is invalid
 *
 *   <b> Pre Condition </b>
 *   @n  PLL_init and PLL_config should be called successfully.
 *
 *   <b> Post Condition </b>
 *   @n  Pll is enabled
 *
 *   @b Modifies
 *   @n hPll variable
 *
 *   @b Example
 *   @verbatim
         CSL_Status              status;
         PLL_Obj                 pllObj;
         PLL_Config              configInfo;
         PLL_Handle              hPll;
         Uint32                  pllInstId;
         pllInstId = 0;
         status = PLL_init(&pllObj,pllInstId);
         hPll = &pllObj;
	     .......
         Configure the PLL for 12.288MHz
         configInfo.PLLCNTL1 = 0x82ed;
         configInfo.PLLINCNTL = 0x8000;
         configInfo.PLLCNTL2 = 0x0806;
         configInfo.PLLOUTCNTL = 0x0200;
         status = PLL_config(hPll, &configInfo);
         status = PLL_enable(hPll);

     @endverbatim
 *  ============================================================================
 */


CSL_Status PLL_enable(
	           PLL_Handle hPll
);

/** ============================================================================
 *   @n@b PLL_bypass
 *
 *   @b Description
 *   @n This API is used to Bypass the PLL.
 *
 *   @b Arguments
 *   @verbatim
            hPll        Handle to the pll
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_Status
 *   @li                    CSL_SOK             -  Bypassing the PLL is successful
 *
 *   @li                    CSL_ESYS_BADHANDLE  - The handle passed is invalid
 *
 *   <b> Pre Condition </b>
 *   @n  PLL_init and PLL_config should be called successfully.
 *
 *   <b> Post Condition </b>
 *   @n  Pll is bypassed
 *
 *   @b Modifies
 *   @n hPll variable
 *
 *   @b Example
 *   @verbatim
         CSL_Status              status;
         PLL_Obj                 pllObj;
         PLL_Config              configInfo;
         PLL_Handle              hPll;
         Uint32                  pllInstId;
         pllInstId = 0;
         status = PLL_init(&pllObj,pllInstId);
         hPll = &pllObj;
	     .......
         Configure the PLL for 12.288MHz
         configInfo.PLLCNTL1 = 0x82ed;
         configInfo.PLLINCNTL = 0x8000;
         configInfo.PLLCNTL2 = 0x0806;
         configInfo.PLLOUTCNTL = 0x0200;
         status = PLL_config(hPll, &configInfo);
         status = PLL_bypass(hPll);
     @endverbatim
 *  ============================================================================
 */
CSL_Status PLL_bypass(
	           PLL_Handle hPll
);

/** ============================================================================
 *   @n@b PLL_reset
 *
 *   @b Description
 *   @n Resets all the PLL registers.
 *
 *   @b Arguments
 *   @verbatim
            hPll        Handle to the pll
     @endverbatim
 *
 *   <b> Return Value </b>  CSL_Status
 *   @li                    CSL_SOK             -         Resetting the PLL is successful.
 *
 *   @li                    CSL_ESYS_BADHANDLE  - The handle passed is invalid
 *
 *
 *   <b> Pre Condition </b>
 *   @n  PLL_init should be called successfully.
 *
 *   <b> Post Condition </b>
 *   @n  PLL registers are resetted.
 *
 *   @b Modifies
 *   @n hPll variable
 *
 *   @b Example
 *   @verbatim
            CSL_Status              status;
            PLL_Obj                 pllObj;
            Uint32                  pllInstId;
            PLL_Handle              hPll;
            pllInstId = 0;
            status = PLL_init(&pllObj,pllInstId);
          	.....
            hPll = &pllObj;
            status = PLL_reset(&pllObj);
     @endverbatim
 *  ============================================================================
 */
CSL_Status PLL_reset(
		PLL_Handle hPll
);

/**
 *  @n@b getSysClk
 *
 *  @b Description
 *  @n Function to calculate the clock at which system is running
 *
 *  @b Arguments
 *
 *  <b> Return Value </b>   System clock value
 */
Uint32 getSysClk(void);
/**
@} */
#ifdef __cplusplus
}
#endif
#endif /* _CSL_PLL_H_ */


