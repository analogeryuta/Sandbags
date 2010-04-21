
.SUFFIX =  .java .html

HTML = schedularSimulator/Event.java.html schedularSimulator/EventInterface.java.html schedularSimulator/PeriodicalRun.java.html schedularSimulator/RateMonotonicEvent.java.html schedularSimulator/Run.java.html schedularSimulator/Task.java.html 

all: 
	javac -encoding utf-8 sche*/*.java

html: $(HTML)

tar:
	make clean
	-rm -rf os-queue-java.tgz
	(cd ..; tar zcf os-queue-java.tgz os-queue-java --exclude CVS )
	mv ../os-queue-java.tgz .


.java.html:
	c2html.pl $^ > $@

debug: os-queue
	gdb os-queue

debug-sim: os-queue
	gdb os-queue

depend: 
	makedepend ${SRC} ${SIM_SRC}

clean:

