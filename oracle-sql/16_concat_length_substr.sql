--Aula da funções de caracter (CONCAT, LENGTH, SUBSTR)


drop table funcionario;

create table funcionario(
    id number primary key,
    nome varchar2(40),
    sobrenome varchar2(40)
);

insert into funcionario values (1, 'Ana', 'Souza');
insert into funcionario values (2, 'Ana', 'Silva');
insert into funcionario values (3, 'Bianca', 'Oliveira');
insert into funcionario values (4, 'Marcos', 'Andrade');
insert into funcionario values (5, null, null);

/*Após a execução desses scripts podemos iniciar a utilização das funções*/

--CONCAT: concatena duas strings. Equivalente ao operador ||
select concat(nome, sobrenome)
  from funcionario; 
  
--Aceita concatenar apenas duas cadeias de caracteres
select concat(nome, ' ', sobrenome)
  from funcionario; --Gera erro, pois estamos tentando passar 3 argumentos
  
--Podemos usar o operador || dentro da função concat
select concat(nome||' ', sobrenome)
  from funcionario;
  
--LENGTH: retorna o número de caracteres de uma expressão
select length(nome), nome
  from funcionario; 

--Pode-se aninhar as funções
select length(concat(nome, sobrenome)), concat(nome, sobrenome)
  from funcionario;   --Observe que o tamanho de uma coluna nula, também será nulo
 
--SUBSTR: obter uma string de uma outra string
--O primeiro argumento é a string em que vamos buscar
--O segundo é a posição em que iniciaremos a busca
select substr(sobrenome, 1), sobrenome
  from funcionario;
  
select substr(sobrenome, 3), sobrenome
  from funcionario;

--O terceiro argumento é a quantidade de caracteres que vamos buscar (campo opcional).
--Se esse campo não for especificado é selecionada a string até o final
select substr(sobrenome, 2, 2), sobrenome
  from funcionario;
  
--O segundo argumento pode ser negativo. Nesse caso, a contagem da posição inicial começará do final da string
select substr(sobrenome, -4, 2), sobrenome
  from funcionario;
 
