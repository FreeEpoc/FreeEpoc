/*
* Copyright (c) 2002 Nokia Corporation and/or its subsidiary(-ies).
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
* Description: DRM Player
*
*/

#ifndef __PARAMETERS_H
#define __PARAMETERS_H

#include <e32std.h>
#include <e32base.h>

class CParameters : public CBase
	{
public:
	TInt iAction;
	CParameters(const TInt &aAction = 0);
	//virtual ~CParameters();
	};

#endif	//__PARAMETERS_H
