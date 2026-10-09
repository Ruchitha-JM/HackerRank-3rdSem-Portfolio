#!/usr/bin/env python3
"""HackerRank: Compare the Triplets."""
import sys


def compare_triplets(alice, bob):
    alice_score = sum(a > b for a, b in zip(alice, bob))
    bob_score = sum(b > a for a, b in zip(alice, bob))
    return alice_score, bob_score


def main():
    data = list(map(int, sys.stdin.buffer.read().split()))
    if len(data) >= 6:
        alice_score, bob_score = compare_triplets(data[:3], data[3:6])
        print(alice_score, bob_score)


if __name__ == "__main__":
    main()
