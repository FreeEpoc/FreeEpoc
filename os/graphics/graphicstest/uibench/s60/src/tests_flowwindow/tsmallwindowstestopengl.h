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

/**
 @file
 @test
 @internalComponent - Internal Symbian test code 
*/
 
#ifndef TSMALLWINDOWSTESTOPENGL_H
#define TSMALLWINDOWSTESTOPENGL_H

#include "te_graphicsperformanceSuiteStepBase.h"
#include "tflowwindowscontroller.h"


/**
 *  CTSmallWindowsTestOpenGL
 * 
 */
class CTSmallWindowsTestOpenGL : public CTe_graphicsperformanceSuiteStepBase
	{
public:
	CTSmallWindowsTestOpenGL();
	virtual ~CTSmallWindowsTestOpenGL();

private:
	// From CTestStep
	virtual TVerdict doTestStepPreambleL();
	virtual TVerdict doTestStepL();
	
	void FlowWindowsL();

private:	
	CTFlowWindowsController* iFlowWindowsController;
	RArray<TPtrC> iFileNames;
	TSize iWindowSize;
	TInt iIterationsToTest;	
	};

_LIT(KTSmallWindowsOpenGL, "tsmallwindowsopengl");

#endif // TSMALLWINDOWSTESTOPENGL_H
