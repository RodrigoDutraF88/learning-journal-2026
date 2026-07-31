--Aula de to_yminterval/to_dsinterval

--Nessa aula iremos aprender sobre to_yminterval/to_dsinterval

select sysdate
  from dual;
  
select sysdate+10
  from dual;

--Se eu quero uma data após 1 ano e 2 meses da data atual
select sysdate + interval '01-02' year to month
  from dual;
  
select sysdate + to_yminterval('01-02')
  from dual;
  
--Se eu quero adicionar 6 dias e 2 horas a data atual
select sysdate + to_dsinterval('6 02:00:00')
  from dual;
  
select to_char(sysdate + to_dsinterval('6 02:00:00'), 'dd-mm-yyyy hh:mi:ss')
  from dual;

--Aula de tz_offset

--Nessa aula iremos aprender sobre tz_offset

select tz_offset('Asia/Dubai'), tz_offset('America/Chicago')
  from dual;
  
--from_tz
/*Função que retorna conversão de timestamp para 
timestamp with time zone de acordo com a timezone informada */
select from_tz(timestamp '2000-03-6 08:00:00', 'America/Chicago')
  from dual;