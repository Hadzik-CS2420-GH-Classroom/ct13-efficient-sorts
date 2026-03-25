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
// ? SEE DIAGRAM: images/cpp_diagrams.md #1 -- how the three functions work together
//

// ---------------------------------------------------------------------------
// 1a. merge() -- merge two sorted halves into one sorted region
// ---------------------------------------------------------------------------
//
// ! DISCUSSION: Why merge sort needs O(n) extra space.
//   - the tradeoff: guaranteed O(n log n) time costs O(n) space
//   - the step-by-step diagrams show exactly why we copy before merging
//
static void merge(std::vector<int>& data, int left, int mid, int right) {
    // TODO 1a: Merge two sorted halves
    // ? SEE DIAGRAM: images/cpp_diagrams.md #5 -- step 1 (2-element merge)
    // ? SEE DIAGRAM: images/cpp_diagrams.md #8 -- step 1 (4-element final merge)
    //
    //   Step 1: Copy both halves into temp vectors
    //     - vector<int> left_half(data.begin()+left, data.begin()+mid+1)
    //     - vector<int> right_half(data.begin()+mid+1, data.begin()+right+1)
    //
    // ? SEE DIAGRAM: images/cpp_diagrams.md #6 -- step 2 (2-element merge)
    // ? SEE DIAGRAM: images/cpp_diagrams.md #9 -- step 2 (4-element final merge)
    //
    //   Step 2: Use three indices (i for left_half, j for right_half, k starting at left)
    //     - while both halves have elements: compare front of each, pick smaller into data[k++]
    //
    // ? SEE DIAGRAM: images/cpp_diagrams.md #7 -- step 3 (2-element merge)
    // ? SEE DIAGRAM: images/cpp_diagrams.md #10 -- step 3 (4-element final merge)
    //
    //   Step 3: Copy any remaining elements from left_half, then from right_half
}

// ---------------------------------------------------------------------------
// 1b. merge_sort_recursive() -- divide and conquer
// ---------------------------------------------------------------------------
//
// ? SEE DIAGRAM: images/cpp_diagrams.md #3 -- merge_sort_recursive(): the recursion (code)
// ? SEE DIAGRAM: images/cpp_diagrams.md #4 -- merge_sort_recursive(): tracing the calls
//
// ! DISCUSSION: Why O(n log n)?
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
// ? SEE DIAGRAM: images/cpp_diagrams.md #2 -- merge_sort(): the public entry point
void merge_sort(std::vector<int>& data) {
    if (data.size() <= 1) return;
    merge_sort_recursive(data, 0, static_cast<int>(data.size()) - 1);
}

// =============================================================================
// 2. Quick Sort
// =============================================================================
//
// ? SEE DIAGRAM: images/cpp_diagrams.md #11 -- how the three functions work together
// ? SEE DIAGRAM: images/header_diagrams.md #5 -- quick sort: partition step
//

// ---------------------------------------------------------------------------
// 2a. partition() -- rearrange around a pivot
// ---------------------------------------------------------------------------
//
// ? SEE DIAGRAM: images/cpp_diagrams.md #15 -- partition() step 1: median-of-three pivot selection
// ? SEE DIAGRAM: images/cpp_diagrams.md #16 -- partition() step 2: scan and swap
// ? SEE DIAGRAM: images/cpp_diagrams.md #17 -- partition() step 3: place pivot in final position
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
// ? SEE DIAGRAM: images/cpp_diagrams.md #13 -- quick_sort_recursive(): the recursion (code)
// ? SEE DIAGRAM: images/cpp_diagrams.md #14 -- quick_sort_recursive(): tracing the calls
//
// ! DISCUSSION: Why O(n log n) average, O(n^2) worst?
//   - average case: pivot lands near the middle -> log n levels -> O(n log n)
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
// ? SEE DIAGRAM: images/cpp_diagrams.md #12 -- quick_sort(): the public entry point
void quick_sort(std::vector<int>& data) {
    if (data.size() <= 1) return;
    quick_sort_recursive(data, 0, static_cast<int>(data.size()) - 1);
}

// =============================================================================
// 3. Heap Sort
// =============================================================================
//
// ? SEE DIAGRAM: images/cpp_diagrams.md #18 -- how the two functions work together
// ? SEE DIAGRAM: images/header_diagrams.md #6 -- heap sort phase 1: build the max-heap
// ? SEE DIAGRAM: images/header_diagrams.md #7 -- heap sort phase 2: extract max repeatedly
//

// ---------------------------------------------------------------------------
// 3a. heapify_down() -- restore the max-heap property
// ---------------------------------------------------------------------------
//
// ? SEE DIAGRAM: images/cpp_diagrams.md #20 -- heapify_down(): step-by-step code walkthrough
//
// ! DISCUSSION: What is a max-heap?
//   - a complete binary tree stored in an array
//   - for any node at index i: left child = 2i+1, right child = 2i+2
//   - max-heap property: every parent is >= both children
//   - the root (index 0) is always the LARGEST element
//   - time per call: O(log n) -- at most the height of the tree
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
// ! DISCUSSION: Why heap sort is O(1) space.
//   - the heap IS the array -- no extra allocation needed
//   - contrast with merge sort's O(n) temporary array
//   - guaranteed O(n log n) with O(1) space, but not stable
//
// ? SEE DIAGRAM: images/cpp_diagrams.md #19 -- heap_sort(): two phases, one helper
// ? SEE DIAGRAM: images/cpp_diagrams.md #21 -- phase 1: build the max-heap
// ? SEE DIAGRAM: images/cpp_diagrams.md #22 -- phase 2: extract max repeatedly
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
