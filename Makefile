
CFLAGS = -Wall -g
LDFLAGS = -g

leak-example : leak-example.o
leak-example.o : leak-example.c

clean:
	rm -f leak-example leak-example.o *.lst

run: leak-example
	MALLOC_TRACE=trace_mem.lst ./leak-example
	mtrace leak-example trace_mem.lst


