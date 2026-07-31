--Aula de to_char para datas

--Nessa aula iremos aprender sobre to_char para datas

drop table funcionario;

create table funcionario(
    id number primary key,
    nome varchar2(40),
    data_nasc date
);

insert into funcionario values (1, 'Ana', sysdate);
insert into funcionario values (2, 'Ana', '01-jan-08');
insert into funcionario values (3, 'Bianca', '16-jun-16');
insert into funcionario values (4, 'Marcos', '23-nov-99');
insert into funcionario values (5, null, null);

select to_char(sysdate, 'dd/mm/rrrr')
  from dual;
  

select to_char(sysdate, 'dd/mm/rrrr hh:mi:ss AM') 
  from dual; --AM e PM tem a mesma função
 
select to_char(sysdate, 'dd/mm/rrrr hh24:mi:ss') 
  from dual; 
  
select to_char(sysdate, 'dd Month rrrr hh24:mi:ss'), to_char(sysdate, 'fmdd Month rrrr hh24:mi:ss')
  from dual; 
  
select to_char(sysdate, 'dd "of" month rrrr hh24:mi:ss'), to_char(sysdate, 'fmddsp Month rrrr hh24:mi:ss')
     , to_char(sysdate, 'fmddth Month rrrr hh24:mi:ss') , to_char(sysdate, 'fmddspth Month rrrr hh24:mi:ss')
  from dual; 
  
select *
  from funcionario
 where to_char(data_nasc, 'rrrr') = '2019';
 
select *
  from funcionario
 where to_char(data_nasc, 'mm') = '01';
 
select *
  from funcionario
 where to_char(data_nasc, 'fmmm') = '1';

--Pratique o comando de SELECT com a tabela abaixo
drop table departamento;

create table departamento(
    num_dept number primary key,
    nom_dept varchar2(50),
    dat_abert date
);

insert into departamento values (1, 'dept1', '01-jul-16');
insert into departamento values (2, 'dept2', '12-apr-10');
insert into departamento values (3, 'dept3', '16-aug-89');
insert into departamento values (4, 'dept4', sysdate);