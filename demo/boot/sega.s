.section .text.keepboot

        .org    0x00000000

_Start_Of_Rom:
_Vecteurs_68K:
        dc.l    0x00FFFE00
        dc.l    main
	
        move.w	#0x2700, sr
        move.l	Header(pc), 0xA4000

.org 0x100
Header:
	.ascii	 "SEGA"

_INT:
        rte
