CC      ?= gcc
CFLAGS  ?= -O2 -w
CFLAGS  += -Wno-error=incompatible-pointer-types \
           -Wno-error=int-conversion \
           -Wno-error=implicit-function-declaration \
           -Wno-error=pointer-sign \
           -Wno-error=return-type
LDLIBS  = -lcups -lcupsimage

all: rastertodpp268 commandtofilter2

rastertodpp268: rastertodpp268.c
	$(CC) $(CFLAGS) -c rastertodpp268.c -o rastertodpp268.o
	$(CC) rastertodpp268.o $(LDLIBS) -o rastertodpp268

commandtofilter2: commandtofilter2.c
	$(CC) -O2 -o commandtofilter2 commandtofilter2.c

clean:
	rm -f rastertodpp268.o rastertodpp268 commandtofilter2

install: all
	install -m755 rastertodpp268 /usr/lib/cups/filter/
	install -m755 commandtofilter2 /usr/lib/cups/filter/
	install -m644 LUT/*.bin /usr/share/cups/driver/FUJIFILM/rastertodpp268/LUT/

.PHONY: all clean install
