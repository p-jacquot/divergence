HERMITUX_DIR:=/root/hermitux
HERMITCORE_DIR=/opt/hermit

CC:=gcc

divergence-no-omp:
	cd src && make \
		CFLAGS="-D GETTIMEOFDAY -O4" \
		LFLAGS="-O4" \
		LOMP=""
	mv src/divergence .

divergence:
	cd src && make CFLAGS="-D GETTIMEOFDAY -D OMP -O4" LFLAGS="-O4"
	mv src/divergence .

hermitux :
	cd src && make \
		CC=$(CC) \
		CFLAGS="-D GETTIMEOFDAY -O4" \
		LD=$(HERMITUX_DIR)/musl/obj/musl-gcc \
		LFLAGS="-static -O4" \
		LOMP="-fopenmp -L$(HERMITUX_DIR)/libiomp/build/runtime/src"
	mv src/divergence .

hermitux-llvm11 :
	cd src && make \
		CC=$(CC) \
		CFLAGS="-D GETTIMEOFDAY -D OMP -O4" \
		LD=$(HERMITUX_DIR)/musl/obj/musl-gcc \
		LFLAGS="-static -O4" \
		LOMP="-fopenmp /root/omp/*.o"
	mv src/divergence .

hermitux-no-omp :
	cd src && make \
		CC=$(CC) \
		CFLAGS="-D GETTIMEOFDAY -O4 -static" \
		LD=$(CC) \
		LFLAGS="-static -O4" \
		LOMP=""
	mv src/divergence .


hermitcore :
	cd src && make \
		CC=$(HERMITCORE_DIR)/bin/x86_64-hermit-gcc \
		CFLAGS="-D GETTIMEOFDAY -O4 -D OMP" \
		LD=$(HERMITCORE_DIR)/bin/x86_64-hermit-gcc \
		LFLAGS="-O4"
	mv src/divergence .

hermitcore-no-omp :
	cd src && make \
		CC=$(HERMITCORE_DIR)/bin/x86_64-hermit-gcc \
		CFLAGS="-D GETTIMEOFDAY -O4" \
		LD=$(HERMITCORE_DIR)/bin/x86_64-hermit-gcc \
		LFLAGS="-O4" \
		LOMP=""
	mv src/divergence .


clean :
	cd src && make clean
	rm -rf divergence timestamps.csv
