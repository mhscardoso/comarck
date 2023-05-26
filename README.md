# Comarck

It`s a set of codes for testing execution time and performance of DGEMM algotithms for Computer Architecture.

All it does is multiply ten matrices (random) of order 8192, with elements of type double. Doing that, we consume 1.5 GB
execution time.

We also test for differents optimizations flags. (O1, O2, O3).

```
- ... (real code)
- utils
	- files.h		// Just for write files and terminal output
- rand_matrix
	- randm.h		// Codes for random matrices
```