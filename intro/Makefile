include ../Make.defines

PROGS = daytimetcpcli daytimetcpsrv daytimetcpcliv6
BUILDDIR = build

all: $(PROGS)

$(BUILDDIR):
	mkdir $(BUILDDIR)

$(BUILDDIR)/%.o: %.c $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

daytimetcpcli: $(BUILDDIR)/daytimetcpcli.o
	$(CC) $(CFLAGS) -o build/$@ $< $(LIBS)

daytimetcpsrv: $(BUILDDIR)/daytimetcpsrv.o
	$(CC) $(CFLAGS) -o build/$@ $< $(LIBS)

daytimetcpcliv6: $(BUILDDIR)/daytimetcpcliv6.o
	$(CC) $(CFLAGS) -o build/$@ $< $(LIBS)

clean:
	rm -rf *.o
	rm -rf build
