#include <iostream>
#include <algorithm>
#include <cstdint>
#include <vector>
#include "SortTester.h"

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
  if (arr.size() <= 1) {
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

  std::cout << "Testing MergeSort on Random Arrays:\n";
  tester.TestSort(MergeSortWrapper, "Random");
  return 0;
}
