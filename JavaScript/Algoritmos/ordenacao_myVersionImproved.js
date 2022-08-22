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

/*
    creating a books list in books declaration order
*/
const booksList = []
booksList.push(homoDeus)
booksList.push(homoSapiens)
booksList.push(antiCrist)
booksList.push(bible)

/*
    make a copy of original list
*/
let booksListPricedLowToGreat = []

booksListPricedLowToGreat = booksList.slice() 

/* 
    repeats the algorithm 'n' times, 'n' is defined by the books list length
*/
booksListPricedLowToGreat.forEach( book => {
    for(let currentBookPriceIndex in booksList) {
        if(currentBookPriceIndex > 0) { 
            /*
                if currentBookPriceIndex === 0 then currentBookPriceIndex-1 === -1, 
                so we test that index to continue
            */
            if(booksListPricedLowToGreat[currentBookPriceIndex - 1].price < 
               booksListPricedLowToGreat[currentBookPriceIndex].price) {
                continue
                /*
                    if last book's value is already lower than current one
                    we don't need to invert their positions
                */
            }

            // inverting books positions
            const copyLastBook = booksListPricedLowToGreat[currentBookPriceIndex - 1]
            const copyCurrentBookPrice = booksListPricedLowToGreat[currentBookPriceIndex]

            booksListPricedLowToGreat[currentBookPriceIndex - 1] = copyCurrentBookPrice
            booksListPricedLowToGreat[currentBookPriceIndex] = copyLastBook
        }
    }
})
console.log(booksListPricedLowToGreat)
