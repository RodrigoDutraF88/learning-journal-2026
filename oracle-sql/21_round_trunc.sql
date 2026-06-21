--Aula da funções de data (ROUND, TRUNC)


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

--ROUND: arredondar data para o ano ou mês mais próximo
select round(data_nasc, 'month'), data_nasc
  from funcionario; --dia <= 15 arredonda para o mesmo mês
                    --dia >15 arredonda para o dia seguinte
                    
select round(data_nasc, 'year'), data_nasc
  from funcionario; --mês <= 6 arredonda para o mesmo ano
                    --mês >6 arredonda para o ano seguinte
  
--TRUNC: trunca a data para o ano e mês mais próximo
select trunc(data_nasc, 'month'), data_nasc
  from funcionario; 
                    
select trunc(data_nasc, 'year'), data_nasc
  from funcionario; 
 
