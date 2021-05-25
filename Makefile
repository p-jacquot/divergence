HERMITUX_DIR:=/root/hermitux
HERMITCORE_DIR=/opt/hermit

CC:=gcc

divergence :
	cd src && make CFLAGS="-D GETTIMEOFDAY"
	mv src/divergence .

hermitux :
	cd src && make \
		CC=$(CC) \
		CFLAGS="-D GETTIMEOFDAY"
		LD=$(HERMITUX_DIR)/musl/obj/musl-gcc \
		LFLAGS=-static \
		LOMP="-fopenmp -L$(HERMITUX_DIR)/libiomp/build/runtime/src"
	mv src/divergence .

hermitcore :
	cd src && make \
		CC=$(HERMITCORE_DIR)/bin/x86_64-hermit-gcc \
		CFLAGS="-D GETTIMEOFDAY" \
		LD=$(HERMITCORE_DIR)/bin/x86_64-hermit-gcc
	mv src/divergence .

clean :
	cd src && make clean
	rm -rf divergence timestamps.csv
