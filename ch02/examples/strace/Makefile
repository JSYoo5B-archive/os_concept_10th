CC?=gcc
# Add static flag to prevent linking shared objects
CFLAGS=-static -g

all: fork exec exit open read write close mmap malloc

fork: fork.c
	$(CC) -o $@ $< $(CFLAGS)

hello: hello.c
	$(CC) -o $@ $< $(CFLAGS)

exec: exec.c hello
	$(CC) -o exec exec.c $(CFLAGS)

exit: exit.c
	$(CC) -o $@ $< $(CFLAGS)

open: open.c
	$(CC) -o $@ $< $(CFLAGS)

read: read.c
	$(CC) -o $@ $< $(CFLAGS)

write: write.c
	$(CC) -o $@ $< $(CFLAGS)

close: close.c
	$(CC) -o $@ $< $(CFLAGS)

mmap: mmap.c
	$(CC) -o $@ $< $(CFLAGS)

malloc: malloc.c
	$(CC) -o $@ $< $(CFLAGS)

blank: blank.c
	$(CC) -o $@ $< $(CFLAGS)

clean:
	rm -f fork
	rm -f hello exec
	rm -f exit
	rm -f open
	rm -f read
	rm -f write
	rm -f close
	rm -f mmap
	rm -f malloc
	rm -f blank
