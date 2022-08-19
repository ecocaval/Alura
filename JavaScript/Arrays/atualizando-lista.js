// Sem splice()

const listaDeAlunos = ['João', 'Ana', 'Caio', 'Lara', 'Marjorie', 'Leo']
const copiaListaOriginal = []

const copiaLista = (listaOriginal, copiaDaLista) => {
    for(let i = 0; i < listaOriginal.length; i++) {
        copiaDaLista.push(listaOriginal[i])
    }
}

const limpaCopiaLista = (copiaDaLista) => {
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
    limpaCopiaLista(copiaListaOriginal)
    copiaLista(listaDeAlunos, copiaListaOriginal)
}

listaDeAlunos.push('Rodrigo')

console.log(listaDeAlunos)

/***********************************************************************/

// Com splice()

const listaDeAlunos2 = ['João', 'Ana', 'Caio', 'Lara', 'Marjorie', 'Leo']
console.log(listaDeAlunos2)

listaDeAlunos2.splice(1,2,'Rodrigo')
console.log(listaDeAlunos2)
