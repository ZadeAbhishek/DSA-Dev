// 0 1 2 3 4 5 6 7 8 9
// 1 0 3 4 

class Node{
    constructor(data){
       this.data = data;
       this.next = null;
    }
    add(data){
        let ptr = this;
        let head = this;
        let temp = new Node(data);
        while(ptr.next != null) ptr = ptr.next;
        ptr.next = temp;
        return head;
    }
    print(){
        let ptr = this;
        let res = [];
        while(ptr != null) res.push(ptr.data),ptr = ptr.next;
        console.log(...res);
    }
}

// 1 2 3 4 5 6
function reverse_alt(head){
    let alt = head.next;
    let prev = head; // 1
    let curr = head.next; // 2
    let next = curr.next; // 3
    while(next.next!=null){
        prev.next = next.next;
        curr.next = prev;
        prev = next;
        curr = prev.next;
        next = curr.next;
        if(next == null) break
    }
    prev.next = null;
    curr.next = prev;
    return alt;
}

let head = new Node(0);
head.add(1);
head.add(2);
head.add(3);
head.add(4);
head.add(5);
head.add(6);
head.add(7);
head.add(8);
head.add(9);
head.add(10);
head.add(11);
head.print();
let res = reverse_alt(head);
res.print();