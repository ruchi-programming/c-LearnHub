# c-LearnHub

**Learn concepts. Explore code. Build logic.**

A student-friendly collection of small, function-oriented C programs for classroom demonstrations, revision and independent practice.

## Learning path

| Order | Folder | Main concepts |
|---|---|---|
| 01 | `01_fundamentals` | Input/output, data types, operators, conditions, loops |
| 02 | `02_number_operations` | Digit processing, palindrome, Armstrong, prime, GCD/LCM |
| 03 | `03_patterns` | Nested loops and pattern construction |
| 04 | `04_functions` | Function declaration, definition, arguments, return values, scope |
| 05 | `05_arrays_1d` | Traversal, search, aggregates, reverse, sorting, insertion/deletion |
| 06 | `06_arrays_2d` | Matrix traversal and operations |
| 07 | `07_strings` | Character arrays, null terminator, standard library, string algorithms |
| 08 | `08_pointers` | Addresses, dereferencing, pointer parameters, arrays and pointers |
| 09 | `09_recursion` | Base case, recursive case, call stack and classic problems |
| 10 | `10_stack_queue` | Stack and circular queue using fixed-size arrays only |
| 11 | `11_structures` | Structures, arrays of structures and `typedef` |
| 12 | `12_file_handling` | Text-file read/write basics |

## Compile and run

Using GCC:

```bash
gcc -std=c11 -Wall -Wextra -Wpedantic filename.c -o program
./program
```

On Windows:

```powershell
gcc -std=c11 -Wall -Wextra -Wpedantic filename.c -o program.exe
.\program.exe
```

Each `.c` file is a separate program with its own `main()`. Compile one file at a time. Do not compile every source file in the repository into one executable.

## Suggested classroom workflow

1. Explain the concept and trace the sample code.
2. Ask students to predict the output before running it.
3. Run the program with normal, boundary and invalid inputs.
4. Change one condition or loop and predict the effect.
5. Ask students to implement one extension without copying the solution.

## Code conventions

- Standard C headers and C11-compatible examples.
- Descriptive function and variable names.
- Comments explain the reasoning rather than restating every line.
- Input validation is included where it materially improves the demonstration.
- Fixed-size arrays are used in beginner examples to avoid introducing variable-length array portability issues too early.

## Important notes

- Array indices start at `0`; user-facing positions are often shown starting at `1`.
- A C string is a character array terminated by `'\0'`.
- Array parameters to functions are adjusted to pointers; pass the array length separately.
- A pointer must refer to a valid object before it is dereferenced.
- Recursive functions need a reachable base case.
- Integer overflow is possible. The sample number programs use bounded inputs and explain their assumptions.

## Repository map

See [`LEARNING_CHECKLIST.md`](LEARNING_CHECKLIST.md) for a topic checklist and [`PRACTICE_EXTENSIONS.md`](PRACTICE_EXTENSIONS.md) for exercises that students can attempt after studying the demonstrations.


## Stack and queue scope

The stack and queue demonstrations in this repository use **arrays only**:
- `stack_array.c`: stack implemented with a fixed-size array and a `top` index.
- `circular_queue_array.c`: circular queue implemented with a fixed-size array and `front`, `rear` and `count` variables.

Linked-list implementations are intentionally excluded from this repository's stack/queue demonstrations. The queue example is circular so students can see how modulo indexing reuses freed positions in the array.
