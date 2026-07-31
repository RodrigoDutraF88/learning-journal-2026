--Aula de timestamp/timestamp with time zone

--Nessa aula iremos aprender sobre timestamp/timestamp with time zone

create table datas (
    data1 date,
    data2 timestamp,
    data3 timestamp with time zone
);

--sysdate retorna a data e hora corrente para o servidor
--current_timestamp retorna a data e hora corrente para o usuário da sessão (timestamp with time zone)
insert into datas values (sysdate, current_timestamp, current_timestamp);

select *
  from datas;
  
select to_char(data1, 'dd-mm-yyyy hh:mi:ss'), data2, data3
  from datas;

--Aula de funções de extração

--Nessa aula iremos aprender sobre funções de extração

select to_char(sysdate, 'yyyy') ano,
       to_char(sysdate, 'mm') mes,
       to_char(sysdate, 'dd') dia
  from dual;
  
select extract(year from sysdate) ano,
       extract(month from  sysdate) mes,
       extract(day from sysdate) dia
  from dual;
  
select extract(year from to_date('01/05/2018', 'dd/mm/yyyy')) ano,
       extract(month from  to_date('01/05/2018', 'dd/mm/yyyy')) mes,
       extract(day from to_date('01/05/2018', 'dd/mm/yyyy')) dia
  from dual;

--Aula de interval (year to month/day to second)

--Nessa aula iremos aprender sobre (year to month/day to second)

--ano pode ser uma valor positivo ou negativo
--mês 00-11
--dia pode ser um valor positivo ou negativo
--hora 00-23
--minuto 00-59
--segundo 00 to 59.9

select interval '55-11' year to month
  from dual;
  
select interval '1-4' year to month
  from dual;
  
select interval '555-11' year to month
  from dual; --se o ano for maior que 2 digitos, é necessário especificar o tamanho
  
select interval '555-11' year(3) to month
  from dual;
  
select interval '1000-11' year(4) to month
  from dual;
  
select interval '350' month
  from dual;
  
select interval '10' year
  from dual;
  
select interval '33 20:20:20' day to second
  from dual;
  
select interval '333 20:20:20' day(3) to second
  from dual;
  
select interval '500' hour
  from dual;