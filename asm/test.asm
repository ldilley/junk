section .data
  mystring db "I like pie"

section .text
  extern puts
  extern exit

global _start
_start:
  mov rdi, mystring
  call puts
  mov rdi, 0
  call exit
