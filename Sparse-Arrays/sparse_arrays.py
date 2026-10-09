#!/usr/bin/env python3
"""HackerRank: Sparse Arrays."""
from collections import Counter
import sys


def sparse_array(strings, queries):
    frequencies = Counter(strings)
    return [frequencies[query] for query in queries]


def main():
    stream = sys.stdin.buffer
    first = stream.readline()
    if not first:
        return
    n = int(first)
    frequencies = Counter(stream.readline().decode().rstrip("\n") for _ in range(n))
    q = int(stream.readline())
    answers = [str(frequencies[stream.readline().decode().rstrip("\n")]) for _ in range(q)]
    sys.stdout.write("\n".join(answers))
    if answers:
        sys.stdout.write("\n")


if __name__ == "__main__":
    main()
