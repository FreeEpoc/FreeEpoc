
// TestEffectCustom.h

// Copyright (c) 2005-2009 Nokia Corporation and/or its subsidiary(-ies).
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

#ifndef TESTEFFECTCUSTOM_H
#define TESTEFFECTCUSTOM_H

class MTestEffectCustomIf
	{
public:
	virtual void SetActive(TBool aValue)=0;
	virtual void GenCallbackL()=0;
	};

#endif // TESTEFFECTCUSTOM_H
