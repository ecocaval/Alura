class Book {
    constructor(name, author, price) {
        this.name = name
        this.author = author
        this.price = price
    }
}

const homoDeus = new Book('Homo Deus','Harari', 50)
const homoSapiens = new Book('Homo Sapiens', 'Harari', 75)
const antiCrist = new Book('Anti Crist', 'Nietzsche', 60)
const bible = new Book('Bible', '?', 10)

const booksList = []
booksList.push(homoDeus)
booksList.push(homoSapiens)
booksList.push(antiCrist)
booksList.push(bible)

const booksListKeys = []
const booksPricesLowerToGreater = []

// making a list only of prices
booksList.forEach(book => {
    const objectKeyAnalyser = (Object.keys(book))
    const objectPricesAnalyser = (Object.values(book))
    const priceIndex = objectKeyAnalyser.indexOf('price')

    // console.log(objectKeyAnalyser, 'book number: ' + bookCounter)
    
    for(let objectKey in objectKeyAnalyser) {
        if(objectKeyAnalyser[objectKey] != 'price') {
            continue
        }
        booksPricesLowerToGreater.push(objectPricesAnalyser[priceIndex])
    }
})
console.log(booksPricesLowerToGreater)

// organizing the prices list
booksPricesLowerToGreater.forEach(bookprice => {
    for(let currentBookPriceIndex in booksPricesLowerToGreater) {
        if(currentBookPriceIndex > 0) {
            if(booksPricesLowerToGreater[currentBookPriceIndex - 1] < booksPricesLowerToGreater[currentBookPriceIndex]) {
                continue
            } 
            const copyLastBookPrice = booksPricesLowerToGreater[currentBookPriceIndex - 1]
            
            booksPricesLowerToGreater[currentBookPriceIndex - 1] = booksPricesLowerToGreater[currentBookPriceIndex] 
            booksPricesLowerToGreater[currentBookPriceIndex] = copyLastBookPrice
        }
    }
})
console.log(booksPricesLowerToGreater)

// reconstructing the objects from the prices list
let booksPricedList = []

booksPricesLowerToGreater.forEach( price => {
    for(let bookAnalyserCounter in booksList) {
        if(booksList[bookAnalyserCounter].price === price) {
            booksPricedList.push(booksList[bookAnalyserCounter])
            break
        }
    }
})

console.log(booksPricedList)