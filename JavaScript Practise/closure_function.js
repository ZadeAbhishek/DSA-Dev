// Define a function called Adder that takes a parameter x
function Adder(x) {
    // Return an inner function called multipler
    return function multipler(y) {
        // Return the product of x and y
        return x * y;
    };
}

// Create a variable call and set it equal to the result of invoking Adder with argument 1
let call = Adder(1);

// Call the function stored in the call variable with argument 3 and log the result to the console
console.log(call(3)); // Output: 3  ==> 1(x) * 3(y);
