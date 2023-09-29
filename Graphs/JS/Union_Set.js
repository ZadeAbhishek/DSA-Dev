class Union_set {

    constructor() {
        this.parent;
        this.size;
        this.set_size;
        this.find;
        this.union;
        this.init;
    }

    init(size) {
        this.parent = new Array(size).fill(0);
        this.size = new Array(size).fill(1);
        for (let index = 0; index <= size; index++) {
            this.parent[index] = index;
        }
        this.set_size = size;
    }

    union(e1, e2) {
        let x = this.find(e1);
        let y = this.find(e2);
        if (x === y) return true;
        if (this.size[x] >= this.parent[y]) this.size[x] += this.size[y], this.parent[y] = x;
        else this.size[y] += this.size[x], this.parent[x] = y;

        return false;
    }

    find(x) {
        //console.log(this.parent[x], x);
        if (this.parent[x] == x) return x;
        return this.find(this.parent[x])
    }


}


function getReduntant(edges, nodes) {
    let result = [];
    let temp = new Array();
    const union_set = new Union_set();
    union_set.init(nodes);
    for (let n of edges) {
        let r = union_set.union(n[0], n[1]);
        if (r) {
            temp.push(n[0]);
            temp.push(n[1]);
            result.push(temp.slice());
            temp = [];
        }
    }

    return result;
}

function init() {
    let egdes = [
        [1, 2],
        [1, 3],
        [2, 3],
        [2, 5],
        [3, 4],
        [4, 5]
    ];

    let result = getReduntant(egdes, 5);
    console.log(...result);
}
init();