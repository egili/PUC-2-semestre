// 25009281

// ex 1

let nome = "Eliseu";
console.log(`Bem-vindo, ${nome}!`);

// ex 2 

let idade = 23;
let altura = 1.90;
let estudante = true;

console.log(`Idade: ${idade}, Tipo: ${typeof idade}`);
console.log(`Altura: ${altura}, Tipo: ${typeof altura}`);
console.log(`Estudante: ${estudante}, Tipo: ${typeof estudante}`);

// ex 3

let num1 = parseFloat(prompt("Digite o primeiro número:"));
let num2 = parseFloat(prompt("Digite o segundo número:"));
console.log(`Soma: ${num1 + num2}`);
console.log(`Subtração: ${num1 - num2}`);
console.log(`Multiplicação: ${num1 * num2}`);
console.log(`Divisão: ${num1 / num2}`);

// ex 4
let idadeUsuario = parseInt(prompt("Digite sua idade em anos:"));
if(idadeUsuario >= 18) {
    console.log("Você é maior de idade.");
} else {
    console.log("Você é menor de idade.");
}

// ex 5
let numero = parseInt(prompt("Digite um número:"));
if(numero % 2 === 0) {
    console.log("O número é par.");
} else {
    console.log("O número é ímpar.");
}

// ex 6
let nota1 = parseFloat(prompt("Digite a primeira nota:"));
let nota2 = parseFloat(prompt("Digite a segunda nota:"));
let media = (nota1 + nota2) / 2;

if(media >= 7) {
    console.log("Aprovado");
} else if(media >= 5) {
    console.log("Recuperação");
} else {
    console.log("Reprovado");
}

// ex 7
for(let i = 1; i <= 10; i++) {
    console.log(i);
}

// ex 8
let soma = 0;

for (let i = 1; i <= 100; i++) {
    soma += i;
}

console.log(`A soma de 1 a 100 é: ${soma}`);

// ex 9
let n = prompt("Digite um número para ver a tabuada:");
n = Number(n);

console.log(`Tabuada do ${n}:`);
for (let i = 1; i <= 10; i++) {
    console.log(`${n} x ${i} = ${n * i}`);
}

// ex 10
let frutas = ["maçã", "banana", "laranja", "uva", "pera"];
frutas.forEach(fruta => {
    console.log(fruta);
});

// ex 11
let numeros = [10, 20, 30, 40, 50];
numeros.forEach(num => {
    console.log(num * 2);
});

// ex 12
let nomes = ["Ana", "Bruno", "Carlos", "Diana", "Eduardo"];
nomes.forEach(nome => {
    console.log(`Olá, ${nome}!`);
});

// ex 13
let i = 1;

while (i <= 10) {
    console.log(i);
    i++;
}

// ex 14
let numeroContagem = prompt("Digite um número para iniciar a contagem regressiva:");

numeroContagem = Number(numeroContagem);

console.log(`Contagem regressiva a partir de ${numeroContagem}:`);
while (numeroContagem >= 0) {
    console.log(numeroContagem);
    numeroContagem--;
}

// ex 15
let senhaCorreta = "senha123";
let senhaUsuario = prompt("Digite a senha:");

while (senhaUsuario !== senhaCorreta) {
    senhaUsuario = prompt("Senha incorreta. Tente novamente:");
}
console.log("Acertou a senha!");