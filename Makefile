HERMITUX_DIR:=/root/hermitux

CC:=gcc

divergence :
	cd src && make
	mv src/divergence .

hermitux :
	cd src && make \
		CC=$(CC) \
		LD=$(HERMITUX_DIR)/musl/obj/musl-gcc \
		LFLAGS=-static \
		LOMP="-fopenmp -L$(HERMITUX_DIR)/libiomp/build/runtime/src"
	mv src/divergence .

clean :
	cd src && make clean
	rm -rf divergence
