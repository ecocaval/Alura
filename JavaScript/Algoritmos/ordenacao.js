const booksPrices = [25, 15, 30, 50, 45, 20, 100, 48, 90, 44.2, 31.7, 55.8, 100.5]

console.log(booksPrices)

booksPrices.forEach(bookprice => {
    for(let currentBookPriceIndex in booksPrices) {
        if(currentBookPriceIndex > 0) {
            if(booksPrices[currentBookPriceIndex - 1] < booksPrices[currentBookPriceIndex]) {
                continue
            } else {
                const copyCurrentBookPrice = booksPrices[currentBookPriceIndex - 1]
                booksPrices[currentBookPriceIndex - 1] = booksPrices[currentBookPriceIndex] 
                booksPrices[currentBookPriceIndex] = copyCurrentBookPrice
            }
        }
    }
})

console.log(booksPrices)

