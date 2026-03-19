#include <gtest/gtest.h>
#include "EfficientSorts.h"
#include <algorithm>
#include <numeric>

// =============================================================================
// Helper: verify a vector is sorted in ascending order
// =============================================================================
static bool is_sorted_ascending(const std::vector<int>& data) {
    for (int i = 1; i < static_cast<int>(data.size()); ++i) {
        if (data[i] < data[i - 1]) return false;
    }
    return true;
}

// =============================================================================
// Merge Sort Tests (10 points)
// =============================================================================

TEST(MergeSort, BasicSort) {
    std::vector<int> data = {5, 3, 8, 1, 9, 2};
    merge_sort(data);
    EXPECT_TRUE(is_sorted_ascending(data));
}

TEST(MergeSort, AlreadySorted) {
    std::vector<int> data = {1, 2, 3, 4, 5};
    merge_sort(data);
    EXPECT_TRUE(is_sorted_ascending(data));
    EXPECT_EQ(data[0], 1);
    EXPECT_EQ(data[4], 5);
}

TEST(MergeSort, ReverseSorted) {
    std::vector<int> data = {5, 4, 3, 2, 1};
    merge_sort(data);
    EXPECT_TRUE(is_sorted_ascending(data));
}

TEST(MergeSort, SingleElement) {
    std::vector<int> data = {42};
    merge_sort(data);
    EXPECT_EQ(data[0], 42);
}

TEST(MergeSort, EmptyVector) {
    std::vector<int> data;
    merge_sort(data);
    EXPECT_TRUE(data.empty());
}

TEST(MergeSort, Duplicates) {
    std::vector<int> data = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    merge_sort(data);
    EXPECT_TRUE(is_sorted_ascending(data));
    EXPECT_EQ(data.size(), 10u);
}

TEST(MergeSort, NegativeNumbers) {
    std::vector<int> data = {-3, 0, -7, 4, -1, 2};
    merge_sort(data);
    EXPECT_TRUE(is_sorted_ascending(data));
    EXPECT_EQ(data[0], -7);
    EXPECT_EQ(data[5], 4);
}

TEST(MergeSort, LargerDataset) {
    std::vector<int> data(200);
    std::iota(data.begin(), data.end(), 0);
    std::reverse(data.begin(), data.end());
    merge_sort(data);
    EXPECT_TRUE(is_sorted_ascending(data));
    EXPECT_EQ(data[0], 0);
    EXPECT_EQ(data[199], 199);
}

// =============================================================================
// Quick Sort Tests (10 points)
// =============================================================================

TEST(QuickSort, BasicSort) {
    std::vector<int> data = {5, 3, 8, 1, 9, 2};
    quick_sort(data);
    EXPECT_TRUE(is_sorted_ascending(data));
}

TEST(QuickSort, AlreadySorted) {
    std::vector<int> data = {1, 2, 3, 4, 5};
    quick_sort(data);
    EXPECT_TRUE(is_sorted_ascending(data));
}

TEST(QuickSort, ReverseSorted) {
    std::vector<int> data = {5, 4, 3, 2, 1};
    quick_sort(data);
    EXPECT_TRUE(is_sorted_ascending(data));
}

TEST(QuickSort, SingleElement) {
    std::vector<int> data = {42};
    quick_sort(data);
    EXPECT_EQ(data[0], 42);
}

TEST(QuickSort, EmptyVector) {
    std::vector<int> data;
    quick_sort(data);
    EXPECT_TRUE(data.empty());
}

TEST(QuickSort, Duplicates) {
    std::vector<int> data = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    quick_sort(data);
    EXPECT_TRUE(is_sorted_ascending(data));
}

TEST(QuickSort, AllSameValue) {
    std::vector<int> data = {7, 7, 7, 7, 7};
    quick_sort(data);
    EXPECT_TRUE(is_sorted_ascending(data));
}

TEST(QuickSort, LargerDataset) {
    std::vector<int> data(200);
    std::iota(data.begin(), data.end(), 0);
    std::reverse(data.begin(), data.end());
    quick_sort(data);
    EXPECT_TRUE(is_sorted_ascending(data));
    EXPECT_EQ(data[0], 0);
    EXPECT_EQ(data[199], 199);
}

TEST(QuickSort, TwoElements) {
    std::vector<int> data = {9, 1};
    quick_sort(data);
    EXPECT_EQ(data[0], 1);
    EXPECT_EQ(data[1], 9);
}

TEST(QuickSort, ThreeElements) {
    std::vector<int> data = {3, 1, 2};
    quick_sort(data);
    EXPECT_EQ(data[0], 1);
    EXPECT_EQ(data[1], 2);
    EXPECT_EQ(data[2], 3);
}

// =============================================================================
// Heap Sort Tests (10 points)
// =============================================================================

TEST(HeapSort, BasicSort) {
    std::vector<int> data = {5, 3, 8, 1, 9, 2};
    heap_sort(data);
    EXPECT_TRUE(is_sorted_ascending(data));
}

TEST(HeapSort, AlreadySorted) {
    std::vector<int> data = {1, 2, 3, 4, 5};
    heap_sort(data);
    EXPECT_TRUE(is_sorted_ascending(data));
}

TEST(HeapSort, ReverseSorted) {
    std::vector<int> data = {5, 4, 3, 2, 1};
    heap_sort(data);
    EXPECT_TRUE(is_sorted_ascending(data));
}

TEST(HeapSort, SingleElement) {
    std::vector<int> data = {42};
    heap_sort(data);
    EXPECT_EQ(data[0], 42);
}

TEST(HeapSort, EmptyVector) {
    std::vector<int> data;
    heap_sort(data);
    EXPECT_TRUE(data.empty());
}

TEST(HeapSort, Duplicates) {
    std::vector<int> data = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
    heap_sort(data);
    EXPECT_TRUE(is_sorted_ascending(data));
}

TEST(HeapSort, AllSameValue) {
    std::vector<int> data = {7, 7, 7, 7, 7};
    heap_sort(data);
    EXPECT_TRUE(is_sorted_ascending(data));
}

TEST(HeapSort, NegativeNumbers) {
    std::vector<int> data = {-3, 0, -7, 4, -1, 2};
    heap_sort(data);
    EXPECT_TRUE(is_sorted_ascending(data));
    EXPECT_EQ(data[0], -7);
}

TEST(HeapSort, LargerDataset) {
    std::vector<int> data(200);
    std::iota(data.begin(), data.end(), 0);
    std::reverse(data.begin(), data.end());
    heap_sort(data);
    EXPECT_TRUE(is_sorted_ascending(data));
    EXPECT_EQ(data[0], 0);
    EXPECT_EQ(data[199], 199);
}

TEST(HeapSort, TwoElements) {
    std::vector<int> data = {9, 1};
    heap_sort(data);
    EXPECT_EQ(data[0], 1);
    EXPECT_EQ(data[1], 9);
}
