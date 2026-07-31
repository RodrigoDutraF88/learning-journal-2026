--Aula de alter table - set unused

--Nessa aula iremos aprender sobre alter table - set unused

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
set unused (created_by);

select *
  from funcionario;
  
select *
  from user_unused_col_tabs;
  
update funcionario
   set created_by = 1;
   
alter table funcionario 
set unused (created_date) online;

select *
  from funcionario;
  
select *
  from user_unused_col_tabs;
  
update funcionario
   set created_date = 1;
   
alter table funcionario
drop unused columns;

select *
  from user_unused_col_tabs;