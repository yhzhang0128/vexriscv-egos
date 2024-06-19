RISCV_CC      = riscv64-unknown-elf-gcc -march=rv32ima
RISCV_OBJCOPY = riscv64-unknown-elf-objcopy
RISCV_OBJDUMP = riscv64-unknown-elf-objdump

LDFLAGS       = -nostdlib -lc -lgcc
CFLAGS 				= -mabi=ilp32 -Wl,--gc-sections -ffunction-sections -fdata-sections -fdiagnostics-show-option
DEBUG_FLAGS   = --source --all-headers --demangle --line-numbers --wide

elf:
	$(RISCV_CC) $(CFLAGS) hello.s hello.c -Thello.lds $(LDFLAGS) -o ./linker/hello.elf
	$(RISCV_OBJDUMP) $(DEBUG_FLAGS) ./linker/hello.elf > ./linker/hello.lst

bin: elf
	$(RISCV_OBJCOPY) -O binary ./linker/hello.elf hello.bin

run: bin
	./run.sh

clean:
	rm -r ./linker/*.elf ./linker/*.lst *.bin