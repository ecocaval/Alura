// let polygon = 'triangle';
// let polygonHeight = 3;
// let polygonLenght = 10;

// var polygonArea;

// if(polygon === 'triangle') {
//     polygonArea = polygonHeight * polygonLenght / 2;
// } 
// else {
//     polygonArea = polygonHeight * polygonLenght;
// }

// console.log(polygonArea);

/*********************************************/

// let textExample = 'test';
// let numberExample = 5;
// let undefinedExample;

// console.log(typeof textExample);
// console.log(typeof numberExample);
// console.log(typeof undefinedExample);

/*********************************************/

// let numberNumber = 313;
// let numberString = '313';

// implicit conversion 

// console.log(numberNumber == numberString); 
// console.log(numberNumber === numberString);

// explicit conversion

// // model 1
// console.log(String(numberNumber) + numberString);
// console.log(numberNumber + Number(numberString));

// // model 2
// console.log(numberNumber.toString() + numberString);
// console.log(numberNumber + (+ numberString)); // not usual to use this type of conversion

/*********************************************/

// let numberTest = 2;

// if (numberTest === 1) {
//     console.log('ok!');
// } else {
//     console.error('error in code!');
// }

/*********************************************/

// let numberTest = 2;

// console.time();

// if (numberTest === 1) {
//     console.log('ok!');
// } else {
//     console.error(new Error('error in code!'));
// }

// console.timeEnd();

/*********************************************/

// let numberTested1 = 1;
// let numberTested2 = 2;

// const comparingNumbers = numberTested1 > numberTested2;

// console.assert(comparingNumbers, 'number1 is not greater than number2!');

// console.clear();

/*********************************************/

// console.count(1);
// console.count(1);
// console.count(1);
// console.count(1);
// console.count('123');
// console.count('123');
// console.countReset(1);
// console.countReset('123');
// console.count(1);
// console.count(1);
// console.count('123');
// console.count('123');

/*********************************************/

// console.table([{a: 1, b: 'Y'} , {a: 'Z', b: 0}]);

// console.table([{Nome1: 'Regina', Nome2: 'Silvia'} , {Nome1: 100.45, Nome2: 80.59}]);

/*********************************************/

let number = 313;
let numberString = '313';

console.log(number != numberString);
console.log(number !== numberString);