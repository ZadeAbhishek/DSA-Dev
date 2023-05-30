class Queue {

    constructor() {
        this.data = [];
    }
    push(data) {
        this.data.push(data);
    }
    pop() {
        let curr = this.data[0];
        this.data.reverse();
        this.data.pop();
        this.data.reverse();
        return curr;
    }
    print() {
        console.log(...this.data);
    }
    empty() {
        if (this.data.length == 0) return true;
        else return false;
    }
}

init();

function insert(array, sorce, destination) {
    let arr = array;
    arr[sorce].push(destination);
    arr[destination].push(sorce);
    return;
}

function bfs(arr, curr, memo, result) {

    let q = new Queue();
    q.push(curr);
    while (!q.empty()) {
        let temp = q.pop();
        result.push(temp);
        for (let it of arr[temp]) {
            if (memo[it] == 1) continue;
            memo[it] = 1;
            q.push(it);
        }
    }
}


function init() {
    let arr = [
        []
    ];

    let size_of_graph = 9;
    for (let i = 0; i < size_of_graph; i++) arr.push([]);
    insert(arr, 0, 1);
    insert(arr, 0, 2);
    insert(arr, 0, 5);
    insert(arr, 2, 3);
    insert(arr, 2, 4);
    insert(arr, 3, 7);
    insert(arr, 4, 7);
    insert(arr, 7, 8);
    insert(arr, 5, 6);

    let memo = new Array(size_of_graph).fill(0);

    let result = [];

    for (let curr = 0; curr < size_of_graph; curr++) {
        if (memo[curr] != 0) continue;
        memo[curr] = 1;
        bfs(arr, curr, memo, result);
    }

    console.log(...result);
}