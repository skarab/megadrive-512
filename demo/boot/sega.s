.section .text.keepboot

        .org    0x00000000

_Start_Of_Rom:
_Vecteurs_68K:
        dc.l    0x00FFFE00              /* Stack address */
        dc.l    main            /* Program start address */
	
        dc.l    _INT
        dc.l    _INT
        dc.l    _INT
        dc.l    _INT
        dc.l    _INT
        dc.l    _INT
        dc.l    _INT
        dc.l    _INT
        dc.l    _INT
        dc.l    _INT
        dc.l     _INT, _INT, _INT, _INT
        dc.l     _INT, _INT, _INT, _INT
        dc.l     _INT, _INT, _INT, _INT
        dc.l    _INT, _INT, _INT, _INT
        dc.l    _INT
        dc.l    _INT
        dc.l    _INT
        dc.l    _INT 
        dc.l    _INT,_INT,_INT,_INT,_INT,_INT,_INT,_INT
        dc.l    _INT,_INT,_INT,_INT,_INT,_INT,_INT,_INT
        dc.l    _INT,_INT,_INT,_INT,_INT,_INT,_INT,_INT
        dc.l    _INT,_INT,_INT,_INT,_INT,_INT,_INT,_INT

        .incbin "boot/rom_head.bin", 0x10, 0x98

_INT:
        rte
