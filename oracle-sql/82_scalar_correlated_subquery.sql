--Aula sobre scalar/correlated subquery

--Nessa aula iremos aprender sobre scalar/correlated subquery

drop table cidade;

create table cidade(
    id number primary key,
    nome varchar2(40) not null
);

insert into cidade values (1, 'Curitiba');
insert into cidade values (2, 'São Paulo');
insert into cidade values (3, 'Rio de Janeiro');
  
--scalar subquery: query que retorna exatamente uma coluna e uma linha
select c.nome, (select count(*) from cidade) qtd_cid
  from cidade c;
  
select c.nome
  from cidade c
 where c.id = (select max(id)
                 from cidade);
                 
--Correlated subquery: subquery que referencia uma coluna da query master
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

select *
  from departamento d
 where d.id_cidade = (select c.id
                        from cidade c
                       where c.id = d.id_cidade
                         and upper(c.nome) = upper('curitiba'));