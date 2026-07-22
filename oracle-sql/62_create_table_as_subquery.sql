--Aula de create table as subquery
--Nessa aula iremos aprender sobre create table as subquery

--Criando uma tabela
drop table funcionario;

create table funcionario(
    id number primary key,
    nome varchar2(30) not null,
    salario number
);

insert into funcionario values (1, 'Karol', 1000);
insert into funcionario values (2, 'João', 2000);
insert into funcionario values (3, 'Ana', 3000);
insert into funcionario values (4, 'Maria', 4000);

select *
  from funcionario;
  
create table func2
as 
select id, nome, salario
  from funcionario;
  
select *
  from func2;
  
create table func3 (id_func, nome_func, salario_func default 0)
as 
select *
  from funcionario
 where salario > 2000;
  
select *
  from func3;
  
--gera erro, pois quando utilizamos expressões ou funções devemos inserir um alias
create table func4
as 
select nome, salario+1000
  from funcionario;

create table func4
as 
select nome, salario+1000 sal_max
  from funcionario;
  
select *
  from func4;
