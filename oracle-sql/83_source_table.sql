--Aula sobre como utilizar subquery como uma source table

--Nessa aula iremos aprender sobre como utilizar subquery como uma source table

drop table cidade;

create table cidade(
    id number primary key,
    nome varchar2(40) not null
);
  
drop table departamento;

create table departamento(
    id number primary key,
    nome varchar2(40) not null, 
    id_cidade number,
    constraint fk_dept_cid foreign key (id_cidade) references cidade (id)
);
  
insert into cidade values (1, 'Curitiba');
insert into cidade values (2, 'São Paulo');
insert into cidade values (3, 'Rio de Janeiro');

insert into departamento values (1, 'dept1', 1);
insert into departamento values (2, 'dept2', 1);
insert into departamento values (3, 'dept3', 2);

select id, nome
  from cidade;
  
select id, nome, id_cidade
  from departamento;

--Para saber qual a cidade de cada departamento?
select dept.nome, cit.nome
  from departamento dept,
  (select id, nome from cidade) cit --Nomeamos essa subquery como inline view
 where dept.id_cidade = cit.id;
 
select dept.nome, cit.nome
  from departamento dept,
  (select id, nome from cidade where id < 5) cit --Nomeamos essa subquery como inline view
 where dept.id_cidade = cit.id;