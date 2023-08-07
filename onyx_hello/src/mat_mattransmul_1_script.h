#ifndef BITSTREAM_H
#define BITSTREAM_H

const int app_size = 460;

uint32_t app_addrs_script[] = {
  0x030E0408,
  0x020E0408,
  0x030E0508,
  0x020E0508,
  0x050E0608,
  0x020E0608,
  0x050E0607,
  0x020E0607,
  0x00030606,
  0x000E0408,
  0x000E0508,
  0x010E0608,
  0x010E0607,
  0x020E0A04,
  0x010E0A04,
  0x020B0B04,
  0x010B0B04,
  0x040B0B03,
  0x020B0B03,
  0x040E0C03,
  0x030E0C03,
  0x020E0C03,
  0x00030C02,
  0x000E0A04,
  0x000B0B04,
  0x010B0B03,
  0x000E0C03,
  0x030B0302,
  0x020B0302,
  0x030E0202,
  0x020E0202,
  0x020E0102,
  0x010E0102,
  0x020E0101,
  0x010E0101,
  0x000B0302,
  0x000E0202,
  0x000E0102,
  0x000E0101,
  0x020B0304,
  0x010B0304,
  0x020B0303,
  0x010B0303,
  0x010B0302,
  0x020B0301,
  0x010B0301,
  0x000B0304,
  0x000B0303,
  0x000B0301,
  0x050E0502,
  0x020E0502,
  0x050E0402,
  0x020E0402,
  0x050B0302,
  0x050B0303,
  0x00060304,
  0x010E0502,
  0x010E0402,
  0x050E0201,
  0x020E0201,
  0x050B0301,
  0x050E0401,
  0x020E0401,
  0x050E0501,
  0x020E0501,
  0x050E0601,
  0x020E0601,
  0x00050701,
  0x010E0201,
  0x010E0401,
  0x010E0501,
  0x040B0701,
  0x020B0701,
  0x040E0801,
  0x020E0801,
  0x040E0901,
  0x020E0901,
  0x040E0902,
  0x020E0902,
  0x00030903,
  0x010B0701,
  0x010E0801,
  0x000E0901,
  0x010E0901,
  0x000E0902,
  0x010E0902,
  0x030B0701,
  0x030E0801,
  0x030E0901,
  0x030E0902,
  0x00050903,
  0x000B0701,
  0x000E0801,
  0x030E0602,
  0x020E0602,
  0x030E0601,
  0x00030701,
  0x000E0602,
  0x000E0601,
  0x030E0403,
  0x010E0403,
  0x00050303,
  0x000E0401,
  0x000E0402,
  0x020E0403,
  0x020E0503,
  0x010E0503,
  0x020E0603,
  0x010E0603,
  0x020B0703,
  0x010B0703,
  0x020E0803,
  0x010E0803,
  0x00040903,
  0x000E0403,
  0x000E0503,
  0x000E0603,
  0x000B0703,
  0x000E0803,
  0x030B0303,
  0x030E0503,
  0x030E0603,
  0x030B0703,
  0x030E0803,
  0x00060903,
  0x050E0C02,
  0x020E0C02,
  0x050B0B02,
  0x020B0B02,
  0x050E0A02,
  0x020E0A02,
  0x00030902,
  0x010E0C02,
  0x010B0B02,
  0x040E0602,
  0x040E0502,
  0x040E0402,
  0x00030303,
  0x010E0602,
  0x040E0601,
  0x040E0501,
  0x040E0401,
  0x00050301,
  0x010E0601,
  0x040B0301,
  0x00040602,
  0x030B0301,
  0x030E0401,
  0x030E0501,
  0x00060602,
  0x000E0501,
  0x040E0802,
  0x020E0802,
  0x030B0702,
  0x020B0702,
  0x00050703,
  0x010E0802,
  0x040B0703,
  0x050B0704,
  0x020B0704,
  0x050E0804,
  0x020E0804,
  0x050E0904,
  0x020E0904,
  0x00030A04,
  0x010B0704,
  0x010E0804,
  0x010E0904,
  0x050E0606,
  0x020E0606,
  0x050E0605,
  0x020E0605,
  0x050E0604,
  0x020E0604,
  0x050E0603,
  0x00030703,
  0x010E0606,
  0x010E0605,
  0x010E0604,
  0x040E0A01,
  0x020E0A01,
  0x050E0802,
  0x050B0702,
  0x050B0703,
  0x00050704,
  0x010E0A01,
  0x010B0702,
  0x050B0701,
  0x00030801,
  0x030E0607,
  0x030E0606,
  0x040B0706,
  0x020B0706,
  0x040B0705,
  0x020B0705,
  0x00030704,
  0x000E0607,
  0x000E0606,
  0x010B0706,
  0x010B0705,
  0x050E0902,
  0x040B0702,
  0x050E0602,
  0x00030502,
  0x030E0C01,
  0x010E0C01,
  0x040B0B01,
  0x020B0B01,
  0x00050B02,
  0x000E0C01,
  0x010B0B01,
  0x040B0B02,
  0x040E0A02,
  0x030E0802,
  0x00040801,
  0x010E0A02,
  0x000E0802,
  0x030E0A02,
  0x00030B02,
  0x000B0702,
  0x030E0E01,
  0x020E0E01,
  0x030E0D01,
  0x020E0D01,
  0x00050B01,
  0x000E0E01,
  0x000E0D01,
  0x050B0B01,
  0x050E0A01,
  0x050E0A03,
  0x020E0A03,
  0x00040A04,
  0x010E0A03,
  0x020E0903,
  0x010E0903,
  0x00030B01,
  0x000E0903,
  0x000E0A03,
  0x000E0A02,
  0x030E1001,
  0x020E1001,
  0x030E1002,
  0x020E1002,
  0x050E1003,
  0x00050F03,
  0x000E1001,
  0x000E1002,
  0x050B0F03,
  0x040B0F03,
  0x020B0F03,
  0x030E0E03,
  0x020E0E03,
  0x050E0E02,
  0x040E0E02,
  0x020E0E02,
  0x050E0D02,
  0x040E0D02,
  0x020E0D02,
  0x00040C02,
  0x010B0F03,
  0x000E0E03,
  0x010E0E02,
  0x010E0D02,
  0x030E0903,
  0x030E0A03,
  0x030B0B03,
  0x030E0D03,
  0x020E0D03,
  0x00030F03,
  0x000B0B03,
  0x000E0D03,
  0x040E0603,
  0x040E0604,
  0x040E0605,
  0x00030505,
  0x020E0905,
  0x010E0905,
  0x020E0906,
  0x010E0906,
  0x00030907,
  0x000E0904,
  0x000E0905,
  0x000E0906,
  0x030E0502,
  0x030E0402,
  0x00060302,
  0x000E0502,
  0x050E0505,
  0x020E0505,
  0x050E0405,
  0x020E0405,
  0x050E0406,
  0x020E0406,
  0x050E0407,
  0x020E0407,
  0x00040408,
  0x010E0505,
  0x010E0405,
  0x010E0406,
  0x010E0407,
  0x030E0505,
  0x030E0504,
  0x020E0504,
  0x040E0503,
  0x00040402,
  0x000E0505,
  0x000E0504,
  0x030E0506,
  0x020E0506,
  0x030E0507,
  0x00040607,
  0x000E0506,
  0x030E0907,
  0x010E0907,
  0x050E0807,
  0x020E0807,
  0x030E0806,
  0x010E0806,
  0x030B0706,
  0x00040606,
  0x000E0907,
  0x010E0807,
  0x000E0806,
  0x000B0706,
  0x050E0801,
  0x00040502,
  0x030E0001,
  0x020E0001,
  0x030E0002,
  0x020E0002,
  0x030E0003,
  0x020E0003,
  0x030E0004,
  0x020E0004,
  0x030E0005,
  0x020E0005,
  0x030E0105,
  0x020E0105,
  0x030E0205,
  0x00050305,
  0x000E0001,
  0x000E0002,
  0x000E0003,
  0x000E0004,
  0x000E0005,
  0x000E0105,
  0x030B0305,
  0x020B0305,
  0x040E0405,
  0x040E0404,
  0x020E0404,
  0x040E0403,
  0x00030602,
  0x000B0305,
  0x010E0404,
  0x040B0305,
  0x030B0304,
  0x030E0404,
  0x050E0504,
  0x050E0503,
  0x00050602,
  0x000E0404,
  0x010E0504,
  0x00000602,
  0x03000602,
  0x00000505,
  0x03000505,
  0x00000408,
  0x03000408,
  0x00000606,
  0x03000606,
  0x02000A04,
  0x01000A04,
  0x00000A04,
  0x03000A04,
  0x02000C02,
  0x01000C02,
  0x00000C02,
  0x03000C02,
  0x02000502,
  0x01000502,
  0x00000502,
  0x03000502,
  0x00000902,
  0x03000902,
  0x00000402,
  0x03000402,
  0x00000903,
  0x03000903,
  0x00000907,
  0x03000907,
  0x02000801,
  0x01000801,
  0x00000801,
  0x03000801,
  0x00000607,
  0x03000607,
  0x00000000,
  0x17000305,
  0x0C000305,
  0x01000305,
  0x00000305,
  0x2E000305,
  0x17000302,
  0x0C000302,
  0x01000302,
  0x00000302,
  0x2E000302,
  0x00000100,
  0x17000304,
  0x0C000304,
  0x00000304,
  0x2E000304,
  0x00000300,
  0x00000200,
  0x17000701,
  0x0C000701,
  0x00000701,
  0x2E000701,
  0x00000400,
  0x17000303,
  0x0C000303,
  0x00000303,
  0x2E000303,
  0x00000600,
  0x17000301,
  0x0C000301,
  0x01000301,
  0x00000301,
  0x2E000301,
  0x00000800,
  0x17000703,
  0x0C000703,
  0x01000703,
  0x00000703,
  0x2E000703,
  0x00000A00,
  0x17000704,
  0x0C000704,
  0x01000704,
  0x00000704,
  0x2E000704,
  0x00000C00,
  0x17000B02,
  0x0C000B02,
  0x01000B02,
  0x00000B02,
  0x2E000B02,
  0x00000E00,
  0x17000B01,
  0x0C000B01,
  0x01000B01,
  0x00000B01,
  0x2E000B01,
  0x00001000,
  0x17000F03,
  0x0C000F03,
  0x01000F03,
  0x00000F03,
  0x2E000F03,
};

