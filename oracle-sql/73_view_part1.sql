--Aula de view

--Nessa aula iremos aprender sobre view

drop table funcionario;

create table funcionario(
    id number primary key,
    nome varchar2(40) not null unique,
    salario number
);

insert into funcionario values (1, 'Karol', 400);

create view func
as
select id, nome
  from funcionario;
  
select *
  from func;
 
insert into func values (2, 'Ana');

select *
  from funcionario;
  
select *
  from user_views;
  
drop view func;
  
create view func
as
select id id_func, nome nome_func
  from funcionario;
  
select *
  from func;
  
insert into func(id_func, nome_func) values (3, 'Bianca');

drop view func;
  
create view func (id_func, nome_func)
as
select id, nome
  from funcionario;
  
select *
  from func;
  
insert into func(id_func, nome_func) values (4, 'João');