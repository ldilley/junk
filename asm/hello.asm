section .data
  thing db "Hello world!" ; literal constant

section .text
  extern exit    ; refer to external function exit()
  extern puts    ; refer to external function puts()

global _start
_start:
  mov edi, thing ; edi always holds first arg
  call puts      ; puts(thing);
  ;mov ebx, 0    ; sys_exit() looks at ebx for args -- zero means nothing went wrong
  ;mov eax, 1    ; 1 is the table entry for sys_exit()
  ;int 0x80      ; call sys_exit(0);
  mov edi, 0
  call exit
