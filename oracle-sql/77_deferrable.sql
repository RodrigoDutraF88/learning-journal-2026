--Aula sobre defferable constraints

--Nessa aula iremos aprender sobre defferable constraints

drop table funcionario;

create table funcionario(
    id number primary key,
    nome varchar2(40),
    salario number check (salario > 100),
    dept number
);

select *
  from user_constraints 
 where table_name in ('FUNCIONARIO');
 
insert into funcionario values (1, 'Karol', 50, 1);

alter table funcionario
drop constraint SYS_C0023550013;

alter table funcionario
modify salario check(salario>100) deferrable initially deferred;


alter table funcionario
add constraint dept check(dept>0) deferrable initially immediate;

select *
  from user_constraints 
 where table_name in ('FUNCIONARIO');
 
--Quando utilizamos deferrable initially deferred o erro só irá ser mostrado no momento do commit
insert into funcionario values (1, 'Karol', 50, 1);

--Quando utilizamos deferrable initially immediate o erro irá ser mostrado no momento do insert
insert into funcionario values (1, 'Karol', 150, -1);

set constraint SYS_C0023550139 immediate;

insert into funcionario values (1, 'Karol', 50, 1);

drop table funcionario;

create table funcionario(
    id number primary key,
    nome varchar2(40),
    salario number check (salario > 100),
    dept number
);

select *
  from user_constraints 
 where table_name in ('FUNCIONARIO');
 
--Comandos abaixo geram erro, pois a constraint não foi criada como defferable
set constraint SYS_C0023550272 immediate;

set constraint SYS_C0023550272 deferred;
