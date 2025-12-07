srcdir = src
objdir = objects
builddir = build

cfiles := $(wildcard $(srcdir)/*.c)
ofiles := $(patsubst $(srcdir)/%.c, $(objdir)/%.o, $(cfiles))

libfile = $(builddir)/libvector.a

CC = gcc


.PHONY: prepare build clean cleanall


clean:
	@rm $(objdir)/*


build: prepare $(ofiles)
	@ar crs $(libfile) $(ofiles)


prepare:
	@mkdir -p objects build


$(objdir)/%.o: $(srcdir)/%.c
	@$(CC) -c -o $@ $<
	
