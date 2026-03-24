// =============================================================================
// CT13: O(n log n) Sorting Algorithms
// =============================================================================
//
// Three efficient sorts that use divide-and-conquer (or heap structure)
// to achieve O(n log n) performance. Massive improvement over O(n^2) on
// large datasets.
//
// Scenario: sorting student exam scores in ascending order (same as CT12).
//

#include "EfficientSorts.h"
#include <iostream>
#include <algorithm>  // std::swap

// =============================================================================
// 1. Merge Sort
// =============================================================================
//
// ? SEE DIAGRAM: images/header_diagrams.md #4 -- merge sort: divide and conquer tree
// ? SEE DIAGRAM: images/cpp_diagrams.md #1 -- merge(): combining two sorted halves (with code)
//

// ---------------------------------------------------------------------------
// 1a. merge() -- merge two sorted halves into one sorted region
// ---------------------------------------------------------------------------
//
// ! DISCUSSION: The merge step is where the real work happens.
//   - left half: data[left..mid] is sorted
//   - right half: data[mid+1..right] is sorted
//   - compare the front of each half, pick the smaller, repeat
//   - this produces a fully sorted region data[left..right]
//
// ! DISCUSSION: Why merge sort needs O(n) extra space.
//   - we copy both halves into temporary vectors before merging back
//   - we can't merge in-place without losing data (overwriting elements
//     we haven't compared yet)
//   - this is the tradeoff: guaranteed O(n log n) time costs O(n) space
//
static void merge(std::vector<int>& data, int left, int mid, int right) {
    // TODO 1a: Merge two sorted halves
    //   Step 1: Copy left half (data[left..mid]) into a temp vector left_half
    //   Step 2: Copy right half (data[mid+1..right]) into a temp vector right_half
    //   Step 3: Use three indices (i for left_half, j for right_half, k for data)
    //     - while both halves have elements: compare front of each, pick smaller
    //     - copy any remaining elements from left_half
    //     - copy any remaining elements from right_half
}

// ---------------------------------------------------------------------------
// 1b. merge_sort_recursive() -- divide and conquer
// ---------------------------------------------------------------------------
//
// ! DISCUSSION: How merge sort divides the problem.
//   - base case: if left >= right, the subarray has 0 or 1 elements (already sorted)
//   - recursive case: split in half, sort left, sort right, merge
//   - the recursion creates log n levels (halving each time)
//   - at each level, merging does O(n) work total
//   - total: O(n) * O(log n) = O(n log n)
//
static void merge_sort_recursive(std::vector<int>& data, int left, int right) {
    // TODO 1b: Recursive merge sort
    //   - base case: if left >= right, return (0 or 1 elements)
    //   - find the midpoint: mid = left + (right - left) / 2
    //   - recursively sort the left half:  merge_sort_recursive(data, left, mid)
    //   - recursively sort the right half: merge_sort_recursive(data, mid + 1, right)
    //   - merge the two sorted halves:     merge(data, left, mid, right)
}

// Public wrapper
void merge_sort(std::vector<int>& data) {
    if (data.size() <= 1) return;
    merge_sort_recursive(data, 0, static_cast<int>(data.size()) - 1);
}

// =============================================================================
// 2. Quick Sort
// =============================================================================
//
// ? SEE DIAGRAM: images/header_diagrams.md #5 -- quick sort: partition step
// ? SEE DIAGRAM: images/cpp_diagrams.md #2 -- partition(): scan, swap, place pivot (with code)
//

// ---------------------------------------------------------------------------
// 2a. partition() -- rearrange around a pivot
// ---------------------------------------------------------------------------
//
// ! DISCUSSION: How partitioning works.
//   - choose a pivot element (we use median-of-three for a good pivot)
//   - rearrange so elements <= pivot are on the left, elements > pivot on the right
//   - the pivot ends up in its FINAL sorted position
//   - return the pivot's index so we know where to split for recursion
//
// ! DISCUSSION: Median-of-three pivot selection.
//   - choosing the last element as pivot is simple but gives O(n^2) on sorted input
//   - median-of-three: look at first, middle, last -- use the median as pivot
//   - this avoids worst-case on already-sorted or reverse-sorted data
//   - move the median to data[high] so the rest of the partitioning logic is unchanged
//
// ! DISCUSSION: Why quick sort is NOT stable.
//   - the swap in the partition step can move elements far from their original position
//   - two equal elements on opposite sides of the pivot can end up reversed
//
static int partition(std::vector<int>& data, int low, int high) {
    // TODO 2a: Partition the array around a pivot
    //
    //   Step 1: Median-of-three pivot selection
    //     - int mid = low + (high - low) / 2
    //     - sort data[low], data[mid], data[high] so median ends up at data[high]
    //       if data[mid] < data[low]: swap(data[low], data[mid])
    //       if data[high] < data[low]: swap(data[low], data[high])
    //       if data[mid] < data[high]: swap(data[mid], data[high])
    //     - now data[high] holds the median -- use it as the pivot
    //     - int pivot = data[high]
    //
    //   Step 2: Partition
    //     - int i = low - 1  (i tracks the boundary of "elements <= pivot")
    //     - for j from low to high-1:
    //         if data[j] <= pivot: increment i, swap data[i] and data[j]
    //     - swap data[i+1] and data[high] (put pivot in its final position)
    //     - return i + 1 (the pivot's index)
    return low;  // placeholder
}

