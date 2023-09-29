class Node{
    constructor(data){
        this.data = data;
        this.next = null;
    }
}

function printNode(head){
  let ptr = head;
  let res = [];
  while(ptr!=null) res.push(ptr.data),ptr=ptr.next;
  console.log(...res); 
}

function Add(head,data){
    let ptr = head;
    let t = new Node(data);
    while(ptr.next!=null) ptr = ptr.next;
    ptr.next = t;
}

function reverse(head){
    let ptr = null;
    let prev = null;
    let curr = head;
    while(curr!=null){
        ptr = curr.next;
        curr.next = prev; 
        prev = curr;
        curr = ptr;
    }
    return prev;
}

let head = new Node(0);
Add(head,1);
Add(head,2);
Add(head,3);
Add(head,4);
Add(head,5);
Add(head,6);
Add(head,7);
Add(head,8);
Add(head,9);
printNode(head);
printNode(reverse(head));