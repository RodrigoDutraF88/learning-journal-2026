--Aula de commit e rollback


drop table funcionario;

create table funcionario(
    id number primary key,
    nome varchar2(40),
    salario number
);

insert into funcionario values (1, 'Karol', 1300);
insert into funcionario values (2, 'Ana', 2000);
insert into funcionario values (3, 'Bianca', 5000);
insert into funcionario values (4, 'Marcos', 2500);
insert into funcionario values (5, 'João', 630);
insert into funcionario values (6, 'Alan', null);
--Commit para finalizar essa transação
commit;

---------------------------------------------------------------------
--Iniciando uma nova transação
--1
insert into funcionario values (8, 'TESTE', null);

--2
update funcionario
   set salario = 100000
 where id = 4;
 
--3
delete 
  from funcionario
 where id = 5;
 
--Commit efetivará as 3 instruções.
commit;

select *
  from funcionario
 order by id; 
---------------------------------------------------------------------
--Iniciando uma nova transação
--1
insert into funcionario values (9, 'TESTE', null);

--2
update funcionario
   set salario = 200
 where id = 4;
 
--3
delete 
  from funcionario
 where id = 1;

--Rollback retornará as 3 instruções
rollback;

select *
  from funcionario
 order by id; 
---------------------------------------------------------------------
--Iniciando uma nova transação
--1
insert into funcionario values (10, 'TESTE', null);
 
--2 
delete 
  from funcionario
 where id = 4;
 
--Instrução DDL faz commit implicito 
create table func_tmp(
    id number,
    nome varchar2(40)
);

--O rollback não funcionará, pois as instruções já foram commitadas
rollback;

select *
  from funcionario
 order by id; 
---------------------------------------------------------------------
--Iniciando uma nova transação
--1
delete 
  from funcionario
 where id = 1;
 
--2 
delete 
  from funcionario;

--3  
delete 
  from funcionario
 where id = 2;
 
--Oracle irá fazer o rollback apenas da instrução 2 (statement-level rollback)
rollback;
--Nas outras transações (1, 3) poderão ser aplicados commit ou rollback
commit;

select *
  from funcionario
 order by id; 
---------------------------------------------------------------------


