--Aula sobre with clause

--Nessa aula iremos aprender sobre with clause

drop table cidade;

create table cidade(
    id number primary key,
    nome varchar2(40) not null
);

insert into cidade values (1, 'Curitiba');
insert into cidade values (2, 'São Paulo');
insert into cidade values (3, 'Rio de Janeiro');
  
drop table departamento;

create table departamento(
    id number primary key,
    nome varchar2(40) not null, 
    id_cidade number,
    constraint fk_dept_cid foreign key (id_cidade) references cidade (id)
);

insert into departamento values (1, 'dept1', 1);
insert into departamento values (2, 'dept2', 1);
insert into departamento values (3, 'dept3', 2);

with cid
as 
(
    select nome
      from cidade
)
select *
  from cid;
  
with dept_count
as 
(
    select id, count(1) qtd_dept
      from departamento  
     group by id
)
select d.nome, dc.qtd_dept
  from departamento d, dept_count dc
 where d.id = dc.id;

