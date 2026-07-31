--Aula de drop table

--Nessa aula iremos aprender sobre drop table

drop table funcionario;

create table funcionario(
    id number primary key,
    nome varchar2(40) not null,
    salario number,
    genero char,
    created_date date default sysdate, 
    created_by varchar2(100) default user
);
  
insert into funcionario (id, nome, salario)
values (1, 'Karol', 100);

select *
  from funcionario;

drop table funcionario;

select *
  from funcionario;
  
select *
  from user_recyclebin
 where original_name = 'FUNCIONARIO';
 

create table funcionario2(
    id number primary key,
    nome varchar2(40) not null,
    salario number,
    genero char,
    created_date date default sysdate, 
    created_by varchar2(100) default user
);
  
select *
  from funcionario2;

drop table funcionario2 purge;

select *
  from funcionario2;
  
select *
  from user_recyclebin
 where original_name = 'FUNCIONARIO2';
 
 