# Learning Parallel Programming

A collection C programs I wrote while learning parallel programming,
one for each of the three main models:

| Program                   | Model  | What it does                                                        |
| ------------------------- | ------ | ------------------------------------------------------------------- |
| `openmp-set-sort/`        | OpenMP | Thread-safe set operations (add/remove) + odd-even sort             |
| `mpi-letter-histogram/`   | MPI    | Letter-frequency histogram over a text file, split across processes |
| `opencl-gradient-update/` | OpenCL | `weights[i][j] += gradients[i] * inputs[j]` computed on the GPU     |

## Build & run

openmp-set-sort (edit the function calls in `main.c` first:

```sh
cd openmp-set-sort && gcc -fopenmp -o set_sort main.c
./set_sort <maxSetSize> <numToAdd> <numToRemove> <sortYesNo>
```

mpi-letter-histogram (reads `input.txt` from the working directory):

```sh
cd mpi-letter-histogram && mpicc -Wall -o letter_hist main.c
mpirun -np 4 ./letter_hist
```

opencl-gradient-update (`N` and `M` must be powers of 2):

```sh
cd opencl-gradient-update && make
./gradient_update <N> <M>
```

