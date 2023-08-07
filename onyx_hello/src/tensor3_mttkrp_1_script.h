#ifndef BITSTREAM_H
#define BITSTREAM_H

const int app_size = 402;

uint32_t app_addrs_script[] = {
  0x050E0603,
  0x020E0603,
  0x040E0503,
  0x020E0503,
  0x040E0502,
  0x020E0502,
  0x00040501,
  0x010E0603,
  0x010E0503,
  0x020E0802,
  0x010E0802,
  0x020E0803,
  0x010E0803,
  0x00030804,
  0x000E0802,
  0x000E0803,
  0x030E0001,
  0x020E0001,
  0x030E0101,
  0x020E0101,
  0x030E0201,
  0x020E0201,
  0x00050301,
  0x000E0001,
  0x000E0101,
  0x020B0301,
  0x010B0301,
  0x020E0401,
  0x010E0401,
  0x00030501,
  0x000B0301,
  0x000E0401,
  0x030B0303,
  0x020B0303,
  0x030E0203,
  0x020E0203,
  0x020E0103,
  0x010E0103,
  0x020E0102,
  0x010E0102,
  0x000B0303,
  0x000E0203,
  0x000E0103,
  0x000E0102,
  0x030E0202,
  0x020E0202,
  0x030E0204,
  0x020E0204,
  0x00050304,
  0x000E0201,
  0x000E0202,
  0x000E0204,
  0x020B0304,
  0x010B0304,
  0x020E0404,
  0x010E0404,
  0x00030504,
  0x000B0304,
  0x000E0404,
  0x030B0304,
  0x030E0404,
  0x00050504,
  0x040E0403,
  0x020E0403,
  0x00030304,
  0x010E0403,
  0x020B0302,
  0x010B0302,
  0x000B0302,
  0x030E0401,
  0x030E0501,
  0x020E0501,
  0x030E0601,
  0x020E0601,
  0x00050701,
  0x000E0501,
  0x020B0701,
  0x010B0701,
  0x050E0801,
  0x020E0801,
  0x00030802,
  0x000B0701,
  0x010E0801,
  0x020E0804,
  0x010E0804,
  0x020E0904,
  0x010E0904,
  0x00040A04,
  0x000E0804,
  0x000E0904,
  0x040B0701,
  0x040E0801,
  0x00050802,
  0x000E0801,
  0x040E0501,
  0x040E0601,
  0x00030701,
  0x010E0501,
  0x010E0601,
  0x050E0602,
  0x020E0602,
  0x050B0702,
  0x020B0702,
  0x050E0802,
  0x040E0902,
  0x020E0902,
  0x050E0903,
  0x020E0903,
  0x050E0A03,
  0x020E0A03,
  0x00050B03,
  0x010E0602,
  0x010B0702,
  0x010E0902,
  0x010E0903,
  0x050B0B03,
  0x020B0B03,
  0x030E0C03,
  0x020E0C03,
  0x00030C02,
  0x010B0B03,
  0x000E0C03,
  0x040B0B03,
  0x030B0B03,
  0x030B0B02,
  0x020B0B02,
  0x00050C02,
  0x000B0B03,
  0x000B0B02,
  0x030E0A04,
  0x020E0A04,
  0x050B0B04,
  0x020B0B04,
  0x00030B03,
  0x000E0A04,
  0x010B0B04,
  0x030B0702,
  0x000B0702,
  0x000E0602,
  0x000E0601,
  0x030E0801,
  0x00060702,
  0x020E0901,
  0x010E0901,
  0x020E0A01,
  0x010E0A01,
  0x00050B01,
  0x000E0901,
  0x020B0B01,
  0x010B0B01,
  0x050E0C01,
  0x020E0C01,
  0x00040C02,
  0x000B0B01,
  0x010E0C01,
  0x030E0C02,
  0x020E0C02,
  0x00030C03,
  0x040B0B01,
  0x040E0C01,
  0x00060C02,
  0x000E0C01,
  0x020E0A02,
  0x010E0A02,
  0x010B0B02,
  0x00030B01,
  0x000E0902,
  0x000E0A02,
  0x030E0A01,
  0x050E0A02,
  0x050E0902,
  0x030E0803,
  0x00050703,
  0x000E0A01,
  0x030B0703,
  0x020B0703,
  0x050E0803,
  0x00040802,
  0x000B0703,
  0x010B0703,
  0x00060802,
  0x050E0504,
  0x020E0504,
  0x050E0604,
  0x020E0604,
  0x030B0704,
  0x020B0704,
  0x00030703,
  0x010E0504,
  0x010E0604,
  0x050B0B01,
  0x030E0A02,
  0x030E0902,
  0x040E0802,
  0x040E0803,
  0x040E0804,
  0x00050704,
  0x050B0704,
  0x040B0704,
  0x040E0604,
  0x00040504,
  0x010B0704,
  0x030E0604,
  0x00060504,
  0x000B0704,
  0x000E0604,
  0x040E0602,
  0x040B0703,
  0x00030704,
  0x00040A03,
  0x020E0E01,
  0x010E0E01,
  0x030E0E02,
  0x010E0E02,
  0x030E0D02,
  0x010E0D02,
  0x010E0C02,
  0x00050B02,
  0x000E0E01,
  0x000E0E02,
  0x000E0D02,
  0x000E0C02,
  0x050B0B02,
  0x050E0C02,
  0x00030D02,
  0x030E0A03,
  0x00030B02,
  0x000E0A03,
  0x030E1001,
  0x020E1001,
  0x040B0F01,
  0x020B0F01,
  0x00050F02,
  0x000E1001,
  0x000B0F01,
  0x010B0F01,
  0x030B0F02,
  0x020B0F02,
  0x020E0E02,
  0x00040D02,
  0x000B0F02,
  0x040E0C02,
  0x040E0D02,
  0x020E0D02,
  0x040E0E02,
  0x00030F02,
  0x040E1201,
  0x020E1201,
  0x050E1101,
  0x040E1101,
  0x020E1101,
  0x050E1001,
  0x040E1001,
  0x00050F01,
  0x010E1201,
  0x010E1101,
  0x050B0F01,
  0x050E0E01,
  0x050E0D01,
  0x020E0D01,
  0x00040C01,
  0x040E0E01,
  0x00030F01,
  0x030B0301,
  0x030B0302,
  0x00030402,
  0x040E0D01,
  0x00030C01,
  0x010E0D01,
  0x040B0301,
  0x040B0302,
  0x00060303,
  0x030E0402,
  0x020E0402,
  0x00040403,
  0x050E0402,
  0x050E0502,
  0x00040602,
  0x010E0402,
  0x010E0502,
  0x030E0504,
  0x00030603,
  0x000E0504,
  0x010B0303,
  0x00060302,
  0x00030A01,
  0x050E0A01,
  0x040E0A01,
  0x050E0901,
  0x040E0901,
  0x00030801,
  0x030E0802,
  0x00030A03,
  0x030E0804,
  0x030E0904,
  0x00030A04,
  0x00000402,
  0x03000402,
  0x00000403,
  0x03000403,
  0x00000504,
  0x03000504,
  0x00000603,
  0x03000603,
  0x00000501,
  0x03000501,
  0x00000802,
  0x03000802,
  0x00000804,
  0x03000804,
  0x00000A04,
  0x03000A04,
  0x00000C02,
  0x03000C02,
  0x00000C03,
  0x03000C03,
  0x00000A03,
  0x03000A03,
  0x02000D02,
  0x01000D02,
  0x00000D02,
  0x03000D02,
  0x02000C01,
  0x01000C01,
  0x00000C01,
  0x03000C01,
  0x00000A01,
  0x03000A01,
  0x00000801,
  0x03000801,
  0x00000602,
  0x03000602,
  0x00000000,
  0x17000301,
  0x0C000301,
  0x01000301,
  0x00000301,
  0x2E000301,
  0x17000303,
  0x0C000303,
  0x01000303,
  0x00000303,
  0x2E000303,
  0x00000100,
  0x00000200,
  0x17000304,
  0x0C000304,
  0x00000304,
  0x2E000304,
  0x17000302,
  0x0C000302,
  0x00000302,
  0x2E000302,
  0x00000300,
  0x00000400,
  0x17000701,
  0x0C000701,
  0x00000701,
  0x2E000701,
  0x00000600,
  0x17000B03,
  0x0C000B03,
  0x00000B03,
  0x2E000B03,
  0x17000702,
  0x0C000702,
  0x00000702,
  0x2E000702,
  0x00000500,
  0x00000800,
  0x17000B01,
  0x0C000B01,
  0x00000B01,
  0x2E000B01,
  0x00000A00,
  0x17000703,
  0x0C000703,
  0x00000703,
  0x2E000703,
  0x00000C00,
  0x17000704,
  0x0C000704,
  0x00000704,
  0x2E000704,
  0x00000E00,
  0x17000B02,
  0x0C000B02,
  0x01000B02,
  0x00000B02,
  0x2E000B02,
  0x00001000,
  0x17000F02,
  0x0C000F02,
  0x01000F02,
  0x00000F02,
  0x2E000F02,
  0x00001200,
  0x17000F01,
  0x0C000F01,
  0x01000F01,
  0x00000F01,
  0x2E000F01,
};

