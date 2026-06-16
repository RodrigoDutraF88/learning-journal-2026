--Aula de operadores lógicos

drop table funcionario;

create table funcionario(
    id number primary key,
    nome varchar2(40),
    idade number
);

insert into funcionario values (1, 'Ana', 23);
insert into funcionario values (2, 'Ana', 25);
insert into funcionario values (3, 'Bianca', 46);
insert into funcionario values (4, 'Marcos', 33);
insert into funcionario values (5, null, null);

/*Após a execução desses scripts podemos iniciar as instruções de busca*/

--AND - ambas as expressões devem ser atendidas.
select nome, idade 
  from funcionario
 where nome like 'Ana' AND idade = 25; 
 
--OR - apenas uma das expressões devem ser atendidas.
select nome, idade 
  from funcionario
 where nome like 'Ana' OR idade = 25; 
 
--Precedencia: NOT, AND, OR
select nome, idade 
  from funcionario
 where nome like 'Ana' OR idade = 46 AND id = 3; 
 
--Para alterar a precedencia utilize parenteses
select nome, idade 
  from funcionario
 where nome like 'Ana' OR (idade = 46 AND id = 3); --mesmo resultado da busca anterior
 
select nome, idade 
  from funcionario
 where (nome like 'Ana' OR idade = 46) AND id = 3; 