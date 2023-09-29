init();

function ConverToDecimal(Binary) {

    let Decimal = 0;
    let CurrPow = 0;
    while (Binary != 0) {
        let temp = Binary % 10;
        let curr = temp * Math.pow(2, CurrPow);
        CurrPow++;
        Decimal += curr;
        Binary = Math.floor(Binary / 10);
    }
    return Decimal;
}

function init() {
    let Binary = 111;
    let result = ConverToDecimal(Binary);
    console.log(result);
}