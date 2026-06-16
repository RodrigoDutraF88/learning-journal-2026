--Aula da clausula order by

drop table funcionario;

create table funcionario(
    id number primary key,
    nome varchar2(40),
    idade number
);

insert into funcionario values (1, 'Ana', 23);
insert into funcionario values (2, 'Ana', 25);
insert into funcionario values (3, 'Bianca', 46);
insert into funcionario values (4, 'Marcos', 33);
insert into funcionario values (5, null, null);

/*Após a execução desses scripts podemos iniciar as instruções de busca*/

--Order by ordernará o resultado da consulta
select nome
  from funcionario
 order by nome; 

--O default de ordenação é em ordem crescente (ASC)
select nome
  from funcionario
 order by nome ASC; --mesmo resultado da consulta anterior
 
--Podemos alterar a ordenação para decrescente utilizando o comando DESC
select nome
  from funcionario
 order by nome DESC;
 
--Valores null aparecem ao final da lista na ordem crescente - Default nulls last.
select nome
  from funcionario
 order by nome ASC;
 
select nome
  from funcionario
 order by nome ASC NULLS LAST; --mesmo retorno do comando anterior
 
--Podemos utilizá-lo para manter os valores null ao final, mesmo na ordem decrescente
select nome
  from funcionario
 order by nome DESC NULLS LAST;
 
--Podemos utilizar o comando NULLS FIRST para mostrar os valores nulos antes dos outros valores
select nome
  from funcionario
 order by nome NULLS FIRST;
 
--Podemos mesclar o tipo de ordenação
select nome, idade
  from funcionario
 order by nome ASC, idade DESC;
 
--É possível inserir no order by colunas que não estão no select (não é muito recomendado)
select nome, idade
  from funcionario
 order by id;
 
--Utilizando alias no order by
--É possível utilizar os alias das colunas do select no order by
select nome n, idade i
  from funcionario
 order by n, i;
 
--Também é possível utilizar os numerais referentes a posição da coluna no select 
select nome, idade
  from funcionario
 order by 2;
 
--Assim como é permitido mesclar todas as opções
select nome n, idade
  from funcionario
 order by 2, id, n;