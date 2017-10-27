.PHONY: clean all

clean:
	rm override.so test

override.so: override.c
	gcc -shared -fPIC -o liboverride.so override.c -ldl

test: test.c override.c
	gcc -o test test.c

all: override.so test
