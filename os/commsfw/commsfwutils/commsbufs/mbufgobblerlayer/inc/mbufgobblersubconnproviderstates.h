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
// Connection Provider Declaration
//  (control plane)
//
//
//  This is a 3-plane comms layer implementation example, which has been customised to be a test layer which gobbles and releases ESOCK MBUFs.
//  The MBuf gobbling functionality can be disabled by undefining the macro SYMBIAN_COMMSFW_MBUF_GOBBLER which is specified in mbufgobblerproviders.mmp.
//  When SYMBIAN_COMMSFW_MBUF_GOBBLER is undefined, the source code specified by mbufgobblerproviders.mmp becomes a pass through layer i.e. it passes the data
//  through to the layer above or below without altering it. This makes it useful as a starting point for implementing your own layers / providers;
//  useful documentation on how to customise your own passthrough layer can be found in ..\docs\MbufGobblerLayer.doc
//

/**
 @file
 @internalComponent
*/

#ifndef MBUFGOBBLERSUBCONNPROVIDERSTATES_H
#define MBUFGOBBLERSUBCONNPROVIDERSTATES_H

// INCLUDES
#include <e32std.h>
#include <e32base.h>

// CLASS DECLARATION

/**
 *  CMbufGobblerSubconnMeshStates
 * 
 */
class CMbufGobblerSubconnMeshStates : public CBase
	{
public:
	// Constructors and destructor

	/**
	 * Destructor.
	 */
	~CMbufGobblerSubconnMeshStates();

	/**
	 * Two-phased constructor.
	 */
	static CMbufGobblerSubconnMeshStates* NewL();

	/**
	 * Two-phased constructor.
	 */
	static CMbufGobblerSubconnMeshStates* NewLC();

private:

	/**
	 * Constructor for performing 1st stage construction
	 */
	CMbufGobblerSubconnMeshStates();

	/**
	 * EPOC default constructor for performing 2nd stage construction
	 */
	void ConstructL();

	};

#endif // MBUFGOBBLERSUBCONNPROVIDERSTATES_H
