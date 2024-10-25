// Copyright (c) 2010 Nokia Corporation and/or its subsidiary(-ies).
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
// Implements backup and restore support for the Bluetooth Manager server.
//


inline TInt CBTManServerBURMgr::TransitionState(TBTBUREvent aBUREvent)
	{
	return iStateMachine->TransitionState(aBUREvent);
	}

inline TBool CBTRegistryBURData::HasRegistryData() const
	{
	return iHasRegistryData;
	}

inline TBTBURState CBTManServerBURMgrStateFactory::GetCurrentState()
	{
	return iState;
	}

inline TBTBURState CBTManServerBURMgrStateAction::GetThisState()
	{
	return iState;
	}
