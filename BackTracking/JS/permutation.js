init();

function init() {
    // Back tracking problem
    let arr = [1, 2, 3];
    var buffer = new Array(arr.length).fill(0);
    var result = [];
    var curr = new Array();

    permutation(arr, result, curr, buffer);
    console.log(result.length)
    console.log(result);
}

function permutation(arr, result, curr, buffer) {
    if (curr.length == arr.length) {
        result.push(curr.slice());
        return result;
    }
    for (let index = 0; index < arr.length; index++) {
        if (buffer[index] != 0) continue;
        buffer[index] = 1;
        curr.push(arr[index]);
        permutation(arr, result, curr, buffer)
        curr.pop(arr[index]);
        buffer[index] = 0;
    }
    return result;
}