--Aula de group by e having

--Nessa aula iremos aprender sobre group by e having

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

select max(idade), min(idade), dept
  from funcionario; --Erro: pois não encontra a função de grupo
  
select max(idade), min(idade), dept
  from funcionario
 group by dept;
 
select max(idade), min(idade), dept
  from funcionario
 group by dept
 order by min(idade); --Pode-se incluir funções de grupo no order by
 
select max(idade), min(idade), dept, nome
  from funcionario
 group by dept; --Erro: todas as colunas do select que não saõ funções de grupo devem estar no group by

select sum(idade) soma, dept
  from funcionario
 group by soma; --Erro: não é possível usar alias no group by
 
select sum(idade) soma, dept
  from funcionario
 where dept > 1
 group by dept;
 
select sum(idade) soma, dept
  from funcionario
 where sum(idade) > 10 
 group by dept; --Erro: funções de grupo não podem ser incluidas no where
 
select sum(idade) soma, dept
  from funcionario
 group by dept
having sum(idade) > 10 ; 


select sum(idade) soma, dept
  from funcionario
having sum(idade) > 10 
 group by dept ; 
 
select sum(max(idade))
  from funcionario
 group by dept; --Só é possível aninhar funções de grupo até o segundo nível
 
