
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
            actualsListArr: booksAnalysedInfoArr[0],
            listIsFinishedArr: booksAnalysedInfoArr[1],
            booksListSizeArr: booksAnalysedInfoArr[2],
            actualFinalMax: booksAnalysedInfoArr[3],
            editorsList: booksAnalysedInfoArr[4]
        }

        return booksAnalysedInfo
    }

    const booksAnalysedInfo = copyBookInfoArrToObj(booksToAnalyseObj)    

    const booksInAscendigOrder = []
    let bookNumberIdentifier = 1

    const editorsNameList0 = booksAnalysedInfo.editorsList[0]
    const editorsNameList1 = booksAnalysedInfo.editorsList[1]
    /*
        - 1 because we see the array position that begins in 0.
    */
    const booksList0Size = booksAnalysedInfo.booksListSizeArr[0] - 1
    const booksList1Size = booksAnalysedInfo.booksListSizeArr[1] - 1

    for(let contador = 0; contador < booksAnalysedInfo.actualFinalMax; contador++) {

        let actualPivotList0 = booksAnalysedInfo.actualsListArr[0]
        let actualPivotList1 = booksAnalysedInfo.actualsListArr[1]

        let list0IsFinished = booksAnalysedInfo.listIsFinishedArr[0]
        let list1IsFinished = booksAnalysedInfo.listIsFinishedArr[1]
        
        let list0Book = booksToAnalyseObj[editorsNameList0][actualPivotList0] 
        let list1Book = booksToAnalyseObj[editorsNameList1][actualPivotList1] 
        
        if(list0Book.preco < list1Book.preco || list1IsFinished) {

            booksInAscendigOrder.push(list0Book)
            {
                // adds numerity to listed books array

                booksInAscendigOrder[contador].bookNumber = bookNumberIdentifier
                bookNumberIdentifier++
            }
            
            if(actualPivotList0 < booksList0Size) { 

                booksAnalysedInfo.actualsListArr[0] += 1
                continue
            }

            if(!booksAnalysedInfo.listIsFinishedArr[0]) booksAnalysedInfo.listIsFinishedArr[0] = true 
            /*
                if atualListaFolha reached the top limit it means all elements of the list were added into the 
                ordered array booksInAscendigOrder, so we set that list as finished.
            */
            continue
        }
        
        booksInAscendigOrder.push(list1Book)
        {
            booksInAscendigOrder[contador].bookNumber = bookNumberIdentifier
            bookNumberIdentifier++
        }
        
        if(actualPivotList1 < booksList1Size)  {
            booksAnalysedInfo.actualsListArr[1] += 1
            continue
        }
        
        if(!list1IsFinished) booksAnalysedInfo.listIsFinishedArr[1] = true 
    }
    return booksInAscendigOrder
}

const livrosOrdenados = putBooksInAscendingPriceOrder(livrosAnalisados)

console.log(livrosOrdenados)