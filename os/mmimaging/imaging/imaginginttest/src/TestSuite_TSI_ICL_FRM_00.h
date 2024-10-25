// Copyright (c) 2002-2009 Nokia Corporation and/or its subsidiary(-ies).
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

#ifndef __TESTSUITE_TSI_ICL_FRM_00_H__
#define __TESTSUITE_TSI_ICL_FRM_00_H__

#include <testframework.h>

// Base class for the TS_MM_TSTH_U_22 suite
class  CTestSuite_TSI_ICL_FRM_00 : public CTestSuite
	{
public:
	void InitialiseL();
	virtual ~CTestSuite_TSI_ICL_FRM_00();
	TPtrC GetVersion() const;
	};


#endif //__TESTSUITE_TSI_ICL_FRM_00_H__
