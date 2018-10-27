#ifndef _SOUND_H_
#define _SOUND_H_

typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef unsigned long u32;
typedef volatile u8 vu8;
typedef volatile u16 vu16;
typedef volatile u32 vu32;

#define TRUE 1
#define FALSE 0

void sound_play(const u8 *song);


#define Z80_HALT_PORT                   0xA11100
#define Z80_RESET_PORT                  0xA11200

#define Z80_RAM_START                   0xA00000
#define Z80_RAM_END                     0xA01FFF
#define Z80_RAM                         Z80_RAM_START
#define Z80_RAM_LEN                     ((Z80_RAM_END - Z80_RAM_START) + 1)
#define Z80_YM2612                      0xA04000
#define Z80_BANK_REGISTER               0xA06000
#define Z80_DRV_COMMAND                 0xA00100
#define Z80_DRV_STATUS                  0xA00102
#define Z80_DRV_PARAMS                  0xA00104

u16  Z80_isBusTaken();
void Z80_requestBus(u16 wait);
void Z80_releaseBus();
void Z80_startReset();
void Z80_endReset();
void Z80_setBank(const u16 bank);
u8 Z80_read(const u16 addr);
void Z80_write(const u16 addr, const u8 value);
void Z80_clear(const u16 dest, const u16 size, const u16 resetz80);
void Z80_upload(const u16 dest, const u8 *data, const u16 size, const u16 resetz80);
void Z80_download(const u16 from, u8 *dest, const u16 size);
void Z80_loadDriver(const u16 waitReady);

extern const u8 z80_vgm[3648];

#endif
