const chalk = require('chalk');
const fs = require('fs');

function treatError (err) {
    return console.log(chalk.red(`An error was detected!\n${err}`));
}

async function readFile (filePath) {
    const encoding = 'utf-8';

    console.log('\nStarted reading file...')
    try {
        const texto = await fs.promises.readFile(filePath, encoding);
        console.log(chalk.green(texto));
    } catch (err) {
        treatError(err);
    } finally {
        console.log('Finished reading file...')
    }
}

readFile('./arquivos/texto1.md');

/*
    EXPRESSOES REGULARES:
    1) \[[\w]*\} ----> seleciona todas (*) as palavras (\w) dentro de (\[) e (\]) -> note que o '\' 
    é para que a [ e a ] nao sejam consfundidas com um vetor). Para o nosso caso o problema desta
    abordagem é que não seram considerados caracteres especiais incluidos dentro de '[]' no caso de
    '<input>' por exemplo, para resolver isso podemos realizar a expressão da seguinte maneira:

    2) \[[^\]*\] ----> selecionas tudo (*) que começa em [ e não termina com ] (^\]) e vai até ]. 

    agora querendo encontrar os links kttps entre ()

    3) \(https?:\/\/[^$#\s].[^\s]*\)  ---->  seleciona tudo que começa com '(https?://' + tudo que nao
    os '[]' aqui       \s faz referencia |   for '$', '#', ' ' (representado por \s) + '.' + tudo que
    criam uma classe.  a "white space". |    nao for ' ' até ')' (o qual também precisa iniciar com \).

    Para declarar una expressão regular em javascript utilizamos '//'

    ex: const regex = /[a-zA-z\s]/;
        let regex = new RegExp("[a-zA-z\s]");
*/                


