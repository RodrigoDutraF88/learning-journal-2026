--Aula de to_char para números

select to_char(1234)
  from dual;
  
select to_char(1234, '9999')
  from dual;
  
select to_char(1234, '0000')
  from dual;
  
select to_char(1234, '9,999')
  from dual;
  
select to_char(1234, '$9,999')
  from dual;
  
select to_char(1234, '$9G999')
  from dual;
  
select to_char(1234.67, '99999.99')
  from dual;
 
select to_char(1234.67, '00000.00')
  from dual;
  
select to_char(1234.67, '9,999.99')
  from dual;
  
select to_char(1234.67, '9G999.99')
  from dual; --Gera erro, se utilizarmos o G, é necessário usar o D para decimal

select to_char(1234.67, '9G999D99')
  from dual;
  
select to_char(1234.67, '9999.9')
  from dual; --Valor é arredondado
  
 
select to_char(1234.67, '99.9')
  from dual; --Valor é aparece como #####

select to_char(-1234.67, '9999.9mi')
  from dual; 
  
select to_char(-1234.67, '9999.9PR')
  from dual; 
  

select to_char(14566, 'FM999,9999,999')
  from dual; 

select length(to_char(2, '9'))
  from dual; --Tamanho do número sempre considera o sinal
  
select length(to_char(-2, '9'))
  from dual;
  