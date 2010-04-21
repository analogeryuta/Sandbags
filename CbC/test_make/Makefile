CC = gcc
CFLAGS = -g -O2 -Wall

MC = mc-powerpc
MCFLAGS = -s

TARGET = main
SRCS = extern_value_main.c extern_value1.c extern_value2.c
OBJS = $(SRCS:.c=.o)

#サフィックスルールによる.oファイル生成．
#ここでの "$@" は, file.s から生成する file.o を示す
.SUFFIXES: .c .o

.c.o:
	$(MCC) $(MCFLAGS) $<
	$(CC) $(CFLAGS) -o $@ -c $(<:.c=.s)

clean:
	-rm -f $(TARGET)
	-rm -f *.s *.o
	-rm -f *~
tags:
	etags *.[ch]
depend:
	makedepend -- $(CFLAGS) -- $(SRCS) $(MAINSRC)
