# CLAUDE.md

This file provides guidance to Claude Code when working with code in this repository.

## Project Overview

Personal solutions to the annual Advent of Code programming challenges. The 2024 solutions are written in C. Solutions are organized by year and day number.

## Tech Stack

- **Language**: C (primary, for 2024 solutions)
- **Compiler**: gcc
- **No build system**: Each solution is a standalone C file compiled directly

## Project Structure

```
aoc-sols/
├── 2024/
│   ├── day01/
│   │   └── solution.c
│   ├── day02/
│   │   └── solution.c
│   ├── ...
│   └── dayNN/
│       └── solution.c
└── .github/workflows/
    └── claude.yml       # Claude Code Actions workflow
```

Each day's directory contains:
- `solution.c` -- the solution source code
- Input files may be present (puzzle input)

## Development Commands

```bash
# Compile a solution
cd 2024/dayXX
gcc solution.c -o solution

# Run the solution
./solution

# Compile with warnings and debug info
gcc -Wall -Wextra -g solution.c -o solution

# Compile with optimizations
gcc -O2 solution.c -o solution
```

## Code Style & Standards

- Standard C (C99/C11)
- Each solution is self-contained in a single file
- Input parsing is typically done via stdin or file reading
- No external libraries -- standard library only
- Keep solutions readable but concise

## Architecture Notes

- Each day is independent -- no shared code between days
- Solutions read puzzle input from files or stdin
- Part 1 and Part 2 of each day are typically in the same file
- Focus on correctness first, optimization second

## Troubleshooting

- Compilation errors: Ensure gcc is installed (`gcc --version`)
- Wrong answers: Double-check input file is correct for your account
- Segfaults: Use `gcc -g` and run with `lldb` or `valgrind`
