
--Aula de expressões aritméticas

/*Nessa aula utilizaremos as expressões aritméticas (+,-,*,/).
Para isso, execute o script abaixo*/

drop table pessoa;

create table pessoa(
    id number primary key,
    nome varchar2(40),
    salario number
);

insert into pessoa values (1, 'Maria', 100);
insert into pessoa values (2, 'João', 305.05);
insert into pessoa values (3, 'Joana', 400);

/*Após a execução desses scripts podemos iniciar as instruções de busca*/

--Soma (+)
select salario, salario+100 from pessoa; 

--Subtração (-)
select salario, salario-100 from pessoa;

--Multiplicação (*)
select salario, salario*2 from pessoa;

--Divisão
select salario, salario/2 from pessoa; 

--Junção de expressões (Precendencia * e / antes de + e -)
select salario, 100+salario*2 from pessoa; 

--Junção de expressões para mudar precendencia utilize o parenteses
select salario, (100+salario)*2 from pessoa; 

--Pratique o comando de SELECT com a tabela abaixo


