# Source Review and Improvement Notes

This update is based on the six original uploaded programs: `Array_1d_Operations.C`, `2dArray.c`, `stringOperations.c`, `stack.c`, `queue.c` and `recursion.c`.

## 1D arrays

- Removed the unused `int array[3] = {1,2};`.
- Split the large menu program into three focused standalone demonstrations: basic operations, in-place modifications, and insertion/deletion/sorting.
- Kept the original function-based structure and the distinction between printing in reverse and reversing the array.
- Added `const` to read-only array parameters.
- Kept insertion/deletion pointer parameters so students can see how a function updates the caller's logical size.
- Added input and boundary checks.

## 2D arrays

- Kept matrix input, display, addition, multiplication, transpose, row/column sums, diagonal sum and identity matrix concepts.
- Split basic matrix operations from multiplication/transpose to make the three-loop multiplication algorithm easier to focus on.
- Generalized multiplication to rectangular compatible dimensions: A is rowsA x colsA, B is rowsB x colsB, and colsA must equal rowsB.
- Used fixed maximum dimensions instead of variable-length arrays for more predictable compiler support.
- Used `long long` for row, column and diagonal sums.

## Strings

- The uploaded `stringOperations.c` was not a string program; it demonstrated integer 1D array input, display, sum and increment. It has not been silently relabelled as a string demonstration.
- Added actual string demonstrations using character arrays, `fgets`, `strlen`, `strcmp`, copy, concatenation, reversal and palindrome checking.
- `fgets` permits spaces, unlike `%s`.

## Stack and queue

- Both remain array-only implementations.
- Moved operations into functions that receive the array and state variables as parameters rather than relying on file-scope global state.
- Stack uses `top`; queue uses `front`, `rear` and `count`.
- Queue remains circular and uses modulo indexing to reuse array positions.
- Functions return success/failure for overflow and underflow; `main()` handles messages.

## Recursion

- Renamed `f1` to `printMessageNTimes` to make its purpose clear.
- Kept factorial, natural-number sum and Fibonacci examples.
- Restricted factorial input to 0..20 for `unsigned long long`.
- Restricted naive recursive Fibonacci to index 40 and explain that repeated recursive calls make it inefficient for larger inputs.
- Used unsigned inputs so negative factorial values are not silently treated as a base case.

## Important limitation

These are educational demonstrations, not production libraries. For brevity, some matrix input helpers return early after invalid input without a separate status return; in a later refinement they should return success/failure to `main()` before any operation is performed. For classroom use, enter valid integer matrix elements.
