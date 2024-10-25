/*
* Copyright (c) 2002-2003 Nokia Corporation and/or its subsidiary(-ies).
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
*
*/

#ifndef __MMF_TMMFAUDIO_PCM16BE_TO_PCMS16_CODEC_H__
#define __MMF_TMMFAUDIO_PCM16BE_TO_PCMS16_CODEC_H__
#include <e32std.h>
#include "MMFAudioCodecBase.h"

/*
*
* class TMMFAudioPcmU16BeToPcmS16Codec
*
*/
class TMMFAudioPcmU16BeToPcmS16Codec : public TMMFAudioCodecBase
	{
public:
	IMPORT_C virtual void Convert(TUint8* aSrc, TUint8* aDst, TInt aSamples);
	};

#endif //__MMF_TMMFAUDIO_PCM16BE_TO_PCMS16_CODEC_H__
