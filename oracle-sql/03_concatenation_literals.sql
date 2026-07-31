--Aula de operadores de contatenação e literais
DROP TABLE produto;

CREATE TABLE produto (
    id NUMBER PRIMARY KEY,
    nome VARCHAR2(40),
    validade_meses NUMBER
);

INSERT INTO produto VALUES (1, 'Bala', 100);
INSERT INTO produto VALUES (2, 'Banana', 5);
INSERT INTO produto VALUES (3, 'Chá', 50);

--Operador || concatena colunas em uma só
select nome||validade_meses FROM produto;

--usa um alias para melhor representação
select nome||validade_meses validade FROM produto;

--é possivel inserir espaço entre as colunas
select nome|| ' '||validade_meses validadeFROM produto;

--posso inserir uma cadeia de caracteres na concatenação ( essas cadeias são chamadas de literais)
select nome|| 'vence em:' ||validade_meses|| 'meses' validade FROM produto;

--Literais também podem ser retornados fixos no select
select 'teste' literal --valor fixo no codigo
    FROM produto;