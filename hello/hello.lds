OUTPUT_ARCH("riscv")

ENTRY(hello_entry)

MEMORY 
{
  ram (rwx) : ORIGIN = 0x40F00000, LENGTH = 0x1000
}

SECTIONS
{
  .text : { 
    *(.text.hello_entry) 
    *(.text.*)
  } >ram

  .data : {
    *(.data)
  } >ram

  .bss (NOLOAD) : {
    *(.bss)
  } >ram
}