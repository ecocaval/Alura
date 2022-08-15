let notas = [10, 6.5, 8, 7.5]

let medias = [0]

for(let i = 0; i < notas.length; i++) {
    medias[0] += notas[i]
}

medias[0] /= notas.length

console.log(medias[0])
