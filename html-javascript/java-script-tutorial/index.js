// This is my first javascript code
console.log("Hello World");

let firstName = 'Leighton';
console.log(firstName);

let lastName = 'Guang';
console.log(lastName);

const interestRate = 0.3;
console.log(interestRate);

let isApproved = false; //boolean
let someName = undefined;
let selectedColor = null;

let person = {
    name: 'Leighton',
    age: 22
};

//dot notation
person.name = 'Jason';

//Bracket notatino
person['name'] = 'Mosh';

console.log(person);

let selectedColors = ['red', 'green'];
selectedColors[2] = 'blue';
console.log(selectedColors);
console.log(selectedColors.length);

//function
function greet(name, lastname) {
    console.log('Hello ' + name + ' ' + lastname);
}

greet(firstName, lastName);

function square(number){
    return number * number;
}

let number = square(2);
console.log(number);
