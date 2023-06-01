init();

function SpiralTraverse(arr) {
    let top = 0;
    let bottom = arr.length - 1;
    let left = 0;
    let right = arr[0].length - 1;
    let direction = 0;
    let result = [];

    while (top <= bottom && left <= right) {

        if (direction == 0) {
            for (let index = top; index <= right; index++) result.push(arr[top][index]);
            top++;
        }
        if (direction == 1) {
            for (let index = top; index <= bottom; index++) result.push(arr[index][right]);
            right--;
        }
        if (direction == 2) {
            for (let index = bottom; index >= left; index--) result.push(arr[bottom][index]);
            bottom--;
        }
        if (direction == 3) {
            for (let index = bottom; index >= top; index--) result.push(arr[index][left]);
            left++;
        }

        direction = (direction + 1) % 4;
    }

    return result;
}


function init() {

    let arr = [
        [1, 2, 3, 4],
        [5, 6, 7, 8],
        [9, 10, 11, 12]
    ];
    let result = SpiralTraverse(arr);
    console.log(...result);
}