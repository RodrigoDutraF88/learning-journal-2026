--Aula de null com subquery

--Nessa aula iremos aprender sobre null com subquery

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

--Quando a subquery retorna null com o operador in não tem nenhum problema, mas não retorna o funcionario que tem idade null
--IN é igual a =any
select *
  from funcionario 
 where idade in (18, 16, null); 
 
select f.idade
  from funcionario f 
 where f.idade in (select f2.idade
                     from funcionario f2
                    where f2.dept = 2);

--Quando a subquery retorna algum valor nulo utilizando o operador not in, nenhum valor é retornado pela query principal
--NOT IN é igual a <>ALL
select *
  from funcionario 
 where idade not in (18, 16, null); 
 
select f.idade
  from funcionario f 
 where f.idade not in (select f2.idade
                         from funcionario f2
                        where f2.dept = 2);
                        
--Correlated subquery: utilizamos dados da main query dentro da subquery
select f.idade
  from funcionario f 
 where f.dept in ( select d.num_dept
                     from departamento d
                    where d.num_dept = f.dept
                      and d.num_dept = 5);
 
drop table pedido;

create table pedido(
    id number,
    cliente varchar2(50)
);

insert into pedido values (1, 'Ana');
insert into pedido values (2, 'José');
insert into pedido values (3, 'Bianca');
insert into pedido values (4, 'João');
insert into pedido values (5, 'Maria');

