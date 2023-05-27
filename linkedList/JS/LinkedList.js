// Node Class template
class Node {
    constructor(data) {
        this.data = data;
        this.next = null;
    }

    createNodeEnd(data) {
        if (data == null) return;
        let newNode = new Node(data);
        let node = this;
        while (node.next != null) node = node.next;
        node.next = newNode;
    }

    NodePrint() {
        let node = this;
        while (node.next != null) process.stdout.write(`${node.data} - `), node = node.next;
        console.log(node.data);
    }

    reverseNode() {
        let curr = this;
        let prev = null;
        let temp = null;
        while (curr.next != null) {
            temp = curr.next;
            curr.next = prev;
            prev = curr;
            curr = temp;
        }
        curr.next = prev;
        return curr;
    }

    alternateReverse() {
        let curr = this; // 0
        let altHead = curr.next;

        // 0 - 1 - 2 - 3 - 4 - 5 - 6
        // 1 - 0 - 3 - 2 - 5 - 4 - 6
        // 0 - 3 curr->next = ntn.next; 
        // 1 - 0 next->next = curr;
        // 0 = 4 curr = ntn.next 

        let next = curr.next;
        let nextTOnext = next.next;
        while (nextTOnext.next != null) {

            curr.next = nextTOnext.next // 0 - 3
            next.next = curr; // 1 - 0
            curr = nextTOnext; // 1 = 3
            next = curr.next; // 2 = 4
            nextTOnext = next.next // 3 = 5
            if (nextTOnext == null) break;
        }

        curr.next = null // 0 - 3
        next.next = curr;
        return altHead;
    }

    returnNodeAddress(data) {
        let node = this;
        while (node != null) {
            if (node.data == data) return node;
            node = node.next;
        }
        return null;

    }
    addNodeEnd(newNode) {
        if (newNode == null) return;
        let node = this;
        while (node.next != null) node = node.next;
        node.next = newNode;
    }

    detectcycle() {
        let curr = this;
        let slow = curr;
        let fast = curr;

        while (fast != null) {

            slow = slow.next;
            fast = fast.next.next;
            if (fast == slow) return true;
        }
        return false;
    }

    deleteNodeEnd() {
        let curr = this;
        while (curr.next.next != null) curr = curr.next;

        curr.next = null;
    }
}




function init() {
    let head = new Node(0);
    head.createNodeEnd(1);
    head.createNodeEnd(2);
    head.createNodeEnd(3);
    head.createNodeEnd(4);
    head.createNodeEnd(5);
    head.createNodeEnd(6);
    head.createNodeEnd(7);
    head.createNodeEnd(8);
    head.createNodeEnd(9);
    head.NodePrint();

    // console.log("Reverse Node");
    // reverse Node
    // head = head.reverseNode();

    // alternate reversr node
    // console.log("Reverse alt Node");
    // head = head.alternateReverse();
    // head.NodePrint();

    // find node with data and return
    // let node = head.returnNodeAddress(2);
    // node ? node.NodePrint() : console.log("NOT FOUND");

    // creating cycle
    // head.addNodeEnd(node);

    // detecting cycle
    // console.log(head.detectcycle());

    // delete n nodes from end node from end
    // head.deleteNodeEnd();
    // head.deleteNodeEnd();
    // head.NodePrint();
    // head = head.reverseNode();
    // head.deleteNodeEnd();
    // head.deleteNodeEnd();
    // head = head.reverseNode();
    // head.NodePrint();


}

init();