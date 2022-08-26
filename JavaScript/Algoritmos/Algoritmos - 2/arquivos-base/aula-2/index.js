const listaLivros = require(`./array.js`)

function mergeSort(arrToSort) {

  if(arrToSort.length > 1) {
    const arrToSortSlice1 = mergeSort(arrToSort.slice(0, Math.floor(arrToSort.length / 2)))
    const arrToSortSlice2 = mergeSort(arrToSort.slice(Math.floor(arrToSort.length / 2), arrToSort.length))

    arrToSort = ascendingPriceOrderList(arrToSortSlice1, arrToSortSlice2)
  }

  return arrToSort
}

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

console.log(mergeSort(listaLivros))