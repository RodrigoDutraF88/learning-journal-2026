--Aula de sequence

--Nessa aula iremos aprender sobre sequence

drop table funcionario;

create table funcionario(
    id number primary key,
    nome varchar2(40) not null,
    salario number
);

drop sequence seq_id;

create sequence seq_id
start with 10
increment by 10;

select *
  from user_sequences;
  
insert into funcionario values (seq_id.nextval, 'Karol', 1000);

insert into funcionario values (seq_id.nextval, 'Andre', 5000);

select *
  from funcionario;
  
drop sequence seq_id;

create sequence seq_id
increment by -5;

insert into funcionario values (seq_id.nextval, 'Joao', 1000);

insert into funcionario values (seq_id.nextval, 'Beatriz', 5000);

select *
  from funcionario;
  
update funcionario
  set id = seq_id.nextval
 where id = 10;
 
select *
  from funcionario
 order by 1;
 
drop table funcionario;

create table funcionario(
    id number default seq_id.nextval primary key,
    nome varchar2(40) not null,
    salario number
);

insert into funcionario (nome, salario) values ('Ana', 5000);

select *
  from funcionario
 order by 1;
 
drop sequence seq_id;

create sequence seq_id;

drop table funcionario;

create table funcionario(
    id number default seq_id.nextval primary key,
    nome varchar2(40) not null,
    salario number,
    id_dept number
);

create sequence seq_dept;

insert into funcionario (nome, salario, id_dept) values ('Ana', 5000, seq_dept.nextval);
insert into funcionario (nome, salario, id_dept) values ('Joao', 5000, seq_dept.currval);
insert into funcionario (nome, salario, id_dept) values ('Maria', 5000, seq_dept.currval);
insert into funcionario (nome, salario, id_dept) values ('Beatriz', 5000, seq_dept.currval);

select *
  from funcionario
 order by 1;
 
alter sequence seq_dept
increment by 5;

select *
  from user_sequences
 where sequence_name = 'SEQ_DEPT';

alter sequence seq_dept
cache 10;

select *
  from user_sequences
 where sequence_name = 'SEQ_DEPT';

alter sequence seq_dept
maxvalue 10;

select *
  from user_sequences
 where sequence_name = 'SEQ_DEPT';
 
alter sequence seq_dept
start with 10; --Não podemos alterar o start with

create sequence seq2
start with 1
increment by 1
maxvalue 5
nocache
cycle;

select seq2.nextval from dual;
select seq2.nextval from dual;
select seq2.nextval from dual;
select seq2.nextval from dual;
select seq2.nextval from dual;
select seq2.nextval from dual;
select seq2.nextval from dual;