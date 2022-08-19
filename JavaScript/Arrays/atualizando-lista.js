const listaDeAlunos = ['João', 'Ana', 'Caio', 'Lara', 'Marjorie', 'Leo']
const copiaListaOriginal = []

console.log(listaDeAlunos)

const copiaLista = (listaOriginal, copiaDaLista) => {
    for(let i = 0; i < listaOriginal.length; i++) {
        copiaDaLista.push(listaOriginal[i])
    }
}

copiaLista(listaDeAlunos, copiaListaOriginal)

for(let i = 0; i < copiaListaOriginal.length; i++) {
    if(copiaListaOriginal[i] == 'Ana') {
        for(let j = i; j < copiaListaOriginal.length; j++){
            listaDeAlunos.pop()
        }
    }
}

console.log(listaDeAlunos)