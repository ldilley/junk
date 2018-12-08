section .data
  hexstr db "0x10h"

section .text
  extern puts
  extern exit

global _start
_start:
  mov rcx, 10
  iter:
    push rcx
    mov rdi, hexstr
    call puts
    pop rcx
  loop iter
  mov rdi, 0
  call exit
