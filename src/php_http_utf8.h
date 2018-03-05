/*
    +--------------------------------------------------------------------+
    | PECL :: http                                                       |
    +--------------------------------------------------------------------+
    | Redistribution and use in source and binary forms, with or without |
    | modification, are permitted provided that the conditions mentioned |
    | in the accompanying LICENSE file are met.                          |
    +--------------------------------------------------------------------+
    | Copyright (c) 2004-2014, Michael Wallner <mike@php.net>            |
    +--------------------------------------------------------------------+
*/

#ifndef PHP_HTTP_UTF8_H
#define PHP_HTTP_UTF8_H

typedef struct utf8_range {
	unsigned int start;
	unsigned int end;
	unsigned char step;
} utf8_range_t;

static const unsigned char utf8_mblen[256] = {
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
    2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
    3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
    4,4,4,4,4,4,4,4,5,5,5,5,6,6,6,6
};

static const unsigned char utf8_mask[] = {
		0, 0x7f, 0x1f, 0x0f, 0x07, 0x03, 0x01
};

#if PHP_HTTP_UTF8_LOOP
static const utf8_range_t utf8_ranges[] = {
/* BEGIN::UTF8TABLE */
	{    0x0041,     0x005A, 1},
	{    0x0061,     0x007A, 1},
	{    0x00AA,          0, 0},
	{    0x00B5,          0, 0},
	{    0x00BA,          0, 0},
	{    0x00C0,     0x00D6, 1},
	{    0x00D8,     0x00F6, 1},
	{    0x00F8,     0x02C1, 1},
	{    0x02C6,     0x02D1, 1},
	{    0x02E0,     0x02E4, 1},
	{    0x02EC,          0, 0},
	{    0x02EE,          0, 0},
	{    0x0345,          0, 0},
	{    0x0370,     0x0374, 1},
	{    0x0376,     0x0377, 1},
	{    0x037A,     0x037D, 1},
	{    0x037F,          0, 0},
	{    0x0386,          0, 0},
	{    0x0388,     0x038A, 1},
	{    0x038C,          0, 0},
	{    0x038E,     0x03A1, 1},
	{    0x03A3,     0x03F5, 1},
	{    0x03F7,     0x0481, 1},
	{    0x048A,     0x052F, 1},
	{    0x0531,     0x0556, 1},
	{    0x0559,          0, 0},
	{    0x0561,     0x0587, 1},
	{    0x05B0,     0x05BD, 1},
	{    0x05BF,          0, 0},
	{    0x05C1,     0x05C2, 1},
	{    0x05C4,     0x05C5, 1},
	{    0x05C7,          0, 0},
	{    0x05D0,     0x05EA, 1},
	{    0x05F0,     0x05F2, 1},
	{    0x0610,     0x061A, 1},
	{    0x0620,     0x0657, 1},
	{    0x0659,     0x0669, 1},
	{    0x066E,     0x06D3, 1},
	{    0x06D5,     0x06DC, 1},
	{    0x06E1,     0x06E8, 1},
	{    0x06ED,     0x06FC, 1},
	{    0x06FF,          0, 0},
	{    0x0710,     0x073F, 1},
	{    0x074D,     0x07B1, 1},
	{    0x07C0,     0x07EA, 1},
	{    0x07F4,     0x07F5, 1},
	{    0x07FA,          0, 0},
	{    0x0800,     0x0817, 1},
	{    0x081A,     0x082C, 1},
	{    0x0840,     0x0858, 1},
	{    0x0860,     0x086A, 1},
	{    0x08A0,     0x08B4, 1},
	{    0x08B6,     0x08BD, 1},
	{    0x08D4,     0x08DF, 1},
	{    0x08E3,     0x08E9, 1},
	{    0x08F0,     0x093B, 1},
	{    0x093D,     0x094C, 1},
	{    0x094E,     0x0950, 1},
	{    0x0955,     0x0963, 1},
	{    0x0966,     0x096F, 1},
	{    0x0971,     0x0983, 1},
	{    0x0985,     0x098C, 1},
	{    0x098F,     0x0990, 1},
	{    0x0993,     0x09A8, 1},
	{    0x09AA,     0x09B0, 1},
	{    0x09B2,          0, 0},
	{    0x09B6,     0x09B9, 1},
	{    0x09BD,     0x09C4, 1},
	{    0x09C7,     0x09C8, 1},
	{    0x09CB,     0x09CC, 1},
	{    0x09CE,          0, 0},
	{    0x09D7,          0, 0},
	{    0x09DC,     0x09DD, 1},
	{    0x09DF,     0x09E3, 1},
	{    0x09E6,     0x09F1, 1},
	{    0x09FC,          0, 0},
	{    0x0A01,     0x0A03, 1},
	{    0x0A05,     0x0A0A, 1},
	{    0x0A0F,     0x0A10, 1},
	{    0x0A13,     0x0A28, 1},
	{    0x0A2A,     0x0A30, 1},
	{    0x0A32,     0x0A33, 1},
	{    0x0A35,     0x0A36, 1},
	{    0x0A38,     0x0A39, 1},
	{    0x0A3E,     0x0A42, 1},
	{    0x0A47,     0x0A48, 1},
	{    0x0A4B,     0x0A4C, 1},
	{    0x0A51,          0, 0},
	{    0x0A59,     0x0A5C, 1},
	{    0x0A5E,          0, 0},
	{    0x0A66,     0x0A75, 1},
	{    0x0A81,     0x0A83, 1},
	{    0x0A85,     0x0A8D, 1},
	{    0x0A8F,     0x0A91, 1},
	{    0x0A93,     0x0AA8, 1},
	{    0x0AAA,     0x0AB0, 1},
	{    0x0AB2,     0x0AB3, 1},
	{    0x0AB5,     0x0AB9, 1},
	{    0x0ABD,     0x0AC5, 1},
	{    0x0AC7,     0x0AC9, 1},
	{    0x0ACB,     0x0ACC, 1},
	{    0x0AD0,          0, 0},
	{    0x0AE0,     0x0AE3, 1},
	{    0x0AE6,     0x0AEF, 1},
	{    0x0AF9,     0x0AFC, 1},
	{    0x0B01,     0x0B03, 1},
	{    0x0B05,     0x0B0C, 1},
	{    0x0B0F,     0x0B10, 1},
	{    0x0B13,     0x0B28, 1},
	{    0x0B2A,     0x0B30, 1},
	{    0x0B32,     0x0B33, 1},
	{    0x0B35,     0x0B39, 1},
	{    0x0B3D,     0x0B44, 1},
	{    0x0B47,     0x0B48, 1},
	{    0x0B4B,     0x0B4C, 1},
	{    0x0B56,     0x0B57, 1},
	{    0x0B5C,     0x0B5D, 1},
	{    0x0B5F,     0x0B63, 1},
	{    0x0B66,     0x0B6F, 1},
	{    0x0B71,          0, 0},
	{    0x0B82,     0x0B83, 1},
	{    0x0B85,     0x0B8A, 1},
	{    0x0B8E,     0x0B90, 1},
	{    0x0B92,     0x0B95, 1},
	{    0x0B99,     0x0B9A, 1},
	{    0x0B9C,          0, 0},
	{    0x0B9E,     0x0B9F, 1},
	{    0x0BA3,     0x0BA4, 1},
	{    0x0BA8,     0x0BAA, 1},
	{    0x0BAE,     0x0BB9, 1},
	{    0x0BBE,     0x0BC2, 1},
	{    0x0BC6,     0x0BC8, 1},
	{    0x0BCA,     0x0BCC, 1},
	{    0x0BD0,          0, 0},
	{    0x0BD7,          0, 0},
	{    0x0BE6,     0x0BEF, 1},
	{    0x0C00,     0x0C03, 1},
	{    0x0C05,     0x0C0C, 1},
	{    0x0C0E,     0x0C10, 1},
	{    0x0C12,     0x0C28, 1},
	{    0x0C2A,     0x0C39, 1},
	{    0x0C3D,     0x0C44, 1},
	{    0x0C46,     0x0C48, 1},
	{    0x0C4A,     0x0C4C, 1},
	{    0x0C55,     0x0C56, 1},
	{    0x0C58,     0x0C5A, 1},
	{    0x0C60,     0x0C63, 1},
	{    0x0C66,     0x0C6F, 1},
	{    0x0C80,     0x0C83, 1},
	{    0x0C85,     0x0C8C, 1},
	{    0x0C8E,     0x0C90, 1},
	{    0x0C92,     0x0CA8, 1},
	{    0x0CAA,     0x0CB3, 1},
	{    0x0CB5,     0x0CB9, 1},
	{    0x0CBD,     0x0CC4, 1},
	{    0x0CC6,     0x0CC8, 1},
	{    0x0CCA,     0x0CCC, 1},
	{    0x0CD5,     0x0CD6, 1},
	{    0x0CDE,          0, 0},
	{    0x0CE0,     0x0CE3, 1},
	{    0x0CE6,     0x0CEF, 1},
	{    0x0CF1,     0x0CF2, 1},
	{    0x0D00,     0x0D03, 1},
	{    0x0D05,     0x0D0C, 1},
	{    0x0D0E,     0x0D10, 1},
	{    0x0D12,     0x0D3A, 1},
	{    0x0D3D,     0x0D44, 1},
	{    0x0D46,     0x0D48, 1},
	{    0x0D4A,     0x0D4C, 1},
	{    0x0D4E,          0, 0},
	{    0x0D54,     0x0D57, 1},
	{    0x0D5F,     0x0D63, 1},
	{    0x0D66,     0x0D6F, 1},
	{    0x0D7A,     0x0D7F, 1},
	{    0x0D82,     0x0D83, 1},
	{    0x0D85,     0x0D96, 1},
	{    0x0D9A,     0x0DB1, 1},
	{    0x0DB3,     0x0DBB, 1},
	{    0x0DBD,          0, 0},
	{    0x0DC0,     0x0DC6, 1},
	{    0x0DCF,     0x0DD4, 1},
	{    0x0DD6,          0, 0},
	{    0x0DD8,     0x0DDF, 1},
	{    0x0DE6,     0x0DEF, 1},
	{    0x0DF2,     0x0DF3, 1},
	{    0x0E01,     0x0E3A, 1},
	{    0x0E40,     0x0E46, 1},
	{    0x0E4D,          0, 0},
	{    0x0E50,     0x0E59, 1},
	{    0x0E81,     0x0E82, 1},
	{    0x0E84,          0, 0},
	{    0x0E87,     0x0E88, 1},
	{    0x0E8A,          0, 0},
	{    0x0E8D,          0, 0},
	{    0x0E94,     0x0E97, 1},
	{    0x0E99,     0x0E9F, 1},
	{    0x0EA1,     0x0EA3, 1},
	{    0x0EA5,          0, 0},
	{    0x0EA7,          0, 0},
	{    0x0EAA,     0x0EAB, 1},
	{    0x0EAD,     0x0EB9, 1},
	{    0x0EBB,     0x0EBD, 1},
	{    0x0EC0,     0x0EC4, 1},
	{    0x0EC6,          0, 0},
	{    0x0ECD,          0, 0},
	{    0x0ED0,     0x0ED9, 1},
	{    0x0EDC,     0x0EDF, 1},
	{    0x0F00,          0, 0},
	{    0x0F20,     0x0F29, 1},
	{    0x0F40,     0x0F47, 1},
	{    0x0F49,     0x0F6C, 1},
	{    0x0F71,     0x0F81, 1},
	{    0x0F88,     0x0F97, 1},
	{    0x0F99,     0x0FBC, 1},
	{    0x1000,     0x1036, 1},
	{    0x1038,          0, 0},
	{    0x103B,     0x1049, 1},
	{    0x1050,     0x1062, 1},
	{    0x1065,     0x1068, 1},
	{    0x106E,     0x1086, 1},
	{    0x108E,          0, 0},
	{    0x1090,     0x1099, 1},
	{    0x109C,     0x109D, 1},
	{    0x10A0,     0x10C5, 1},
	{    0x10C7,          0, 0},
	{    0x10CD,          0, 0},
	{    0x10D0,     0x10FA, 1},
	{    0x10FC,     0x1248, 1},
	{    0x124A,     0x124D, 1},
	{    0x1250,     0x1256, 1},
	{    0x1258,          0, 0},
	{    0x125A,     0x125D, 1},
	{    0x1260,     0x1288, 1},
	{    0x128A,     0x128D, 1},
	{    0x1290,     0x12B0, 1},
	{    0x12B2,     0x12B5, 1},
	{    0x12B8,     0x12BE, 1},
	{    0x12C0,          0, 0},
	{    0x12C2,     0x12C5, 1},
	{    0x12C8,     0x12D6, 1},
	{    0x12D8,     0x1310, 1},
	{    0x1312,     0x1315, 1},
	{    0x1318,     0x135A, 1},
	{    0x135F,          0, 0},
	{    0x1380,     0x138F, 1},
	{    0x13A0,     0x13F5, 1},
	{    0x13F8,     0x13FD, 1},
	{    0x1401,     0x166C, 1},
	{    0x166F,     0x167F, 1},
	{    0x1681,     0x169A, 1},
	{    0x16A0,     0x16EA, 1},
	{    0x16EE,     0x16F8, 1},
	{    0x1700,     0x170C, 1},
	{    0x170E,     0x1713, 1},
	{    0x1720,     0x1733, 1},
	{    0x1740,     0x1753, 1},
	{    0x1760,     0x176C, 1},
	{    0x176E,     0x1770, 1},
	{    0x1772,     0x1773, 1},
	{    0x1780,     0x17B3, 1},
	{    0x17B6,     0x17C8, 1},
	{    0x17D7,          0, 0},
	{    0x17DC,          0, 0},
	{    0x17E0,     0x17E9, 1},
	{    0x1810,     0x1819, 1},
	{    0x1820,     0x1877, 1},
	{    0x1880,     0x18AA, 1},
	{    0x18B0,     0x18F5, 1},
	{    0x1900,     0x191E, 1},
	{    0x1920,     0x192B, 1},
	{    0x1930,     0x1938, 1},
	{    0x1946,     0x196D, 1},
	{    0x1970,     0x1974, 1},
	{    0x1980,     0x19AB, 1},
	{    0x19B0,     0x19C9, 1},
	{    0x19D0,     0x19D9, 1},
	{    0x1A00,     0x1A1B, 1},
	{    0x1A20,     0x1A5E, 1},
	{    0x1A61,     0x1A74, 1},
	{    0x1A80,     0x1A89, 1},
	{    0x1A90,     0x1A99, 1},
	{    0x1AA7,          0, 0},
	{    0x1B00,     0x1B33, 1},
	{    0x1B35,     0x1B43, 1},
	{    0x1B45,     0x1B4B, 1},
	{    0x1B50,     0x1B59, 1},
	{    0x1B80,     0x1BA9, 1},
	{    0x1BAC,     0x1BE5, 1},
	{    0x1BE7,     0x1BF1, 1},
	{    0x1C00,     0x1C35, 1},
	{    0x1C40,     0x1C49, 1},
	{    0x1C4D,     0x1C7D, 1},
	{    0x1C80,     0x1C88, 1},
	{    0x1CE9,     0x1CEC, 1},
	{    0x1CEE,     0x1CF3, 1},
	{    0x1CF5,     0x1CF6, 1},
	{    0x1D00,     0x1DBF, 1},
	{    0x1DE7,     0x1DF4, 1},
	{    0x1E00,     0x1F15, 1},
	{    0x1F18,     0x1F1D, 1},
	{    0x1F20,     0x1F45, 1},
	{    0x1F48,     0x1F4D, 1},
	{    0x1F50,     0x1F57, 1},
	{    0x1F59,          0, 0},
	{    0x1F5B,          0, 0},
	{    0x1F5D,          0, 0},
	{    0x1F5F,     0x1F7D, 1},
	{    0x1F80,     0x1FB4, 1},
	{    0x1FB6,     0x1FBC, 1},
	{    0x1FBE,          0, 0},
	{    0x1FC2,     0x1FC4, 1},
	{    0x1FC6,     0x1FCC, 1},
	{    0x1FD0,     0x1FD3, 1},
	{    0x1FD6,     0x1FDB, 1},
	{    0x1FE0,     0x1FEC, 1},
	{    0x1FF2,     0x1FF4, 1},
	{    0x1FF6,     0x1FFC, 1},
	{    0x2071,          0, 0},
	{    0x207F,          0, 0},
	{    0x2090,     0x209C, 1},
	{    0x2102,          0, 0},
	{    0x2107,          0, 0},
	{    0x210A,     0x2113, 1},
	{    0x2115,          0, 0},
	{    0x2119,     0x211D, 1},
	{    0x2124,          0, 0},
	{    0x2126,          0, 0},
	{    0x2128,          0, 0},
	{    0x212A,     0x212D, 1},
	{    0x212F,     0x2139, 1},
	{    0x213C,     0x213F, 1},
	{    0x2145,     0x2149, 1},
	{    0x214E,          0, 0},
	{    0x2160,     0x2188, 1},
	{    0x24B6,     0x24E9, 1},
	{    0x2C00,     0x2C2E, 1},
	{    0x2C30,     0x2C5E, 1},
	{    0x2C60,     0x2CE4, 1},
	{    0x2CEB,     0x2CEE, 1},
	{    0x2CF2,     0x2CF3, 1},
	{    0x2D00,     0x2D25, 1},
	{    0x2D27,          0, 0},
	{    0x2D2D,          0, 0},
	{    0x2D30,     0x2D67, 1},
	{    0x2D6F,          0, 0},
	{    0x2D80,     0x2D96, 1},
	{    0x2DA0,     0x2DA6, 1},
	{    0x2DA8,     0x2DAE, 1},
	{    0x2DB0,     0x2DB6, 1},
	{    0x2DB8,     0x2DBE, 1},
	{    0x2DC0,     0x2DC6, 1},
	{    0x2DC8,     0x2DCE, 1},
	{    0x2DD0,     0x2DD6, 1},
	{    0x2DD8,     0x2DDE, 1},
	{    0x2DE0,     0x2DFF, 1},
	{    0x2E2F,          0, 0},
	{    0x3005,     0x3007, 1},
	{    0x3021,     0x3029, 1},
	{    0x3031,     0x3035, 1},
	{    0x3038,     0x303C, 1},
	{    0x3041,     0x3096, 1},
	{    0x309D,     0x309F, 1},
	{    0x30A1,     0x30FA, 1},
	{    0x30FC,     0x30FF, 1},
	{    0x3105,     0x312E, 1},
	{    0x3131,     0x318E, 1},
	{    0x31A0,     0x31BA, 1},
	{    0x31F0,     0x31FF, 1},
	{    0x3400,     0x4DB5, 1},
	{    0x4E00,     0x9FEA, 1},
	{    0xA000,     0xA48C, 1},
	{    0xA4D0,     0xA4FD, 1},
	{    0xA500,     0xA60C, 1},
	{    0xA610,     0xA62B, 1},
	{    0xA640,     0xA66E, 1},
	{    0xA674,     0xA67B, 1},
	{    0xA67F,     0xA6EF, 1},
	{    0xA717,     0xA71F, 1},
	{    0xA722,     0xA788, 1},
	{    0xA78B,     0xA7AE, 1},
	{    0xA7B0,     0xA7B7, 1},
	{    0xA7F7,     0xA801, 1},
	{    0xA803,     0xA805, 1},
	{    0xA807,     0xA80A, 1},
	{    0xA80C,     0xA827, 1},
	{    0xA840,     0xA873, 1},
	{    0xA880,     0xA8C3, 1},
	{    0xA8C5,          0, 0},
	{    0xA8D0,     0xA8D9, 1},
	{    0xA8F2,     0xA8F7, 1},
	{    0xA8FB,          0, 0},
	{    0xA8FD,          0, 0},
	{    0xA900,     0xA92A, 1},
	{    0xA930,     0xA952, 1},
	{    0xA960,     0xA97C, 1},
	{    0xA980,     0xA9B2, 1},
	{    0xA9B4,     0xA9BF, 1},
	{    0xA9CF,     0xA9D9, 1},
	{    0xA9E0,     0xA9E4, 1},
	{    0xA9E6,     0xA9FE, 1},
	{    0xAA00,     0xAA36, 1},
	{    0xAA40,     0xAA4D, 1},
	{    0xAA50,     0xAA59, 1},
	{    0xAA60,     0xAA76, 1},
	{    0xAA7A,          0, 0},
	{    0xAA7E,     0xAABE, 1},
	{    0xAAC0,          0, 0},
	{    0xAAC2,          0, 0},
	{    0xAADB,     0xAADD, 1},
	{    0xAAE0,     0xAAEF, 1},
	{    0xAAF2,     0xAAF5, 1},
	{    0xAB01,     0xAB06, 1},
	{    0xAB09,     0xAB0E, 1},
	{    0xAB11,     0xAB16, 1},
	{    0xAB20,     0xAB26, 1},
	{    0xAB28,     0xAB2E, 1},
	{    0xAB30,     0xAB5A, 1},
	{    0xAB5C,     0xAB65, 1},
	{    0xAB70,     0xABEA, 1},
	{    0xABF0,     0xABF9, 1},
	{    0xAC00,     0xD7A3, 1},
	{    0xD7B0,     0xD7C6, 1},
	{    0xD7CB,     0xD7FB, 1},
	{    0xF900,     0xFA6D, 1},
	{    0xFA70,     0xFAD9, 1},
	{    0xFB00,     0xFB06, 1},
	{    0xFB13,     0xFB17, 1},
	{    0xFB1D,     0xFB28, 1},
	{    0xFB2A,     0xFB36, 1},
	{    0xFB38,     0xFB3C, 1},
	{    0xFB3E,          0, 0},
	{    0xFB40,     0xFB41, 1},
	{    0xFB43,     0xFB44, 1},
	{    0xFB46,     0xFBB1, 1},
	{    0xFBD3,     0xFD3D, 1},
	{    0xFD50,     0xFD8F, 1},
	{    0xFD92,     0xFDC7, 1},
	{    0xFDF0,     0xFDFB, 1},
	{    0xFE70,     0xFE74, 1},
	{    0xFE76,     0xFEFC, 1},
	{    0xFF10,     0xFF19, 1},
	{    0xFF21,     0xFF3A, 1},
	{    0xFF41,     0xFF5A, 1},
	{    0xFF66,     0xFFBE, 1},
	{    0xFFC2,     0xFFC7, 1},
	{    0xFFCA,     0xFFCF, 1},
	{    0xFFD2,     0xFFD7, 1},
	{    0xFFDA,     0xFFDC, 1},
	{0x00010000, 0x0001000B, 1},
	{0x0001000D, 0x00010026, 1},
	{0x00010028, 0x0001003A, 1},
	{0x0001003C, 0x0001003D, 1},
	{0x0001003F, 0x0001004D, 1},
	{0x00010050, 0x0001005D, 1},
	{0x00010080, 0x000100FA, 1},
	{0x00010140, 0x00010174, 1},
	{0x00010280, 0x0001029C, 1},
	{0x000102A0, 0x000102D0, 1},
	{0x00010300, 0x0001031F, 1},
	{0x0001032D, 0x0001034A, 1},
	{0x00010350, 0x0001037A, 1},
	{0x00010380, 0x0001039D, 1},
	{0x000103A0, 0x000103C3, 1},
	{0x000103C8, 0x000103CF, 1},
	{0x000103D1, 0x000103D5, 1},
	{0x00010400, 0x0001049D, 1},
	{0x000104A0, 0x000104A9, 1},
	{0x000104B0, 0x000104D3, 1},
	{0x000104D8, 0x000104FB, 1},
	{0x00010500, 0x00010527, 1},
	{0x00010530, 0x00010563, 1},
	{0x00010600, 0x00010736, 1},
	{0x00010740, 0x00010755, 1},
	{0x00010760, 0x00010767, 1},
	{0x00010800, 0x00010805, 1},
	{0x00010808,          0, 0},
	{0x0001080A, 0x00010835, 1},
	{0x00010837, 0x00010838, 1},
	{0x0001083C,          0, 0},
	{0x0001083F, 0x00010855, 1},
	{0x00010860, 0x00010876, 1},
	{0x00010880, 0x0001089E, 1},
	{0x000108E0, 0x000108F2, 1},
	{0x000108F4, 0x000108F5, 1},
	{0x00010900, 0x00010915, 1},
	{0x00010920, 0x00010939, 1},
	{0x00010980, 0x000109B7, 1},
	{0x000109BE, 0x000109BF, 1},
	{0x00010A00, 0x00010A03, 1},
	{0x00010A05, 0x00010A06, 1},
	{0x00010A0C, 0x00010A13, 1},
	{0x00010A15, 0x00010A17, 1},
	{0x00010A19, 0x00010A33, 1},
	{0x00010A60, 0x00010A7C, 1},
	{0x00010A80, 0x00010A9C, 1},
	{0x00010AC0, 0x00010AC7, 1},
	{0x00010AC9, 0x00010AE4, 1},
	{0x00010B00, 0x00010B35, 1},
	{0x00010B40, 0x00010B55, 1},
	{0x00010B60, 0x00010B72, 1},
	{0x00010B80, 0x00010B91, 1},
	{0x00010C00, 0x00010C48, 1},
	{0x00010C80, 0x00010CB2, 1},
	{0x00010CC0, 0x00010CF2, 1},
	{0x00011000, 0x00011045, 1},
	{0x00011066, 0x0001106F, 1},
	{0x00011082, 0x000110B8, 1},
	{0x000110D0, 0x000110E8, 1},
	{0x000110F0, 0x000110F9, 1},
	{0x00011100, 0x00011132, 1},
	{0x00011136, 0x0001113F, 1},
	{0x00011150, 0x00011172, 1},
	{0x00011176,          0, 0},
	{0x00011180, 0x000111BF, 1},
	{0x000111C1, 0x000111C4, 1},
	{0x000111D0, 0x000111DA, 1},
	{0x000111DC,          0, 0},
	{0x00011200, 0x00011211, 1},
	{0x00011213, 0x00011234, 1},
	{0x00011237,          0, 0},
	{0x0001123E,          0, 0},
	{0x00011280, 0x00011286, 1},
	{0x00011288,          0, 0},
	{0x0001128A, 0x0001128D, 1},
	{0x0001128F, 0x0001129D, 1},
	{0x0001129F, 0x000112A8, 1},
	{0x000112B0, 0x000112E8, 1},
	{0x000112F0, 0x000112F9, 1},
	{0x00011300, 0x00011303, 1},
	{0x00011305, 0x0001130C, 1},
	{0x0001130F, 0x00011310, 1},
	{0x00011313, 0x00011328, 1},
	{0x0001132A, 0x00011330, 1},
	{0x00011332, 0x00011333, 1},
	{0x00011335, 0x00011339, 1},
	{0x0001133D, 0x00011344, 1},
	{0x00011347, 0x00011348, 1},
	{0x0001134B, 0x0001134C, 1},
	{0x00011350,          0, 0},
	{0x00011357,          0, 0},
	{0x0001135D, 0x00011363, 1},
	{0x00011400, 0x00011441, 1},
	{0x00011443, 0x00011445, 1},
	{0x00011447, 0x0001144A, 1},
	{0x00011450, 0x00011459, 1},
	{0x00011480, 0x000114C1, 1},
	{0x000114C4, 0x000114C5, 1},
	{0x000114C7,          0, 0},
	{0x000114D0, 0x000114D9, 1},
	{0x00011580, 0x000115B5, 1},
	{0x000115B8, 0x000115BE, 1},
	{0x000115D8, 0x000115DD, 1},
	{0x00011600, 0x0001163E, 1},
	{0x00011640,          0, 0},
	{0x00011644,          0, 0},
	{0x00011650, 0x00011659, 1},
	{0x00011680, 0x000116B5, 1},
	{0x000116C0, 0x000116C9, 1},
	{0x00011700, 0x00011719, 1},
	{0x0001171D, 0x0001172A, 1},
	{0x00011730, 0x00011739, 1},
	{0x000118A0, 0x000118E9, 1},
	{0x000118FF,          0, 0},
	{0x00011A00, 0x00011A32, 1},
	{0x00011A35, 0x00011A3E, 1},
	{0x00011A50, 0x00011A83, 1},
	{0x00011A86, 0x00011A97, 1},
	{0x00011AC0, 0x00011AF8, 1},
	{0x00011C00, 0x00011C08, 1},
	{0x00011C0A, 0x00011C36, 1},
	{0x00011C38, 0x00011C3E, 1},
	{0x00011C40,          0, 0},
	{0x00011C50, 0x00011C59, 1},
	{0x00011C72, 0x00011C8F, 1},
	{0x00011C92, 0x00011CA7, 1},
	{0x00011CA9, 0x00011CB6, 1},
	{0x00011D00, 0x00011D06, 1},
	{0x00011D08, 0x00011D09, 1},
	{0x00011D0B, 0x00011D36, 1},
	{0x00011D3A,          0, 0},
	{0x00011D3C, 0x00011D3D, 1},
	{0x00011D3F, 0x00011D41, 1},
	{0x00011D43,          0, 0},
	{0x00011D46, 0x00011D47, 1},
	{0x00011D50, 0x00011D59, 1},
	{0x00012000, 0x00012399, 1},
	{0x00012400, 0x0001246E, 1},
	{0x00012480, 0x00012543, 1},
	{0x00013000, 0x0001342E, 1},
	{0x00014400, 0x00014646, 1},
	{0x00016800, 0x00016A38, 1},
	{0x00016A40, 0x00016A5E, 1},
	{0x00016A60, 0x00016A69, 1},
	{0x00016AD0, 0x00016AED, 1},
	{0x00016B00, 0x00016B36, 1},
	{0x00016B40, 0x00016B43, 1},
	{0x00016B50, 0x00016B59, 1},
	{0x00016B63, 0x00016B77, 1},
	{0x00016B7D, 0x00016B8F, 1},
	{0x00016F00, 0x00016F44, 1},
	{0x00016F50, 0x00016F7E, 1},
	{0x00016F93, 0x00016F9F, 1},
	{0x00016FE0, 0x00016FE1, 1},
	{0x00017000, 0x000187EC, 1},
	{0x00018800, 0x00018AF2, 1},
	{0x0001B000, 0x0001B11E, 1},
	{0x0001B170, 0x0001B2FB, 1},
	{0x0001BC00, 0x0001BC6A, 1},
	{0x0001BC70, 0x0001BC7C, 1},
	{0x0001BC80, 0x0001BC88, 1},
	{0x0001BC90, 0x0001BC99, 1},
	{0x0001BC9E,          0, 0},
	{0x0001D400, 0x0001D454, 1},
	{0x0001D456, 0x0001D49C, 1},
	{0x0001D49E, 0x0001D49F, 1},
	{0x0001D4A2,          0, 0},
	{0x0001D4A5, 0x0001D4A6, 1},
	{0x0001D4A9, 0x0001D4AC, 1},
	{0x0001D4AE, 0x0001D4B9, 1},
	{0x0001D4BB,          0, 0},
	{0x0001D4BD, 0x0001D4C3, 1},
	{0x0001D4C5, 0x0001D505, 1},
	{0x0001D507, 0x0001D50A, 1},
	{0x0001D50D, 0x0001D514, 1},
	{0x0001D516, 0x0001D51C, 1},
	{0x0001D51E, 0x0001D539, 1},
	{0x0001D53B, 0x0001D53E, 1},
	{0x0001D540, 0x0001D544, 1},
	{0x0001D546,          0, 0},
	{0x0001D54A, 0x0001D550, 1},
	{0x0001D552, 0x0001D6A5, 1},
	{0x0001D6A8, 0x0001D6C0, 1},
	{0x0001D6C2, 0x0001D6DA, 1},
	{0x0001D6DC, 0x0001D6FA, 1},
	{0x0001D6FC, 0x0001D714, 1},
	{0x0001D716, 0x0001D734, 1},
	{0x0001D736, 0x0001D74E, 1},
	{0x0001D750, 0x0001D76E, 1},
	{0x0001D770, 0x0001D788, 1},
	{0x0001D78A, 0x0001D7A8, 1},
	{0x0001D7AA, 0x0001D7C2, 1},
	{0x0001D7C4, 0x0001D7CB, 1},
	{0x0001D7CE, 0x0001D7FF, 1},
	{0x0001E000, 0x0001E006, 1},
	{0x0001E008, 0x0001E018, 1},
	{0x0001E01B, 0x0001E021, 1},
	{0x0001E023, 0x0001E024, 1},
	{0x0001E026, 0x0001E02A, 1},
	{0x0001E800, 0x0001E8C4, 1},
	{0x0001E900, 0x0001E943, 1},
	{0x0001E947,          0, 0},
	{0x0001E950, 0x0001E959, 1},
	{0x0001EE00, 0x0001EE03, 1},
	{0x0001EE05, 0x0001EE1F, 1},
	{0x0001EE21, 0x0001EE22, 1},
	{0x0001EE24,          0, 0},
	{0x0001EE27,          0, 0},
	{0x0001EE29, 0x0001EE32, 1},
	{0x0001EE34, 0x0001EE37, 1},
	{0x0001EE39,          0, 0},
	{0x0001EE3B,          0, 0},
	{0x0001EE42,          0, 0},
	{0x0001EE47,          0, 0},
	{0x0001EE49,          0, 0},
	{0x0001EE4B,          0, 0},
	{0x0001EE4D, 0x0001EE4F, 1},
	{0x0001EE51, 0x0001EE52, 1},
	{0x0001EE54,          0, 0},
	{0x0001EE57,          0, 0},
	{0x0001EE59,          0, 0},
	{0x0001EE5B,          0, 0},
	{0x0001EE5D,          0, 0},
	{0x0001EE5F,          0, 0},
	{0x0001EE61, 0x0001EE62, 1},
	{0x0001EE64,          0, 0},
	{0x0001EE67, 0x0001EE6A, 1},
	{0x0001EE6C, 0x0001EE72, 1},
	{0x0001EE74, 0x0001EE77, 1},
	{0x0001EE79, 0x0001EE7C, 1},
	{0x0001EE7E,          0, 0},
	{0x0001EE80, 0x0001EE89, 1},
	{0x0001EE8B, 0x0001EE9B, 1},
	{0x0001EEA1, 0x0001EEA3, 1},
	{0x0001EEA5, 0x0001EEA9, 1},
	{0x0001EEAB, 0x0001EEBB, 1},
	{0x0001F130, 0x0001F149, 1},
	{0x0001F150, 0x0001F169, 1},
	{0x0001F170, 0x0001F189, 1},
	{0x00020000, 0x0002A6D6, 1},
	{0x0002A700, 0x0002B734, 1},
	{0x0002B740, 0x0002B81D, 1},
	{0x0002B820, 0x0002CEA1, 1},
	{0x0002CEB0, 0x0002EBE0, 1},
	{0x0002F800, 0x0002FA1D, 1},

/* END::UTF8TABLE */
};
#endif

