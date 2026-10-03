# Sparse Arrays

## Problem

Given a collection of input strings and a collection of query strings, determine how many times each query string occurs in the input collection.

## HackerRank

[Sparse Arrays](https://www.hackerrank.com/challenges/sparse-arrays/problem)

## Difficulty

Medium

## Approach

A hash table is used to store each input string and its frequency.

For every query string, the hash table is searched and its stored frequency is returned.

This avoids repeatedly scanning the complete list of strings for every query.

## Time Complexity

Average: O(N + Q)

Where:
- N = number of input strings
- Q = number of query strings

## Space Complexity

O(N)

The hash table stores the distinct input strings and their frequencies.

## Sample

Input:

```text
4
aba
baba
aba
xzxb
3
aba
xzxb
ab
