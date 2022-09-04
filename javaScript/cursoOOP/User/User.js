export default class User {
    constructor(nome, email, nascimento, role, ativo = true) {
        this.nome = nome;
        this.email = email;
        this.nascimento = nascimento;
        this.role = role;
        this.ativo = ativo;
    }

    exibirInfos() {
        console.log(`nome: ${this.nome}, email: ${this.email}.`);
    }
}

