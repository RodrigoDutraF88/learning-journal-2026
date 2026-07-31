--Aula de on clause

--Nessa aula iremos aprender sobre on clause

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

create table endereco(
    id_end number primary key,
    logradouro varchar2(50),
    numero number,
    complemento varchar2(20),
    bairro varchar2(30),
    cidade varchar2(50),
    estado varchar2(2),
    cep number,
    id_departamento number
);

insert into endereco (id_end, logradouro, numero, complemento, bairro, cidade, estado, cep, id_departamento)
values (1, 'Rua São Caetano', 256, null, 'São Caetano', 'São Paulo', 'SP', 81130020, 1);
insert into endereco (id_end, logradouro, numero, complemento, bairro, cidade, estado, cep, id_departamento)
values (2, 'Rua Joaquim', 120, null, 'Centro', 'Curitiba', 'PR', 12563982, 2);
insert into endereco (id_end, logradouro, numero, complemento, bairro, cidade, estado, cep, id_departamento)
values (3, 'Rua José Bettega', 478, 'Sob 10', 'Centro', 'Curitiba', 'PR', 02356984, 3);
insert into endereco (id_end, logradouro, numero, complemento, bairro, cidade, estado, cep, id_departamento)
values (4, 'Rua Manoel Ribas', 50, null, 'Batel', 'Curitiba', 'PR', 85639245, 4);

--Sintaxe de equijoin (old join)
select f.nome, d.nom_dept
  from funcionario f, departamento d
 where f.dept = d.dept; 
 
--Sintaxe com natural join 
select f.nome, d.nom_dept
  from funcionario f natural join departamento d;
  
--Sintaxe com using clause
select f.nome, d.nom_dept
  from funcionario f join departamento d
 using (dept);
 
--Sintaxe com on clause
select f.nome, d.nom_dept
  from funcionario f join departamento d
    on f.dept = d.dept;

--O join pode ser visto também como inner join (mais comum)
select f.nome, d.nom_dept
  from funcionario f inner join departamento d
    on f.dept = d.dept;
    
--Nesta sintaxe o where fica exclusivo para condições extras, que não envolvem a junção de tabelas
select f.nome, d.nom_dept
  from funcionario f inner join departamento d
    on f.dept = d.dept
 where f.idade > 15;
 
--Para realizar a junção de mais de duas tabelas com a sintaxe on clause
select f.nome, d.nom_dept, e.logradouro
  from funcionario f inner join departamento d
    on f.dept = d.dept
 inner join endereco e
    on d.dept = e.id_departamento
 where f.idade > 15;
  
--inner join ou join pode ser um tipo de equijoin ou nonequijoin
drop table funcionario;

create table funcionario(
    id number primary key,
    nome varchar2(40),
    salario number
);

insert into funcionario values (1, 'Karol', 1800);
insert into funcionario values (2, 'Ana', 5000);
insert into funcionario values (3, 'Bianca', 3400);
insert into funcionario values (4, 'Marcos', 6000);
insert into funcionario values (5, 'João', 2300);
insert into funcionario values (6, 'Alan', 1600);

drop table grade;

create table grade(
    id number,
    menor_salario number,
    maior_salario number
);

insert into grade values (1, 1500, 2000);
insert into grade values (2, 2001, 3000);
insert into grade values (3, 3001, 4000);
insert into grade values (4, 4001, 5000);

--Sintaxe nonequijoin (old join)
select f.nome, f.salario, g.id, g.menor_salario, g.maior_salario
  from funcionario f, grade g
 where f.salario between g.menor_salario and g.maior_salario; 
 
--Sintaxe com on clause
select f.nome, f.salario, g.id, g.menor_salario, g.maior_salario
  from funcionario f inner join grade g
    on f.salario between g.menor_salario and g.maior_salario; 

