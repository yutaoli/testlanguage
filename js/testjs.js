// 学习方法：https://www.zhihu.com/question/19713563
//  https://www.programiz.com/javascript/examples
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

function problem6() {
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

    arr.splice(0, 2);// delete
    console.log(`arr length:${arr.length}, arr:${arr}`);

    arr[10] = 'ten';// modify/add
    console.log(`arr length:${arr.length}, arr:${arr}`);

    var lookupstring = 'one';// find 
    var i = arr.indexOf(lookupstring);
    console.log(`${lookupstring} of in arr is ${i}`)
}

function problem7() {
    const num1 = parseFloat(prompt("Enter first number: "));
    const num2 = parseFloat(prompt("Enter second number: "));
    const num3 = parseFloat(prompt("Enter third number: "));

    let largest;

    if (num1 >= num2 && num1 >= num3) {
        largest = num1;
    }
    else if (num2 >= num1 && num2 >= num3) {
        largest = num2;
    }
    else {
        largest = num3;
    }

    console.log(`largest number in ${num1} ${num2} ${num3} is ${largest}`);

}

function problem8() {
    const number = parseInt(prompt("Enter a positive number:"));
    let isPrime = true;

    if (number < 1) {
        console.log("The number is not a prime number.");
        return;
    }
    if (number == 1) {
        console.log("1 is neither prime nor composite number.");
        return;
    }

    // number > 1
    for (let i = 2; i < number; i++) {
        if (number % i == 0) {
            isPrime = false;
            break;
        }
    }

    if (isPrime) {
        console.log(`${number} is a prime number`);
    }
    else {
        console.log(`${number} is not a prime number.`);
    }
}

function problem9() {
    const number = parseInt(prompt("Enter a positive number:"));

    if (number < 0) {
        console.log(`${number} is not a positive number.`);
        return;
    }

    if (number == 0) {
        console.log(`${number}! is 1.`);
        return;
    }

    let res = 1;
    for (let i = 1; i <= number; i++) {
        res = i * res;
    }
    console.log(`${number}! is ${res}`);
}

function problem10() {
    const number = parseInt(prompt("Enter an integer: "));

    for (let i = 1; i <= 10; i++) {
        const result = i * number;

        console.log(`${number} * ${i} = ${result}`);
    }
}

function problem11() {
    const number = parseInt(prompt("Enter a positive number: "));
    console.log("Finbonacci Series:");

    let n1 = 0, n2 = 1, next;
    if (number < 1) {
        console.log(`${number} is not a positive number.`);
        return;
    }

    // >=1
    for (let i = 0; i < number; i++) {
        console.log(n1);

        next = n1 + n2;
        n1 = n2;
        n2 = next;
    }
}

function problem12() {
    const number = prompt("Enter a positive number:");
    const numberOfDigits = number.length;
    let sum = 0;

    let temp = number;
    while (temp > 0) {
        let reminder = temp % 10;

        sum += Math.pow(reminder, numberOfDigits);
        temp = parseInt(temp / 10);
    }

    if (sum == number) {
        console.log(`${number} is an Armstrong number`);
    }
    else {
        console.log(`${number} is not an Armstrong number`);
    }
}

function problem13() {
    const lowNumber = parseInt(prompt("Enter a positive low integer value: "));
    const highNumber = parseInt(prompt("Enter a positive high integer value: "));

    console.log("Armstrong number:");

    for (let i = lowNumber; i <= highNumber; i++) {

        let numberOfDigits = i.toString().length;
        let temp = i;
        let sum = 0;
        while (temp > 0) {
            let reminder = temp % 10;

            sum += Math.pow(reminder, numberOfDigits);
            temp = parseInt(temp / 10);
        }

        if (sum == i) {
            console.log(i);
        }
    }
}

function problem14() {
    const number1 = prompt("Enter a first postive interger: ");
    const number2 = prompt("Enter a second postive interger: ");

    let temp_number1 = number1, temp_number2 = number2;
    if (temp_number1 > temp_number2) {
        let temp = temp_number1;
        temp_number1 = temp_number2;
        temp_number2 = temp;
    }

    while (temp_number2 % temp_number1 != 0) {
        let temp = temp_number2 % temp_number1;
        temp_number2 = temp_number1;
        temp_number1 = temp;
    }
    console.log(`gcd of ${number1} and ${number2} is ${temp_number1}.`);
}

function finbonacci(num) {
    if (num == 0 || num == 1) {
        return num;
    }

    return finbonacci(num - 1) + finbonacci(num - 2);
}

function problem15() {
    const nTerms = prompt("Enter the number of terms:");
    if (nTerms <= 0) {
        console.log(`Enter a positive number.`);
        return;
    }

    for (let i = 0; i < nTerms; i++) {
        console.log(finbonacci(i));
    }
}

function problem16() {
    const min = parseInt(prompt("Enter a min value: "));
    const max = parseInt(prompt("Enter a max value: "));

    const a = Math.floor((max - min + 1) * Math.random()) + min;// floor([min, min + max-min+1))=floor([min, max+1))=[min, max]
    console.log(`Random value between ${min} and ${max} is ${a}.`);

}

function sum(num) {
    if (num == 0) {
        return 0;
    }
    return num + sum(num - 1);
}

function problem17() {
    const number = parseInt(prompt("Enter a positive integer."));
    const result = sum(number);
    console.log(`sum of 0 to ${number} is ${result}.`);
}

function convertToBinary(x){
    let bin = 0;

    let digit = 1;
    while(x){
        let reminder = x % 2;
        x = parseInt(x/2);

        bin = bin + reminder * digit;
        digit = digit * 10;
    }
    return bin;
}

function problem18(){
    let number = parseInt(prompt("Enter a decimal number:"));
    let bin = convertToBinary(number);
    console.log(`${number} of bin is ${bin}.`);
}

// Default Parameter Value For a Function
function problem19(){
    let calculate = function(x=15, y=x+2){
        return x + y;
    }
    const result1 = calculate(10);
    console.log(result1);

    const result2 = calculate();
    console.log(result2);
}
problem19()
