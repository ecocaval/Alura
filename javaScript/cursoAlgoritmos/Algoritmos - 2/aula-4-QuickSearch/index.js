const booksOrdered = require('./arrayOrdenado')

function searchBookBasedOnPrice (booksOrderedArr, priceSearched) {  

    const arrMiddleIndex = Math.floor(booksOrderedArr.length / 2)
    const priceFromMiddleBook = booksOrderedArr[arrMiddleIndex].price

    if(arrMiddleIndex === 0) return booksOrderedArr; // guard function for recursivity

    if(priceFromMiddleBook === priceSearched) return booksOrderedArr[arrMiddleIndex]; 

    if(priceFromMiddleBook > priceSearched) {
        booksOrderedArr = searchBookBasedOnPrice(booksOrderedArr.slice(0, arrMiddleIndex), priceSearched)
    } else {
        booksOrderedArr = searchBookBasedOnPrice(booksOrderedArr.slice(arrMiddleIndex), priceSearched)
    }

    return booksOrderedArr
}   

console.log(searchBookBasedOnPrice(booksOrdered, 33))

