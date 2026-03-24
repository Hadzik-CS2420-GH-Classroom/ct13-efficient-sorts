# CT13 -- Implementation Diagrams

Code-block diagrams referenced from `EfficientSorts.cpp`.

---

## 1. Merge -- Combining Two Sorted Halves
*`EfficientSorts.cpp::merge()` -- copy halves to temp vectors, interleave back in sorted order*

![Merge -- Combining Two Sorted Halves](svgs/merge_step.svg)

---

## 2. Partition -- Rearranging Around a Pivot
*`EfficientSorts.cpp::partition()` -- scan, swap smaller elements left, place pivot in final position*

![Partition -- Rearranging Around a Pivot](svgs/partition_impl.svg)

---

## 3. Heapify Down -- Restoring the Max-Heap
*`EfficientSorts.cpp::heapify_down()` -- compare with children, swap with largest, sink down*

![Heapify Down -- Restoring the Max-Heap](svgs/heapify_down.svg)