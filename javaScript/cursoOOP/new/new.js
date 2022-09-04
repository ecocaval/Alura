function User (name, email) {
    this.name = name;
    this.email = email;

    this.exibirInfos = function () {
        return console.log(`${this.name} // ${this.email}`);
    }
}

function Admin (role) {
    User.call(this, 'randName', 'randEmail');
    this.role = role || 'estudante';
}

Admin.prototype = Object.create(User.prototype);
const admin1 = new Admin('admin');
admin1.exibirInfos();

const user1 = new User('randName', 'randEMail');
console.log(user1);
user1.exibirInfos();