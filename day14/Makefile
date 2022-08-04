# 定义变量
src=$(wildcard ./*.c)
objs=$(patsubst %.c,%.o,$(src))
target=app

# $(target):$(src)
# 	$(CC) $(src) -o $(target)    

# module: module.c module.h
# 	$(CC) module.c -o module

all: unpackhuf createhuf

%.o: %.c
	$(CC) -c $< -o $@

unpackhuf: unpackhuf.o

createhuf: createhuf.o test_freqhuf_createhuf.o test_buildhuftree_createhuf.o

clean:
	rm $(objs) -f

