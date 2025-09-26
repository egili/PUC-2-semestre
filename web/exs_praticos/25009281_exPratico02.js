
// 25009281

function todosCaracteresIguais(cpf) {
    let allEqual = true;

    cpf.split("").forEach((digit) => {
        if (digit !== cpf[0]) {
            allEqual = false;
        }
    });

    return allEqual;
}

function removerCaracteresEspeciais(cpf) {
    let novoCPF = "";

    for (let char of cpf) {
        if (char >= "0" && char <= "9") {
            novoCPF += char;
        }
    }
    return novoCPF;
}

function calcularDigito(cpf, pesoInicial) {
    let soma = 0;
    let peso = pesoInicial;

    for (let i = 0; i < pesoInicial - 1; i++) {
        soma = soma + parseInt(cpf[i]) * peso;
        peso = peso - 1;
    }

    let resto = soma % 11;
    let digito = 11 - resto;

    if (digito == 10 || digito == 11) {
        digito = 0;
    }

    return digito;
}

function validarCPF(cpf) {
    cpf = removerCaracteresEspeciais(cpf);

    if (cpf.length !== 11 || todosCaracteresIguais(cpf)) {
        return false;
    }

    return calcularDigito(cpf, 10) === parseInt(cpf[9]) && calcularDigito(cpf, 11) === parseInt(cpf[10]);
}

function testarCPF(cpf, esperado) {
    const resultado = validarCPF(cpf);
    const status = resultado === esperado ? "CERTO" : "ERRADO";
    console.log(`${status} CPF: ${cpf} -> Esperado: ${esperado}, Obtido: ${resultado}`);
}

function testes() {
    console.log("Testes de Validação de CPF\n");
    
    testarCPF("529.982.247-25", true);
    testarCPF("52998224725", true);
    testarCPF("11144477735", true);
    
    testarCPF("123.456.789-00", false); 
    testarCPF("000.000.000-00", false);
    testarCPF("12345678900", false);
    testarCPF("52998224735", false);    
    
    testarCPF("1", false);              
    testarCPF("", false);               
    testarCPF("abcdefghijk", false);    
    
    console.log("\nFim dos Testes");
}

function main() {

    testes();

    const fazerTeste = prompt('Deseja validar um CPF? (S/N)').toUpperCase();
    
    if (fazerTeste !== 'S') {
        return;
    }
    
    const cpf = prompt("CPF: ");

    if (validarCPF(cpf)) {
        console.log(`O CPF ${cpf} é VÁLIDO.`);
    } else {
        console.log(`O CPF ${cpf} é INVÁLIDO.`);
    }
}

main();