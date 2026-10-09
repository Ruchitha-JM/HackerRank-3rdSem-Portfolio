#!/usr/bin/env python3
"""HackerRank: Time Conversion."""
import sys


def time_conversion(time_text):
    hour = int(time_text[:2])
    suffix = time_text[-2:]
    if suffix == "AM":
        hour = 0 if hour == 12 else hour
    else:  # PM
        hour = 12 if hour == 12 else hour + 12
    return f"{hour:02d}{time_text[2:8]}"


def main():
    value = sys.stdin.readline().strip()
    if value:
        print(time_conversion(value))


if __name__ == "__main__":
    main()
