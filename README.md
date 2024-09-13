# Enhanced Doubly Linked List Implementation in C++

This C++ program implements a doubly linked list (DLL) with advanced features including dynamic node insertion, deletion, duplicate removal, and middle node detection. The doubly linked structure allows bidirectional traversal and management of list nodes.

## Features

- **Insert at Start**: Insert a value at the beginning of the list.
- **Insert at End**: Insert a value at the end of the list.
- **Insert at Middle**: Insert a value in the middle of the list.
- **Insert Before**: Insert a new value before a specified node.
- **Delete from Start**: Remove the first node of the list.
- **Delete from End**: Remove the last node of the list.
- **Remove Duplicates**: Eliminate all duplicate values from the list.
- **Print List**: Print the list from head to tail.
- **Print in Reverse**: Print the list from tail to head.
- **Middle Node**: Print the middle node of the list.

## Usage

1. **Insert Nodes**: Insert nodes at the start, end, or middle of the list.
2. **Remove Duplicates**: Remove duplicate nodes from the list.
3. **Insert Before**: Add a new node before a specified existing node.
4. **Print and Reverse Print**: Display the list in normal and reverse order.
5. **Middle Node Detection**: Print the middle node of the list.

### Example

The following operations are demonstrated:

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
dll.insertatend(10);
dll.print();
dll.middleNode();
Output:

9 7 9 15 9 10 
9 7 15 6 10 
10 6 15 7 9 
9 7 15 6 10 10 
15
