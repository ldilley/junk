; This small program attempts to fill up the operating system process
; table and exhaust physical memory which will make a Linux/Unix system
; very slow or even crash. This program should not be used on production
; systems. This is only an educational program intended to demonstrate
; the need to implement resource limits. Use at your own risk!

section .data
  which db "PRIO_PROCESS"

section .text
  extern setpriority
  extern fork
  extern malloc

global _start
_start:
  mov rdi, which
  mov rsi, 0       ; who
  mov rdx, 19      ; priority
  call setpriority

  mov rcx, 10
  mov r8d, 10000000
  mov r9d, 1
  outer_loop:
    call fork
    inner_loop:
      dec r8d
      jnz inner_loop
    eat_memory:
      mov rdi, 40  ; 10 * 4 bytes (32-bit integers)
      call malloc
  loop outer_loop
