const chalk = require('chalk');
const fs = require('fs');

function treatError (err) {
    return console.log(chalk.red(`Error! -> ${err}`));
}

function waitingTime () {
    return console.log('waiting!')
}

function takeFile (filePath) {
    const encoding = 'utf-8';
    const text_ = fs.promises.readFile(filePath, encoding)
                    .then((text) => {
                        return text;
                    })
                    .catch((err) => {
                        return treatError(err);
                    });
    waitingTime();
    setTimeout(() => {
        console.log('doing it!')
    }, 10000);
    return text_;
}

async function doSomething () {
    let something = await takeFile('./arquivos/texto1.md');
    return something;
}

doSomething()