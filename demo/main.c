typedef unsigned short u16;
typedef unsigned long u32;
typedef volatile u16 vu16;
typedef volatile u32 vu32;

#define GFX_DATA_PORT           0xC00000
#define GFX_CTRL_PORT           0xC00004
#define GFX_WRITE_CRAM_ADDR(adr)    ((0xC000 + ((adr) & 0x3FFF)) << 16) + (((adr) >> 14) | 0x00)

void main()
{
    static const unsigned char regValues[] = { 0x04, 0x74, 0xE000, 0xD000, 0xC000, 0xDC00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x81, 0xD800, 0x00, 0x02, 0x01, 0x00, 0x00 };
    vu16 *pw;
    vu32 *pl;
    u16 i;
  
    // init
    pw = (u16 *) GFX_CTRL_PORT;
    for (i = 0x00; i < 0x13; i++) *pw = 0x8000 | (i << 8) | regValues[i];

    // set background color
    *(vu32*) GFX_CTRL_PORT = GFX_WRITE_CRAM_ADDR(0);
    *(vu16*) GFX_DATA_PORT = 7|7<<4|7<<8;
}
