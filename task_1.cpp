#include <iostream>
#include <ctime>
#include <cstdlib>

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

int quickselect(int arr[], int low, int high, int k) {
    if (low <= high) {
        int pivotIndex = partition(arr, low, high);

        if (pivotIndex == k) {
            return arr[pivotIndex];
        }
        else if (pivotIndex > k) {
            return quickselect(arr, low, pivotIndex - 1, k);
        }
        else {
            return quickselect(arr, pivotIndex + 1, high, k);
        }
    }

    // Invalid case
    return -1;
}

void printRunningTime(int N) {
    int* arr = new int[N];

    // Initialize the array with random values
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % N;
    }

    // Measure the running time
    clock_t startTime = clock();
    int k = N / 2;
    int result = quickselect(arr, 0, N - 1, k);
    clock_t endTime = clock();

    double runningTime = double(endTime - startTime) / CLOCKS_PER_SEC;

    // Output the result and running time
    std::cout << "N = " << N << ", k = " << k << std::endl;
    std::cout << "Result: " << result << std::endl;
    std::cout << "Running Time: " << runningTime << " seconds" << std::endl;

    delete[] arr;
}

int main() {
    int testCases[] = {1000, 5000, 10000, 50000, 100000};

    for (int i = 0; i < sizeof(testCases) / sizeof(testCases[0]); i++) {
        printRunningTime(testCases[i]);
        std::cout << std::endl;
    }

    return 0;
}
