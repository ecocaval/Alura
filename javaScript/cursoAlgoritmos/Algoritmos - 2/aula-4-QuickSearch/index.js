const booksOrdered = require('./arrayOrdenado')
console.log('\nOriginal Book List:\n')
console.log(booksOrdered)
console.log('\n*******************\n')

function searchBookBasedOnPrice (booksOrderedArr, priceSearched) {  

    console.log(booksOrderedArr)

    const arrMiddleIndex = Math.floor(booksOrderedArr.length / 2)
    const priceFromMiddleBook = booksOrderedArr[arrMiddleIndex].price

    if(arrMiddleIndex === 0) return booksOrderedArr // guard function for recursivity

    if(priceFromMiddleBook > priceSearched) {

        booksOrderedArr = searchBookBasedOnPrice(booksOrderedArr.slice(0, arrMiddleIndex), priceSearched)

    } else if((priceFromMiddleBook < priceSearched)) {

        booksOrderedArr = searchBookBasedOnPrice(booksOrderedArr.slice(arrMiddleIndex), priceSearched)

    } else return booksOrderedArr[arrMiddleIndex];

    return booksOrderedArr
}   

console.log(searchBookBasedOnPrice(booksOrdered, 30))

