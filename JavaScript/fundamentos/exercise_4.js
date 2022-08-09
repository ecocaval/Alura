// let listaDeFuncionarios = {};

// listaDeFuncionarios.nome1 = 'Roberto';
// listaDeFuncionarios.nome2 = 'Valdea';

// console.log(listaDeFuncionarios);
// console.log(listaDeFuncionarios.nome1);
// console.log(listaDeFuncionarios.nome2);

/***************************************/

// let nomes = {};
// let listaDeFuncionarios = {nomes};

// listaDeFuncionarios.nomes.nome1 = 'And';
// listaDeFuncionarios.nomes.nome2 = 'João';

// console.log(listaDeFuncionarios);
// console.log(listaDeFuncionarios.nomes);
// console.log(listaDeFuncionarios.nomes.nome1);
// console.log(listaDeFuncionarios.nomes.nome2);

/***************************************/

// function dec2bin(dec){
//     return (dec >>> 0).toString(2);
// }

// let number2 = 0xF0; // 1111 0000

// let number;

// number = number2 >> 4;
// console.log(dec2bin(number));

// number = number2 << 4;
// console.log(dec2bin(number));

/***************************************/

// let age = 18

// let ageStatus;

// ageStatus = age >= 18 ? 'Adult' : 'Child';
// console.log(ageStatus);

// age = 10;
// ageStatus = age >= 18 ? 'Adult' : 'Child';
// console.log(ageStatus);

/***************************************/

// const x = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9];
// const a = [x, x, x, x, x];

// for (let i = 0, j = 9; i <= j; i++, j--) {
// //                                ^
//   console.log(`a[${i}][${j}]= ${a[i][j]}`);
// }

/***************************************/

// let myObject = {a: 10};

// console.log(myObject);

// delete myObject.a;

// console.log(myObject);

/**************************************/

const myFun = new Function('5 + 2');
const shape = 'round';
const size = 1;
const foo = ['Apple', 'Mango', 'Orange'];
const today = new Date();

console.log(typeof myFun)      ; // returns "function"
console.log(typeof shape)      ; // returns "string"
console.log(typeof size)       ; // returns "number"
console.log(typeof foo)        ; // returns "object"
console.log(typeof today)      ; // returns "object"
console.log(typeof doesntExist); // returns "undefined"
