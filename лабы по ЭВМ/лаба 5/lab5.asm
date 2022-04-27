dnd segment 'code'
assume cs:dnd, ds:dnd, ss:dnd, es:dnd
org 100h
begin: jmp main


date dw ?
my_s db '+'
T_Th db ?
Th db ?
Hu db ?
Tens db ?
Ones db ?
;-------Данные -------------------
n dw 40 ; количество разбиений
s dw 0 ; текущее значение суммы(интегралла)
a dw -20 ; начало отрезка
b dw 20 ; конец отрезка
x dw ? ; текущая точка
t dw ?
;---------------------------------
main proc near
;-------Команды программы --------
mov ax,a ; задаем начальную точку
mov x,ax ;нужен -x
mov cx,39 ; счетчик цикла
m1:
; считаем f(x), т.е. в текущей точке
imul x
cwd 
mov bx,-1
imul bx 
add ax,3
add s,ax ; наращиваем сумму(интеграл)
add x,1 ; переходим к следующей точке
mov ax,x ;

loop m1
;---------------------------------
mov ax,s
cwd ; dx:ax=s
mov bx,20
idiv bx ; s/20 --> ax
mov s,ax

mov date,ax
call DISP

ret
main endp





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


dnd ends
end begin