    .code

.if (.cpu .bitand CPU_ISET_6502)
    .scope
    ; regular basic 6502 (legal) instruction set
LABEL0:
    brk             ; $00
    ora ($12,x)     ; $01
    ora $12         ; $05
    asl $12         ; $06
    php             ; $08
    ora #$12        ; $09
    asl a           ; $0a
    ora $1234       ; $0d
    asl $1234       ; $0e
    bpl LABEL0      ; $10
    ora ($12),y     ; $11
    ora $12,x       ; $15
    asl $12,x       ; $16
    clc             ; $18
    ora $1234,y     ; $19
    ora $1234,x     ; $1d
    asl $1234,x     ; $1e
    jsr $1234       ; $20
    and ($12,x)     ; $21
    bit $12         ; $24
    and $12         ; $25
    rol $12         ; $26
    plp             ; $28
    and #$12        ; $29
    rol a           ; $2a
    bit $1234       ; $2c
    and $1234       ; $2d
    rol $1234       ; $2e
    bmi LABEL       ; $30
    and ($12),y     ; $31
    and $12,x       ; $35
    rol $12,x       ; $36
    sec             ; $38
    and $1234,y     ; $39
    and $1234,x     ; $3d
    rol $1234,x     ; $3e
    rti             ; $40
    eor ($12,x)     ; $41
    eor $12         ; $45
    lsr $12         ; $46
    pha             ; $48
    eor #$12        ; $49
    lsr a           ; $4a
    jmp $1234       ; $4c
    eor $1234       ; $4d
    lsr $1234       ; $4e
    bvc LABEL       ; $50
    eor ($12),y     ; $51
    eor $12,x       ; $55
    lsr $12,x       ; $56
    cli             ; $58
    eor $1234,y     ; $59
    eor $1234,x     ; $5d
    lsr $1234,x     ; $5e
    rts             ; $60
    adc ($12,x)     ; $61
    adc $12         ; $65
    ror $12         ; $66
    pla             ; $68
    adc #$12        ; $69
    ror a           ; $6a
    jmp ($1234)     ; $6c
    adc $1234       ; $6d
    ror $1234       ; $6e
    bvs LABEL       ; $70
    adc ($12),y     ; $71
    adc $12,x       ; $75
    ror $12,x       ; $76
    sei             ; $78
    adc $1234,y     ; $79
    adc $1234,x     ; $7d
    ror $1234,x     ; $7e
LABEL:
    sta ($12,x)     ; $81
    sty $12         ; $84
    sta $12         ; $85
    stx $12         ; $86
    dey             ; $88
    txa             ; $8a
    sty $1234       ; $8c
    sta $1234       ; $8d
    stx $1234       ; $8e
    bcc LABEL       ; $90
    sta ($12),y     ; $91
    sty $12,x       ; $94
    sta $12,x       ; $95
    stx $12,y       ; $96
    tya             ; $98
    sta $1234,y     ; $99
    txs             ; $9a
    sta $1234,x     ; $9d
    ldy #$12        ; $a0
    lda ($12,x)     ; $a1
    ldx #$12        ; $a2
    ldy $12         ; $a4
    lda $12         ; $a5
    ldx $12         ; $a6
    tay             ; $a8
    lda #$12        ; $a9
    tax             ; $aa
    ldy $1234       ; $ac
    lda $1234       ; $ad
    ldx $1234       ; $ae
    bcs LABEL       ; $b0
    lda ($12),y     ; $b1
    ldy $12,x       ; $b4
    lda $12,x       ; $b5
    ldx $12,y       ; $b6
    clv             ; $b8
    lda $1234,y     ; $b9
    tsx             ; $ba
    ldy $1234,x     ; $bc
    lda $1234,x     ; $bd
    ldx $1234,y     ; $be
    cpy #$12        ; $c0
    cmp ($12,x)     ; $c1
    cpy $12         ; $c4
    cmp $12         ; $c5
    dec $12         ; $c6
    iny             ; $c8
    cmp #$12        ; $c9
    dex             ; $ca
    cpy $1234       ; $cc
    cmp $1234       ; $cd
    dec $1234       ; $ce
    bne LABEL       ; $d0
    cmp ($12),y     ; $d1
    cmp $12,x       ; $d5
    dec $12,x       ; $d6
    cld             ; $d8
    cmp $1234,y     ; $d9
    cmp $1234,x     ; $dd
    dec $1234,x     ; $de
    cpx #$12        ; $e0
    sbc ($12,x)     ; $e1
    cpx $12         ; $e4
    sbc $12         ; $e5
    inc $12         ; $e6
    inx             ; $e8
    sbc #$12        ; $e9
    nop             ; $ea
    cpx $1234       ; $ec
    sbc $1234       ; $ed
    inc $1234       ; $ee
    beq LABEL1      ; $f0
    sbc ($12),y     ; $f1
    sbc $12,x       ; $f5
    inc $12,x       ; $f6
    sed             ; $f8
    sbc $1234,y     ; $f9
    sbc $1234,x     ; $fd
    inc $1234,x     ; $fe
