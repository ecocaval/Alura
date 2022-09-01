const chalk = require("chalk"); // must be installed through npm install chalk
const fs = require('fs'); // there's no need to install fs

function treatError (err) {
    throw new Error(chalk.red(err.code, "There's no reading file in this directory!"));
}

async function readfile (fileToCatchPath, encoding) {
    return fs.readFile(fileToCatchPath, encoding)
                .then((textFomFile) => console.log(chalk.yellow(textFomFile)))
}

async function catchFile (fileToCatchPath) {
    const encoding = 'utf-8';
    try {
        return await readfile(fileToCatchPath, encoding);
    } catch (err) {
        return await treatError(err);        
    }
}

async function catchIt () {
    const catchIt = await catchFile('./arquivos/texto1.md');
    return catchIt;
}

catchIt()


// function catchFile (fileToCatchPath) {
//     const encoding = 'utf-8';

//     fs.promises
//     .readFile(fileToCatchPath, encoding)
//     .then((textFomFile) => console.log(chalk.yellow(textFomFile)))
//     .catch((err) => treatError(err))
// }

// catchFile('./arquivos/texto1.md');


/*
function catchFile (fileToCatchPath) {
    const encoding = 'utf-8';
    const callBackCatchFIle = (err, textReceived) => {
        if(err) {
            return treatError(err)
        }
        return console.log(chalk.yellow(textReceived));
    };
    fs.readFile(fileToCatchPath, encoding, callBackCatchFIle);
}

fs refers to 'file system'  -> fs.readFile(file, [encoding], [callback]);
    obs: file = (string) filepath of the file to read;
        encoding = will normally refer to 'UTF-8';
        callback = function (err, data) {
            if (err) {
                return console.log(err);
            }
            console.log(data);
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
*/
