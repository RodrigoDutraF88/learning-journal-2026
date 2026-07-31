--Aula de USER_TABLES/ALL_TABLES/USER_TAB_COLUMNS

--Nessa aula iremos aprender sobre USER_TABLES/ALL_TABLES/USER_TAB_COLUMNS

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
  from user_tables;
  
select *
  from all_tables;

select *
  from all_tables
 where table_name = 'FUNCIONARIO';
 
select *
  from TABS; --tabs é sinonimo de user_tables
  
select *
  from user_tab_columns;
  
select *
  from user_tab_columns
 where table_name = 'FUNCIONARIO';