--Aula da funções de caracter (LPAD, RPAD, REPLACE, TRIM)


drop table funcionario;

create table funcionario(
    id number primary key,
    nome varchar2(40),
    sobrenome varchar2(40)
);

insert into funcionario values (1, 'Ana', 'Souza');
insert into funcionario values (2, 'Ana', 'Silva');
insert into funcionario values (3, 'Bianca', 'Oliveira');
insert into funcionario values (4, 'Marcos', 'Andrade');
insert into funcionario values (5, null, null);

/*Após a execução desses scripts podemos iniciar a utilização das funções*/

--LPAD: retorna uma expressão, preenchida com um caracter especificado à esquerda
--Primeiro argumento é a string principal
--Segundo argumento é o tamanho máximo da minha string
select lpad(sobrenome, 3), sobrenome
  from funcionario; 
  
select lpad(sobrenome, 10), sobrenome
  from funcionario; 

--Terceiro argumento é um caracter para preenhcer a string à esquerda (opcional, o default é um ' ')
select lpad(sobrenome, 10, '*'), sobrenome
  from funcionario; 

--RPAD: mesma função do LPAD, porém a string é preenchida à direita.
select rpad(sobrenome, 10, '*'), sobrenome
  from funcionario;   
  
--REPLACE: substitui buscas em expressões por caracteres
--O primeiro argumento é a string em que quero procurar
--O segundo argumento é a expressão que quero procurar dentro do primeiro argumento
select replace(sobrenome, 'a'), sobrenome
  from funcionario; 
  
--O terceiro argumento é o caracter que quero colocar no lugar do segundo argumento (opcional, default é '');
select replace(sobrenome, 'a', 'b'), sobrenome
  from funcionario;    
  
select replace(sobrenome, 'a', 'be'), sobrenome
  from funcionario;    
  
--TRIM: remove characteres do inicio ou fim (ou ambos) de uma string
select trim('    oi        bem vindo      ')
  from funcionario;   
  
--Alguns argumentos extras podem ser adicionados a função TRIM
--Podemos inserir no primeiro argumento qual o caracter que queremos remover do início e fim da string seguido da palavra FROM
select trim('f' from 'ffffoifffbem vindofffff')
  from funcionario;   
  
--Podemos inserir a palavra LEADING especificando que o caracter deve ser removido apenas do início da palavra
select trim(leading from '          oi bem vindo           ')
  from funcionario; 

select trim(leading '0' from '0000oi bem vindo0000')
  from funcionario; 
  
--Podemos inserir a palavra TRAILING especificando que o caracter deve ser removido apenas do fim da palavra
select trim(TRAILING from '          oi bem vindo           ')
  from funcionario; 

select trim(TRAILING '0' from '0000oi bem vindo0000')
  from funcionario; 
  
--Podemos inserir a palavra BOTH especificando que o caracter deve ser removido de ambos os lados (default)
select trim(both from '          oi bem vindo           ')
  from funcionario; 

select trim(both '0' from '0000oi bem vindo0000')
  from funcionario; 
  
--Uma outra forma de utilizar o comando TRIM é com LTRIM e RTRIM
--O LTRIM irá remover o caracter especificado apenas da esquerda
select ltrim('       oi bem vindo         ')
  from funcionario; --por default remove os espaços em branco

select ltrim('0000oi bem vindo0000', '0')
  from funcionario; 
  
--O RTRIM irá remover o caracter especificado apenas da direita
select RTRIM('       oi bem vindo         ')
  from funcionario; --por default remove os espaços em branco

select RTRIM('0000oi bem vindo0000', '0')
  from funcionario; 
  