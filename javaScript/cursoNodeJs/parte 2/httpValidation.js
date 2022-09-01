const fetch = (...args) => import('node-fetch').then(({default: fetch}) => fetch(...args));

function geraArrayDeURLs (objectsArr, urlsArr) {
    objectsArr.forEach(element => {
        urlsArr.push((Object.values(element))[0]);
    });
}

async function validaURLs (arrayDeLinksParaValidar) {
    try {
        const urlsArr = []; 
        geraArrayDeURLs(arrayDeLinksParaValidar, urlsArr);
        const linksStatus = await checaStatus(urlsArr);
        return linksStatus;
    } catch (err) {
        return err;
    }
}

async function checaStatus (urlsArr) {
    try {
        const statusArr = Promise.all(urlsArr.map(async (url) => {
            const res = await fetch(url);
            return res.status;
        }));
        return statusArr;
    } catch (err) {
        return err;
    }
}

module.exports = validaURLs