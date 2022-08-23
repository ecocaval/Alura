
Array.prototype.equals = function (array) {
    if (!array) return false;

    if (this.length != array.length) return false

    for (var i = 0, l = this.length; i < l; i++) {
        if (this[i] instanceof Array && array[i] instanceof Array) {
            if (!this[i].equals(array[i])) return false      
        }           
        else if (this[i] != array[i]) return false   
    }       
    return true
}
 
Object.defineProperty(Array.prototype, "equals", {enumerable: false}); // Hide method from for-in loops

class Book {
    constructor(name, author, price) {
        this.name = name
        this.author = author
        this.price = price
    }
}

const homoDeus = new Book('Homo Deus','Harari', 90)
const antiCrist = new Book('Anti Crist', 'Nietzsche', 33.2)
const homoSapiens = new Book('Homo Sapiens', 'Harari', 25)
const bible = new Book('Bible', '?', 77.99)

/*
    creating a books list in books declaration order
*/
const booksList = []
booksList.push(homoDeus)
booksList.push(antiCrist)
booksList.push(homoSapiens)
booksList.push(bible)

/*
    make a copy of original list
*/
let booksListPricedLowToGreat = []

booksListPricedLowToGreat = booksList.slice() 

/* 
    repeats the algorithm 'n' times, 'n' is defined by the books list length
*/
let lastBookList = booksListPricedLowToGreat.slice()
let currentBookList = []

for(let book in booksListPricedLowToGreat) {

    if(lastBookList.equals(currentBookList)) break /*
                                                      if any books were moved
                                                      during last interaction we
                                                      can break the loop, avoiding
                                                      unnecessary repetition
                                                   */

    lastBookList = booksListPricedLowToGreat.slice()

    for(let currentBookPriceIndex in booksList) {

        if(currentBookPriceIndex > 0) { 
            /*
                if currentBookPriceIndex === 0 then currentBookPriceIndex-1 === -1, 
                so we test that index to continue
            */
           if(booksListPricedLowToGreat[currentBookPriceIndex - 1].price < 
              booksListPricedLowToGreat[currentBookPriceIndex].price) {
                /*
                    if last book's value is already lower than current one
                    we don't need to invert their positions
                */
                continue
            }
            // inverting books positions
            const copyLastBook = booksListPricedLowToGreat[currentBookPriceIndex - 1]
            const copyCurrentBook = booksListPricedLowToGreat[currentBookPriceIndex]
            
            booksListPricedLowToGreat[currentBookPriceIndex - 1] = copyCurrentBook
            booksListPricedLowToGreat[currentBookPriceIndex] = copyLastBook
        }
    }
    currentBookList = booksListPricedLowToGreat.slice()   
}

console.log(booksListPricedLowToGreat)