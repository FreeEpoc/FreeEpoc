// Copyright (c) 2001-2009 Nokia Corporation and/or its subsidiary(-ies).
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
// EsocOpenServer.cpp
// This is the header file for ESCOK test 1.1
// 
//


#if (!defined __ESOCKOPENSERVER_H__)
#define __ESOCKOPENSERVER_H__
#include "TestStepEsock.h"


class CEsockOpenServer : public CTestStepEsock
	{
	public:
		static const TDesC& GetTestName();
		~CEsockOpenServer();
		
		virtual enum TVerdict easyTestStepL();
	};

#endif //(__ESOCKOPENSERVER_H__)

