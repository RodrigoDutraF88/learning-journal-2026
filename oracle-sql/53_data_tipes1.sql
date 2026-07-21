--Aula de nomenclatura de tipos de dados


--Tabela para avaliar tipo de dados number
create table test(
    n1 number,
    n2 number(5,3)
);

insert into test values (1655.66, 1.34);

select *
  from test;
  
insert into test values (20.25, 23.347);

select *
  from test;
  
insert into test values (444.25, 23.2403666);


insert into test values (444.25, 23.2477666);

select *
  from test;
  
--gera erro
insert into test values (444.25, 500);

create table test2(
    n1 number(2, 2),
    n2 number(1,5)
);