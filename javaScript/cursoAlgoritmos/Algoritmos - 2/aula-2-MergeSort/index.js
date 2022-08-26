const listaLivros = require(`./array.js`)

/**
 * recursive function that works together with ascendingPriceOrderList() calls it self till we have 2 
 * slices with length == 1, in this moment arrToSort will call ascendingPriceOrderList() and start 
 * ordering the arrays in pairs, in this example we have:
 * 
 * 11 books .:
 * 
 * level 0 instance: slice1: (0,5) === ['GO','C++','JAVA','PHP','ELIXIR']
 *                   slice2: (5,11) === [RUST, SCALA, RUBY, JS, C#, PYTHON] -> stays `reserved` waiting slice1 loop
 * 
 * moves to
 * level 1 instance: slice1: (0,2) === ['GO','C++']
 *                   slice2: (2,5) === ['JAVA','PHP',ELIXIR'] -> stays `reserved` waiting slice1 loop
 * moves to
 * level 2 instance: slice1 (0,1) === ['GO'] -> returns itself when entering mergeSort()
 *                   slice2 (1,2) === ['C++'] -> returns itself when entering mergeSort()
 *                   arrToSort = ascendingPriceOrderList(slice1, slice2) == ['C++', 'GO']
 * returns to
 * level 1 instance: slice1: (0,2) === ['C++', 'GO']
 *                   slice2: (2,5) === ['JAVA','PHP',ELIXIR'] -> enters mergeSort()
 * moves to
 * level 2 instance: slice1: (0,1) === ['JAVA'] -> returns itself when entering mergeSort()
 *                   slice2: (1,3) === ['PHP', 'ELIXIR'] -> enters mergeSort()
 * moves to
 * level 3 instance: slice1: (0,1) === ['PHP'] -> returns itself when entering mergeSort()
 *                   slice2: (1,2) === ['ELIXIR'] -> returns itself when entering mergeSort()
 *                   arrToSort = ascendingPriceOrderList(slice1, slice2) == ['PHP', 'ELIXIR']
 * returns to
 * level 2 instance: slice1: (0,1) === ['JAVA'] 
 *                   slice2: (1,3) === ['PHP', 'ELIXIR'] 
 *                   arrToSort = ascendingPriceOrderList(slice1, slice2) == ['PHP', 'JAVA', 'ELIXIR']
 * returns to 
 * level 1 instance: slice1: (0,2) === ['C++', 'GO']
 *                   slice2: (2,5) === ['PHP', 'JAVA', 'ELIXIR']
 *                   arrToSort = ascendingPriceOrderList(slice1, slice2) == ['PHP', 'JAVA', 'C++', 'GO', 'ELIXIR']
 * return to
 * level 0 instance: slice1: (0,5) === ['PHP', 'JAVA', 'C++', 'GO', 'ELIXIR']
 *                   slice2: (5,11) === [RUST, SCALA, RUBY, JS, C#, PYTHON] -> enters mergeSort() ..............
 * .....
 * .....
 * .....
 *      
 */

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
  let ascendingOrderedList = []

  const incrementFinalList = (list, listPivot) => {
      if(listPivot != list.length) {
          ascendingOrderedList.push(list[listPivot])
          listPivot++
      }
      return listPivot
  }

  const listIsFinished = (listToVerify, listToVerifyPivot) => {
      if(listToVerifyPivot === listToVerify.length) {
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

      if(listIsFinished(list2, list2Pivot)) {
          ascendingOrderedList = ascendingOrderedList.concat(list1.slice(list1Pivot))
          break
      }

      if(listIsFinished(list1,list1Pivot)) {
          ascendingOrderedList = ascendingOrderedList.concat(list2.slice(list2Pivot))
          break
      }
  }
  return ascendingOrderedList
}

console.log(mergeSort(listaLivros))
