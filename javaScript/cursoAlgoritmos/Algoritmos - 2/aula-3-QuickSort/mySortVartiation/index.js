const booksAnalysed = require('./array.js') // console.log(booksAnalysed);

function quickSortArr(arrToQuickSort) {

    let pricesToScanArr = []
    let numberOfLowerPricesArr = []
    let quickSortedArr = []

    for(let currentObjIndex in arrToQuickSort) {

        const currentObjPrice = arrToQuickSort[currentObjIndex].price

        numberOfLowerPricesArr[currentObjIndex] = 0
        pricesToScanArr[currentObjIndex] = currentObjPrice
    
        const scanNextObjs = () => {
            for(let nextObjIndex = currentObjIndex; nextObjIndex < arrToQuickSort.length; nextObjIndex++)  {
                const nextObjPrice = arrToQuickSort[nextObjIndex].price
    
                if(nextObjPrice < currentObjPrice) numberOfLowerPricesArr[currentObjIndex]++
            }
        }

        const scanPreviousObjs = () => {
            for(let lastObjIndex = currentObjIndex - 1; lastObjIndex >= 0; lastObjIndex--)  {
                const lastObjPrice = arrToQuickSort[lastObjIndex].price
    
                if(lastObjPrice <= currentObjPrice) numberOfLowerPricesArr[currentObjIndex]++
            }
        }

        scanNextObjs()
        scanPreviousObjs()
        quickSortedArr[numberOfLowerPricesArr[currentObjIndex]] = arrToQuickSort[currentObjIndex]
    }
    return quickSortedArr
}

console.log(quickSortArr(booksAnalysed))