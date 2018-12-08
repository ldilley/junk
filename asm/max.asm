section .data
  array db 3, 67, 34, 222, 45, 4, 7, 10, 51, 19

section .text
  extern exit

global _start
_start:
  mov rdi, 0
  mov eax, [array + rdi * 4]
  mov ebx, eax

start_loop:
  cmp eax, 0
  je loop_exit
  inc rdi
  mov eax, [array + rdi * 4]
  cmp eax, ebx
  jle start_loop
  mov ebx, eax
  jmp start_loop

loop_exit:
  mov eax, 1
  call exit
