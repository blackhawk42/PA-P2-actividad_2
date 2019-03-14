CC=gcc
CFLAGS=

DISTDIR=dists/
ZIPFILE=actividad_2.zip

SOURCES=$(wildcard *.c)
MARKDOWNS=$(wildcard *.md)

TEXTSDIR=texts/

README=README.md

.PHONY: all dist clean run

all: 02.exe 03.exe 04.exe 05.exe

02.exe: 02.c
	$(CC) $(CFLAGS) -o $@ $<

03.exe: 03.c
	$(CC) $(CFLAGS) -o $@ $<

04.exe: 04.c
	$(CC) $(CFLAGS) -o $@ $<

05.exe: 05.c
	$(CC) $(CFLAGS) -o $@ $<


$(DISTDIR):
	mkdir $@

dist: $(SOURCES) $(MARKDOWNS) Makefile | $(DISTDIR) $(TEXTSDIR)
	zip -r $(DISTDIR)$(ZIPFILE) $(SOURCES) $(MARKDOWNS) $(TEXTSDIR) Makefile

clean:
	rm -rf *.exe *.o dists/*