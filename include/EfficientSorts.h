#pragma once

#include <vector>
#include <string>

// ---------------------------------------------------------------------------
// EfficientSorts -- O(n log n) sorting algorithms
// ---------------------------------------------------------------------------
//
// ? SEE DIAGRAM: images/header_diagrams.md #1 -- the three O(n log n) sorts at a high level
// ? SEE DIAGRAM: images/header_diagrams.md #2 -- O(n log n) vs O(n^2) growth comparison
// ? SEE DIAGRAM: images/header_diagrams.md #3 -- why O(n log n): divide and conquer
//
// ! DISCUSSION: Why "n log n"?
//   - n work per level * log n levels = O(n log n)
//   - When n doubles, runtime roughly DOUBLES (not quadruples like O(n^2))
//
// Key design decisions:
//   - Free functions taking std::vector<int>& -- not class methods
//   - Sort in ascending order (smallest first)
//

// ---------------------------------------------------------------------------
// Merge Sort
// ---------------------------------------------------------------------------
//
// ? SEE DIAGRAM: images/header_diagrams.md #4 -- merge sort: divide and conquer tree
//
// - Divide array in half, recursively sort each half, merge the sorted halves
// - Time: O(n log n) always (best, average, worst)
// - Space: O(n) -- temporary array needed for merging
// - Stable: Yes (equal elements keep their original relative order)
//
void merge_sort(std::vector<int>& data);

// ---------------------------------------------------------------------------
// Quick Sort
// ---------------------------------------------------------------------------
//
// ? SEE DIAGRAM: images/header_diagrams.md #5 -- quick sort: partition step
//
// - Pick a pivot, partition: elements < pivot go left, elements > pivot go right
// - Recursively sort the left and right partitions
// - Time: O(n log n) average | O(n^2) worst (bad pivot on sorted data)
// - Space: O(log n) -- recursive call stack depth
// - Stable: No (partitioning can swap distant elements)
//
void quick_sort(std::vector<int>& data);

// ---------------------------------------------------------------------------
// Heap Sort
// ---------------------------------------------------------------------------
//
// ? SEE DIAGRAM: images/header_diagrams.md #6 -- heap sort phase 1: build the max-heap
// ? SEE DIAGRAM: images/header_diagrams.md #7 -- heap sort phase 2: extract max repeatedly
//
// - Build a max-heap from the array, then repeatedly extract the max
// - Each extraction places the largest remaining element at the end
// - Time: O(n log n) always (best, average, worst)
// - Space: O(1) -- in-place (the heap IS the array)
// - Stable: No (heap operations move distant elements)
//
void heap_sort(std::vector<int>& data);

// ? SEE DIAGRAM: images/header_diagrams.md #8 -- side-by-side comparison (time, space, stability)

// ---------------------------------------------------------------------------
// Utility: print a vector (for demo output)
// ---------------------------------------------------------------------------
void print_vector(const std::vector<int>& data, const std::string& label = "");
