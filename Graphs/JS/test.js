let x = {};
x[1] = 5;
x[2] = 6;
x[3] = 7;
x[4] = 8;
x[5] = 9;
console.log(x);
delete x[1];
console.log(x);
for(let i in x){
    console.log(x[i]);
}