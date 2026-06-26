--Aula de Single row subquery

--Nessa aula iremos aprender sobre Single row subquery

drop table funcionario;

create table funcionario(
    id number primary key,
    nome varchar2(40),
    salario number
);

insert into funcionario values (1, 'Karol', 1300);
insert into funcionario values (2, 'Ana', 2000);
insert into funcionario values (3, 'Bianca', 5000);
insert into funcionario values (4, 'Marcos', 2500);
insert into funcionario values (5, 'João', 630);
insert into funcionario values (6, 'Alan', null);

--Para buscar a média dos salários
select avg(salario)
  from funcionario;
  
--Para buscar os salários maiores que a média
select *
  from funcionario
 where salario > 2286;

--Usando subquery
select *
  from funcionario 
 where salario > (select avg(salario)
  from funcionario);

--Funcionario com o maior salário
select *
  from funcionario 
 where salario = (select max(salario)
  from funcionario);
  
--Single row subquerie são subquerys que retornam apenas uma linha 
--Para Single row subquerys podemos utilizar os operadores >, <. >=, <=, <>, =

--Esses operadores não podem ser utilizados quando a subquery retornar mais de uma linha
select *
  from funcionario 
 where salario = (select salario
  from funcionario
 where salario > 1000);
 
--Podemos utilizar subquerys também na clausula having
select length(nome), max(salario)
  from funcionario
 group by length(nome)
having max(salario) = (select max(salario)
                         from funcionario);
                
--Se a subquery não retornar nenhuma linha, então toda a query retornará vazia
select *
  from funcionario 
 where salario = (select max(salario)
                    from funcionario
                   where salario > 10000);
                
--Importante: lembre-se sempre que a subquery será executada antes da query principal

--Single row subquery pode retornar mais de uma coluna
select *
  from funcionario 
 where (salario, nome)  = (select max(salario), nome
                                from funcionario
                               where length(nome) = 3
                               group by nome);
  
