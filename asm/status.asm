section .data
  ; no vars
section .text
  extern exit
global _start
_start:
  mov rax, 1 ; exit()
  mov rdi, 0 ; return code
  call exit
