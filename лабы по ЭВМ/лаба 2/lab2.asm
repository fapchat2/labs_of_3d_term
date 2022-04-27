CODESG SEGMENT PARA; CODESG - название сегмента. SEGMENT - обозначение начала сегмента
ASSUME CS:CODESG, DS:CODESG, SS:CODESG, ES:CODESG; ASSUME позволяет использовать сегменты как сегменты кода, данных или стека. CS:CODESG - сегмент кода CODESG. 				
;DS - Сегмент данных. SS - Сегмент стека. ES - дополнительный сегмент, и может не использоваться программой
ORG 100H ; Директива org 100H говорит компилятору что всю адресацию внутри кода нужно сместить именно на эти 100 байт(нужно для того, чтобы можно было указывать реальные адреса)
BEGIN: JMP MAIN ; JMP MAIN выполняет безусловный переход в MAIN

A101 DB ?
A102 DB 'LAND VENTURE'
A103 DB 115
A104 DB 50H
A105 DB 10000100B
A106 DB 03,'KJH',09,'HKL',07,'SQW'
A107 DB '456753'
A108 DB 9 DUP(0)
B101 DW 0CDF3H
B102 DW 10101001B
B103 DW A103
B104 DW 2,5,7,9,11
B105 DW 6 DUP(0)
C101 DD ?
C102 DD 'IT'
C103 DD 32240
C104 DD A103-A102
C105 DD 14,43
D101 DQ ?
D102 DQ 05D35H
D103 DQ 32240
E101 DT ?
E102 DT 'UN'

MAIN PROC NEAR

mov ah,09h
mov dx,offset A102
int 21h

RET; команда RET выполняет выход из программы или процедуры

MAIN ENDP
CODESG ENDS; CODESG ends - конец сегмента CODESG
END BEGIN