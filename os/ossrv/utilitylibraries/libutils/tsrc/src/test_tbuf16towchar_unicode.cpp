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

#include <stdio.h>
#include<e32std.h>
#include "libutils.h"
#include"std_log_result.h"
#define LOG_FILENAME_LINE __FILE__, __LINE__
int main()
{
    __UHEAP_MARK;
    _LIT16(Kname,"\xAE");
    TBuf16<20>src(Kname);
    wchar_t * des= new wchar_t [30]; 
    int size=50;
    int retval =ESuccess;
    retval= Tbuf16ToWchar(src,des,size);

    if(retval ==ESuccess)
    {
    printf(" Test_tbuf16towchar_unicode PASSED\n");
    }
    else
    {
    assert_failed = true;
    printf(" Test_tbuf16towchar_unicode FAILURE\n");
    }
    delete[] des;
    des = NULL;
    __UHEAP_MARKEND;
    testResultXml("test_tbuf16towchar_unicode");
	return 0;
}
