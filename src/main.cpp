// =============================================================================
// CT13: O(n log n) Sorting Algorithms -- Exam Score Sorter
// =============================================================================
//
// Scenario: sort student exam scores using three efficient sorting algorithms.
// These are dramatically faster than CT12's O(n^2) sorts on large datasets.
//

#include <iostream>
#include <vector>
#include "EfficientSorts.h"

int main() {
    std::cout << "=== CT13: O(n log n) Sorting Algorithms ===\n";
    std::cout << "=== Scenario: Sorting Exam Scores (Efficiently) ===\n\n";

    // -----------------------------------------------------------------------
    // 1. Merge Sort -- divide in half, sort each half, merge
    // -----------------------------------------------------------------------
    //
    // ! DISCUSSION: Merge sort is the "safe" O(n log n) sort.
    //   - guaranteed O(n log n) in ALL cases (no bad-pivot risk)
    //   - stable: equal elements keep their original order
    //   - tradeoff: needs O(n) extra space for the temporary merge arrays
    //   - used by Python's sort (Timsort is a merge sort variant)
    //
    std::cout << "--- Part 1: Merge Sort ---\n";
    std::vector<int> scores1 = {78, 95, 62, 88, 73, 91, 55, 82, 67, 84};

    print_vector(scores1, "  Unsorted: ");
    merge_sort(scores1);
    print_vector(scores1, "  Sorted:   ");

    // -----------------------------------------------------------------------
    // 2. Quick Sort -- partition around pivot, sort each side
    // -----------------------------------------------------------------------
    //
    // ! DISCUSSION: Quick sort is usually the fastest in practice.
    //   - O(n log n) average, but O(n^2) worst case (very rare with good pivot)
    //   - in-place: O(log n) space (just the recursion stack)
    //   - cache-friendly: works on contiguous memory
    //   - C++'s std::sort uses a quick sort variant (introsort)
    //   - NOT stable: partitioning can reorder equal elements
    //
    std::cout << "\n--- Part 2: Quick Sort ---\n";
    std::vector<int> scores2 = {78, 95, 62, 88, 73, 91, 55, 82, 67, 84};

    print_vector(scores2, "  Unsorted: ");
    quick_sort(scores2);
    print_vector(scores2, "  Sorted:   ");

    // -----------------------------------------------------------------------
    // 3. Heap Sort -- build max-heap, extract max repeatedly
    // -----------------------------------------------------------------------
    //
    // ! DISCUSSION: Heap sort gives guaranteed O(n log n) with O(1) space.
    //   - no extra arrays needed (the heap IS the array)
    //   - guaranteed O(n log n) -- no worst-case degradation like quick sort
    //   - NOT stable: heap operations move distant elements
    //   - poor cache performance (parent/child indices jump around)
    //   - rarely used alone, but the heap data structure is widely used
    //     (priority queues, Dijkstra's algorithm in Module 8)
    //
    std::cout << "\n--- Part 3: Heap Sort ---\n";
    std::vector<int> scores3 = {78, 95, 62, 88, 73, 91, 55, 82, 67, 84};

    print_vector(scores3, "  Unsorted: ");
    heap_sort(scores3);
    print_vector(scores3, "  Sorted:   ");

    // -----------------------------------------------------------------------
    // 4. Larger dataset -- show all three produce the same result
    // -----------------------------------------------------------------------
    //
    // ! DISCUSSION: All three algorithms produce the same sorted output.
    //   - the difference is HOW they get there and the tradeoffs:
    //     merge sort:  stable, O(n) space, guaranteed O(n log n)
    //     quick sort:  fastest in practice, O(log n) space, O(n^2) worst case
    //     heap sort:   O(1) space, guaranteed O(n log n), poor cache locality
    //
    std::cout << "\n--- Part 4: Larger Dataset (20 scores) ---\n";
    std::vector<int> big_scores = {78, 95, 62, 88, 73, 91, 55, 82, 67, 84,
                                   99, 71, 86, 60, 93, 77, 81, 58, 90, 65};

    std::vector<int> test1 = big_scores;
    merge_sort(test1);
    print_vector(test1, "  Merge:  ");

    std::vector<int> test2 = big_scores;
    quick_sort(test2);
    print_vector(test2, "  Quick:  ");

    std::vector<int> test3 = big_scores;
    heap_sort(test3);
    print_vector(test3, "  Heap:   ");

    // -----------------------------------------------------------------------
    // 5. Summary -- compare all O(n log n) sorts
    // -----------------------------------------------------------------------
    std::cout << "\n--- Summary ---\n";
    std::cout << "  Algorithm  | Time (avg)  | Time (worst) | Space    | Stable?\n";
    std::cout << "  -----------|-------------|--------------|----------|---------\n";
    std::cout << "  Merge Sort | O(n log n)  | O(n log n)   | O(n)     | Yes\n";
    std::cout << "  Quick Sort | O(n log n)  | O(n^2)       | O(log n) | No\n";
    std::cout << "  Heap Sort  | O(n log n)  | O(n log n)   | O(1)     | No\n";
    std::cout << "\n  All three are O(n log n) average case.\n";
    std::cout << "  Quick sort is fastest in practice (cache-friendly, low overhead).\n";
    std::cout << "  Merge sort is the safe choice (stable, guaranteed performance).\n";
    std::cout << "  Heap sort wins on space (O(1), no extra arrays).\n";

    // -----------------------------------------------------------------------
    // 6. Bucket sort overview (discussion only -- no implementation)
    // -----------------------------------------------------------------------
    //
    // ! DISCUSSION: Bucket sort -- a different approach entirely.
    //   - NOT comparison-based: doesn't use < or > to sort
    //   - distributes elements into "buckets" based on value ranges
    //   - sort each bucket (with insertion sort or similar), concatenate
    //   - Time: O(n + k) where k is the number of buckets
    //     - best case O(n) when elements distribute evenly across buckets
    //     - worst case O(n^2) when all elements land in one bucket
    //   - Space: O(n + k) -- need storage for all buckets
    //   - Works best when input is uniformly distributed over a known range
    //   - Example: sorting exam scores 0-100 into 10 buckets (0-9, 10-19, ...)
    //
    std::cout << "\n--- Bucket Sort (Discussion Only) ---\n";
    std::cout << "  Bucket sort is NOT comparison-based.\n";
    std::cout << "  It distributes elements into buckets by value range.\n";
    std::cout << "  Time: O(n + k) average, O(n^2) worst (all in one bucket).\n";
    std::cout << "  Space: O(n + k).\n";
    std::cout << "  Best for uniformly distributed data over a known range.\n";

    std::cout << "\n=== CT13 Complete ===\n";
    return 0;
}
