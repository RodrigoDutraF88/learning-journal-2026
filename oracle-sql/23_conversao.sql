--Aula de Conversão

--Nessa aula iremos aprender sobre conversão implicita

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

--Quando incluimos um valor entre aspas é considerado um caracter, porém o Oracle converte para number, pois a coluna id é um number
select *
  from funcionario
 where id = '4';
 
--Oracle também faz a conversão implicita de caracter para data 
select *
  from funcionario
 where data_nasc = '01-jan-08'
  
--Neste caso o Oracle esta fazendo a conversão da data e numero para caracter
select concat(data_nasc, id)
  from funcionario;
  

