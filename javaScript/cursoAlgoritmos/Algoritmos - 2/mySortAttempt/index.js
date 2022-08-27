const booksAnalysed = require('./array')
// console.log(booksAnalysed)

function invertBooks (arr, leftBook, rightBook) {
    const previousLeftBook = arr[leftBook]
    const previousRigthBook = arr[rightBook]

    arr[leftBook] = previousRigthBook
    arr[rightBook] = previousLeftBook

    return arr
}

function checkAndInvertBook (arrToCheck) {
    let arrLeftReference = 0
    let arrRightReference = arrToCheck.length - 1
    let arrMiddleReference = Math.floor(arrToCheck.length/2)

    while(arrLeftReference < arrRightReference) {
        const leftPriceIsHigher = arrToCheck[arrLeftReference].price > arrToCheck[arrRightReference].price

        if(leftPriceIsHigher) {
            arrToCheck = invertBooks(arrToCheck, arrLeftReference, arrRightReference)
        }
        
        const leftPriceCanIncrement = arrToCheck[arrLeftReference].price < arrToCheck[arrMiddleReference].price
        const rightPriceCanDecrement = arrToCheck[arrRightReference].price > arrToCheck[arrMiddleReference].price

        if(leftPriceCanIncrement) arrLeftReference++;
        if(rightPriceCanDecrement) arrRightReference--
    }

    return arrToCheck
}

function modifyArrBeingSort (arrBeingSorted, subArrOrdered, leftReference) {
    for(let allBooksIndex in subArrOrdered) {
        arrBeingSorted[leftReference] = subArrOrdered[allBooksIndex]
        leftReference++
    }   
    return arrBeingSorted
}

function newSort (arrToSort) {
    const arrMiddleReference = Math.floor(arrToSort.length / 2)
    let arrRightReference = arrMiddleReference + 1
    let arrLeftReference = arrMiddleReference - 1
    
    let slicedArrToSort = []

    do {       
        slicedArrToSort = arrToSort.slice(arrLeftReference, arrRightReference + 1)

        console.log('\nMiddle Ref: ' + arrMiddleReference +
        '\nLeft Ref: ' + arrLeftReference   +
        '\nRigth Ref: ' + arrRightReference  + '\n')
        console.log(slicedArrToSort)

        slicedArrToSort = checkAndInvertBook(slicedArrToSort)
        console.log(slicedArrToSort)

        arrToSort = modifyArrBeingSort(arrToSort, slicedArrToSort, arrLeftReference)
        console.log(arrToSort)

        arrRightReference++
        arrLeftReference--
    } while (slicedArrToSort.length != arrToSort.length)                    

    return arrToSort
}

newSort(booksAnalysed)