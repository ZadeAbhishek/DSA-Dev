console.log("DFS JS");
dfs();

function insert(array, sorce, destination) {
    let arr = array;
    arr[sorce].push(destination);
    arr[destination].push(sorce);
}

function traverse(arr, vis, curr, result) {
    vis[curr] = 1;
    //console.log(result);
    result.push(curr);
    let len = arr[curr].length;
    for (let i = 0; i < len; i++) {
        if (vis[arr[curr][i]] == 0) {
            vis[arr[curr][i]] = 1;
            traverse(arr, vis, arr[curr][i], result);
        }
    }
}

function dfs() {
    let arr = [
        []
    ];
    for (let i = 0; i < 9; i++) { arr.push([]) };
    insert(arr, 0, 1);
    insert(arr, 0, 2);
    insert(arr, 0, 5);
    insert(arr, 2, 3);
    insert(arr, 2, 4);
    insert(arr, 3, 7);
    insert(arr, 4, 7);
    insert(arr, 7, 8);
    insert(arr, 5, 6);
    //console.log(arr);
    let vis = [];
    let result = new Array();
    for (let i = 0; i < 9; i++) { vis.push(0) };
    for (let curr = 0; curr < 9; curr++) {
        if (vis[curr] == 0) {
            vis[curr] = 1;
            traverse(arr, vis, curr, result);
        }
    }
    console.log(...result);
}