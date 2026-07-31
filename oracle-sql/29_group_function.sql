--Aula de funções de grupo

--Nessa aula iremos aprender sobre funções de grupo

drop table funcionario;

create table funcionario(
    id number primary key,
    nome varchar2(40),
    idade number
);

insert into funcionario values (1, 'Karol', 23);
insert into funcionario values (2, 'Ana', 18);
insert into funcionario values (3, 'Bianca', 16);
insert into funcionario values (4, 'Marcos', 10);
insert into funcionario values (5, 'João', null);
insert into funcionario values (6, 'Alan', 10);

select idade
  from funcionario
 order by idade;
  
select max(idade), min(idade)
  from funcionario; --Valor nulo descartado
  
select max(idade), min(idade)
  from funcionario
 where idade > 50; --Se não existir registros, retorna null
 
select sum(idade), sum(distinct idade), sum(all idade)
  from funcionario; --All é default

select count(idade), count(distinct idade)
  from funcionario; --Null foi descartado
 
select avg(idade), avg(distinct idade)
  from funcionario; --Null descartado
 
--Para forçar que as funções considerem o valor null, utilize a função nvl
select count(nvl(idade, 0)), sum(nvl(idade, 0)), max(nvl(idade, 0)), min(nvl(idade, 0)), avg(nvl(idade, 0))
  from funcionario;

--Podemos utilizar data e caracter com as funções count, max e min
select count(nome), max(nome), min(nome)
  from funcionario;

