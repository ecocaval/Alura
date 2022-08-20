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

const cliente = {
    nome: 'Andre',
    sobrenome: 'Andrade',
    idade: 18,
    cpf: '129014894039',
    email: 'sadjsi@email.com'
}


const chavesAnalisadas = ['nome', 'sobrenome', 'idade', 'cpf']

chavesAnalisadas.forEach(chave =>{
    console.log(cliente[chave])
})