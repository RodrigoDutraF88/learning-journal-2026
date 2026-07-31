--Aula de merge

--Nessa aula iremos aprender sobre merge

drop table funcionario;

create table funcionario(
    id number primary key,
    nome varchar2(40) not null,
    salario number,
    genero char,
    created_date date default sysdate, 
    created_by varchar2(100) default user
);

drop table funcionario2;

create table funcionario2(
    id number primary key,
    nome varchar2(40) not null,
    salario number,
    genero char,
    created_date date default sysdate, 
    created_by varchar2(100) default user
);

insert into funcionario values (1, 'Ana', 500, 'F', sysdate, user);
insert into funcionario values (2, 'Maria', 1000, 'F', sysdate, user);
insert into funcionario values (3, 'João', 700, 'M', sysdate, user);

insert into funcionario2 values (1, 'Dirce', 200, 'F', sysdate, user);

merge into funcionario2 f2
using (select * from funcionario2) f
on (f.id = f2.id)
when matched then
update 
set f2.salario = f2.salario+200
when not matched then
insert values (f.id, f.nome, f.salario, f.genero, sysdate, user);

select *
  from funcionario2;
  

