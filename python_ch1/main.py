from rand_matrix import empty_matrix, rd_matrix, show_matrix
from time import time, sleep

## Constant
ORDER = 1024

## Creating Matrixes
print("Creating Matrix ...")
A = rd_matrix(ORDER)
B = rd_matrix(ORDER)

# Result Matrix
C = empty_matrix(ORDER)
print("All matrixes created!\n\n")

## Showing Matrixes
# show_matrix("A: ", A)
# show_matrix("B: ", B)


## Here, starts DMGGEM
print("Starting Multiplication...")
start_time = time()

for line in range(ORDER):
    for column in range(ORDER):
        for index in range(ORDER):
            C[line][column] += A[line][index] * B[index][column]

end_time = time()

# Getting execution time
execution_time = end_time - start_time

## Results
# show_matrix("Result: ", C)

## Time for matrix multiplication
print(f"Elapsed Time: {execution_time}")

## Performance for Matrix Muitiplication in Python
performance = 1 / execution_time
print("Performance: ", performance)