uint32_t app_datas_script[] = {
  0x000000E0,
  0x00000001,
  0x00000060,
  0x00000001,
  0x00000200,
  0x00002000,
  0x00000A00,
  0x00002002,
  0x00000023,
  0x00006000,
  0x00003000,
  0x00300000,
  0x00180000,
  0x000E0000,
  0x10000000,
  0x00400000,
  0x20000000,
  0x00004000,
  0x00000101,
  0x00000002,
  0x40000060,
  0x00000021,
  0x00000013,
  0x00000006,
  0x00000018,
  0x00000060,
  0x18003000,
  0x00708000,
  0x0140400C,
  0x00500000,
  0x00000008,
  0x00C00000,
  0x20000000,
  0x01400000,
  0x20000000,
  0x00CC0030,
  0x00600000,
  0x00000030,
  0x00000018,
  0x01C00001,
  0x20000000,
  0x01524010,
  0x30C00000,
  0x21800000,
  0x01401110,
  0x20030060,
  0x00003030,
  0x0600001E,
  0x06000018,
  0x00380050,
  0x00029080,
  0x00280070,
  0x18069080,
  0x0000C000,
  0x00014000,
  0x00000021,
  0x9C030006,
  0x5606000C,
  0x00000010,
  0x00001000,
  0x00000050,
  0x00000050,
  0x18001110,
  0x00000050,
  0x08001190,
  0x00000052,
  0x000008D4,
  0x00000027,
  0x00060000,
  0x40060030,
  0x40030066,
  0x20024000,
  0x00001910,
  0x23014000,
  0x00000D14,
  0x00000A50,
  0x000000C4,
  0x20000A30,
  0x000008C5,
  0x00000011,
  0x00036060,
  0x0000D830,
  0x80180000,
  0x00000007,
  0xC00C3000,
  0x0000C00C,
  0x16000000,
  0x0A008000,
  0x00028000,
  0x00018060,
  0x00000009,
  0x06000000,
  0x03180000,
  0x00001567,
  0x00000C83,
  0x06028000,
  0x00000017,
  0x00036C00,
  0xC30C0000,
  0x0A000401,
  0x10000180,
  0x00000005,
  0x03000180,
  0x000000C6,
  0x00020212,
  0x00021090,
  0x1006000C,
  0x00021412,
  0x10030C00,
  0x00026410,
  0x10D81800,
  0x00020010,
  0x10000000,
  0x00000007,
  0x03018003,
  0x06000006,
  0x03018003,
  0x06000006,
  0x03000003,
  0x16000000,
  0x0A000000,
  0x0A001400,
  0x0A000000,
  0x0A000000,
  0x00000017,
  0x00380000,
  0x00008000,
  0x00280000,
  0x00008080,
  0x00294000,
  0x01404080,
  0x00000025,
  0x0C000000,
  0x0600000C,
  0x27001200,
  0x00000A00,
  0x00000A00,
  0x00000009,
  0x8000780C,
  0x20000250,
  0x00014A00,
  0x00014A00,
  0x00000015,
  0x0000C00C,
  0x00024000,
  0x00000011,
  0x16000000,
  0x0A000000,
  0x0A000000,
  0x00000009,
  0x060000C0,
  0x20000200,
  0x00008883,
  0x00008060,
  0x00006801,
  0x00000009,
  0x06006006,
  0x09000000,
  0x00001210,
  0x00003000,
  0x00000050,
  0x00001000,
  0x00000050,
  0x18001000,
  0x00000027,
  0x00330000,
  0x00060000,
  0x40030000,
  0x00000E00,
  0x00002010,
  0x00000A00,
  0x00002080,
  0x00000A00,
  0x00002400,
  0x00000030,
  0x00000027,
  0x00300000,
  0x00180006,
  0x00301800,
  0x00004200,
  0x00004180,
  0x00080002,
  0x0000CA02,
  0x00014A00,
  0x00000021,
  0x00C0003C,
  0x01B0C000,
  0x00000032,
  0x00000027,
  0x00001C00,
  0x06000000,
  0x00080000,
  0x00000200,
  0x00280000,
  0x00000200,
  0x0000001B,
  0x00030000,
  0x03000000,
  0x80000300,
  0x00000180,
  0x00000003,
  0x20000000,
  0x00000002,
  0x0000001D,
  0x00500001,
  0x80000000,
  0x01000000,
  0x00008400,
  0x00000019,
  0x00000C00,
  0x0C000C00,
  0x00001200,
  0x00000A00,
  0x00000460,
  0x0000000B,
  0x21800006,
  0x0001E000,
  0x00000060,
  0x0000000F,
  0x00003000,
  0x00100000,
  0x00000008,
  0x00500000,
  0x00000008,
  0x0000000D,
  0x00C00000,
  0x00600000,
  0x00480000,
  0x0000C000,
  0x00014000,
  0x00404001,
  0x00000021,
  0x20C00000,
  0x38160001,
  0x50000000,
  0x0000001F,
  0x00006186,
  0x00003018,
  0x00000030,
  0x00018000,
  0x00000004,
  0x00018000,
  0x00000004,
  0x00080000,
  0x00000025,
  0x00180000,
  0x000C0000,
  0x00000004,
  0x20000000,
  0x00000800,
  0x40000060,
  0x00000021,
  0x00000001,
  0x20000000,
  0x00000800,
  0x00000002,
  0x20000000,
  0x00000800,
  0x0000001D,
  0x0000C000,
  0x18003000,
  0x0000C000,
  0x00006000,
  0x00000120,
  0x00000060,
  0x00000060,
  0x00000060,
  0x00000001,
  0x0000000F,
  0x00006000,
  0x00006000,
  0x03000000,
  0x03000000,
  0x00000200,
  0x00000015,
  0x18000000,
  0x40000000,
  0x18000000,
  0x40000000,
  0x00000001,
  0x000000C0,
  0x00000180,
  0x000000C0,
  0x00000005,
  0x00000005,
  0x00000005,
  0x00000603,
  0x00380000,
  0x00008006,
  0x0000C000,
  0x00004200,
  0x00014000,
  0x00004000,
  0x00014000,
  0x00004000,
  0x00000021,
  0x0C000000,
  0x00C00180,
  0x01800000,
  0x00C00000,
  0x00039C00,
  0x00000C00,
  0x00002002,
  0x00000600,
  0x0000000B,
  0x001B0000,
  0x00018000,
  0x00018000,
  0x00000004,
  0x02000000,
  0x00000017,
  0x000C0000,
  0x00000007,
  0x80000000,
  0x00000600,
  0x00002000,
  0x00000003,
  0x80000000,
  0x00000005,
  0x00000005,
  0x00000C00,
  0x00180000,
  0x00000C00,
  0x00000600,
  0x00000003,
  0x00000001,
  0x00018000,
  0x00000004,
  0x00018000,
  0x00000004,
  0x00018000,
  0x00000004,
  0x00018000,
  0x00000004,
  0x02000000,
  0x00000010,
  0x0A000000,
  0x00000010,
  0x0A000000,
  0x00000017,
  0x00180000,
  0x000C0000,
  0x00180000,
  0x000C0000,
  0x06000000,
  0x03000000,
  0x52000000,
  0x00000030,
  0x00080000,
  0x00280000,
  0x00000201,
  0x00280000,
  0x00000007,
  0x36000000,
  0x00000300,
  0x00000005,
  0x000000A0,
  0x00000060,
  0x00000200,
  0x00000030,
  0x0000000B,
  0x00006000,
  0x00180000,
  0x00000003,
  0x00080000,
  0x00000001,
  0x000D0000,
  0x00040001,
  0x000C0000,
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
  0x00090000,
  0x08000200,
  0x00800001,
  0x000B0000,
  0x00000005,
  0x000E0000,
  0x00040001,
  0x000C0000,
  0x00000001,
  0x00080000,
  0x00000001,
  0x000D0000,
  0x00092000,
  0x08000200,
  0x00800021,
  0x000B0000,
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
  0x00000200,
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
