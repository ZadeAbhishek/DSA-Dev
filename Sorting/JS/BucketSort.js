// Bucket Sort

function getMax(array){
    let temp = -999999
    for(let x of array) temp = x>temp?x:temp;
    return temp; 
}

function bucktSort(array){
    let MaxElement = getMax(array);
    let digit = 1, count = 0;
    while(MaxElement > 0) MaxElement = Math.floor(MaxElement/10), count++;
    count--;
    while(count > 0) digit *= 10,count--;
    let Bucket = {};
    for(let i = 0; i <= 10;i++) Bucket[i] = new Array();
    for(let e of array) Bucket[Math.floor(e/digit)].push(e);
    for(let e in Bucket) Bucket[e].sort();
    array = [];
    for(let e in Bucket) array.push(...Bucket[e]);
    return array;
}

let array = [7,11,9,3,6,10,66,78,96,12,36,105,700,64,3,6,0,90];
console.log(...array)
console.log(...bucktSort(array));
