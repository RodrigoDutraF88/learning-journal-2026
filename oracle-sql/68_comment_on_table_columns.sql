--Aula de COMMENT ON TABLE/COLUMN

--Nessa aula iremos aprender sobre COMMENT ON TABLE/COLUMN

drop table funcionario;

create table funcionario(
    id number primary key,
    nome varchar2(40) not null,
    salario number,
    genero char,
    created_date date default sysdate, 
    created_by varchar2(100) default user
);

comment on table funcionario 
is 'Está tabela possui dados de todos os funcionários da base de dados';

select *
  from user_tab_comments
 where table_name = 'FUNCIONARIO';
 
comment on column funcionario.nome
is 'Está coluna possui o nome dos funcionários';
  
select *
  from user_col_comments
 where table_name = 'FUNCIONARIO';