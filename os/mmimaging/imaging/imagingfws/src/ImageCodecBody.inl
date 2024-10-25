// Copyright (c) 2001-2009 Nokia Corporation and/or its subsidiary(-ies).
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
// inline implementation for the Codec Body classes
// 
//

#ifndef __CImageCodecBody_inl
#define __CImageCodecBody_inl

// CImageProcessorReadCodecBody

inline CImageProcessor* CImageProcessorReadCodecBody::ImageProcessor() const
	{
	return iImageProc;
	}

inline const TPoint& CImageProcessorReadCodecBody::Pos() const
	{
	return iPos;
	}

inline TPoint& CImageProcessorReadCodecBody::Pos()
	{
	return iPos;
	}

inline void CImageProcessorReadCodecBody::SetPos(const TPoint& aPos)
	{
	iPos = aPos;
	}

// CImageMaskProcessorReadCodecBody

inline CImageProcessor* CImageMaskProcessorReadCodecBody::MaskProcessor() const
	{
	return iMaskProc;
	}

#endif  // __CImageCodecBody_inl
