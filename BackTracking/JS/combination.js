init();

function init() {
    // Back tracking problem
    let arr = [2, 3, 6, 7];
    var result = [];
    var curr = new Array();

    combination(arr, 7, result, curr, 0)
    console.log(result);
}

function combination(arr, target, result, curr, sum) {
    //console.log(sum, curr);
    if (sum > target) return;
    if (sum == target) {
        // console.log(sum, curr)
        let newArr = curr.slice();
        result.push(newArr);
        return;
    }

    for (let index = 0; index < arr.length; index++) {
        sum += arr[index];
        curr.push(arr[index]);
        combination(arr, target, result, curr, sum);
        curr.pop(arr[index]);
        sum -= arr[index];
    }
    //console.log(result);
    return;

}