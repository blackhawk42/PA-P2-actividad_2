CC=gcc
CFLAGS=

DISTDIR=dists/
ZIPFILE=actividad_3.zip

SOURCES=$(wildcard *.c)
MARKDOWNS=$(wildcard *.md)

TEXTSDIR=texts/
TEXTS=$(wildcard texts/*)
UTILSDIR=utils/

README=README.md

.PHONY: all dist clean run unix2windows windows2unix

all: 02.exe 03.exe 04.exe 05.exe 06.exe 07.exe

02.exe: 02.c
	$(CC) $(CFLAGS) -o $@ $<

03.exe: 03.c
	$(CC) $(CFLAGS) -o $@ $<

04.exe: 04.c
	$(CC) $(CFLAGS) -o $@ $<

05.exe: 05.c
	$(CC) $(CFLAGS) -o $@ $<

06.exe: 06.c
	$(CC) $(CFLAGS) -o $@ $<

07.exe: 07.c
	$(CC) $(CFLAGS) -o $@ $<


$(DISTDIR):
	mkdir $@

dist: $(SOURCES) $(MARKDOWNS) Makefile $(TEXTSDIR) $(UTILSDIR) | $(DISTDIR)
	zip -r $(DISTDIR)$(ZIPFILE) $(SOURCES) $(MARKDOWNS) $(TEXTSDIR) $(UTILSDIR) Makefile

unix2windows:
	python utils/lines.py -w $(TEXTS)

windows2unix:
	python utils/lines.py -u $(TEXTS)

clean:
	rm -rf *.exe *.o dists/*