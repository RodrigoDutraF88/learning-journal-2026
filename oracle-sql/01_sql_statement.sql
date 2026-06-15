-- Aula de SQL statement
/* Os comentários tem dois tipo,
o barra asterisco pode comentar mais de 1 linha */

create table employees(
    id number PRIMARY key,
    nome varchar2(40),
    idade number
);

insert into employees values (1, 'Ana', 22);
insert into employees values (2, 'Felipe', 55);
insert into employees values (3, 'Bianca', 2);
insert into employees values (4, 'Marcos', 10);
insert into employees values (5, 'Julio', 10);

select * from employees;
-- ira retornar todas as colunAS DA Tabela

select nome from employees;
--filtra por nome

select idade FROM employees;
-- comando select nao é case-sensitive

-- a clausula where ira limitar a busca
select *
from employees
where idade > 20;

create table departments(
    num_dept number PRIMARY KEY,
    nom_dept VARCHAR2(50),
    qtd_func NUMBER
);

insert into departments values (1,'dept1', 2);
insert into departments values (2,'dept2', 50);
insert into departments values (3,'dept3', 25);
insert into departments values (4,'dept4', 150);
insert into departments values (5,'dept5', 33);

