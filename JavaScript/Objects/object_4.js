
// const { name } = userErico
// const { dependents } = userErico

// console.log(name, dependents);

const consoleSpaceOut = `
-------------------------------
`

function showClientBalance(client) {
    console.log(`
    Olá sr(a). ${client.name}, seu saldo é de: ${client.balance}
    `)
}

function runTransfer(clientSending, clientReceveing, amountToSend) {
    clientSending.sendTransfer(amountToSend, clientReceveing)
    showClientBalance(clientSending)
    showClientBalance(clientReceveing)
    console.log(consoleSpaceOut)
}

function Client(name, lastName, age, email, cpf, dependents, hasSecure, balance, sendTransfer) {
    this.name = name
    this.lastName = lastName
    this.age = age
    this.email = email
    this.cpf = cpf
    this.dependents = dependents
    this.hasSecure = hasSecure 
    this.balance = balance
    this.sendTransfer = function(value, client) {
        if(this.balance >= value) {
            this.balance -= value
            client.balance += value
        } else {
            console.log(`Desculpe Sr.(a) ${this.nome}, seu saldo de R$ ${this.saldo} é insuficiente para realizar a transação de R$ ${value}`)
        }
    }
}

const userErico = new Client('Érico', 'Cavalcanti', 22, 'ecocaval@hotmail.com', '13140363788', {name: 'Sabrina', relation: 'Daugther'}, false, 1000)
const userVitoria = new Client('Vitoria', 'Harter', 24, 'vitoriaharter@gmail.com', '4495521972', undefined, true, 5000)

const clientAnalyser = Object.entries(userErico)
const clientBasicInfo = []

clientAnalyser.forEach(clientInfo => {
    if(typeof clientInfo[1] != 'object' && typeof clientInfo[1] != 'function' && clientInfo[0] != 'cpf') {
        clientBasicInfo.push(clientInfo)
    }
    // console.log(clientInfo)
})

console.log(clientBasicInfo)




// console.log(userErico)
// console.log(userVitoria)
// runTransfer(userErico,userVitoria,200)
// runTransfer(userVitoria, userErico, 600)



