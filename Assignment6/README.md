## Design

The design of the binary search tree includes:

- Each node in the BST stores a value and pointers to its left and right children.
- The BST maintains the ordering property: values less than or equal to a node are stored in its left subtree, and values greater than the node are stored in its right subtree.

## Tests

The following tests ensure the correctness of the implemented BST:

1. **Test add function:**

   - Adds values to the tree and verifies they are inserted correctly.
   - Example code:
     ```cpp
     tree.add(5);
     tree.add(3);
     tree.add(7);
     ```

2. **Test remove function:**

   - Adds values to the tree, removes some values, and ensures the tree structure is maintained correctly after removal.
   - Example code:
     ```cpp
     tree.remove(3);
     tree.remove(7);
     ```

3. **Test in-order traversal:**
   - Creates a tree with known values, traverses it in-order, and verifies the values are visited in ascending order.
   - Example code:
     ```cpp
     tree.inOrderTraversal();
     // Expected output: 1 4 5 6 9
     ```

## Implementation

The implementation consists of a `BST` class with functions for adding, removing, and traversing the tree. Here are the relevant lines of code for each function:

- Add function:

  ```cpp
  void add(int value) {
      root = addRecursive(root, value);
  }

  ```

- Remove function:

  ```cpp
    void remove(int value) {
    root = removeRecursive(root, value);
    }

  ```

- In-order traversal:

  ```cpp
  void inOrderTraversal() {
  inOrderRecursive(root);
  std::cout << std::endl;
  }
  ```

Disclaimer: do you like my fancy new readme? I used chatgpts help to make it look way better!
