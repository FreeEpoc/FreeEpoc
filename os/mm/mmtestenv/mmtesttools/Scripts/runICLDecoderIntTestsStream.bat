rem Copyright (c) 2007-2009 Nokia Corporation and/or its subsidiary(-ies).
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
rem Image Decoder Integration Tests
rem 
rem

del E:\Logs\TestResults\icl\imagedecoder\TSI_ICL_IMAGEDECODER_STREAM.htm

md  E:\Logs\
md  E:\Logs\TestResults\
md  E:\Logs\TestResults\icl\
md  E:\Logs\TestResults\icl\imagedecoder\

md  c:\icl\
md  c:\icl\testimages\
md  c:\icl\testimages\mbm\
md  c:\icl\testimages\jpeg\


copy E:\inttest\icl\testimages\jpeg\jpeg_small18.jpg c:\icl\testimages\jpeg\jpeg_small18.jpg
copy E:\inttest\icl\testimages\jpeg\jpeg_small07.jpg c:\icl\testimages\jpeg\jpeg_small07.jpg
copy E:\inttest\icl\testimages\jpeg\jpeg_small19.jpg c:\icl\testimages\jpeg\jpeg_small19.jpg
copy E:\inttest\icl\testimages\jpeg\jpeg_empty01.jpg c:\icl\testimages\jpeg\jpeg_empty01.jpg
copy E:\inttest\icl\testimages\jpeg\jpeg_small09.jpg c:\icl\testimages\jpeg\jpeg_small09.jpg
copy E:\inttest\icl\testimages\jpeg\jpeg_small12.jpg c:\icl\testimages\jpeg\jpeg_small12.jpg
copy E:\inttest\icl\testimages\jpeg\jpeg_small13.jpg c:\icl\testimages\jpeg\jpeg_small13.jpg
copy E:\inttest\icl\testimages\jpeg\jpeg_large02.jpg c:\icl\testimages\jpeg\jpeg_large02.jpg
copy E:\inttest\icl\testimages\jpeg\jpeg_small10.jpg c:\icl\testimages\jpeg\jpeg_small10.jpg
copy E:\inttest\icl\testimages\jpeg\jpeg_small15.jpg c:\icl\testimages\jpeg\jpeg_small15.jpg
copy E:\inttest\icl\testimages\jpeg\jpeg_small01.jpg c:\icl\testimages\jpeg\jpeg_small01.jpg
copy E:\inttest\icl\testimages\jpeg\jpeg_corrupt05.jpg c:\icl\testimages\jpeg\jpeg_corrupt05.jpg
copy E:\inttest\icl\testimages\jpeg\jpeg_corrupt02.jpg c:\icl\testimages\jpeg\jpeg_corrupt02.jpg
copy E:\inttest\icl\testimages\jpeg\jpeg_corrupt03.jpg c:\icl\testimages\jpeg\jpeg_corrupt03.jpg
copy E:\inttest\icl\testimages\jpeg\jpeg_corrupt01.jpg c:\icl\testimages\jpeg\jpeg_corrupt01.jpg
copy E:\inttest\icl\testimages\jpeg\jpeg_small14_a.jpg c:\icl\testimages\jpeg\jpeg_small14_a.jpg
copy E:\inttest\icl\testimages\jpeg\jpeg_average01.jpg c:\icl\testimages\jpeg\jpeg_average01.jpg
copy E:\inttest\icl\testimages\jpeg\jpeg_supersize01.jpg c:\icl\testimages\jpeg\jpeg_supersize01.jpg
copy E:\inttest\icl\testimages\jpeg\jpeg_multiscan.jpg c:\icl\testimages\jpeg\jpeg_multiscan.jpg
copy E:\inttest\icl\testimages\jpeg\jpeg_restartinterop.jpg c:\icl\testimages\jpeg\jpeg_restartinterop.jpg


testframework -q \icl\imagedecoder\tsi_icl_imagedecoder_stream.script
move C:\Logs\TestResults\icl\imagedecoder\*.htm E:\Logs\TestResults\icl\imagedecoder\


del c:\icl\testimages\mbm\*.*
del c:\icl\testimages\jpeg\*.*

REM Copy output images from hardware to MMC, if output images are generated for hw
REM E:\inttest\icl\ folder will be already existing in MMC
md E:\inttest\icl\outputimages\
md E:\inttest\icl\outputimages\mbm\
md E:\inttest\icl\outputimages\jpeg\

copy c:\icl\outputimages\mbm\*.* E:\inttest\icl\outputimages\mbm\*.*
del c:\icl\outputimages\mbm\*.*
copy c:\icl\outputimages\jpeg\*.* E:\inttest\icl\outputimages\jpeg\*.*
del c:\icl\outputimages\jpeg\*.*
