--Aula de produto cartesiano

--Nessa aula iremos aprender sobre produto cartesiano

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
    num_dept number primary key,
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


select f.nome, d.nom_dept
  from funcionario f, departamento d
 where f.dept = d.num_dept
 order by nome; 
 
select f.nome, d.nom_dept
  from funcionario f, departamento d
 where f.dept = d.num_dept
   and f.idade >= 18
 order by nome;  
 
select f.nome, d.nom_dept, e.logradouro||', '||e.numero endereco
  from funcionario f, departamento d, endereco e
 where f.dept = d.num_dept
   and d.num_dept = e.id_departamento;


