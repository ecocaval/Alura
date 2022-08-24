
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
    
    // console.log(booksToAnalyseObj)
    // console.log(booksAnalysedInfo)

    const booksInAscendigOrder = []
    let bookNumberIdentifier = 1

    for(let contador = 0; contador < booksAnalysedInfo.actualFinalMax; contador++) {

        const list0Book = booksToAnalyseObj[booksAnalysedInfo.editorsList[0]][booksAnalysedInfo.actualsListArr[0]] 
        const list1Book = booksToAnalyseObj[booksAnalysedInfo.editorsList[1]][booksAnalysedInfo.actualsListArr[1]] 
        
        if(list0Book.preco < list1Book.preco || booksAnalysedInfo.listIsFinishedArr[1]) {

            booksInAscendigOrder.push(list0Book)

            {
                // adds numerity to listed books array

                booksInAscendigOrder[contador].bookNumber = bookNumberIdentifier
                bookNumberIdentifier++
            }
            
            if(booksAnalysedInfo.actualsListArr[0] < booksAnalysedInfo.booksListSizeArr[0] - 1) { 
                /*
                   - 1 because we see the array position that begins in 0.
                */
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
        
        if(booksAnalysedInfo.actualsListArr[1] < booksAnalysedInfo.booksListSizeArr[1] - 1)  {
            booksAnalysedInfo.actualsListArr[1] += 1
            continue
        }
        
        if(!booksAnalysedInfo.listIsFinishedArr[1]) booksAnalysedInfo.listIsFinishedArr[1] = true 
    }

    return booksInAscendigOrder
}

const livrosOrdenados = putBooksInAscendingPriceOrder(livrosAnalisados)

console.log(livrosOrdenados)