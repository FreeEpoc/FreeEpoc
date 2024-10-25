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
*
*/



/**
 @file registerformobilitynotificationStep.h
*/
#if (!defined REGISTERFORMOBILITYNOTIFICATION_STEP_H)
#define REGISTERFORMOBILITYNOTIFICATION_STEP_H
#include <testexecutestepbase.h>
#include "Te_EsockStepBase.h"

/**
Class implementing registerformobilitynotificationStep

@internalComponent
*/
class CregisterformobilitynotificationStep : public CTe_EsockStepBase
	{
public:
	CregisterformobilitynotificationStep(CCEsockTestBase*& aEsockTest);
	TVerdict doSingleTestStep();
	TBool DescriptionExists();

private:
	TEventContainerParams iParams; //current params (.ini)
	TBuf<KMaxTestExecuteNameLength> iEventName;
	};

_LIT(KregisterformobilitynotificationStep,"registerformobilitynotificationStep");

#endif //REGISTERFORMOBILITYNOTIFICATION_STEP_H

