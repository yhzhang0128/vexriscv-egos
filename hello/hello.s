  .section .text.entry
  .global hello_entry

hello_entry:
  li sp, 0x40008000 /* 8 KB Stack */
  call main
  j loop

loop:
  beq x0, x0, loop
