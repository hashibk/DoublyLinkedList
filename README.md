# Doubly Linked List with Various Operations

This C++ program implements a doubly linked list with multiple operations, including insertion, deletion, and node manipulation. The list allows for inserting elements at different positions, removing duplicates, and swapping nodes.

## Features

- **Insertion Operations**:
  - Insert at the start
  - Insert at the end
  - Insert at the middle
  - Insert before a specific node

- **Deletion Operations**:
  - Delete from the start
  - Delete from the end

- **Traversal Operations**:
  - Print list in normal order
  - Print list in reverse order

- **Additional Operations**:
  - Remove duplicate elements
  - Find and print the middle node
  - Swap nodes based on their position

## Usage

1. **Insertion**:
   - Use `insertatstart(T d)` to insert a node at the beginning.
   - Use `insertatend(T d)` to insert a node at the end.
   - Use `insertatmiddle(T d)` to insert a node in the middle.
   - Use `insertBefore(T const v1, T const v2)` to insert a node before a specified node with value `v2`.

2. **Deletion**:
   - Use `deletefromstart()` to remove the first node.
   - Use `deletefromend()` to remove the last node.

3. **Traversal**:
   - Use `print()` to display the list from start to end.
   - Use `reverseprint()` to display the list from end to start.

4. **Additional Operations**:
   - Use `removeduplicates()` to remove duplicate values.
   - Use `middleNode()` to find and print the middle node.
   - Use `nodeswap(int k)` to swap the k-th node from the start with the k-th node from the end.

### Example

In the given code:

- Elements are inserted into the list: 7, 9, 9, 10, 9, 15, and 10.
- Duplicates are removed, a node with value 6 is inserted before the node with value 10.
- The list is then printed, reversed, and the middle node is displayed.
- Nodes at position 2 are swapped.

**Output**:
```plaintext
9 7 9 15 10 9 
9 7 15 6 10 //after removal of duplicates
10 6 15 7 9 //reverse print
9 7 15 6 10 10 //more insertion
6 //middle node
9 10 15 6 7 10 //node swap
