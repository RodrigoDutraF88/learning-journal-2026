--Aula sobre global temporary table 

--Nessa aula iremos aprender sobre global temporary table 

--São tabelas onde os dados ficam disponíveis somente durante a sessão. 
--Cada sessão pode ver e modificar apenas os seus dados

drop table funcionario;

create global temporary table funcionario(
    id number primary key,
    nome varchar2(40),
    salario number,
    dept number
) on commit delete rows;
 
insert into funcionario values (1, 'Karol', 50, 1);
insert into funcionario values (2, 'Andre', 50, 1);


select *
  from funcionario;
  
commit;

select *
  from funcionario;

drop table funcionario;

create global temporary table funcionario(
    id number primary key,
    nome varchar2(40),
    salario number,
    dept number
) on commit preserve rows;

insert into funcionario values (1, 'Karol', 50, 1);
insert into funcionario values (2, 'Andre', 50, 1);


select *
  from funcionario;
  
commit;

select *
  from funcionario;