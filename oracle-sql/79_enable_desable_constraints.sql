--Aula sobre habilitar/desabilitar constraints

--Nessa aula iremos aprender sobre habilitar/desabilitar constraints

drop table departamento;

create table departamento(
    id number primary key,
    nome varchar2(50)
);

drop table funcionario;

create table funcionario(
    id number primary key,
    nome varchar2(40),
    salario number, 
    dept number, 
    constraint fk_func_dept foreign key (dept) references departamento (id)
);

select *
  from user_constraints 
 where table_name in ('FUNCIONARIO', 'DEPARTAMENTO');
 
select *
  from user_indexes;
  
alter table funcionario
disable constraint SYS_C0023548381;

select *
  from user_constraints 
 where table_name in ('FUNCIONARIO', 'DEPARTAMENTO');
 
select *
  from user_indexes;
  
alter table funcionario
enable constraint SYS_C0023548381;

select *
  from user_constraints 
 where table_name in ('FUNCIONARIO', 'DEPARTAMENTO');
 
select *
  from user_indexes;
  
alter table departamento
disable constraint SYS_C0023548380; --Gera erro, pois existe uma referencia


alter table departamento
disable constraint SYS_C0023548380 cascade;

select *
  from user_constraints 
 where table_name in ('FUNCIONARIO', 'DEPARTAMENTO');
 
select *
  from user_indexes;
  