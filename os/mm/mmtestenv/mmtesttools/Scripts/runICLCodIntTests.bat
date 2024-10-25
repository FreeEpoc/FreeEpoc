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
rem *************** ICL COD TESTS *****************
rem 
rem

runtsiiclcod05tests.bat
runtsiicldirscandecode01tests.bat

del E:\Logs\TestResults\TSI_ICL_COD*.*
md E:\Logs\
md E:\Logs\TestResults\

md c:\ICL\
md c:\ICL\Validation\
md c:\ICL\Validation\bmp

copy E:\inttest\ICL\Validation\bmp\00000042.bmp c:\ICL\Validation\bmp\00000042.bmp
copy E:\inttest\ICL\Validation\bmp\00000047.bmp c:\ICL\Validation\bmp\00000047.bmp
copy E:\inttest\ICL\Validation\bmp\00000051.bmp c:\ICL\Validation\bmp\00000051.bmp
copy E:\inttest\ICL\Validation\bmp\00000053.bmp c:\ICL\Validation\bmp\00000053.bmp
copy E:\inttest\ICL\Validation\bmp\00000064.bmp c:\ICL\Validation\bmp\00000064.bmp
copy E:\inttest\ICL\Validation\bmp\00000074.bmp c:\ICL\Validation\bmp\00000074.bmp
copy E:\inttest\ICL\Validation\bmp\00000075.bmp c:\ICL\Validation\bmp\00000075.bmp
copy E:\inttest\ICL\Validation\bmp\00000079.bmp c:\ICL\Validation\bmp\00000079.bmp
copy E:\inttest\ICL\Validation\bmp\00000080.bmp c:\ICL\Validation\bmp\00000080.bmp
copy E:\inttest\ICL\Validation\bmp\00000085.bmp c:\ICL\Validation\bmp\00000085.bmp
copy E:\inttest\ICL\Validation\bmp\00000086.bmp c:\ICL\Validation\bmp\00000086.bmp
copy E:\inttest\ICL\Validation\bmp\00000088.bmp c:\ICL\Validation\bmp\00000088.bmp
copy E:\inttest\ICL\Validation\bmp\00000096.bmp c:\ICL\Validation\bmp\00000096.bmp
copy E:\inttest\ICL\Validation\bmp\00000097.bmp c:\ICL\Validation\bmp\00000097.bmp
copy E:\inttest\ICL\Validation\bmp\00000106.bmp c:\ICL\Validation\bmp\00000106.bmp
copy E:\inttest\ICL\Validation\bmp\00000117.bmp c:\ICL\Validation\bmp\00000117.bmp
copy E:\inttest\ICL\Validation\bmp\00000128.bmp c:\ICL\Validation\bmp\00000128.bmp
copy E:\inttest\ICL\Validation\bmp\00000139.bmp c:\ICL\Validation\bmp\00000139.bmp
copy E:\inttest\ICL\Validation\bmp\00000150.bmp c:\ICL\Validation\bmp\00000150.bmp
copy E:\inttest\ICL\Validation\bmp\00000154.bmp c:\ICL\Validation\bmp\00000154.bmp
copy E:\inttest\ICL\Validation\bmp\00000160.bmp c:\ICL\Validation\bmp\00000160.bmp
copy E:\inttest\ICL\Validation\bmp\00000161.bmp c:\ICL\Validation\bmp\00000161.bmp