uint32_t app_datas_script[] = {
  0x00380010,
  0x00009000,
  0x00180000,
  0x00000200,
  0x00280000,
  0x00001000,
  0x0000001B,
  0x0C030000,
  0x00000180,
  0x38125410,
  0x50C30C00,
  0x18402400,
  0x60181800,
  0x00000001,
  0x06000186,
  0x000000D8,
  0x00000020,
  0x00000001,
  0x00000060,
  0x01400001,
  0x00018060,
  0x00000004,
  0x0000000F,
  0x00006000,
  0x00003000,
  0x01560404,
  0x30001800,
  0x00020001,
  0x10000000,
  0x00000007,
  0x0018001E,
  0x00006003,
  0x00708000,
  0x0140000C,
  0x00518000,
  0x0000000C,
  0x00C00000,
  0x20000000,
  0x01400000,
  0x20000000,
  0x00CC0018,
  0x00780000,
  0x00000030,
  0x00000018,
  0x00018000,
  0x00000004,
  0x02000000,
  0x00000010,
  0x00000017,
  0x00180000,
  0x000C0000,
  0x03000000,
  0x00D20010,
  0x30000000,
  0x00020018,
  0x10000000,
  0x00000007,
  0x06000036,
  0x03600003,
  0x16000000,
  0x0A500000,
  0x00000017,
  0x00000E00,
  0x00000080,
  0x00000009,
  0x0000000C,
  0x01C00410,
  0x20000C00,
  0x03000030,
  0x00000020,
  0x00000060,
  0x00C00101,
  0x00300060,
  0x00000508,
  0x0000000F,
  0x00003018,
  0x00120500,
  0x10000C60,
  0x00004000,
  0x000A4040,
  0x00000021,
  0x00000006,
  0x90C00000,
  0x000E0081,
  0x10000006,
  0x00020000,
  0x10000000,
  0x00000007,
  0x00003006,
  0x00000003,
  0x0102C000,
  0x00000050,
  0x00000011,
  0xC0000C06,
  0x0001C000,
  0x03014000,
  0x0000001F,
  0x20000060,
  0x00001830,
  0x00000010,
  0x00C01400,
  0x00000050,
  0x00001008,
  0x0000C050,
  0x05000000,
  0x00028410,
  0x00000010,
  0x00001000,
  0x00000050,
  0x00000010,
  0x00000027,
  0x20031800,
  0x00060000,
  0x9C001800,
  0x00030000,
  0x00000090,
  0x00001228,
  0x00701400,
  0x0000000A,
  0x0000000B,
  0x00060180,
  0x00C18000,
  0x00080005,
  0x40500000,
  0x000000A0,
  0x00401001,
  0x0000000F,
  0x30600000,
  0x00003018,
  0x000000E0,
  0x00000001,
  0x00000200,
  0x00002000,
  0x00000023,
  0x00006000,
  0x00180000,
  0x00700000,
  0x00C00000,
  0x00000018,
  0x00C00000,
  0x00000007,
  0x00000019,
  0x00020800,
  0x10006000,
  0x08020804,
  0x4000C000,
  0x00000007,
  0x00000003,
  0x00128900,
  0x16006060,
  0x00384000,
  0x0000C840,
  0x00000021,
  0x00000006,
  0x0CC0C000,
  0x00038005,
  0x00121100,
  0x00000009,
  0x2002C000,
  0x20000050,
  0x00000011,
  0xC0000000,
  0x00028000,
  0x96000000,
  0x20060000,
  0x00000003,
  0x03000C03,
  0x00000606,
  0x00018000,
  0x00080000,
  0x00280000,
  0x00100000,
  0x0000000D,
  0x00180180,
  0x00000120,
  0x00160001,
  0x00000200,
  0x00000023,
  0x00006006,
  0x10000000,
  0x00000003,
  0x00000090,
  0x00001019,
  0x00000052,
  0x00001A01,
  0x0000146B,
  0x00000801,
  0x0000000B,
  0x00060000,
  0x80036180,
  0x00280002,
  0x00028001,
  0x0A000005,
  0x01000000,
  0x03000000,
  0x00000200,
  0x00000015,
  0x00000004,
  0x20000000,
  0x20080000,
  0x0000001D,
  0x8000C000,
  0x00000065,
  0x00000005,
  0x00006C00,
  0x00003600,
  0x07000000,
  0x05000000,
  0x00000019,
  0x0000000D,
  0x18008100,
  0x46000030,
  0x00500001,
  0xA0000000,
  0x00001C05,
  0x90000030,
  0x90030060,
  0x00000005,
  0x00000180,
  0x00600630,
  0x00030C03,
  0x00000606,
  0x00000090,
  0x00000050,
  0x00000027,
  0x0E000000,
  0x0000001B,
  0x06000000,
  0x00100000,
  0x00000008,
  0x00000010,
  0x00008040,
  0x00000011,
  0x00C00000,
  0xC0000000,
  0x0C000000,
  0x00900000,
  0x00000008,
  0x00400008,
  0x0000000D,
  0x00C00000,
  0x0002C000,
  0x00014000,
  0x00020102,
  0x00014000,
  0x0000001F,
  0x20000000,
  0x00000800,
  0x00000002,
  0x20000000,
  0x00000800,
  0x00000002,
  0x20000000,
  0x0000001D,
  0x0000C000,
  0x00006000,
  0x00480000,
  0x00280000,
  0x00280000,
  0x00000080,
  0x00000025,
  0x00004000,
  0x0000001F,
  0x00048000,
  0x02000000,
  0x00000017,
  0x00000600,
  0x00000015,
  0x00000006,
  0x09000000,
  0x03000000,
  0x00000019,
  0x00038000,
  0x00001000,
  0x00000009,
  0x00000070,
  0x00000050,
  0x00000027,
  0x00060000,
  0x00030000,
  0x0E700160,
  0x0000001B,
  0x06C06000,
  0x20000000,
  0x00000003,
  0x00000025,
  0x00000003,
  0x20000000,
  0x00000002,
  0x20000000,
  0x0000001D,
  0x16000000,
  0x00000009,
  0x00000060,
  0x00000060,
  0x0000000F,
  0x00000001,
  0x000D0000,
  0x00040001,
  0x000C0000,
  0x00000001,
  0x00080000,
  0x00000001,
  0x000D0000,
  0x00000003,
  0x000C0000,
  0x00000001,
  0x00080000,
  0x00000001,
  0x000D0000,
  0x00000003,
  0x000C0000,
  0x00000001,
  0x00080000,
  0x00000001,
  0x000D0000,
  0x00000003,
  0x000C0000,
  0x00092000,
  0x08000200,
  0x00800021,
  0x000B0000,
  0x00092000,
  0x08000200,
  0x00800021,
  0x000B0000,
  0x00000005,
  0x000E0000,
  0x00000005,
  0x000E0000,
  0x00040001,
  0x000C0000,
  0x00800000,
  0x00000088,
  0x80002000,
  0x00000200,
  0x00F00001,
  0x01000000,
  0x00000088,
  0xC0002000,
  0x00000200,
  0x00D00001,
  0x01000000,
  0x00800000,
  0x00800000,
  0x00000088,
  0x80002000,
  0x00F00001,
  0x01000000,
  0x00000088,
  0xC0002000,
  0x00D00001,
  0x01000000,
  0x00800000,
  0x00800000,
  0x00000088,
  0x80002000,
  0x00F00001,
  0x01000000,
  0x00800000,
  0x00000088,
  0x80002000,
  0x00F00001,
  0x01000000,
  0x00000088,
  0xC0002000,
  0x00D40001,
  0x01000000,
  0x00800000,
  0x00800000,
  0x00000088,
  0x80002000,
  0x00F00001,
  0x01000000,
  0x00800000,
  0x00000088,
  0x80002000,
  0x00F00001,
  0x01000000,
  0x00800000,
  0x00000088,
  0x80002000,
  0x00F00001,
  0x01000000,
  0x00800000,
  0x00000088,
  0x80002000,
  0x08000000,
  0x00F40001,
  0x01000000,
  0x00800000,
  0x00000088,
  0x80002000,
  0x08000000,
  0x00F40001,
  0x01000000,
  0x00800000,
  0x00000088,
  0x80002000,
  0x08000000,
  0x00F40001,
  0x01000000,
};

#endif  // BITSTREAM_H
