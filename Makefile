CC=gcc
CFLAGS=

DISTDIR=dists/
ZIPFILE=actividad_2.zip

SOURCES=$(wildcard *.c)
MARKDOWNS=$(wildcard *.md)

README=README.md

.PHONY: all dist clean run

all: 02.exe 03.exe 04.exe

02.exe: 02.c
	$(CC) $(CFLAGS) -o $@ $<

03.exe: 03.c
	$(CC) $(CFLAGS) -o $@ $<

04.exe: 04.c
	$(CC) $(CFLAGS) -o $@ $<


$(DISTDIR):
	mkdir $@

dist: $(SOURCES) $(MARKDOWNS) Makefile | $(DISTDIR)
	zip $(DISTDIR)$(ZIPFILE) $(SOURCES) $(MARKDOWNS) Makefile

clean:
	rm -rf *.exe *.o dists/*