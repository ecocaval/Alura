const chalk = require('chalk');
const fs = require('fs');

function treatError (err) {
    return console.log(chalk.red(`An error was detected!\n${err}`));
}

async function readFile (filePath) {
    const encoding = 'utf-8';
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

setTimeout(() => console.log(chalk.yellow('12345')), 10);

