--Aula de insert all/first 

--Nessa aula iremos aprender sobre insert all 

drop table funcionario;

create table funcionario(
    id number primary key,
    nome varchar2(40) not null,
    salario number,
    genero char,
    created_date date default sysdate, 
    created_by varchar2(100) default user
);

drop table funcionario2;

create table funcionario2(
    id number primary key,
    nome varchar2(40) not null,
    salario number,
    genero char,
    created_date date default sysdate, 
    created_by varchar2(100) default user
);

insert into funcionario values (1, 'Ana', 500, 'F', sysdate, user);
insert into funcionario values (2, 'Maria', 1000, 'F', sysdate, user);
insert into funcionario values (3, 'João', 700, 'M', sysdate, user);

--Insert incondicional
insert all
into funcionario values (4, nome, salario, genero, sysdate, user)
into funcionario2 values (1, nome, salario, genero, sysdate, user)
select nome, salario, genero 
from funcionario
where id = 1;

select *
  from funcionario;
  
select *
  from funcionario2;
  
--Insert condicional
delete funcionario2;

drop table funcionario3;

create table funcionario3(
    id number primary key,
    nome varchar2(40) not null,
    salario number,
    genero char,
    created_date date default sysdate, 
    created_by varchar2(100) default user
);

insert all
when salario > 500 then
into funcionario2 values (id, nome, salario, genero, sysdate, user)
when genero = 'F' then
into funcionario3 values (id, nome, salario, genero, sysdate, user)
select id, nome, salario, genero 
from funcionario;

select *
  from funcionario2;
  
select *
  from funcionario3;
  
--insert first
delete funcionario2;
delete funcionario3;

insert first
when salario > 500 then
into funcionario2 values (id, nome, salario, genero, sysdate, user)
when genero = 'F' then
into funcionario3 values (id, nome, salario, genero, sysdate, user)
select id, nome, salario, genero 
from funcionario;

select *
  from funcionario2;
  
select *
  from funcionario3;
