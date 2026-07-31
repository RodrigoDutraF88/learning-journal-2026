--Aula de rename

--Nessa aula iremos aprender sobre rename

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

alter table funcionario
rename column created_by to criado_por;

select *
  from funcionario;
  
rename funcionario to func;

select *
  from funcionario; --gera erro
  
select *
  from func;