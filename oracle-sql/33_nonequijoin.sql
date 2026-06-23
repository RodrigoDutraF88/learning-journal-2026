--Aula de nonequijoins

--Nessa aula iremos aprender sobre nonequijoins

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

select f.nome, f.salario, g.id, g.menor_salario, g.maior_salario
  from funcionario f, grade g
 where f.salario >= g.menor_salario
   and f.salario <= g.maior_salario; 
   
select f.nome, f.salario, g.id, g.menor_salario, g.maior_salario
  from funcionario f, grade g
 where f.salario between g.menor_salario and g.maior_salario; 
 
