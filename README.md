Leak Tracing Example for Linux glibc
====================================

This is simple C example to demonstrate leak diagnostics for glibc based programs.


Setup
-----

* Ensure that you have mtrace command and libraries installed. In RedHat and its clones you can use:

		yum install glibc-utils

Running application
-------------------

Issue command:

		make run

You should get output like:
		
		cc -Wall -g   -c -o leak-example.o leak-example.c
		cc -g  leak-example.o   -o leak-example
		MALLOC_TRACE=trace_mem.lst ./leak-example
		test: Data1
		test: Data2
		mtrace leak-example trace_mem.lst
		
		Memory not freed:
		-----------------
		           Address     Size     Caller
		0x00000000020ff460      0xa  at .../leak-tracing-example/leak-example.c:19
		make: *** [run] Error 1

This properly indicates that there is a memory leak (lost 10 bytes)

Credits
-------

This application is licensed to Public Domain

