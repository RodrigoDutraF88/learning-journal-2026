--Aula de sequence

--Nessa aula iremos aprender sobre sequence

drop table funcionario;

create table funcionario(
    id number primary key,
    nome varchar2(40) not null,
    salario number
);

create sequence seq_id;

select *
  from user_sequences;
  
insert into funcionario values (seq_id.nextval, 'Karol', 1000);

insert into funcionario values (seq_id.nextval, 'Andre', 5000);

select *
  from funcionario;
  
select seq_id.currval
  from dual;

select seq_id.nextval
  from dual;

insert into funcionario values (seq_id.nextval, 'Maria', 20000);

select *
  from funcionario;