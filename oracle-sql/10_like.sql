--Aula de LIKE

drop table funcionario;

create table funcionario(
    id number primary key,
    nome varchar2(40),
    sobrenome varchar2(40)
);

insert into funcionario values (1, 'Ana', 'Souza');
insert into funcionario values (2, 'Felipe', 'Silva');
insert into funcionario values (3, 'Bianca', 'Paula');
insert into funcionario values (4, 'Marcos', 'Lima');
insert into funcionario values (5, 'Julio', 'Oliveira');

/*Após a execução desses scripts podemos iniciar as instruções de busca*/

--Like é um operador de comparação de cadeia de caracter (string)
--Podemos comparar uma string da seguinte forma:
select nome, sobrenome 
  from funcionario
 where nome = 'Julio';
 
--Mas também podemos comparar com a instrução LIKE. 
select nome, sobrenome 
  from funcionario
 where nome LIKE ('Julio');

--A diferença é que o LIKE possui a possibilidade do uso de dois caracteres especiais (% e _).
--% simboliza que a string deve conter zero ou mais caracteres.
--No exemplo abaixo o sobrenome deve iniciar com a letra S e ter zero ou mais caracteres depois.
select nome, sobrenome 
  from funcionario
 where sobrenome LIKE ('S%');
 
--O % também pode ser inserido no início da literal.
--No exemplo abaixo o sobrenome deve finalizar com a letra a, não importando quantas letras tenha antes
select nome, sobrenome 
  from funcionario
 where sobrenome LIKE ('%a');
 
--O % também pode ser inserido em qualquer posição da palavra.
--No exemplo abaixo o sobrenome deve contar a letra a em qualquer posição.
select nome, sobrenome 
  from funcionario
 where sobrenome LIKE ('%a%');

--No exemplo abaixo o sobrenome deve contar a letra a em qualquer posição e após isso a letra l.
select nome, sobrenome 
  from funcionario
 where sobrenome LIKE ('%a%l%');
 
--O segundo caracter especial é o _, nesse caso ele especifica a quantidade de letras que deve existir em determinada posição
--Nesse exemplo o sobrenome deve iniciar com Sil e possuir exatamente dois caracteres após a string.
select nome, sobrenome 
  from funcionario
 where sobrenome LIKE ('Sil__');
 
--Nesse exemplo o sobrenome deve terminar com va e possuir exatamente três caracteres antes da string.
select nome, sobrenome 
  from funcionario
 where sobrenome LIKE ('___va');
 
--Nesse exemplo o sobrenome deve iniciar com S e ter pelo menos um caracter depois disso.
select nome, sobrenome 
  from funcionario
 where sobrenome LIKE ('S_%');
 
--A clausula escape nos permite interpretar os caracteres especiais como caracter simples
--Nesse exemplo colocamos como escape a \, inserindo essa \ na string o caracter após ela não terá função especial
select nome, sobrenome 
  from funcionario
 where nome LIKE ('An\_') escape '\'; --Não retorna nada, pois não existe nenhum sobrenome na base com _
 