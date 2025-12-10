srcdir = src
objdir = objects
builddir = build

cfiles := $(wildcard $(srcdir)/*.c)
ofiles := $(patsubst $(srcdir)/%.c, $(objdir)/%.o, $(cfiles))

libfile = $(builddir)/libvector.a

libdir = build
libname = vector

CC = gcc
ctestflags = -g

testfile = test/test


.PHONY: prepare build clean cleanall list


list:
	@echo "clean build runtest buildtest"


dbgtest: $(testfile)
	@gdb --tui $(testfile)


runtest: $(testfile)
	@$(testfile)


buildtest: $(cfiles) main.c
	@$(CC) $(ctestflags) -o $(testfile) main.c $(cfiles)


clean:
	@rm $(objdir)/*


build: prepare $(ofiles)
	@ar crs $(libfile) $(ofiles)


prepare:
	@mkdir -p objects build test


$(objdir)/%.o: $(srcdir)/%.c
	@$(CC) -c -o $@ $<
	
