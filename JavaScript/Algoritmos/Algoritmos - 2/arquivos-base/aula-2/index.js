const editorBooks = require('./array.js')

let interaction = 0

const listOrdered = []

function assembleLists1and2 (list1, list2) {

    // const list1Ordered = list1.sort( (a,b) => a.price - b.price) // sorts arr in ascending order
    // const list2Ordered = list2.sort( (a,b) => a.price - b.price) // sorts arr in ascending order

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

function mergeSort(arr) {

    if(arr.length === 1 ) return
    
    console.log(`
    **********************************

`)

    if(arr.length > 1) {
        const arrPart1 = arr.slice(0, Math.floor(arr.length / 2))
        const arrPart2 = arr.slice(Math.floor(arr.length / 2), arr.length)

        if(arrPart1.length === 1 && arrPart2.length === 1) {

        }

        console.log(`
        Array Part 1:
        `)
        console.log(arrPart1)

        console.log(`
        Array Part 2:
        `)
        console.log(arrPart2)

        console.log(`
        
    **********************************
    
    `)

        mergeSort(arrPart1)
        mergeSort(arrPart2)
    }
}

mergeSort(editorBooks)

