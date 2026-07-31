--Aula sobre adicionar/remover constraints

--Nessa aula iremos aprender sobre adicionar/remover constraints

drop table funcionario;

create table funcionario(
    id number,
    nome varchar2(40),
    salario number, 
    dept number
);

alter table funcionario
modify id primary key;

select *
  from user_constraints
 where table_name = 'FUNCIONARIO';
 
alter table funcionario
drop constraint SYS_C0023547358;

select *
  from user_constraints
 where table_name = 'FUNCIONARIO';
 
alter table funcionario 
add constraint pk_funcionario primary key (id);

select *
  from user_constraints
 where table_name = 'FUNCIONARIO';
 
alter table funcionario
drop constraint pk_funcionario;

create table departamento(
    id number primary key,
    nome varchar2(50)
);

alter table funcionario 
modify dept references departamento(id);

select *
  from user_constraints
 where table_name = 'FUNCIONARIO';
 
alter table funcionario
drop constraint SYS_C0023547400;

alter table funcionario 
add constraint fk_func_sal foreign key (dept) references departamento (id);

select *
  from user_constraints
 where table_name = 'FUNCIONARIO';
 
alter table funcionario
drop constraint fk_func_sal;

--Esse comando só funcionará se a tabela estiver vazia, ou todas as linhas da coluna possuir valor
alter table funcionario
modify salario not null;

select *
  from user_constraints
 where table_name = 'FUNCIONARIO';
 
select *
  from user_constraints
 where table_name = 'DEPARTAMENTO';
 
alter table departamento
drop primary key;

--Ao executar o drop primary key com o comando cascade, todas as foreign keys que fazem referencia também serão excluidas
alter table departamento
drop primary key cascade;

