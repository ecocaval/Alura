let notas = [10, 8, 9, 10]
let somaDasNotas = 0

notas.forEach((nota) => {
    somaDasNotas += nota
})

let media = somaDasNotas/notas.length

console.log(media)
