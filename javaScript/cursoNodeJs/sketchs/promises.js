/*
    Uma função declarada como async significa que o valor de 
    retorno da função será, "por baixo dos panos", uma Promise.
*/
async function getUser(userId) {
    let response = await fetch(`https://api.com/api/user/${userId}`);
    let userData = await response.json();
    return userData.name; // nas linhas de return não é necessário usar await
}

async function getCustomerOrders(customerId) {
    const response = await fetch(`https://api.com/api/customer/${customerId}`)
    const customer = await response.json()
   
    return await Promise.all(customer.orders.map(async (orderId) => {
      const response = await fetch(`https://api.com/api/order/${orderId}`)
      const orderData = await response.json()
      return orderData.amount
    }))
}