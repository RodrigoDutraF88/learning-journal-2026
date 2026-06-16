-- Utilizando Alias
/* apelido para coluna ou para tabela
altera cabeçalho da coluna
AS: opcional
Alias sem aspas: não é case sensitive
Não é possivel ter duas tabelas com o mesmo alias
ALias com aspas duplas: é case sensitive
*/

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


-- comando as é opcional, os dois selects abaixo retornam o mesmo resultado
select nome as nome_employees from employees; --dando apelido para coluna nome
select nome nome_employees from employees;

--alias sem aspas
select nome 2 from employees; --gera erro
select nome NOME_Employees from employees;
select nome nome employee from employees; --gera erro , espaço

--alias com aspas duplas
select nome "NOME_Employees" from employees;
select nome "nome funcionario" from employees;

--Alias pode também ser usado como apelido de tabela
select f.nome FROM employees f;
select f.nome FROM employees f, employees c;
select f.nome FROM employees f, employees f; --gera erro nao é possível colocar o mesmo alias em 2 tabelas da clausula from
select nome FROM employees f, employees c; --gera erro slq não saberá diferenciar de qual tabela deve retornar a coluna nome

select nome
    from employees f
    where f.nome = 'Ana';


select nome nom
    from employees
    where nom = 'Ana'; --gera erro, a parte do select é a ultima a ser executada






