import chalk from 'chalk';

const user = {
    nome: 'erico',
    email: 'ecocaval@hotmail.com',
    nascimento: '18/02/2000',
    role: 'admin',
    ativo: true,
    exibirInfos: function() {
        console.log((chalk.yellow('Nome: ')) + this.nome);
        console.log((chalk.yellow('Email: ')) + this.email);
        console.log((chalk.yellow('Nascimento: ')) + this.nascimento);
    }
}

user.exibirInfos();