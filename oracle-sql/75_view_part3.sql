--Aula de view

--Nessa aula iremos aprender sobre view

drop table funcionario;

drop view func;

drop view func2;

create table funcionario(
    id number primary key,
    nome varchar2(40) not null,
    salario number, 
    dept number
);

insert into funcionario values (1, 'Karol', 400, 1);
insert into funcionario values (2, 'Andre', 1000, 1);
insert into funcionario values (3, 'Ana', 500, 2);

create view func
as
select id, nome
  from funcionario
with read only;

select *
  from func;
  
delete from func; --Gera erro, pois a view foi criada com read only

select *
  from user_constraints
 where table_name = 'FUNC';
 
create or replace view func
as
select id, nome, salario
  from funcionario
 where salario = 400
with check option;
  
select *
  from func;
  
insert into func values (4, 'Maria', 600); --Gera erro, pois a view abrange apenas salarios de 400
 
select *
  from user_constraints
 where table_name = 'FUNC';
 
drop table departamento;

create view func2
as 
select *
  from departamento; --gera erro, pois a tabela não existe
  

create force view func2
as 
select *
  from departamento;
  
select *
  from user_views
 where view_name = 'FUNC2';