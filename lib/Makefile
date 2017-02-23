include ../Make.defines

BUILDDIR = build
OBJECTS := $(addprefix $(BUILDDIR)/, $(patsubst %.c, %.o, $(wildcard *.c)))

.DEFAULT_GOAL := all

.PHONY: clean

$(BUILDDIR):
	mkdir $(BUILDDIR)

$(OBJECTS): $(BUILDDIR)/%.o: %.c $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(OBJECTS)
	ar rv $(LIBUNP_NAME) $^
	$(RANLIB) $(LIBUNP_NAME)

clean:
	@rm -rf $(BUILDDIR)
	@rm $(LIBUNP_NAME)
