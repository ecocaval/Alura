const booksOrdered = require('./arrayOrdenado')
console.log('\nOriginal Book List:\n')
console.log(booksOrdered)
console.log('\n*******************\n')

function searchBookBasedOnPrice (booksOrderedArr, priceSearched) {  

    const arrMiddleIndex = Math.floor(booksOrderedArr.length / 2)
    const priceFromMiddleBook = booksOrderedArr[arrMiddleIndex].price

    if(arrMiddleIndex === 0) return booksOrderedArr; // guard function for recursivity

    if(priceFromMiddleBook === priceSearched) return booksOrderedArr[arrMiddleIndex]; 

    if(priceFromMiddleBook > priceSearched) {
        return searchBookBasedOnPrice(booksOrderedArr.slice(0, arrMiddleIndex), priceSearched)
    } else {
        return searchBookBasedOnPrice(booksOrderedArr.slice(arrMiddleIndex), priceSearched)
    }
}   

console.log(searchBookBasedOnPrice(booksOrdered, 22))

