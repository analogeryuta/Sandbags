QUEUE = queue.o
# QUEUE = queue_pool.o
EVENT = event.o
# EVENT = event_pool.o
TASK = task.o

SRC = main.c queue.c queue_pool.c task.c 
SIM_SRC = simulate.c event.c event_pool.c

.SUFFIX =  .c .html

HTML = main.c.html queue.c.html queue_pool.c.html task.c.html simulate.c.html event.c.html event_pool.c.html

CFLAGS = -g -Wall

all: os-queue os-simulate

html: $(HTML)

tar:
	make clean
	-rm -rf os-queue.tar
	(cd ..; tar cf os-queue.tar os-queue)
	mv ../os-queue.tar .

os-queue: main.o ${QUEUE} ${TASK}
	$(CC) $(CFLAGS) -o $@ $^

os-simulate: simulate.o ${QUEUE} ${EVENT} ${TASK}
	$(CC) $(CFLAGS) -o $@ $^

test: test-queue test-sim

test-queue: os-queue
	./os-queue < data/task_data.01

test-sim: os-simulate
	./os-simulate < data/task_data.p1

test-view: os-simulate os-queue
	./os-queue < data/task_data.02 | perl view_task.pl
	./os-simulate < data/task_data.p1 | perl view_task.pl -t

.c.html:
	c2html.pl $^ > $@

debug: os-queue
	gdb os-queue

debug-sim: os-queue
	gdb os-queue

depend: 
	makedepend ${SRC} ${SIM_SRC}
tags:
	etags *.[ch]

