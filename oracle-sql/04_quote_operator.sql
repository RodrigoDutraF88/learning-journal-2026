
--Aula de quote operator 

/*Nessa aula utilizaremos quote operator.
Para isso, execute o script abaixo*/

DROP TABLE produto;

create table produto(
    id number primary key,
    nome varchar2(40),
    validade_meses number
);

insert into produto values (1, 'Bala', 180);
insert into produto values (2, 'Banana', 5);
insert into produto values (3, 'Chá', 50);

/*Após a execução desses scripts podemos iniciar as instruções de busca*/

--quote operator nos permite inserir apostrofo em strings literais sem que ocorram erros internos no oracle
select 'It's important' from produto; --gera erro

--Para melhor apresentação da coluna, aconselhável utilizar um alias
select q'[It's important]' quote_operator from produto; 
select q'aIt's importanta' quote_operator from produto; 
select q'2It's important2' quote_operator from produto; 
select q'%It's important%' quote_operator from produto; 
select q"%It's important%" quote_operator from produto; --gera erro

