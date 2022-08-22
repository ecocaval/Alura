class Book {
    constructor(name, author, price) {
        this.name = name
        this.author = author
        this.price = price
    }
}

const booksList = []

const homoDeus = new Book('Homo Deus','Harari', 50)
booksList.push(homoDeus)

const homoSapiens = new Book('Homo Sapiens', 'Harari', 75)
booksList.push(homoSapiens)

const antiCristo = new Book('Anti Cristo', 'Nietzsche', 60)
booksList.push(antiCristo)

// think how to push prices from book list

const booksPrices = [25, 15, 30, 50, 45, 20, 100, 48, 90, 44.2, 31.7, 55.8, 100.5]
 
console.log(booksPrices)

booksPrices.forEach(bookprice => {
    for(let currentBookPriceIndex in booksPrices) {
        if(currentBookPriceIndex > 0) {
            if(booksPrices[currentBookPriceIndex - 1] < booksPrices[currentBookPriceIndex]) {
                continue
            } else {
                const copyLastBookPrice = booksPrices[currentBookPriceIndex - 1]
                booksPrices[currentBookPriceIndex - 1] = booksPrices[currentBookPriceIndex] 
                booksPrices[currentBookPriceIndex] = copyLastBookPrice
            }
        }
    }
})

console.log(booksPrices)
