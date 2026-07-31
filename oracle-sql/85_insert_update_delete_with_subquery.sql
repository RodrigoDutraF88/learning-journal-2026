--Aula sobre insert/update/delete utilizando suquery

--Nessa aula iremos aprender sobre insert/update/delete utilizando suquery

drop table cidade;

create table cidade(
    id number primary key,
    nome varchar2(40) not null
);

insert into cidade values (1, 'Curitiba');
insert into cidade values (2, 'São Paulo');
insert into cidade values (3, 'Rio de Janeiro');
  
insert into
(
select id, nome
from cidade
where id = 1
)
values (20, 'Fortaleza');

select *
  from cidade;
  
insert into
(
select id, nome
from cidade
where nome like 'S%'
with check option
)
values (5, 'Porto Seguro');

update 
(
select id, nome
from cidade
where id = 20
)
set nome = 'Porto Seguro';

select *
  from cidade;
  
delete (select *
          from cidade
         where id = 20);
         
select *
  from cidade;
  
