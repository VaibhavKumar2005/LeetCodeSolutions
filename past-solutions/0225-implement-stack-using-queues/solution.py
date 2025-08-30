from collections import deque

class MyStack:
    def __init__(self):
        self.queue1 = deque()  # main queue to hold elements
        self.queue2 = deque()  # helper queue to reverse the order
    
    def push(self, x: int) -> None:
        # Push element to the back of queue1
        self.queue1.append(x)
    
    def pop(self) -> int:
        # Move all elements except the last one to queue2
        while len(self.queue1) > 1:
            self.queue2.append(self.queue1.popleft())
        
        # The last element in queue1 is the top element of the stack
        top_element = self.queue1.popleft()
        
        # Swap queue1 and queue2 to continue the stack operations
        self.queue1, self.queue2 = self.queue2, self.queue1
        
        return top_element
    
    def top(self) -> int:
        # Move all elements except the last one to queue2
        while len(self.queue1) > 1:
            self.queue2.append(self.queue1.popleft())
        
        # The last element in queue1 is the top element of the stack
        top_element = self.queue1[0]
        
        # Move the element to queue2 after accessing it
        self.queue2.append(self.queue1.popleft())
        
        # Swap queue1 and queue2 to continue the stack operations
        self.queue1, self.queue2 = self.queue2, self.queue1
        
        return top_element
    
    def empty(self) -> bool:
        # If queue1 is empty, the stack is empty
        return len(self.queue1) == 0

