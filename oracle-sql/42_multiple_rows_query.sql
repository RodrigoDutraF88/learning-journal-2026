--Aula de multiple row subquery

--Nessa aula iremos aprender sobre multiple row subquery

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

--Para buscar os salários maiores que 2000
select salario
  from funcionario
 where salario > 2000;
  
--Para buscar os salários maiores que a média
select *
  from funcionario
 where salario IN (select salario
                     from funcionario
                    where salario > 2000);

-- Usando operador any
-- =ANY é equivalente ao IN
select *
  from funcionario
 where salario = any (select salario
                        from funcionario
                       where salario > 2000);
                       
--Usando operador all
-- =ALL irá retornar nulo
select *
  from funcionario
 where salario = all (select salario
                        from funcionario
                       where salario > 2000);

-- > ALL significa mais que o máximo valor
select *
  from funcionario
 where salario > all (select salario
                        from funcionario
                       where salario < 2000);
                     
-- < ALL significa menos que o mínimo valor;
select *
  from funcionario
 where salario < all (select salario
                        from funcionario
                       where salario > 2000);

