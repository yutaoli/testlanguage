function problem3() {
    const number1 = 2.25;
    const number2 = -1;

    const result1 = Math.sqrt(number1);
    const result2 = Math.sqrt(number2);

    document.write(`sqrt${number1} = ${result1}`);

    document.write("<br/>")
    document.write(`sqrt${number2} = ${result2}`);
}

function problem4() {
    let root1, root2;

    let a = prompt("Enter the first number: ");
    let b = prompt("Enter the second number: ");
    let c = prompt("Enter the third number: ");

    // 
    let disriminant = b * b - 4 * a * c;

    // 
    if (disriminant > 0) {
        root1 = (-b + Math.sqrt(disriminant)) / (2 * a);
        root2 = (-b + Math.sqrt(disriminant)) / (2 * a);

        // result
        console.log(`The roots of quadratic equation are ${root1} and ${root2}`)
    }
    else if (disriminant == 0) {
        root1 = root2 = -b / (2 * a);
    }

}

problem3()
