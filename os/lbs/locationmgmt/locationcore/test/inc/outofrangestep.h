/**
* Copyright (c) 2007-2009 Nokia Corporation and/or its subsidiary(-ies).
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



/**
 @file outofrangestep.h
 @internalTechnology
*/
#ifndef __OUTOFRANGE_STEP_H__
#define __OUTOFRANGE_STEP_H__
#include <test/testexecutestepbase.h>
#include "te_lbsadminsuitestepbase.h"

class COutOfRangeStep : public CTe_LbsAdminSuiteStepBase
	{
public:
	COutOfRangeStep();
	~COutOfRangeStep();
	virtual TVerdict doTestStepPreambleL();
	virtual TVerdict doTestStepL();
	virtual TVerdict doTestStepPostambleL();

private:
	};

_LIT(KOutOfRangeStep,"OutOfRangeStep");

#endif
