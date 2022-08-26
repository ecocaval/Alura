const client = {
    name: 'Andre',
    lastName: 'Andrade',
    age: 18,
    cpf: '129014894039',
    email: 'sadjsi@email.com',

    dependent: {
        name: 'Tamires',
        relation: 'Daughter',
        age: 11
    },

    sendTransf: function(value, client) {
        if(this.balance >= value) {
            this.balance -= value
            client.balance += value
        } else {
            console.log(`Desculpe Sr.(a) ${this.nome}, seu saldo de R$ ${this.saldo} é insuficiente para realizar a transação de R$ ${value}`)
        }
    },
}

let clientReport = {}

for(let clientInfo in client) {
    if(typeof client[clientInfo] === 'function' || typeof client[clientInfo] === 'object' || clientInfo === 'cpf') continue

    clientReport[clientInfo] = client[clientInfo]
}

console.log(clientReport)