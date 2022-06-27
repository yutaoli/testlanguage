// 学习方法：https://www.zhihu.com/question/19713563
//  https://www.programiz.com/javascript/examples

// TODO import {countDown} from './testexport.js';

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

    let arr = ['zero', 'one', 'two'];
    console.log(arr);

    // add elements to arr array
    arr[3] = 'three';
    console.log(`arr length:${arr.length}, arr:${arr}`);

    //arr.push('four');// add,push on the end
    arr.splice(arr.length, 0, 'four');// add,push on the end
    console.log(`arr length:${arr.length}, arr:${arr}`);

    arr.splice(0, 2);// delete
    console.log(`arr length:${arr.length}, arr:${arr}`);

    arr[10] = 'ten';// modify/add
    console.log(`arr length:${arr.length}, arr:${arr}`);

    var lookupstring = 'one';// find 
    var i = arr.indexOf(lookupstring);
    console.log(`${lookupstring} of in arr is ${i}`)

    // copy arr
    let arr2 = arr.slice(0);// array deep copy,copy from index 0 to end
    //let arr2 = [...arr];// array deep copy,copy from index 0 to end
    console.log(`arr2 length:${arr2.length}, arr2:${arr2}`);

    let arr3 = arr;// not deep copy arr

    // empty array
    arr[3] = 'new three';
    arr3 = [];//empty arr,only empty arr3
    //arr3.length = 0; // will empty arr  arr3
    //arr3.splice(0);// will empty arr  arr3
    //arr3[3] = "three3333333333333";
    console.log(`arr length:${arr.length}, arr:${arr}`);
    console.log(`arr2 length:${arr2.length}, arr2:${arr2}`);
    console.log(`arr3 length:${arr3.length}, arr3:${arr3}`);
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

function convertToBinary(x) {
    let bin = 0;

    let digit = 1;
    while (x) {
        let reminder = x % 2;
        x = parseInt(x / 2);

        bin = bin + reminder * digit;
        digit = digit * 10;
    }
    return bin;
}

function problem18() {
    let number = parseInt(prompt("Enter a decimal number:"));
    let bin = convertToBinary(number);
    console.log(`${number} of bin is ${bin}.`);
}

// Default Parameter Value For a Function
function problem19() {
    let calculate = function (x = 15, y = x + 2) {
        return x + y;
    }
    const result1 = calculate(10);
    console.log(result1);

    const result2 = calculate();
    console.log(result2);
}

function problem20() {
    let x = 0;
    let typeofX = typeof x;
    console.log(`typeof ${x} is ${typeofX}.`);

    let x2 = "aaaaaaaaaaaaaa";
    let typeofX2 = typeof x2;
    console.log(`typeof ${x2} is ${typeofX2}.`);

    let x3 = function () {
        return 3;
    };
    let typeofX3 = typeof x3;
    console.log(`typeof ${x3} is ${typeofX3}.`);

}

function problem21() {
    setTimeout(problem20, 1000);// get called after 1000 milliseconds;
    console.log("hello world.");
}

function problem22Sum() {
    if (arguments.length == 0) {
        console.log(`you have no pass any argement`);
        return;
    }

    if (arguments.length == 1) {
        console.log(`pass at least two arguments.`);
        return;
    }

    let result = 0;
    let length = arguments.length;
    for (let i = 0; i < length; i++) {
        result += arguments[i];
    }
    console.log(result);
}

function problem22() {
    problem22Sum();
    problem22Sum(5);
    problem22Sum(5, 9);
    problem22Sum(1, 2, 3, 4, 5, 6, 7, 8, 9);
}

function problem23Greet() {
    return 'hello';
}
function problem23Name(user, func) {
    const message = func();

    console.log(`${message}, ${user}`);
}

function problem23() {
    problem23Name('John', problem23Greet);
    problem23Name('Jack', problem23Greet);
    problem23Name('John', problem23Greet);
}

// array & object
function problem24() {
    const suits = ["Spades", "Diamonds", "Club", "Heart"];
    const values = ["Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"];

    let deck = [];
    for (let i = 0; i < suits.length; i++) {
        for (let x = 0; x < values.length; x++) {
            deck.push({ Value: values[x], Suit: suits[i] });
        }
    }

    for (let i = deck.length - 1; i > 0; i--) {
        let rand = Math.floor(Math.random() * i);
        let temp = deck[i];
        deck[i] = deck[rand];
        deck[rand] = temp;
    }

    console.log('The first five cards are:');
    for (let i = 0; i < 5; i++) {
        console.log(`${deck[i].Value},${deck[i].Suit}`);
    }
}

