--Aula de IN

drop table funcionario;

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

--Para retornar todos os funcionários que possuem idade igual a 18, 22 e 55 podemos realizar a busca da seguinte forma
select nome, idade 
  from funcionario
 where idade = 10 or idade =22 or idade = 55;
 
--O comando IN fará a mesma comparação, porém com uma sintaxe mais simples. 
select nome, idade 
  from funcionario
 where idade IN (10, 22, 55);

--O comando IN aceita valores em data, numero ou caracter.
select nome, idade 
  from funcionario
 where nome in ('Ana', 'Felipe');

--É possível negar a comparação utilizando o comando NOT.
select nome, idade 
  from funcionario
 where nome NOT IN ('Ana', 'Felipe');
 
--É necessário sempre realizar a comparação com variáveis e literais do mesmo tipo
select nome, idade 
  from funcionario
 where idade NOT IN ('Ana', 'Felipe'); --gera erro, pois a coluna idade é do tipo number e as literais do in são caracter
 
--No IN não é necessário respeitar uma ordem de valores da lista.
select nome, idade 
  from funcionario
 where idade IN (55, 22, 10);