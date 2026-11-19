# c-LearnHub — Improved Classroom Demonstrations

These programs are revised from the original classroom code supplied for review. The focus is not only on the algorithm, but also on **how to divide a problem into user-defined functions and call those functions from `main()`**.

## Folder structure

```text
c-LearnHub/
└── classroom_demos/
    ├── 01_arrays_1d/
    │   ├── 01_array_basics.c
    │   ├── 02_array_modification.c
    │   └── 03_array_insertion_deletion_sort.c
    ├── 02_arrays_2d/
    │   ├── 01_matrix_basics_and_addition.c
    │   └── 02_matrix_multiplication_transpose.c
    ├── 03_strings/
    │   ├── 01_string_basics.c
    │   └── 02_string_operations.c
    ├── 04_stack_queue/
    │   ├── 01_stack_using_array.c
    │   └── 02_circular_queue_using_array.c
    └── 05_recursion/
        └── 01_recursion_basics.c
```

## Compile one program at a time

GCC:

```bash
gcc -std=c11 -Wall -Wextra -Wpedantic path/to/file.c -o demo
```

Windows PowerShell:

```powershell
gcc -std=c11 -Wall -Wextra -Wpedantic path\to\file.c -o demo.exe
.\demo.exe
```

Each source file is a standalone program with its own `main()`. Do not compile all `.c` files into one executable.

## Teaching sequence

1. Read the function prototypes.
2. Identify each function's purpose, parameters and return type.
3. Trace how `main()` calls the functions.
4. Dry-run one example before executing the program.
5. Change the input and predict the output.
6. Modify or add one function as a practice task.

## Key teaching conventions

- Array functions receive the array and its size.
- Functions that only inspect an array use `const` where appropriate.
- Operations that modify an array are clearly named and demonstrated separately.
- Insertion and deletion use pointer parameters to update the logical array size.
- Stack and queue are implemented **using arrays only**. No linked-list implementation is included.
- Stack and queue operations are separate functions; the menu remains in `main()`.
- Matrix examples use fixed maximum dimensions to keep the examples portable and easy to compile.
- String input uses `fgets()` so that spaces can be included.
- Input is checked before values are used.

## Source fidelity and changes

The programs retain the original concepts and function-oriented teaching approach. Improvements include clearer names, validation, separation into related standalone demonstrations, const-correct parameters, boundary checks and comments that explain important logic.

The originally uploaded file `stringOperations.c` actually contained integer 1D-array operations. It has therefore not been treated as an original string program. The `03_strings` folder contains proper C-string demonstrations added to complete the topic.
