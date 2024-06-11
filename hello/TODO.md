If you run `step0/1/2.sh` in the root dir, you will be able to run Linux on the Arty board.
Read `step2.sh` and `linux/boot.json` to get a sense of how `step2.sh` loads the Linux image into the Arty board.
The goal here is to compile a simple `hello-world` binary and use the command in `step2.sh` to load the hello-world instead of Linux.
The rough steps are:

* Read the [liteuart driver in Linux](https://github.com/torvalds/linux/blob/master/drivers/tty/serial/liteuart.c)
* Add a simple `hello.c` in this directory
* Add a linker script (hello.lds) similar to, say, [earth.lds](https://github.com/yhzhang0128/egos-2000/blob/main/earth/earth.lds) in egos-2000
* With the linker script, compile `hello.c` into a binary (bin instead of elf, see how the [egos-2000 Makefile](https://github.com/yhzhang0128/egos-2000/blob/main/Makefile#L61) creates `earth.bin`)
* Add a similar `boot.json` here; load and run the hello-world binary on the Arty board
