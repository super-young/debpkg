PREFIX?=/usr/local
CFLAGS=-g -Wall -I${PREFIX}/apr/include/apr-1 -I${PREFIX}/apr/include/apr-util-1

LDFLAGS=-L${PREFIX}/apr/lib -lapr-1 -pthread -lapr-util-1

all: devpkg

devpkg: bstrlib.o db.o shell.o commands.o

install:
	install -d $(DESTDIR)/$(PREFIX)/bin/
	install devpkg $(DESTDIR)/$(PREFIX)/bin/

clean:
	rm -rf *.o
	rm -rf devpkg
	rm -rf *.dSYM