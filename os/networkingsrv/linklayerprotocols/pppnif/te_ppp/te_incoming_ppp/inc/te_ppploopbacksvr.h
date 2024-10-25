// Copyright (c) 2004-2009 Nokia Corporation and/or its subsidiary(-ies).
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
// Standard TestExecute server header:
// Interface for PPP loopback testing testsuite. 
// No PPP specifics here.
// 
//

/**
 @file
 @internalComponent
*/


#ifndef __TE_PPP_LOOPBACKSVR_H__
#define __TE_PPP_LOOPBACKSVR_H__

#include <test/testexecuteserverbase.h>

/**
TestSuite server

@internalComponent
@test
*/
class CTe_PppLoopbackSvr : public CTestServer
	{
public:
	static CTe_PppLoopbackSvr* NewL();
	virtual CTestStep* CreateTestStep(const TDesC& aStepName);
	RFs& Fs(){return iFs;};

private:
	RFs iFs;
	};
	
#endif
