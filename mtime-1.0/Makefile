include config.mk

SRC = mtime.c
OBJ = ${SRC:.c=.o}

all: options mtime

options:
	@echo mtime build options:
	@echo "CFLAGS   = ${CFLAGS}"
	@echo "LDFLAGS  = ${LDFLAGS}"
	@echo "CXX      = ${CXX}"

.c.o:
	@echo CXX $<
	@${CXX} -c ${CFLAGS} $<

${OBJ}: mtime.c config.mk

mtime: ${OBJ}
	@echo CXX -o $@
	@${CXX} -o $@ ${OBJ} ${LDFLAGS}

clean:
	@echo cleaning
	@rm -f mtime ${OBJ}

dist: clean
	@echo creating dist tarball
	@mkdir -p mtime-${VERSION}
	@cp -R LICENSE Makefile config.mk \
		mtime.1 ${SRC} mtime-${VERSION}
	@tar -cf mtime-${VERSION}.tar mtime-${VERSION}
	@gzip mtime-${VERSION}.tar
	@rm -rf mtime-${VERSION}

install: all
	@echo installing executable file to ${DESTDIR}${PREFIX}/bin
	@mkdir -p ${DESTDIR}${PREFIX}/bin
	@cp -f mtime ${DESTDIR}${PREFIX}/bin
	@chmod 755 ${DESTDIR}${PREFIX}/bin/mtime
	@echo installing manual page to ${DESTDIR}${MANPREFIX}/man1
	@mkdir -p ${DESTDIR}${PREFIX}/man1
	@sed "s/VERSION/${VERSION}/g" < mtime.1 > ${DESTDIR}${MANPREFIX}/man1/mtime.1
	@chmod 644 ${DESTDIR}${MANPREFIX}/man1/mtime.1

uninstall:
	@echo removing executable file from ${DESTDIR}${PREFIX}/bin
	@rm -f ${DESTDIR}${PREFIX}/bin/mtime
	@echo removing manual page from ${DESTDIR}${MANPREFIX}/man1
	@rm -f ${DESTDIR}${MANPREFIX}/man1/mtime.1

.PHONY: all options clean dist install uninstall
