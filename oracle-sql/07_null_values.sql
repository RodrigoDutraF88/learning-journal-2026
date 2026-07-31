/* Valores nulos
NUll- vazio , nao atribuido, desconhecido
Diferente de zero ou espaço em branco
Expressões aritimeticas em null resultarão em valor null

*/

--Aula de valores nulos

/*Nessa aula trabalharemos com valores nulos.
Para isso, execute o script abaixo*/

drop table pessoa;

create table pessoa(
    id number primary key,
    nome varchar2(40),
    salario number
);

insert into pessoa values (1, 'Maria', 100);
insert into pessoa values (2, 'João', null);
insert into pessoa values (3, 'Joana', 0);

/*Após a execução desses scripts podemos iniciar as instruções de busca*/
--Funcionário João possui salário nullo, já a funcionária Joana possui salário 0
--Null é diferente de zero e espaço em branco
select *
  from pessoa;
  
--Expressões aritméticas com valor null terá como resultado o valor null
--Soma (+)
select salario, salario+100 from pessoa; 

--Subtração (-)
select salario, salario-100 from pessoa;

--Multiplicação (*)
select salario, salario*2 from pessoa;

--Divisão
select salario, salario/2 from pessoa; 