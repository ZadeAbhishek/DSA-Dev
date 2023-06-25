res = [];
arr = [1,2,3,4,5,6,7,8] // if 3 state then 2^3 = 8 possiblility
function powerSet(){
    let temp = [];
   for(let i = 0 ; i < Math.pow(2,arr.length) ; i++){
     temp = [];
     for(let j = 0 ; j < arr.length ; j++){
        if(i & (1<<j)) temp.push(arr[j]); 
     }
     res.push(temp.slice());
   }
}
powerSet();
console.log(res);