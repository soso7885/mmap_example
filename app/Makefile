SRC		= my_mmap_app.c
CFLAGS 	= -std=c99
TARG	= my_mmap_app

all: $(TARG)

my_mmap_app: $(SRC)
	gcc -Wall $(CFLAGS) -o $@ $(SRC)

clean:
	rm -f $(TARG)
