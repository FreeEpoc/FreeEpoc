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





const long unsigned int color16array[16]= {
	0x00000000,	0x00555555,	0x00000080,	0x00008080,
	0x00008000,	0x000000ff,	0x0000ffff,	0x0000ff00,
	0x00ff00ff,	0x00ff0000,	0x00ffff00,	0x00800080,
	0x00800000,	0x00808000,0x00aaaaaa,	0x00ffffff	};

const unsigned char color16inverse[512] = {
	0x00, 0x00, 0x02, 0x02, 0x02, 0x02, 0x05, 0x05,	0x00, 0x00, 0x02, 0x02, 0x02, 0x02, 0x05, 0x05,
	0x04, 0x04, 0x01, 0x03, 0x03, 0x03, 0x05, 0x05,	0x04, 0x04, 0x03, 0x03, 0x03, 0x03, 0x03, 0x05,
	0x04, 0x04, 0x03, 0x03, 0x03, 0x03, 0x03, 0x06,	0x04, 0x04, 0x03, 0x03, 0x03, 0x03, 0x06, 0x06,
	0x07, 0x07, 0x07, 0x03, 0x03, 0x06, 0x06, 0x06,	0x07, 0x07, 0x07, 0x07, 0x06, 0x06, 0x06, 0x06,
	0x00, 0x00, 0x02, 0x02, 0x02, 0x02, 0x05, 0x05,	0x00, 0x00, 0x01, 0x02, 0x02, 0x02, 0x05, 0x05,
	0x04, 0x01, 0x01, 0x01, 0x03, 0x03, 0x05, 0x05,	0x04, 0x04, 0x01, 0x03, 0x03, 0x03, 0x03, 0x05,
	0x04, 0x04, 0x03, 0x03, 0x03, 0x03, 0x03, 0x06,	0x04, 0x04, 0x03, 0x03, 0x03, 0x03, 0x06, 0x06,
	0x07, 0x07, 0x07, 0x03, 0x03, 0x06, 0x06, 0x06,	0x07, 0x07, 0x07, 0x07, 0x06, 0x06, 0x06, 0x06,
	0x0c, 0x0c, 0x01, 0x0b, 0x0b, 0x0b, 0x05, 0x05,	0x0c, 0x01, 0x01, 0x01, 0x0b, 0x0b, 0x05, 0x05,
	0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x05,	0x0d, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x05,
	0x0d, 0x0d, 0x01, 0x01, 0x03, 0x0e, 0x0e, 0x06,	0x0d, 0x0d, 0x01, 0x01, 0x0e, 0x0e, 0x0e, 0x06,
	0x07, 0x07, 0x01, 0x01, 0x0e, 0x0e, 0x06, 0x06,	0x07, 0x07, 0x07, 0x07, 0x06, 0x06, 0x06, 0x06,
	0x0c, 0x0c, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x05,	0x0c, 0x0c, 0x01, 0x0b, 0x0b, 0x0b, 0x0b, 0x05,
	0x0d, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x05,	0x0d, 0x0d, 0x01, 0x01, 0x01, 0x0e, 0x0e, 0x0e,
	0x0d, 0x0d, 0x01, 0x01, 0x0e, 0x0e, 0x0e, 0x0e,	0x0d, 0x0d, 0x01, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e,
	0x0d, 0x0d, 0x01, 0x0e, 0x0e, 0x0e, 0x0e, 0x06,	0x07, 0x07, 0x07, 0x0e, 0x0e, 0x0e, 0x06, 0x06,
	0x0c, 0x0c, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x08,	0x0c, 0x0c, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x08,
	0x0d, 0x0d, 0x01, 0x01, 0x0b, 0x0e, 0x0e, 0x08,	0x0d, 0x0d, 0x01, 0x01, 0x0e, 0x0e, 0x0e, 0x0e,
	0x0d, 0x0d, 0x0d, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e,	0x0d, 0x0d, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e,
	0x0d, 0x0d, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0f,	0x0a, 0x0a, 0x0a, 0x0e, 0x0e, 0x0e, 0x0f, 0x0f,
	0x0c, 0x0c, 0x0b, 0x0b, 0x0b, 0x0b, 0x08, 0x08,	0x0c, 0x0c, 0x0b, 0x0b, 0x0b, 0x0b, 0x08, 0x08,
	0x0d, 0x0d, 0x01, 0x01, 0x0e, 0x0e, 0x0e, 0x08,	0x0d, 0x0d, 0x01, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e,
	0x0d, 0x0d, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e,	0x0d, 0x0d, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e,
	0x0a, 0x0a, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0f,	0x0a, 0x0a, 0x0a, 0x0e, 0x0e, 0x0e, 0x0f, 0x0f,
	0x09, 0x09, 0x09, 0x0b, 0x0b, 0x08, 0x08, 0x08,	0x09, 0x09, 0x09, 0x0b, 0x0b, 0x08, 0x08, 0x08,
	0x09, 0x09, 0x01, 0x01, 0x0e, 0x0e, 0x08, 0x08,	0x0d, 0x0d, 0x01, 0x0e, 0x0e, 0x0e, 0x0e, 0x08,
	0x0d, 0x0d, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0f,	0x0a, 0x0a, 0x0e, 0x0e, 0x0e, 0x0e, 0x0e, 0x0f,
	0x0a, 0x0a, 0x0a, 0x0e, 0x0e, 0x0e, 0x0f, 0x0f,	0x0a, 0x0a, 0x0a, 0x0a, 0x0f, 0x0f, 0x0f, 0x0f,
	0x09, 0x09, 0x09, 0x09, 0x08, 0x08, 0x08, 0x08,	0x09, 0x09, 0x09, 0x09, 0x08, 0x08, 0x08, 0x08,
	0x09, 0x09, 0x09, 0x09, 0x08, 0x08, 0x08, 0x08,	0x09, 0x09, 0x09, 0x0e, 0x0e, 0x0e, 0x08, 0x08,
	0x0a, 0x0a, 0x0a, 0x0e, 0x0e, 0x0e, 0x0f, 0x0f,	0x0a, 0x0a, 0x0a, 0x0e, 0x0e, 0x0e, 0x0f, 0x0f,
	0x0a, 0x0a, 0x0a, 0x0a, 0x0f, 0x0f, 0x0f, 0x0f,	0x0a, 0x0a, 0x0a, 0x0a, 0x0f, 0x0f, 0x0f, 0x0f
	};

