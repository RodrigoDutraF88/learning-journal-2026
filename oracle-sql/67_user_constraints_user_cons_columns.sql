--Aula de USER_CONSTRAINTS/USER_CONS_COLUMNS

--Nessa aula iremos aprender sobre USER_CONSTRAINTS/USER_CONS_COLUMNS

drop table funcionario;
drop table departamento;

create table departamento(
    id number primary key,
    nome varchar2(40)
);

create table funcionario(
    id number primary key,
    nome varchar2(40) not null,
    salario number,
    genero char,
    created_date date default sysdate, 
    created_by varchar2(100) default user,
    id_dept number,
    constraint fk_func_dept foreign key (id_dept) references departamento (id)
);

select *
  from user_constraints;
  
select *
  from user_constraints 
 where constraint_name = 'FK_FUNC_DEPT';
 
select *
  from user_cons_columns;
  
select *
  from user_constraints uc, user_cons_columns ucc
 where uc.constraint_name = ucc.constraint_name;

