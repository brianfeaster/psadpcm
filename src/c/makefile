# Path of the source files and include files
CC         = gcc

CFLAGS = -I. -Wall -march=native -Wconversion -Wno-trigraphs -Wno-format -Werror -O3 -ggdb
# -I                Include this directory for h file searches
# -Wall             Many warnings.
# -ggdb             Debugging
# -march=native     GCC can figure out the best optimization switches
# -Wno-trigraphs    Don't honor trigraphs
# -Wno-format       Disable the annoying printf warnings.
# -Wno-parentheses  If it's valid C why complain?
# -pg               Profiling.
# -O3               -malign-loops=2 -malign-jumps=2 -malign-functions=2 -malign-double -mwide-multiply
# -Werror           Warnings prevent compilation.

LDFLAGS = -lm
# -lm       Math library (probably trig functions).
# -lcrypto  Crypto library for md5sum hash function.

OBJS := main.o ps_init.o

main: main.o ps_init.o
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

main.o: main.c common.h
	$(CC) $(CFLAGS) -c -o $@ $<

ps_init.o: ps_init.c common.h
	$(CC) $(CFLAGS) -c -o $@ $<

run: main
	main
