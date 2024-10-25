/**
* Copyright (c) 2002-2009 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of "Eclipse Public License v1.0"
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description:
* Setting values for the primary and secondary filters, etc.*
* 
*
*/



/**
 @file te_setfilterparameters.h
 @internalTechnology
*/

#if (!defined __TE_SETFILTERPARAMETERS_H__)
#define __TE_SETFILTERPARAMETERS_H__
#include <d32btrace.h>
#ifdef __KERNEL_MODE__
#include "kernel.h"
#endif
#include <e32utrace.h>


/*Settings for trace data field - only one can be selected at any time*/
#define SMALLTRACE
//#define BIGTRACE
//#define HUGETRACE

/*********************************************/

/*Settings for systart testing - uncomment this and only run the LoggingTestStep*/
//#define SysStartTest

/*********************************************/

/*Settings for performance tests*/
//  - one or many plugins can be selected
//  - only one trace performance test type can be selceted - this sets the loop details defined below
#define FILE_PERF
#define SERIAL_PERF

#define CACHE_TRACE
//#define SINGLE_TRACE

/*********************************************/

//I've made this parameterisable for any future modifications to UTrace 
//te_utracecmds.cpp needs to be updated accordingly in this case
static const TInt NumberOfUTraceMacros =18; 
static const TInt NumberOfPrintfMacros = 16;
static const TInt UTrace_Count = 10000;


/*********************************************/

//Set the number of traces here for the performance test on UTrace
#ifdef CACHE_TRACE
static const TInt UTrace_Cache_Count = 10000;
static const TInt StatAverage = 1; //this number is used mainly for the single trace performance tests to average over isochronal or statistical effects and avoid caching
#endif

#ifdef SINGLE_TRACE
static const TInt UTrace_Cache_Count = 1;
static const TInt StatAverage = 10000; 
#endif

/*********************************************/

/* Various UTrace Macro Data and Parameter Arguments*/

static const TInt MaxNumberOfPrimaryFilters = 256;
static const TInt MaxNumberOfSecondaryFilters = 4096;//4294967296//2^32
static const TPrimaryFilter UTracePrimary = 255;
static const TSecondaryFilter UTraceSecondary = 333;//4294967296;
static const TUint32 Tracea1=4444;
static const TUint32 Tracea2=55555;
static const TUint32 Tracea3=8;
static const TTraceSchema schema = KBinary; //this is the same as the subcategory in btrace
static const TBool context = EFalse; //now developers can chose what to have, not hardcoded like with PREQ1333.
static const TBool pc = EFalse;
static const TBool pcTrue = ETrue;
#ifndef __KERNEL_MODE__
_LIT16(KName16,"A _LIT16 string with integer parameter %i !");
#endif
_LIT8(KName8,"A _LIT8 string with integer parameter %i !");


/*DATA*/

#ifdef SMALLTRACE
/* <80bytes*/
static const TAny* aData="This is an any data text string that you can use...."; // SMALL DATA
static const TInt aSize= sizeof("This is an any data text string that you can use....");
#endif

#ifdef BIGTRACE
/* >80bytes (96bytes)*/
static const TInt8 aData[] =            
{
0x50,0x4b,0x03,0x04,0x14,0x00,0x02,0x00,0x08,0x00,0x36,0xaa,0x50,0x33,0xaf,0x61,0xac,0x5a,0x7a,0x03,0x00,0x00,0xd0,0x03,0x00,0x00,0x06,0x00,0x00,0x00,0x78,0x78,0x2e,0x74,0x69,0x66,0xf3,0xf4,0xd4,0x62,0xf8,0xc3,0xc4,0xc0,0xa0,0xb6,0xa0,0x22,0x53,0xf0,0x44,0x1f,0xbf,0x42,0x45,0x1a,0x1f,0x87,0x40,0x9f,0xf2,0x04,0x1b,0xa3,0xe3,0x9a,0xa7,0xe4,0x05,0x2e,0x3a,0x3f,0xe1,0x67,0x66,0x9e,0x62,0xe5,0xd3,0x27,0x6d,0x37,0x41,0xc1,0x79,0x42,0x4c,0xd1,0x9c,0x85,0x27,0xf4,0x2c,0x9d,0x6f,0x6c
};     // BIG DATA
static const TInt aSize=sizeof(aData);
#endif


