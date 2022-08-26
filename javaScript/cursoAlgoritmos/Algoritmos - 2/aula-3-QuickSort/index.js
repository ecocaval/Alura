const booksAnalysed = require('./array.js') // console.log(booksAnalysed);

function quickSortArr(arrToQuickSort) {

    let priceToScan = []
    let numberOfLowerPrices = []
    let quickSortedList = []

    for(let currentObjIndex in arrToQuickSort) {

        const currentObjPrice = arrToQuickSort[currentObjIndex].price

        numberOfLowerPrices[currentObjIndex] = 0
        priceToScan[currentObjIndex] = currentObjPrice
    
        const scanNextObjs = () => {
            for(let nextObjIndex = currentObjIndex; nextObjIndex < arrToQuickSort.length; nextObjIndex++)  {
                const nextObjPrice = arrToQuickSort[nextObjIndex].price
    
                if(nextObjPrice < currentObjPrice) numberOfLowerPrices[currentObjIndex]++
            }
        }

        const scanPreviousObjs = () => {
            for(let lastObjIndex = currentObjIndex - 1; lastObjIndex >= 0; lastObjIndex--)  {
                const lastObjPrice = arrToQuickSort[lastObjIndex].price
    
                if(lastObjPrice <= currentObjPrice) numberOfLowerPrices[currentObjIndex]++
            }
        }

        scanNextObjs()

        scanPreviousObjs()
        
        quickSortedList[numberOfLowerPrices[currentObjIndex]] = arrToQuickSort[currentObjIndex]
    }
    return quickSortedList
}

console.log(quickSortArr(booksAnalysed))