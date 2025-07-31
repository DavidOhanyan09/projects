CC = clang
AS = clang
LD = ld
OBJCOPY = objcopy
QEMU = qemu-system-i386

CFLAGS = -m16 -ffreestanding -fno-stack-protector -nostdlib
ASFLAGS = -m16 -ffreestanding -fno-stack-protector -nostdlib
LDFLAGS = -m elf_i386 -T test.ld

all: test.bin floppy.img

test.o: test.c
	$(CC) $(CFLAGS) -c test.c -o test.o

asm.o: test.S
	$(CC) $(ASFLAGS) -c  test.S -o asm.o

test.elf: test.o asm.o
	$(LD) $(LDFLAGS)  test.o -o test.elf

test.bin: test.elf
	$(OBJCOPY) -O binary test.elf test.bin

floppy.img: test.bin
	dd if=/dev/zero of=floppy.img bs=512 count=2880
	dd if=test.bin of=floppy.img conv=notrunc

run: floppy.img
	$(QEMU) -fda floppy.img

clean:
	rm -f *.o *.elf *.bin floppy.img
