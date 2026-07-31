--Aula de delete 

--Nessa aula iremos aprender sobre delete

drop table funcionario;

create table funcionario(
    id number primary key,
    nome varchar2(40),
    idade number,
    dept number
);

insert into funcionario values (1, 'Karol', 23, 1);
insert into funcionario values (2, 'Ana', 18, 1);
insert into funcionario values (3, 'Bianca', 16, 1);
insert into funcionario values (4, 'Marcos', 10, null);
insert into funcionario values (5, 'João', null, 2);
insert into funcionario values (6, 'Alan', 10, null);

--Verificar o estado atual da tabela
select *
  from funcionario;
  
--Se não incluirmos a condição where, todas as linhas da tabela serão removidas
delete from funcionario;
delete funcionario; --palavra chave from é opcional

--Quando desejamos alterar apenas um registro, devemos utilizar a chave primária no where
delete from funcionario
 where id = 1;
 
--Podemos inserir qualquer condição no where
--dica: antes de executar o comando de delete, execute o mesmo where com o select para ter certeza de que está deletando apenas as linhas necessárias
select *
  from funcionario
 where idade > 20;
 
delete from funcionario
 where idade > 20;
 
--Podemos usar subquery no delete
delete funcionario
 where id in (select id
                from funcionario 
               where idade > 20);
 
--truncate: deleta todos os dados da tabela
truncate table funcionario;

