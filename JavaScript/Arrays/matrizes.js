let alunos = ['Joao', 'Carlos', 'Roberto', 'Rodrigo']
let mediasDosAlunos = [10, 8, 5, 7]

let salaDeAula = [alunos, mediasDosAlunos]

const exibeNomeENota = (nomeDoAluno) => {
    if(salaDeAula[0].includes(nomeDoAluno)) {
        let indiceDoAluno = salaDeAula[0].indexOf(nomeDoAluno)
        return `${salaDeAula[0][indiceDoAluno]} nota: ${salaDeAula[1][indiceDoAluno]}`
    } else {
        return 'Aluno não cadastrado!'
    }
}

console.log(exibeNomeENota('Roberto'))
console.log(exibeNomeENota('Carlos'))

console.log(salaDeAula)