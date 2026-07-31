--Aula de sinonimo

--Nessa aula iremos aprender sobre sinonimo

drop table funcionario;

create table funcionario(
    id number primary key,
    nome varchar2(40) not null,
    salario number
);

create synonym func
for funcionario;

select *
  from func;
  
insert into func values (1, 'Karol', 400);
 
select *
  from funcionario;
  
select *
  from user_synonyms;
  
drop synonym func;

create public synonym func for funcionario; --Erro, pois não temos privilegios suficientes