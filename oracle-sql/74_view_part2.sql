--Aula de view

--Nessa aula iremos aprender sobre view

drop table funcionario;

create table funcionario(
    id number primary key,
    nome varchar2(40) not null,
    salario number, 
    dept number
);

insert into funcionario values (1, 'Karol', 400, 1);
insert into funcionario values (2, 'Andre', 1000, 1);
insert into funcionario values (3, 'Ana', 500, 2);

select rownum, nome
  from funcionario;
  
create view func
as
select dept, count(id) func_id, 
       min(salario) min_sal, max(salario) max_sal
  from funcionario
 group by dept;
 
create or replace view func
as
select dept, count(id) func_id, 
       min(salario) min_sal, max(salario) max_sal,
       avg(salario) media_sal
  from funcionario
 group by dept;
  
select *
  from func;
 
create table departamento(
    id number primary key,
    nome varchar2(50)
);

insert into departamento values (1, 'dept1');
insert into departamento values (2, 'dept2');

alter table funcionario add constraint fk_func_dept foreign key (dept) references departamento (id);

create view func2
as
select f.nome, nvl(d.nome, 'sem departamento') nom_dept
  from funcionario f left join departamento d
    on f.dept = d.id;

select * from func2;

