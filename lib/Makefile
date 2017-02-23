include ../Make.defines

BUILDDIR = build
OBJECTS := $(addprefix $(BUILDDIR)/, $(patsubst %.c, %.o, $(wildcard *.c)))


.PHONY: clean

$(BUILDDIR)/%.o: %.c
	mkdir $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(OBJECTS)
	ar rv $(LIBUNP_NAME) $?
	$(RANLIB) $(LIBUNP_NAME)

clean:
	rm $(LIBUNP_NAME)
	rm -rf $(BUILDDIR)
