// Copyright (c) 2008-2009 Nokia Corporation and/or its subsidiary(-ies).
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
 @file te_agpsmanagerstep13.cpp
*/
 
#include "te_agpsmanagerstep13.h"
#include "te_agpsmanagersuitedefs.h"
#include <lbs/lbslocdatasourceclasstypes.h>


CTe_AgpsManagerStep13::~CTe_AgpsManagerStep13()
	{
	}

CTe_AgpsManagerStep13::CTe_AgpsManagerStep13()
	{
	SetTestStepName(KAgpsManagerStep13);
	}

TVerdict CTe_AgpsManagerStep13::doTestStepPreambleL()
	{
	CTe_AgpsManagerStepBase::doTestStepPreambleL();
	return TestStepResult();
	}

// Valid Combinations of Positioning Methods in Location
// Requests from LS and NRH in Terminal Assisted only H/W.
// This test ensures that, for hardware only capable of
// Terminal Based positioning, when both the LS and NRH issue
// a Location Request with a valid positioning method
// (Autonomous or Terminal Based), the GPS Module receives a call
// to set new gps options with that positioning method.
//
TVerdict CTe_AgpsManagerStep13::doTestStepL()
	{
 	if (TestStepResult()==EPass)
 		{
		CLbsAdmin* admin;
		TLbsGpsOptions gpsOptions;
		TTime time;
		TLbsLocRequestQualityInt quality;

		// Configure H/W Capabilities as Terminal Based only
		__ASSERT_ALWAYS(KErrNone == iCapabilitiesProperty.Set(KManagerTestSuiteUid, CTe_AgpsManagerStepBase::ETestCapabilitiesKey, TPositionModuleInfoExtended::EDeviceGpsModeTerminalAssisted), User::Invariant());
		
		// Set admin gps mode to Terminal Based. Get current GPS mode so
		// that admin can be returned to its original value at the end of the test
		//
		admin = CLbsAdmin::NewL();
		CleanupStack::PushL(admin);
		CLbsAdmin::TGpsMode originalMode; 
		admin->Get(KLbsSettingRoamingGpsMode, originalMode);
		admin->Set(KLbsSettingRoamingGpsMode, CLbsAdmin::EGpsPreferTerminalAssisted);

		//*******************************************************************************************
		//************* LS: Terminal Assisted; NRH: Terminal Assisted *******************************
		//*******************************************************************************************
		//Inject a location request from LS for Terminal Assisted mode		
		iLsToManagerRequestInjector->RequestPositionUpdate(CTestAgpsRequestSender::ETPosMethodTa);
		// Verify that the Manager called SetGpsOptions to set autonomous followed by a location
		// request
		iGpsModuleObserver->WaitForCallBack();
		__ASSERT_ALWAYS(iGpsModuleObserver->WereGpsOptionsSet(gpsOptions), User::Invariant());
		__ASSERT_ALWAYS(ELbsGpsOptionsClass == gpsOptions.ClassType(), User::Invariant());
		__ASSERT_ALWAYS(CLbsAdmin::EGpsPreferTerminalAssisted == gpsOptions.GpsMode(), User::Invariant());
		__ASSERT_ALWAYS(iGpsModuleObserver->WasLocationUpdateRequested(time, quality), User::Invariant());
	
		// Inject a location request from NRH for Terminal Assisted method
		iNrhToManagerRequestInjector->RequestPositionUpdate(CTestAgpsRequestSender::ETPosMethodTa);
		// Verify that the Manager sent to the module a location request
		iGpsModuleObserver->WaitForCallBack();
		__ASSERT_ALWAYS(iGpsModuleObserver->WasLocationUpdateRequested(time, quality), User::Invariant());

		// Cancel NRH location request
		iNrhToManagerRequestInjector->CancelPositionUpdate();
		// Verify new location request with only LS requirements sent to GPS Module
		iGpsModuleObserver->WaitForCallBack();
		__ASSERT_ALWAYS(iGpsModuleObserver->WasLocationUpdateRequested(time, quality), User::Invariant());

		// Cancel LS location request
		iLsToManagerRequestInjector->CancelPositionUpdate();
		// Expect a cancel sent to the GPS Module
		iGpsModuleObserver->WaitForCallBack();
		__ASSERT_ALWAYS(iGpsModuleObserver->WasLocationUpdateCancelled(), User::Invariant());
		// Ensure that no other messages were sent to the GPS module
		__ASSERT_ALWAYS(!iGpsModuleObserver->IsMoreActivityObserved(), User::Invariant());
		
		// Reset Admin to to value it had before the test changed it
		admin->Set(KLbsSettingRoamingGpsMode, originalMode);

		CleanupStack::PopAndDestroy(admin);
		}
	  return TestStepResult();
	}

TVerdict CTe_AgpsManagerStep13::doTestStepPostambleL()
	{
	CTe_AgpsManagerStepBase::doTestStepPostambleL();
	return TestStepResult();
	}
