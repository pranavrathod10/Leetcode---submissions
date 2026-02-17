class MyQueue:

    def __init__(self):
        self.viewSt = []
        self.useSt = []

    def push(self, x: int) -> None:
        self.viewSt.append(x)
        
        return

    def pop(self) -> int:
        # if len(self.useSt) != len(self.viewSt):
        #     for i in range(len(self.viewSt)-1,-1,-1):
        #         self.useSt.append(self.viewSt[i])

        # res = self.useSt[-1]
        # self.useSt.pop()

        # self.viewSt.clear()

        # for i in range(len(self.useSt)-1,-1,-1):
        #     self.viewSt.append(self.useSt[i])
        if not self.useSt:
            while self.viewSt:
                self.useSt.append(self.viewSt.pop())
        
        return self.useSt.pop()

    def peek(self) -> int:
        if not self.useSt:
            while self.viewSt:
                self.useSt.append(self.viewSt.pop())

        return self.useSt[-1]

    def empty(self) -> bool:
        print(self.viewSt)
        return len(self.viewSt) == 0 and len(self.useSt) == 0


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()