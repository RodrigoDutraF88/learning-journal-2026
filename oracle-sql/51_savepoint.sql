--Aula de savepoint

--Ideal seria testar na plataforma correta mas aqui segue os exemplos

drop table funcionario;

create table funcionario(
    id number primary key,
    nome varchar2(40),
    salario number
);

insert into funcionario values (1, 'Karol', 1300);
insert into funcionario values (2, 'Ana', 2000);
insert into funcionario values (3, 'Bianca', 5000);
insert into funcionario values (4, 'Marcos', 2500);
insert into funcionario values (5, 'João', 630);
insert into funcionario values (6, 'Alan', null);
--Commit para finalizar essa transação
commit;

---------------------------------------------------------------------
--Iniciando uma nova transação
insert into funcionario values (7, 'TESTE', 2000);
commit;

--Iniciando uma nova transação
--1
update funcionario
   set salario = 1900
 where id = 7;
 
savepoint A;

--2
update funcionario
   set salario = 9000
 where id = 7;
 
savepoint B;

--3
update funcionario
   set salario = 1500
 where id = 7;

savepoint C;

--rollback voltará para o valor original 2000 e apagará os savepoints
rollback;
rollback to savepoint a; --gera erro

select *
  from funcionario
 where id = 7;
---------------------------------------------------------------------
--Iniciando uma nova transação
--1
update funcionario
   set salario = 1900
 where id = 7;
 
savepoint A;

--2
update funcionario
   set salario = 9000
 where id = 7;
 
savepoint B;

--3
update funcionario
   set salario = 1500
 where id = 7;

savepoint C;

select *
  from funcionario
 where id = 7;

--Retorna para o valor 1900 e exclui o savepoint B e C
rollback to savepoint a;

select *
  from funcionario
 where id = 7;
 
--É possível nesse momento executar o commit ou rollback;
commit;

select *
  from funcionario
 where id = 7;
---------------------------------------------------------------------