const long unsigned int color256array[256] = {
	0x00000000,	0x00000033,	0x00000066,	0x00000099,	0x000000cc,	0x000000ff,
	0x00003300,	0x00003333,	0x00003366,	0x00003399,	0x000033cc,	0x000033ff,
	0x00006600,	0x00006633,	0x00006666,	0x00006699,	0x000066cc,	0x000066ff,
	0x00009900,	0x00009933,	0x00009966,	0x00009999,	0x000099cc,	0x000099ff,
	0x0000cc00,	0x0000cc33,	0x0000cc66,	0x0000cc99,	0x0000cccc,	0x0000ccff,
	0x0000ff00,	0x0000ff33,	0x0000ff66,	0x0000ff99,	0x0000ffcc,	0x0000ffff,

	0x00330000,	0x00330033,	0x00330066,	0x00330099,	0x003300cc,	0x003300ff,
	0x00333300,	0x00333333,	0x00333366,	0x00333399,	0x003333cc,	0x003333ff,
	0x00336600,	0x00336633,	0x00336666,	0x00336699,	0x003366cc,	0x003366ff,
	0x00339900,	0x00339933,	0x00339966,	0x00339999,	0x003399cc,	0x003399ff,
	0x0033cc00,	0x0033cc33,	0x0033cc66,	0x0033cc99,	0x0033cccc,	0x0033ccff,
	0x0033ff00,	0x0033ff33,	0x0033ff66,	0x0033ff99,	0x0033ffcc,	0x0033ffff,

	0x00660000,	0x00660033,	0x00660066,	0x00660099,	0x006600cc,	0x006600ff,
	0x00663300,	0x00663333,	0x00663366,	0x00663399,	0x006633cc,	0x006633ff,
	0x00666600,	0x00666633,	0x00666666,	0x00666699,	0x006666cc,	0x006666ff,
	0x00669900,	0x00669933,	0x00669966,	0x00669999,	0x006699cc,	0x006699ff,
	0x0066cc00,	0x0066cc33,	0x0066cc66,	0x0066cc99,	0x0066cccc,	0x0066ccff,
	0x0066ff00,	0x0066ff33,	0x0066ff66,	0x0066ff99,	0x0066ffcc,	0x0066ffff,

	0x00111111, 0x00222222, 0x00444444, 0x00555555, 0x00777777,
	0x00000011, 0x00000022, 0x00000044, 0x00000055, 0x00000077,
	0x00001100,	0x00002200,	0x00004400,	0x00005500,	0x00007700,
	0x00110000,	0x00220000,	0x00440000,	0x00550000,	0x00770000,

	0x00880000,	0x00aa0000,	0x00bb0000,	0x00dd0000,	0x00ee0000,
	0x00008800,	0x0000aa00,	0x0000bb00,	0x0000dd00,	0x0000ee00,
	0x00000088,	0x000000aa,	0x000000bb,	0x000000dd,	0x000000ee,
	0x00888888, 0x00aaaaaa, 0x00bbbbbb, 0x00dddddd, 0x00eeeeee,

	0x00990000,	0x00990033,	0x00990066,	0x00990099,	0x009900cc,	0x009900ff,
	0x00993300,	0x00993333,	0x00993366,	0x00993399,	0x009933cc,	0x009933ff,
	0x00996600,	0x00996633,	0x00996666,	0x00996699,	0x009966cc,	0x009966ff,
	0x00999900,	0x00999933,	0x00999966,	0x00999999,	0x009999cc,	0x009999ff,
	0x0099cc00,	0x0099cc33,	0x0099cc66,	0x0099cc99,	0x0099cccc,	0x0099ccff,
	0x0099ff00,	0x0099ff33,	0x0099ff66,	0x0099ff99,	0x0099ffcc,	0x0099ffff,

	0x00cc0000,	0x00cc0033,	0x00cc0066,	0x00cc0099,	0x00cc00cc,	0x00cc00ff,
	0x00cc3300,	0x00cc3333,	0x00cc3366,	0x00cc3399,	0x00cc33cc,	0x00cc33ff,
	0x00cc6600,	0x00cc6633,	0x00cc6666,	0x00cc6699,	0x00cc66cc,	0x00cc66ff,
	0x00cc9900,	0x00cc9933,	0x00cc9966,	0x00cc9999,	0x00cc99cc,	0x00cc99ff,
	0x00cccc00,	0x00cccc33,	0x00cccc66,	0x00cccc99,	0x00cccccc,	0x00ccccff,
	0x00ccff00,	0x00ccff33,	0x00ccff66,	0x00ccff99,	0x00ccffcc,	0x00ccffff,

	0x00ff0000,	0x00ff0033,	0x00ff0066,	0x00ff0099,	0x00ff00cc,	0x00ff00ff,
	0x00ff3300,	0x00ff3333,	0x00ff3366,	0x00ff3399,	0x00ff33cc,	0x00ff33ff,
	0x00ff6600,	0x00ff6633,	0x00ff6666,	0x00ff6699,	0x00ff66cc,	0x00ff66ff,
	0x00ff9900,	0x00ff9933,	0x00ff9966,	0x00ff9999,	0x00ff99cc,	0x00ff99ff,
	0x00ffcc00,	0x00ffcc33,	0x00ffcc66,	0x00ffcc99,	0x00ffcccc,	0x00ffccff,
	0x00ffff00,	0x00ffff33,	0x00ffff66,	0x00ffff99,	0x00ffffcc,	0x00ffffff
	};

