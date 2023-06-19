class Node:
    def __init__(this,data):
        this.data = data
        this.next = None


def addNode(head,value):
    while head.next != None: head = head.next
    temp = Node(value)
    head.next = temp

def printNode(head):
    temp = []
    count = 0
    while head != None:
        temp.append(head.data)
        count += 1
        head = head.next
    print(temp)
    print("Total Element:{count}".format(count=count))


if __name__ == '__main__':
    head = Node(0)
    addNode(head,1)
    addNode(head,2)
    addNode(head,3)
    addNode(head,4)
    addNode(head,5)
    addNode(head,6)
    addNode(head,7)
    printNode(head)

