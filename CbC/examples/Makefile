CC=gcc
#MCC=./mcc
#MCC=mc-mips
MCC=mc-ia32
TARGET=first hello_mod separate dumparg arg arg-c dumparg-struct struct struct2 deep-nested-struct code-ptr-array func-ptr-array struct-ptr-arg for struct-align struct-array struct-array2 struct-mips struct-interface symbol symbol-c symbol-gcc symbol-mcc

MCCFLAGS=-s
CFLAGS=-g -Wall

#%.o: %.c
#.SUFFIXES:  .c .o .s #.d
.SUFFIXES:  .c .o

.c.o:
	$(MCC) -s $<
	$(CC) $(CFLAGS) -o $@ -c $(<:.c=.s)

all: $(TARGET)

dbg.o:dbg.c
	$(CC) $(CFLAGS) -o $@ -c $<

struct-interface:struct-interface.o dbg.o
	$(CC) -o $@ $^

struct-array2:struct-array2.o
	$(CC) -o $@ $^

struct-array: struct-array.o
	$(CC) -o $@ $^

struct-align: struct-align.o
	$(CC) -o $@ $^

for: for.o
	$(CC) -o $@ $^

first: first.o
	$(CC) -o $@ $^

hello_mod.o:hello_mod.c
	$(CC) -o $@ -c $<

hello_mod: call.o hello_mod.o
	$(CC) -o $@ $^

separate_sp.o: separate_sp.c
	$(CC) -o $@ -c $<

separate: separate_sp.o separate.o
	$(CC) -o $@ $^

arg: arg.o
	$(CC) -o $@ $^

arg-c.o: arg-c.c
	$(CC) $(CFLAGS) -o $@ -c $<

arg-c: arg-c.o
	$(CC) -o $@ $^

dumparg: dumparg.o
	$(CC) -o $@ $^

dumparg-struct: dumparg-struct.o
	$(CC) -o $@ $^

struct: struct.o
	$(CC) -o $@ $^

struct2: struct2.o
	$(CC) -o $@ $^

struct-c.o: struct-c.c
	$(CC) -o $@ -c $<

struct-c: struct-c.o
	$(CC) -o $@ $^

asm-studies: asm-studies.o
	$(CC) -o $@ $^

deep-nested-struct: deep-nested-struct.o
	$(CC) -o $@ $^
struct-ptr-arg: struct-ptr-arg.o
	$(CC) -o $@ $^
move:move.o
	$(CC) -o $@ $^

funcptr-ptr-array: funcptr-ptr-array.o
	$(CC) -o $@ $^

code-ptr-array:code-ptr-array.o
	$(CC) -o $@ $^

struct-mips: struct-mips.o
	$(CC) -o $@ $^

symbol:symbol.o
	$(CC) -o $@ $^

symbol-gcc.o:symbol-c.c
	$(CC) $(CFLAGS) -c -o $@ $<

symbol-gcc:symbol-gcc.o
	$(CC) -o $@ $^

symbol-mcc.o:symbol-c.c
	$(MCC) -s $<
	$(CC) $(CFLAGS) -c -o $@ $(<:.c=.s)

symbol-mcc:symbol-mcc.o
	$(CC) -o $@ $^

clean:
	rm -f $(TARGET)
	rm -f *.s *.o *.d *.i a.out
