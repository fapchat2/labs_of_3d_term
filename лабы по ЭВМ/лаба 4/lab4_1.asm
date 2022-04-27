;Задание No1. Написать программу, которая определяет в данном слове (4. BC68)
;(см. таблицу No1) содержимое разрядов i и i + 1 и формирует число К в виде:
;0, если i = 0 и i + 1 = 0
;К = 1, если i = 0 и i + 1 = 1
;2, если i = 1 и i + 1 = 0
;3, если i = 1 и i + 1 = 1,
;где i – номер варианта.

Chinik segment para 'code'
assume cs:Chinik,ds:Chinik,ss:Chinik,es:Chinik
org 100h ; пропускаем первые 256 байт (.com)
begin: jmp main
; это мои данные (переменные)
;---------------------------------
date dw ?
my_s db '+'
T_Th db ?
Th db ?
Hu db ?
Tens db ?
Ones db ?
;---------------------------------
A dw 068BCh 
OTV dw ?
MASKA dw 0000000000110000b
main proc near
mov ax,A
and ax,MASKA 
; первый вариант
cmp ax,0
jz m1
; второй вариант
cmp ax,10h
jz m2
cmp ax,20h
jz m3

mov OTV, 3 ; 0000 0000 0011 0000
jmp konec

m1: ; результат 0000 0000 0000 0000
mov OTV,0
jmp konec

m2: ; результат 0000 0000 0010 0000
mov OTV,1
jmp konec

m3: ; результат 0000 0000 0001 0000
mov OTV,2

konec: mov ax,OTV
mov date,ax
call disp
ret
main endp
;------------------------------------------

; Процедура выводит результат вычислений, помещенный в data
DISP proc near
;----- Вывод результата на экран ----------------
;--- Число отрицательное ?----------
mov ax,date
and ax,1000000000000000b
mov cl,15
shr ax,cl
cmp ax,1
jne @m1
mov ax,date
neg ax
mov my_s,'-'
jmp @m2
;--- Получаем десятки тысяч ---------------
@m1: mov ax,date
@m2: cwd
mov bx,10000
idiv bx
mov T_Th,al
;------- Получаем тысячи ------------------------------
mov ax,dx
cwd
mov bx,1000
idiv bx
mov Th,al
;------ Получаем сотни ---------------
mov ax,dx
mov bl,100
idiv bl
mov Hu,al
;---- Получаем десятки и единицы ----------------------
mov al,ah
cbw
mov bl,10
idiv bl
mov Tens,al
mov Ones,ah
;--- Выводим знак -----------------------
cmp my_s,'+'
je @m500
mov ah,02h
mov dl,my_s
int 21h
;---------- Выводим цифры -----------------
@m500: cmp T_TH,0 ; проверка на ноль
je @m200

mov ah,02h ; выводим на экран, если не ноль
mov dl,T_Th
add dl,48
int 21h
@m200: cmp T_Th,0
jne @m300
cmp Th,0
je @m400
@m300: mov ah,02h
mov dl,Th
add dl,48
int 21h
@m400: cmp T_TH,0
jne @m600
cmp Th,0
jne @m600
cmp hu,0
je @m700
@m600: mov ah,02h
mov dl,Hu
add dl,48
int 21h
@m700: cmp T_TH,0
jne @m900
cmp Th,0
jne @m900
cmp Hu,0
jne @m900
cmp Tens,0
je @m950
@m900: mov ah,02h
mov dl,Tens
add dl,48
int 21h
@m950: mov ah,02h
mov dl,Ones
add dl,48
int 21h
mov ah,02h
mov dl,10
int 21h
mov ah,02h

mov dl,13
int 21h
;-------------------------------------
mov ah,08
int 21h
ret
DISP endp

Chinik ends
end begin