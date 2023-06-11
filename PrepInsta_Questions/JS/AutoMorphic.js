// sqrt should be equal t0 the number 
// (25)^2 = 625



init();


function Automorphic(no) {
    let sqr = Math.pow(no, 2);
    while (no > 0) {
        if (no % 10 != sqr % 10) return false;
        no = Math.floor(no / 10);
        sqr = Math.floor(sqr / 10);
    }
    return true;
}


function init() {

    // let result = Automorphic(25);
    // console.log(result);
    // result = Automorphic(76);
    // console.log(result);
    // result = Automorphic(7);
    // console.log(result);
    // result = Automorphic(36);
    // console.log(result);

    let AutomorphicNumber = [];

    for (let no = 1; no <= 1000000; no++)
        if (Automorphic(no)) AutomorphicNumber.push(no);

    console.log(...AutomorphicNumber);
}