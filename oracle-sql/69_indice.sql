--Aula de indice

--Nessa aula iremos aprender sobre indice

drop table funcionario;

create table funcionario(
    id number primary key,
    nome varchar2(40) not null unique,
    salario number
);

insert into funcionario values (1, 'Karol', 400);
insert into funcionario values (1, 'Ana', 5000);
 
select *
  from user_indexes;
  
select *
  from user_ind_columns;
  
select *
  from funcionario
 where id = 1; --Oacle utiliza o indice para acelerar o acesso aos dados
 
--Oracle optimizer

create index idx_func_sal on funcionario (salario);

drop table funcionario;

create table funcionario(
    id number primary key,
    nome varchar2(40) not null,
    salario number
);
 
select *
  from user_indexes;
  
select *
  from user_ind_columns;
  
create unique index idx_func_nome on funcionario (nome);

create index idx_func_nome2 on funcionario (upper(nome));

select *
  from user_indexes;
  
select *
  from user_ind_expressions;
  
drop table funcionario;

create table funcionario(
    id number primary key using index (create index idx_func_id on funcionario (id)),
    nome varchar2(40) not null,
    salario number
);

select *
  from user_indexes;
  
create index idx_funcionario on funcionario (id, nome);

select *
  from user_indexes;
  
select *
  from user_ind_columns;
  
drop index idx_funcionario;