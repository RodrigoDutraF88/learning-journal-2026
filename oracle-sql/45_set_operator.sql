--Aula de set operator


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

drop table cliente;

create table cliente(
    id_cliente number primary key,
    nom_cliente varchar2(50),
    idade number
);

insert into cliente values (1, 'Silmara', 44);
insert into cliente values (2, 'Samanta', 33);
insert into cliente values (3, 'Janaina', 18);
insert into cliente values (4, 'Sara', null);

--intersect - retorna a idade dos funcionarios que existem também na tabela cliente
--Intersect não ignora null
select f.idade
  from funcionario f
intersect
select c.idade
  from cliente c; 
 
--minus - retorna a idade dos funcionarios que não existem na tabela cliente
--minus não ignora null
select f.idade
  from funcionario f
minus
select c.idade
  from cliente c; 
  
--union - retorna a idade dos funcionarios e a dos clientes
--union não ignora null
--valores duplicados são excluidos e os valores são retornados em ordem crescente
select f.idade
  from funcionario f
union
select c.idade
  from cliente c; 
  
--union all - retorna a idade dos funcionarios e a dos clientes
--union all não ignora null
--valores duplicados não são excluidos e os valores são retornados sem ordem
select f.idade
  from funcionario f
union all
select c.idade
  from cliente c; 
  
--O número de colunas das queries envolvidas precisam ser as mesmas
select f.idade, f.nome
  from funcionario f
union all
select c.idade
  from cliente c; 
  
--Os tipos dos dados retornados precisam ser do mesmo GRUPO DE DADOS (como numérico ou caracter)
select f.nome
  from funcionario f
union all
select c.nom_cliente
  from cliente c; 
  
select f.nome
  from funcionario f
union all
select c.idade
  from cliente c; --gera erro
  
--O nome das colunas não precisam ser os mesmos entre as queries envolvidas
select f.nome nome_funcionario
  from funcionario f
minus
select c.nom_cliente
  from cliente c;
  
--A CLAUSULA ORDER BY DEVE SER INSERIDA NO FINAL DE TODAS AS QUERIES E SÓ PODERÃO SER USADOS OS NOMES DAS COLUNAS DA PRIMEIRA QUERY
select f.nome nome_funcionario, f.idade ida_func
  from funcionario f
union all
select c.nom_cliente, c.idade ida_cli
  from cliente c
order by nome_funcionario, ida_func;
  
select f.nome nome_funcionario, f.idade ida_func
  from funcionario f
union all
select c.nom_cliente, c.idade ida_cli
  from cliente c
order by nom_cliente, ida_cli; --gera erro

select f.nome nome_funcionario, f.idade ida_func
  from funcionario f
union all
select c.nom_cliente, c.idade ida_cli
  from cliente c
order by nome_funcionario, 2;

--Podemos mesclar vários set operadors na mesma cláusula
select f.idade ida_func
  from funcionario f
union all
select c.idade ida_cli
  from cliente c
 where idade > 18
minus 
select f.idade ida_func
  from funcionario f
 where idade < 10
order by 1;

