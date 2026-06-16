
--Aula de distinct


create table pessoa(
    id number primary key,
    nome varchar2(40),
    sobrenome varchar2(40)
);

insert into pessoa values (1, 'Maria', 'Silva');
insert into pessoa values (2, 'João', 'Silva');
insert into pessoa values (3, 'Maria', 'Santos');
insert into pessoa values (4, 'João', 'Silva');

/*Após a execução desses scripts podemos iniciar as instruções de busca*/

--Em algumas situações podemos obter resultados duplicados em uma busca
select sobrenome from pessoa; 

--Para remover essa duplicidade inserir o comando distinct
select distinct sobrenome from pessoa;

--Podemos utilizar também para mais de uma coluna
select nome, sobrenome from pessoa;
select distinct nome, sobrenome from pessoa;

--Observação importante: O distinct irá ser aplicado para todas as colunas e só pode ser usado no inicio do select 
select nome, distinct sobrenome from pessoa; --gera erro

