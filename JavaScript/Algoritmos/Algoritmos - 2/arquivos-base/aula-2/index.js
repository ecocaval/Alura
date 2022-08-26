const editorBooks = require('./array.js')

let interaction = 0

let separatedBooks = []

function mergeSort(arr) {
    if(arr.length === 1) {
        separatedBooks.push(arr)

        console.log(`**********************************
Separated books list:
`)

        console.log(separatedBooks)
        return
    }

    interaction++
    console.log(`**********************************
Interaction no. : ${interaction}
`)

    if(arr.length > 1) {
        const arrPart1 = arr.slice(0, Math.floor(arr.length / 2))
        const arrPart2 = arr.slice(Math.floor(arr.length / 2), arr.length)

        console.log(`
        Array Part 1:
        `)
        console.log(arrPart1)

        console.log(`
        Array Part 2:
        `)
        console.log(arrPart2)

        mergeSort(arrPart1)
        mergeSort(arrPart2)
    }
}

mergeSort(editorBooks)