LABEL1:
    .endscope
.endif


.if (.cpu .bitand CPU_ISET_6502X)
    .scope
    ; all "undocumented" 6502 instructions (aka "unintended opcodes")
    jam             ; $02
    slo ($12,x)     ; $03
    nop $12         ; $04
    slo $12         ; $07
    anc #$12        ; $0b
    nop $1234       ; $0c
    slo $1234       ; $0f
    jam             ; $12
    slo ($12),y     ; $13
    nop $12,x       ; $14
    slo $12,y       ; $17
    nop             ; $1a
    slo $1234,y     ; $1b
    nop $1234,x     ; $1c
    slo $1234,x     ; $1f
    jam             ; $22
    rla ($12,x)     ; $23
    rla $12         ; $27
    anc #$12        ; $2b
    rla $1234       ; $2f
    jam             ; $32
    rla ($12),y     ; $33
    nop $12,x       ; $34
    rla $12,y       ; $37
    nop             ; $3a
    rla $1234,y     ; $3b
    nop $1234,x     ; $3c
    rla $1234,x     ; $3f
    jam             ; $42
    sre ($12,x)     ; $43
    nop $12         ; $44
    sre $12         ; $47
    alr #$12        ; $4b
    sre $1234       ; $4f
    jam             ; $52
    sre ($12),y     ; $53
    nop $12,x       ; $54
    sre $12,y       ; $57
    nop             ; $5a
    sre $1234,y     ; $5b
    nop $1234,x     ; $5c
    sre $1234,x     ; $5f
    jam             ; $62
    rra ($12,x)     ; $63
    nop $12         ; $64
    rra $12         ; $67
    arr #$12        ; $6b
    rra $1234       ; $6f
    jam             ; $72
    rra ($12),y     ; $73
    nop $12,x       ; $74
    rra $12,y       ; $77
    nop             ; $7a
    rra $1234,y     ; $7b
    nop $1234,x     ; $7c
    rra $1234,x     ; $7f
    nop #$12        ; $80
    nop #$12        ; $82
    sax ($12,x)     ; $83
    sax $12         ; $87
    nop #$12        ; $89
    ane #$12        ; $8b
    sax $1234       ; $8f
    jam             ; $92
    sha ($12),y     ; $93
    sax $12,y       ; $97
    tas $1234,y     ; $9b
    shy $1234,x     ; $9c
    shx $1234,y     ; $9e
    sha $1234,y     ; $9f
    lax ($12,x)     ; $a3
    lax $12         ; $a7
    lax #$12        ; $ab
    lax $1234       ; $af
    jam             ; $b2
    lax ($12),y     ; $b3
    lax $12,y       ; $b7
    las $1234,y     ; $bb
    lax $1234,y     ; $bf
    nop #$12        ; $c2
    dcp ($12,x)     ; $c3
    dcp $12         ; $c7
    axs #$12        ; $cb
    dcp $1234       ; $cf
    jam             ; $d2
    dcp ($12),y     ; $d3
    nop $12,x       ; $d4
    dcp $12,y       ; $d7
    nop             ; $da
    dcp $1234,y     ; $db
    nop $1234,x     ; $dc
    dcp $1234,x     ; $df
    nop #$12        ; $e2
    isc ($12,x)     ; $e3
    isc $12         ; $e7
    sbc #$12        ; $eb
    isc $1234       ; $ef
    jam             ; $f2
    isc ($12),y     ; $f3
    nop $12,x       ; $f4
    isc $12,y       ; $f7
    nop             ; $fa
    isc $1234,y     ; $fb
    nop $1234,x     ; $fc
    isc $1234,x     ; $ff
    .endscope
.endif


.if (.cpu .bitand CPU_ISET_6502DTV)
    .scope
