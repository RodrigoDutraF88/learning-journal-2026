--Aula de natural join

--Nessa aula iremos aprender sobre natural join

drop table funcionario;

create table funcionario(
    id number primary key,
    nome varchar2(40),
    idade number,
    dept number
);

insert into funcionario values (1, 'Karol', 23, 1);
insert into funcionario values (2, 'Ana', 18, 1);
insert into funcionario values (3, 'Bianca', 16, 1);
insert into funcionario values (4, 'Marcos', 10, 2);
insert into funcionario values (5, 'João', null, 2);
insert into funcionario values (6, 'Alan', 10, 2);

drop table departamento;

create table departamento(
    dept number primary key,
    nom_dept varchar2(50),
    num_func number
);

insert into departamento values (1, 'dept1', 12);
insert into departamento values (2, 'dept2', 455);
insert into departamento values (3, 'dept3', 67);
insert into departamento values (4, 'dept4', null);

--Sintaxe de equijoin (old join)
select f.nome, d.nom_dept
  from funcionario f, departamento d
 where f.dept = d.dept; 
 
--Sintaxe com natural join 
select f.nome, d.nom_dept
  from funcionario f natural join departamento d;
  
--Natural join é um tipo de equijoin
 
