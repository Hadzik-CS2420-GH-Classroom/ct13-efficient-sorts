#pragma once

#include <vector>
#include <string>

// ---------------------------------------------------------------------------
// EfficientSorts -- O(n log n) sorting algorithms
// ---------------------------------------------------------------------------
//
// ! DISCUSSION: Why "n log n"?
//   - These algorithms divide the problem in half at each level (log n levels)
//   - At each level, they do O(n) work (merging, partitioning, or heapifying)
//   - Total: n work * log n levels = O(n log n)
//   - When n doubles, runtime roughly DOUBLES (not quadruples like O(n^2))
//
// ! DISCUSSION: Divide-and-conquer pattern.
//   - Merge sort: split in half, sort each half, merge the results
//   - Quick sort: pick a pivot, partition around it, sort each side
//   - Heap sort: build a max-heap, repeatedly extract the maximum
//   - All three reduce a big problem into smaller subproblems
//
// Key design decisions:
//   - Free functions taking std::vector<int>& -- not class methods
//   - Sort in ascending order (smallest first)
//   - Merge sort uses O(n) extra space; quick sort and heap sort are in-place
//

// ---------------------------------------------------------------------------
// Merge Sort
// ---------------------------------------------------------------------------
// - Divide array in half, recursively sort each half, merge the sorted halves
// - Time: O(n log n) always (best, average, worst)
// - Space: O(n) -- temporary array needed for merging
// - Stable: Yes (equal elements keep their original relative order)
//
void merge_sort(std::vector<int>& data);

// ---------------------------------------------------------------------------
// Quick Sort
// ---------------------------------------------------------------------------
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
// - Build a max-heap from the array, then repeatedly extract the max
// - Each extraction places the largest remaining element at the end
// - Time: O(n log n) always (best, average, worst)
// - Space: O(1) -- in-place (the heap IS the array)
// - Stable: No (heap operations move distant elements)
//
void heap_sort(std::vector<int>& data);

// ---------------------------------------------------------------------------
// Utility: print a vector (for demo output)
// ---------------------------------------------------------------------------
void print_vector(const std::vector<int>& data, const std::string& label = "");
