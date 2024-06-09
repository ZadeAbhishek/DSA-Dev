class DarkCoffee {
    constructor(){
        this.description = "Dark-Coffee";
    }
    getDescription(){
        return this.description;
    }
    cost(){
        return 10;
    }
}



// Dark is base and Mocha is add on
class Mocha {
    constructor(beverage){
        this.beverage = beverage;
        this.description = "Mocha"
    }

    getDescription(){
        return `${this.description} + ${this.beverage.getDescription()}`
    }

    cost(){
        return 0.20 + this.beverage.cost();
    }
}

class Milk {
    constructor(beverage){
        this.beverage = beverage;
        this.description = "Milk"
    }

    getDescription(){
        return `${this.description} + ${this.beverage.getDescription()}`
    }

    cost(){
        return 3.10 + this.beverage.cost();
    }
}

const darkCoffee = new DarkCoffee();
const mochaDarkcofee = new Mocha(darkCoffee);
const milkMochaDarkCoffee = new Milk(mochaDarkcofee);
console.log(`${milkMochaDarkCoffee.getDescription()} :: Rs ${milkMochaDarkCoffee.cost()}`);