org 0x0
bits 16

%define ENDL 0x0D, 0x0A


start:
    ; print message
    mov si, msg_hello
    call puts

.halt:
    cli
    hlt





;
; Prints a string to the screen
; Params:
;   - ds:si points to string
;
puts:
    ; save registers we will modify
    push si
    push ax
    push bx

.loop:
    lodsb                       ; loads next character
    or al, al                   ; verify if next character is null
    jz .done                    ; if char is null, goto done

    mov ah, 0x0e                ; set interupt type to tty
    mov bh, 0                   ; set page number to 0
    int 0x10                    ; call bios interrupt

    jmp .loop                   ; loop again

.done: 
    pop bx
    pop ax
    pop si
    ret



msg_hello: db 'Kernel Loaded!!!', ENDL, 0
