--Aula de between

create table funcionario(
    id number primary key,
    nome varchar2(40),
    idade number
);

insert into funcionario values (1, 'Ana', 22);
insert into funcionario values (2, 'Felipe', 55);
insert into funcionario values (3, 'Bianca', 2);
insert into funcionario values (4, 'Marcos', 10);
insert into funcionario values (5, 'Julio', 18);

/*Após a execução desses scripts podemos iniciar as instruções de busca*/

--Para retornar todos os funcionários com idade entre 10 e 22 anos podemos utilizar os operadores >= e <=
select nome, idade 
  from funcionario
 where idade >= 10 and idade <=22;
 
--O comando between fará a mesma comparação, porém com uma sintaxe mais simples. 
select nome, idade 
  from funcionario
 where idade between 10 and 22;

--O comando between aceita valores em data, numero ou caracter.
select nome, idade 
  from funcionario
 where nome between 'Ana' and 'Felipe';

--É possível negar o range utilizando o comando NOT antes do between.
select nome, idade 
  from funcionario
 where idade NOT between 10 and 22;
 
--Observação: Insira sempre o menor valor e em seguinda o maior valor no range do between.
select nome, idade 
  from funcionario
 where idade between 22 and 10; --Não retornará nada, pois o range está na ordem errada.