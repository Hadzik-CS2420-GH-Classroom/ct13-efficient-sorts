# CT13 -- Implementation Diagrams

Code-block diagrams referenced from `EfficientSorts.cpp`.

---

## 1. merge() Step 1: Copy Halves to Temp Vectors
*`EfficientSorts.cpp::merge()` -- copy left and right halves before merging (why O(n) space)*

![merge() Step 1: Copy Halves](svgs/merge_step1_copy.svg)

---

## 2. merge() Step 2: Compare Fronts, Pick Smaller
*`EfficientSorts.cpp::merge()` -- the main merge loop with i, j, k pointers*

![merge() Step 2: Compare and Pick](svgs/merge_step2_compare.svg)

---

## 3. merge() Step 3: Copy Remaining Elements
*`EfficientSorts.cpp::merge()` -- when one half runs out, copy the rest*

![merge() Step 3: Copy Remaining](svgs/merge_step3_remaining.svg)

---

## 4. Partition: Rearranging Around a Pivot
*`EfficientSorts.cpp::partition()` -- scan with j, swap smaller elements left, place pivot*

![Partition: Rearranging Around a Pivot](svgs/partition_impl.svg)

---

## 5. Heapify Down: Restoring the Max-Heap
*`EfficientSorts.cpp::heapify_down()` -- compare with children, swap with largest, sink down*

![Heapify Down: Restoring the Max-Heap](svgs/heapify_down.svg)