CC = gcc
USBIN = /usr/local/bin
LIBDIR = /usr/local/lib
all: pwdx envx

.c.o:
	$(CC) -c -o $@ $<

mylibxxx.so: mylibxxx.o
	$(CC) -shared -o mylibxxx.so mylibxxx.o
	strip mylibxxx.so

pwdx: pwdx.c mylibxxx.so
	$(CC) -o pwdx $^
	strip pwdx

envx: envx.c mylibxxx.so
	$(CC) -o envx $^
	strip envx

clean:
	rm -f *.so *.o

install-lib: mylibxxx.so
	mkdir -p $(LIBDIR)
	install mylibxxx.so $(LIBDIR)
	ldconfig

uninstall-lib: 
	rm -f $(LIBDIR)/mylibxxx.so
	ldconfig