md c:\ICL\Validation\png
copy E:\inttest\ICL\Validation\png\00000020.png c:\ICL\Validation\png\00000020.png
copy E:\inttest\ICL\Validation\png\00000022.png c:\ICL\Validation\png\00000022.png
copy E:\inttest\ICL\Validation\png\00000047.png c:\ICL\Validation\png\00000047.png
copy E:\inttest\ICL\Validation\png\00000049.png c:\ICL\Validation\png\00000049.png
copy E:\inttest\ICL\Validation\png\00000055.png c:\ICL\Validation\png\00000055.png
copy E:\inttest\ICL\Validation\png\00000062.png c:\ICL\Validation\png\00000062.png
copy E:\inttest\ICL\Validation\png\00000105.pngi c:\ICL\Validation\png\00000105.pngi
copy E:\inttest\ICL\Validation\png\00000113.pngi c:\ICL\Validation\png\00000113.pngi
copy E:\inttest\ICL\Validation\png\00000116.png c:\ICL\Validation\png\00000116.png
copy E:\inttest\ICL\Validation\png\00000117.png c:\ICL\Validation\png\00000117.png
copy E:\inttest\ICL\Validation\png\00000118.png c:\ICL\Validation\png\00000118.png
copy E:\inttest\ICL\Validation\png\00000119.png c:\ICL\Validation\png\00000119.png
copy E:\inttest\ICL\Validation\png\00000120.png c:\ICL\Validation\png\00000120.png
copy E:\inttest\ICL\Validation\png\00000121.png c:\ICL\Validation\png\00000121.png
copy E:\inttest\ICL\Validation\png\00000122.png c:\ICL\Validation\png\00000122.png
copy E:\inttest\ICL\Validation\png\00000123.png c:\ICL\Validation\png\00000123.png
copy E:\inttest\ICL\Validation\png\00000124.png c:\ICL\Validation\png\00000124.png
copy E:\inttest\ICL\Validation\png\00000125.png c:\ICL\Validation\png\00000125.png
copy E:\inttest\ICL\Validation\png\00000126.png c:\ICL\Validation\png\00000126.png
copy E:\inttest\ICL\Validation\png\00000127.png c:\ICL\Validation\png\00000127.png
copy E:\inttest\ICL\Validation\png\00000128.png c:\ICL\Validation\png\00000128.png
copy E:\inttest\ICL\Validation\png\00000129.png c:\ICL\Validation\png\00000129.png
copy E:\inttest\ICL\Validation\png\00000130.png c:\ICL\Validation\png\00000130.png
copy E:\inttest\ICL\Validation\png\00000149.png c:\ICL\Validation\png\00000149.png
copy E:\inttest\ICL\Validation\png\00000150.png c:\ICL\Validation\png\00000150.png
copy E:\inttest\ICL\Validation\png\00000168.png c:\ICL\Validation\png\00000168.png
copy E:\inttest\ICL\Validation\png\00000169.png c:\ICL\Validation\png\00000169.png
copy E:\inttest\ICL\Validation\png\00000182.pngi c:\ICL\Validation\png\00000182.pngi
copy E:\inttest\ICL\Validation\png\00000183.pngi c:\ICL\Validation\png\00000183.pngi
copy E:\inttest\ICL\Validation\png\00000184.pngi c:\ICL\Validation\png\00000184.pngi
copy E:\inttest\ICL\Validation\png\00000199.png c:\ICL\Validation\png\00000199.png
copy E:\inttest\ICL\Validation\png\00000200.png c:\ICL\Validation\png\00000200.png
copy E:\inttest\ICL\Validation\png\00000232.pngi c:\ICL\Validation\png\00000232.pngi
copy E:\inttest\ICL\Validation\png\00000233.pngi c:\ICL\Validation\png\00000233.pngi
copy E:\inttest\ICL\Validation\png\00000254.png c:\ICL\Validation\png\00000254.png
copy E:\inttest\ICL\Validation\png\00000255.png c:\ICL\Validation\png\00000255.png
copy E:\inttest\ICL\Validation\png\00000268.png c:\ICL\Validation\png\00000268.png
copy E:\inttest\ICL\Validation\png\00000269.png c:\ICL\Validation\png\00000269.png
copy E:\inttest\ICL\Validation\png\00000431.png c:\ICL\Validation\png\00000431.png
copy E:\inttest\ICL\Validation\png\00000432.png c:\ICL\Validation\png\00000432.png
copy E:\inttest\ICL\Validation\png\00000513.png c:\ICL\Validation\png\00000513.png
copy E:\inttest\ICL\Validation\png\00000514.png c:\ICL\Validation\png\00000514.png
copy E:\inttest\ICL\Validation\png\00000628.png c:\ICL\Validation\png\00000628.png
copy E:\inttest\ICL\Validation\png\00000654.png c:\ICL\Validation\png\00000654.png
copy E:\inttest\ICL\Validation\png\00000655.png c:\ICL\Validation\png\00000655.png
copy E:\inttest\ICL\Validation\png\00000680.png c:\ICL\Validation\png\00000680.png
copy E:\inttest\ICL\Validation\png\00000681.png c:\ICL\Validation\png\00000681.png
copy E:\inttest\ICL\Validation\png\00000706.png c:\ICL\Validation\png\00000706.png
copy E:\inttest\ICL\Validation\png\00000707.png c:\ICL\Validation\png\00000707.png
copy E:\inttest\ICL\Validation\png\00000719.png c:\ICL\Validation\png\00000719.png
copy E:\inttest\ICL\Validation\png\00000720.png c:\ICL\Validation\png\00000720.png
copy E:\inttest\ICL\Validation\png\00000740.png c:\ICL\Validation\png\00000740.png
copy E:\inttest\ICL\Validation\png\00000741.png c:\ICL\Validation\png\00000741.png
copy E:\inttest\ICL\Validation\png\00000742.png c:\ICL\Validation\png\00000742.png
copy E:\inttest\ICL\Validation\png\00000743.png c:\ICL\Validation\png\00000743.png
copy E:\inttest\ICL\Validation\png\00000744.png c:\ICL\Validation\png\00000744.png
copy E:\inttest\ICL\Validation\png\00000745.png c:\ICL\Validation\png\00000745.png

