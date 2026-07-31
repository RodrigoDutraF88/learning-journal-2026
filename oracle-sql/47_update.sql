--Aula de update 

--Nessa aula iremos aprender sobre update

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
  
--Se não incluirmos a condição where, todas as linhas da tabela serão alteradas
update funcionario
   set dept = 1;

--Quando desejamos alterar apenas um registro, devemos utilizar a chave primária no where
update funcionario
   set dept = 2
 where id = 1;
 
--Podemos inserir qualquer condição no where
--dica: antes de executar o comando de update, execute o mesmo where com o select para ter certeza de que está alterando apenas as linhas necessárias
select *
  from funcionario
 where idade > 20;
 
update funcionario
   set idade = 40
 where idade > 20;
 
--Podemos alterar mais de uma coluna por vez
update funcionario
   set idade =23,
       nome = 'teste'
 where id = 3;
 
--Podemos alterar um valor para null
update funcionario
   set idade = null
 where id = 3;
 
--Podemos usar subquery no update
update funcionario
   set idade = 90
 where id in (select id
                from funcionario 
               where idade > 20);
               
--Também podemos utilizar subquery no comando set
update funcionario
   set (idade, nome) = (select idade, nome
                          from funcionario
                         where id = 3)
 where id = 1;
 
update funcionario
   set idade = (select idade
                  from funcionario
                 where id = 4),
       nome = (select nome
                  from funcionario
                 where id = 4)
 where id = 1;
 
