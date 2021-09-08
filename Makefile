CC=gcc
PROG=memhog

all:
	${CC} ${PROG}.c -Wall -g -o ${PROG}

clean:
	rm -rf ${PROG}