md c:\ICL\Validation\jpg
copy E:\inttest\ICL\Validation\jpg\00000043.jpgi c:\ICL\Validation\jpg\00000043.jpgi
copy E:\inttest\ICL\Validation\jpg\00000132.jpgi c:\ICL\Validation\jpg\00000132.jpgi
copy E:\inttest\ICL\Validation\jpg\00000147.jpgi c:\ICL\Validation\jpg\00000147.jpgi
copy E:\inttest\ICL\Validation\jpg\00000152.jpgi c:\ICL\Validation\jpg\00000152.jpgi
copy E:\inttest\ICL\Validation\jpg\00000245.jpgi c:\ICL\Validation\jpg\00000245.jpgi
copy E:\inttest\ICL\Validation\jpg\00000250.jpgi c:\ICL\Validation\jpg\00000250.jpgi
copy E:\inttest\ICL\Validation\jpg\00000254.jpgi c:\ICL\Validation\jpg\00000254.jpgi
copy E:\inttest\ICL\Validation\jpg\00000259.jpgi c:\ICL\Validation\jpg\00000259.jpgi
copy E:\inttest\ICL\Validation\jpg\00000289.jpgi c:\ICL\Validation\jpg\00000289.jpgi
copy E:\inttest\ICL\Validation\jpg\00000293.jpgi c:\ICL\Validation\jpg\00000293.jpgi
copy E:\inttest\ICL\Validation\jpg\00000295.jpgi c:\ICL\Validation\jpg\00000295.jpgi
copy E:\inttest\ICL\Validation\jpg\00000296.jpgi c:\ICL\Validation\jpg\00000296.jpgi
copy E:\inttest\ICL\Validation\jpg\00000303.jpgi c:\ICL\Validation\jpg\00000303.jpgi
copy E:\inttest\ICL\Validation\jpg\00000304.jpgi c:\ICL\Validation\jpg\00000304.jpgi
copy E:\inttest\ICL\Validation\jpg\00000305.jpgi c:\ICL\Validation\jpg\00000305.jpgi
copy E:\inttest\ICL\Validation\jpg\00000306.jpgi c:\ICL\Validation\jpg\00000306.jpgi
copy E:\inttest\ICL\Validation\jpg\00000308.jpgi c:\ICL\Validation\jpg\00000308.jpgi
copy E:\inttest\ICL\Validation\jpg\00000309.jpgi c:\ICL\Validation\jpg\00000309.jpgi
copy E:\inttest\ICL\Validation\jpg\00000310.jpgi c:\ICL\Validation\jpg\00000310.jpgi
copy E:\inttest\ICL\Validation\jpg\00000315.jpgi c:\ICL\Validation\jpg\00000315.jpgi
copy E:\inttest\ICL\Validation\jpg\00000316.jpgi c:\ICL\Validation\jpg\00000316.jpgi
copy E:\inttest\ICL\Validation\jpg\00000317.jpgi c:\ICL\Validation\jpg\00000317.jpgi
copy E:\inttest\ICL\Validation\jpg\00000318.jpgi c:\ICL\Validation\jpg\00000318.jpgi
copy E:\inttest\ICL\Validation\jpg\00000319.jpgi c:\ICL\Validation\jpg\00000319.jpgi
copy E:\inttest\ICL\Validation\jpg\00000320.jpgi c:\ICL\Validation\jpg\00000320.jpgi
copy E:\inttest\ICL\Validation\jpg\00000321.jpgi c:\ICL\Validation\jpg\00000321.jpgi
copy E:\inttest\ICL\Validation\jpg\00000322.jpgi c:\ICL\Validation\jpg\00000322.jpgi
copy E:\inttest\ICL\Validation\jpg\00000323.jpgi c:\ICL\Validation\jpg\00000323.jpgi
copy E:\inttest\ICL\Validation\jpg\00000324.jpgi c:\ICL\Validation\jpg\00000324.jpgi
copy E:\inttest\ICL\Validation\jpg\00000325.jpgi c:\ICL\Validation\jpg\00000325.jpgi
copy E:\inttest\ICL\Validation\jpg\00000326.jpgi c:\ICL\Validation\jpg\00000326.jpgi
copy E:\inttest\ICL\Validation\jpg\00000344.jpgi c:\ICL\Validation\jpg\00000344.jpgi
copy E:\inttest\ICL\Validation\jpg\00000345.jpgi c:\ICL\Validation\jpg\00000345.jpgi
copy E:\inttest\ICL\Validation\jpg\00000351.jpgi c:\ICL\Validation\jpg\00000351.jpgi
copy E:\inttest\ICL\Validation\jpg\00000356.jpgi c:\ICL\Validation\jpg\00000356.jpgi
copy E:\inttest\ICL\Validation\jpg\00000361.jpgi c:\ICL\Validation\jpg\00000361.jpgi
copy E:\inttest\ICL\Validation\jpg\00000387.jpgi c:\ICL\Validation\jpg\00000387.jpgi
copy E:\inttest\ICL\Validation\jpg\00000390.jpgi c:\ICL\Validation\jpg\00000390.jpgi
copy E:\inttest\ICL\Validation\jpg\00000395.jpgi c:\ICL\Validation\jpg\00000395.jpgi
copy E:\inttest\ICL\Validation\jpg\00000423.jpgi c:\ICL\Validation\jpg\00000423.jpgi
copy E:\inttest\ICL\Validation\jpg\00000424.jpgi c:\ICL\Validation\jpg\00000424.jpgi
copy E:\inttest\ICL\Validation\jpg\00000425.jpgi c:\ICL\Validation\jpg\00000425.jpgi
copy E:\inttest\ICL\Validation\jpg\00000461.jpgi c:\ICL\Validation\jpg\00000461.jpgi
copy E:\inttest\ICL\Validation\jpg\00000466.jpgi c:\ICL\Validation\jpg\00000466.jpgi
copy E:\inttest\ICL\Validation\jpg\00000471.jpgi c:\ICL\Validation\jpg\00000471.jpgi
copy E:\inttest\ICL\Validation\jpg\00000474.jpgi c:\ICL\Validation\jpg\00000474.jpgi
copy E:\inttest\ICL\Validation\jpg\00000475.jpgi c:\ICL\Validation\jpg\00000475.jpgi
copy E:\inttest\ICL\Validation\jpg\00000476.jpgi c:\ICL\Validation\jpg\00000476.jpgi
copy E:\inttest\ICL\Validation\jpg\00000477.jpgi c:\ICL\Validation\jpg\00000477.jpgi
copy E:\inttest\ICL\Validation\jpg\00000478.jpgi c:\ICL\Validation\jpg\00000478.jpgi
copy E:\inttest\ICL\Validation\jpg\00000479.jpgi c:\ICL\Validation\jpg\00000479.jpgi
copy E:\inttest\ICL\Validation\jpg\00000480.jpgi c:\ICL\Validation\jpg\00000480.jpgi
copy E:\inttest\ICL\Validation\jpg\00000481.jpgi c:\ICL\Validation\jpg\00000481.jpgi
copy E:\inttest\ICL\Validation\jpg\00000482.jpgi c:\ICL\Validation\jpg\00000482.jpgi
copy E:\inttest\ICL\Validation\jpg\00000483.jpgi c:\ICL\Validation\jpg\00000483.jpgi
copy E:\inttest\ICL\Validation\jpg\00000484.jpgi c:\ICL\Validation\jpg\00000484.jpgi
copy E:\inttest\ICL\Validation\jpg\00000485.jpgi c:\ICL\Validation\jpg\00000485.jpgi
copy E:\inttest\ICL\Validation\jpg\00000486.jpgi c:\ICL\Validation\jpg\00000486.jpgi
copy E:\inttest\ICL\Validation\jpg\00000487.jpgi c:\ICL\Validation\jpg\00000487.jpgi
copy E:\inttest\ICL\Validation\jpg\00000488.jpgi c:\ICL\Validation\jpg\00000488.jpgi
copy E:\inttest\ICL\Validation\jpg\00000489.jpgi c:\ICL\Validation\jpg\00000489.jpgi
copy E:\inttest\ICL\Validation\jpg\00000530.jpgi c:\ICL\Validation\jpg\00000530.jpgi
copy E:\inttest\ICL\Validation\jpg\00000535.jpgi c:\ICL\Validation\jpg\00000535.jpgi
copy E:\inttest\ICL\Validation\jpg\00000572.jpgi c:\ICL\Validation\jpg\00000572.jpgi
copy E:\inttest\ICL\Validation\jpg\00000577.jpgi c:\ICL\Validation\jpg\00000577.jpgi
copy E:\inttest\ICL\Validation\jpg\00000597.jpgi c:\ICL\Validation\jpg\00000597.jpgi
copy E:\inttest\ICL\Validation\jpg\00000602.jpgi c:\ICL\Validation\jpg\00000602.jpgi
copy E:\inttest\ICL\Validation\jpg\00000607.jpgi c:\ICL\Validation\jpg\00000607.jpgi
copy E:\inttest\ICL\Validation\jpg\00000623.jpgi c:\ICL\Validation\jpg\00000623.jpgi
copy E:\inttest\ICL\Validation\jpg\00000628.jpgi c:\ICL\Validation\jpg\00000628.jpgi
copy E:\inttest\ICL\Validation\jpg\00000650.jpgi c:\ICL\Validation\jpg\00000650.jpgi
copy E:\inttest\ICL\Validation\jpg\00000655.jpgi c:\ICL\Validation\jpg\00000655.jpgi
copy E:\inttest\ICL\Validation\jpg\00000667.jpgi c:\ICL\Validation\jpg\00000667.jpgi
copy E:\inttest\ICL\Validation\jpg\00000668.jpgi c:\ICL\Validation\jpg\00000668.jpgi
copy E:\inttest\ICL\Validation\jpg\00000669.jpgi c:\ICL\Validation\jpg\00000669.jpgi
copy E:\inttest\ICL\Validation\jpg\00000670.jpgi c:\ICL\Validation\jpg\00000670.jpgi
copy E:\inttest\ICL\Validation\jpg\00000673.jpgi c:\ICL\Validation\jpg\00000673.jpgi
copy E:\inttest\ICL\Validation\jpg\00000678.jpgi c:\ICL\Validation\jpg\00000678.jpgi
copy E:\inttest\ICL\Validation\jpg\00000679.jpgi c:\ICL\Validation\jpg\00000679.jpgi
copy E:\inttest\ICL\Validation\jpg\00000680.jpgi c:\ICL\Validation\jpg\00000680.jpgi
copy E:\inttest\ICL\Validation\jpg\00000681.jpgi c:\ICL\Validation\jpg\00000681.jpgi
copy E:\inttest\ICL\Validation\jpg\00000684.jpgi c:\ICL\Validation\jpg\00000684.jpgi
copy E:\inttest\ICL\Validation\jpg\00000689.jpgi c:\ICL\Validation\jpg\00000689.jpgi
copy E:\inttest\ICL\Validation\jpg\00000694.jpgi c:\ICL\Validation\jpg\00000694.jpgi
copy E:\inttest\ICL\Validation\jpg\00000698.jpgi c:\ICL\Validation\jpg\00000698.jpgi
copy E:\inttest\ICL\Validation\jpg\00000700.jpgi c:\ICL\Validation\jpg\00000700.jpgi
copy E:\inttest\ICL\Validation\jpg\00000708.jpgi c:\ICL\Validation\jpg\00000708.jpgi
copy E:\inttest\ICL\Validation\jpg\00000710.jpgi c:\ICL\Validation\jpg\00000710.jpgi
copy E:\inttest\ICL\Validation\jpg\00000711.jpgi c:\ICL\Validation\jpg\00000711.jpgi
copy E:\inttest\ICL\Validation\jpg\00000713.jpgi c:\ICL\Validation\jpg\00000713.jpgi
copy E:\inttest\ICL\Validation\jpg\00000714.jpgi c:\ICL\Validation\jpg\00000714.jpgi
copy E:\inttest\ICL\Validation\jpg\00000715.jpgi c:\ICL\Validation\jpg\00000715.jpgi
copy E:\inttest\ICL\Validation\jpg\00000720.jpgi c:\ICL\Validation\jpg\00000720.jpgi
copy E:\inttest\ICL\Validation\jpg\00000721.jpgi c:\ICL\Validation\jpg\00000721.jpgi
copy E:\inttest\ICL\Validation\jpg\00000724.jpgi c:\ICL\Validation\jpg\00000724.jpgi
copy E:\inttest\ICL\Validation\jpg\00000725.jpgi c:\ICL\Validation\jpg\00000725.jpgi
copy E:\inttest\ICL\Validation\jpg\00000726.jpgi c:\ICL\Validation\jpg\00000726.jpgi
copy E:\inttest\ICL\Validation\jpg\00000727.jpgi c:\ICL\Validation\jpg\00000727.jpgi
copy E:\inttest\ICL\Validation\jpg\00000749.jpgi c:\ICL\Validation\jpg\00000749.jpgi
copy E:\inttest\ICL\Validation\jpg\00000750.jpgi c:\ICL\Validation\jpg\00000750.jpgi
copy E:\inttest\ICL\Validation\jpg\00000848.jpgi c:\ICL\Validation\jpg\00000848.jpgi
copy E:\inttest\ICL\Validation\jpg\00000853.jpgi c:\ICL\Validation\jpg\00000853.jpgi
copy E:\inttest\ICL\Validation\jpg\00000887.jpgi c:\ICL\Validation\jpg\00000887.jpgi
copy E:\inttest\ICL\Validation\jpg\00000892.jpgi c:\ICL\Validation\jpg\00000892.jpgi
copy E:\inttest\ICL\Validation\jpg\00000896.jpgi c:\ICL\Validation\jpg\00000896.jpgi
copy E:\inttest\ICL\Validation\jpg\00000898.jpgi c:\ICL\Validation\jpg\00000898.jpgi
copy E:\inttest\ICL\Validation\jpg\00000906.jpgi c:\ICL\Validation\jpg\00000906.jpgi
copy E:\inttest\ICL\Validation\jpg\00000907.jpgi c:\ICL\Validation\jpg\00000907.jpgi
copy E:\inttest\ICL\Validation\jpg\00000908.jpgi c:\ICL\Validation\jpg\00000908.jpgi
copy E:\inttest\ICL\Validation\jpg\00000909.jpgi c:\ICL\Validation\jpg\00000909.jpgi
copy E:\inttest\ICL\Validation\jpg\00000911.jpgi c:\ICL\Validation\jpg\00000911.jpgi
copy E:\inttest\ICL\Validation\jpg\00000922.jpgi c:\ICL\Validation\jpg\00000922.jpgi
copy E:\inttest\ICL\Validation\jpg\00000923.jpgi c:\ICL\Validation\jpg\00000923.jpgi
copy E:\inttest\ICL\Validation\jpg\00000924.jpgi c:\ICL\Validation\jpg\00000924.jpgi
copy E:\inttest\ICL\Validation\jpg\00000925.jpgi c:\ICL\Validation\jpg\00000925.jpgi
copy E:\inttest\ICL\Validation\jpg\00000926.jpgi c:\ICL\Validation\jpg\00000926.jpgi
copy E:\inttest\ICL\Validation\jpg\00000947.jpgi c:\ICL\Validation\jpg\00000947.jpgi
copy E:\inttest\ICL\Validation\jpg\00000948.jpgi c:\ICL\Validation\jpg\00000948.jpgi
copy E:\inttest\ICL\Validation\jpg\00000964.jpgi c:\ICL\Validation\jpg\00000964.jpgi
copy E:\inttest\ICL\Validation\jpg\00000967.jpgi c:\ICL\Validation\jpg\00000967.jpgi
copy E:\inttest\ICL\Validation\jpg\00000972.jpgi c:\ICL\Validation\jpg\00000972.jpgi
copy E:\inttest\ICL\Validation\jpg\00001000.jpgi c:\ICL\Validation\jpg\00001000.jpgi
copy E:\inttest\ICL\Validation\jpg\00001001.jpgi c:\ICL\Validation\jpg\00001001.jpgi
copy E:\inttest\ICL\Validation\jpg\00001002.jpgi c:\ICL\Validation\jpg\00001002.jpgi
copy E:\inttest\ICL\Validation\jpg\00001003.jpgi c:\ICL\Validation\jpg\00001003.jpgi
copy E:\inttest\ICL\Validation\jpg\00001004.jpgi c:\ICL\Validation\jpg\00001004.jpgi

testframework -q TSI_ICL_COD_00.script
move C:\Logs\TestResults\*.htm E:\Logs\TestResults\

testframework -q TSI_ICL_COD_01.script
move C:\Logs\TestResults\*.htm E:\Logs\TestResults\

testframework -q TSI_ICL_COD_02.script
move C:\Logs\TestResults\*.htm E:\Logs\TestResults\

del c:\ICL\Validation\bmp\*.*
del c:\ICL\Validation\png\*.*
del c:\ICL\Validation\jpg\*.*
