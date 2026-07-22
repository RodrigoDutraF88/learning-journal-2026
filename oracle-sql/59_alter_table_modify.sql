--Aula de alter table - modify

--Nessa aula iremos aprender sobre alter table - modify

drop table funcionario;

create table funcionario(
    id number primary key,
    nome varchar2(40) not null,
    salario number,
    genero char,
    created_date date default sysdate, 
    created_by varchar2(100) default user
);
  
insert into funcionario (id, nome, salario)
values (1, 'Karol', 100);

select *
  from funcionario;

alter table funcionario
modify (created_by varchar2(20));

alter table funcionario
modify (created_by varchar2(500));

--Erro, pois a coluna possui valor maior do que 1
alter table funcionario
modify (created_by varchar2(1));

select *
  from funcionario;
  
alter table funcionario
modify (created_by not null);

--Erro, pois a coluna possui um registro com valor null
alter table funcionario
modify (genero not null);

update funcionario
   set genero = 'M';
   
select *
  from funcionario;
  
--Erro, pois a coluna possui um registro em formato caracter
alter table funcionario
modify (genero number);

alter table funcionario
modify (genero varchar2(11));

alter table funcionario
modify (genero char(10));

--Erro, pois não podemos diminuir o tamanho da coluna ao mudar o tipo de char para varchar2 (varchar2 é variavel e char é fixo)
alter table funcionario
modify (genero varchar2(9));

alter table funcionario
modify (genero varchar2(10));

update funcionario 
   set genero = null;
   
select *
  from funcionario;
  
alter table funcionario
modify (genero char(1));

alter table funcionario
modify (genero varchar2(10));
