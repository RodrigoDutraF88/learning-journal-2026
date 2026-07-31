--Aula de create table


--Criando uma tabela (sem constraints)
create table FUNC_emp(
    id number,
    FName varchar2(200),
    salario number(8, 2),
    data_inicio date,
    comissao number(2, 2),
    foto blob,
    notas long --Mais indicado utilizar clob
);

select *
  from func_emp; --Nome não é case-sensitive
  
select *
  from funC_EMP;
  
--Create table utilizando aspas duplas ("")
create table "XX_func"(
    emp_id number,
    "Fname" varchar2(40)
);

--Utilizas as aspas duplas quando for buscar os dados da tabela
select *
  from "XX_func";
  
select "Fname"
  from "XX_func";
  
select fname
  from "XX_func"; --gera erro
  
--Default é utilizado para inserir valores defaults nas colunas
create table funcionario(
    id number,
    nome varchar2(50),
    data_inicio date default sysdate
);

insert into funcionario (id, nome)
values (1, 'Karol');

select * 
  from funcionario;
  
--Podemos visualizar as tabelas criadas através da tabela user_tables
select table_name
  from user_tables;
  
--tabela all_tables é possível ver todas as tabelas da base, a qual temos acesso
select *
  from all_tables
 where table_name = 'FUNCIONARIO';