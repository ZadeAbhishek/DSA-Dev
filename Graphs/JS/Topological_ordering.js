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


function insert_node(node, source, destination) {
    let arr = node;
    arr[source].push(destination);
}


function topologicalSort(node) {
    // step 1 calcuate indegree of node
    let inDegree = new Array(node.length).fill(0);
    for (let n of node) {
        for (let x of n) inDegree[x] += 1;
    }

    // step 2 add it queue in the order of indegree
    let q = new Queue();
    for (let x of inDegree)
        if (x === 0) q.push(x)
            // step 3 traverse using bfs since queue and to result
    let result = [];
    while (!q.empty()) {
        let curr = q.pop();
        result.push(curr);
        for (let x of node[curr]) {
            inDegree[x]--;
            if (inDegree[x] == 0) q.push(x);
        }
    }
    return result.length !== node.length ? [] : result;
}

function init() {
    let no_node = 6;
    let node = [
        []
    ];
    for (let index = 0; index <= no_node; index++) node.push([]);
    insert_node(node, 0, 1);
    insert_node(node, 1, 6);
    insert_node(node, 0, 2);
    insert_node(node, 0, 5);
    insert_node(node, 2, 3);
    insert_node(node, 2, 4);
    insert_node(node, 3, 7);
    insert_node(node, 4, 7);
    insert_node(node, 7, 8);
    insert_node(node, 5, 6);
    //console.log(node);
    let result = topologicalSort(node);
    console.log(...result);
}

init();