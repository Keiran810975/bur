#define GET_BIT(value, bit) (((value) >> bit) & 1)      // 读取指定位
#define CPL_BIT(value, bit) ((value) ^= (1 << (bit)))   // 取反指定位
#define SET0_BIT(value, bit) ((value) &= ~(1 << (bit))) // 某位置0
#define SET1_BIT(value, bit) ((value) |= (1 << (bit)))  //某位置1