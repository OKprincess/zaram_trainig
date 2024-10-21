# ---------------------------------------------------------
#	Makefile Example for RV32I
# ---------------------------------------------------------

.SUFFIXES:
CC		= riscv64-unknown-linux-gnu-gcc
OBJDUMP	= riscv64-unknown-linux-gnu-objdump
CFLAGS	= -march=rv32im -mabi=lip32

%.i:	%.c
	$(CC)				-E $<	-o $@

%.s:	%.i
	$(CC)	$(CFLAGS)	-S $<	-o $@

%.o:	%.s
	$(CC)	$(CFLAGS)	-c $<	-o $@

%:		%.o
	$(CC)	$(CFLAGS)	-static $<	-o $@

%.dump:	%.o
	$(OBJDUMP)		-d --visualize-jumps -M no-aliases $<	> $@

all:	program	program.dump

program.i:	program.c
program.s:	program.i
program.o:	program.s
program:	program.o

build:
	$(CC)	-o program	program.c --save-temps

clean:
	$(RM)	*.i *.s *.o *.dump program
