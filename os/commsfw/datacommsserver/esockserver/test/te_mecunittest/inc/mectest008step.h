// Copyright (c) 2009 Nokia Corporation and/or its subsidiary(-ies).
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
// mectest008step.h
//

/**
@file
*/


#ifndef MECTEST008STEP_H
#define MECTEST008STEP_H

#include "mecunitteststepbase.h"


_LIT(KMecTest008Step, "MecTest008");


class CMecTest008Step : public CMecUnitTestStepBase
	{
public:
	virtual ~CMecTest008Step();

public:
    explicit CMecTest008Step()
        : CMecUnitTestStepBase(KMecTest008Step)
        {
        }

    virtual TVerdict RunTestStepL();
    };
  
#endif
// MECTEST008STEP_H


