#!/usr/bin/env python3
"""HackerRank: Dynamic Array."""
import sys


def dynamic_array(n, queries):
    sequences = [[] for _ in range(n)]
    last_answer = 0
    answers = []
    for query_type, x, y in queries:
        index = (x ^ last_answer) % n
        if query_type == 1:
            sequences[index].append(y)
        else:
            last_answer = sequences[index][y % len(sequences[index])]
            answers.append(last_answer)
    return answers


def main():
    data = list(map(int, sys.stdin.buffer.read().split()))
    if not data:
        return
    n, q = data[0], data[1]
    sequences = [[] for _ in range(n)]
    last_answer = 0
    answers = []
    offset = 2
    for _ in range(q):
        query_type, x, y = data[offset:offset + 3]
        offset += 3
        index = (x ^ last_answer) % n
        if query_type == 1:
            sequences[index].append(y)
        else:
            last_answer = sequences[index][y % len(sequences[index])]
            answers.append(str(last_answer))
    sys.stdout.write("\n".join(answers))
    if answers:
        sys.stdout.write("\n")


if __name__ == "__main__":
    main()
