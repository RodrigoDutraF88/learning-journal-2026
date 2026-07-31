--Aula de CASE



drop table funcionario;

create table funcionario(
    id number primary key,
    nome varchar2(40),
    idade number
);

insert into funcionario values (1, 'Karol', 23);
insert into funcionario values (2, 'Ana', 18);
insert into funcionario values (3, 'Bianca', 16);
insert into funcionario values (4, 'Marcos', 10);
insert into funcionario values (5, 'João', null);

select nome, idade,
       case idade when 16 then 'Menor'
                  when 10 then 'Menor'
       else 'Maior'
       end teste
  from funcionario;
  
--Caso algum valor atenda a duas das condições, só irá retornar o valor da primeira.
select nome, idade, 
       case when idade < 16 then 'Criança'
            when idade < 18 then 'Jovem'
       else 'Adulto'
       end teste
  from funcionario; --Valor null cairá no else
  
  
