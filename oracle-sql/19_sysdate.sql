 --Aula da funções de data (SYSDATE)

drop table funcionario;

create table funcionario(
    id number primary key,
    nome varchar2(40),
    data_admissao date
);

insert into funcionario values (1, 'Ana', sysdate);
insert into funcionario values (2, 'Ana', '01-jan-08');
insert into funcionario values (3, 'Bianca', '01-oct-59');
insert into funcionario values (4, 'Marcos', '01-feb-99');

/*Após a execução desses scripts podemos iniciar a utilização das funções*/

--SYSDATE: é uma função que retorna a data e horário atual do servidor da base de dados
select sysdate
  from funcionario; 
  
--somar e subtrair um número de uma data retorna uma data
select sysdate+3
  from funcionario; 
  
select sysdate-3
  from funcionario; 
  
--Diminuir duas datas para encontrar o número de dias entre elas  
select sysdate-data_admissao
  from funcionario; 

--Adicionar horas em uma data dividindo o número de horas por 24
select sysdate+5/24
  from funcionario; 
  
--Descobrir quantas semanas os funcionários estão trabalhando
select (sysdate-data_admissao)/7
  from funcionario; 
  
--Pratique o comando de SELECT com a tabela abaixo
drop table departamento;
