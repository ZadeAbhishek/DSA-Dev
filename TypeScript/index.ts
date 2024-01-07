// type annotation
// varaible:type
let fullName : string = "Abhi";
let num:number;
num = 1;

const names: string[] = [];
names.push("Hi");


// varaible:type  fun():returnType{}
function sum (a:number, b:number) : number{
    return a+b;
}

// tuples
let address : [number, string , number];
address = [111,'delhi',311111];

// objects
let preson : {name:string};
preson = {name:'Abhi'};

// object with optional varialbes
let anotherPerson : {name:string, age?:number};
anotherPerson = {name:"Abhi",age:30};
anotherPerson = {name:"Abhi"};

// optinal parameter in functions
// Always required parameter Comes First
function add(a:number,b?:number):number{
    return b?a+b:a;
}

add(1,2); // 3
add(1); // 1

// interface (sort of struct)
interface Person{
    name:string; // we can also make this optional
    age:number;
    id?:number;
}

let p : Person;
p = {name:"Abhi",age:30,id:1};

interface Student{
    name:string; // we can also make this optional
    age:number;
    rollNo?:number;
}

let p1 : Person | Student; // Union (any one of the properties should match or all can be matched also)
p1 = {name:"Abhi",age:30,rollNo:1}; // student
p1 = {name:"Abhi",age:30,id:1}; // Person
p1 = {name:"Abhi",age:30,rollNo:1, id:2}; // Both

let p2 : Person & Student; // Intersection (All properties Should Match)
p2 = {name:"Abhi",age:30,rollNo:1, id:2}; // Both

// Type Alias (shortCut)
type count = string | number;
let c : count;
c = 1;
c = "One";
// c = false; // throw error

type X = string & number; // never type nothing can go in this

// class
class CarX{ // Basic JavaScript template
    brand;
    constructor(carName){
        this.brand = carName;
    }
    getName(){
        return this.brand;
    }
}

let c1 = new CarX("BMW");
console.log(c1.getName());
c1.brand; // we can access as there is no defination of Private or protected


class CarY { // TypeScript template 
    constructor(public brand){} // this will automaticallty init the brand varaible and make it public
    getName(){return this.brand};
}
let c2 = new CarX("BMW");
console.log(c2.getName());
c2.brand;

class CarP { // TypeScript template for Private
    constructor(private brand){} // this will automaticallty init the brand varaible and make it public
    getName(){return this.brand};
}
let c3 = new CarP("BMW");
console.log(c3.getName());
 // c3.brand; // this give error

 class CarPro { // TypeScript template for Protected
    constructor(protected brand){} // this will automaticallty init the brand varaible and make it public
    getName(){return this.brand};
}
let c4 = new CarP("BMW");
console.log(c4.getName());
 // c4.brand; // this give error