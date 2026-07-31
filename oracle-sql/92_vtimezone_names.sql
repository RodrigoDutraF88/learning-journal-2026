--Aula de v$timezone_names

--Nessa aula iremos aprender sobre v$timezone_names

--Todos os nomes de time zonas estão na seguinte tabela
select *
  from v$timezone_names;
--LMT - Local Mean Time
--CST - Central Standard Time
--CDT - Central Daylight Time
--EST - Eastern Standard Time
--CWT - Central West Time

--DBTIMEZONE mostra a time zone da database, ela é definida na criação da database
select DBTIMEZONE from dual;

--SESSIONTIMEZONE mostra a time zone da sessão
select SESSIONTIMEZONE from dual;

select to_char(current_date, 'dd-mm-yyyy hh:mi:ss'), to_char(sysdate, 'dd-mm-yyyy hh:mi:ss')
  from dual;
  
--Retorna a data e hora corrente para o usuário da sessão
select localtimestamp from dual;
