
// 25009281 - Eliseu Pereira Gili
// Exercicio do Slide 20 da aula 03 Javascript - Objetos

function Cilindro(r, h) {
  this.raioBase = r;
  this.altura = h;

  this.calculaAreaBase = function() {
    return Math.PI * Math.pow(this.raioBase, 2);
  };

  this.calculaAreaLateral = function() {
    return 2 * Math.PI * this.raioBase * this.altura;
  };

  this.calculaAreaTotal = function() {
    return 2 * this.calculaAreaBase() + this.calculaAreaLateral();
  };

  this.calculaVolume = function() {
    return this.calculaAreaBase() * this.altura;
  };
}

const cilindroUm = new Cilindro(2, 5);

alert(
  "Raio da base: " + cilindroUm.raioBase +
  "\nAltura: " + cilindroUm.altura +
  "\nÁrea da base: " + cilindroUm.calculaAreaBase().toFixed(2) +
  "\nÁrea lateral: " + cilindroUm.calculaAreaLateral().toFixed(2) +
  "\nÁrea total: " + cilindroUm.calculaAreaTotal().toFixed(2) +
  "\nVolume: " + cilindroUm.calculaVolume().toFixed(2)
);
