--Aula de IS NULL

/*Nessa aula iremos aprender a utilizar o operador de comparação IS NULL. 
Novamente iremos utilizar a tabela funcionário de exemplo*/

drop table funcionario;

create table funcionario(
    id number primary key,
    nome varchar2(40),
    sobrenome varchar2(40)
);

insert into funcionario values (1, 'Ana', 'Souza');
insert into funcionario values (2, 'Felipe', 'Silva');
insert into funcionario values (3, 'Bianca', 'Paula');
insert into funcionario values (4, 'Marcos', null);
insert into funcionario values (5, null, 'Oliveira');

/*Após a execução desses scripts podemos iniciar as instruções de busca*/

--IS NULL é um operador para verificar se a expressão possui valor null ou não.
--Não é possível comparar null com o operador =
select nome, sobrenome 
  from funcionario
 where nome = null; --Não retorna nenhum valor
 
--Também é incorreto comparar valor null com espaço em branco
select nome, sobrenome 
  from funcionario
 where nome = ' '; --Não retorna nenhum valor
 
--maneira correta de realizar a busca por nomes com valor null é com IS NULL
select nome, sobrenome 
  from funcionario
 where nome is null;

--Para buscar casos em que a expressão não possui valor null, insira a expressão NOT
select nome, sobrenome 
  from funcionario
 where nome IS NOT NULL;


