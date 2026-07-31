--Aula da tabela DUAL

--Nessa aula iremos aprender a utilizar a tabela dual

--DUAL: utilizada para fazer extrações onde não é necessário fazer extração de dados em tabelas
--Possui apenas uma coluna e uma linha chamada “dummy”
select *
  from dual;
  
select sysdate
  from dual;
  
select substr('teste dual', instr('teste dual', ' ')+1)
  from dual;
  
select round(months_between(sysdate, trunc(sysdate, 'year'))), trunc(sysdate, 'year')
  from dual;