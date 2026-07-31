--Aula de NVL, NVL2, NULLIF e COALESCE

drop table funcionario;

create table funcionario(
    id number primary key,
    nome varchar2(40),
    apelido varchar2(40)
);

insert into funcionario values (1, 'Karol', null);
insert into funcionario values (2, 'Ana', null);
insert into funcionario values (3, 'Bianca', 'Bi');
insert into funcionario values (4, 'Marcos', 'Marcão');

select nome, nvl(apelido, 'Não possui apelido')
  from funcionario;
  
select nome, nvl(id, 'Não possui id')
  from funcionario; --Erro, pois os argumentos não são do mesmo tipo
  
select nome, nvl(to_char(id), 'Não possui id')
  from funcionario;
  
select nome, nvl2(apelido, 'Possui apelido', 'Não possui apelido')
  from funcionario;
  
select nome, nvl2(id, id, 'Não possui id')
  from funcionario; --Erro, pois o segundo e terceiro argumento não são do mesmo tipo
  
select nome, nvl2(id, to_char(id), 'Não possui id')
  from funcionario;
  
select nome, nullif(nome, 'Ana')
  from funcionario;
  
select nome, nullif(id, 2)
  from funcionario;
  
select nome, nullif(id, 'teste')
  from funcionario; --Erro, pois os argumentos não são do mesmo tipo
  
select nome, nullif(null, 'teste')
  from funcionario; --Erro, pois não é possivel passar a literal null no primeiro argumento
  
select nome, coalesce(apelido, nome)
  from funcionario;

select nome, coalesce(apelido)
  from funcionario; --Erro, pois é necessário passar pelo menos dois argumentos
  
