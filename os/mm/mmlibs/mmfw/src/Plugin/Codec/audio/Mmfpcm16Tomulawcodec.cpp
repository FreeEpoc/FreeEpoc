// Copyright (c) 1997-2009 Nokia Corporation and/or its subsidiary(-ies).
// All rights reserved.
// This component and the accompanying materials are made available
// under the terms of "Eclipse Public License v1.0"
// which accompanies this distribution, and is available
// at the URL "http://www.eclipse.org/legal/epl-v10.html".
//
// Initial Contributors:
// Nokia Corporation - initial contribution.
//
// Contributors:
//
// Description:
//

#include "MMFPcm16ToMuLawCodec.h"


// __________________________________________________________________________
// Implementation

CMMFCodec* CMMFPcm16MulawCodec::NewL(TAny* aInitParams)
	{
	CMMFPcm16MulawCodec* self=new(ELeave) CMMFPcm16MulawCodec();
	CleanupStack::PushL(self);
	self->ConstructL(aInitParams);
	CleanupStack::Pop(self);
	return STATIC_CAST( CMMFCodec*, self );
	}

CMMFPcm16MulawCodec::~CMMFPcm16MulawCodec()
	{
	}

CMMFPcm16MulawCodec::CMMFPcm16MulawCodec()
	{
	}

void CMMFPcm16MulawCodec::ConstructL(TAny*  /*aInitParams*/)
	{
	}


//this codec converts 2 bytes into 1
TCodecProcessResult CMMFPcm16MulawCodec::ProcessL(const CMMFBuffer& aSrc, CMMFBuffer& aDst)
	{

	TCodecProcessResult result;
	result.iStatus = TCodecProcessResult::EProcessIncomplete;

	//convert from generic CMMFBuffer to CMMFDataBuffer
	iSrc = STATIC_CAST(const CMMFDataBuffer*, &aSrc);
	iDst = STATIC_CAST(CMMFDataBuffer*, &aDst);

	const TUint dstMaxLen = iDst->Data().MaxLength();

	if (!dstMaxLen)
		User::Leave(KErrArgument);

	//don't scribble Destination (pDst) by only consuming enough source to fill pDst
	TUint srcUse = (dstMaxLen - iDst->Position()) * 2;
	const TUint srcLen = iSrc->Data().Length();
	const TUint sourceRemain = srcLen - iSrc->Position();

	//make sure we don't blow source by checking against remaining
	//and clipping to minimum remaining if necessary
	srcUse = (srcUse<sourceRemain ? srcUse : sourceRemain);

	//we need to cast away CONST even on the source, as the TClass needs a TUint8*
	TUint8* pSrc = CONST_CAST(TUint8*,iSrc->Data().Ptr());
	pSrc += iSrc->Position();
	TUint8* pDst = CONST_CAST(TUint8*,iDst->Data().Ptr());
	pDst += iDst->Position();

	//compress TWO bytes (16-bit PCM word) into a to 1 byte sample
	i16PcmToMulaw.Convert(pSrc, pDst, srcUse / 2);

	TUint dstBytesAdded = srcUse / 2;

	if (dstBytesAdded + iDst->Position() < dstMaxLen)
		result.iStatus = TCodecProcessResult::EDstNotFilled;

	else if (srcUse + iSrc->Position() >= srcLen)
		result.iStatus = TCodecProcessResult::EProcessComplete;

	result.iSrcBytesProcessed = srcUse;
	result.iDstBytesAdded = dstBytesAdded;

	iDst->Data().SetLength(iDst->Position() + result.iDstBytesAdded);

	return result;

	}
