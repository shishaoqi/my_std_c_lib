CC  := gcc
CFLAGS  := -w -std=gnu99 -ggdb -ffunction-sections # -w:关闭所有告警
CFLAGS  := -g -I. $(CCFLAGS)
SRCS    := $(wildcard *.c) # 当前目录下的所有的.c文件 
OBJS    := $(SRCS:.c=.o) # 将所有的.c文件名替换为.o
REDISLIB	:= libredis.a

all:$(REDISLIB) gccs

# ***************************************************************
# C compilations
smalloc.o: smalloc.c smalloc.h except.h assert.h
	$(CC) $(CFLAGS) -c smalloc.c

simpio.o: simpio.c simpio.h strlib.h smalloc.h
	$(CC) $(CFLAGS) -c simpio.c

strlib.o: strlib.c strlib.h smalloc.h
	$(CC) $(CFLAGS) -c strlib.c

random.o: random.c random.h
	$(CC) $(CFLAGS) -c random.c

$(REDISLIB):$(OBJS)
	-rm -f $(REDISLIB)
	ar cr $(REDISLIB) $(OBJS)
	ranlib $(REDISLIB)

# ***************************************************************
# Entry to reconstruct the gccs script

gccs: makefile
	@echo '#! /bin/csh -f' > gccs
	@echo 'set INCLUDE =' `pwd` >> gccs
	@echo 'set REDISLIB = $$INCLUDE/libredis.a' >> gccs
	@echo 'set LIBRARIES = ($$REDISLIB)' >> gccs
	@echo 'foreach x ($$*)' >> gccs
	@echo '  if ("x$$x" == "x-c") then' >> gccs
	@echo '    set LIBRARIES = ""' >> gccs
	@echo '    break' >> gccs
	@echo '  endif' >> gccs
	@echo 'end' >> gccs
	@echo 'gcc -g -I$$INCLUDE $$* $$LIBRARIES' >> gccs
	@chmod a+x gccs
	@echo '[gccs script created]'

clean:
	rm -f *.o
	rm -f $(BINS)
	rm -f $(REDISLIB)
	rm -f gccs
