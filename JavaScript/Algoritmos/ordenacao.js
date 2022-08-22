class Book {
    constructor(name, author, price) {
        this.name = name
        this.author = author
        this.price = price
    }
}

const booksList = []

const homoDeus = new Book('Homo Deus','Harari', 50)
const homoSapiens = new Book('Homo Sapiens', 'Harari', 75)
const antiCristo = new Book('Anti Cristo', 'Nietzsche', 60)

booksList.push(homoDeus)
booksList.push(homoSapiens)
booksList.push(antiCristo)

const booksListKeys = []
const booksPrices = []
let bookCounter = 0

booksList.forEach(book => {
    const objectKeyAnalyser = (Object.keys(book))
    const objectPricesAnalyser = (Object.values(book))
    const priceIndex = objectKeyAnalyser.indexOf('price')

    // console.log(objectKeyAnalyser, 'book number: ' + bookCounter)
    
    for(let objectKey in objectKeyAnalyser) {
        if(objectKeyAnalyser[objectKey] != 'price') {
            continue
        }
        booksPrices[bookCounter] = objectPricesAnalyser[priceIndex]
    }
    bookCounter++
})

console.log(booksPrices)

booksPrices.forEach(bookprice => {
    for(let currentBookPriceIndex in booksPrices) {
        if(currentBookPriceIndex > 0) {
            if(booksPrices[currentBookPriceIndex - 1] < booksPrices[currentBookPriceIndex]) {
                continue
            } 
            const copyLastBookPrice = booksPrices[currentBookPriceIndex - 1]
            booksPrices[currentBookPriceIndex - 1] = booksPrices[currentBookPriceIndex] 
            booksPrices[currentBookPriceIndex] = copyLastBookPrice
        }
    }
})

console.log(booksPrices)
