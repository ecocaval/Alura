// let notas = [10, 7, 8, 5, 10]

// notas.pop()

// let media = 0

// for(let i = 0; i < notas.length; i++) {
//     media += notas[i]
// }

// media /= notas.length

// console.log(media)

/*************************************/

// let firstArray = [1, 2]
// let secondArray = [3, 4]

// let newArray = firstArray.concat(secondArray)

// console.log(newArray)

/*************************************/

// let notas =[1,1,1,1,0,0,0,0]
// let newNotas;

// const funcTest = (notas) => {
//     newNotas = notas.filter(funcTest(notas))
// }

// console.log(newNotas)

/*************************************/

// let notas = [1, 1, -1, -1]

// const filteredNotas = notas.filter(n => n > 0)
// console.log(filteredNotas)

// const filteredNotas2 = notas.filter(n => n < 0)
// console.log(filteredNotas2)

/*************************************/

// let notas = [1, 2, 3, 4, 5, 6, 2]

// let findNota = notas.find(n => n == 5)
// console.log(findNota)

// let findNotaIndex = notas.findIndex(n => n == 5)
// console.log(findNotaIndex)

// let findIndexFrom = notas.indexOf(2)
// console.log(findIndexFrom)

// let findLastIndexFrom = notas.lastIndexOf(2)
// console.log(findLastIndexFrom)

/*************************************/

// let notas = [1, 2, 3, 5, 2]

// notas.forEach((item, index, arr) => {
//     console.log(`${item} (item) from ${index} (index) => full array ${arr}`)
// })

/*************************************/

// let number = [1,2,3,4,5]
// let somaNumber = 0

// number.forEach(number => {somaNumber += number})
// console.log(somaNumber)

/*************************************/

let letters = ['a','a','a','b','c','d','e','a','x','l','a']

let letter_counter = 0

letters.forEach(letter => {if(letter === 'a') letter_counter++})

console.log(letter_counter)
