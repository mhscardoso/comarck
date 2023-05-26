from random import random

def empty_matrix(order):
    """
    Generates an empty matrix,
    a list os lists in python
    with all entries in zero
    """

    matrix = list()

    for line in range(order):
            matrix.append(list())

            for column in range(order):
                    matrix[line].append(0)

    return matrix


def rd_matrix(order):
    """
    Generates a matrix with
    random floating point numbers
    """

    if order <= 0:
            raise KeyError(f"{order} is not a valid for matrix")

    matrix = empty_matrix(order)

    for line in range(order):
            for column in range(order):
                    matrix[line][column] = random()

    return matrix


def show_matrix(message, matrix):
    order = len(matrix)

    print(message)

    for line in range(order):
            for column in range(order):
                    print(matrix[line][column], end="  ")
            print()

    print("-------------\n\n")