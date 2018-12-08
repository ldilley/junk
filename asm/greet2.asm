[BITS 64]

section .bss
  clear_buffer resb 1

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
  mov rax, 1                  ; '1' is the ID for the sys_write call
  mov rdi, 1                  ; '1' is the file descriptor for stdout and our first argument
  mov rsi, prompt             ; prompt string is the second argument
  mov rdx, 20
  ;mov rdx, prompt_length     ; prompt string length is the third argument
  syscall                     ; make the call with all arguments passed

  ; Get the user's name
  mov rax, 0                  ; 0 = sys_read
  mov rdi, 0                  ; 0 = stdin
  mov rsi, name
  mov rdx, name_length
  syscall
  push rax                    ; store return value (size of name) on the stack... we'll need this for later

  cmp rax, name_length        ; compare read size to maximum length
  jl input_ok                 ; if read size is less than max length, things are OK

  cmp byte [name + name_length - 1], 10 ; check if last character is a newline (0x10)
  je input_ok                           ; if last char is a newline, things are OK

  ; Otherwise, prevent excess characters from being interpreted by the shell
  mov byte [name + name_length - 1], 10 ; append a newline (0x10)
  call trim
  jmp input_ok

trim:
  mov rax,
  ;mov rax, 0                 ; 0 = sys_read
  ;mov rdi, 1                 ; 1 = stdin
  ;mov rsi, clear_buffer
  ;mov rdx, 1                 ; length
  ;syscall
  ;cmp byte [rsi + rdx - 1], 10 ; check for newline (0x10)
  ;jne trim
  ;ret

input_ok:
  ; Print our greeting string
  mov rax, 1                  ; 1 = sys_write
  mov rdi, 1                  ; 1 = stdout
  mov rsi, greeting
  mov rdx, greeting_length
  syscall

  ; Print the user's name
  mov rax, 1                  ; 1 = sys_write
  mov rdi, 1                  ; 1 = stdout
  ;mov byte [r15+20], 10 ; newline
  mov rsi, name
  pop rdx                     ; length previously returned by sys_read and stored on the stack
  syscall

  ; Exit the program normally
  mov rax, 60                 ; 60 = sys_exit
  xor rdi, rdi                ; return code 0
  syscall
