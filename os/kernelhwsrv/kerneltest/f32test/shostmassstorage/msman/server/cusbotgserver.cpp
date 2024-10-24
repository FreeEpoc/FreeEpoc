// Copyright (c) 2009 Nokia Corporation and/or its subsidiary(-ies).
// All rights reserved.
// This component and the accompanying materials are made available
// under the terms of the License "Eclipse Public License v1.0"
// which accompanies this distribution, and is available
// at the URL "http://www.eclipse.org/legal/epl-v10.html".
//
// Initial Contributors:
// Nokia Corporation - initial contribution.
//
// Contributors:
//
// Description:
// Implements a Symbian OS server that exposes the RUsbMassStorage API
// 
//



/**
 @file
 @internalTechnology
*/

#include <e32svr.h>
#include <f32file.h>

#include <d32usbdi_hubdriver.h>
#include <d32otgdi.h>

#include "usbtypes.h"
#include "cusbotg.h"

#include "msmanclientserver.h"
#include "cusbotgserver.h"
#include "cusbotgsession.h"

#include "tmslog.h"

CUsbOtgServer* CUsbOtgServer::NewLC()
	{
    __MSFNSLOG
	CUsbOtgServer* r = new (ELeave) CUsbOtgServer();
	CleanupStack::PushL(r);
    r->ConstructL();
	return r;
	}


CUsbOtgServer::CUsbOtgServer()
:   CServer2(EPriorityLow)
	{
    __MSFNSLOG
	}


void CUsbOtgServer::ConstructL()
    {
    __MSFNSLOG

	iUsbOtg = CUsbOtg::NewL();
	StartL(KUsbOtgServerName);
    }


CUsbOtgServer::~CUsbOtgServer()
	{
    __MSFNSLOG
    delete iUsbOtg;
	}


CSession2* CUsbOtgServer::NewSessionL(const TVersion &aVersion, const RMessage2& /*aMessage*/) const
	{
    __MSFNSLOG
	TVersion v(KUsbOtgSrvMajorVersionNumber, KUsbOtgSrvMinorVersionNumber, KUsbOtgSrvBuildVersionNumber);

	if (!User::QueryVersionSupported(v, aVersion))
		User::Leave(KErrNotSupported);

	CUsbOtgSession* session = CUsbOtgSession::NewL();

	return session;
	}



TInt CUsbOtgServer::RunError(TInt aError)
	{
    __MSFNSLOG

	Message().Complete(aError);
	ReStart();
    return KErrNone;
	}


void CUsbOtgServer::AddSession()
    {
    __MSFNSLOG
    ++iSessionCount;
    }

void CUsbOtgServer::RemoveSession()
    {
    __MSFNSLOG
    if (--iSessionCount == 0)
        {
        User::After(1000000);
        CActiveScheduler::Stop();
        }
    }
