const livrosAnalisados = require('./arrays.js')
// console.log(livrosAnalisados)
// console.log((livrosAnalisados.edFolha[atualListaFolha]).preco)

let livrosOrdenados = []

let atualListaFolha = 0 
let atualListaGalho = 0
 
const listaFolhaTamanho = livrosAnalisados.edFolha.length
const listaGalhoTamanho = livrosAnalisados.edGalho.length
 
const atualFinalMax = listaFolhaTamanho + listaGalhoTamanho
// console.log(atualFinalMax)

for(let atualFinal = 0; atualFinal < 4; atualFinal++) {
    if((livrosAnalisados.edFolha[atualListaFolha]).preco < livrosAnalisados.edGalho[atualListaGalho].preco) {
        livrosOrdenados.push(livrosAnalisados.edFolha[atualListaFolha])
        atualListaFolha++
        continue
    }
    
    livrosOrdenados.push(livrosAnalisados.edGalho[atualListaGalho])
    atualListaGalho++
}

console.log(livrosOrdenados)

// console.log(livrosOrdenados)