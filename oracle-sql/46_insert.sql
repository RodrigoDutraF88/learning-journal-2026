--Aula de insert

--Nessa aula iremos aprender sobre insert

drop table funcionario;

create table funcionario(
    id number primary key,
    nome varchar2(40) not null,
    salario number
);

--Posso inserir na tabela funcionarios sem indicar o nome dos campos,
--desde que eu insira valor para todos os campos e na ordem de criação da tabela
insert into funcionario values (1, 'Karol', 1300);
insert into funcionario values (2, 'Ana', null);
--Posso inserir apenas os valores obrigatórios, colocando o nome das colunas
--Os campos não inserido assumirão valor null
insert into funcionario(id, nome) values (3, 'Bianca');
--Não podemos omitir os valores que são obrigatórios
insert into funcionario (id) values (4);
--Podemos utilizar funções para inserir valores. Ex: to_char, to_date, sysdate
insert into funcionario values (5, Upper('João'), 630);

--Podemos fazer um insert com a instrução select, nesse caso podemos incluir mais de um registro na tabela com o mesmo comando.
create table funcionario2(
    id number primary key,
    nome varchar2(40) not null,
    salario number
);

insert into funcionario2
select *
  from funcionario;
  
select *
  from funcionario2;

delete from funcionario2;

insert into funcionario2 (id, nome)
select id, nome
  from funcionario;
  
--Erros comuns

--Inserir um valor que já existe na tabela e essa coluna ser chave primária
insert into funcionario2 (id, nome) values (1, 'Telmo');

--Inserir valor muito grande
insert into funcionario2 (id, nome) values (1, 'Juliano da Silva Rodrigues Santos Almeida Prado Junior');

--Inserir valor no tipo errado
insert into funcionario2 (id, nome) values (sysdate, 'Ana');

