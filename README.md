# divergence

Divergence is a small program for measuring OS noise.
It does so by spawning several threads, and asking them to save timestamps after performing some operations.

## Build

The program require OpenMP to be compiled and run.

Simply use the following commands : 

```
git clone https://github.com/p-jacquot/divergence
cd divergence
make
```

If you want to customise the compilation, you can specify makefile variables :

```
make CC=clang LD=clang
```

Please check the first lines of `src/Makefile` to see what variables you can override.

## usage

Executing divergence create a `timestamps.csv` files, where the timestamps taken by the differents threads are stored.

Here is the command syntax :

```
./divergence [-n NUMBER] [-t NUMBER]
```

### parameters

* n : Number of timestamps to take. (default : 100)
* t : Number of threads to spawn. (default : `omp_get_max_threads()` return value)
