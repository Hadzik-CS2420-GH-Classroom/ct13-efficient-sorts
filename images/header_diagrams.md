# CT13 -- Header Diagrams

Conceptual diagrams referenced from `EfficientSorts.h`.

---

## 1. The Three O(n log n) Sorts
*`EfficientSorts.h` -- what merge sort, quick sort, and heap sort are and how they work at a high level*

![The Three O(n log n) Sorts](svgs/efficient_sorts_overview.svg)

---

## 2. O(n log n) vs O(n^2) Growth Comparison
*`EfficientSorts.h` -- why moving from quadratic to n log n sorts matters at scale*

![O(n log n) vs O(n^2) Growth Comparison](svgs/nlogn_vs_quadratic.svg)

---

## 3. Why O(n log n): Divide and Conquer
*`EfficientSorts.h` -- all three sorts divide the problem into log n levels with O(n) work each*

![Why O(n log n): Divide and Conquer](svgs/nlogn_why.svg)

---

## 4. Merge Sort -- Divide and Conquer Tree
*`EfficientSorts.h` -- split until single elements, then merge sorted halves back up*

![Merge Sort -- Divide and Conquer Tree](svgs/merge_sort_tree.svg)

---

## 5. Quick Sort -- Partition Step
*`EfficientSorts.h` -- pick a pivot, partition around it, recurse on each side*

![Quick Sort -- Partition Step](svgs/partition_step.svg)

---

## 6. Heap Sort Phase 1: Build the Max-Heap
*`EfficientSorts.h` -- rearrange the array so every parent is larger than its children*

![Heap Sort Phase 1: Build the Max-Heap](svgs/heap_sort_phase1.svg)

---

## 7. Heap Sort Phase 2: Extract Max Repeatedly
*`EfficientSorts.h` -- swap max to end, shrink heap, re-heapify until sorted*

![Heap Sort Phase 2: Extract Max Repeatedly](svgs/heap_sort_phase2.svg)

---

## 8. O(n log n) Sorts -- Side-by-Side Comparison
*`EfficientSorts.h` -- best/average/worst case, space, and stability at a glance*

![O(n log n) Sorts -- Side-by-Side Comparison](svgs/efficient_sorts_comparison.svg)
