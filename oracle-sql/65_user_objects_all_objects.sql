--Aula de user_objects/all_objects

--Nessa aula iremos aprender sobre user_objects/all_objects

drop table funcionario;

create table funcionario(
    id number primary key,
    nome varchar2(40) not null,
    salario number,
    genero char,
    created_date date default sysdate, 
    created_by varchar2(100) default user
);

select *
  from user_objects;
  
select *
  from user_objects
 where object_name = 'FUNCIONARIO';
 
select *
  from all_objects;

select *
  from all_objects
 where object_name = 'FUNCIONARIO';
 
select *
  from cat; --cat é um sinonimo de user_catalog
  
select *
  from user_catalog;
 
