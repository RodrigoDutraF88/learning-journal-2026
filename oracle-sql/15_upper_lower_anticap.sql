--Aula da funções de caracter(UPPER, LOWER, INITCAP)


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

--Função UPPER: converte todos os caracteres para letras maiúsculas
select upper(nome)
  from funcionario;
--Muito utilizada para comparar duas string
select nome
  from funcionario
 where upper(nome)='ANA';
 
--Função LOWER: converte todos os caracteres para letras minúsculas
select lower(nome)
  from funcionario;
  
--Função INITCAP: Primeira letra de cada palavra como maiúscula e as outras letras em minúscula
select initcap(nome)
  from funcionario;
  
select initcap('ESSE CURSO É SOBRE ORACLE DATABASE SQL')
  from funcionario;