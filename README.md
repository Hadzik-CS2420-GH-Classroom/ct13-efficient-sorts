# CT13 -- O(n log n) Sorting Algorithms

## Overview

An in-class code-together activity introducing **efficient sorting algorithms** -- merge sort, quick sort, and heap sort. Students implement all three in `EfficientSorts.cpp` and call them from `main.cpp` to sort exam scores. The activity covers the divide-and-conquer pattern, pivot selection, the heap data structure, space/time tradeoffs, and why these algorithms dominate over O(n^2) sorts on large datasets. Bucket sort is discussed conceptually but not implemented.

## Learning Objectives

- Implement **merge sort** using the divide-in-half and merge pattern, understanding O(n) space cost
- Implement **quick sort** with median-of-three pivot selection, understanding average vs worst case
- Implement **heap sort** by building a max-heap and repeatedly extracting the maximum
- Explain the **divide-and-conquer** pattern: split the problem, solve subproblems, combine results
- Explain why O(n log n) is dramatically faster than O(n^2) on large datasets
- Compare **space/time tradeoffs**: merge sort (O(n) space), quick sort (O(log n) space), heap sort (O(1) space)
- Describe **bucket sort** conceptually: non-comparison-based, O(n+k) average, best for uniform distributions

## Files

| File | Focus | TODOs |
|---|---|---|
| `EfficientSorts.cpp` | Implement merge sort, quick sort, heap sort | 6 (1a, 1b, 2a, 2b, 3a, 3b) |
| `main.cpp` | Call each sort on exam scores, compare results | 4 |

## Teaching Order

### 1. `EfficientSorts.h` -- Function declarations

Walk through the header. Discuss O(n log n) vs O(n^2) and the divide-and-conquer concept.

### 2. `EfficientSorts.cpp` -- Sort implementations (6 TODOs)

1. **TODO 1a: merge()** -- merge two sorted halves using temporary vectors
2. **TODO 1b: merge_sort_recursive()** -- base case + divide + recurse + merge
3. **TODO 2a: partition()** -- median-of-three pivot + rearrange around pivot
4. **TODO 2b: quick_sort_recursive()** -- base case + partition + recurse each side
5. **TODO 3a: heapify_down()** -- compare parent with children, swap largest, recurse
6. **TODO 3b: heap_sort()** -- phase 1: build max-heap, phase 2: extract max repeatedly

### 3. `main.cpp` -- Exam Score Sorter (4 TODOs)

1. **TODO 1: Merge sort demo** -- sort and print exam scores
2. **TODO 2: Quick sort demo** -- same scores, different algorithm
3. **TODO 3: Heap sort demo** -- same scores, different algorithm
4. **TODO 4: Larger dataset** -- sort 20 scores with all three, compare results

### 4. Bucket sort discussion (no code TODOs)

Section 6 of main.cpp discusses bucket sort conceptually -- non-comparison-based, O(n+k) time, best for uniform distributions.

## Grading (30 points)

| Category | Points | What is tested |
|---|---|---|
| Build | 0 | Project must compile (tests won't run otherwise) |
| Merge sort | 10 | Basic, sorted, reverse, empty, duplicates, negatives, large dataset |
| Quick sort | 10 | Basic, sorted, reverse, empty, duplicates, all-same, 2/3 elements, large dataset |
| Heap sort | 10 | Basic, sorted, reverse, empty, duplicates, all-same, negatives, large dataset |

## Key Concepts

- **Divide-and-conquer**: split the problem in half, solve recursively, combine results
- **O(n log n)**: log n levels of recursion, O(n) work at each level
- **Merge sort**: stable, guaranteed O(n log n), but O(n) extra space
- **Quick sort**: fastest in practice (cache-friendly), O(log n) space, but O(n^2) worst case
- **Heap sort**: O(1) space, guaranteed O(n log n), but poor cache locality and not stable
- **Bucket sort**: non-comparison-based, O(n+k) average, best for uniformly distributed data
- **Stability**: merge sort preserves order of equal elements; quick sort and heap sort do not
