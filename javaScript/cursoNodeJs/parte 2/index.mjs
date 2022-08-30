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
    \[[\w]*\} ----> seleciona todas (*) as palavras (\w) dentro de (\[) e (\]) -> note que o '\' 
    é para que a [ e a ] nao sejam consfundidas com um vetor).
*/


