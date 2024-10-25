rem Copyright (c) 2004-2009 Nokia Corporation and/or its subsidiary(-ies).
rem All rights reserved.
rem This component and the accompanying materials are made available
rem under the terms of "Eclipse Public License v1.0"
rem which accompanies this distribution, and is available
rem at the URL "http://www.eclipse.org/legal/epl-v10.html".
rem
rem Initial Contributors:
rem Nokia Corporation - initial contribution.
rem
rem Contributors:
rem
rem Description:
rem

del E:\Logs\TestResults\TSU_ICL_MEDIASVR*.*
md E:\Logs
md E:\Logs\TestResults

REM ***********************************************
REM ************** MEDIASVR TESTS *****************
REM ***********************************************

md c:\MediaSvrTest\
md c:\MediaSvrTest\stress\

copy E:\unittest\icl\mediasvr\bmp1bpp.bmp c:\MediaSvrTest\bmp1bpp.bmp
copy E:\unittest\icl\mediasvr\bmp24bpp.bmp c:\MediaSvrTest\bmp24bpp.bmp
copy E:\unittest\icl\mediasvr\bmp4bpp.bmp c:\MediaSvrTest\bmp4bpp.bmp
copy E:\unittest\icl\mediasvr\bmp8bpp.bmp c:\MediaSvrTest\bmp8bpp.bmp
copy E:\unittest\icl\mediasvr\bmprle4.bmp c:\MediaSvrTest\bmprle4.bmp
copy E:\unittest\icl\mediasvr\bmprle8.bmp c:\MediaSvrTest\bmprle8.bmp
copy E:\unittest\icl\mediasvr\GifComment.gif c:\MediaSvrTest\GifComment.gif
copy E:\unittest\icl\mediasvr\jfif10.jpg c:\MediaSvrTest\jfif10.jpg
copy E:\unittest\icl\mediasvr\jfif100.jpg c:\MediaSvrTest\jfif100.jpg
copy E:\unittest\icl\mediasvr\jfif30.jpg c:\MediaSvrTest\jfif30.jpg
copy E:\unittest\icl\mediasvr\jfif420.jpg c:\MediaSvrTest\jfif420.jpg
copy E:\unittest\icl\mediasvr\jfif422.jpg c:\MediaSvrTest\jfif422.jpg
copy E:\unittest\icl\mediasvr\jfif444.jpg c:\MediaSvrTest\jfif444.jpg
copy E:\unittest\icl\mediasvr\jfif60.jpg c:\MediaSvrTest\jfif60.jpg
copy E:\unittest\icl\mediasvr\jfifMono.jpg c:\MediaSvrTest\jfifMono.jpg
copy E:\unittest\icl\mediasvr\jfifProg.jpg c:\MediaSvrTest\jfifProg.jpg
copy E:\unittest\icl\mediasvr\mbm12bpp.mbm c:\MediaSvrTest\mbm12bpp.mbm
copy E:\unittest\icl\mediasvr\mbm16bpp.mbm c:\MediaSvrTest\mbm16bpp.mbm
copy E:\unittest\icl\mediasvr\mbm1bpp.mbm c:\MediaSvrTest\mbm1bpp.mbm
copy E:\unittest\icl\mediasvr\mbm24bpp.mbm c:\MediaSvrTest\mbm24bpp.mbm
copy E:\unittest\icl\mediasvr\mbm2bpp.mbm c:\MediaSvrTest\mbm2bpp.mbm
copy E:\unittest\icl\mediasvr\mbm4bppc.mbm c:\MediaSvrTest\mbm4bppc.mbm
copy E:\unittest\icl\mediasvr\mbm4bppm.mbm c:\MediaSvrTest\mbm4bppm.mbm
copy E:\unittest\icl\mediasvr\mbm8bppc.mbm c:\MediaSvrTest\mbm8bppc.mbm
copy E:\unittest\icl\mediasvr\mbm8bppm.mbm c:\MediaSvrTest\mbm8bppm.mbm
copy E:\unittest\icl\mediasvr\png1.png c:\MediaSvrTest\png1.png
copy E:\unittest\icl\mediasvr\png2.png c:\MediaSvrTest\png2.png
copy E:\unittest\icl\mediasvr\png3.png c:\MediaSvrTest\png3.png
copy E:\unittest\icl\mediasvr\png4.png c:\MediaSvrTest\png4.png
copy E:\unittest\icl\mediasvr\tif1.tif c:\MediaSvrTest\tif1.tif
copy E:\unittest\icl\mediasvr\tif2.tif c:\MediaSvrTest\tif2.tif
copy E:\unittest\icl\mediasvr\tif3.tif c:\MediaSvrTest\tif3.tif
copy E:\unittest\icl\mediasvr\wmf1.wmf c:\MediaSvrTest\wmf1.wmf
copy E:\unittest\icl\mediasvr\wmf2.wmf c:\MediaSvrTest\wmf2.wmf
copy E:\unittest\icl\mediasvr\wmf3.wmf c:\MediaSvrTest\wmf3.wmf
copy E:\unittest\icl\mediasvr\wmf4.wmf c:\MediaSvrTest\wmf4.wmf
copy E:\unittest\icl\mediasvr\wmf5.wmf c:\MediaSvrTest\wmf5.wmf
copy E:\unittest\icl\mediasvr\wmf6.wmf c:\MediaSvrTest\wmf6.wmf
copy E:\unittest\icl\mediasvr\trans.gif c:\MediaSvrTest\trans.gif
copy E:\unittest\icl\mediasvr\ref.gif c:\MediaSvrTest\ref.gif
copy E:\unittest\icl\mediasvr\stress\bmp24bpp.bmp c:\MediaSvrTest\stress\bmp24bpp.bmp
copy E:\unittest\icl\mediasvr\stress\jfif100.jpg c:\MediaSvrTest\stress\jfif100.jpg
copy E:\unittest\icl\mediasvr\stress\mbm24bpp.mbm c:\MediaSvrTest\stress\mbm24bpp.mbm

testframework -q TSU_ICL_MEDIASVR.script
move C:\Logs\TestResults\*.htm E:\Logs\TestResults\

testframework -q TSU_ICL_MEDIASVR_alloc.script
move C:\Logs\TestResults\*.htm E:\Logs\TestResults\

del c:\MediaSvrTest\stress\*.*
del c:\MediaSvrTest\*.*