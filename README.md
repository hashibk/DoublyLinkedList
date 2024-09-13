# Doubly Linked List Implementation in C++

This C++ program implements a doubly linked list (DLL) with a variety of features, including dynamic node insertion, deletion, duplicate removal, and reverse printing. The doubly linked structure allows traversal in both directions.

## Features

- **Insert at Start**: Insert a value at the start of the list.
- **Insert at End**: Insert a value at the end of the list.
- **Insert at Middle**: Insert a value in the middle of the list.
- **Insert Before**: Insert a value before a specified node.
- **Delete from Start**: Delete the first node of the list.
- **Delete from End**: Delete the last node of the list.
- **Remove Duplicates**: Remove all duplicate values from the list.
- **Print in Reverse**: Print the list from tail to head.
- **Print List**: Print the list from head to tail.

## Usage

1. **Insert Nodes**: Insert nodes at the start, end, or middle of the list.
2. **Duplicate Removal**: Remove all duplicate occurrences of values.
3. **Insert Before**: Insert a new value before another specified node.
4. **Print**: Print the elements of the list, or print them in reverse order.

### Example

The given example demonstrates inserting values, removing duplicates, and printing:

```cpp
dll.insertatend(7);
dll.insertatend(9);
dll.insertatstart(9);
dll.insertatend(10);
dll.insertatend(9);
dll.insertatmiddle(15);
dll.print();
dll.removeduplicates();
dll.insertBefore(6,10);
dll.print();
dll.reverseprint();
dll.print();

Output:

9 7 9 15 9 10 
9 7 15 6 10 
10 6 15 7 9 
9 7 15 6 10
