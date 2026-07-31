--Aula de DECODE

--Nessa aula iremos aprender sobre DECODE

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
       decode(idade, 16, 'Menor'
                   , 10, 'Menor'
                   , 'Maior') teste
  from funcionario;
  
select nome, idade,
       decode(nome, 'Karol', 'Karol'
                   , 'Ana', 'Ana') teste
  from funcionario; --default não precisa ser utilizado, nesse caso alguns valores serão null

