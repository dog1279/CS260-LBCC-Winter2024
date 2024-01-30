## Assignment 3: Queue using Linked List

1. Line 22: Shows linked list queue.
2. Line 28: Shows implementation of enqueue. Line 110 and 125 show correct values being enqueued.
3. Line 43: Shows implementation of dequeue. Line 118 and 132 show correct values being dequeued.
4. Line 66: Shows implementation of peek. Line 113, 128, and 135 show correct value being peeked.

## enqueue(int value):

Time Complexity: O(1) <br>
Explanation: Enqueue operation involves adding a new node to the rear of the queue. Since the rear pointer is maintained, adding a new element is a constant time operation.

## dequeue():

Time Complexity: O(1) <br>
Explanation: Dequeue operation involves removing the front node of the queue. The head pointer is used to keep track of the front, and deleting the front element is a constant time operation.

## peek():

Time Complexity: O(1) <br>
Explanation: Peek operation involves looking at the front element of the queue without removing it. The head pointer is used, and accessing the front element is a constant time operation.

## display():

Time Complexity: O(n) <br>
Explanation: Display operation involves traversing the entire linked list to print each element. The time complexity is linear with respect to the number of elements in the queue.

## isEmpty():

Time Complexity: O(1) <br>
Explanation: Checking if the queue is empty involves a simple comparison of the head pointer. It is a constant time operation.
