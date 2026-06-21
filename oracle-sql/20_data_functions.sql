--Aula da funções de data (MONTHS_BETWEEN, ADD_MONTHS, NEXT_DAY, LAST_DAY)


drop table funcionario;

create table funcionario(
    id number primary key,
    nome varchar2(40),
    data_nasc date
);

insert into funcionario values (1, 'Ana', sysdate);
insert into funcionario values (2, 'Ana', '01-jan-08');
insert into funcionario values (3, 'Bianca', '16-jun-16');
insert into funcionario values (4, 'Marcos', '23-nov-99');
insert into funcionario values (5, null, null);

/*Após a execução desses scripts podemos iniciar a utilização das funções*/

--MONTHS_BETWEEN: recebe duas datas e retorna a quantidade de meses entre elas (é errado utilizar a divisão por 30);
select months_between(sysdate, data_nasc)
  from funcionario;
  
select months_between(sysdate, data_nasc), (sysdate-data_nasc)/30
  from funcionario;

--Se a data maior foi inserida primeiro, o retorno será negativo
select months_between(data_nasc, sysdate)
  from funcionario;
  
--ADD_MONTHS: adicionar meses a uma data
select add_months(data_nasc, 1), data_nasc
  from funcionario; --Observe que a data 31-oct-19 quando é acrescentado um mês vira 30-nov-19
  
--NEXT_DAY: retornar a próxima data do dia da semana especificado
select next_day(data_nasc, 'friday'), data_nasc
  from funcionario;
  
select next_day(sysdate, 1), data_nasc
  from funcionario;
  
--LAST_DAY: recuperar a última data do mês
select last_day(data_nasc), data_nasc
  from funcionario; 
