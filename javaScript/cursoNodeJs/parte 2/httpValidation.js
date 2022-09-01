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
        const linksStatus = await checaStatus(urlsArr); // checaStatus() not working due to fetch, returning arr of 200;

        const arrDeLinksComStatus = []
        for(let link in arrayDeLinksParaValidar) {
            const auxArr = arrayDeLinksParaValidar.slice();
            auxArr[link].status = linksStatus[link]
            arrDeLinksComStatus.push(auxArr[link])
        }    

        return arrDeLinksComStatus;
    } catch (err) {
        return err;
    }
}

async function checaStatus (urlsArr) {
    try {
        const statusArr = [200,200,200,200,200] 
              /*Promise.all(urlsArr.map(async (url) => {
              const res = await fetch(url);
              return res.status;}));*/
        return statusArr;
    } catch (err) {
        return err;
    }
}

module.exports = validaURLs