/*
* Copyright (c) 2005-2009 Nokia Corporation and/or its subsidiary(-ies).
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



#ifndef __T_VOLUME_INFO_DATA_H__
#define __T_VOLUME_INFO_DATA_H__

//	User Includes
#include "DataWrapperBase.h"
#include "T_FsData.h"

//	EPOC includes
#include <f32file.h>
#include <e32std.h>
#include <f32fsys.h>


class CT_VolumeInfoData: public CDataWrapperBase
	{
public:
	static CT_VolumeInfoData* NewL();
	~CT_VolumeInfoData();

	virtual TBool DoCommandL(const TTEFFunction& aCommand, const TTEFSectionName& aSection, const TInt aAsyncErrorIndex);
	virtual TAny* GetObject();
	virtual void SetObjectL(TAny* aAny);
	virtual void DisownObjectL();	
	inline virtual TCleanupOperation CleanupOperation();

protected:
	CT_VolumeInfoData();
	void ConstructL();

private:	
    inline void DoCleanup();
    inline void DoCmdNew();
    
    static void CleanupOperation(TAny* aAny);

private:
	
	//	TVolumeInfo class instance that is tested
	TVolumeInfo*		iVolumeInfo;
	};

#endif // __T_VOLUME_INFO_DATA_H__
