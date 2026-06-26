--Aula de operadores exists e not existis

--Nessa aula iremos aprender sobre operadores exists e not existis

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
insert into funcionario values (4, 'Marcos', 10, null);
insert into funcionario values (5, 'João', null, 2);
insert into funcionario values (6, 'Alan', 10, null);
insert into funcionario values (7, 'Adan', 89, 2);

drop table departamento;

create table departamento(
    num_dept number primary key,
    nom_dept varchar2(50),
    num_func number
);

insert into departamento values (1, 'dept1', 12);
insert into departamento values (2, 'dept2', 455);
insert into departamento values (3, 'dept3', 67);
insert into departamento values (4, 'dept4', null);


--Quando uma subquery pode retornar muitos valores, aconselha-se utilizar os operadores exists e not exists
--Nesse caso estou retornando os departamentos que possuem algum funcionario
select *
  from departamento d
 where d.num_dept in (select f.dept
                        from funcionario f);
                
select *
  from departamento d
 where exists (select *
                 from funcionario f
                where f.dept = d.num_dept);
 
--Nesse caso estou retornando os departamentos que não possuem funcionario
select *
  from departamento d
 where not exists (select *
                 from funcionario f
                where f.dept = d.num_dept);
                
