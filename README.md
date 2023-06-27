# Data Structures and Algorithms in C

This repository contains implementations of various data structures and basic algorithms in C. 
It provides code examples for lists, queues, stacks (both array-based and linked-list-based), binary trees, binary search trees, and sorting algorithms. 
Each abstract data type (ADT) is defined by a pair of .c and .h modules for both array implementation and linked list implementation, following the principles of information hiding and modularity.
The ADTs utilize a pseudo-generics approach using the Item ADT, which is defined as `typedef void * Item` in `item.h`.

Every module has extensive comment to explain each function. (In `Italian` Only for Now).

## Item Implementation

- `item_int.c` : Implementation of Item to manage integers
- `item_str.c` : Implementation of Item to manage strings
- `item.h` : Interface for both.

## Data Structures

### Lists

- `list.c` : Implementation of a list using linked lists.
- `list.h` : Interface

### Queues

- `queue_array.c`: Implementation of a queue using arrays.
- `queue_list.c` : Implementation of a queue using linked lists.
- `queue.h` : Interface.

### Stacks

- `stack_array.c`: Implementation of a stack using arrays.
- `stack_linked.c`: Implementation of a stack using linked lists.
- `stack.h` : Interface.

### Binary Trees

- `btree.c` and `btree.h`: Implementation of a binary tree.

### Binary Search Trees

- `bst.c` and `bst.h`: Implementation of a binary search tree.

## Sorting Algorithms

### Array-based Sorting

- `vector.c` and `vector.h`: Implementation of sorting algorithms for arrays.
  - Selection Sort (`selection_sort`)
  - Insertion Sort (`insertion_sort`)
  - Bubble Sort (`bubble_sort`)
  - Quicksort (`quick_sort`)
  - Mergesort (`merge_sort`)

### List-based Sorting

- In `list.c` : Implementation of Mergesort for linked lists (nodes sorted).
- In `list.c` : Implementation of SelectionSort and BubbleSort for linked lists (Items sorted).

## Arrays Management

- In `vector.c` : It contains other functions for arrays like binary search, input and output array.

## Usage

To use any of the provided data structures or algorithms, you can include the respective .h file in your C project. Each .c module contains the implementation details and is linked with its corresponding .h file. The modules follow the principles of information hiding and modularity, allowing you to use the ADTs with ease.

## Contributing

Contributions to this repository are welcome! If you find any bugs, have suggestions for improvements, or would like to add new features, please feel free to open an issue or submit a pull request.

## License and Warranty

This project is available under the Unlicense, which means it is released to the public domain. You can use, modify, and distribute the code without any restrictions. However, please note that this code comes with no warranty or guarantee of any kind. Use it at your own risk.

Please refer to the [LICENSE](LICENSE) file for more details.



