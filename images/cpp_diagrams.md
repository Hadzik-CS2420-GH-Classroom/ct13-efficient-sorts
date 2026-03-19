# CT13 -- Implementation Diagrams

Code-block diagrams referenced from `EfficientSorts.cpp`.

---

## 1. Merge -- Merging Two Sorted Halves
*`EfficientSorts.cpp::merge()` -- compare front of each half, pick smaller, repeat*

![Merge -- Merging Two Sorted Halves](svgs/merge_step.svg)

---

## 2. Merge Sort -- Divide and Conquer Tree
*`EfficientSorts.cpp::merge_sort_recursive()` -- split until single elements, merge back up*

![Merge Sort -- Divide and Conquer Tree](svgs/merge_sort_tree.svg)

---

## 3. Quick Sort -- Partition Step
*`EfficientSorts.cpp::partition()` -- pivot chosen, i tracks boundary, j scans, pivot placed*

![Quick Sort -- Partition Step](svgs/partition_step.svg)

---

## 4. Heap Sort -- Heapify Down
*`EfficientSorts.cpp::heapify_down()` -- small root sinks to correct level in max-heap*

![Heap Sort -- Heapify Down](svgs/heapify_down.svg)

---

## 5. Heap Sort -- Two Phases
*`EfficientSorts.cpp::heap_sort()` -- Phase 1: build max-heap. Phase 2: extract max repeatedly*

![Heap Sort -- Two Phases](svgs/heap_sort_phases.svg)