#ifdef HUGETRACE
/* (1KB) */
static const TInt8 aData[] = 
{
	0x50,0x4b,0x03,0x04,0x14,0x00,0x02,0x00,0x08,0x00,0x36,0xaa,0x50,0x33,0xaf,0x61,
	0xac,0x5a,0x7a,0x03,0x00,0x00,0xd0,0x03,0x00,0x00,0x06,0x00,0x00,0x00,0x78,0x78,
	0x2e,0x74,0x69,0x66,0xf3,0xf4,0xd4,0x62,0xf8,0xc3,0xc4,0xc0,0xa0,0xb6,0xa0,0x22,
	0x53,0xf0,0x44,0x1f,0xbf,0x42,0x45,0x1a,0x1f,0x87,0x40,0x9f,0xf2,0x04,0x1b,0xa3,
	0xe3,0x9a,0xa7,0xe4,0x05,0x2e,0x3a,0x3f,0xe1,0x67,0x66,0x9e,0x62,0xe5,0xd3,0x27,
	0x6d,0x37,0x41,0xc1,0x79,0x42,0x4c,0xd1,0x9c,0x85,0x27,0xf4,0x2c,0x9d,0x6f,0x6c,
	0xb2,0xd0,0x98,0xb0,0xb8,0x45,0x49,0xee,0xc4,0x83,0x55,0x5c,0x5d,0x32,0x02,0x8a,
	0x37,0x32,0x59,0xc4,0x9c,0xf8,0x02,0x9e,0xf2,0x1d,0x3b,0xf1,0xa2,0x8f,0x4b,0x25,
	0xe4,0xad,0xc2,0x39,0x4b,0xbf,0x09,0x1d,0x1e,0x2a,0xd3,0x66,0x3a,0x6f,0x14,0x64,
	0x0b,0xf8,0x26,0x26,0x27,0x92,0xa9,0xd4,0xae,0xd8,0xf8,0xa4,0x22,0x32,0xf9,0x0b,
	0x50,0x5d,0xeb,0x84,0xc7,0x2d,0xc2,0xca,0x2d,0xcd,0x92,0xce,0x2f,0xbb,0x59,0x80,
	0x7c,0x8f,0x02,0x87,0x49,0x1e,0x2a,0xc1,0x3d,0x07,0x05,0x2f,0xca,0x18,0x6e,0x6a,
	0x77,0x64,0xb9,0xe4,0xa9,0xda,0xe5,0xb1,0xf0,0xa4,0xa5,0xf3,0x8a,0xa7,0xfc,0x17,
	0x36,0x7a,0x8a,0x58,0x38,0xd6,0x2a,0x38,0xb4,0xaa,0x04,0x3c,0xe5,0x97,0x35,0x3d,
	0xac,0x51,0xb1,0xa1,0x69,0x6b,0x47,0xb7,0x97,0xce,0xc2,0x53,0xb2,0xd3,0xf9,0x77,
	0xbf,0x64,0x11,0xd6,0x68,0x70,0x29,0x99,0x94,0x7a,0xa2,0x4f,0xac,0xe3,0xa5,0x88,
	0x65,0xa0,0xe2,0x84,0x8e,0x2e,0xcf,0xa5,0x1c,0x02,0x53,0x2c,0x54,0x02,0x7e,0x6b,
	0x5e,0x76,0x94,0x29,0x71,0x77,0x29,0xe3,0x14,0xbc,0xcc,0xe2,0x7e,0xc3,0x49,0x47,
	0xc8,0x3b,0x61,0x91,0x44,0xf7,0xd1,0x9b,0x2e,0xc5,0x19,0xbb,0x04,0x5c,0x6d,0xe7,
	0x94,0xb8,0x7b,0x08,0xca,0x73,0x28,0x02,0x5d,0xc1,0xbf,0xf1,0x10,0xe7,0x14,0x0b,
	0x25,0xab,0x25,0x1c,0x42,0x82,0x1b,0x33,0x0b,0x16,0x4d,0xb6,0x2a,0x9a,0xc2,0xa4,
	0x7c,0xec,0x93,0x9d,0xbb,0x43,0xa3,0xca,0x2e,0x8e,0xc4,0xc7,0x2e,0x25,0x12,0x8e,
	0x86,0x29,0xc7,0x1f,0x3b,0xcd,0xf2,0x50,0xce,0xb8,0xc5,0xf1,0xb8,0x5f,0x23,0x72,
	0x2d,0x4b,0xf0,0x22,0x2b,0xc1,0x54,0x3e,0x61,0x0e,0xc5,0x43,0xca,0x0b,0x9a,0x44,
	0xce,0xa5,0x54,0x8b,0x9c,0xf8,0x28,0x9b,0xa3,0xad,0xdc,0x14,0x31,0x57,0x40,0xc5,
	0xdd,0xb1,0xc5,0xdd,0x91,0xe5,0x14,0x5b,0x70,0x4b,0x23,0x93,0x47,0xc7,0x4b,0x16,
	0xf1,0xb6,0x1b,0x1b,0x3c,0x59,0x5a,0x15,0xb6,0xc5,0x0a,0x7e,0x08,0xd9,0xf1,0xa2,
	0x6f,0xa2,0xf3,0x26,0x2b,0x4f,0x15,0x41,0x59,0xa0,0xdb,0xc4,0x9a,0x2e,0x38,0x72,
	0x73,0x4f,0xb1,0x33,0x3e,0xa9,0x72,0xe2,0x61,0x73,0xd4,0xd5,0x26,0x96,0x9b,0xce,
	0xad,0x1f,0x2f,0xca,0x72,0x6b,0xd4,0x2c,0x3c,0x25,0x03,0x44,0x2b,0x38,0xfa,0x1a,
	0x99,0x1c,0xbf,0x77,0x38,0xf2,0xff,0x3b,0xd5,0xb4,0x85,0x7b,0xcb,0xb6,0x46,0x23,
	0x2b,0x8b,0x8e,0x97,0x2d,0x87,0xb8,0x94,0x04,0x7c,0x55,0xb6,0x29,0x09,0xc4,0x27,
	0x2a,0x4c,0xd2,0xa8,0x58,0xd8,0xc5,0xc9,0xcc,0xa1,0xab,0x32,0xed,0xc4,0x4b,0x95,
	0x49,0xbe,0xac,0x62,0x5d,0xb2,0x46,0xed,0xbc,0x2a,0x93,0x9c,0xbb,0x3d,0x55,0x26,
	0x3a,0xb7,0x2d,0xb2,0x5d,0x28,0x94,0xfc,0x70,0xba,0x9b,0x80,0x63,0xd4,0xa6,0x76,
	0x1b,0x0e,0xd7,0x4b,0x81,0x1a,0x45,0xc7,0xbd,0x2b,0x80,0x81,0x3b,0xc9,0x51,0xf0,
	0xcb,0x24,0x11,0x45,0x96,0x43,0xb2,0x4b,0x26,0x79,0xaa,0x70,0x08,0x7b,0xa8,0x04,
	0xbc,0x50,0x13,0xe4,0xb3,0x70,0x34,0x98,0x29,0x63,0xf8,0xff,0x1b,0xa7,0xe2,0xa3,
	0xb3,0x82,0xb2,0xae,0x2d,0x87,0x84,0x14,0x9e,0xf2,0x09,0xdd,0xf2,0x54,0x99,0xe4,
	0x64,0xc4,0x67,0xe3,0xc6,0x21,0xe4,0xc8,0xba,0x64,0x12,0x87,0x7a,0xa6,0xca,0x04,
	0xc7,0xf4,0x09,0x29,0x73,0x84,0x74,0x2a,0x57,0x2a,0xca,0x27,0xd9,0x2e,0xd9,0xc8,
	0xc2,0xa9,0x52,0x78,0xc1,0xd1,0xc5,0x49,0xf9,0xa9,0xd8,0x41,0x26,0x4f,0x85,0xee,
	0x35,0x0a,0xfe,0x97,0x38,0xd4,0xda,0x9f,0xf2,0x15,0x7e,0xab,0x76,0x68,0x35,0x99,
	0xe8,0x7c,0x3c,0x6c,0xc2,0x12,0x81,0x48,0xd9,0xf0,0x44,0x0e,0xc7,0x4c,0x96,0x89,
	0x25,0xb9,0x2c,0x01,0xcf,0x65,0x55,0x26,0x69,0x54,0xf6,0x73,0x8b,0x4c,0x17,0x93,
	0x16,0x70,0x68,0x9f,0x78,0x61,0x43,0x8b,0xdb,0xe2,0xbf,0xcc,0x97,0x37,0x34,0xbd,
	0x55,0x64,0x79,0xb3,0x5c,0xc3,0x04,0x98,0x28,0x58,0x38,0x75,0x94,0xb9,0xe6,0x14,
	0x74,0xc9,0x28,0xbd,0x50,0x58,0x2c,0xd0,0xb4,0x65,0xa2,0xf3,0x46,0xf1,0x8e,0x16,
	0x71,0x81,0x2d,0x0b,0xc5,0x1d,0x99,0x16,0x5c,0xf2,0x54,0x6a,0xb7,0x78,0x98,0xb1,
	0xa7,0x3e,0xfc,0x6d,0x4f,0xdf,0x41,0x26,0x1f,0xb3,0xbd,0x0a,0x1d,0x2f,0xfa,0xb6,
	0x86,0x35,0xcd,0x53,0x68,0x4c,0x6a,0x64,0xf2,0x71,0x65,0x9b,0xe0,0x58,0x28,0x28,
	0xc1,0xd0,0xc0,0xc1,0xc0,0xcf,0xc0,0xc0,0xc8,0xcc,0xc0,0xc8,0xc0,0xc0,0x50,0x01,
	0xc4,0x8c,0x50,0xb6,0x29,0x10,0x33,0x41,0xd9,0x20,0xcc,0x0c,0x65,0xb3,0x00,0x31,
	0x1b,0x94,0x0d,0x02,0x82,0x8c,0x2c,0x60,0x36,0x07,0x10,0x0b,0x21,0xa9,0x17,0x45,
	0x62,0x8b,0x21,0x99,0x29,0x0e,0x55,0xff,0x19,0x98,0xdb,0xa4,0x18,0x59,0xc1,0xec,
	0x6d,0xcc,0x0c,0x0c,0xd2,0x50,0xf6,0x3e,0x20,0x5b,0x06,0x49,0xaf,0x06,0x94,0x0d,
	0x54,0xce,0x60,0xc8,0xc8,0xc4,0xc0,0x05,0xa4,0x8f,0x31,0x33,0xc0,0x80,0x07,0x54,
	0x19,0x98,0xf6,0x2c,0x4a,0x4b,0xcc,0x0b,0xcb,0x4c,0x2d,0x67,0x00,0x00,0x50,0x4b,
	0x01,0x02,0x14,0x00,0x14,0x00,0x02,0x00,0x08,0x00,0x36,0xaa,0x50,0x33,0xaf,0x61,
	0xac,0x5a,0x7a,0x03,0x00,0x00,0xd0,0x03,0x00,0x00,0x06,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x78,0x78,0x2e,0x74,
	0x69,0x66,0x50,0x4b,0x05,0x06,0x00,0x00,0x00,0x00,0x01,0x00,0x01,0x00,0x34,0x00,
	0x00,0x00,0x9e,0x03,0x00,0x00,0x00,0x00
}; //HUGE DATA


static const TInt aSize=sizeof(aData);
#endif



#endif
