# Data Structures Binary Trees

## Objective: To practice programming skills with linked-list-based implementation for binary search trees.

## Menu.h

 ### displayOperations:
Parameters none.
Returns nothing.
Displays a menu when called on.

### getOperation:
Parameters a reference integer to be altered based on user input. Checks for valid input i.e. a numerical value between 1 and 7.
Returns nothing.
Gets user input and performs input validation.

### callToTree:
Parameters a value to control the switch and a TreeNode class to alter.
Returns nothing.
Calls the various binary tree functions dependent on the user input.

### callToInsert:
Parameters a TreeNode to insert data into.
Returns nothing.
Calls to the insert function for tree node after collecting and validating user input.

### callToSearch:
Parameters a tree node to search into.
Returns nothing.
Calls to the search function for tree nodes after collecting and validating user input.

### callToDelete:
Parameters a tree node to delete a node from.
Returns nothing.
Calls to the delete function for tree nodes after collecting and validating user input.

## BinaryTree.h

### newNode:
Parameters the data to be inserted into the binary tree.
Returns a node with the given data.
Creates a new node with the data provided.

### search:
Parameters a tree to be search and the value to search for.
Returns the node if found.
Searches through the given tree for the value provided.

### insert:
Parameters a tree that should be inserted into and the value to be inserted.
Returns the tree with the newly inserted value.
Calls to newNode to create a new node and insert the node into the provided tree.

### minValueNode:
Parameters a tree to find the smallest value.
Returns the node with the smallest value.
Searches through the provided tree and returns the node with the smallest value.

### deleteNode:
Parameters a tree that should have a node be deleted and the value of the node to be deleted.
Returns the tree with the node deleted.
Deleted a node from the given tree with the value provided.

### printTree:
Parameters a tree to be printed and an index of 0.
Returns nothing.
Prints out the tree in a format that looks like the roots of the tree.

### printTreeInOrder:
Parameters the tree to be printed.
Returns nothing.
Prints out a list of the tree from highest to lowest values.

### maxSumPath:
Parameters the tree to be searched and counted.
Returns the count of the most expensive path.
Searches through the provided tree to find the most expensive path and returns the count of that path.

### getTargetLeaf:
Parameters a tree to be searched through, an reference to count the maximum sum, an reference to count the current sum and a target node.
Returns nothing.
Searches down each branch of the tree to count the sum of the values, the highest sum is stored.
