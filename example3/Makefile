.PHONY: all assembly clean

CFLAGS=-g -Wno-incompatible-pointer-types -no-pie -fno-stack-protector -z norelro -z execstack -D_FORTIFY_SOURCE=0

all: example3

example3: example3.c
	@gcc -o $@ $^ ${CFLAGS}
	@chmod +x $@

assembly: example3.c
	@gcc -S -o - $^ ${CFLAGS}

run: example3
	@setarch -R ./example3

clean:
	@rm -f example3
