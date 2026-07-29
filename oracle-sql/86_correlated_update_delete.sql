--Aula sobre correlated update/delete

--Nessa aula iremos aprender sobre correlated update/delete

drop table cidade;

create table cidade(
    id number primary key,
    nome varchar2(40) not null
);

insert into cidade values (1, 'Curitiba');
insert into cidade values (2, 'São Paulo');
insert into cidade values (3, 'Rio de Janeiro');

drop table cidade2;

create table cidade2(
    id number primary key,
    nome varchar2(40) not null
);

insert into cidade2 values (1, 'Teste');
insert into cidade2 values (2, 'Porto');
insert into cidade2 values (3, 'Rio');
 
update cidade2 c
set nome = (select nome
             from cidade ci
            where ci.id = c.id);
            
select *
  from cidade2;
  
delete from cidade c
where exists (select 1 from cidade2 c2 where c.id = c2.id);