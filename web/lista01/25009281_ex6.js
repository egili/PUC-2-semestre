// 25009281

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