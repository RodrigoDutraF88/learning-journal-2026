--Aula de constraints nível de coluna


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
    salario number not null,
    genero char,
    id_dept number,
    constraint pk_funcionario primary key (id),
    constraint uk_nome_func unique (nome),
    constraint ck_gen_func check( genero in ('M', 'F')),
    constraint fk_func_dept foreign key (id_dept) references departamento (id)
);
