/*
* Copyright (c) 2008-2009 Nokia Corporation and/or its subsidiary(-ies).
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
* file te_sysutiltestdevicetypeinfo.h
* 
*
*/



#ifndef __TE_SYSUTIL_TEST_DEVICE_TYPE_INFO_SERVER_H__
#define __TE_SYSUTIL_TEST_DEVICE_TYPE_INFO_SERVER_H__

#include "te_sysutilburtestserver.h"
#include <babackup.h>
#include "te_sysutilburtestbase.h"

_LIT(KSysUtilTestDeviceTypeInfoPreBackupRestoreStep, "SysUtilTestDeviceTypeInfoPreBackupRestoreStep");
_LIT(KSysUtilTestDeviceTypeInfoPostBackupRestoreStep, "SysUtilTestDeviceTypeInfoPostBackupRestoreStep");

class CSysUtilTestDeviceTypeInfoStep : public CTeSysUtilSuiteStepBase
	{
public:
	CSysUtilTestDeviceTypeInfoStep(const TDesC& aStepName, CSysUtilBurTestServer& aTestServer);
	~CSysUtilTestDeviceTypeInfoStep();
	TVerdict doTestStepL();
	TVerdict PreBackupRestoreL();
	TVerdict PostBackupRestoreL();
	static void TestAllAPIsL();
private:
	// Store a reference to the test server so that we can call it's functions. This is
	// required so we can set which set of APIs should be called during a backup and restore.
	CSysUtilBurTestServer& iTestServer;
	};

#endif
