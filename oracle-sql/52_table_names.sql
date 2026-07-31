--Aula de nomenclatura de tabelas



--Tabela deve iniciar com letra
create table 2func(
    id number
);

--Tamanho máximo de 30 caracteres (oracle 12c 12.1, no oracle 12c 12.2 o tamanho máximo é 128);
create table funcionario_e_informacao_rh_tabela_matriz(
    id number
);

--Conter apenas A-Z, a-z, 0-9, _, $ and #
create table emp-t(
    id number
);

--Não duplicar o nome de outro objeto que pertença ao mesmo usuário
create table emp(
    id number
);

create table emp(
    id number
);

--Não ser uma palavra reservada pelo Oracle (ex: select, update, from)
create table select(
    id number
);