static inline size_t utf8towc(unsigned *wc, const unsigned char *uc, size_t len)
{
	unsigned char ub = utf8_mblen[*uc];

	if (!ub || ub > len || ub > 4) {
		return 0;
	}

	*wc = *uc & utf8_mask[ub];

	switch (ub) {
	case 4:
		if ((uc[1] & 0xc0) != 0x80) {
			return 0;
		}
		*wc <<= 6;
		*wc += *++uc & 0x3f;
		/* no break */
	case 3:
		if ((uc[1] & 0xc0) != 0x80) {
			return 0;
		}
		*wc <<= 6;
		*wc += *++uc & 0x3f;
		/* no break */
	case 2:
		if ((uc[1] & 0xc0) != 0x80) {
			return 0;
		}
		*wc <<= 6;
		*wc += *++uc & 0x3f;
		/* no break */
	case 1:
		break;

	default:
		return 0;
	}

	return ub;
}

static inline zend_bool isualpha(unsigned ch)
{
#if PHP_HTTP_UTF8_LOOP
	unsigned j;
	const utf8_range_t *u = &utf8_ranges[0], *e = &utf8_ranges[sizeof(utf8_ranges)/sizeof(utf8_range_t)-1];

	do {
		if (u->start == ch) {
			return 1;
		} else if (u->start <= ch && u->end >= ch) {
			if (u->step == 1) {
				return 1;
			}
			for (j = u->start; j <= u->end; j+= u->step) {
				if (ch == j) {
					return 1;
				}
			}
			return 0;
		}
	} while (++u != e);

#else

/* BEGIN::UTF8SWITCH */
/* generated on 03/03/18 15:03:45 with
 b = 10
 m = 0x003ffffc
 b2= 8
*/switch (ch >> 10) {
case 0x00000000:
 switch((ch & 0x003FFFFC) >> 8) {
 case 0x00000000:
  if (ch >= 0x00000041) {
   if (ch <= 0x0000005A) return 1;
   if (ch >= 0x00000061) {
    if (ch <= 0x0000007A) return 1;
    if (ch == 0x000000AA) return 1;
    if (ch == 0x000000B5) return 1;
    if (ch == 0x000000BA) return 1;
    if (ch >= 0x000000C0) {
     if (ch <= 0x000000D6) return 1;
     if (ch >= 0x000000D8) {
      if (ch <= 0x000000F6) return 1;
      if (ch >= 0x000000F8) {
       if (ch <= 0x000002C1) return 1;
  }}}}}
  break;
 case 0x00000002:
  if (ch >= 0x000002C6) {
   if (ch <= 0x000002D1) return 1;
   if (ch >= 0x000002E0) {
    if (ch <= 0x000002E4) return 1;
    if (ch == 0x000002EC) return 1;
    if (ch == 0x000002EE) return 1;
  }}
  break;
 case 0x00000003:
  if (ch == 0x00000345) return 1;
  if (ch >= 0x00000370) {
   if (ch <= 0x00000374) return 1;
   if (ch >= 0x00000376) {
    if (ch <= 0x00000377) return 1;
    if (ch >= 0x0000037A) {
     if (ch <= 0x0000037D) return 1;
     if (ch == 0x0000037F) return 1;
     if (ch == 0x00000386) return 1;
     if (ch >= 0x00000388) {
      if (ch <= 0x0000038A) return 1;
      if (ch == 0x0000038C) return 1;
      if (ch >= 0x0000038E) {
       if (ch <= 0x000003A1) return 1;
       if (ch >= 0x000003A3) {
        if (ch <= 0x000003F5) return 1;
        if (ch >= 0x000003F7) {
         if (ch <= 0x00000481) return 1;
  }}}}}}}
  break;
 }
 break;
case 0x00000001:
 switch((ch & 0x003FFFFC) >> 8) {
 case 0x00000004:
  if (ch >= 0x0000048A) {
   if (ch <= 0x0000052F) return 1;
  }
  break;
 case 0x00000005:
  if (ch >= 0x00000531) {
   if (ch <= 0x00000556) return 1;
   if (ch == 0x00000559) return 1;
   if (ch >= 0x00000561) {
    if (ch <= 0x00000587) return 1;
    if (ch >= 0x000005B0) {
     if (ch <= 0x000005BD) return 1;
     if (ch == 0x000005BF) return 1;
     if (ch >= 0x000005C1) {
      if (ch <= 0x000005C2) return 1;
      if (ch >= 0x000005C4) {
       if (ch <= 0x000005C5) return 1;
       if (ch == 0x000005C7) return 1;
       if (ch >= 0x000005D0) {
        if (ch <= 0x000005EA) return 1;
        if (ch >= 0x000005F0) {
         if (ch <= 0x000005F2) return 1;
  }}}}}}}
  break;
 case 0x00000006:
  if (ch >= 0x00000610) {
   if (ch <= 0x0000061A) return 1;
   if (ch >= 0x00000620) {
    if (ch <= 0x00000657) return 1;
    if (ch >= 0x00000659) {
     if (ch <= 0x00000669) return 1;
     if (ch >= 0x0000066E) {
      if (ch <= 0x000006D3) return 1;
      if (ch >= 0x000006D5) {
       if (ch <= 0x000006DC) return 1;
       if (ch >= 0x000006E1) {
        if (ch <= 0x000006E8) return 1;
        if (ch >= 0x000006ED) {
         if (ch <= 0x000006FC) return 1;
         if (ch == 0x000006FF) return 1;
  }}}}}}}
  break;
 case 0x00000007:
  if (ch >= 0x00000710) {
   if (ch <= 0x0000073F) return 1;
   if (ch >= 0x0000074D) {
    if (ch <= 0x000007B1) return 1;
    if (ch >= 0x000007C0) {
     if (ch <= 0x000007EA) return 1;
     if (ch >= 0x000007F4) {
      if (ch <= 0x000007F5) return 1;
      if (ch == 0x000007FA) return 1;
  }}}}
  break;
 }
 break;
case 0x00000002:
 switch((ch & 0x003FFFFC) >> 8) {
 case 0x00000008:
  if (ch >= 0x00000800) {
   if (ch <= 0x00000817) return 1;
   if (ch >= 0x0000081A) {
    if (ch <= 0x0000082C) return 1;
    if (ch >= 0x00000840) {
     if (ch <= 0x00000858) return 1;
     if (ch >= 0x00000860) {
      if (ch <= 0x0000086A) return 1;
      if (ch >= 0x000008A0) {
       if (ch <= 0x000008B4) return 1;
       if (ch >= 0x000008B6) {
        if (ch <= 0x000008BD) return 1;
        if (ch >= 0x000008D4) {
         if (ch <= 0x000008DF) return 1;
         if (ch >= 0x000008E3) {
          if (ch <= 0x000008E9) return 1;
          if (ch >= 0x000008F0) {
           if (ch <= 0x0000093B) return 1;
  }}}}}}}}}
  break;
 case 0x00000009:
  if (ch >= 0x0000093D) {
   if (ch <= 0x0000094C) return 1;
   if (ch >= 0x0000094E) {
    if (ch <= 0x00000950) return 1;
    if (ch >= 0x00000955) {
     if (ch <= 0x00000963) return 1;
     if (ch >= 0x00000966) {
      if (ch <= 0x0000096F) return 1;
      if (ch >= 0x00000971) {
       if (ch <= 0x00000983) return 1;
       if (ch >= 0x00000985) {
        if (ch <= 0x0000098C) return 1;
        if (ch >= 0x0000098F) {
         if (ch <= 0x00000990) return 1;
         if (ch >= 0x00000993) {
          if (ch <= 0x000009A8) return 1;
          if (ch >= 0x000009AA) {
           if (ch <= 0x000009B0) return 1;
           if (ch == 0x000009B2) return 1;
           if (ch >= 0x000009B6) {
            if (ch <= 0x000009B9) return 1;
            if (ch >= 0x000009BD) {
             if (ch <= 0x000009C4) return 1;
             if (ch >= 0x000009C7) {
              if (ch <= 0x000009C8) return 1;
              if (ch >= 0x000009CB) {
               if (ch <= 0x000009CC) return 1;
               if (ch == 0x000009CE) return 1;
               if (ch == 0x000009D7) return 1;
               if (ch >= 0x000009DC) {
                if (ch <= 0x000009DD) return 1;
                if (ch >= 0x000009DF) {
                 if (ch <= 0x000009E3) return 1;
                 if (ch >= 0x000009E6) {
                  if (ch <= 0x000009F1) return 1;
                  if (ch == 0x000009FC) return 1;
  }}}}}}}}}}}}}}}}
  break;
 case 0x0000000A:
  if (ch >= 0x00000A01) {
   if (ch <= 0x00000A03) return 1;
   if (ch >= 0x00000A05) {
    if (ch <= 0x00000A0A) return 1;
    if (ch >= 0x00000A0F) {
     if (ch <= 0x00000A10) return 1;
     if (ch >= 0x00000A13) {
      if (ch <= 0x00000A28) return 1;
      if (ch >= 0x00000A2A) {
       if (ch <= 0x00000A30) return 1;
       if (ch >= 0x00000A32) {
        if (ch <= 0x00000A33) return 1;
        if (ch >= 0x00000A35) {
         if (ch <= 0x00000A36) return 1;
         if (ch >= 0x00000A38) {
          if (ch <= 0x00000A39) return 1;
          if (ch >= 0x00000A3E) {
           if (ch <= 0x00000A42) return 1;
           if (ch >= 0x00000A47) {
            if (ch <= 0x00000A48) return 1;
            if (ch >= 0x00000A4B) {
             if (ch <= 0x00000A4C) return 1;
             if (ch == 0x00000A51) return 1;
             if (ch >= 0x00000A59) {
              if (ch <= 0x00000A5C) return 1;
              if (ch == 0x00000A5E) return 1;
              if (ch >= 0x00000A66) {
               if (ch <= 0x00000A75) return 1;
               if (ch >= 0x00000A81) {
                if (ch <= 0x00000A83) return 1;
                if (ch >= 0x00000A85) {
                 if (ch <= 0x00000A8D) return 1;
                 if (ch >= 0x00000A8F) {
                  if (ch <= 0x00000A91) return 1;
                  if (ch >= 0x00000A93) {
                   if (ch <= 0x00000AA8) return 1;
                   if (ch >= 0x00000AAA) {
                    if (ch <= 0x00000AB0) return 1;
                    if (ch >= 0x00000AB2) {
                     if (ch <= 0x00000AB3) return 1;
                     if (ch >= 0x00000AB5) {
                      if (ch <= 0x00000AB9) return 1;
                      if (ch >= 0x00000ABD) {
                       if (ch <= 0x00000AC5) return 1;
                       if (ch >= 0x00000AC7) {
                        if (ch <= 0x00000AC9) return 1;
                        if (ch >= 0x00000ACB) {
                         if (ch <= 0x00000ACC) return 1;
                         if (ch == 0x00000AD0) return 1;
                         if (ch >= 0x00000AE0) {
                          if (ch <= 0x00000AE3) return 1;
                          if (ch >= 0x00000AE6) {
                           if (ch <= 0x00000AEF) return 1;
                           if (ch >= 0x00000AF9) {
                            if (ch <= 0x00000AFC) return 1;
  }}}}}}}}}}}}}}}}}}}}}}}}}}
  break;
 case 0x0000000B:
  if (ch >= 0x00000B01) {
   if (ch <= 0x00000B03) return 1;
   if (ch >= 0x00000B05) {
    if (ch <= 0x00000B0C) return 1;
    if (ch >= 0x00000B0F) {
     if (ch <= 0x00000B10) return 1;
     if (ch >= 0x00000B13) {
      if (ch <= 0x00000B28) return 1;
      if (ch >= 0x00000B2A) {
       if (ch <= 0x00000B30) return 1;
       if (ch >= 0x00000B32) {
        if (ch <= 0x00000B33) return 1;
        if (ch >= 0x00000B35) {
         if (ch <= 0x00000B39) return 1;
         if (ch >= 0x00000B3D) {
          if (ch <= 0x00000B44) return 1;
          if (ch >= 0x00000B47) {
           if (ch <= 0x00000B48) return 1;
           if (ch >= 0x00000B4B) {
            if (ch <= 0x00000B4C) return 1;
            if (ch >= 0x00000B56) {
             if (ch <= 0x00000B57) return 1;
             if (ch >= 0x00000B5C) {
              if (ch <= 0x00000B5D) return 1;
              if (ch >= 0x00000B5F) {
               if (ch <= 0x00000B63) return 1;
               if (ch >= 0x00000B66) {
                if (ch <= 0x00000B6F) return 1;
                if (ch == 0x00000B71) return 1;
                if (ch >= 0x00000B82) {
                 if (ch <= 0x00000B83) return 1;
                 if (ch >= 0x00000B85) {
                  if (ch <= 0x00000B8A) return 1;
                  if (ch >= 0x00000B8E) {
                   if (ch <= 0x00000B90) return 1;
                   if (ch >= 0x00000B92) {
                    if (ch <= 0x00000B95) return 1;
                    if (ch >= 0x00000B99) {
                     if (ch <= 0x00000B9A) return 1;
                     if (ch == 0x00000B9C) return 1;
                     if (ch >= 0x00000B9E) {
                      if (ch <= 0x00000B9F) return 1;
                      if (ch >= 0x00000BA3) {
                       if (ch <= 0x00000BA4) return 1;
                       if (ch >= 0x00000BA8) {
                        if (ch <= 0x00000BAA) return 1;
                        if (ch >= 0x00000BAE) {
                         if (ch <= 0x00000BB9) return 1;
                         if (ch >= 0x00000BBE) {
                          if (ch <= 0x00000BC2) return 1;
                          if (ch >= 0x00000BC6) {
                           if (ch <= 0x00000BC8) return 1;
                           if (ch >= 0x00000BCA) {
                            if (ch <= 0x00000BCC) return 1;
                            if (ch == 0x00000BD0) return 1;
                            if (ch == 0x00000BD7) return 1;
                            if (ch >= 0x00000BE6) {
                             if (ch <= 0x00000BEF) return 1;
  }}}}}}}}}}}}}}}}}}}}}}}}}}}
  break;
 }
 break;
case 0x00000003:
 switch((ch & 0x003FFFFC) >> 8) {
 case 0x0000000C:
  if (ch >= 0x00000C00) {
   if (ch <= 0x00000C03) return 1;
   if (ch >= 0x00000C05) {
    if (ch <= 0x00000C0C) return 1;
    if (ch >= 0x00000C0E) {
     if (ch <= 0x00000C10) return 1;
     if (ch >= 0x00000C12) {
      if (ch <= 0x00000C28) return 1;
      if (ch >= 0x00000C2A) {
       if (ch <= 0x00000C39) return 1;
       if (ch >= 0x00000C3D) {
        if (ch <= 0x00000C44) return 1;
        if (ch >= 0x00000C46) {
         if (ch <= 0x00000C48) return 1;
         if (ch >= 0x00000C4A) {
          if (ch <= 0x00000C4C) return 1;
          if (ch >= 0x00000C55) {
           if (ch <= 0x00000C56) return 1;
           if (ch >= 0x00000C58) {
            if (ch <= 0x00000C5A) return 1;
            if (ch >= 0x00000C60) {
             if (ch <= 0x00000C63) return 1;
             if (ch >= 0x00000C66) {
              if (ch <= 0x00000C6F) return 1;
              if (ch >= 0x00000C80) {
               if (ch <= 0x00000C83) return 1;
               if (ch >= 0x00000C85) {
                if (ch <= 0x00000C8C) return 1;
                if (ch >= 0x00000C8E) {
                 if (ch <= 0x00000C90) return 1;
                 if (ch >= 0x00000C92) {
                  if (ch <= 0x00000CA8) return 1;
                  if (ch >= 0x00000CAA) {
                   if (ch <= 0x00000CB3) return 1;
                   if (ch >= 0x00000CB5) {
                    if (ch <= 0x00000CB9) return 1;
                    if (ch >= 0x00000CBD) {
                     if (ch <= 0x00000CC4) return 1;
                     if (ch >= 0x00000CC6) {
                      if (ch <= 0x00000CC8) return 1;
                      if (ch >= 0x00000CCA) {
                       if (ch <= 0x00000CCC) return 1;
                       if (ch >= 0x00000CD5) {
                        if (ch <= 0x00000CD6) return 1;
                        if (ch == 0x00000CDE) return 1;
                        if (ch >= 0x00000CE0) {
                         if (ch <= 0x00000CE3) return 1;
                         if (ch >= 0x00000CE6) {
                          if (ch <= 0x00000CEF) return 1;
                          if (ch >= 0x00000CF1) {
                           if (ch <= 0x00000CF2) return 1;
  }}}}}}}}}}}}}}}}}}}}}}}}}
  break;
 case 0x0000000D:
  if (ch >= 0x00000D00) {
   if (ch <= 0x00000D03) return 1;
   if (ch >= 0x00000D05) {
    if (ch <= 0x00000D0C) return 1;
    if (ch >= 0x00000D0E) {
     if (ch <= 0x00000D10) return 1;
     if (ch >= 0x00000D12) {
      if (ch <= 0x00000D3A) return 1;
      if (ch >= 0x00000D3D) {
       if (ch <= 0x00000D44) return 1;
       if (ch >= 0x00000D46) {
        if (ch <= 0x00000D48) return 1;
        if (ch >= 0x00000D4A) {
         if (ch <= 0x00000D4C) return 1;
         if (ch == 0x00000D4E) return 1;
         if (ch >= 0x00000D54) {
          if (ch <= 0x00000D57) return 1;
          if (ch >= 0x00000D5F) {
           if (ch <= 0x00000D63) return 1;
           if (ch >= 0x00000D66) {
            if (ch <= 0x00000D6F) return 1;
            if (ch >= 0x00000D7A) {
             if (ch <= 0x00000D7F) return 1;
             if (ch >= 0x00000D82) {
              if (ch <= 0x00000D83) return 1;
              if (ch >= 0x00000D85) {
               if (ch <= 0x00000D96) return 1;
               if (ch >= 0x00000D9A) {
                if (ch <= 0x00000DB1) return 1;
                if (ch >= 0x00000DB3) {
                 if (ch <= 0x00000DBB) return 1;
                 if (ch == 0x00000DBD) return 1;
                 if (ch >= 0x00000DC0) {
                  if (ch <= 0x00000DC6) return 1;
                  if (ch >= 0x00000DCF) {
                   if (ch <= 0x00000DD4) return 1;
                   if (ch == 0x00000DD6) return 1;
                   if (ch >= 0x00000DD8) {
                    if (ch <= 0x00000DDF) return 1;
                    if (ch >= 0x00000DE6) {
                     if (ch <= 0x00000DEF) return 1;
                     if (ch >= 0x00000DF2) {
                      if (ch <= 0x00000DF3) return 1;
  }}}}}}}}}}}}}}}}}}}}
  break;
 case 0x0000000E:
  if (ch >= 0x00000E01) {
   if (ch <= 0x00000E3A) return 1;
   if (ch >= 0x00000E40) {
    if (ch <= 0x00000E46) return 1;
    if (ch == 0x00000E4D) return 1;
    if (ch >= 0x00000E50) {
     if (ch <= 0x00000E59) return 1;
     if (ch >= 0x00000E81) {
      if (ch <= 0x00000E82) return 1;
      if (ch == 0x00000E84) return 1;
      if (ch >= 0x00000E87) {
       if (ch <= 0x00000E88) return 1;
       if (ch == 0x00000E8A) return 1;
       if (ch == 0x00000E8D) return 1;
       if (ch >= 0x00000E94) {
        if (ch <= 0x00000E97) return 1;
        if (ch >= 0x00000E99) {
         if (ch <= 0x00000E9F) return 1;
         if (ch >= 0x00000EA1) {
          if (ch <= 0x00000EA3) return 1;
          if (ch == 0x00000EA5) return 1;
          if (ch == 0x00000EA7) return 1;
          if (ch >= 0x00000EAA) {
           if (ch <= 0x00000EAB) return 1;
           if (ch >= 0x00000EAD) {
            if (ch <= 0x00000EB9) return 1;
            if (ch >= 0x00000EBB) {
             if (ch <= 0x00000EBD) return 1;
             if (ch >= 0x00000EC0) {
              if (ch <= 0x00000EC4) return 1;
              if (ch == 0x00000EC6) return 1;
              if (ch == 0x00000ECD) return 1;
              if (ch >= 0x00000ED0) {
               if (ch <= 0x00000ED9) return 1;
               if (ch >= 0x00000EDC) {
                if (ch <= 0x00000EDF) return 1;
  }}}}}}}}}}}}}}
  break;
 case 0x0000000F:
  if (ch == 0x00000F00) return 1;
  if (ch >= 0x00000F20) {
   if (ch <= 0x00000F29) return 1;
   if (ch >= 0x00000F40) {
    if (ch <= 0x00000F47) return 1;
    if (ch >= 0x00000F49) {
     if (ch <= 0x00000F6C) return 1;
     if (ch >= 0x00000F71) {
      if (ch <= 0x00000F81) return 1;
      if (ch >= 0x00000F88) {
       if (ch <= 0x00000F97) return 1;
       if (ch >= 0x00000F99) {
        if (ch <= 0x00000FBC) return 1;
  }}}}}}
  break;
 }
 break;
case 0x00000004:
 switch((ch & 0x003FFFFC) >> 8) {
 case 0x00000010:
  if (ch >= 0x00001000) {
   if (ch <= 0x00001036) return 1;
   if (ch == 0x00001038) return 1;
   if (ch >= 0x0000103B) {
    if (ch <= 0x00001049) return 1;
    if (ch >= 0x00001050) {
     if (ch <= 0x00001062) return 1;
     if (ch >= 0x00001065) {
      if (ch <= 0x00001068) return 1;
      if (ch >= 0x0000106E) {
       if (ch <= 0x00001086) return 1;
       if (ch == 0x0000108E) return 1;
       if (ch >= 0x00001090) {
        if (ch <= 0x00001099) return 1;
        if (ch >= 0x0000109C) {
         if (ch <= 0x0000109D) return 1;
         if (ch >= 0x000010A0) {
          if (ch <= 0x000010C5) return 1;
          if (ch == 0x000010C7) return 1;
          if (ch == 0x000010CD) return 1;
          if (ch >= 0x000010D0) {
           if (ch <= 0x000010FA) return 1;
           if (ch >= 0x000010FC) {
            if (ch <= 0x00001248) return 1;
  }}}}}}}}}}
  break;
 case 0x00000012:
  if (ch >= 0x0000124A) {
   if (ch <= 0x0000124D) return 1;
   if (ch >= 0x00001250) {
    if (ch <= 0x00001256) return 1;
    if (ch == 0x00001258) return 1;
    if (ch >= 0x0000125A) {
     if (ch <= 0x0000125D) return 1;
     if (ch >= 0x00001260) {
      if (ch <= 0x00001288) return 1;
      if (ch >= 0x0000128A) {
       if (ch <= 0x0000128D) return 1;
       if (ch >= 0x00001290) {
        if (ch <= 0x000012B0) return 1;
        if (ch >= 0x000012B2) {
         if (ch <= 0x000012B5) return 1;
         if (ch >= 0x000012B8) {
          if (ch <= 0x000012BE) return 1;
          if (ch == 0x000012C0) return 1;
          if (ch >= 0x000012C2) {
           if (ch <= 0x000012C5) return 1;
           if (ch >= 0x000012C8) {
            if (ch <= 0x000012D6) return 1;
            if (ch >= 0x000012D8) {
             if (ch <= 0x00001310) return 1;
  }}}}}}}}}}}
  break;
 case 0x00000013:
  if (ch >= 0x00001312) {
   if (ch <= 0x00001315) return 1;
   if (ch >= 0x00001318) {
    if (ch <= 0x0000135A) return 1;
    if (ch == 0x0000135F) return 1;
    if (ch >= 0x00001380) {
     if (ch <= 0x0000138F) return 1;
     if (ch >= 0x000013A0) {
      if (ch <= 0x000013F5) return 1;
      if (ch >= 0x000013F8) {
       if (ch <= 0x000013FD) return 1;
  }}}}}
  break;
 }
 break;
case 0x00000005:
 switch((ch & 0x003FFFFC) >> 8) {
 case 0x00000014:
  if (ch >= 0x00001401) {
   if (ch <= 0x0000166C) return 1;
  }
  break;
 case 0x00000016:
  if (ch >= 0x0000166F) {
   if (ch <= 0x0000167F) return 1;
   if (ch >= 0x00001681) {
    if (ch <= 0x0000169A) return 1;
    if (ch >= 0x000016A0) {
     if (ch <= 0x000016EA) return 1;
     if (ch >= 0x000016EE) {
      if (ch <= 0x000016F8) return 1;
  }}}}
  break;
 case 0x00000017:
  if (ch >= 0x00001700) {
   if (ch <= 0x0000170C) return 1;
   if (ch >= 0x0000170E) {
    if (ch <= 0x00001713) return 1;
    if (ch >= 0x00001720) {
     if (ch <= 0x00001733) return 1;
     if (ch >= 0x00001740) {
      if (ch <= 0x00001753) return 1;
      if (ch >= 0x00001760) {
       if (ch <= 0x0000176C) return 1;
       if (ch >= 0x0000176E) {
        if (ch <= 0x00001770) return 1;
        if (ch >= 0x00001772) {
         if (ch <= 0x00001773) return 1;
         if (ch >= 0x00001780) {
          if (ch <= 0x000017B3) return 1;
          if (ch >= 0x000017B6) {
           if (ch <= 0x000017C8) return 1;
           if (ch == 0x000017D7) return 1;
           if (ch == 0x000017DC) return 1;
           if (ch >= 0x000017E0) {
            if (ch <= 0x000017E9) return 1;
  }}}}}}}}}}
  break;
 }
 break;
case 0x00000006:
 switch((ch & 0x003FFFFC) >> 8) {
 case 0x00000018:
  if (ch >= 0x00001810) {
   if (ch <= 0x00001819) return 1;
   if (ch >= 0x00001820) {
    if (ch <= 0x00001877) return 1;
    if (ch >= 0x00001880) {
     if (ch <= 0x000018AA) return 1;
     if (ch >= 0x000018B0) {
      if (ch <= 0x000018F5) return 1;
  }}}}
  break;
 case 0x00000019:
  if (ch >= 0x00001900) {
   if (ch <= 0x0000191E) return 1;
   if (ch >= 0x00001920) {
    if (ch <= 0x0000192B) return 1;
    if (ch >= 0x00001930) {
     if (ch <= 0x00001938) return 1;
     if (ch >= 0x00001946) {
      if (ch <= 0x0000196D) return 1;
      if (ch >= 0x00001970) {
       if (ch <= 0x00001974) return 1;
       if (ch >= 0x00001980) {
        if (ch <= 0x000019AB) return 1;
        if (ch >= 0x000019B0) {
         if (ch <= 0x000019C9) return 1;
         if (ch >= 0x000019D0) {
          if (ch <= 0x000019D9) return 1;
  }}}}}}}}
  break;
 case 0x0000001A:
  if (ch >= 0x00001A00) {
   if (ch <= 0x00001A1B) return 1;
   if (ch >= 0x00001A20) {
    if (ch <= 0x00001A5E) return 1;
    if (ch >= 0x00001A61) {
     if (ch <= 0x00001A74) return 1;
     if (ch >= 0x00001A80) {
      if (ch <= 0x00001A89) return 1;
      if (ch >= 0x00001A90) {
       if (ch <= 0x00001A99) return 1;
       if (ch == 0x00001AA7) return 1;
  }}}}}
  break;
 case 0x0000001B:
  if (ch >= 0x00001B00) {
   if (ch <= 0x00001B33) return 1;
   if (ch >= 0x00001B35) {
    if (ch <= 0x00001B43) return 1;
    if (ch >= 0x00001B45) {
     if (ch <= 0x00001B4B) return 1;
     if (ch >= 0x00001B50) {
      if (ch <= 0x00001B59) return 1;
      if (ch >= 0x00001B80) {
       if (ch <= 0x00001BA9) return 1;
       if (ch >= 0x00001BAC) {
        if (ch <= 0x00001BE5) return 1;
        if (ch >= 0x00001BE7) {
         if (ch <= 0x00001BF1) return 1;
  }}}}}}}
  break;
 }
 break;
case 0x00000007:
 switch((ch & 0x003FFFFC) >> 8) {
 case 0x0000001C:
  if (ch >= 0x00001C00) {
   if (ch <= 0x00001C35) return 1;
   if (ch >= 0x00001C40) {
    if (ch <= 0x00001C49) return 1;
    if (ch >= 0x00001C4D) {
     if (ch <= 0x00001C7D) return 1;
     if (ch >= 0x00001C80) {
      if (ch <= 0x00001C88) return 1;
      if (ch >= 0x00001CE9) {
       if (ch <= 0x00001CEC) return 1;
       if (ch >= 0x00001CEE) {
        if (ch <= 0x00001CF3) return 1;
        if (ch >= 0x00001CF5) {
         if (ch <= 0x00001CF6) return 1;
  }}}}}}}
  break;
 case 0x0000001D:
  if (ch >= 0x00001D00) {
   if (ch <= 0x00001DBF) return 1;
   if (ch >= 0x00001DE7) {
    if (ch <= 0x00001DF4) return 1;
  }}
  break;
 case 0x0000001E:
  if (ch >= 0x00001E00) {
   if (ch <= 0x00001F15) return 1;
  }
  break;
 case 0x0000001F:
  if (ch >= 0x00001F18) {
   if (ch <= 0x00001F1D) return 1;
   if (ch >= 0x00001F20) {
    if (ch <= 0x00001F45) return 1;
    if (ch >= 0x00001F48) {
     if (ch <= 0x00001F4D) return 1;
     if (ch >= 0x00001F50) {
      if (ch <= 0x00001F57) return 1;
      if (ch == 0x00001F59) return 1;
      if (ch == 0x00001F5B) return 1;
      if (ch == 0x00001F5D) return 1;
      if (ch >= 0x00001F5F) {
       if (ch <= 0x00001F7D) return 1;
       if (ch >= 0x00001F80) {
        if (ch <= 0x00001FB4) return 1;
        if (ch >= 0x00001FB6) {
         if (ch <= 0x00001FBC) return 1;
         if (ch == 0x00001FBE) return 1;
         if (ch >= 0x00001FC2) {
          if (ch <= 0x00001FC4) return 1;
          if (ch >= 0x00001FC6) {
           if (ch <= 0x00001FCC) return 1;
           if (ch >= 0x00001FD0) {
            if (ch <= 0x00001FD3) return 1;
            if (ch >= 0x00001FD6) {
             if (ch <= 0x00001FDB) return 1;
             if (ch >= 0x00001FE0) {
              if (ch <= 0x00001FEC) return 1;
              if (ch >= 0x00001FF2) {
               if (ch <= 0x00001FF4) return 1;
               if (ch >= 0x00001FF6) {
                if (ch <= 0x00001FFC) return 1;
  }}}}}}}}}}}}}}
  break;
 }
 break;
case 0x00000008:
 switch((ch & 0x003FFFFC) >> 8) {
 case 0x00000020:
  if (ch == 0x00002071) return 1;
  if (ch == 0x0000207F) return 1;
  if (ch >= 0x00002090) {
   if (ch <= 0x0000209C) return 1;
  }
  break;
 case 0x00000021:
  if (ch == 0x00002102) return 1;
  if (ch == 0x00002107) return 1;
  if (ch >= 0x0000210A) {
   if (ch <= 0x00002113) return 1;
   if (ch == 0x00002115) return 1;
   if (ch >= 0x00002119) {
    if (ch <= 0x0000211D) return 1;
    if (ch == 0x00002124) return 1;
    if (ch == 0x00002126) return 1;
    if (ch == 0x00002128) return 1;
    if (ch >= 0x0000212A) {
     if (ch <= 0x0000212D) return 1;
     if (ch >= 0x0000212F) {
      if (ch <= 0x00002139) return 1;
      if (ch >= 0x0000213C) {
       if (ch <= 0x0000213F) return 1;
       if (ch >= 0x00002145) {
        if (ch <= 0x00002149) return 1;
        if (ch == 0x0000214E) return 1;
        if (ch >= 0x00002160) {
         if (ch <= 0x00002188) return 1;
  }}}}}}}
  break;
 }
 break;
case 0x00000009:
 switch((ch & 0x003FFFFC) >> 8) {
 case 0x00000024:
  if (ch >= 0x000024B6) {
   if (ch <= 0x000024E9) return 1;
  }
  break;
 }
 break;
case 0x0000000B:
 switch((ch & 0x003FFFFC) >> 8) {
 case 0x0000002C:
  if (ch >= 0x00002C00) {
   if (ch <= 0x00002C2E) return 1;
   if (ch >= 0x00002C30) {
    if (ch <= 0x00002C5E) return 1;
    if (ch >= 0x00002C60) {
     if (ch <= 0x00002CE4) return 1;
     if (ch >= 0x00002CEB) {
      if (ch <= 0x00002CEE) return 1;
      if (ch >= 0x00002CF2) {
       if (ch <= 0x00002CF3) return 1;
  }}}}}
  break;
 case 0x0000002D:
  if (ch >= 0x00002D00) {
   if (ch <= 0x00002D25) return 1;
   if (ch == 0x00002D27) return 1;
   if (ch == 0x00002D2D) return 1;
   if (ch >= 0x00002D30) {
    if (ch <= 0x00002D67) return 1;
    if (ch == 0x00002D6F) return 1;
    if (ch >= 0x00002D80) {
     if (ch <= 0x00002D96) return 1;
     if (ch >= 0x00002DA0) {
      if (ch <= 0x00002DA6) return 1;
      if (ch >= 0x00002DA8) {
       if (ch <= 0x00002DAE) return 1;
       if (ch >= 0x00002DB0) {
        if (ch <= 0x00002DB6) return 1;
        if (ch >= 0x00002DB8) {
         if (ch <= 0x00002DBE) return 1;
         if (ch >= 0x00002DC0) {
          if (ch <= 0x00002DC6) return 1;
          if (ch >= 0x00002DC8) {
           if (ch <= 0x00002DCE) return 1;
           if (ch >= 0x00002DD0) {
            if (ch <= 0x00002DD6) return 1;
            if (ch >= 0x00002DD8) {
             if (ch <= 0x00002DDE) return 1;
             if (ch >= 0x00002DE0) {
              if (ch <= 0x00002DFF) return 1;
  }}}}}}}}}}}}
  break;
 case 0x0000002E:
  if (ch == 0x00002E2F) return 1;
  
  break;
 }
 break;
case 0x0000000C:
 switch((ch & 0x003FFFFC) >> 8) {
 case 0x00000030:
  if (ch >= 0x00003005) {
   if (ch <= 0x00003007) return 1;
   if (ch >= 0x00003021) {
    if (ch <= 0x00003029) return 1;
    if (ch >= 0x00003031) {
     if (ch <= 0x00003035) return 1;
     if (ch >= 0x00003038) {
      if (ch <= 0x0000303C) return 1;
      if (ch >= 0x00003041) {
       if (ch <= 0x00003096) return 1;
       if (ch >= 0x0000309D) {
        if (ch <= 0x0000309F) return 1;
        if (ch >= 0x000030A1) {
         if (ch <= 0x000030FA) return 1;
         if (ch >= 0x000030FC) {
          if (ch <= 0x000030FF) return 1;
  }}}}}}}}
  break;
 case 0x00000031:
  if (ch >= 0x00003105) {
   if (ch <= 0x0000312E) return 1;
   if (ch >= 0x00003131) {
    if (ch <= 0x0000318E) return 1;
    if (ch >= 0x000031A0) {
     if (ch <= 0x000031BA) return 1;
     if (ch >= 0x000031F0) {
      if (ch <= 0x000031FF) return 1;
  }}}}
  break;
 }
 break;
case 0x0000000D:
 switch((ch & 0x003FFFFC) >> 8) {
 case 0x00000034:
  if (ch >= 0x00003400) {
   if (ch <= 0x00004DB5) return 1;
  }
  break;
 }
 break;
case 0x00000013:
 switch((ch & 0x003FFFFC) >> 8) {
 case 0x0000004E:
  if (ch >= 0x00004E00) {
   if (ch <= 0x00009FEA) return 1;
  }
  break;
 }
 break;
case 0x00000028:
 switch((ch & 0x003FFFFC) >> 8) {
 case 0x000000A0:
  if (ch >= 0x0000A000) {
   if (ch <= 0x0000A48C) return 1;
  }
  break;
 }
 break;
case 0x00000029:
 switch((ch & 0x003FFFFC) >> 8) {
 case 0x000000A4:
  if (ch >= 0x0000A4D0) {
   if (ch <= 0x0000A4FD) return 1;
  }
  break;
 case 0x000000A5:
  if (ch >= 0x0000A500) {
   if (ch <= 0x0000A60C) return 1;
  }
  break;
 case 0x000000A6:
  if (ch >= 0x0000A610) {
   if (ch <= 0x0000A62B) return 1;
   if (ch >= 0x0000A640) {
    if (ch <= 0x0000A66E) return 1;
    if (ch >= 0x0000A674) {
     if (ch <= 0x0000A67B) return 1;
     if (ch >= 0x0000A67F) {
      if (ch <= 0x0000A6EF) return 1;
  }}}}
  break;
 case 0x000000A7:
  if (ch >= 0x0000A717) {
   if (ch <= 0x0000A71F) return 1;
   if (ch >= 0x0000A722) {
    if (ch <= 0x0000A788) return 1;
    if (ch >= 0x0000A78B) {
     if (ch <= 0x0000A7AE) return 1;
     if (ch >= 0x0000A7B0) {
      if (ch <= 0x0000A7B7) return 1;
      if (ch >= 0x0000A7F7) {
       if (ch <= 0x0000A801) return 1;
  }}}}}
  break;
 }
 break;
case 0x0000002A:
 switch((ch & 0x003FFFFC) >> 8) {
 case 0x000000A8:
  if (ch >= 0x0000A803) {
   if (ch <= 0x0000A805) return 1;
   if (ch >= 0x0000A807) {
    if (ch <= 0x0000A80A) return 1;
    if (ch >= 0x0000A80C) {
     if (ch <= 0x0000A827) return 1;
     if (ch >= 0x0000A840) {
      if (ch <= 0x0000A873) return 1;
      if (ch >= 0x0000A880) {
       if (ch <= 0x0000A8C3) return 1;
       if (ch == 0x0000A8C5) return 1;
       if (ch >= 0x0000A8D0) {
        if (ch <= 0x0000A8D9) return 1;
        if (ch >= 0x0000A8F2) {
         if (ch <= 0x0000A8F7) return 1;
         if (ch == 0x0000A8FB) return 1;
         if (ch == 0x0000A8FD) return 1;
  }}}}}}}
  break;
 case 0x000000A9:
  if (ch >= 0x0000A900) {
   if (ch <= 0x0000A92A) return 1;
   if (ch >= 0x0000A930) {
    if (ch <= 0x0000A952) return 1;
    if (ch >= 0x0000A960) {
     if (ch <= 0x0000A97C) return 1;
     if (ch >= 0x0000A980) {
      if (ch <= 0x0000A9B2) return 1;
      if (ch >= 0x0000A9B4) {
       if (ch <= 0x0000A9BF) return 1;
       if (ch >= 0x0000A9CF) {
        if (ch <= 0x0000A9D9) return 1;
        if (ch >= 0x0000A9E0) {
         if (ch <= 0x0000A9E4) return 1;
         if (ch >= 0x0000A9E6) {
          if (ch <= 0x0000A9FE) return 1;
  }}}}}}}}
  break;
 case 0x000000AA:
  if (ch >= 0x0000AA00) {
   if (ch <= 0x0000AA36) return 1;
   if (ch >= 0x0000AA40) {
    if (ch <= 0x0000AA4D) return 1;
    if (ch >= 0x0000AA50) {
     if (ch <= 0x0000AA59) return 1;
     if (ch >= 0x0000AA60) {
      if (ch <= 0x0000AA76) return 1;
      if (ch == 0x0000AA7A) return 1;
      if (ch >= 0x0000AA7E) {
       if (ch <= 0x0000AABE) return 1;
       if (ch == 0x0000AAC0) return 1;
       if (ch == 0x0000AAC2) return 1;
       if (ch >= 0x0000AADB) {
        if (ch <= 0x0000AADD) return 1;
        if (ch >= 0x0000AAE0) {
         if (ch <= 0x0000AAEF) return 1;
         if (ch >= 0x0000AAF2) {
          if (ch <= 0x0000AAF5) return 1;
  }}}}}}}}
  break;
 case 0x000000AB:
  if (ch >= 0x0000AB01) {
   if (ch <= 0x0000AB06) return 1;
   if (ch >= 0x0000AB09) {
    if (ch <= 0x0000AB0E) return 1;
    if (ch >= 0x0000AB11) {
     if (ch <= 0x0000AB16) return 1;
     if (ch >= 0x0000AB20) {
      if (ch <= 0x0000AB26) return 1;
      if (ch >= 0x0000AB28) {
       if (ch <= 0x0000AB2E) return 1;
       if (ch >= 0x0000AB30) {
        if (ch <= 0x0000AB5A) return 1;
        if (ch >= 0x0000AB5C) {
         if (ch <= 0x0000AB65) return 1;
         if (ch >= 0x0000AB70) {
          if (ch <= 0x0000ABEA) return 1;
          if (ch >= 0x0000ABF0) {
           if (ch <= 0x0000ABF9) return 1;
  }}}}}}}}}
  break;
 }
 break;
case 0x0000002B:
 switch((ch & 0x003FFFFC) >> 8) {
 case 0x000000AC:
  if (ch >= 0x0000AC00) {
   if (ch <= 0x0000D7A3) return 1;
  }
  break;
 }
 break;
case 0x00000035:
 switch((ch & 0x003FFFFC) >> 8) {
 case 0x000000D7:
  if (ch >= 0x0000D7B0) {
   if (ch <= 0x0000D7C6) return 1;
   if (ch >= 0x0000D7CB) {
    if (ch <= 0x0000D7FB) return 1;
  }}
  break;
 }
 break;
case 0x0000003E:
 switch((ch & 0x003FFFFC) >> 8) {
 case 0x000000F9:
  if (ch >= 0x0000F900) {
   if (ch <= 0x0000FA6D) return 1;
  }
  break;
 case 0x000000FA:
  if (ch >= 0x0000FA70) {
   if (ch <= 0x0000FAD9) return 1;
  }
  break;
 case 0x000000FB:
  if (ch >= 0x0000FB00) {
   if (ch <= 0x0000FB06) return 1;
   if (ch >= 0x0000FB13) {
    if (ch <= 0x0000FB17) return 1;
    if (ch >= 0x0000FB1D) {
     if (ch <= 0x0000FB28) return 1;
     if (ch >= 0x0000FB2A) {
      if (ch <= 0x0000FB36) return 1;
      if (ch >= 0x0000FB38) {
       if (ch <= 0x0000FB3C) return 1;
       if (ch == 0x0000FB3E) return 1;
       if (ch >= 0x0000FB40) {
        if (ch <= 0x0000FB41) return 1;
        if (ch >= 0x0000FB43) {
         if (ch <= 0x0000FB44) return 1;
         if (ch >= 0x0000FB46) {
          if (ch <= 0x0000FBB1) return 1;
          if (ch >= 0x0000FBD3) {
           if (ch <= 0x0000FD3D) return 1;
  }}}}}}}}}
  break;
 }
 break;
case 0x0000003F:
 switch((ch & 0x003FFFFC) >> 8) {
 case 0x000000FD:
  if (ch >= 0x0000FD50) {
   if (ch <= 0x0000FD8F) return 1;
   if (ch >= 0x0000FD92) {
    if (ch <= 0x0000FDC7) return 1;
    if (ch >= 0x0000FDF0) {
     if (ch <= 0x0000FDFB) return 1;
  }}}
  break;
 case 0x000000FE:
  if (ch >= 0x0000FE70) {
   if (ch <= 0x0000FE74) return 1;
   if (ch >= 0x0000FE76) {
    if (ch <= 0x0000FEFC) return 1;
  }}
  break;
 case 0x000000FF:
  if (ch >= 0x0000FF10) {
   if (ch <= 0x0000FF19) return 1;
   if (ch >= 0x0000FF21) {
    if (ch <= 0x0000FF3A) return 1;
    if (ch >= 0x0000FF41) {
     if (ch <= 0x0000FF5A) return 1;
     if (ch >= 0x0000FF66) {
      if (ch <= 0x0000FFBE) return 1;
      if (ch >= 0x0000FFC2) {
       if (ch <= 0x0000FFC7) return 1;
       if (ch >= 0x0000FFCA) {
        if (ch <= 0x0000FFCF) return 1;
        if (ch >= 0x0000FFD2) {
         if (ch <= 0x0000FFD7) return 1;
         if (ch >= 0x0000FFDA) {
          if (ch <= 0x0000FFDC) return 1;
  }}}}}}}}
  break;
 }
 break;
case 0x00000040:
 switch((ch & 0x003FFFFC) >> 8) {
 case 0x00000100:
  if (ch >= 0x00010000) {
   if (ch <= 0x0001000B) return 1;
   if (ch >= 0x0001000D) {
    if (ch <= 0x00010026) return 1;
    if (ch >= 0x00010028) {
     if (ch <= 0x0001003A) return 1;
     if (ch >= 0x0001003C) {
      if (ch <= 0x0001003D) return 1;
      if (ch >= 0x0001003F) {
       if (ch <= 0x0001004D) return 1;
       if (ch >= 0x00010050) {
        if (ch <= 0x0001005D) return 1;
        if (ch >= 0x00010080) {
         if (ch <= 0x000100FA) return 1;
  }}}}}}}
  break;
 case 0x00000101:
  if (ch >= 0x00010140) {
   if (ch <= 0x00010174) return 1;
  }
  break;
 case 0x00000102:
  if (ch >= 0x00010280) {
   if (ch <= 0x0001029C) return 1;
   if (ch >= 0x000102A0) {
    if (ch <= 0x000102D0) return 1;
  }}
  break;
 case 0x00000103:
  if (ch >= 0x00010300) {
   if (ch <= 0x0001031F) return 1;
   if (ch >= 0x0001032D) {
    if (ch <= 0x0001034A) return 1;
    if (ch >= 0x00010350) {
     if (ch <= 0x0001037A) return 1;
     if (ch >= 0x00010380) {
      if (ch <= 0x0001039D) return 1;
      if (ch >= 0x000103A0) {
       if (ch <= 0x000103C3) return 1;
       if (ch >= 0x000103C8) {
        if (ch <= 0x000103CF) return 1;
        if (ch >= 0x000103D1) {
         if (ch <= 0x000103D5) return 1;
  }}}}}}}
  break;
 }
 break;
case 0x00000041:
 switch((ch & 0x003FFFFC) >> 8) {
 case 0x00000104:
  if (ch >= 0x00010400) {
   if (ch <= 0x0001049D) return 1;
   if (ch >= 0x000104A0) {
    if (ch <= 0x000104A9) return 1;
    if (ch >= 0x000104B0) {
     if (ch <= 0x000104D3) return 1;
     if (ch >= 0x000104D8) {
      if (ch <= 0x000104FB) return 1;
  }}}}
  break;
 case 0x00000105:
  if (ch >= 0x00010500) {
   if (ch <= 0x00010527) return 1;
   if (ch >= 0x00010530) {
    if (ch <= 0x00010563) return 1;
  }}
  break;
 case 0x00000106:
  if (ch >= 0x00010600) {
   if (ch <= 0x00010736) return 1;
  }
  break;
 case 0x00000107:
  if (ch >= 0x00010740) {
   if (ch <= 0x00010755) return 1;
   if (ch >= 0x00010760) {
    if (ch <= 0x00010767) return 1;
  }}
  break;
 }
 break;
case 0x00000042:
 switch((ch & 0x003FFFFC) >> 8) {
 case 0x00000108:
  if (ch >= 0x00010800) {
   if (ch <= 0x00010805) return 1;
   if (ch == 0x00010808) return 1;
   if (ch >= 0x0001080A) {
    if (ch <= 0x00010835) return 1;
    if (ch >= 0x00010837) {
     if (ch <= 0x00010838) return 1;
     if (ch == 0x0001083C) return 1;
     if (ch >= 0x0001083F) {
      if (ch <= 0x00010855) return 1;
      if (ch >= 0x00010860) {
       if (ch <= 0x00010876) return 1;
       if (ch >= 0x00010880) {
        if (ch <= 0x0001089E) return 1;
        if (ch >= 0x000108E0) {
         if (ch <= 0x000108F2) return 1;
         if (ch >= 0x000108F4) {
          if (ch <= 0x000108F5) return 1;
  }}}}}}}}
  break;
 case 0x00000109:
  if (ch >= 0x00010900) {
   if (ch <= 0x00010915) return 1;
   if (ch >= 0x00010920) {
    if (ch <= 0x00010939) return 1;
    if (ch >= 0x00010980) {
     if (ch <= 0x000109B7) return 1;
     if (ch >= 0x000109BE) {
      if (ch <= 0x000109BF) return 1;
  }}}}
  break;
 case 0x0000010A:
  if (ch >= 0x00010A00) {
   if (ch <= 0x00010A03) return 1;
   if (ch >= 0x00010A05) {
    if (ch <= 0x00010A06) return 1;
    if (ch >= 0x00010A0C) {
     if (ch <= 0x00010A13) return 1;
     if (ch >= 0x00010A15) {
      if (ch <= 0x00010A17) return 1;
      if (ch >= 0x00010A19) {
       if (ch <= 0x00010A33) return 1;
       if (ch >= 0x00010A60) {
        if (ch <= 0x00010A7C) return 1;
        if (ch >= 0x00010A80) {
         if (ch <= 0x00010A9C) return 1;
         if (ch >= 0x00010AC0) {
          if (ch <= 0x00010AC7) return 1;
          if (ch >= 0x00010AC9) {
           if (ch <= 0x00010AE4) return 1;
  }}}}}}}}}
  break;
 case 0x0000010B:
  if (ch >= 0x00010B00) {
   if (ch <= 0x00010B35) return 1;
   if (ch >= 0x00010B40) {
    if (ch <= 0x00010B55) return 1;
    if (ch >= 0x00010B60) {
     if (ch <= 0x00010B72) return 1;
     if (ch >= 0x00010B80) {
      if (ch <= 0x00010B91) return 1;
  }}}}
  break;
 }
 break;
case 0x00000043:
 switch((ch & 0x003FFFFC) >> 8) {
 case 0x0000010C:
  if (ch >= 0x00010C00) {
   if (ch <= 0x00010C48) return 1;
   if (ch >= 0x00010C80) {
    if (ch <= 0x00010CB2) return 1;
    if (ch >= 0x00010CC0) {
     if (ch <= 0x00010CF2) return 1;
  }}}
  break;
 }
 break;
case 0x00000044:
 switch((ch & 0x003FFFFC) >> 8) {
 case 0x00000110:
  if (ch >= 0x00011000) {
   if (ch <= 0x00011045) return 1;
   if (ch >= 0x00011066) {
    if (ch <= 0x0001106F) return 1;
    if (ch >= 0x00011082) {
     if (ch <= 0x000110B8) return 1;
     if (ch >= 0x000110D0) {
      if (ch <= 0x000110E8) return 1;
      if (ch >= 0x000110F0) {
       if (ch <= 0x000110F9) return 1;
  }}}}}
  break;
 case 0x00000111:
  if (ch >= 0x00011100) {
   if (ch <= 0x00011132) return 1;
   if (ch >= 0x00011136) {
    if (ch <= 0x0001113F) return 1;
    if (ch >= 0x00011150) {
     if (ch <= 0x00011172) return 1;
     if (ch == 0x00011176) return 1;
     if (ch >= 0x00011180) {
      if (ch <= 0x000111BF) return 1;
      if (ch >= 0x000111C1) {
       if (ch <= 0x000111C4) return 1;
       if (ch >= 0x000111D0) {
        if (ch <= 0x000111DA) return 1;
        if (ch == 0x000111DC) return 1;
  }}}}}}
  break;
 case 0x00000112:
  if (ch >= 0x00011200) {
   if (ch <= 0x00011211) return 1;
   if (ch >= 0x00011213) {
    if (ch <= 0x00011234) return 1;
    if (ch == 0x00011237) return 1;
    if (ch == 0x0001123E) return 1;
    if (ch >= 0x00011280) {
     if (ch <= 0x00011286) return 1;
     if (ch == 0x00011288) return 1;
     if (ch >= 0x0001128A) {
      if (ch <= 0x0001128D) return 1;
      if (ch >= 0x0001128F) {
       if (ch <= 0x0001129D) return 1;
       if (ch >= 0x0001129F) {
        if (ch <= 0x000112A8) return 1;
        if (ch >= 0x000112B0) {
         if (ch <= 0x000112E8) return 1;
         if (ch >= 0x000112F0) {
          if (ch <= 0x000112F9) return 1;
  }}}}}}}}
  break;
 case 0x00000113:
  if (ch >= 0x00011300) {
   if (ch <= 0x00011303) return 1;
   if (ch >= 0x00011305) {
    if (ch <= 0x0001130C) return 1;
    if (ch >= 0x0001130F) {
     if (ch <= 0x00011310) return 1;
     if (ch >= 0x00011313) {
      if (ch <= 0x00011328) return 1;
      if (ch >= 0x0001132A) {
       if (ch <= 0x00011330) return 1;
       if (ch >= 0x00011332) {
        if (ch <= 0x00011333) return 1;
        if (ch >= 0x00011335) {
         if (ch <= 0x00011339) return 1;
         if (ch >= 0x0001133D) {
          if (ch <= 0x00011344) return 1;
          if (ch >= 0x00011347) {
           if (ch <= 0x00011348) return 1;
           if (ch >= 0x0001134B) {
            if (ch <= 0x0001134C) return 1;
            if (ch == 0x00011350) return 1;
            if (ch == 0x00011357) return 1;
            if (ch >= 0x0001135D) {
             if (ch <= 0x00011363) return 1;
  }}}}}}}}}}}
  break;
 }
 break;
case 0x00000045:
 switch((ch & 0x003FFFFC) >> 8) {
 case 0x00000114:
  if (ch >= 0x00011400) {
   if (ch <= 0x00011441) return 1;
   if (ch >= 0x00011443) {
    if (ch <= 0x00011445) return 1;
    if (ch >= 0x00011447) {
     if (ch <= 0x0001144A) return 1;
     if (ch >= 0x00011450) {
      if (ch <= 0x00011459) return 1;
      if (ch >= 0x00011480) {
       if (ch <= 0x000114C1) return 1;
       if (ch >= 0x000114C4) {
        if (ch <= 0x000114C5) return 1;
        if (ch == 0x000114C7) return 1;
        if (ch >= 0x000114D0) {
         if (ch <= 0x000114D9) return 1;
  }}}}}}}
  break;
 case 0x00000115:
  if (ch >= 0x00011580) {
   if (ch <= 0x000115B5) return 1;
   if (ch >= 0x000115B8) {
    if (ch <= 0x000115BE) return 1;
    if (ch >= 0x000115D8) {
     if (ch <= 0x000115DD) return 1;
  }}}
  break;
 case 0x00000116:
  if (ch >= 0x00011600) {
   if (ch <= 0x0001163E) return 1;
   if (ch == 0x00011640) return 1;
   if (ch == 0x00011644) return 1;
   if (ch >= 0x00011650) {
    if (ch <= 0x00011659) return 1;
    if (ch >= 0x00011680) {
     if (ch <= 0x000116B5) return 1;
     if (ch >= 0x000116C0) {
      if (ch <= 0x000116C9) return 1;
  }}}}
  break;
 case 0x00000117:
  if (ch >= 0x00011700) {
   if (ch <= 0x00011719) return 1;
   if (ch >= 0x0001171D) {
    if (ch <= 0x0001172A) return 1;
    if (ch >= 0x00011730) {
     if (ch <= 0x00011739) return 1;
  }}}
  break;
 }
 break;
case 0x00000046:
 switch((ch & 0x003FFFFC) >> 8) {
 case 0x00000118:
  if (ch >= 0x000118A0) {
   if (ch <= 0x000118E9) return 1;
   if (ch == 0x000118FF) return 1;
  }
  break;
 case 0x0000011A:
  if (ch >= 0x00011A00) {
   if (ch <= 0x00011A32) return 1;
   if (ch >= 0x00011A35) {
    if (ch <= 0x00011A3E) return 1;
    if (ch >= 0x00011A50) {
     if (ch <= 0x00011A83) return 1;
     if (ch >= 0x00011A86) {
      if (ch <= 0x00011A97) return 1;
      if (ch >= 0x00011AC0) {
       if (ch <= 0x00011AF8) return 1;
  }}}}}
  break;
 }
 break;
case 0x00000047:
 switch((ch & 0x003FFFFC) >> 8) {
 case 0x0000011C:
  if (ch >= 0x00011C00) {
   if (ch <= 0x00011C08) return 1;
   if (ch >= 0x00011C0A) {
    if (ch <= 0x00011C36) return 1;
    if (ch >= 0x00011C38) {
     if (ch <= 0x00011C3E) return 1;
     if (ch == 0x00011C40) return 1;
     if (ch >= 0x00011C50) {
      if (ch <= 0x00011C59) return 1;
      if (ch >= 0x00011C72) {
       if (ch <= 0x00011C8F) return 1;
       if (ch >= 0x00011C92) {
        if (ch <= 0x00011CA7) return 1;
        if (ch >= 0x00011CA9) {
         if (ch <= 0x00011CB6) return 1;
  }}}}}}}
  break;
 case 0x0000011D:
  if (ch >= 0x00011D00) {
   if (ch <= 0x00011D06) return 1;
   if (ch >= 0x00011D08) {
    if (ch <= 0x00011D09) return 1;
    if (ch >= 0x00011D0B) {
     if (ch <= 0x00011D36) return 1;
     if (ch == 0x00011D3A) return 1;
     if (ch >= 0x00011D3C) {
      if (ch <= 0x00011D3D) return 1;
      if (ch >= 0x00011D3F) {
       if (ch <= 0x00011D41) return 1;
       if (ch == 0x00011D43) return 1;
       if (ch >= 0x00011D46) {
        if (ch <= 0x00011D47) return 1;
        if (ch >= 0x00011D50) {
         if (ch <= 0x00011D59) return 1;
  }}}}}}}
  break;
 }
 break;
case 0x00000048:
 switch((ch & 0x003FFFFC) >> 8) {
 case 0x00000120:
  if (ch >= 0x00012000) {
   if (ch <= 0x00012399) return 1;
  }
  break;
 }
 break;
case 0x00000049:
 switch((ch & 0x003FFFFC) >> 8) {
 case 0x00000124:
  if (ch >= 0x00012400) {
   if (ch <= 0x0001246E) return 1;
   if (ch >= 0x00012480) {
    if (ch <= 0x00012543) return 1;
  }}
  break;
 }
 break;
case 0x0000004C:
 switch((ch & 0x003FFFFC) >> 8) {
 case 0x00000130:
  if (ch >= 0x00013000) {
   if (ch <= 0x0001342E) return 1;
  }
  break;
 }
 break;
case 0x00000051:
 switch((ch & 0x003FFFFC) >> 8) {
 case 0x00000144:
  if (ch >= 0x00014400) {
   if (ch <= 0x00014646) return 1;
  }
  break;
 }
 break;
case 0x0000005A:
 switch((ch & 0x003FFFFC) >> 8) {
 case 0x00000168:
  if (ch >= 0x00016800) {
   if (ch <= 0x00016A38) return 1;
  }
  break;
 case 0x0000016A:
  if (ch >= 0x00016A40) {
   if (ch <= 0x00016A5E) return 1;
   if (ch >= 0x00016A60) {
    if (ch <= 0x00016A69) return 1;
    if (ch >= 0x00016AD0) {
     if (ch <= 0x00016AED) return 1;
  }}}
  break;
 case 0x0000016B:
  if (ch >= 0x00016B00) {
   if (ch <= 0x00016B36) return 1;
   if (ch >= 0x00016B40) {
    if (ch <= 0x00016B43) return 1;
    if (ch >= 0x00016B50) {
     if (ch <= 0x00016B59) return 1;
     if (ch >= 0x00016B63) {
      if (ch <= 0x00016B77) return 1;
      if (ch >= 0x00016B7D) {
       if (ch <= 0x00016B8F) return 1;
  }}}}}
  break;
 }
 break;
case 0x0000005B:
 switch((ch & 0x003FFFFC) >> 8) {
 case 0x0000016F:
  if (ch >= 0x00016F00) {
   if (ch <= 0x00016F44) return 1;
   if (ch >= 0x00016F50) {
    if (ch <= 0x00016F7E) return 1;
    if (ch >= 0x00016F93) {
     if (ch <= 0x00016F9F) return 1;
     if (ch >= 0x00016FE0) {
      if (ch <= 0x00016FE1) return 1;
  }}}}
  break;
 }
 break;
case 0x0000005C:
 switch((ch & 0x003FFFFC) >> 8) {
 case 0x00000170:
  if (ch >= 0x00017000) {
   if (ch <= 0x000187EC) return 1;
  }
  break;
 }
 break;
case 0x00000062:
 switch((ch & 0x003FFFFC) >> 8) {
 case 0x00000188:
  if (ch >= 0x00018800) {
   if (ch <= 0x00018AF2) return 1;
  }
  break;
 }
 break;
case 0x0000006C:
 switch((ch & 0x003FFFFC) >> 8) {
 case 0x000001B0:
  if (ch >= 0x0001B000) {
   if (ch <= 0x0001B11E) return 1;
  }
  break;
 case 0x000001B1:
  if (ch >= 0x0001B170) {
   if (ch <= 0x0001B2FB) return 1;
  }
  break;
 }
 break;
case 0x0000006F:
 switch((ch & 0x003FFFFC) >> 8) {
 case 0x000001BC:
  if (ch >= 0x0001BC00) {
   if (ch <= 0x0001BC6A) return 1;
   if (ch >= 0x0001BC70) {
    if (ch <= 0x0001BC7C) return 1;
    if (ch >= 0x0001BC80) {
     if (ch <= 0x0001BC88) return 1;
     if (ch >= 0x0001BC90) {
      if (ch <= 0x0001BC99) return 1;
      if (ch == 0x0001BC9E) return 1;
  }}}}
  break;
 }
 break;
case 0x00000075:
 switch((ch & 0x003FFFFC) >> 8) {
 case 0x000001D4:
  if (ch >= 0x0001D400) {
   if (ch <= 0x0001D454) return 1;
   if (ch >= 0x0001D456) {
    if (ch <= 0x0001D49C) return 1;
    if (ch >= 0x0001D49E) {
     if (ch <= 0x0001D49F) return 1;
     if (ch == 0x0001D4A2) return 1;
     if (ch >= 0x0001D4A5) {
      if (ch <= 0x0001D4A6) return 1;
      if (ch >= 0x0001D4A9) {
       if (ch <= 0x0001D4AC) return 1;
       if (ch >= 0x0001D4AE) {
        if (ch <= 0x0001D4B9) return 1;
        if (ch == 0x0001D4BB) return 1;
        if (ch >= 0x0001D4BD) {
         if (ch <= 0x0001D4C3) return 1;
         if (ch >= 0x0001D4C5) {
          if (ch <= 0x0001D505) return 1;
  }}}}}}}}
  break;
 case 0x000001D5:
  if (ch >= 0x0001D507) {
   if (ch <= 0x0001D50A) return 1;
   if (ch >= 0x0001D50D) {
    if (ch <= 0x0001D514) return 1;
    if (ch >= 0x0001D516) {
     if (ch <= 0x0001D51C) return 1;
     if (ch >= 0x0001D51E) {
      if (ch <= 0x0001D539) return 1;
      if (ch >= 0x0001D53B) {
       if (ch <= 0x0001D53E) return 1;
       if (ch >= 0x0001D540) {
        if (ch <= 0x0001D544) return 1;
        if (ch == 0x0001D546) return 1;
        if (ch >= 0x0001D54A) {
         if (ch <= 0x0001D550) return 1;
         if (ch >= 0x0001D552) {
          if (ch <= 0x0001D6A5) return 1;
  }}}}}}}}
  break;
 case 0x000001D6:
  if (ch >= 0x0001D6A8) {
   if (ch <= 0x0001D6C0) return 1;
   if (ch >= 0x0001D6C2) {
    if (ch <= 0x0001D6DA) return 1;
    if (ch >= 0x0001D6DC) {
     if (ch <= 0x0001D6FA) return 1;
     if (ch >= 0x0001D6FC) {
      if (ch <= 0x0001D714) return 1;
  }}}}
  break;
 case 0x000001D7:
  if (ch >= 0x0001D716) {
   if (ch <= 0x0001D734) return 1;
   if (ch >= 0x0001D736) {
    if (ch <= 0x0001D74E) return 1;
    if (ch >= 0x0001D750) {
     if (ch <= 0x0001D76E) return 1;
     if (ch >= 0x0001D770) {
      if (ch <= 0x0001D788) return 1;
      if (ch >= 0x0001D78A) {
       if (ch <= 0x0001D7A8) return 1;
       if (ch >= 0x0001D7AA) {
        if (ch <= 0x0001D7C2) return 1;
        if (ch >= 0x0001D7C4) {
         if (ch <= 0x0001D7CB) return 1;
         if (ch >= 0x0001D7CE) {
          if (ch <= 0x0001D7FF) return 1;
  }}}}}}}}
  break;
 }
 break;
case 0x00000078:
 switch((ch & 0x003FFFFC) >> 8) {
 case 0x000001E0:
  if (ch >= 0x0001E000) {
   if (ch <= 0x0001E006) return 1;
   if (ch >= 0x0001E008) {
    if (ch <= 0x0001E018) return 1;
    if (ch >= 0x0001E01B) {
     if (ch <= 0x0001E021) return 1;
     if (ch >= 0x0001E023) {
      if (ch <= 0x0001E024) return 1;
      if (ch >= 0x0001E026) {
       if (ch <= 0x0001E02A) return 1;
  }}}}}
  break;
 }
 break;
case 0x0000007A:
 switch((ch & 0x003FFFFC) >> 8) {
 case 0x000001E8:
  if (ch >= 0x0001E800) {
   if (ch <= 0x0001E8C4) return 1;
  }
  break;
 case 0x000001E9:
  if (ch >= 0x0001E900) {
   if (ch <= 0x0001E943) return 1;
   if (ch == 0x0001E947) return 1;
   if (ch >= 0x0001E950) {
    if (ch <= 0x0001E959) return 1;
  }}
  break;
 }
 break;
case 0x0000007B:
 switch((ch & 0x003FFFFC) >> 8) {
 case 0x000001EE:
  if (ch >= 0x0001EE00) {
   if (ch <= 0x0001EE03) return 1;
   if (ch >= 0x0001EE05) {
    if (ch <= 0x0001EE1F) return 1;
    if (ch >= 0x0001EE21) {
     if (ch <= 0x0001EE22) return 1;
     if (ch == 0x0001EE24) return 1;
     if (ch == 0x0001EE27) return 1;
     if (ch >= 0x0001EE29) {
      if (ch <= 0x0001EE32) return 1;
      if (ch >= 0x0001EE34) {
       if (ch <= 0x0001EE37) return 1;
       if (ch == 0x0001EE39) return 1;
       if (ch == 0x0001EE3B) return 1;
       if (ch == 0x0001EE42) return 1;
       if (ch == 0x0001EE47) return 1;
       if (ch == 0x0001EE49) return 1;
       if (ch == 0x0001EE4B) return 1;
       if (ch >= 0x0001EE4D) {
        if (ch <= 0x0001EE4F) return 1;
        if (ch >= 0x0001EE51) {
         if (ch <= 0x0001EE52) return 1;
         if (ch == 0x0001EE54) return 1;
         if (ch == 0x0001EE57) return 1;
         if (ch == 0x0001EE59) return 1;
         if (ch == 0x0001EE5B) return 1;
         if (ch == 0x0001EE5D) return 1;
         if (ch == 0x0001EE5F) return 1;
         if (ch >= 0x0001EE61) {
          if (ch <= 0x0001EE62) return 1;
          if (ch == 0x0001EE64) return 1;
          if (ch >= 0x0001EE67) {
           if (ch <= 0x0001EE6A) return 1;
           if (ch >= 0x0001EE6C) {
            if (ch <= 0x0001EE72) return 1;
            if (ch >= 0x0001EE74) {
             if (ch <= 0x0001EE77) return 1;
             if (ch >= 0x0001EE79) {
              if (ch <= 0x0001EE7C) return 1;
              if (ch == 0x0001EE7E) return 1;
              if (ch >= 0x0001EE80) {
               if (ch <= 0x0001EE89) return 1;
               if (ch >= 0x0001EE8B) {
                if (ch <= 0x0001EE9B) return 1;
                if (ch >= 0x0001EEA1) {
                 if (ch <= 0x0001EEA3) return 1;
                 if (ch >= 0x0001EEA5) {
                  if (ch <= 0x0001EEA9) return 1;
                  if (ch >= 0x0001EEAB) {
                   if (ch <= 0x0001EEBB) return 1;
  }}}}}}}}}}}}}}}}}
  break;
 }
 break;
case 0x0000007C:
 switch((ch & 0x003FFFFC) >> 8) {
 case 0x000001F1:
  if (ch >= 0x0001F130) {
   if (ch <= 0x0001F149) return 1;
   if (ch >= 0x0001F150) {
    if (ch <= 0x0001F169) return 1;
    if (ch >= 0x0001F170) {
     if (ch <= 0x0001F189) return 1;
  }}}
  break;
 }
 break;
case 0x00000080:
 switch((ch & 0x003FFFFC) >> 8) {
 case 0x00000200:
  if (ch >= 0x00020000) {
   if (ch <= 0x0002A6D6) return 1;
  }
  break;
 }
 break;
case 0x000000A9:
 switch((ch & 0x003FFFFC) >> 8) {
 case 0x000002A7:
  if (ch >= 0x0002A700) {
   if (ch <= 0x0002B734) return 1;
  }
  break;
 }
 break;
case 0x000000AD:
 switch((ch & 0x003FFFFC) >> 8) {
 case 0x000002B7:
  if (ch >= 0x0002B740) {
   if (ch <= 0x0002B81D) return 1;
  }
  break;
 }
 break;
case 0x000000AE:
 switch((ch & 0x003FFFFC) >> 8) {
 case 0x000002B8:
  if (ch >= 0x0002B820) {
   if (ch <= 0x0002CEA1) return 1;
  }
  break;
 }
 break;
case 0x000000B3:
 switch((ch & 0x003FFFFC) >> 8) {
 case 0x000002CE:
  if (ch >= 0x0002CEB0) {
   if (ch <= 0x0002EBE0) return 1;
  }
  break;
 }
 break;
case 0x000000BE:
 switch((ch & 0x003FFFFC) >> 8) {
 case 0x000002F8:
  if (ch >= 0x0002F800) {
   if (ch <= 0x0002FA1D) return 1;
  }
  break;
 }
 break;
}

/* END::UTF8SWITCH */
#endif

	return 0;
}

