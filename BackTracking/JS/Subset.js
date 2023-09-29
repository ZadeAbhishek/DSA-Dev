init();

function init() {
    let arr = [1, 2, 3, 4];
    let result = new Array();
    let temp = new Array();
    subsets(arr, 0, result, temp);
    console.log(...result);

}

function subsets(arr, curr, result, temp) {
    if (curr == arr.length) {
        result.push(temp.slice());
        return;
    }
    temp.push(arr[curr]);
    subsets(arr, curr + 1, result, temp);
    temp.pop();
    subsets(arr, curr + 1, result, temp);
    return;

}