clean:
	rm -f *.bak *.o os-queue os-simulate */*.bak TAGS


#
# DO NOT DELETE

main.o: /usr/include/stdio.h /usr/include/_types.h /usr/include/sys/_types.h
main.o: /usr/include/sys/cdefs.h /usr/include/machine/_types.h
main.o: /usr/include/i386/_types.h /usr/include/stdlib.h
main.o: /usr/include/sys/wait.h /usr/include/sys/signal.h
main.o: /usr/include/sys/appleapiopts.h /usr/include/machine/signal.h
main.o: /usr/include/i386/signal.h /usr/include/sys/resource.h
main.o: /usr/include/machine/endian.h /usr/include/i386/endian.h
main.o: /usr/include/sys/_endian.h /usr/include/stdint.h
main.o: /usr/include/libkern/OSByteOrder.h
main.o: /usr/include/libkern/i386/OSByteOrder.h /usr/include/alloca.h
main.o: /usr/include/machine/types.h /usr/include/i386/types.h
main.o: /usr/include/strings.h /usr/include/string.h queue.h task.h
queue.o: /usr/include/stdio.h /usr/include/_types.h /usr/include/sys/_types.h
queue.o: /usr/include/sys/cdefs.h /usr/include/machine/_types.h
queue.o: /usr/include/i386/_types.h /usr/include/stdlib.h
queue.o: /usr/include/sys/wait.h /usr/include/sys/signal.h
queue.o: /usr/include/sys/appleapiopts.h /usr/include/machine/signal.h
queue.o: /usr/include/i386/signal.h /usr/include/sys/resource.h
queue.o: /usr/include/machine/endian.h /usr/include/i386/endian.h
queue.o: /usr/include/sys/_endian.h /usr/include/stdint.h
queue.o: /usr/include/libkern/OSByteOrder.h
queue.o: /usr/include/libkern/i386/OSByteOrder.h /usr/include/alloca.h
queue.o: /usr/include/machine/types.h /usr/include/i386/types.h queue.h
queue_pool.o: /usr/include/stdio.h /usr/include/_types.h
queue_pool.o: /usr/include/sys/_types.h /usr/include/sys/cdefs.h
queue_pool.o: /usr/include/machine/_types.h /usr/include/i386/_types.h
queue_pool.o: /usr/include/stdlib.h /usr/include/sys/wait.h
queue_pool.o: /usr/include/sys/signal.h /usr/include/sys/appleapiopts.h
queue_pool.o: /usr/include/machine/signal.h /usr/include/i386/signal.h
queue_pool.o: /usr/include/sys/resource.h /usr/include/machine/endian.h
queue_pool.o: /usr/include/i386/endian.h /usr/include/sys/_endian.h
queue_pool.o: /usr/include/stdint.h /usr/include/libkern/OSByteOrder.h
queue_pool.o: /usr/include/libkern/i386/OSByteOrder.h /usr/include/alloca.h
queue_pool.o: /usr/include/machine/types.h /usr/include/i386/types.h queue.h
task.o: /usr/include/stdio.h /usr/include/_types.h /usr/include/sys/_types.h
task.o: /usr/include/sys/cdefs.h /usr/include/machine/_types.h
task.o: /usr/include/i386/_types.h /usr/include/stdlib.h
task.o: /usr/include/sys/wait.h /usr/include/sys/signal.h
task.o: /usr/include/sys/appleapiopts.h /usr/include/machine/signal.h
task.o: /usr/include/i386/signal.h /usr/include/sys/resource.h
task.o: /usr/include/machine/endian.h /usr/include/i386/endian.h
task.o: /usr/include/sys/_endian.h /usr/include/stdint.h
task.o: /usr/include/libkern/OSByteOrder.h
task.o: /usr/include/libkern/i386/OSByteOrder.h /usr/include/alloca.h
task.o: /usr/include/machine/types.h /usr/include/i386/types.h
task.o: /usr/include/strings.h /usr/include/string.h queue.h task.h
simulate.o: /usr/include/stdio.h /usr/include/_types.h
simulate.o: /usr/include/sys/_types.h /usr/include/sys/cdefs.h
simulate.o: /usr/include/machine/_types.h /usr/include/i386/_types.h
simulate.o: /usr/include/stdlib.h /usr/include/sys/wait.h
simulate.o: /usr/include/sys/signal.h /usr/include/sys/appleapiopts.h
simulate.o: /usr/include/machine/signal.h /usr/include/i386/signal.h
simulate.o: /usr/include/sys/resource.h /usr/include/machine/endian.h
simulate.o: /usr/include/i386/endian.h /usr/include/sys/_endian.h
simulate.o: /usr/include/stdint.h /usr/include/libkern/OSByteOrder.h
simulate.o: /usr/include/libkern/i386/OSByteOrder.h /usr/include/alloca.h
simulate.o: /usr/include/machine/types.h /usr/include/i386/types.h
simulate.o: /usr/include/strings.h /usr/include/string.h queue.h event.h
simulate.o: task.h
event.o: /usr/include/stdio.h /usr/include/_types.h /usr/include/sys/_types.h
event.o: /usr/include/sys/cdefs.h /usr/include/machine/_types.h
event.o: /usr/include/i386/_types.h /usr/include/stdlib.h
event.o: /usr/include/sys/wait.h /usr/include/sys/signal.h
event.o: /usr/include/sys/appleapiopts.h /usr/include/machine/signal.h
event.o: /usr/include/i386/signal.h /usr/include/sys/resource.h
event.o: /usr/include/machine/endian.h /usr/include/i386/endian.h
event.o: /usr/include/sys/_endian.h /usr/include/stdint.h
event.o: /usr/include/libkern/OSByteOrder.h
event.o: /usr/include/libkern/i386/OSByteOrder.h /usr/include/alloca.h
event.o: /usr/include/machine/types.h /usr/include/i386/types.h queue.h
event.o: event.h
event_pool.o: /usr/include/stdio.h /usr/include/_types.h
event_pool.o: /usr/include/sys/_types.h /usr/include/sys/cdefs.h
event_pool.o: /usr/include/machine/_types.h /usr/include/i386/_types.h
event_pool.o: /usr/include/stdlib.h /usr/include/sys/wait.h
event_pool.o: /usr/include/sys/signal.h /usr/include/sys/appleapiopts.h
event_pool.o: /usr/include/machine/signal.h /usr/include/i386/signal.h
event_pool.o: /usr/include/sys/resource.h /usr/include/machine/endian.h
event_pool.o: /usr/include/i386/endian.h /usr/include/sys/_endian.h
event_pool.o: /usr/include/stdint.h /usr/include/libkern/OSByteOrder.h
event_pool.o: /usr/include/libkern/i386/OSByteOrder.h /usr/include/alloca.h
event_pool.o: /usr/include/machine/types.h /usr/include/i386/types.h queue.h
event_pool.o: event.h
