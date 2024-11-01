# C++ Sorting Program

## Overview
This C++ program allows users to load an array from a binary file, select a sorting algorithm, and sort the array using one of the four implemented sorting algorithms: Bubble Sort, Selection Sort, Insertion Sort, or Shell Sort. After sorting, the program displays the sorted array within user-defined bounds.

## Features
- **Sorting Algorithms**: Includes implementations of Bubble Sort, Selection Sort, Insertion Sort, and Shell Sort.
- **File Input**: Reads array data from a binary file, making it easy to test with various data sets.
- **Time Measurement**: Uses a timer to measure the sorting duration.
- **Customizable Output**: Allows the user to specify the range of the sorted array to display.

## Usage
1. Compile the program using a C++ compiler (e.g., `g++`).
2. Run the executable and provide a binary file containing the array data to be sorted.

### Running the Program
```bash
# Compile the program
g++ -o sorting_program sorting_program.cpp

# Run the compiled executable
./sorting_program
