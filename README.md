# Activity 8 — HackerRank Algorithmic Problem-Solving

**Course:** Portfolio Building B25CS0311 · 3rd Semester B.Tech, Computer Science & Engineering  
**Author:** Ruchitha J M (`@jmruchitha`)  
**Language:** Python 3  
**HackerRank profile:** https://www.hackerrank.com/profile/jmruchitha  
**GitHub repository:** https://github.com/Ruchitha-JM/HackerRank-3rdSem-Portfolio

## Completion status

All five required Activity 8 challenges were accepted on HackerRank. The public profile displays the **3-star Problem Solving badge**. After additional warm-up submissions, the verified score was **205/475**; HackerRank confirmed the third star had been earned.

## Required solutions

| HackerRank problem | Source file | Approach | Time | Auxiliary space |
|---|---|---|---|---|
| [Diagonal Difference](https://www.hackerrank.com/challenges/diagonal-difference/problem) | `Diagonal-Difference/diagonal_difference.py` | Read one row at a time and update both diagonal sums. | O(n²) for matrix input | O(n) row buffer; O(1) accumulator state |
| [Dynamic Array](https://www.hackerrank.com/challenges/dynamic-array/problem) | `Dynamic-Array/dynamic_array.py` | XOR-derived sequence index; append or indexed query. | O(n + q) | O(n + q), including sequences, parsed queries, and buffered answers |
| [Time Conversion](https://www.hackerrank.com/challenges/time-conversion/problem) | `Time-Conversion/time_conversion.py` | Convert AM/PM explicitly, handling 12 AM and 12 PM. | O(1) | O(1) |
| [Compare the Triplets](https://www.hackerrank.com/challenges/compare-the-triplets/problem) | `Compare-the-Triplets/compare_the_triplets.py` | Compare three corresponding scores and count wins. | O(1) for fixed-size input | O(1) |
| [Sparse Arrays](https://www.hackerrank.com/challenges/sparse-arrays/problem) | `Sparse-Arrays/sparse_arrays.py` | Build a frequency map once, then answer queries by lookup. | O(n + q), expected | O(u + q): frequency map plus buffered output, where u is the number of unique strings |

The `n`/`q` symbols are the matrix dimension or input-string count and query count, as appropriate. Input/output costs are included in the estimates. The handout's stated O(n) target for Diagonal Difference counts diagonal arithmetic after input is available; reading all n² matrix values still takes O(n²).

## Run locally

```bash
python3 Diagonal-Difference/diagonal_difference.py < input.txt
python3 Dynamic-Array/dynamic_array.py < input.txt
python3 Time-Conversion/time_conversion.py < input.txt
python3 Compare-the-Triplets/compare_the_triplets.py < input.txt
python3 Sparse-Arrays/sparse_arrays.py < input.txt
bash tests/sample_tests.sh
```

## Badge-building practice

The following additional warm-up challenges were accepted while building toward the required badge: A Very Big Sum, Plus Minus, Mini-Max Sum, Staircase, Birthday Cake Candles, Grading Students, Breaking the Records, Migratory Birds, Divisible Sum Pairs, Apple and Orange, and Sales by Match. The final Sales by Match acceptance took the score to 205/475 and triggered HackerRank's third-star award dialog.

## Evidence

- `evidence/platform_notes.md` records the verified account, challenge URLs, and completion state.
- `evidence/hackerrank_profile_three_star.png` is a public-profile screenshot showing the three-star badge.
- `Sparse-Arrays/Screenshot 2026-10-03 165310.png` is the pre-existing accepted Sparse Arrays screenshot in this repository.
- Full-suite acceptance for all five required challenges was verified live in the authenticated HackerRank session. Individual local screenshot files for the other four accepted-result screens were not available to export in this run; capture and add those pages if the instructor strictly requires one separate screenshot per challenge.

## Tests

The project includes five runnable Python solutions and sample-based checks in `tests/sample_tests.sh`. Local tests supplement, but do not replace, the accepted HackerRank submissions.