// ---------------------------------------------------------------------------
// 2b. quick_sort_recursive()
// ---------------------------------------------------------------------------
//
// ! DISCUSSION: How quick sort divides the problem.
//   - partition puts one element (the pivot) in its final position
//   - recursively sort the elements to the left of the pivot
//   - recursively sort the elements to the right of the pivot
//   - average case: pivot lands near the middle, giving log n levels -> O(n log n)
//   - worst case: pivot lands at the edge every time -> n levels -> O(n^2)
//     (median-of-three makes this extremely unlikely)
//
static void quick_sort_recursive(std::vector<int>& data, int low, int high) {
    // TODO 2b: Recursive quick sort
    //   - base case: if low >= high, return
    //   - int pivot_idx = partition(data, low, high)
    //   - recursively sort left:  quick_sort_recursive(data, low, pivot_idx - 1)
    //   - recursively sort right: quick_sort_recursive(data, pivot_idx + 1, high)
}

// Public wrapper
void quick_sort(std::vector<int>& data) {
    if (data.size() <= 1) return;
    quick_sort_recursive(data, 0, static_cast<int>(data.size()) - 1);
}

// =============================================================================
// 3. Heap Sort
// =============================================================================
//
// ? SEE DIAGRAM: images/header_diagrams.md #6 -- heap sort phase 1: build the max-heap
// ? SEE DIAGRAM: images/header_diagrams.md #7 -- heap sort phase 2: extract max repeatedly
// ? SEE DIAGRAM: images/cpp_diagrams.md #3 -- heapify_down(): sink node to correct level (with code)
//

// ---------------------------------------------------------------------------
// 3a. heapify_down() -- restore the max-heap property
// ---------------------------------------------------------------------------
//
// ! DISCUSSION: What is a max-heap?
//   - a complete binary tree stored in an array
//   - for any node at index i: left child = 2i+1, right child = 2i+2
//   - max-heap property: every parent is >= both children
//   - the root (index 0) is always the LARGEST element
//
// ! DISCUSSION: How heapify_down works.
//   - start at a node that might violate the heap property
//   - compare with left and right children -- find the largest of the three
//   - if the largest isn't the parent, swap and repeat at the child's position
//   - this "sinks" a small element down to its correct level
//   - time: O(log n) -- at most the height of the tree
//
static void heapify_down(std::vector<int>& data, int heap_size, int index) {
    // TODO 3a: Restore max-heap property from index downward
    //   - int largest = index
    //   - int left = 2 * index + 1
    //   - int right = 2 * index + 2
    //   - if left < heap_size AND data[left] > data[largest]: largest = left
    //   - if right < heap_size AND data[right] > data[largest]: largest = right
    //   - if largest != index:
    //       swap data[index] and data[largest]
    //       heapify_down(data, heap_size, largest)  // recurse on the swapped child
}

// ---------------------------------------------------------------------------
// 3b. heap_sort() -- build heap, then extract max repeatedly
// ---------------------------------------------------------------------------
//
// ! DISCUSSION: Heap sort in two phases.
//   Phase 1 -- Build max-heap: call heapify_down on every non-leaf node
//     - non-leaf nodes are at indices n/2-1 down to 0
//     - after this, data[0] is the largest element
//     - time: O(n) (not O(n log n) -- math proof beyond this course)
//
//   Phase 2 -- Extract max repeatedly:
//     - swap data[0] (the max) with the last unsorted element
//     - shrink the heap by 1 (the max is now in its final position)
//     - heapify_down on the new root to restore the heap
//     - repeat until the heap is size 1
//     - time: O(n log n) -- n extractions, each O(log n)
//
// ! DISCUSSION: Why heap sort is O(1) space.
//   - the heap IS the array -- no extra allocation needed
//   - contrast with merge sort's O(n) temporary array
//   - heap sort gives guaranteed O(n log n) with O(1) space
//   - but it's not stable and has poor cache performance (jumps around the array)
//
void heap_sort(std::vector<int>& data) {
    int n = static_cast<int>(data.size());
    if (n <= 1) return;

    // TODO 3b-phase1: Build max-heap
    //   - for i from n/2 - 1 down to 0:
    //       heapify_down(data, n, i)

    // TODO 3b-phase2: Extract max repeatedly
    //   - for i from n-1 down to 1:
    //       swap data[0] and data[i]   (move max to its final position)
    //       heapify_down(data, i, 0)   (restore heap on the shrunk portion)
}

// ? SEE DIAGRAM: images/header_diagrams.md #8 -- side-by-side comparison (time, space, stability)

// ---------------------------------------------------------------------------
// Utility: print a vector
// ---------------------------------------------------------------------------
void print_vector(const std::vector<int>& data, const std::string& label) {
    if (!label.empty()) {
        std::cout << label;
    }
    std::cout << "[";
    for (int i = 0; i < static_cast<int>(data.size()); ++i) {
        if (i > 0) std::cout << ", ";
        std::cout << data[i];
    }
    std::cout << "]\n";
}
