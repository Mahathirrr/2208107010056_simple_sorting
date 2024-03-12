#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

// Fungsi untuk membuat folder jika belum ada
void createFolder(const char *folder) {
    #ifdef _WIN32
        mkdir(folder);
    #else
        mkdir(folder, 0777);
    #endif
}

// Fungsi untuk menyimpan array ke dalam file txt
void saveToFile(int arr[], int n, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Gagal membuka file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++) {
        fprintf(file, "%d\n", arr[i]);
    }

    fclose(file);
}

// Fungsi untuk melakukan bubble sort
void bubbleSort(int arr[], int n, const char *filename) {
    int i, j;
    for (i = 0; i < n-1; i++)
        for (j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1]) {
                // Swap bilangan jika tidak terurut
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
    saveToFile(arr, n, filename);
}

// Fungsi untuk melakukan selection sort
void selectionSort(int arr[], int n, const char *filename) {
    int i, j, min_idx;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        // Swap bilangan jika tidak terurut
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
    saveToFile(arr, n, filename);
}

// Fungsi untuk melakukan insertion sort
void insertionSort(int arr[], int n, const char *filename) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Pindahkan elemen yang lebih besar dari key ke posisi setelahnya
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    saveToFile(arr, n, filename);
}

// Fungsi untuk mencetak garis tepi tabel
void printTableBorder(int width) {
    for (int i = 0; i < width; i++) {
        printf("-");
    }
    printf("\n");
}

int main() {
    // Inisialisasi variabel
    const int maxNumbers = 1000000;
    const int step = 100000;
    const char *inputFolder = "input";
    const char *outputFolder = "output";

    // Membuat folder input dan output jika belum ada
    createFolder(inputFolder);
    createFolder(outputFolder);

    int *numbers = (int*)malloc(maxNumbers * sizeof(int));

    // Generate bilangan secara acak dan menyimpan ke dalam file input
    srand(time(NULL));
    for (int i = 0; i < maxNumbers; i++) {
        numbers[i] = rand();
    }

    char inputFilename[50];
    sprintf(inputFilename, "%s/input.txt", inputFolder);
    saveToFile(numbers, maxNumbers, inputFilename);

    // Melakukan pengurutan dan menyimpan hasil ke dalam file
    printTableBorder(59);
    printf("| %-15s | %-15s | %-20s |\n", "Jenis Algoritma", "Jumlah Bilangan", "Waktu Eksekusi (ms)");
    printTableBorder(59);
    for (int n = step; n <= maxNumbers; n += step) {
        int *copyNumbers = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            copyNumbers[i] = numbers[i];
        }

        // Bubble Sort
        char bubbleFilename[50];
        sprintf(bubbleFilename, "%s/%d_bubble.txt", outputFolder, n);
        clock_t start = clock();
        bubbleSort(copyNumbers, n, bubbleFilename);
        clock_t end = clock();
        double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC * 1000;
        printf("| %-15s | %-15d | %-20f |\n", "Bubble Sort", n, cpu_time_used);

        // Selection Sort
        char selectionFilename[50];
        sprintf(selectionFilename, "%s/%d_selection.txt", outputFolder, n);
        start = clock();
        selectionSort(copyNumbers, n, selectionFilename);
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC * 1000;
        printf("| %-15s | %-15d | %-20f |\n", "Selection Sort", n, cpu_time_used);

        // Insertion Sort
        char insertionFilename[50];
        sprintf(insertionFilename, "%s/%d_insertion.txt", outputFolder, n);
        start = clock();
        insertionSort(copyNumbers, n, insertionFilename);
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC * 1000;
        printf("| %-15s | %-15d | %-20f |\n", "Insertion Sort", n, cpu_time_used);

        // Mencetak garis tepi antara setiap baris tabel
        printTableBorder(59);

        free(copyNumbers);
    }

    free(numbers);

    return 0;
}
