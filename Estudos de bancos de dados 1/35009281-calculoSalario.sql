SET SERVEROUTPUT ON;

-- Eliseu Pereira Gili
-- 25009281

DECLARE
    vSalarioBruto NUMBER := 3000; 
    vINSS NUMBER;
    vIRRF NUMBER;
    vSalarioLiquido NUMBER;
BEGIN
    
    IF vSalarioBruto <= 1412 THEN
        vINSS := vSalarioBruto * 0.075;
    ELSIF vSalarioBruto <= 2666.68 THEN
        vINSS := vSalarioBruto * 0.09;
    ELSIF vSalarioBruto <= 4000.03 THEN
        vINSS := vSalarioBruto * 0.12;
    ELSIF vSalarioBruto <= 7786.02 THEN
        vINSS := vSalarioBruto * 0.14;
    ELSE
        vINSS := 908.85; 
    END IF;

    vIRRF := (vSalarioBruto - vINSS) * 0.15 - 169.44; 
    
    IF (vSalarioBruto - vINSS) <= 2259.20 THEN
        vIRRF := 0;
    END IF;

    vSalarioLiquido := vSalarioBruto - vINSS - vIRRF;

    DBMS_OUTPUT.PUT_LINE('Salário Bruto: R$ ' || vSalarioBruto);
    DBMS_OUTPUT.PUT_LINE('INSS: R$ ' || ROUND(vINSS, 2));
    DBMS_OUTPUT.PUT_LINE('IRRF: R$ ' || ROUND(vIRRF, 2));
    DBMS_OUTPUT.PUT_LINE('Salário Líquido: R$ ' || ROUND(vSalarioLiquido, 2));
END;
/