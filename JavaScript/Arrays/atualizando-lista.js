const listaDeAlunos = ['João', 'Ana', 'Caio', 'Lara', 'Marjorie', 'Leo']
const copiaListaOriginal = []

const copiaLista = (listaOriginal, copiaDaLista) => {
    for(let i = 0; i < listaOriginal.length; i++) {
        copiaDaLista.push(listaOriginal[i])
    }
}

const limpaListaCopia = (copiaDaLista) => {
    const tamanhoDaCopia = copiaDaLista.length
    for(let i = 0; i < tamanhoDaCopia; i++) {
        copiaDaLista.pop()
    }
}

copiaLista(listaDeAlunos, copiaListaOriginal)
console.log(listaDeAlunos)

for(let i = 0; i < copiaListaOriginal.length; i++) {
    if(copiaListaOriginal[i] == 'Ana' || copiaListaOriginal[i] == 'Caio') {
        for(let j = i; j < copiaListaOriginal.length; j++){
            listaDeAlunos.pop()
        } 
        i++
        for(let j = i; j < copiaListaOriginal.length; j++){
            listaDeAlunos.push(copiaListaOriginal[j])
        } 
        i -= 2
    }
    limpaListaCopia(copiaListaOriginal)
    copiaLista(listaDeAlunos, copiaListaOriginal)
}

listaDeAlunos.push('Rodrigo')

console.log(listaDeAlunos)