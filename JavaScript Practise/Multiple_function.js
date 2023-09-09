/*
This was Zomatos question asked in frontend Developments
*/

let funArray  = [
    function add(a,b){ return a+b;},
    function sub(a,b){ return a-b;},
    function divide(a,b){ return a/b;},
    function multiply(a,b){ return a*b;}
]

let funObject = {
    add:(a,b)=>{return a+b},
    sub:(a,b)=>{return a-b},
    mul:(a,b)=>{return a*b},
    div:(a,b)=>{return a/b},
}

let ansObj = Object.keys(funObject).map((fn)=>{return funObject[fn](8,6)});

let ans = funArray.map((fn)=>{return fn(8,6)});
console.log(ans);
console.log(ansObj);