LABEL:
    ; opcodes added over 6502 (these are JAM on 6502)
    bra LABEL       ; $12
    sac #$12        ; $32
    sir #$12        ; $42

    ; opcodes added over 6502, which work the same as the "illegal" opcodes on 6502
    nop $12         ; $04
    nop $1234       ; $0c
    nop $12,x       ; $14
    nop             ; $1a
    nop $1234,x     ; $1c
    nop $12,x       ; $34
    nop             ; $3a
    nop $1234,x     ; $3c
    nop $12         ; $44
    nop $12,x       ; $54
    nop             ; $5a
    nop $1234,x     ; $5c
    nop $12         ; $64
    nop $12,x       ; $74
    nop             ; $7a
    nop $1234,x     ; $7c
    nop #$12        ; $80
    nop #$12        ; $82
    nop #$12        ; $89
    nop #$12        ; $c2
    nop $12,x       ; $d4
    nop             ; $da
    nop $1234,x     ; $dc
    nop #$12        ; $e2
    nop $12,x       ; $f4
    nop             ; $fa
    nop $1234,x     ; $fc

    anc #$12        ; $0b
    anc #$12        ; $2b

    rla ($12,x)     ; $23
    rla $12         ; $27
    rla $1234       ; $2f
    rla ($12),y     ; $33
    rla $12,y       ; $37
    rla $1234,y     ; $3b
    rla $1234,x     ; $3f

    lax ($12,x)     ; $a3
    lax $12         ; $a7
    lax #$12        ; $ab
    lax $1234       ; $af
    lax ($12),y     ; $b3
    lax $12,y       ; $b7
    lax $1234,y     ; $bf

    las $1234,y     ; $bb

    alr #$12        ; $4b

    arr #$12        ; $6b

    rra ($12,x)     ; $63
    rra $12         ; $67
    rra $1234       ; $6f
    rra ($12),y     ; $73
    rra $12,y       ; $77
    rra $1234,y     ; $7b
    rra $1234,x     ; $7f

    shy $1234,x     ; $9c
    shx $1234,y     ; $9e

    axs #$12        ; $cb

    sbc #$12        ; $eb

    .endscope
.endif

;------------------------------------------------------------------------------
; The 65sc02 is the original CMOS re-design of the 6502.
;
;      65SC02           65ce02
;
; $04  tsb zp
; $0c  tsb abs16
; $12  ora (zp)         (-> ora (zp), z)
; $14  trb zp
; $1a  inc
; $1c  trb abs16
; $32  and (zp)         (-> and (zp), z)
; $34  bit zp, x
; $3a  dec
; $3c  bit abs16, x
; $52  eor (zp)         (-> eor (zp), z)
; $5a  phy
; $64  stz zp           (store z, not 0)
; $72  adc (zp)         (-> adc (zp), z)
; $74  stz zp, x        (store z, not 0)
; $7a  ply
; $7c  jmp (abs16, x)
; $80  bra rel8
; $89  bit #imm8
; $92  sta (zp)         (-> sta (zp), z)
; $9c  stz abs16        (store z, not 0)
; $9e  stz abs16, x     (store z, not 0)
; $b2  lda (zp)         (-> lda (zp), z)
; $d2  cmp (zp)         (-> cmp (zp), z)
; $da  phx
; $f2  sbc (zp)         (-> sbc (zp), z)
; $fa  plx

.if (.cpu .bitand CPU_ISET_65SC02)
    .scope
    ; 65c02 instruction set adds some extra legal instructions to 6502
    tsb $12         ; $04
    tsb $1234       ; $0c
    ora ($12)       ; $12  FIXME: not working with 4510:ora (zp), z
    trb $12         ; $14
    inc a           ; $1a
    trb $1234       ; $1c
    and ($12)       ; $32  FIXME: not working with 4510:and (zp), z
    bit $12,x       ; $34
    dec a           ; $3a
    bit $1234,x     ; $3c
    eor ($12)       ; $52  FIXME: not working with 4510:eor (zp), z
    phy             ; $5a
    stz $12         ; $64
    adc ($12)       ; $72  FIXME: not working with 4510:adc (zp), z
    stz $12,x       ; $74
    ply             ; $7a
    jmp ($1234)     ; $7c
LABEL:
    bra LABEL       ; $80
    bit #$12        ; $89
    sta ($12)       ; $92  FIXME: not working with 4510:sta (zp), z
    stz $1234       ; $9c
    stz $1234,x     ; $9e
    lda ($12)       ; $b2  FIXME: not working with 4510:lda (zp), z
    cmp ($12)       ; $d2  FIXME: not working with 4510:cmp (zp), z
    phx             ; $da
    sbc ($12)       ; $f2  FIXME: not working with 4510:sbc (zp), z
    plx             ; $fa
    .endscope
.endif


