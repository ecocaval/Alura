const booksAnalysed = require('./array.js') // console.log(booksAnalysed);

function quickSortArr(arrToQuickSort) {

    let pricesChecked = 0
    let priceToScan = []
    let numberOfLowerPrices = []
    let quickSortedList = []

    priceToScan[0] = arrToQuickSort[0].price
    numberOfLowerPrices[0] = 0

    arrToQuickSort.forEach(elementOfArr => {

        if(arrToQuickSort.indexOf(elementOfArr) > 0) {
            if(elementOfArr.price < priceToScan[0]) {
                numberOfLowerPrices[0] += 1
            }
        }
    })

    quickSortedList[numberOfLowerPrices] = arrToQuickSort[0]
    
    console.log(quickSortedList)
}

quickSortArr(booksAnalysed)