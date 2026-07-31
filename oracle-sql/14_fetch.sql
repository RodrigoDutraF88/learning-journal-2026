--Aula da clausula fetch

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

--Limita a quantidade de registros retornados pela consulta
select nome
  from funcionario
 fetch first 2 rows only; 
 
--first/next possui a mesma função
select nome
  from funcionario
 fetch first 2 rows only; --Mesmo retorno da consulta anterior
 
--row/rows - limita pelo número de linhas
select nome
  from funcionario
 fetch first 2 row only;--Mesmo retorno da consulta anterior
 
--percent rows only - limita pela porcentagem de registros
select nome
  from funcionario
 fetch first 20 percent rows only;
 
--with ties - se existir registros duplicados, pode retornar mais valores do que o especificado 
--Observação: quando utilizamos essa cláusula é recomendado o uso do group by na consulta
select nome
  from funcionario
 order by nome
 fetch first 20 percent rows with ties;
 
select nome
  from funcionario
 fetch first 20 percent rows with ties; --Não retorna o segundo nome 'Ana', mesmo com a clausula with ties devido a ausencia de group by

--OFFSET: inicia o retorno dos resultados a partir de uma determinada linha
select nome
  from funcionario
 order by nome
 offset 2 rows fetch first 2 rows only; 
 
--caso o offset for negativo, considera-se como 0
select nome
  from funcionario
 order by nome
 offset -5 rows fetch first 2 rows only; 
 