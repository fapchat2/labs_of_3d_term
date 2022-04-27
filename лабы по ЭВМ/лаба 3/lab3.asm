; x=3*5 + (1982-1857)/25+497
wow segment 'code'
assume cs:wow, ds:wow, ss:wow, es:wow
org 100h
begin: jmp main
;---------------------------------
date dw ?
my_s db '+'
T_Th db ?
Th db ?
Hu db ?
Tens db ?
Ones db ?
;---------------------------------
; Переменные программы
T dw ?
MAIN proc near
; Команды программы
; x= (125/25)+(13-5)/4*5 + 553

mov ax,125
cwd
mov bx,25
idiv bx; (125/25)
mov T,ax

mov ax,13
sub ax,5
cwd  ; 13-5
mov bx,4 
idiv bx ; (13-5)/4
mov bx,5
imul bx 
add T,ax

mov ax, 553
add ax, T

mov date,ax
call disp

; -----------------------------------------

; y= (25+15)*(144-4)/(75-5) + 2 * 10 * (115-15)/100

mov ax,25
add ax,15
cwd
mov bx,144
sub bx,4
imul bx
cwd
mov bx,75
sub bx,5
idiv bx
mov T,ax

mov ax, 2
mov ax, 10
imul ax
cwd
mov bx, 115
sub bx, 15
imul bx
mov bx, 100
idiv bx
add T,ax


mov date,ax
call disp
ret
MAIN endp

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
wow ends
end begin