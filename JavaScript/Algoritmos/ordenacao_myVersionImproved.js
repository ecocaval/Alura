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

let booksListPricedLowToGreat = []

booksListPricedLowToGreat = booksList.slice() // make a copy of original list
console.log(booksListPricedLowToGreat)

booksListPricedLowToGreat.forEach( book => {
    for(let currentBookPriceIndex in booksList) {
        if(currentBookPriceIndex > 0) {
            if(booksListPricedLowToGreat[currentBookPriceIndex - 1].price < booksListPricedLowToGreat[currentBookPriceIndex].price) {
                continue
            }
            const copyLastBook = booksListPricedLowToGreat[currentBookPriceIndex - 1]
            const copyCurrentBookPrice = booksListPricedLowToGreat[currentBookPriceIndex]

            booksListPricedLowToGreat[currentBookPriceIndex - 1] = copyCurrentBookPrice
            booksListPricedLowToGreat[currentBookPriceIndex] = copyLastBook
        }
    }
})
console.log(booksListPricedLowToGreat)
