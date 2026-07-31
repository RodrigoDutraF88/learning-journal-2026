--Aula de outer join

--Nessa aula iremos aprender sobre outer join

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

--Utilizando equijoin os funcionarios Marcos e Alan não aparecem, pois possuem valor null no campo dept 
select f.nome, d.nom_dept
  from funcionario f, departamento d
 where f.dept = d.num_dept
 order by nome; 

--Utilizando outer join os funcionários aparecem, com o campo nom_dept como nulo
select f.nome, d.nom_dept
  from funcionario f, departamento d
 where f.dept = d.num_dept (+)
 order by nome;  
 
--Sintaxe left join
select f.nome, d.nom_dept
  from funcionario f left join departamento d
    on f.dept = d.num_dept 
 order by nome;  
 
--Se o símbolo (+) aparecer na tabela funcionário o resultado muda
select f.nome, d.nom_dept
  from funcionario f, departamento d
 where f.dept (+) = d.num_dept 
 order by nome; 
 
--Sintaxe right join
select f.nome, d.nom_dept
  from funcionario f right join departamento d
    on f.dept = d.num_dept 
 order by nome;  

--Não é possível inserir o símbolo nas duas tabelas
select f.nome, d.nom_dept
  from funcionario f, departamento d
 where f.dept (+) = d.num_dept (+)
 order by nome; 
 
--Sintaxe full outer join
select f.nome, d.nom_dept
  from funcionario f full outer join departamento d
    on f.dept = d.num_dept 
 order by nome;  
 
