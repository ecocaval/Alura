// let letraA = ['a']
// let letraB = ['b']

// let letrasAB = ''

// letrasAB += letraA
// letrasAB += letraB

// console.log(letrasAB); 

// let nome = "André"
// let sobreNome ="Silva"
// let nomeCompleto = "Meu nome completo é : " + nome + sobreNome

// console.log(nomeCompleto)

// let linguagens = "JavaScript; Java; C#; PHP; Python; Go; Vb; SQL; C; C++"; 
// let arrayLinguagens = linguagens.split("; "); 
// console.log(arrayLinguagens)

// let login = "   andre@emailteste.com      ";
// let loginSemEspaco = login.trim();
// console.log(loginSemEspaco); //andre@emailteste.com

// class User {
//     constructor(firstName, lastName, age, dateAccountCreation, accountStatus) {
//         this.firstName = firstName
//         this.lastName = lastName
//         this.age = age
//         this.dateAccountCreation = dateAccountCreation
//         this.accountStatus = accountStatus
//     }
// }

// let userErico = new User('Erico', 'Cavalcanti', '22', '22/11/2015', 'Premium')
// let userVitoria = new User('Vitoria', 'Harter', '24', '24/03/2007', 'Standard')

// console.log(userErico)
// console.log(userVitoria)

// const cliente = {
//     nome: 'Andre',
//     sobrenome: 'Andrade',
//     idade: 18,
//     cpf: '129014894039',
//     email: 'sadjsi@email.com'
// }


// const chavesAnalisadas = ['nome', 'sobrenome', 'idade', 'cpf']

// chavesAnalisadas.forEach(chave =>{
//     console.log(cliente[chave])
// })

// class Cliente {
//     constructor(nome, idade, cpf, email, telefones, dependentes) {
//         this.nome = nome
//         this.idade = idade
//         this.cpf = cpf
//         this.email = email
//         this.telefones = telefones
//         this.dependentes = dependentes
//     }
// }

// let erico = new Cliente('Erico', 
//                          22, 
//                         '13140363788', 
//                         'ecocaval@hotmail.com', 
//                         ['24992266520', '48999917321'], 
//                         [{nome: 'Sabrina', parentesco: 'Filha', idade: 9}])

// erico.dependentes.push({nome: 'Samara', parentesco: 'Filha', idade: 13})                       

// erico.dependentes.forEach(dependente => {
//     if(dependente.idade > 8) {
//         console.log(dependente.idade)
//     }
// })

let cliente1 = {
    nome: 'Erico',
    saldo: 100,

    enviaTransf: function(valor, cliente) {
        if(this.saldo >= valor) {
            this.saldo -= valor
            cliente.saldo += valor
        }
    },
}

let cliente2 = {
    nome: 'Roberto',
    saldo: 100,

    enviaTransf: function(valor, cliente) {
        if(this.saldo >= valor) {
            this.saldo -= valor
            cliente.saldo += valor
        } else {
            console.log(`Desculpe Sr.(a) ${this.nome}, seu saldo de R$ ${this.saldo} é insuficiente para realizar a transação de R$ ${valor}`)
        }
    },
}

console.log(`Saldo do cliente 1: ${cliente1.saldo}`, `Saldo do cliente 2: ${cliente2.saldo}`)

cliente1.enviaTransf(50, cliente2)

console.log(`Saldo do cliente 1: ${cliente1.saldo}`, `Saldo do cliente 2: ${cliente2.saldo}`)

cliente2.enviaTransf(200,cliente1)

console.log(`Saldo do cliente 1: ${cliente1.saldo}`, `Saldo do cliente 2: ${cliente2.saldo}`)