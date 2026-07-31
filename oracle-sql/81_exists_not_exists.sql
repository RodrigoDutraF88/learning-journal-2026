--Aula sobre exists/not exists

--Nessa aula iremos aprender sobre exists/not exists

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

--Mostrar todas as cidades que possuem departamento
select *
  from cidade c
 where exists (select 1 from departamento d where d.id_cidade = c.id);
 
select *
  from cidade 
 where id in (select id_cidade
                from departamento);

--Mostrar todas as cidades que não possuem departamento
select *
  from cidade c
 where not exists (select 1 from departamento d where d.id_cidade = c.id);
 
select *
  from cidade 
 where id not in (select id_cidade
                from departamento);