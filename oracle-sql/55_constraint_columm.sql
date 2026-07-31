--Aula de constraints nível de coluna


--Criando uma tabela
create table departamento (
    id number constraint pk_departamento primary key,
    nome varchar2(30)
);

create table funcionario(
    id number constraint pk_funcionario primary key,
    nome varchar2(30) constraint uk_nome_func unique,
    salario number not null,
    genero char constraint ck_gen_func check( genero in ('M', 'F')),
    id_dept number constraint fk_func_dept references departamento (id) 
);

--Tabela para visualizar todas as constraints criadas pelo usuário
select * 
  from user_constraints;
  
insert into departamento values (1, 'dept1');

--Gera erro devido ao check
insert into funcionario (id, nome, salario, genero, id_dept)
values (1, 'Karol', 1000, 'D', 1);

insert into funcionario (id, nome, salario, genero, id_dept)
values (1, 'Karol', 1000, null, 1);

select * 
  from funcionario;
  
--Gera erro devido a unique constraint
insert into funcionario (id, nome, salario, genero, id_dept)
values (2, 'Karol', 3000, 'F', 1);
