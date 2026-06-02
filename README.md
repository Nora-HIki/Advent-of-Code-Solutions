# Advent of Code Solutions in C

My solutions to the yearly **Advent of Code** programming challenges, implemented in **C**.

## About

[Advent of Code](https://adventofcode.com/) is an annual set of programming puzzles released every December. Each day contains two related challenges that gradually increase in difficulty.

This repository contains my solutions, organized by year and day.

## Repository Structure

```text
.
├── 2015/
│   ├── day01/
│   ├── day02/
│   └── ...
├── 2016/
│   ├── day01/
│   ├── day02/
│   └── ...
├── 2024/
│   ├── day01/
│   ├── day02/
│   └── ...
└── README.md
```

Each day's directory typically contains:

```text
dayXX/
├── part1.c
├── part2.c    
└── input.txt
```

## Building

Compile a solution using GCC:

```bash
gcc partX.c
```

Or with additional warnings enabled:

```bash
gcc -Wall -Wextra -O2 partX.c
```

## Running

Place the puzzle input in `input.txt` and run:

```bash
./a.out
```

Example:

```bash
cd 2016/day07
gcc partX.c
./a.out
```

## Goals

* Solve every Advent of Code puzzle in C
* Practice algorithms and data structures
* Improve problem-solving skills
* Explore different optimization techniques

## Progress

| Year | Stars|
| ---- | ----- |
| 2015 |   14    |
| 2016 |   17    |
| 2017 |   00    |
| 2018 |   00    |
| 2019 |   00    |
| 2020 |   00    |
| 2021 |   00    |
| 2022 |   00    |
| 2023 |   00    |
| 2024 |   00    |
| 2025 |   00    |

## Notes

* Solutions are written in standard C.
* Inputs are not included unless permitted by Advent of Code.
* Code prioritizes correctness first, then optimization where interesting.

## License

This repository is licensed under the MIT License.
