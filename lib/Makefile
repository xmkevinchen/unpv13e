include ../Make.defines

all: ${LIB_OBJCS}
	ar rv ${LIBUNP_NAME} $?
	${RANLIB} ${LIBUNP_NAME}

clean:
	rm -rf ${PROGS} ${CLEANFILES}