function problem25() {
    const string = prompt('Enter a sentance :');

    const words = string.split(' ');
    words.sort();
    console.log(`The sorted word are:`);

    for (let i = 0; i < words.length; i++) {
        console.log(`${words[i]}`);
    }

    wordsString = words.join('-')
    console.log(`${wordsString}`);
}

function problem26() {
    const person = {
        name: 'John',
        age: 20,
        hobbies: ['reading', 'games', 'coding'],
        greet: function () {
            console.log(`hello everyone.`);
        },
        score: {
            math: 90,
            science: 80
        }
    };

    console.log(typeof person);// object

    console.log(person.name);
    console.log(person.hobbies[0]);
    person.greet();
    console.log(person.score.math);
}

function problem27() {
    const person = {
        name: 'John',
        age: 20,
        hobbies: ['reading', 'games', 'coding'],
        greet: function () {
            console.log(`hello everyone.`);
        },
        score: {
            math: 90,
            science: 80
        }
    };

    console.log(person);

    delete person.greet;
    delete person.score;

    console.log(person);

}

function problem28() {
    const person = {
        name: 'John',
        age: 21
    };

    const clonePerson = { ...person };// deep copy
    //clonePerson = person; // pointing to the same object
    console.log(clonePerson);

    clonePerson.name = 'Peter';
    console.log(clonePerson);

    console.log(person);
}

function problem29() {
    const student = {
        name: 'John',
        age: 20,
        hobbies: ['reading', 'games', 'coding']
    };

    for (let [key, value] of Object.entries(student)) {// iterator
        console.log(`${key}-${value}`);
    }
}

function problem30() {
    const person = {
        name: 'Jack',
        age: 26
    };

    const student = {
        gender: 'male'
    };

    const newObj = { ...person, ...student };
    console.log(newObj);
}

function problem31() {
    const student = {
        name: 'John',
        age: 20,
        hobbies: ['reading', 'game', 'coding']
    };

    student['height'] = 5.4;
    console.log(student);
}

function problem32() {
    const person = {
        name: 'Jack',
        age: 27
    };
    const result = JSON.stringify(person);
    console.log(result);
    console.log(typeof result);
}

function problem33() {
    const string = "Learning JavaScript Program";
    //const result = string.replace(/a/g,"A");
    const result = string.split("a").join("A");
    console.log(result);
}

function problem34() {
    const array = [2, 1, 2, 3, 2, 3, 1];
    const array2 = [2, 3, 4, 3, 2, 5];

    const concatArray = [...array, ...array2];// concat 2 array

    let uniqArray = [...new Set(concatArray)];// new Set(array) return set, ...set return all element of set
    console.log(uniqArray);
}

function compareName(a, b) {
    const name1 = a.name.toUpperCase();
    const name2 = b.name.toUpperCase();

    let comparison = 0;
    if (name1 > name2) {
        comparison = 1;
    }
    else if (name1 < name2) {
        comparison = -1;
    }
    return comparison;
}

function compareAge(a, b) {
    return a.age - b.age;
}

function problem35() {
    const student = [{ name: 'Sara', age: 24 }, { name: 'John', age: 22 }, { name: 'Jack', age: 25 }];
    // student.sort(compareName);
    student.sort(compareAge);
    console.log(student);
}

function twoDimensionArray(a, b) {
    let arr = [];

    // creating two dimensional array
    for (let i = 0; i < a; i++) {
        arr[i] = [];
    }

    // inserting elements to array
    for (let i = 0; i < a; i++) {
        for (let j = 0; j < b; j++) {
            arr[i][j] = j;
        }
    }
    return arr;
}

function problem36() {
    const x = 2;
    const y = 3;

    const result = twoDimensionArray(x, y);
    console.log(result);
}

function extractValue(arr, prop) {
    // extract value from property
    //let extractedValue = arr.map(function(item){return item[prop]})
    let extractedValue = arr.map(item => item[prop]);// 和上面是等价的

    return extractedValue;
}

