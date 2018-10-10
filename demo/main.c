typedef unsigned short u16;
typedef unsigned long u32;
typedef volatile u16 vu16;
typedef volatile u32 vu32;

#define GFX_DATA_PORT           0xC00000
#define GFX_CTRL_PORT           0xC00004
#define GFX_WRITE_CRAM_ADDR(adr)    ((0xC000 + ((adr) & 0x3FFF)) << 16) + (((adr) >> 14) | 0x00)

static const unsigned char regValues[] = { 0x04, 0x74, 0xE000, 0xD000, 0xC000, 0xDC00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x81, 0xD800, 0x00, 0x02, 0x01, 0x00, 0x00 };
static const u16 colors[] = {  15|0<<4|0<<8, 0|15<<4|0<<8, 0|0<<4|15<<8 };

void init()
{
    u16 i;
    vu16* pw = (u16 *) GFX_CTRL_PORT;
    for (i = 0x00; i < 0x13; i++) *pw = 0x8000 | (i << 8) | regValues[i];
}

void set_color(u16 color)
{
    *(vu32*) GFX_CTRL_PORT = GFX_WRITE_CRAM_ADDR(0);
    *(vu16*) GFX_DATA_PORT = color;
}

void wait(u16 time)
{
    u16 k;
    for (k=0 ; k<time ; ++k)
        init();
}

void main()
{
    u16 i,v, j, k;

    init();

    while (1)
    {
        set_color(colors[0]);
        wait(3000);
        set_color(colors[1]);
        wait(3000);
        set_color(colors[2]);
        wait(3000);

        for (j=0 ; j<10 ; ++j)
        {
            i = 0;
            for (k=0 ; k<1000 ; ++k)
            {
                set_color(colors[i]);
                ++i;
                if (i==3) i = 0;
                wait(j);
            }
        }
    }
}
