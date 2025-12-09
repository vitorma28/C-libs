srcdir = src
objdir = objects
builddir = build

cfiles := $(wildcard $(srcdir)/*.c)
ofiles := $(patsubst $(srcdir)/%.c, $(objdir)/%.o, $(cfiles))

libfile = $(builddir)/libvector.a

libdir = build
libname = vector

CC = gcc

testfile = test/test


.PHONY: prepare build clean cleanall list


list:
	@echo "clean build runtest buildtest"


runtest: $(testfile)
	@$(testfile)


buildtest: $(libfile) main.c
	@$(CC) -o $(testfile) main.c -L$(libdir) -l$(libname)


clean:
	@rm $(objdir)/*


build: prepare $(ofiles)
	@ar crs $(libfile) $(ofiles)


prepare:
	@mkdir -p objects build


$(objdir)/%.o: $(srcdir)/%.c
	@$(CC) -c -o $@ $<
	
