class Queue:
    def __init__(self):
        self.items = []

    def empty(self):
        return self.items == []

    def push(self, item):
        self.items.insert(0, item)

    def pop(self):
        return self.items.pop()
        
    def front(self):
        return self.items[-1]

    def size(self):
        return len(self.items)

    def __str__(self):
        squeue = ''
        for i in self.items:
            squeue += str(i)
        return squeue