; The R65C02 is a superset of the 65C02. It adds bit manipulation instructions:
.if (.cpu .bitand CPU_ISET_65C02)

    ; R65C02 instruction set adds some extra legal instructions to 65C02
    rmb0 $12            ; $07
    bbr0 $12, LABEL3    ; $0f
    rmb1 $12            ; $17
    bbr1 $12, LABEL3    ; $1f
    rmb2 $12            ; $27
    bbr2 $12, LABEL3    ; $2f
    rmb3 $12            ; $37
    bbr3 $12, LABEL3    ; $3f
    rmb4 $12            ; $47
    bbr4 $12, LABEL3    ; $4f
    rmb5 $12            ; $57
    bbr5 $12, LABEL3    ; $5f
    rmb6 $12            ; $67
    bbr6 $12, LABEL3    ; $6f
    rmb7 $12            ; $77
    bbr7 $12, LABEL3    ; $7f
LABEL3:
    smb0 $12            ; $87
    bbs0 $12, LABEL3    ; $8f
    smb1 $12            ; $97
    bbs1 $12, LABEL3    ; $9f
    smb2 $12            ; $a7
    bbs2 $12, LABEL3    ; $af
    smb3 $12            ; $b7
    bbs3 $12, LABEL3    ; $bf
    smb4 $12            ; $c7
    bbs4 $12, LABEL3    ; $cf
    smb5 $12            ; $d7
    bbs5 $12, LABEL3    ; $df
    smb6 $12            ; $e7
    bbs6 $12, LABEL3    ; $ef
    smb7 $12            ; $f7
    bbs7 $12, LABEL3    ; $ff

.endif


; The W65C02 is a superset of the R65C02. It only adds two instructions:
.if (.cpu .bitand CPU_ISET_W65C02)
    wai             ; $cb
    stp             ; $db
.endif


; The 65CE02 is another superset of the R65C02. It has several improvements:
.if (.cpu .bitand CPU_ISET_65CE02)
    .scope

    ; 65CE02 adds the following:
    cle                         ; $02
    see                         ; $03
    tsy                         ; $0b
    ora ($12), z                ; $12    (ora (zp) on 65C02)
    lbpl $1234                  ; $13
    inz                         ; $1b
    jsr ($1234)                 ; $22
    jsr ($1234,x)               ; $23
    tys                         ; $2b
    and ($12), z                ; $32    (and (zp) on 65C02)
    lbmi $1234                  ; $33
    dez                         ; $3b
    neg                         ; $42
    asr a                       ; $43
    asr $12                     ; $44
    taz                         ; $4b
    lbvc $1234                  ; $53
    asr $12,x                   ; $54
    tab                         ; $5b
    ;aug                        ; $5c FIXME: implement in assembler
    rtn #$12                    ; $62
    bsr $1234                   ; $63
    stz $12                     ; $64    (stores 0 on 65C02)
    tza                         ; $6b
    adc ($12), z                ; $72    (adc (zp) on 65C02)
    lbvs $1234                  ; $73
    stz $12, x                  ; $74    (stores 0 on 65C02)
    tba                         ; $7b
    sta ($12,s),y               ; $82
    lbra $1234                  ; $83
    sty $1234,x                 ; $8b
    lbcc $1234                  ; $93
    sta ($12), z                ; $92    (sta (zp) on 65C02)
    stx $1234,y                 ; $9b
    stz $1234                   ; $9c    (stores 0 on 65C02)
    ldz #$12                    ; $a3
    ldz $1234                   ; $ab
    lda ($12), z                ; $b2    (lda (zp) on 65C02)
    lbcs $1234                  ; $b3
    ldz $1234,x                 ; $bb
    cpz #$12                    ; $c2
    dew $12                     ; $c3
    cmp ($12), z                ; $d2    (cmp ($12) on 65C02)
    lbne $1234                  ; $d3
    cpz $12                     ; $d4
    cpz $1234                   ; $dc
    lda ($12,s),y               ; $e2
    inw $12                     ; $e3
    row $1234                   ; $eb
    sbc ($12), z                ; $f2    (sbc (zp) on 65C02)
    lbeq $1234                  ; $f3
    phw #$1234                  ; $f4
    plz                         ; $fb
    phw $1234                   ; $fc

    .endscope
.endif


