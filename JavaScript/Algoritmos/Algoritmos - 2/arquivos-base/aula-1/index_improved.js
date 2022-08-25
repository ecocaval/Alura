const editorsBooksList = require('./arrays_improved.js')

let { edFolha, edGalho } = editorsBooksList

console.log(edFolha, edGalho)

edFolha = edFolha.sort( (a,b) => a.price - b.price) // sorts arr in ascending order
edGalho = edGalho.sort( (a,b) => a.price - b.price) // sorts arr in ascending order

console.log(edFolha, edGalho)

function assembleLists1and2 (list1, list2) {

    let list1Pivot = 0
    let list2Pivot = 0
    const ascendingOrderedList = []

    const checkListAndIncrementFinalList = (list, listPivot) => {

        if(listPivot != list.length) {

            ascendingOrderedList.push(list[listPivot])
            listPivot++

        }

        return listPivot
    }

    const verifyIfListIsFinished = (listToVerify, listToVerifyPivot, listToIncrement, listToIncrementPivot) => {

        if(listToVerifyPivot === listToVerify.length) {

            while(listToIncrementPivot < listToIncrement.length){

                listToIncrementPivot = checkListAndIncrementFinalList(listToIncrement, listToIncrementPivot)

            }

            return true
        } 

        return false
    }

    while(list1Pivot < list1.length && list2Pivot < list2.length) {
        
        if(list1[list1Pivot].price < list2[list2Pivot].price) {

           list1Pivot = checkListAndIncrementFinalList(list1, list1Pivot)

        } else {
            
           list2Pivot = checkListAndIncrementFinalList(list2, list2Pivot)
           
        }

        if(verifyIfListIsFinished(list2, list2Pivot, list1, list1Pivot)) {
            break
        }

        if(verifyIfListIsFinished(list1,list1Pivot, list2, list2Pivot)) {
            break
        }
    }
    return ascendingOrderedList
}

const orderedList = assembleLists1and2(edFolha,edGalho)

console.log(orderedList)