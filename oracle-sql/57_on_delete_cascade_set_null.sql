--Aula de on delete cascade/on delete set null

--Criando uma tabela
drop table funcionario;
drop table departamento;

create table departamento (
    id number constraint pk_departamento primary key,
    nome varchar2(30)
);

create table funcionario(
    id number,
    nome varchar2(30),
    id_dept,
    constraint fk_func_dept foreign key (id_dept) references departamento (id)
);

insert into departamento values (1, 'dept1');

insert into funcionario values (1, 'Karol', 1);

--não consigo deletar a linha 1 da tabela departamento, pois possui referencia com a tabela funcionario
delete departamento where id = 1;

--Opções de exclusão:
--excluir primeiro da tabela funcionario para depois excluir da tabela departamento
delete funcionario where id_dept = 1;
delete departamento where id = 1;

--ON DELETE CASCADE: quando deletar a primary key/unique key, irá deletar os registros da foreign key;
drop table funcionario;
drop table departamento;

create table departamento (
    id number constraint pk_departamento primary key,
    nome varchar2(30)
);

create table funcionario(
    id number,
    nome varchar2(30),
    id_dept,
    constraint fk_func_dept foreign key (id_dept) references departamento (id) on delete cascade
);

insert into departamento values (1, 'dept1');

insert into funcionario values (1, 'Karol', 1);

--No momento de excluir da tabela departamento, as linhas que possuem referencia serão também excluidas
delete from departamento where id = 1;

select *
  from funcionario;
  
--ON DELETE SET NULL: quando deletar a primary key/unique key, irá inserir null nos registros da foreign key
drop table funcionario;
drop table departamento;

create table departamento (
    id number constraint pk_departamento primary key,
    nome varchar2(30)
);

create table funcionario(
    id number,
    nome varchar2(30),
    id_dept,
    constraint fk_func_dept foreign key (id_dept) references departamento (id) on delete set null
);

insert into departamento values (1, 'dept1');

insert into funcionario values (1, 'Karol', 1);

--No momento de excluir da tabela departamento, as linhas que possuem referencia terão valor null na foreign key
delete from departamento where id = 1;

select *
  from funcionario;
  
