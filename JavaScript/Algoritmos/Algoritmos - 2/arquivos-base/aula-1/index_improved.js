const editorsBooksList = require('./arrays_improved.js')

let { edFolha, edGalho } = editorsBooksList

console.log(edFolha, edGalho)

edFolha = edFolha.sort( (a,b) => a.price - b.price) // sorts arr in ascending order
edGalho = edGalho.sort( (a,b) => a.price - b.price) // sorts arr in ascending order

console.log(edFolha, edGalho)

function ascendingPriceOrderList (list1, list2) {

    let list1Pivot = 0
    let list2Pivot = 0
    const ascendingOrderedList = []

    const incrementFinalList = (list, listPivot) => {
        if(listPivot != list.length) {
            ascendingOrderedList.push(list[listPivot])
            listPivot++
        }
        return listPivot
    }

    const listIsFinished = (listToVerify, listToVerifyPivot, listToIncrement, listToIncrementPivot) => {
        if(listToVerifyPivot === listToVerify.length) {
            while(listToIncrementPivot < listToIncrement.length){
                listToIncrementPivot = incrementFinalList(listToIncrement, listToIncrementPivot)
            }
            return true
        } 
        return false
    }

    while(list1Pivot < list1.length && list2Pivot < list2.length) {
        if(list1[list1Pivot].price < list2[list2Pivot].price) {
           list1Pivot = incrementFinalList(list1, list1Pivot)
        } else {
           list2Pivot = incrementFinalList(list2, list2Pivot)
        }

        if(listIsFinished(list2, list2Pivot, list1, list1Pivot)) {
            break
        }

        if(listIsFinished(list1,list1Pivot, list2, list2Pivot)) {
            break
        }
    }
    return ascendingOrderedList
}

const orderedList = ascendingPriceOrderList(edFolha,edGalho)

console.log(orderedList)