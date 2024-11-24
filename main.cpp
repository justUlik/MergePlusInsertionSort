#include <iostream>
#include "ArrayGenerator.h"

int main()
{
    try {
        ArrayGenerator generator;

        for (int test_size = 500; test_size <= 1000; test_size += 100) {
            auto random_array = generator.GetRandomArray(test_size);
            auto reversed_array = generator.GetReversedArray(test_size);
            auto nearly_sorted_array = generator.GetNearlySortedArray(test_size);

            std::cout << "Size: " << test_size << "\n";

            std::cout << "Random Array (first 5 elements): ";
            for (int i = 0; i < 5; ++i) {
                std::cout << random_array[i] << " ";
            }
            std::cout << "\n";

            std::cout << "Reversed Array (first 5 elements): ";
            for (int i = 0; i < 5; ++i) {
                std::cout << reversed_array[i] << " ";
            }
            std::cout << "\n";

            std::cout << "Nearly Sorted Array (first 5 elements): ";
            for (int i = 0; i < 5; ++i) {
                std::cout << nearly_sorted_array[i] << " ";
            }
            std::cout << "\n";

            std::cout << "------------------------------------\n";
        }
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
}
