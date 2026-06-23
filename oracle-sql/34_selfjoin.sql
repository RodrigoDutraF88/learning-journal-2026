--Aula de outer join

--Nessa aula iremos aprender sobre outer join

drop table funcionario;

create table funcionario(
    id number primary key,
    nome varchar2(40),
    idade number,
    gerente number
);

insert into funcionario values (1, 'Karol', 23, null);
insert into funcionario values (2, 'Ana', 18, 1);
insert into funcionario values (3, 'Bianca', 16, 1);
insert into funcionario values (4, 'Marcos', 10, null);
insert into funcionario values (5, 'João', null, 4);
insert into funcionario values (6, 'Alan', 10, 4);

select f.nome nome_funcionario, g.nome nome_gerente
  from funcionario f, funcionario g
 where f.gerente = g.id;
 
--Utilizando outer join com self join
select f.nome nome_funcionario, g.nome nome_gerente
  from funcionario f, funcionario g
 where f.gerente  = g.id (+);
 
