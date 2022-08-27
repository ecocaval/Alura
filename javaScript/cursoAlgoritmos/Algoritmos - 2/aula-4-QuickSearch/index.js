const booksOrdered = require('./arrayOrdenado')

function searchBookBasedOnPrice (booksOrderedArr, priceSearched) {  

    const arrMiddleIndex = Math.floor(booksOrderedArr.length / 2)
    const priceFromMiddleBook = booksOrderedArr[arrMiddleIndex].price

    if(arrMiddleIndex === 0) { // guard function for recursivity
        if(booksOrderedArr[arrMiddleIndex].price === priceSearched) {
            return booksOrderedArr; 
        }
        return "\nWe don't have a book with that price!\n"
    }

    if(priceFromMiddleBook === priceSearched) return booksOrderedArr[arrMiddleIndex]; 

    if(priceFromMiddleBook > priceSearched) {
        return searchBookBasedOnPrice(booksOrderedArr.slice(0, arrMiddleIndex), priceSearched)
    } else {
        return searchBookBasedOnPrice(booksOrderedArr.slice(arrMiddleIndex), priceSearched)
    }
}   

console.log(searchBookBasedOnPrice(booksOrdered, 0))

