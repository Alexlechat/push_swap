# push_swap
 
A sorting algorithm project from the 42 school curriculum. The goal is to sort a stack of integers using the minimum number of operations, with only two stacks (A and B) and a restricted instruction set.
 
**Author:** Alexandre Lefranc
 
---
 
## Overview
 
push_swap is an exercise in algorithm design under strict constraints. No standard sorting algorithm can be applied directly — the program must sort exclusively through stack operations, making efficiency both a technical and algorithmic challenge.
 
---
 
## Algorithm
 
### Large inputs (100+ elements) — Radix Sort
 
For large datasets, the program uses a **Radix Sort** adapted for stack operations. Values are first normalized to contiguous indices, then sorted bit by bit using push and rotate operations. This guarantees O(n log n) complexity regardless of input distribution.
 
### Small inputs (5 elements or fewer)
 
Hard-coded decision trees handle small cases directly, reaching the optimal operation count for any permutation.
 
---
 
## Allowed Instructions
 
| Instruction | Description |
|---|---|
| `sa` / `sb` / `ss` | Swap the top two elements of stack A / B / both |
| `pa` / `pb` | Push the top element from B to A / from A to B |
| `ra` / `rb` / `rr` | Rotate stack A / B / both upward |
| `rra` / `rrb` / `rrr` | Reverse rotate stack A / B / both downward |
 
---
 
## Build
 
```bash
make
```
 
Run the program:
 
```bash
./push_swap 3 1 4 1 5 9 2 6
```
 
Check the operation count:
 
```bash
./push_swap 3 1 4 1 5 9 2 6 | wc -l
```
 
Verify correctness with the checker:
 
```bash
ARG="3 1 4 1 5 9 2 6"
./push_swap $ARG | ./checker $ARG
```
 
---
 
## Performance
 
| Input size | Target | Result |
|---|---|---|
| 3 elements | ≤ 3 ops | ✓ |
| 5 elements | ≤ 12 ops | ✓ |
| 100 elements | ≤ 700 ops | ✓ |
| 500 elements | ≤ 5000 ops | ✓ |
 
---
 
## Technical Notes
 
- Values are normalized to indices before sorting, making the algorithm input-independent.
- The stack is implemented as a doubly linked list for efficient front and back access.
- Memory is fully managed with no leaks (verified with Valgrind).
- The codebase follows the 42 Norm throughout.
---
 
## Score
 
**100 / 100**
 
---
 
## License
 
This project was completed as part of the 42 school curriculum and is shared for educational purposes.
