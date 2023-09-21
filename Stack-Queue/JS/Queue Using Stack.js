class Stack {
    constructor() {
        this.data = [];
    }
    push(data) {
        this.data.reverse();
        this.data.push(data);
        this.data.reverse();
    }
    pop() {
        if (this.data.length == 0) return null;
        let curr = this.data[0];
        this.data.reverse();
        this.data.pop();
        this.data.reverse();
        return curr;
    }
    print() {
        console.log(...this.data);
        return this.data;
    }
    size() { return this.data.length; }
}


class Queue {
    constructor() {
        this.stackA = new Stack();
        this.stackB = new Stack();
    }
    push(data) {
        this.stackA.push(data);
    }
    pop() {
        let index = 0;
        let lenght_stack = this.stackA.size();
        while (index < lenght_stack) this.stackB.push(this.stackA.pop()), index++;
        let curr = this.stackB.pop();
        lenght_stack = this.stackB.size();
        index = 0;
        while (index < lenght_stack) this.stackA.push(this.stackB.pop()), index++;
        return curr;


    }
    print() {
        let arr = this.stackA.data.slice();
        arr.reverse();
        console.log(...arr);
    }
}

// let q = new Queue();
// q.push(1);
// q.push(2);
// q.push(3);
// q.push(4);
// q.print();
// q.pop();
// q.pop();
// q.print();
// q.push(1);
// q.push(2);
// q.print();
// q.push(10);
// q.push(22);
// q.print();
// q.pop();
// q.print();
// q.pop();
// q.print();
// q.pop();
// q.print();
// q.pop();
// q.print();
// q.push(1);
// q.push(2);
// q.push(3);
// q.push(4);
// q.print();
// q.pop();
// q.print();