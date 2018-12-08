[BITS 64]

section .bss
  ; nada

section .data
  prompt:          db 'What is your name? '
  prompt_length:   equ $-prompt
  name:            times 20 db 0
  name_length:     equ $-name
  greeting:        db 'Greetings, '
  greeting_length: equ $-greeting

section .text
global _start
_start:
  ; Prompt the user for their name
  mov rax, 1                 ; '1' is the ID for the sys_write call
  mov rdi, 1                 ; '1' is the file descriptor for stdout and our first argument
  mov rsi, prompt            ; prompt string is the second argument
  mov rdx, 20
  ;mov rdx, prompt_length    ; prompt string length is the third argument
  syscall                    ; make the call with all arguments passed

  ; Get the user's name
  mov rax, 0                 ; 0 = sys_read
  mov rdi, 0                 ; 0 = stdin
  mov rsi, name
  mov rdx, name_length
  syscall
  push rax                   ; store return value (size of name) on the stack... we'll need this for later

  ; Print our greeting string
  mov rax, 1                 ; 1 = sys_write
  mov rdi, 1                 ; 1 = stdout
  mov rsi, greeting
  mov rdx, greeting_length
  syscall

  ; Print the user's name
  mov rax, 1                 ; 1 = sys_write
  mov rdi, 1                 ; 1 = stdout
  mov rsi, name
  pop rdx                    ; length previously returned by sys_read and stored on the stack
  syscall

  ; Exit the program normally
  mov rax, 60                ; 60 = sys_exit
  xor rdi, rdi               ; return code 0
  syscall
