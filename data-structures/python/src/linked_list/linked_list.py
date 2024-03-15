class Node:
    """
        Manages data and a pointer for the subsequent node
        
        Attributes
        ----------
        data (any): actual data to be held
        next (any): pointer for subsequent node
    """
    def __init__(self, data = None) -> None:
        self.data = data
        self.next = None

class LinkedList:
    """
        Container that manages a collection of nodes

        Attributes
        ----------
        head (any): starting point of container
        tail (any): end point for container
    """
    def __init__(self):
        self.head = None
        self.tail = None
    def insert(self, data = None) -> bool:
        if data == None:
            return False
        node = Node(data)
        self.head = node
        if self.tail == None:
            self.tail = node
        return True
    def walk(self) -> list:
        nodes = []
        node = self.head
        while node != None:
            nodes.append(node)
            node = node.next
        return nodes
    def print_list(self) -> None:
        nodes = walk()
        for n in nodes:
            print(f"{n} {'->' if n else ''}")


