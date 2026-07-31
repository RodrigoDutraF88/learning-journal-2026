--Aula de alter table - read only

--Nessa aula iremos aprender sobre alter table - read only

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
  
alter table funcionario read only;

delete from funcionario; --gera erro

alter table funcionario
add (teste number); --DDL é permitido nesse caso, pois não altera os dados

alter table funcionario
drop (created_by); --DDL não permitido, pois altera os dados

alter table funcionario read write;

delete from funcionario;