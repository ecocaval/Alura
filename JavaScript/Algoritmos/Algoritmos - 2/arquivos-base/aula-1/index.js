
const livrosAnalisados = require('./arrays.js') // comes in form of an object of arrays

const putBooksInAscendingPriceOrder = (booksToAnalyseObj) => {
    
    const buildBooksInfo = (booksToAnalyseObj) => {

        // [actualsListArr, listIsFinishedArr, booksListSizeArr, actualFinalMax, editorsList]
        const booksAnalysedInfoAuxArr = [[],[],[],[],[]] 
    
        Object.keys(booksToAnalyseObj).forEach( key => {
            booksAnalysedInfoAuxArr[0].push(0)
            booksAnalysedInfoAuxArr[1].push(false)
            booksAnalysedInfoAuxArr[2].push(booksToAnalyseObj[key].length)
            booksAnalysedInfoAuxArr[4].push(key)
        })
    
        // finalLisTotalSize = list1Size + list2Size
        booksAnalysedInfoAuxArr[3] = booksAnalysedInfoAuxArr[2][0] + booksAnalysedInfoAuxArr[2][1] 
    
        return booksAnalysedInfoAuxArr
    }

    const copyBookInfoArrToObj = (booksToAnalyseObj) => {
        
        const booksAnalysedInfoArr = buildBooksInfo(booksToAnalyseObj)

        const booksAnalysedInfo = {
            actualsListArr: booksAnalysedInfoArr[0], // arr of lists pivots
            listIsFinishedArr: booksAnalysedInfoArr[1], // arr indicating if list was fully scanned
            booksListSizeArr: booksAnalysedInfoArr[2], // arr indicating both lists length
            actualFinalMax: booksAnalysedInfoArr[3], // num indicating the sum of the two lists
            editorsList: booksAnalysedInfoArr[4] // arr indicating both editors names
        }

        return booksAnalysedInfo
    }

    const checkIfListIsFinished = (listToCheck) => {
        if(booksAnalysedInfo.actualsListArr[listToCheck] < booksAnalysedInfo.booksListSizeArr[listToCheck] - 1)  {
            booksAnalysedInfo.actualsListArr[listToCheck] += 1
            return false
        }
        
        if(!booksAnalysedInfo.listIsFinishedArr[listToCheck]) booksAnalysedInfo.listIsFinishedArr[listToCheck] = true 
        /*
            if atualListaFolha reached the top limit it means all elements of the list were added into the 
            ordered array booksInAscendigOrder, so we set that list as finished.
        */
        return true
    }

    const booksAnalysedInfo = copyBookInfoArrToObj(booksToAnalyseObj)    

    const booksInAscendigOrder = []
    
    let bookNumberIdentifier = 1

    const editorsNameList0 = booksAnalysedInfo.editorsList[0]
    const editorsNameList1 = booksAnalysedInfo.editorsList[1]

    let list1IsFinished = false

    for(let contador = 0; contador < booksAnalysedInfo.actualFinalMax; contador++) {

        const actualPivotList0 = booksAnalysedInfo.actualsListArr[0]
        const actualPivotList1 = booksAnalysedInfo.actualsListArr[1]

        const list0Book = booksToAnalyseObj[editorsNameList0][actualPivotList0] 
        const list1Book = booksToAnalyseObj[editorsNameList1][actualPivotList1] 
        
        if(list0Book.preco < list1Book.preco || list1IsFinished) {

            booksInAscendigOrder.push(list0Book)
            {
                // adds numerity to listed books array

                booksInAscendigOrder[contador].bookNumber = bookNumberIdentifier
                bookNumberIdentifier++
            }
            
            checkIfListIsFinished(0)
            continue
        }
        
        booksInAscendigOrder.push(list1Book)
        {
            booksInAscendigOrder[contador].bookNumber = bookNumberIdentifier
            bookNumberIdentifier++
        }
        
       if(checkIfListIsFinished(1)) list1IsFinished = true
    }
    return booksInAscendigOrder
}

const livrosOrdenados = putBooksInAscendingPriceOrder(livrosAnalisados)

console.log(livrosOrdenados)