; The 4510 is a superset of the 65CE02. Opcode 5c (originally a "4-byte NOP
; reserved for future expansion") has been changed to the "map" instruction,
; now using implied addressing.
;
; $5c  map
; $cb  asw abs
; $db  phz

.if (.cpu .bitand CPU_ISET_4510)
    .scope

    ; added to 65CE02
    map                         ; $5c   ("4-byte NOP reserved for future expansion" on 65CE02)
    eom                         ; $ea   "end of mapping" - but really just a NOP

    .endscope
.endif


; The 45GS02 instruction set extends the 4510 instruction set using prefix bytes.
; Therefore, the "normal" opcode table is the same as for the 4510 cpu

.if (.cpu .bitand CPU_ISET_45GS02)
    .scope

    orq $12          ; $42 $42 $05
    aslq $12         ; $42 $42 $06
    aslq             ; $42 $42 $0a
    orq $1234        ; $42 $42 $0d
    aslq $1234       ; $42 $42 $0e
    orq ($12)        ; $42 $42 $12
    aslq $12,x       ; $42 $42 $16
    inq              ; $42 $42 $1a
    aslq $1234,x     ; $42 $42 $1e
    bitq $12         ; $42 $42 $24
    andq $12         ; $42 $42 $25
    rolq $12         ; $42 $42 $26
    rolq             ; $42 $42 $2a
    bitq $1234       ; $42 $42 $2c
    andq $1234       ; $42 $42 $2d
    rolq $1234       ; $42 $42 $2e
    andq ($12)       ; $42 $42 $32
    rolq $12, x      ; $42 $42 $36
    deq              ; $42 $42 $3a
    rolq $1234, x    ; $42 $42 $3e
    asrq             ; $42 $42 $43
    asrq $12         ; $42 $42 $44
    eorq $12         ; $42 $42 $45
    lsrq $12         ; $42 $42 $46
    lsrq             ; $42 $42 $4a
    eorq $1234       ; $42 $42 $4d
    lsrq $1234       ; $42 $42 $4e
    eorq ($12)       ; $42 $42 $52
    asrq $12, x      ; $42 $42 $54
    lsrq $12, x      ; $42 $42 $56
    lsrq $1234, x    ; $42 $42 $5e
    adcq $12         ; $42 $42 $65
    rorq $12         ; $42 $42 $66
    rorq             ; $42 $42 $6a
    adcq $1234       ; $42 $42 $6d
    rorq $1234       ; $42 $42 $6e
    adcq ($12)       ; $42 $42 $72
    rorq $12, x      ; $42 $42 $76
    rorq $1234, x    ; $42 $42 $7e
    stq $12          ; $42 $42 $85
    stq $1234        ; $42 $42 $8d
    stq ($12)        ; $42 $42 $92
    ldq $12          ; $42 $42 $a5
    ldq $1234        ; $42 $42 $ad
    ldq ($12), z     ; $42 $42 $b2
    cmpq $12         ; $42 $42 $c5
    deq $12          ; $42 $42 $c6
    cmpq $1234       ; $42 $42 $cd
    deq $1234        ; $42 $42 $ce
    cmpq ($12)       ; $42 $42 $d2
    deq $12, x       ; $42 $42 $d6
    deq $1234, x     ; $42 $42 $de
    sbcq $12         ; $42 $42 $e5
    inq $12          ; $42 $42 $e6
    sbcq $1234       ; $42 $42 $ed
    inq $1234        ; $42 $42 $ee
    sbcq ($12)       ; $42 $42 $f2
    inq $12, x       ; $42 $42 $f6
    inq $1234, x     ; $42 $42 $fe

    ora [$12], z     ; $ea $12
    and [$12], z     ; $ea $32
    eor [$12], z     ; $ea $52
    adc [$12], z     ; $ea $72
    sta [$12], z     ; $ea $92
    lda [$12], z     ; $ea $b2
    cmp [$12], z     ; $ea $d2
    sbc [$12], z     ; $ea $f2

    orq [$12]        ; $42 $42 $ea $12
    andq [$12]       ; $42 $42 $ea $32
    eorq [$12]       ; $42 $42 $ea $52
    adcq [$12]       ; $42 $42 $ea $72
    stq [$12]        ; $42 $42 $ea $92
    ldq [$12], z     ; $42 $42 $ea $b2
    cmpq [$12]       ; $42 $42 $ea $d2
    sbcq [$12]       ; $42 $42 $ea $f2

    .endscope
.endif


; The HUC6280 is a superset of the R65C02. It adds some other instructions:

.if (.cpu .bitand CPU_ISET_HUC6280)
    .scope

    ; added to R65C02
    sxy                         ; $02
    st0 #$12                    ; $03
    st1 #$12                    ; $13
    sax                         ; $22
    st2 #$12                    ; $23
    say                         ; $42
    tma #$10                    ; $43
    bsr LABEL                   ; $44
    tam #$12                    ; $53
    csl                         ; $54
    cla                         ; $62
    tii $1234, $5678, $9abc     ; $73
LABEL:
    clx                         ; $82
    tst #$12, $34               ; $83
    clx                         ; $82
    tst #$12, $34               ; $83
    tst #$12, $3456             ; $93
    tst #$12, $34, x            ; $a3
    tst #$12, $3456, x          ; $b3
    cly                         ; $c2
    tdd $1234, $5678, $9abc     ; $c3
    tin $1234, $5678, $9abc     ; $d3
    csh                         ; $d4
    tia $1234, $5678, $9abc     ; $e3
    tai $1234, $5678, $9abc     ; $f3
    set                         ; $f4

    .endscope
.endif


.if (.cpu .bitand CPU_ISET_M740)
    .scope
    ; Mitsubishi M740 - adds new instructions to 65SC02 (but also removes some)

    jsr ($12)           ; $02
    bbs0 a, LABEL       ; $03
    bbs0 $12, LABEL     ; $07
    seb0 a              ; $0b
    seb0 $12            ; $0f
    bbc0 a, LABEL       ; $13
    bbc0 $12, LABEL     ; $17
    clb0 a              ; $1b
    clb0 $12            ; $1f
    jsr $ff12           ; $22
    bbs1 a, LABEL       ; $23
    bbs1 $12, LABEL     ; $27
    seb1 a              ; $2b
    seb1 $12            ; $2f
    bbc1 a, LABEL       ; $33
    bbc1 $12, LABEL     ; $37
    clb1 a              ; $3b
    clb1 $12            ; $3f
    stp                 ; $42
    bbs2 a, LABEL       ; $43
    com $12             ; $44
    bbs2 $12, LABEL     ; $47
    seb2 a              ; $4b
    seb2 $12            ; $4f
    bbc2 a, LABEL       ; $53
    bbc2 $12, LABEL     ; $57
    clb2 a              ; $5b
    clb2 $12            ; $5f
    bbs3 a, LABEL       ; $63
    bbs3 $12, LABEL     ; $67
    seb3 a              ; $6b
    seb3 $12            ; $6f
    bbc3 a, LABEL       ; $73
    bbc3 $12, LABEL     ; $77
    clb3 a              ; $7b
    clb3 $12            ; $7f
LABEL:
    rrf $12             ; $82
    bbs4 a, LABEL       ; $83
    bbs4 $12, LABEL     ; $87
    seb4 a              ; $8b
    seb4 $12            ; $8f
    bbc4 a, LABEL       ; $93
    bbc4 $12, LABEL     ; $97
    clb4 a              ; $9b
    clb4 $12            ; $9f
    bbs5 a, LABEL       ; $a3
    bbs5 $12, LABEL     ; $a7
    seb5 a              ; $ab
    seb5 $12            ; $af
    bbc5 a, LABEL       ; $b3
    bbc5 $12, LABEL     ; $b7
    clb5 a              ; $bb
    clb5 $12            ; $bf
    slw                 ; $c2
    bbs6 a, LABEL       ; $c3
    bbs6 $12, LABEL     ; $c7
    seb6 a              ; $cb
    seb6 $12            ; $cf
    bbc6 a, LABEL       ; $d3
    bbc6 $12, LABEL     ; $d7
    clb6 a              ; $db
    clb6 $12            ; $df
    fst                 ; $e2
    bbs7 a, LABEL       ; $e3
    bbs7 $12, LABEL     ; $e7
    seb7 a              ; $eb
    seb7 $12            ; $ef
    bbc7 a, LABEL       ; $f3
    bbc7 $12, LABEL     ; $f7
    clb7 a              ; $fb
    clb7 $12            ; $ff

    ; replaced from 65SC02
    clt                 ; $12
    set                 ; $32
    ldm $12, #$34       ; $3c
    tst $12             ; $64

    ; removed from 65SC02 (replaced by new)
    ; ora ($12)         ; $12
    ; and ($12)         ; $32
    ; bit $1234,x       ; $3c
    ; stz $12           ; $64

    ; removed from 65SC02
    ; tsb $12           ; $04
    ; tsb $1234         ; $0c
    ; trb $12           ; $14
    ; trb $1234         ; $1c
    ; bit $12,y         ; $34
    ; eor ($12)         ; $52
    ; phy               ; $5a
    ; adc ($12)         ; $72
    ; stz $12,y         ; $74
    ; ply               ; $7a
    ; jmp ($1234)       ; $7c
    ; bit #$12          ; $89
    ; sta ($12)         ; $92
    ; stz $1234         ; $9c
    ; stz $1234,x       ; $9e
    ; cmp ($12)         ; $d2
    ; phx               ; $da
    ; sbc ($12)         ; $f2
    ; plx               ; $fa

    .endscope
.endif

.if (.cpu .bitand CPU_ISET_65816)

    .smart  -                       ; Stop being smart

    .A8 ; akku 8 bit
    .I8 ; index registers 8 bit

    .scope
    cop $12             ; $02  coprocessor operation
    ora $12, s          ; $03
    ora [$12]           ; $07
    phd                 ; $0b  push direct page register
    ora $123456         ; $0f
    ora ($12, s), y     ; $13
    ora [$12], y        ; $17
    tcs                 ; $1b  transfer C to stack pointer
    ora $123456, x      ; $1f
    jsl $123456         ; $22
    and $12, s          ; $23
    and [$12]           ; $27
    pld                 ; $2b  pull direct page register
    and $123456         ; $2f
    and ($12, s), y     ; $33
    and [$12], y        ; $37
    tsc                 ; $3b  transfer stack pointer to C
    and $123456, x      ; $3f
    wdm $12             ; $42  (reserved for future expansion)
    eor $12, s          ; $43
    mvp $1234, $5678    ; $44
    eor [$12]           ; $47
    phk                 ; $4b  push program bank register
    eor $123456         ; $4f
    eor ($12, s), y     ; $53
    mvn $1234, $5678    ; $54
    eor [$12], y        ; $57
    tcd                 ; $5b  transfer C to direct page register
    jml $123456         ; $5c
    eor $123456, x      ; $5f
    per LABEL           ; $62  push effective relative address
    adc $12, s          ; $63
    adc [$12]           ; $67
    rtl                 ; $6b  return long (fetches 24-bit address from stack)
    adc $123456         ; $6f
    adc ($12, s), y     ; $73
    adc [$12], y        ; $77
    tdc                 ; $7b  transfer direct page register to C
    adc $123456, x      ; $7f
LABEL:
    brl LABEL           ; $82  branch long (16-bit offset)
    sta $12, s          ; $83
    sta [$12]           ; $87
    phb                 ; $8b  push data bank register
    sta $123456         ; $8f
    sta ($12, s), y     ; $93
    sta [$12], y        ; $97
    txy                 ; $9b  transfer X to Y
    sta $123456, x      ; $9f
    lda $12, s          ; $a3
    lda [$12]           ; $a7
    plb                 ; $ab  pull data bank register
    lda $123456         ; $af
    lda ($12, s), y     ; $b3
    lda [$12], y        ; $b7
    tyx                 ; $bb  transfer Y to X
    lda $123456, x      ; $bf
    rep #$12            ; $c2  clear bits in status register
    cmp $12, s          ; $c3
    cmp [$12]           ; $c7
    wai                 ; $cb  wait for interrupt
    cmp $123456         ; $cf
    cmp ($12, s), y     ; $d3
    pei ($12)           ; $d4  push effective indirect address
    cmp [$12], y        ; $d7
    stp                 ; $db  wait for reset
    jmp [$1234]         ; $dc
    cmp $123456, x      ; $df
    sep #$12            ; $e2  set bits in status register
    sbc $12, s          ; $e3
    sbc [$12]           ; $e7
    xba                 ; $eb  exchange high and low bytes of accumulator
    sbc $123456         ; $ef
    sbc ($12, s), y     ; $f3
    pea $1234           ; $f4  push effective absolute address
    sbc [$12], y        ; $f7
    xce                 ; $fb  exchange Carry and Emulation bits
    jsr ($1234, x)      ; $fc
    sbc $123456, x      ; $ff
    .endscope

    .A16 ; akku 16 bit
    .I16 ; index registers 16 bit

    .scope
    cop $12             ; $02  coprocessor operation
    ora $12, s          ; $03
    ora [$12]           ; $07
    phd                 ; $0b  push direct page register
    ora $123456         ; $0f
    ora ($12, s), y     ; $13
    ora [$12], y        ; $17
    tcs                 ; $1b  transfer C to stack pointer
    ora $123456, x      ; $1f
    jsl $123456         ; $22
    and $12, s          ; $23
    and [$12]           ; $27
    pld                 ; $2b  pull direct page register
    and $123456         ; $2f
    and ($12, s), y     ; $33
    and [$12], y        ; $37
    tsc                 ; $3b  transfer stack pointer to C
    and $123456, x      ; $3f
    wdm $12             ; $42  (reserved for future expansion)
    eor $12, s          ; $43
    mvp $1234, $5678    ; $44
    eor [$12]           ; $47
    phk                 ; $4b  push program bank register
    eor $123456         ; $4f
    eor ($12, s), y     ; $53
    mvn $1234, $5678    ; $54
    eor [$12], y        ; $57
    tcd                 ; $5b  transfer C to direct page register
    jml $123456         ; $5c
    eor $123456, x      ; $5f
    per LABEL           ; $62  push effective relative address
    adc $12, s          ; $63
    adc [$12]           ; $67
    rtl                 ; $6b  return long (fetches 24-bit address from stack)
    adc $123456         ; $6f
    adc ($12, s), y     ; $73
    adc [$12], y        ; $77
    tdc                 ; $7b  transfer direct page register to C
    adc $123456, x      ; $7f
LABEL:
    brl LABEL           ; $82  branch long (16-bit offset)
    sta $12, s          ; $83
    sta [$12]           ; $87
    phb                 ; $8b  push data bank register
    sta $123456         ; $8f
    sta ($12, s), y     ; $93
    sta [$12], y        ; $97
    txy                 ; $9b  transfer X to Y
    sta $123456, x      ; $9f
    lda $12, s          ; $a3
    lda [$12]           ; $a7
    plb                 ; $ab  pull data bank register
    lda $123456         ; $af
    lda ($12, s), y     ; $b3
    lda [$12], y        ; $b7
    tyx                 ; $bb  transfer Y to X
    lda $123456, x      ; $bf
    rep #$12            ; $c2  clear bits in status register
    cmp $12, s          ; $c3
    cmp [$12]           ; $c7
    wai                 ; $cb  wait for interrupt
    cmp $123456         ; $cf
    cmp ($12, s), y     ; $d3
    pei ($12)           ; $d4  push effective indirect address
    cmp [$12], y        ; $d7
    stp                 ; $db  wait for reset
    jmp [$1234]         ; $dc
    cmp $123456, x      ; $df
    sep #$12            ; $e2  set bits in status register
    sbc $12, s          ; $e3
    sbc [$12]           ; $e7
    xba                 ; $eb  exchange high and low bytes of accumulator
    sbc $123456         ; $ef
    sbc ($12, s), y     ; $f3
    pea $1234           ; $f4  push effective absolute address
    sbc [$12], y        ; $f7
    xce                 ; $fb  exchange Carry and Emulation bits
    jsr ($1234, x)      ; $fc
    sbc $123456, x      ; $ff
    .endscope

.endif

.if (.cpu .bitand CPU_ISET_SWEET16)

    RTN                 ; $00      Return to 6502 code.
    BR   LABEL          ; $01 ea   Unconditional Branch.
    BNC  LABEL          ; $02 ea   Branch if Carry=0.
    BC   LABEL          ; $03 ea   Branch if Carry=1.
    BP   LABEL          ; $04 ea   Branch if last result positive.
    BM   LABEL          ; $0S ea   Branch if last result negative.
    BZ   LABEL          ; $06 ea   Branch if last result zero.
    BNZ  LABEL          ; $07 ea   Branch if last result non-zero.
    BM1  LABEL          ; $08 ea   Branch if last result = -1.
    BNM1 LABEL          ; $09 ea   Branch if last result not -1.
    BK                  ; $0A      Execute 6502 BRK instruction.
    RS                  ; $0B      Return from SWEET-16 subroutine.
    BS   LABEL          ; $0C ea   Call SWEET-16 subroutine.
LABEL:

.repeat 16, count
    SET  count,$1234    ; $1n lo hi  Rn <-- value.
    LD   count          ; $2n        R0 <-- (Rn).
    ST   count          ; $3n        Rn <-- (R0).
    LD   @count         ; $4n        MA = (Rn), ROL <-- (MA), Rn <-- MA+1, R0H <-- 0.
    ST   @count         ; $5n        MA = (Rn), MA <-- (R0L), Rn <-- MA+1.
    LDD  @count         ; $6n        MA = (Rn), R0 <-- (MA, MA+1), Rn <-- MA+2.
    STD  @count         ; $7n        MA = (Rn), MA,MA+l <-- (R0), Rn <-- MA+2.
    POP  @count         ; $8n        MA = (Rn)-1, R0L <-- (MA), R0H <-- 0, Rn <-- MA.
    STP  @count         ; $9n        MA <-- (Rn)-1, (MA) <-- R0L, Rn <-- MA.
    ADD  count          ; $An        R0 <-- (R0) + (Rn).
    SUB  count          ; $Bn        R0 <-- (R0) - (Rn).
    POPD @count         ; $Cn        MA = (Rn)-2, MA,MA+l <-- R0, Rn <-- MA.
    CPR  count          ; $Dn        R13 <-- (R0) - (Rn), R14 <-- status flags.
    INR  count          ; $En        Rn <-- (Rn) + 1.
    DCR  count          ; $Fn        Rn <-- (Rn) - 1.
.endrepeat

.endif
