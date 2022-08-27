const booksAnalysed = require('./arrayOrdenado')
// console.log(booksAnalysed)

const invertBooks = (arr, leftBook, rightBook) => {
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

    console.log('\nMiddle Ref: ' + arrMiddleReference +
                    '\nLeft Ref: ' + arrLeftReference   +
                   '\nRigth Ref: ' + arrRightReference  + '\n')


    while(arrLeftReference < arrRightReference) {
        if(arrToCheck[arrLeftReference].price > arrToCheck[arrRightReference].price) {
            arrToCheck = invertBooks(arrToCheck, arrLeftReference, arrRightReference)
        }
    
        if(arrToCheck[arrLeftReference].price < arrToCheck[arrMiddleReference].price) {
            arrLeftReference++
        }
    
        if(arrToCheck[arrRightReference].price > arrToCheck[arrMiddleReference].price) {
            arrRightReference--
        }
    }

    return arrToCheck
}

function newSort (arrToSort) {

    const arrMiddleReference = Math.floor(arrToSort.length / 2)
    let arrRightReference = arrMiddleReference + 1
    let arrLeftReference = arrMiddleReference - 1
    
    let slicedArrToSort = arrToSort.slice(arrLeftReference, arrRightReference + 1)
    
    console.log('\nMiddle Ref: ' + arrMiddleReference +
    '\nLeft Ref: ' + arrLeftReference   +
    '\nRigth Ref: ' + arrRightReference  + '\n')

    console.log(slicedArrToSort)
    
    console.log(checkAndInvertBook(slicedArrToSort))

    // while(slicedArrToSort.length != arrToSort.length) {
    //     arrRightReference++
    //     arrLeftReference--
        
    //     slicedArrToSort = arrToSort.slice(arrLeftReference, arrRightReference + 1)
        
    //     console.log(slicedArrToSort)
        
    //     console.log('\nMiddle Ref: ' + arrMiddleReference +
    //     '\nLeft Ref: ' + arrLeftReference   +
    //     '\nRigth Ref: ' + arrRightReference  + '\n')

    //     console.log(checkAndInvertBook(slicedArrToSort))
    // }                   

    return arrToSort
}

newSort(booksAnalysed)