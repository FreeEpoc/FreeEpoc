/*
* Copyright (c) 2002-2008 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of the License "Eclipse Public License v1.0"
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description:   Declaration of the MWlanWsaEvent class.
*
*/

/*
* %version: 15 %
*/

#ifndef WLANWSAEVENT_H
#define WLANWSAEVENT_H

#ifndef RD_WLAN_DDK
#include <wha.h>
#else
#include <wlanwha.h>
#endif

class WlanContextImpl;

/**
*  interface for evenets generated by WHA 
*
*  @lib wlanumac.lib
*  @since S60 3.1
*/
class MWlanWsaEvent
    {
    public:  // Constructors and destructor
        
        /**
        * C++ default constructor.
        */
        MWlanWsaEvent() {};
        
        /**
        * Destructor.
        */
        virtual ~MWlanWsaEvent() {};

    public: // New functions

        // Command callbacks

        virtual void CommandResponse( 
            WlanContextImpl& aCtxImpl, 
            WHA::TCommandId aCommandId, 
            WHA::TStatus aStatus,
            const WHA::UCommandResponseParams& aCommandResponseParams ) = 0;

        virtual TBool CommandComplete( 
            WlanContextImpl& aCtxImpl, 
            WHA::TCompleteCommandId aCompleteCommandId, 
            WHA::TStatus aStatus,
            const WHA::UCommandCompletionParams& 
            aCommandCompletionParams ) = 0;

        virtual void Indication( 
            WlanContextImpl& aCtxImpl, 
            WHA::TIndicationId aIndicationId,
            const WHA::UIndicationParams& aIndicationParams ) = 0;

        // Frame receive

        virtual TAny* RequestForBuffer ( 
            WlanContextImpl& aCtxImpl,             
            TUint16 aLength ) = 0;

        virtual void ReceivePacket( 
            WlanContextImpl& aCtxImpl, 
            WHA::TStatus aStatus,
            const void* aFrame,
            TUint16 aLength,
            WHA::TRate aRate,
            WHA::TRcpi aRcpi,
            WHA::TChannelNumber aChannel,
            TUint8* aBuffer,
            TUint32 aFlags ) = 0;
    };

#endif      // WLANWSAEVENT_H