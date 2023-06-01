// Function to print triangle

function Triangle(n) {
    for (let i = 1; i <= n; i++) {
        let x = [];
        for (let j = 1; j <= i + n - 1; j++) {

            if (n - i < j) console.log(n - i, j), x.push('*');
        }
        console.log(...x);
    }
}

Triangle(5);