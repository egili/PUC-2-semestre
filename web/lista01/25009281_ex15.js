// 25009281

// ex 15
let senhaCorreta = "senha123";
let senhaUsuario = prompt("Digite a senha:");

while (senhaUsuario !== senhaCorreta) {
    senhaUsuario = prompt("Senha incorreta. Tente novamente:");
}
console.log("Acertou a senha!");