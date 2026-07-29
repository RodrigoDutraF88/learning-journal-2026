--Aula sobre renomear colunas/constraints

--Nessa aula iremos aprender sobre renomear colunas/constraints

drop table funcionario;

create table funcionario(
    id number primary key,
    nome varchar2(40),
    salario number, 
    dept number
);

select *
  from user_cons_columns
 where table_name = 'FUNCIONARIO';
 
alter table funcionario
rename column id to id_func;

select *
  from user_cons_columns
 where table_name = 'FUNCIONARIO';
 
select *
  from user_constraints 
 where table_name = 'FUNCIONARIO';
 
alter table funcionario
rename constraint SYS_C0023547620 to pk_funcionario;

select *
  from user_constraints 
 where table_name = 'FUNCIONARIO';