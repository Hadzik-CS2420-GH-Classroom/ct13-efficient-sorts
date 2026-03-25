# CT13 -- Implementation Diagrams

Code-block diagrams referenced from `EfficientSorts.cpp`.

---

## 1. merge_sort(): The Public Entry Point
*`EfficientSorts.cpp::merge_sort()` -- the clean API that delegates to the recursive helper*

![merge_sort(): The Public Entry Point](svgs/merge_sort_wrapper.svg)

---

## 2. merge_sort_recursive(): The Recursion (Code)
*`EfficientSorts.cpp::merge_sort_recursive()` -- split in half, recurse, then merge*

![merge_sort_recursive(): The Recursion](svgs/merge_sort_recursive_code.svg)

---

## 3. merge_sort_recursive(): Tracing the Calls
*Watch the recursion unfold on [38, 55, 32, 95] -- split down, merge back up*

![merge_sort_recursive(): Tracing the Calls](svgs/merge_sort_recursive_trace.svg)

---

## 4. merge() Step 1: Copy Halves to Temp Vectors
*Now zooming into merge(), the function that merge_sort_recursive() calls at each level.*
*`EfficientSorts.cpp::merge()` -- calculate mid, copy left and right halves (why O(n) space)*

![merge() Step 1: Copy Halves](svgs/merge_step1_copy.svg)

---

## 5. merge() Step 2: Compare Fronts, Pick Smaller
*`EfficientSorts.cpp::merge()` -- the main merge loop with i, j, k pointers*

![merge() Step 2: Compare and Pick](svgs/merge_step2_compare.svg)

---

## 6. merge() Step 3: Copy Remaining Elements
*`EfficientSorts.cpp::merge()` -- when one half runs out, copy the rest*

![merge() Step 3: Copy Remaining](svgs/merge_step3_remaining.svg)

---

## 7. Partition: Rearranging Around a Pivot
*`EfficientSorts.cpp::partition()` -- scan with j, swap smaller elements left, place pivot*

![Partition: Rearranging Around a Pivot](svgs/partition_impl.svg)

---

## 8. Heapify Down: Restoring the Max-Heap
*`EfficientSorts.cpp::heapify_down()` -- compare with children, swap with largest, sink down*

![Heapify Down: Restoring the Max-Heap](svgs/heapify_down.svg)