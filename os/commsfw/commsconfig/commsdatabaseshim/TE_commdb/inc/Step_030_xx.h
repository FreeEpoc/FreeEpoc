/*
* Copyright (c) 2009 Nokia Corporation and/or its subsidiary(-ies).
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
// This is the header file for CommDb test 030.XX group of scenarios 

#include<cdbpreftable.h>

#if (!defined __STEP_030_XX_H__)
#define __STEP_030_XX_H__


////////////////////
//	Test step 030.01
////////////////////

NONSHARABLE_CLASS(CCommDbTest030_01) : public CTestStepCommDb
{
public:
	CCommDbTest030_01();
	~CCommDbTest030_01();

	virtual enum TVerdict doTestStepL( void );
	TInt executeStepL();
	TVerdict doTestStepPreambleL();
	TVerdict doTestStepPostambleL();

private:
	CCommsDbConnectionPrefTableView* iPrefView;
};

////////////////////
//	Test step 030.01
////////////////////

NONSHARABLE_CLASS(CCommDbTest030_02) : public CTestStepCommDb
{
public:
	CCommDbTest030_02();
	~CCommDbTest030_02();

	virtual enum TVerdict doTestStepL( void );
	TInt executeStepL();
	TVerdict doTestStepPreambleL();
	TVerdict doTestStepPostambleL();

private:
	CCommsDbConnectionPrefTableView* iPrefView;
};

////////////////////
//	Test step 030.03
////////////////////

NONSHARABLE_CLASS(CCommDbTest030_03) : public CTestStepCommDb
{
public:
	CCommDbTest030_03();
	~CCommDbTest030_03();

	virtual enum TVerdict doTestStepL( void );
};

#endif //__STEP_030_XX_H__