static inline zend_bool isualnum(unsigned ch)
{
	/* digits */
	if (ch >= 0x30 && ch <= 0x39) {
		return 1;
	}
	return isualpha(ch);
}

static inline size_t wctoutf16(unsigned short u16[2], unsigned wc)
{
	if (wc > 0x10ffff || (wc >= 0xd800 && wc <= 0xdfff)) {
		return 0;
	}

	if (wc <= 0xffff) {
		u16[0] = (unsigned short) wc;
		return 1;
	}

	wc -= 0x10000;
	u16[0] = (unsigned short) ((wc >> 10) + 0xd800);
	u16[1] = (unsigned short) ((wc & 0x3ff) + 0xdc00);
	return 2;
}

static inline size_t utf16towc(unsigned *wc, unsigned short *u16_str, size_t u16_len)
{
	if (u16_len < 1) {
		return 0;
	}
	if (u16_str[0] - 0xd800 >= 0x800) {
		*wc = u16_str[0];
		return 1;
	}
	if (u16_len < 2 || (u16_str[0] & 0xfffffc00) != 0xd800 || (u16_str[1] & 0xfffffc00) != 0xdc00) {
		return 0;
	}
	*wc = (u16_str[0] << 10) + u16_str[1] - 0x35fdc00;
	return 2;
}

#endif	/* PHP_HTTP_UTF8_H */

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
