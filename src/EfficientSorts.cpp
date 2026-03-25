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
    // Step 1: Copy both halves into temp vectors
    // ? SEE DIAGRAM: images/cpp_diagrams.md #5 -- step 1 (2-element merge)
    // ? SEE DIAGRAM: images/cpp_diagrams.md #8 -- step 1 (4-element final merge)
    std::vector<int> left_half(data.begin() + left, data.begin() + mid + 1);
    std::vector<int> right_half(data.begin() + mid + 1, data.begin() + right + 1);

    // Step 2: Merge back -- compare fronts, pick smaller
    // ? SEE DIAGRAM: images/cpp_diagrams.md #6 -- step 2 (2-element merge)
    // ? SEE DIAGRAM: images/cpp_diagrams.md #9 -- step 2 (4-element final merge)
    int i = 0, j = 0, k = left;
    while (i < static_cast<int>(left_half.size()) && j < static_cast<int>(right_half.size())) {
        if (left_half[i] <= right_half[j]) {
            data[k++] = left_half[i++];
        } else {
            data[k++] = right_half[j++];
        }
    }

    // Step 3: Copy any remaining elements
    // ? SEE DIAGRAM: images/cpp_diagrams.md #7 -- step 3 (2-element merge)
    // ? SEE DIAGRAM: images/cpp_diagrams.md #10 -- step 3 (4-element final merge)
    while (i < static_cast<int>(left_half.size())) {
        data[k++] = left_half[i++];
    }
    while (j < static_cast<int>(right_half.size())) {
        data[k++] = right_half[j++];
    }
}

// ---------------------------------------------------------------------------
// 1b. merge_sort_recursive() -- divide and conquer
// ---------------------------------------------------------------------------
//
// ? SEE DIAGRAM: images/header_diagrams.md #4 -- merge sort: divide and conquer tree (big picture)
// ? SEE DIAGRAM: images/cpp_diagrams.md #3 -- merge_sort_recursive(): the recursion (code)
// ? SEE DIAGRAM: images/cpp_diagrams.md #4 -- merge_sort_recursive(): tracing the calls
//
// ! DISCUSSION: Why O(n log n)?
//   - the recursion creates log n levels (halving each time)
//   - at each level, merging does O(n) work total
//   - total: O(n) * O(log n) = O(n log n)
//
static void merge_sort_recursive(std::vector<int>& data, int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    merge_sort_recursive(data, left, mid);
    merge_sort_recursive(data, mid + 1, right);
    merge(data, left, mid, right);
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
    // Step 1: Median-of-three pivot selection
    int mid = low + (high - low) / 2;
    if (data[mid] < data[low]) std::swap(data[low], data[mid]);
    if (data[high] < data[low]) std::swap(data[low], data[high]);
    if (data[mid] < data[high]) std::swap(data[mid], data[high]);
    int pivot = data[high];

    // Step 2: Partition
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (data[j] <= pivot) {
            ++i;
            std::swap(data[i], data[j]);
        }
    }
    std::swap(data[i + 1], data[high]);
    return i + 1;
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
    if (low >= high) return;

    int pivot_idx = partition(data, low, high);
    quick_sort_recursive(data, low, pivot_idx - 1);
    quick_sort_recursive(data, pivot_idx + 1, high);
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
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heap_size && data[left] > data[largest]) largest = left;
    if (right < heap_size && data[right] > data[largest]) largest = right;

    if (largest != index) {
        std::swap(data[index], data[largest]);
        heapify_down(data, heap_size, largest);
    }
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

    // Phase 1: Build max-heap
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify_down(data, n, i);
    }

    // Phase 2: Extract max repeatedly
    for (int i = n - 1; i >= 1; --i) {
        std::swap(data[0], data[i]);
        heapify_down(data, i, 0);
    }
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
