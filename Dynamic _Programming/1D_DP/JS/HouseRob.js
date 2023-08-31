init();

function init(){
    let arr = [2,7,9,3,1];
    let res = rob(arr,0,0);
    let res1 = rob_linear(arr);
    console.log(res,res1);
}

function rob(arr,index, max){
   if(index >= arr.length) return max;
   return Math.max(rob(arr,index+1,max),rob(arr,index+2,max+arr[index]));
}

function rob_linear(arr){
    if(arr.length === 0) return 0;
    if(arr.length === 1) return arr[0];
    if(arr.length === 2) return Math.max(arr[0],arr[1]);
    for(let i = 2 ; i < arr.length ; i++){
        arr[i] = Math.max(arr[i-1],arr[i]+arr[i-2]);
    }
    return arr[arr.length-1];
}