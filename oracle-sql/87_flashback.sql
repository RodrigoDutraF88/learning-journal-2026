--Aula de flashback table

--Nessa aula iremos aprender sobre merge

select *
  from recyclebin;
  
drop table funcionario;

create table funcionario(
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

drop table funcionario;

select *
  from recyclebin;
  
flashback table funcionario to before drop;

select *
  from funcionario;
  
drop table funcionario;

purge recyclebin; --limpa a tabela de reciclagem

select *
  from recyclebin;
  
create table funcionario(
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

delete from funcionario;

select  versions_starttime, versions_endtime, nome
  from funcionario
versions between scn minvalue and maxvalue
where id = 1;

--Truncate não permite flashback