const unsigned char color256inverse[4096] = {
	0x00, 0x71, 0x72, 0x01, 0x73, 0x74, 0x02, 0x75,	0x8a, 0x03, 0x8b, 0x8c, 0x04, 0x8d, 0x8e, 0x05,
	0x76, 0x6c, 0x72, 0x01, 0x73, 0x74, 0x02, 0x75,	0x8a, 0x03, 0x8b, 0x8c, 0x04, 0x8d, 0x8e, 0x05,
	0x77, 0x77, 0x07, 0x07, 0x07, 0x08, 0x08, 0x08,	0x09, 0x09, 0x09, 0x0a, 0x0a, 0x0a, 0x0b, 0x0b,
	0x06, 0x06, 0x07, 0x07, 0x07, 0x08, 0x08, 0x08,	0x09, 0x09, 0x09, 0x0a, 0x0a, 0x0a, 0x0b, 0x0b,
	0x78, 0x78, 0x07, 0x07, 0x07, 0x08, 0x08, 0x08,	0x09, 0x09, 0x09, 0x0a, 0x0a, 0x0a, 0x0b, 0x0b,
	0x79, 0x79, 0x0d, 0x0d, 0x0d, 0x0e, 0x0e, 0x0e,	0x0f, 0x0f, 0x0f, 0x10, 0x10, 0x10, 0x11, 0x11,
	0x0c, 0x0c, 0x0d, 0x0d, 0x0d, 0x0e, 0x0e, 0x0e,	0x0f, 0x0f, 0x0f, 0x10, 0x10, 0x10, 0x11, 0x11,
	0x7a, 0x7a, 0x0d, 0x0d, 0x0d, 0x0e, 0x0e, 0x0e,	0x0f, 0x0f, 0x0f, 0x10, 0x10, 0x10, 0x11, 0x11,
	0x85, 0x85, 0x13, 0x13, 0x13, 0x14, 0x14, 0x14,	0x15, 0x15, 0x15, 0x16, 0x16, 0x16, 0x17, 0x17,
	0x12, 0x12, 0x13, 0x13, 0x13, 0x14, 0x14, 0x14,	0x15, 0x15, 0x15, 0x16, 0x16, 0x16, 0x17, 0x17,
	0x86, 0x86, 0x13, 0x13, 0x13, 0x14, 0x14, 0x14,	0x15, 0x15, 0x15, 0x16, 0x16, 0x16, 0x17, 0x17,
	0x87, 0x87, 0x19, 0x19, 0x19, 0x1a, 0x1a, 0x1a,	0x1b, 0x1b, 0x1b, 0x1c, 0x1c, 0x1c, 0x1d, 0x1d,
	0x18, 0x18, 0x19, 0x19, 0x19, 0x1a, 0x1a, 0x1a,	0x1b, 0x1b, 0x1b, 0x1c, 0x1c, 0x1c, 0x1d, 0x1d,
	0x88, 0x88, 0x19, 0x19, 0x19, 0x1a, 0x1a, 0x1a,	0x1b, 0x1b, 0x1b, 0x1c, 0x1c, 0x1c, 0x1d, 0x1d,
	0x89, 0x89, 0x1f, 0x1f, 0x1f, 0x20, 0x20, 0x20,	0x21, 0x21, 0x21, 0x22, 0x22, 0x22, 0x23, 0x23,
	0x1e, 0x1e, 0x1f, 0x1f, 0x1f, 0x20, 0x20, 0x20,	0x21, 0x21, 0x21, 0x22, 0x22, 0x22, 0x23, 0x23,
	0x7b, 0x6c, 0x72, 0x01, 0x73, 0x74, 0x02, 0x75,	0x8a, 0x03, 0x8b, 0x8c, 0x04, 0x8d, 0x8e, 0x05,
	0x6c, 0x6c, 0x6c, 0x01, 0x73, 0x74, 0x02, 0x75,	0x8a, 0x03, 0x8b, 0x8c, 0x04, 0x8d, 0x8e, 0x05,
	0x77, 0x6c, 0x6d, 0x07, 0x07, 0x08, 0x08, 0x08,	0x09, 0x09, 0x09, 0x0a, 0x0a, 0x0a, 0x0b, 0x0b,
	0x06, 0x06, 0x07, 0x07, 0x07, 0x08, 0x08, 0x08,	0x09, 0x09, 0x09, 0x0a, 0x0a, 0x0a, 0x0b, 0x0b,
	0x78, 0x78, 0x07, 0x07, 0x07, 0x08, 0x08, 0x08,	0x09, 0x09, 0x09, 0x0a, 0x0a, 0x0a, 0x0b, 0x0b,
	0x79, 0x79, 0x0d, 0x0d, 0x0d, 0x0e, 0x0e, 0x0e,	0x0f, 0x0f, 0x0f, 0x10, 0x10, 0x10, 0x11, 0x11,
	0x0c, 0x0c, 0x0d, 0x0d, 0x0d, 0x0e, 0x0e, 0x0e,	0x0f, 0x0f, 0x0f, 0x10, 0x10, 0x10, 0x11, 0x11,
	0x7a, 0x7a, 0x0d, 0x0d, 0x0d, 0x0e, 0x0e, 0x0e,	0x0f, 0x0f, 0x0f, 0x10, 0x10, 0x10, 0x11, 0x11,
	0x85, 0x85, 0x13, 0x13, 0x13, 0x14, 0x14, 0x14,	0x15, 0x15, 0x15, 0x16, 0x16, 0x16, 0x17, 0x17,
	0x12, 0x12, 0x13, 0x13, 0x13, 0x14, 0x14, 0x14,	0x15, 0x15, 0x15, 0x16, 0x16, 0x16, 0x17, 0x17,
	0x86, 0x86, 0x13, 0x13, 0x13, 0x14, 0x14, 0x14,	0x15, 0x15, 0x15, 0x16, 0x16, 0x16, 0x17, 0x17,
	0x87, 0x87, 0x19, 0x19, 0x19, 0x1a, 0x1a, 0x1a,	0x1b, 0x1b, 0x1b, 0x1c, 0x1c, 0x1c, 0x1d, 0x1d,
	0x18, 0x18, 0x19, 0x19, 0x19, 0x1a, 0x1a, 0x1a,	0x1b, 0x1b, 0x1b, 0x1c, 0x1c, 0x1c, 0x1d, 0x1d,
	0x88, 0x88, 0x19, 0x19, 0x19, 0x1a, 0x1a, 0x1a,	0x1b, 0x1b, 0x1b, 0x1c, 0x1c, 0x1c, 0x1d, 0x1d,
	0x89, 0x89, 0x1f, 0x1f, 0x1f, 0x20, 0x20, 0x20,	0x21, 0x21, 0x21, 0x22, 0x22, 0x22, 0x23, 0x23,
	0x1e, 0x1e, 0x1f, 0x1f, 0x1f, 0x20, 0x20, 0x20,	0x21, 0x21, 0x21, 0x22, 0x22, 0x22, 0x23, 0x23,
	0x7c, 0x7c, 0x25, 0x25, 0x25, 0x26, 0x26, 0x26,	0x27, 0x27, 0x27, 0x28, 0x28, 0x28, 0x29, 0x29,
	0x7c, 0x6c, 0x6d, 0x25, 0x25, 0x26, 0x26, 0x26,	0x27, 0x27, 0x27, 0x28, 0x28, 0x28, 0x29, 0x29,
	0x2a, 0x6d, 0x6d, 0x6d, 0x6d, 0x2c, 0x2c, 0x2c,	0x2d, 0x2d, 0x2d, 0x2e, 0x2e, 0x2e, 0x2f, 0x2f,
	0x2a, 0x2a, 0x6d, 0x2b, 0x2b, 0x2c, 0x2c, 0x2c,	0x2d, 0x2d, 0x2d, 0x2e, 0x2e, 0x2e, 0x2f, 0x2f,
	0x2a, 0x2a, 0x6d, 0x2b, 0x6e, 0x2c, 0x2c, 0x2c,	0x2d, 0x2d, 0x2d, 0x2e, 0x2e, 0x2e, 0x2f, 0x2f,
	0x30, 0x30, 0x31, 0x31, 0x31, 0x32, 0x32, 0x32,	0x33, 0x33, 0x33, 0x34, 0x34, 0x34, 0x35, 0x35,
	0x30, 0x30, 0x31, 0x31, 0x31, 0x32, 0x32, 0x32,	0x33, 0x33, 0x33, 0x34, 0x34, 0x34, 0x35, 0x35,
	0x30, 0x30, 0x31, 0x31, 0x31, 0x32, 0x32, 0x32,	0x33, 0x33, 0x33, 0x34, 0x34, 0x34, 0x35, 0x35,
	0x36, 0x36, 0x37, 0x37, 0x37, 0x38, 0x38, 0x38,	0x39, 0x39, 0x39, 0x3a, 0x3a, 0x3a, 0x3b, 0x3b,
	0x36, 0x36, 0x37, 0x37, 0x37, 0x38, 0x38, 0x38,	0x39, 0x39, 0x39, 0x3a, 0x3a, 0x3a, 0x3b, 0x3b,
	0x36, 0x36, 0x37, 0x37, 0x37, 0x38, 0x38, 0x38,	0x39, 0x39, 0x39, 0x3a, 0x3a, 0x3a, 0x3b, 0x3b,
	0x3c, 0x3c, 0x3d, 0x3d, 0x3d, 0x3e, 0x3e, 0x3e,	0x3f, 0x3f, 0x3f, 0x40, 0x40, 0x40, 0x41, 0x41,
	0x3c, 0x3c, 0x3d, 0x3d, 0x3d, 0x3e, 0x3e, 0x3e,	0x3f, 0x3f, 0x3f, 0x40, 0x40, 0x40, 0x41, 0x41,
	0x3c, 0x3c, 0x3d, 0x3d, 0x3d, 0x3e, 0x3e, 0x3e,	0x3f, 0x3f, 0x3f, 0x40, 0x40, 0x40, 0x41, 0x41,
	0x42, 0x42, 0x43, 0x43, 0x43, 0x44, 0x44, 0x44,	0x45, 0x45, 0x45, 0x46, 0x46, 0x46, 0x47, 0x47,
	0x42, 0x42, 0x43, 0x43, 0x43, 0x44, 0x44, 0x44,	0x45, 0x45, 0x45, 0x46, 0x46, 0x46, 0x47, 0x47,
	0x24, 0x24, 0x25, 0x25, 0x25, 0x26, 0x26, 0x26,	0x27, 0x27, 0x27, 0x28, 0x28, 0x28, 0x29, 0x29,
	0x24, 0x24, 0x25, 0x25, 0x25, 0x26, 0x26, 0x26,	0x27, 0x27, 0x27, 0x28, 0x28, 0x28, 0x29, 0x29,
	0x2a, 0x2a, 0x6d, 0x2b, 0x2b, 0x2c, 0x2c, 0x2c,	0x2d, 0x2d, 0x2d, 0x2e, 0x2e, 0x2e, 0x2f, 0x2f,
	0x2a, 0x2a, 0x2b, 0x2b, 0x2b, 0x2c, 0x2c, 0x2c,	0x2d, 0x2d, 0x2d, 0x2e, 0x2e, 0x2e, 0x2f, 0x2f,
	0x2a, 0x2a, 0x2b, 0x2b, 0x6e, 0x2c, 0x2c, 0x2c,	0x2d, 0x2d, 0x2d, 0x2e, 0x2e, 0x2e, 0x2f, 0x2f,
	0x30, 0x30, 0x31, 0x31, 0x31, 0x32, 0x32, 0x32,	0x33, 0x33, 0x33, 0x34, 0x34, 0x34, 0x35, 0x35,
	0x30, 0x30, 0x31, 0x31, 0x31, 0x32, 0x32, 0x32,	0x33, 0x33, 0x33, 0x34, 0x34, 0x34, 0x35, 0x35,
	0x30, 0x30, 0x31, 0x31, 0x31, 0x32, 0x32, 0x32,	0x33, 0x33, 0x33, 0x34, 0x34, 0x34, 0x35, 0x35,
	0x36, 0x36, 0x37, 0x37, 0x37, 0x38, 0x38, 0x38,	0x39, 0x39, 0x39, 0x3a, 0x3a, 0x3a, 0x3b, 0x3b,
	0x36, 0x36, 0x37, 0x37, 0x37, 0x38, 0x38, 0x38,	0x39, 0x39, 0x39, 0x3a, 0x3a, 0x3a, 0x3b, 0x3b,
	0x36, 0x36, 0x37, 0x37, 0x37, 0x38, 0x38, 0x38,	0x39, 0x39, 0x39, 0x3a, 0x3a, 0x3a, 0x3b, 0x3b,
	0x3c, 0x3c, 0x3d, 0x3d, 0x3d, 0x3e, 0x3e, 0x3e,	0x3f, 0x3f, 0x3f, 0x40, 0x40, 0x40, 0x41, 0x41,
	0x3c, 0x3c, 0x3d, 0x3d, 0x3d, 0x3e, 0x3e, 0x3e,	0x3f, 0x3f, 0x3f, 0x40, 0x40, 0x40, 0x41, 0x41,
	0x3c, 0x3c, 0x3d, 0x3d, 0x3d, 0x3e, 0x3e, 0x3e,	0x3f, 0x3f, 0x3f, 0x40, 0x40, 0x40, 0x41, 0x41,
	0x42, 0x42, 0x43, 0x43, 0x43, 0x44, 0x44, 0x44,	0x45, 0x45, 0x45, 0x46, 0x46, 0x46, 0x47, 0x47,
	0x42, 0x42, 0x43, 0x43, 0x43, 0x44, 0x44, 0x44,	0x45, 0x45, 0x45, 0x46, 0x46, 0x46, 0x47, 0x47,
	0x7d, 0x7d, 0x25, 0x25, 0x25, 0x26, 0x26, 0x26,	0x27, 0x27, 0x27, 0x28, 0x28, 0x28, 0x29, 0x29,
	0x7d, 0x7d, 0x25, 0x25, 0x25, 0x26, 0x26, 0x26,	0x27, 0x27, 0x27, 0x28, 0x28, 0x28, 0x29, 0x29,
	0x2a, 0x2a, 0x6d, 0x2b, 0x6e, 0x2c, 0x2c, 0x2c,	0x2d, 0x2d, 0x2d, 0x2e, 0x2e, 0x2e, 0x2f, 0x2f,
	0x2a, 0x2a, 0x2b, 0x2b, 0x6e, 0x2c, 0x2c, 0x2c,	0x2d, 0x2d, 0x2d, 0x2e, 0x2e, 0x2e, 0x2f, 0x2f,
	0x2a, 0x2a, 0x6e, 0x6e, 0x6e, 0x6e, 0x2c, 0x2c,	0x2d, 0x2d, 0x2d, 0x2e, 0x2e, 0x2e, 0x2f, 0x2f,
	0x30, 0x30, 0x31, 0x31, 0x6e, 0x6f, 0x32, 0x32,	0x33, 0x33, 0x33, 0x34, 0x34, 0x34, 0x35, 0x35,
	0x30, 0x30, 0x31, 0x31, 0x31, 0x32, 0x32, 0x32,	0x33, 0x33, 0x33, 0x34, 0x34, 0x34, 0x35, 0x35,
	0x30, 0x30, 0x31, 0x31, 0x31, 0x32, 0x32, 0x32,	0x33, 0x33, 0x33, 0x34, 0x34, 0x34, 0x35, 0x35,
	0x36, 0x36, 0x37, 0x37, 0x37, 0x38, 0x38, 0x38,	0x39, 0x39, 0x39, 0x3a, 0x3a, 0x3a, 0x3b, 0x3b,
	0x36, 0x36, 0x37, 0x37, 0x37, 0x38, 0x38, 0x38,	0x39, 0x39, 0x39, 0x3a, 0x3a, 0x3a, 0x3b, 0x3b,
	0x36, 0x36, 0x37, 0x37, 0x37, 0x38, 0x38, 0x38,	0x39, 0x39, 0x39, 0x3a, 0x3a, 0x3a, 0x3b, 0x3b,
	0x3c, 0x3c, 0x3d, 0x3d, 0x3d, 0x3e, 0x3e, 0x3e,	0x3f, 0x3f, 0x3f, 0x40, 0x40, 0x40, 0x41, 0x41,
	0x3c, 0x3c, 0x3d, 0x3d, 0x3d, 0x3e, 0x3e, 0x3e,	0x3f, 0x3f, 0x3f, 0x40, 0x40, 0x40, 0x41, 0x41,
	0x3c, 0x3c, 0x3d, 0x3d, 0x3d, 0x3e, 0x3e, 0x3e,	0x3f, 0x3f, 0x3f, 0x40, 0x40, 0x40, 0x41, 0x41,
	0x42, 0x42, 0x43, 0x43, 0x43, 0x44, 0x44, 0x44,	0x45, 0x45, 0x45, 0x46, 0x46, 0x46, 0x47, 0x47,
	0x42, 0x42, 0x43, 0x43, 0x43, 0x44, 0x44, 0x44,	0x45, 0x45, 0x45, 0x46, 0x46, 0x46, 0x47, 0x47,
	0x7e, 0x7e, 0x49, 0x49, 0x49, 0x4a, 0x4a, 0x4a,	0x4b, 0x4b, 0x4b, 0x4c, 0x4c, 0x4c, 0x4d, 0x4d,
	0x7e, 0x7e, 0x49, 0x49, 0x49, 0x4a, 0x4a, 0x4a,	0x4b, 0x4b, 0x4b, 0x4c, 0x4c, 0x4c, 0x4d, 0x4d,
	0x4e, 0x4e, 0x4f, 0x4f, 0x4f, 0x50, 0x50, 0x50,	0x51, 0x51, 0x51, 0x52, 0x52, 0x52, 0x53, 0x53,
	0x4e, 0x4e, 0x4f, 0x4f, 0x4f, 0x50, 0x50, 0x50,	0x51, 0x51, 0x51, 0x52, 0x52, 0x52, 0x53, 0x53,
	0x4e, 0x4e, 0x4f, 0x4f, 0x6e, 0x6f, 0x50, 0x50,	0x51, 0x51, 0x51, 0x52, 0x52, 0x52, 0x53, 0x53,
	0x54, 0x54, 0x55, 0x55, 0x6f, 0x6f, 0x6f, 0x6f,	0x57, 0x57, 0x57, 0x58, 0x58, 0x58, 0x59, 0x59,
	0x54, 0x54, 0x55, 0x55, 0x55, 0x6f, 0x56, 0x56,	0x57, 0x57, 0x57, 0x58, 0x58, 0x58, 0x59, 0x59,
	0x54, 0x54, 0x55, 0x55, 0x55, 0x6f, 0x56, 0x70,	0x57, 0x57, 0x57, 0x58, 0x58, 0x58, 0x59, 0x59,
	0x5a, 0x5a, 0x5b, 0x5b, 0x5b, 0x5c, 0x5c, 0x5c,	0x5d, 0x5d, 0x5d, 0x5e, 0x5e, 0x5e, 0x5f, 0x5f,
	0x5a, 0x5a, 0x5b, 0x5b, 0x5b, 0x5c, 0x5c, 0x5c,	0x5d, 0x5d, 0x5d, 0x5e, 0x5e, 0x5e, 0x5f, 0x5f,
	0x5a, 0x5a, 0x5b, 0x5b, 0x5b, 0x5c, 0x5c, 0x5c,	0x5d, 0x5d, 0x5d, 0x5e, 0x5e, 0x5e, 0x5f, 0x5f,
	0x60, 0x60, 0x61, 0x61, 0x61, 0x62, 0x62, 0x62,	0x63, 0x63, 0x63, 0x64, 0x64, 0x64, 0x65, 0x65,
	0x60, 0x60, 0x61, 0x61, 0x61, 0x62, 0x62, 0x62,	0x63, 0x63, 0x63, 0x64, 0x64, 0x64, 0x65, 0x65,
	0x60, 0x60, 0x61, 0x61, 0x61, 0x62, 0x62, 0x62,	0x63, 0x63, 0x63, 0x64, 0x64, 0x64, 0x65, 0x65,
	0x66, 0x66, 0x67, 0x67, 0x67, 0x68, 0x68, 0x68,	0x69, 0x69, 0x69, 0x6a, 0x6a, 0x6a, 0x6b, 0x6b,
	0x66, 0x66, 0x67, 0x67, 0x67, 0x68, 0x68, 0x68,	0x69, 0x69, 0x69, 0x6a, 0x6a, 0x6a, 0x6b, 0x6b,
	0x48, 0x48, 0x49, 0x49, 0x49, 0x4a, 0x4a, 0x4a,	0x4b, 0x4b, 0x4b, 0x4c, 0x4c, 0x4c, 0x4d, 0x4d,
	0x48, 0x48, 0x49, 0x49, 0x49, 0x4a, 0x4a, 0x4a,	0x4b, 0x4b, 0x4b, 0x4c, 0x4c, 0x4c, 0x4d, 0x4d,
	0x4e, 0x4e, 0x4f, 0x4f, 0x4f, 0x50, 0x50, 0x50,	0x51, 0x51, 0x51, 0x52, 0x52, 0x52, 0x53, 0x53,
	0x4e, 0x4e, 0x4f, 0x4f, 0x4f, 0x50, 0x50, 0x50,	0x51, 0x51, 0x51, 0x52, 0x52, 0x52, 0x53, 0x53,
	0x4e, 0x4e, 0x4f, 0x4f, 0x4f, 0x50, 0x50, 0x50,	0x51, 0x51, 0x51, 0x52, 0x52, 0x52, 0x53, 0x53,
	0x54, 0x54, 0x55, 0x55, 0x55, 0x6f, 0x56, 0x56,	0x57, 0x57, 0x57, 0x58, 0x58, 0x58, 0x59, 0x59,
	0x54, 0x54, 0x55, 0x55, 0x55, 0x56, 0x56, 0x56,	0x57, 0x57, 0x57, 0x58, 0x58, 0x58, 0x59, 0x59,
	0x54, 0x54, 0x55, 0x55, 0x55, 0x56, 0x56, 0x70,	0x57, 0x57, 0x57, 0x58, 0x58, 0x58, 0x59, 0x59,
	0x5a, 0x5a, 0x5b, 0x5b, 0x5b, 0x5c, 0x5c, 0x5c,	0x5d, 0x5d, 0x5d, 0x5e, 0x5e, 0x5e, 0x5f, 0x5f,
	0x5a, 0x5a, 0x5b, 0x5b, 0x5b, 0x5c, 0x5c, 0x5c,	0x5d, 0x5d, 0x5d, 0x5e, 0x5e, 0x5e, 0x5f, 0x5f,
	0x5a, 0x5a, 0x5b, 0x5b, 0x5b, 0x5c, 0x5c, 0x5c,	0x5d, 0x5d, 0x5d, 0x5e, 0x5e, 0x5e, 0x5f, 0x5f,
	0x60, 0x60, 0x61, 0x61, 0x61, 0x62, 0x62, 0x62,	0x63, 0x63, 0x63, 0x64, 0x64, 0x64, 0x65, 0x65,
	0x60, 0x60, 0x61, 0x61, 0x61, 0x62, 0x62, 0x62,	0x63, 0x63, 0x63, 0x64, 0x64, 0x64, 0x65, 0x65,
	0x60, 0x60, 0x61, 0x61, 0x61, 0x62, 0x62, 0x62,	0x63, 0x63, 0x63, 0x64, 0x64, 0x64, 0x65, 0x65,
	0x66, 0x66, 0x67, 0x67, 0x67, 0x68, 0x68, 0x68,	0x69, 0x69, 0x69, 0x6a, 0x6a, 0x6a, 0x6b, 0x6b,
	0x66, 0x66, 0x67, 0x67, 0x67, 0x68, 0x68, 0x68,	0x69, 0x69, 0x69, 0x6a, 0x6a, 0x6a, 0x6b, 0x6b,
	0x7f, 0x7f, 0x49, 0x49, 0x49, 0x4a, 0x4a, 0x4a,	0x4b, 0x4b, 0x4b, 0x4c, 0x4c, 0x4c, 0x4d, 0x4d,
	0x7f, 0x7f, 0x49, 0x49, 0x49, 0x4a, 0x4a, 0x4a,	0x4b, 0x4b, 0x4b, 0x4c, 0x4c, 0x4c, 0x4d, 0x4d,
	0x4e, 0x4e, 0x4f, 0x4f, 0x4f, 0x50, 0x50, 0x50,	0x51, 0x51, 0x51, 0x52, 0x52, 0x52, 0x53, 0x53,
	0x4e, 0x4e, 0x4f, 0x4f, 0x4f, 0x50, 0x50, 0x50,	0x51, 0x51, 0x51, 0x52, 0x52, 0x52, 0x53, 0x53,
	0x4e, 0x4e, 0x4f, 0x4f, 0x4f, 0x50, 0x50, 0x50,	0x51, 0x51, 0x51, 0x52, 0x52, 0x52, 0x53, 0x53,
	0x54, 0x54, 0x55, 0x55, 0x55, 0x6f, 0x56, 0x70,	0x57, 0x57, 0x57, 0x58, 0x58, 0x58, 0x59, 0x59,
	0x54, 0x54, 0x55, 0x55, 0x55, 0x56, 0x56, 0x70,	0x57, 0x57, 0x57, 0x58, 0x58, 0x58, 0x59, 0x59,
	0x54, 0x54, 0x55, 0x55, 0x55, 0x70, 0x70, 0x70,	0x70, 0x57, 0x57, 0x58, 0x58, 0x58, 0x59, 0x59,
	0x5a, 0x5a, 0x5b, 0x5b, 0x5b, 0x5c, 0x5c, 0x70,	0x8f, 0x5d, 0x5d, 0x5e, 0x5e, 0x5e, 0x5f, 0x5f,
	0x5a, 0x5a, 0x5b, 0x5b, 0x5b, 0x5c, 0x5c, 0x5c,	0x5d, 0x5d, 0x5d, 0x5e, 0x5e, 0x5e, 0x5f, 0x5f,
	0x5a, 0x5a, 0x5b, 0x5b, 0x5b, 0x5c, 0x5c, 0x5c,	0x5d, 0x5d, 0x5d, 0x5e, 0x5e, 0x5e, 0x5f, 0x5f,
	0x60, 0x60, 0x61, 0x61, 0x61, 0x62, 0x62, 0x62,	0x63, 0x63, 0x63, 0x64, 0x64, 0x64, 0x65, 0x65,
	0x60, 0x60, 0x61, 0x61, 0x61, 0x62, 0x62, 0x62,	0x63, 0x63, 0x63, 0x64, 0x64, 0x64, 0x65, 0x65,
	0x60, 0x60, 0x61, 0x61, 0x61, 0x62, 0x62, 0x62,	0x63, 0x63, 0x63, 0x64, 0x64, 0x64, 0x65, 0x65,
	0x66, 0x66, 0x67, 0x67, 0x67, 0x68, 0x68, 0x68,	0x69, 0x69, 0x69, 0x6a, 0x6a, 0x6a, 0x6b, 0x6b,
	0x66, 0x66, 0x67, 0x67, 0x67, 0x68, 0x68, 0x68,	0x69, 0x69, 0x69, 0x6a, 0x6a, 0x6a, 0x6b, 0x6b,
	0x80, 0x80, 0x80, 0x95, 0x95, 0x96, 0x96, 0x96,	0x97, 0x97, 0x97, 0x98, 0x98, 0x98, 0x99, 0x99,
	0x80, 0x80, 0x80, 0x95, 0x95, 0x96, 0x96, 0x96,	0x97, 0x97, 0x97, 0x98, 0x98, 0x98, 0x99, 0x99,
	0x80, 0x80, 0x9b, 0x9b, 0x9b, 0x9c, 0x9c, 0x9c,	0x9d, 0x9d, 0x9d, 0x9e, 0x9e, 0x9e, 0x9f, 0x9f,
	0x9a, 0x9a, 0x9b, 0x9b, 0x9b, 0x9c, 0x9c, 0x9c,	0x9d, 0x9d, 0x9d, 0x9e, 0x9e, 0x9e, 0x9f, 0x9f,
	0x9a, 0x9a, 0x9b, 0x9b, 0x9b, 0x9c, 0x9c, 0x9c,	0x9d, 0x9d, 0x9d, 0x9e, 0x9e, 0x9e, 0x9f, 0x9f,
	0xa0, 0xa0, 0xa1, 0xa1, 0xa1, 0x6f, 0xa2, 0x70,	0x8f, 0xa3, 0xa3, 0xa4, 0xa4, 0xa4, 0xa5, 0xa5,
	0xa0, 0xa0, 0xa1, 0xa1, 0xa1, 0xa2, 0xa2, 0x70,	0x8f, 0xa3, 0xa3, 0xa4, 0xa4, 0xa4, 0xa5, 0xa5,
	0xa0, 0xa0, 0xa1, 0xa1, 0xa1, 0x70, 0x70, 0x70,	0x8f, 0x8f, 0x8f, 0xa4, 0xa4, 0xa4, 0xa5, 0xa5,
	0xa6, 0xa6, 0xa7, 0xa7, 0xa7, 0x8f, 0x8f, 0x8f,	0x8f, 0x8f, 0x8f, 0x8f, 0xaa, 0xaa, 0xab, 0xab,
	0xa6, 0xa6, 0xa7, 0xa7, 0xa7, 0xa8, 0xa8, 0x8f,	0x8f, 0xa9, 0xa9, 0xaa, 0xaa, 0xaa, 0xab, 0xab,
	0xa6, 0xa6, 0xa7, 0xa7, 0xa7, 0xa8, 0xa8, 0x8f,	0x8f, 0xa9, 0x90, 0x90, 0xaa, 0xaa, 0xab, 0xab,
	0xac, 0xac, 0xad, 0xad, 0xad, 0xae, 0xae, 0xae,	0x8f, 0xaf, 0x90, 0x91, 0xb0, 0xb0, 0xb1, 0xb1,
	0xac, 0xac, 0xad, 0xad, 0xad, 0xae, 0xae, 0xae,	0xaf, 0xaf, 0xaf, 0xb0, 0xb0, 0xb0, 0xb1, 0xb1,
	0xac, 0xac, 0xad, 0xad, 0xad, 0xae, 0xae, 0xae,	0xaf, 0xaf, 0xaf, 0xb0, 0xb0, 0xb0, 0xb1, 0xb1,
	0xb2, 0xb2, 0xb3, 0xb3, 0xb3, 0xb4, 0xb4, 0xb4,	0xb5, 0xb5, 0xb5, 0xb6, 0xb6, 0xb6, 0xb7, 0xb7,
	0xb2, 0xb2, 0xb3, 0xb3, 0xb3, 0xb4, 0xb4, 0xb4,	0xb5, 0xb5, 0xb5, 0xb6, 0xb6, 0xb6, 0xb7, 0xb7,
	0x94, 0x94, 0x95, 0x95, 0x95, 0x96, 0x96, 0x96,	0x97, 0x97, 0x97, 0x98, 0x98, 0x98, 0x99, 0x99,
	0x94, 0x94, 0x95, 0x95, 0x95, 0x96, 0x96, 0x96,	0x97, 0x97, 0x97, 0x98, 0x98, 0x98, 0x99, 0x99,
	0x9a, 0x9a, 0x9b, 0x9b, 0x9b, 0x9c, 0x9c, 0x9c,	0x9d, 0x9d, 0x9d, 0x9e, 0x9e, 0x9e, 0x9f, 0x9f,
	0x9a, 0x9a, 0x9b, 0x9b, 0x9b, 0x9c, 0x9c, 0x9c,	0x9d, 0x9d, 0x9d, 0x9e, 0x9e, 0x9e, 0x9f, 0x9f,
	0x9a, 0x9a, 0x9b, 0x9b, 0x9b, 0x9c, 0x9c, 0x9c,	0x9d, 0x9d, 0x9d, 0x9e, 0x9e, 0x9e, 0x9f, 0x9f,
	0xa0, 0xa0, 0xa1, 0xa1, 0xa1, 0xa2, 0xa2, 0xa2,	0xa3, 0xa3, 0xa3, 0xa4, 0xa4, 0xa4, 0xa5, 0xa5,
	0xa0, 0xa0, 0xa1, 0xa1, 0xa1, 0xa2, 0xa2, 0xa2,	0xa3, 0xa3, 0xa3, 0xa4, 0xa4, 0xa4, 0xa5, 0xa5,
	0xa0, 0xa0, 0xa1, 0xa1, 0xa1, 0xa2, 0xa2, 0x70,	0x8f, 0xa3, 0xa3, 0xa4, 0xa4, 0xa4, 0xa5, 0xa5,
	0xa6, 0xa6, 0xa7, 0xa7, 0xa7, 0xa8, 0xa8, 0x8f,	0x8f, 0xa9, 0xa9, 0xaa, 0xaa, 0xaa, 0xab, 0xab,
	0xa6, 0xa6, 0xa7, 0xa7, 0xa7, 0xa8, 0xa8, 0xa8,	0xa9, 0xa9, 0xa9, 0xaa, 0xaa, 0xaa, 0xab, 0xab,
	0xa6, 0xa6, 0xa7, 0xa7, 0xa7, 0xa8, 0xa8, 0xa8,	0xa9, 0xa9, 0x90, 0x90, 0xaa, 0xaa, 0xab, 0xab,
	0xac, 0xac, 0xad, 0xad, 0xad, 0xae, 0xae, 0xae,	0xaf, 0xaf, 0x90, 0x91, 0xb0, 0xb0, 0xb1, 0xb1,
	0xac, 0xac, 0xad, 0xad, 0xad, 0xae, 0xae, 0xae,	0xaf, 0xaf, 0xaf, 0xb0, 0xb0, 0xb0, 0xb1, 0xb1,
	0xac, 0xac, 0xad, 0xad, 0xad, 0xae, 0xae, 0xae,	0xaf, 0xaf, 0xaf, 0xb0, 0xb0, 0xb0, 0xb1, 0xb1,
	0xb2, 0xb2, 0xb3, 0xb3, 0xb3, 0xb4, 0xb4, 0xb4,	0xb5, 0xb5, 0xb5, 0xb6, 0xb6, 0xb6, 0xb7, 0xb7,
	0xb2, 0xb2, 0xb3, 0xb3, 0xb3, 0xb4, 0xb4, 0xb4,	0xb5, 0xb5, 0xb5, 0xb6, 0xb6, 0xb6, 0xb7, 0xb7,
	0x81, 0x81, 0x81, 0x95, 0x95, 0x96, 0x96, 0x96,	0x97, 0x97, 0x97, 0x98, 0x98, 0x98, 0x99, 0x99,
	0x81, 0x81, 0x81, 0x95, 0x95, 0x96, 0x96, 0x96,	0x97, 0x97, 0x97, 0x98, 0x98, 0x98, 0x99, 0x99,
	0x81, 0x81, 0x9b, 0x9b, 0x9b, 0x9c, 0x9c, 0x9c,	0x9d, 0x9d, 0x9d, 0x9e, 0x9e, 0x9e, 0x9f, 0x9f,
	0x9a, 0x9a, 0x9b, 0x9b, 0x9b, 0x9c, 0x9c, 0x9c,	0x9d, 0x9d, 0x9d, 0x9e, 0x9e, 0x9e, 0x9f, 0x9f,
	0x9a, 0x9a, 0x9b, 0x9b, 0x9b, 0x9c, 0x9c, 0x9c,	0x9d, 0x9d, 0x9d, 0x9e, 0x9e, 0x9e, 0x9f, 0x9f,
	0xa0, 0xa0, 0xa1, 0xa1, 0xa1, 0xa2, 0xa2, 0xa2,	0xa3, 0xa3, 0xa3, 0xa4, 0xa4, 0xa4, 0xa5, 0xa5,
	0xa0, 0xa0, 0xa1, 0xa1, 0xa1, 0xa2, 0xa2, 0xa2,	0xa3, 0xa3, 0xa3, 0xa4, 0xa4, 0xa4, 0xa5, 0xa5,
	0xa0, 0xa0, 0xa1, 0xa1, 0xa1, 0xa2, 0xa2, 0x70,	0x8f, 0xa3, 0x90, 0xa4, 0xa4, 0xa4, 0xa5, 0xa5,
	0xa6, 0xa6, 0xa7, 0xa7, 0xa7, 0xa8, 0xa8, 0x8f,	0x8f, 0xa9, 0x90, 0x90, 0xaa, 0xaa, 0xab, 0xab,
	0xa6, 0xa6, 0xa7, 0xa7, 0xa7, 0xa8, 0xa8, 0xa8,	0xa9, 0xa9, 0x90, 0x90, 0xaa, 0xaa, 0xab, 0xab,
	0xa6, 0xa6, 0xa7, 0xa7, 0xa7, 0xa8, 0xa8, 0x90,	0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0xab, 0xab,
	0xac, 0xac, 0xad, 0xad, 0xad, 0xae, 0xae, 0xae,	0x90, 0x90, 0x90, 0x91, 0x91, 0x91, 0xb1, 0xb1,
	0xac, 0xac, 0xad, 0xad, 0xad, 0xae, 0xae, 0xae,	0xaf, 0xaf, 0x90, 0x91, 0xb0, 0xb0, 0xb1, 0xb1,
	0xac, 0xac, 0xad, 0xad, 0xad, 0xae, 0xae, 0xae,	0xaf, 0xaf, 0x90, 0x91, 0xb0, 0x92, 0xb1, 0xb1,
	0xb2, 0xb2, 0xb3, 0xb3, 0xb3, 0xb4, 0xb4, 0xb4,	0xb5, 0xb5, 0xb5, 0xb6, 0xb6, 0xb6, 0xb7, 0xb7,
	0xb2, 0xb2, 0xb3, 0xb3, 0xb3, 0xb4, 0xb4, 0xb4,	0xb5, 0xb5, 0xb5, 0xb6, 0xb6, 0xb6, 0xb7, 0xb7,
	0x82, 0x82, 0x82, 0xb9, 0xb9, 0xba, 0xba, 0xba,	0xbb, 0xbb, 0xbb, 0xbc, 0xbc, 0xbc, 0xbd, 0xbd,
	0x82, 0x82, 0x82, 0xb9, 0xb9, 0xba, 0xba, 0xba,	0xbb, 0xbb, 0xbb, 0xbc, 0xbc, 0xbc, 0xbd, 0xbd,
	0x82, 0x82, 0xbf, 0xbf, 0xbf, 0xc0, 0xc0, 0xc0,	0xc1, 0xc1, 0xc1, 0xc2, 0xc2, 0xc2, 0xc3, 0xc3,
	0xbe, 0xbe, 0xbf, 0xbf, 0xbf, 0xc0, 0xc0, 0xc0,	0xc1, 0xc1, 0xc1, 0xc2, 0xc2, 0xc2, 0xc3, 0xc3,
	0xbe, 0xbe, 0xbf, 0xbf, 0xbf, 0xc0, 0xc0, 0xc0,	0xc1, 0xc1, 0xc1, 0xc2, 0xc2, 0xc2, 0xc3, 0xc3,
	0xc4, 0xc4, 0xc5, 0xc5, 0xc5, 0xc6, 0xc6, 0xc6,	0xc7, 0xc7, 0xc7, 0xc8, 0xc8, 0xc8, 0xc9, 0xc9,
	0xc4, 0xc4, 0xc5, 0xc5, 0xc5, 0xc6, 0xc6, 0xc6,	0xc7, 0xc7, 0xc7, 0xc8, 0xc8, 0xc8, 0xc9, 0xc9,
	0xc4, 0xc4, 0xc5, 0xc5, 0xc5, 0xc6, 0xc6, 0xc6,	0xc7, 0xc7, 0xc7, 0xc8, 0xc8, 0xc8, 0xc9, 0xc9,
	0xca, 0xca, 0xcb, 0xcb, 0xcb, 0xcc, 0xcc, 0xcc,	0x8f, 0xcd, 0x90, 0x91, 0xce, 0xce, 0xcf, 0xcf,
	0xca, 0xca, 0xcb, 0xcb, 0xcb, 0xcc, 0xcc, 0xcc,	0xcd, 0xcd, 0x90, 0x91, 0xce, 0xce, 0xcf, 0xcf,
	0xca, 0xca, 0xcb, 0xcb, 0xcb, 0xcc, 0xcc, 0xcc,	0x90, 0x90, 0x90, 0x91, 0x91, 0x91, 0xcf, 0xcf,
	0xd0, 0xd0, 0xd1, 0xd1, 0xd1, 0xd2, 0xd2, 0xd2,	0x91, 0x91, 0x91, 0x91, 0x91, 0x91, 0x91, 0xd5,
	0xd0, 0xd0, 0xd1, 0xd1, 0xd1, 0xd2, 0xd2, 0xd2,	0xd3, 0xd3, 0x91, 0x91, 0xd4, 0xd4, 0xd5, 0xd5,
	0xd0, 0xd0, 0xd1, 0xd1, 0xd1, 0xd2, 0xd2, 0xd2,	0xd3, 0xd3, 0x91, 0x91, 0xd4, 0x92, 0x92, 0xd5,
	0xd6, 0xd6, 0xd7, 0xd7, 0xd7, 0xd8, 0xd8, 0xd8,	0xd9, 0xd9, 0xd9, 0x91, 0xda, 0x92, 0x93, 0xdb,
	0xd6, 0xd6, 0xd7, 0xd7, 0xd7, 0xd8, 0xd8, 0xd8,	0xd9, 0xd9, 0xd9, 0xda, 0xda, 0xda, 0xdb, 0xdb,
	0xb8, 0xb8, 0xb9, 0xb9, 0xb9, 0xba, 0xba, 0xba,	0xbb, 0xbb, 0xbb, 0xbc, 0xbc, 0xbc, 0xbd, 0xbd,
	0xb8, 0xb8, 0xb9, 0xb9, 0xb9, 0xba, 0xba, 0xba,	0xbb, 0xbb, 0xbb, 0xbc, 0xbc, 0xbc, 0xbd, 0xbd,
	0xbe, 0xbe, 0xbf, 0xbf, 0xbf, 0xc0, 0xc0, 0xc0,	0xc1, 0xc1, 0xc1, 0xc2, 0xc2, 0xc2, 0xc3, 0xc3,
	0xbe, 0xbe, 0xbf, 0xbf, 0xbf, 0xc0, 0xc0, 0xc0,	0xc1, 0xc1, 0xc1, 0xc2, 0xc2, 0xc2, 0xc3, 0xc3,
	0xbe, 0xbe, 0xbf, 0xbf, 0xbf, 0xc0, 0xc0, 0xc0,	0xc1, 0xc1, 0xc1, 0xc2, 0xc2, 0xc2, 0xc3, 0xc3,
	0xc4, 0xc4, 0xc5, 0xc5, 0xc5, 0xc6, 0xc6, 0xc6,	0xc7, 0xc7, 0xc7, 0xc8, 0xc8, 0xc8, 0xc9, 0xc9,
	0xc4, 0xc4, 0xc5, 0xc5, 0xc5, 0xc6, 0xc6, 0xc6,	0xc7, 0xc7, 0xc7, 0xc8, 0xc8, 0xc8, 0xc9, 0xc9,
	0xc4, 0xc4, 0xc5, 0xc5, 0xc5, 0xc6, 0xc6, 0xc6,	0xc7, 0xc7, 0xc7, 0xc8, 0xc8, 0xc8, 0xc9, 0xc9,
	0xca, 0xca, 0xcb, 0xcb, 0xcb, 0xcc, 0xcc, 0xcc,	0xcd, 0xcd, 0xcd, 0xce, 0xce, 0xce, 0xcf, 0xcf,
	0xca, 0xca, 0xcb, 0xcb, 0xcb, 0xcc, 0xcc, 0xcc,	0xcd, 0xcd, 0xcd, 0xce, 0xce, 0xce, 0xcf, 0xcf,
	0xca, 0xca, 0xcb, 0xcb, 0xcb, 0xcc, 0xcc, 0xcc,	0xcd, 0xcd, 0x90, 0x91, 0xce, 0xce, 0xcf, 0xcf,
	0xd0, 0xd0, 0xd1, 0xd1, 0xd1, 0xd2, 0xd2, 0xd2,	0xd3, 0xd3, 0x91, 0x91, 0xd4, 0xd4, 0xd5, 0xd5,
	0xd0, 0xd0, 0xd1, 0xd1, 0xd1, 0xd2, 0xd2, 0xd2,	0xd3, 0xd3, 0xd3, 0xd4, 0xd4, 0xd4, 0xd5, 0xd5,
	0xd0, 0xd0, 0xd1, 0xd1, 0xd1, 0xd2, 0xd2, 0xd2,	0xd3, 0xd3, 0xd3, 0xd4, 0xd4, 0x92, 0x92, 0xd5,
	0xd6, 0xd6, 0xd7, 0xd7, 0xd7, 0xd8, 0xd8, 0xd8,	0xd9, 0xd9, 0xd9, 0xda, 0xda, 0x92, 0x93, 0xdb,
	0xd6, 0xd6, 0xd7, 0xd7, 0xd7, 0xd8, 0xd8, 0xd8,	0xd9, 0xd9, 0xd9, 0xda, 0xda, 0xda, 0xdb, 0xdb,
	0x83, 0x83, 0x83, 0xb9, 0xb9, 0xba, 0xba, 0xba,	0xbb, 0xbb, 0xbb, 0xbc, 0xbc, 0xbc, 0xbd, 0xbd,
	0x83, 0x83, 0x83, 0xb9, 0xb9, 0xba, 0xba, 0xba,	0xbb, 0xbb, 0xbb, 0xbc, 0xbc, 0xbc, 0xbd, 0xbd,
	0x83, 0x83, 0xbf, 0xbf, 0xbf, 0xc0, 0xc0, 0xc0,	0xc1, 0xc1, 0xc1, 0xc2, 0xc2, 0xc2, 0xc3, 0xc3,
	0xbe, 0xbe, 0xbf, 0xbf, 0xbf, 0xc0, 0xc0, 0xc0,	0xc1, 0xc1, 0xc1, 0xc2, 0xc2, 0xc2, 0xc3, 0xc3,
	0xbe, 0xbe, 0xbf, 0xbf, 0xbf, 0xc0, 0xc0, 0xc0,	0xc1, 0xc1, 0xc1, 0xc2, 0xc2, 0xc2, 0xc3, 0xc3,
	0xc4, 0xc4, 0xc5, 0xc5, 0xc5, 0xc6, 0xc6, 0xc6,	0xc7, 0xc7, 0xc7, 0xc8, 0xc8, 0xc8, 0xc9, 0xc9,
	0xc4, 0xc4, 0xc5, 0xc5, 0xc5, 0xc6, 0xc6, 0xc6,	0xc7, 0xc7, 0xc7, 0xc8, 0xc8, 0xc8, 0xc9, 0xc9,
	0xc4, 0xc4, 0xc5, 0xc5, 0xc5, 0xc6, 0xc6, 0xc6,	0xc7, 0xc7, 0xc7, 0xc8, 0xc8, 0xc8, 0xc9, 0xc9,
	0xca, 0xca, 0xcb, 0xcb, 0xcb, 0xcc, 0xcc, 0xcc,	0xcd, 0xcd, 0xcd, 0xce, 0xce, 0xce, 0xcf, 0xcf,
	0xca, 0xca, 0xcb, 0xcb, 0xcb, 0xcc, 0xcc, 0xcc,	0xcd, 0xcd, 0xcd, 0xce, 0xce, 0xce, 0xcf, 0xcf,
	0xca, 0xca, 0xcb, 0xcb, 0xcb, 0xcc, 0xcc, 0xcc,	0xcd, 0xcd, 0x90, 0x91, 0xce, 0x92, 0xcf, 0xcf,
	0xd0, 0xd0, 0xd1, 0xd1, 0xd1, 0xd2, 0xd2, 0xd2,	0xd3, 0xd3, 0x91, 0x91, 0xd4, 0x92, 0x92, 0xd5,
	0xd0, 0xd0, 0xd1, 0xd1, 0xd1, 0xd2, 0xd2, 0xd2,	0xd3, 0xd3, 0xd3, 0xd4, 0xd4, 0x92, 0x92, 0xd5,
	0xd0, 0xd0, 0xd1, 0xd1, 0xd1, 0xd2, 0xd2, 0xd2,	0xd3, 0xd3, 0x92, 0x92, 0x92, 0x92, 0x92, 0x92,
	0xd6, 0xd6, 0xd7, 0xd7, 0xd7, 0xd8, 0xd8, 0xd8,	0xd9, 0xd9, 0xd9, 0x92, 0x92, 0x92, 0x93, 0x93,
	0xd6, 0xd6, 0xd7, 0xd7, 0xd7, 0xd8, 0xd8, 0xd8,	0xd9, 0xd9, 0xd9, 0xda, 0xda, 0x92, 0x93, 0xdb,
	0x84, 0x84, 0x84, 0xdd, 0xdd, 0xde, 0xde, 0xde,	0xdf, 0xdf, 0xdf, 0xe0, 0xe0, 0xe0, 0xe1, 0xe1,
	0x84, 0x84, 0x84, 0xdd, 0xdd, 0xde, 0xde, 0xde,	0xdf, 0xdf, 0xdf, 0xe0, 0xe0, 0xe0, 0xe1, 0xe1,
	0x84, 0x84, 0xe3, 0xe3, 0xe3, 0xe4, 0xe4, 0xe4,	0xe5, 0xe5, 0xe5, 0xe6, 0xe6, 0xe6, 0xe7, 0xe7,
	0xe2, 0xe2, 0xe3, 0xe3, 0xe3, 0xe4, 0xe4, 0xe4,	0xe5, 0xe5, 0xe5, 0xe6, 0xe6, 0xe6, 0xe7, 0xe7,
	0xe2, 0xe2, 0xe3, 0xe3, 0xe3, 0xe4, 0xe4, 0xe4,	0xe5, 0xe5, 0xe5, 0xe6, 0xe6, 0xe6, 0xe7, 0xe7,
	0xe8, 0xe8, 0xe9, 0xe9, 0xe9, 0xea, 0xea, 0xea,	0xeb, 0xeb, 0xeb, 0xec, 0xec, 0xec, 0xed, 0xed,
	0xe8, 0xe8, 0xe9, 0xe9, 0xe9, 0xea, 0xea, 0xea,	0xeb, 0xeb, 0xeb, 0xec, 0xec, 0xec, 0xed, 0xed,
	0xe8, 0xe8, 0xe9, 0xe9, 0xe9, 0xea, 0xea, 0xea,	0xeb, 0xeb, 0xeb, 0xec, 0xec, 0xec, 0xed, 0xed,
	0xee, 0xee, 0xef, 0xef, 0xef, 0xf0, 0xf0, 0xf0,	0xf1, 0xf1, 0xf1, 0xf2, 0xf2, 0xf2, 0xf3, 0xf3,
	0xee, 0xee, 0xef, 0xef, 0xef, 0xf0, 0xf0, 0xf0,	0xf1, 0xf1, 0xf1, 0xf2, 0xf2, 0xf2, 0xf3, 0xf3,
	0xee, 0xee, 0xef, 0xef, 0xef, 0xf0, 0xf0, 0xf0,	0xf1, 0xf1, 0xf1, 0xf2, 0xf2, 0xf2, 0xf3, 0xf3,
	0xf4, 0xf4, 0xf5, 0xf5, 0xf5, 0xf6, 0xf6, 0xf6,	0xf7, 0xf7, 0xf7, 0x91, 0xf8, 0x92, 0x93, 0xf9,
	0xf4, 0xf4, 0xf5, 0xf5, 0xf5, 0xf6, 0xf6, 0xf6,	0xf7, 0xf7, 0xf7, 0xf8, 0xf8, 0x92, 0x93, 0xf9,
	0xf4, 0xf4, 0xf5, 0xf5, 0xf5, 0xf6, 0xf6, 0xf6,	0xf7, 0xf7, 0xf7, 0x92, 0x92, 0x92, 0x93, 0x93,
	0xfa, 0xfa, 0xfb, 0xfb, 0xfb, 0xfc, 0xfc, 0xfc,	0xfd, 0xfd, 0xfd, 0x93, 0x93, 0x93, 0x93, 0x93,
	0xfa, 0xfa, 0xfb, 0xfb, 0xfb, 0xfc, 0xfc, 0xfc,	0xfd, 0xfd, 0xfd, 0xfe, 0xfe, 0x93, 0x93, 0xff,
	0xdc, 0xdc, 0xdd, 0xdd, 0xdd, 0xde, 0xde, 0xde,	0xdf, 0xdf, 0xdf, 0xe0, 0xe0, 0xe0, 0xe1, 0xe1,
	0xdc, 0xdc, 0xdd, 0xdd, 0xdd, 0xde, 0xde, 0xde,	0xdf, 0xdf, 0xdf, 0xe0, 0xe0, 0xe0, 0xe1, 0xe1,
	0xe2, 0xe2, 0xe3, 0xe3, 0xe3, 0xe4, 0xe4, 0xe4,	0xe5, 0xe5, 0xe5, 0xe6, 0xe6, 0xe6, 0xe7, 0xe7,
	0xe2, 0xe2, 0xe3, 0xe3, 0xe3, 0xe4, 0xe4, 0xe4,	0xe5, 0xe5, 0xe5, 0xe6, 0xe6, 0xe6, 0xe7, 0xe7,
	0xe2, 0xe2, 0xe3, 0xe3, 0xe3, 0xe4, 0xe4, 0xe4,	0xe5, 0xe5, 0xe5, 0xe6, 0xe6, 0xe6, 0xe7, 0xe7,
	0xe8, 0xe8, 0xe9, 0xe9, 0xe9, 0xea, 0xea, 0xea,	0xeb, 0xeb, 0xeb, 0xec, 0xec, 0xec, 0xed, 0xed,
	0xe8, 0xe8, 0xe9, 0xe9, 0xe9, 0xea, 0xea, 0xea,	0xeb, 0xeb, 0xeb, 0xec, 0xec, 0xec, 0xed, 0xed,
	0xe8, 0xe8, 0xe9, 0xe9, 0xe9, 0xea, 0xea, 0xea,	0xeb, 0xeb, 0xeb, 0xec, 0xec, 0xec, 0xed, 0xed,
	0xee, 0xee, 0xef, 0xef, 0xef, 0xf0, 0xf0, 0xf0,	0xf1, 0xf1, 0xf1, 0xf2, 0xf2, 0xf2, 0xf3, 0xf3,
	0xee, 0xee, 0xef, 0xef, 0xef, 0xf0, 0xf0, 0xf0,	0xf1, 0xf1, 0xf1, 0xf2, 0xf2, 0xf2, 0xf3, 0xf3,
	0xee, 0xee, 0xef, 0xef, 0xef, 0xf0, 0xf0, 0xf0,	0xf1, 0xf1, 0xf1, 0xf2, 0xf2, 0xf2, 0xf3, 0xf3,
	0xf4, 0xf4, 0xf5, 0xf5, 0xf5, 0xf6, 0xf6, 0xf6,	0xf7, 0xf7, 0xf7, 0xf8, 0xf8, 0xf8, 0xf9, 0xf9,
	0xf4, 0xf4, 0xf5, 0xf5, 0xf5, 0xf6, 0xf6, 0xf6,	0xf7, 0xf7, 0xf7, 0xf8, 0xf8, 0xf8, 0xf9, 0xf9,
	0xf4, 0xf4, 0xf5, 0xf5, 0xf5, 0xf6, 0xf6, 0xf6,	0xf7, 0xf7, 0xf7, 0xf8, 0xf8, 0x92, 0x93, 0xf9,
	0xfa, 0xfa, 0xfb, 0xfb, 0xfb, 0xfc, 0xfc, 0xfc,	0xfd, 0xfd, 0xfd, 0xfe, 0xfe, 0x93, 0x93, 0xff,
	0xfa, 0xfa, 0xfb, 0xfb, 0xfb, 0xfc, 0xfc, 0xfc,	0xfd, 0xfd, 0xfd, 0xfe, 0xfe, 0xfe, 0xff, 0xff
	};
