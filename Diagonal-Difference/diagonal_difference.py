#!/usr/bin/env python3
"""HackerRank: Diagonal Difference."""
import sys


def diagonal_difference(matrix):
    n = len(matrix)
    primary = sum(matrix[i][i] for i in range(n))
    secondary = sum(matrix[i][n - 1 - i] for i in range(n))
    return abs(primary - secondary)


def main():
    stream = sys.stdin.buffer
    first = stream.readline()
    if not first:
        return
    n = int(first)
    primary = secondary = 0
    for i in range(n):
        row = list(map(int, stream.readline().split()))
        primary += row[i]
        secondary += row[n - 1 - i]
    print(abs(primary - secondary))


if __name__ == "__main__":
    main()
