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


#ifndef __EGLTEST_ENDPOINTSTREAMING_H__
#define __EGLTEST_ENDPOINTSTREAMING_H__

#include "egltest_endpoint_engine.h"

_LIT(KEGL_EndpointStreaming, "EGL_EndpointStreaming");
NONSHARABLE_CLASS(CEglTest_LocalTestStep_EndpointStreaming) : public CEgltest_Local_Engine
    {
public:
    CEglTest_LocalTestStep_EndpointStreaming();
    };

#endif
