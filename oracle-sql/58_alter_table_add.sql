--Aula de alter table 

--Nessa aula iremos aprender sobre alter table 

drop table funcionario;

create table funcionario(
    id number primary key,
    nome varchar2(40) not null,
    salario number
);

insert into funcionario (id, nome, salario)
values (1, 'Karol', 100);

alter table funcionario
add (genero char);

select *
  from funcionario;
  
--Gera erro, pois ja possui um registro na tabela e estamos usando o not null
alter table funcionario
add (comissao number not null); 

alter table funcionario
add (comissao number default 0 not null); 

select *
  from funcionario;

alter table funcionario
add (comissao2 number default 0); 

select *
  from funcionario;
  
alter table funcionario
add (created_date date default sysdate, created_by varchar2(100) default user); 

select *
  from funcionario;

