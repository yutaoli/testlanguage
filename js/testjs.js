// https://www.programiz.com/javascript/examples
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
        root2 = (-b - Math.sqrt(disriminant)) / (2 * a);

        // result
        console.log(`The roots of quadratic equation are ${root1} and ${root2}`)
    }
    else if (disriminant == 0) {
        root1 = root2 = -b / (2 * a);

        // result
        console.log(`The roots of quadratic queation are ${root1} and ${root2}`)
    }
    else {
        let realpart = (-b / (2 * a)).toFixed(2);
        let imagPart = (Math.sqrt(-disriminant) / (2 * a)).toFixed(2);

        //result
        console.log(`The roots of quadratic equation are ${realpart}+${imagPart}i and ${realpart}-${imagPart}i`)
    }

}

function problem5() {
    const number = parseInt(prompt("Enter a number: "));

    // check 
    if (number > 0) {
        console.log("The number is Positive");
    }
    else if (number == 0) {
        console.log("The number is 0");
    }
    else {
        console.log("The number is negative");
    }
}

function problem6(){
    const a = 5;
    console.log(a);

    // constants are block-scoped
    {
        const a = 50;
        console.log(a);
    }
    console.log(a);

    const arr = ['zero', 'one', 'two'];
    console.log(arr);

    // add elements to arr array
    arr[3] = 'three';
    console.log(`arr length:${arr.length}, arr:${arr}`);

    arr.push('four');// add
    console.log(`arr length:${arr.length}, arr:${arr}`);

    arr.splice(0,2);// delete
    console.log(`arr length:${arr.length}, arr:${arr}`);

    arr[10] = 'ten';// modify/add
    console.log(`arr length:${arr.length}, arr:${arr}`);

    var lookupstring = 'one';// find 
    var i = arr.indexOf(lookupstring);
    console.log(`${lookupstring} of in arr is ${i}`)
}

problem6()