function problem37() {
    const objArray = [{ a: 1, b: 2 }, { a: 4, b: 5 }, { a: 5, b: 6 }];

    const result = extractValue(objArray, 'a');// get property a 
    console.log(result)
}

function performIntersection(arr1, arr2) {
    //const intersectionResult = arr1.filter(item=>arr2.indexOf(item) != -1);// filter 的实现里有for

    let intersectionResult = [];
    let setArr2 = new Set(arr2);
    for (let i of arr1) {// notice:'of', not 'in'
        if (setArr2.has(i)) {
            intersectionResult.push(i)
        }
    }
    return intersectionResult;
}

function problem38() {
    const array1 = [1, 2, 3, 5, 9];
    const array2 = [1, 3, 5, 8, 9];

    const result = performIntersection(array1, array2);
    console.log(result);

}

function problem39() {
    const array = [1, 2, 3, 4, 5, 6, 7, 8];

    let sliceArray = array.slice(1, 4);// [2, 3, 4]
    sliceArray[1] = 15;
    sliceArray[2] = 45;

    console.log(array);
    console.log(sliceArray);
}

function checkVariable(variable) {

    //if (variable === undefined || variable === null){
    if (variable == null) {// is equivalent to above
        console.log('The variable is undefined or null');
    }
    else {
        console.log('The variable is neither undefined nor null');
    }
}

function problem40() {
    let a;
    checkVariable(a)

    let b = 0;
    checkVariable(b)
}

function countString(str, letter) {

    // creating regex 
    const re = new RegExp(letter, 'gi');//g:global,i:ignore upper case or lower case
    const arr = str.match(re);// str.match(re) return ["oo", "oo", "oo"].
    count = arr.length;

    return count;
}

function problem41() {
    const string = 'schoo1oo9oolOO';
    const letterToCheck = 'oo';
    let count = countString(string, letterToCheck);
    console.log(`${count}`)
}

function problem42() {
    const string = '      Hello    World       ';
    const result = string.trim();
    console.log(result);
}

function problem43() {
    const str = "Learning JavaScript";

    // encoding the string base64
    const result = window.btoa(str);
    console.log(result);

    // decoding the string
    const result1 = window.atob(result);
    console.log(result1);
}

function getFileExtension(filename) {
    //return filename.substring(filename.lastIndexOf('.') + 1);
    return filename.substring(filename.lastIndexOf('.') + 1, filename.length);// is equivalent above
}

function problem44() {
    const result1 = getFileExtension('module.txt.js');
    console.log(result1);

    const result2 = getFileExtension('test.txt');
    console.log(result2);
}

function problem45() {
    const timeStamp = new Date().getTime()
    console.log(timeStamp)// 1656306908212

    const date = new Date(1656306908212);
    console.log(date)// Mon Jun 27 2022 13:15:08 GMT+0800 (中国标准时间)
}

function problem46() {
    let leftSecond = 10;
    let intervalMs = 2000;
    // TODO import countDown(leftSecond, intervalMs)
}

function problem47() {
    const url1 = window.location.href;// get url
    const url2 = document.URL;
    console.log(url1);
    console.log(url2);
}

class StackDemo {
    constructor() {
        this.items = [];
    }

    // add element to the stack
    push(element) {
        return this.items.push(element);
    }

    // remove element from the stack
    pop() {
        if (this.items.length > 0) {
            return this.items.pop();
        }
    }

    // check if the stack is empty
    isEmpty() {
        return this.items.length == 0;
    }

    // the size of the stack
    size() {
        return this.items.length;
    }

    // empty the stack
    clear() {
        this.items = [];
    }
}

function problem48() {
    let stack = new StackDemo();
    stack.push(1)
    stack.push(2)
    stack.push(3)
    stack.push(4)
    console.log(stack);


    topElement = stack.pop();
    console.log(`topElement=${topElement}`)
    let size = stack.size();
    console.log(`stack.size=${size}`)
}

function problem49() {
    const img = new Image();

    // get the image
    img.src = '//cdn.programiz.com/sites/tutorial2program/files/cover-artwork.png';

    // get height and width
    img.onload = function () {
        console.log('width ' + this.width)
        console.log('height ' + this.height);
    }
}

problem49();
