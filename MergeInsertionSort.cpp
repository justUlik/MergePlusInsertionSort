#include <iostream>
#include <algorithm>
#include <cstdint>
#include <vector>
#include "SortTester.h"

const int kThreshold = 30;

void InsertionSort(std::vector<int>& arr) {
  size_t n = arr.size();
  for (size_t i = 1; i < n; ++i) {
    int key = arr[i];
    int j = i - 1;

    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      --j;
    }
    arr[j + 1] = key;
  }
}

std::vector<int> Merge(const std::vector<int> &first, const std::vector<int> &second) {
  int i = 0;
  int j = 0;
  std::vector<int> res;
  while (i != first.size() && j != second.size()) {
    if (first[i] <= second[j]) {
      res.push_back(first[i]);
      ++i;
    } else {
      res.push_back(second[j]);
      ++j;
    }
  }
  while (i != first.size()) {
    res.push_back(first[i]);
    ++i;
  }
  while (j != second.size()) {
    res.push_back(second[j]);
    ++j;
  }
  return res;
}

std::vector<int> MergeSort(std::vector<int> &arr) {
  if (arr.size() <= kThreshold) {
    InsertionSort(arr);
    return arr;
  }
  std::vector<int> first;
  std::vector<int> second;
  for (size_t i = 0; i < arr.size(); ++i) {
    if (i < arr.size() / 2) {
      first.push_back(arr[i]);
    } else {
      second.push_back(arr[i]);
    }
  }
  first = MergeSort(first);
  second = MergeSort(second);
  return Merge(first, second);
}

void MergeSortWrapper(std::vector<int>& array) {
  array = MergeSort(array);
}

int main() {
  SortTester tester(10);

  std::cout << "Testing MergeInsertionSort on NearlySorted Arrays:\n";
  tester.TestSort(MergeSortWrapper, "NearlySorted");
  return 0;
}

