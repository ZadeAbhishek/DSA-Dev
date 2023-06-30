// let x = {};
// x[1] = 5;
// x[2] = 6;
// x[3] = 7;
// x[4] = 8;
// x[5] = 9;
// console.log(x);
// delete x[1];
// console.log(x);
// for(let i in x){
//     console.log(x[i]);
// }

let y = {type:"DRAW",Data:[{x:0,y:1,w:84,h:9},{x:0,y:1,w:84,h:9}]};

let x = new Map();
x.set(1,y);
x.set(2,y);
x.set(3,y);
x.set(4,y);

for(let [key,value] of x){
    console.log(key,value);
}

x.forEach((key,value)=>{
    console.log(key,value);
})

// set
// has
// get
// forEach