--Autores(autor_id, nome, sobrenome, data_nascimento, nacionalidade, biografia)
--Editoras(editora_id, nome, endereco, telefone, email, site)
--Categorias(categoria_id, nome, descricao)
--Livros(livro_id, titulo, isbn, ano_publicacao, edicao, num_paginas, idioma, #categoria_id, #editora_id)
--Livro_Autor(#livro_id, #autor_id)
--Usuarios(usuario_id, nome, sobrenome, email, telefone, endereco, data_registro, status)
--Exemplares(exemplar_id, #livro_id, codigo_barras, status, data_aquisicao)
--Emprestimos(emprestimo_id, #exemplar_id, #usuario_id, data_emprestimo, data_devolucao_prevista, data_devolucao_real, multa)
--Reservas(reserva_id, #livro_id, #usuario_id, data_reserva, status)

--Liste o id e o titulo de todos os livros disponíveis (Exemplares.status = 'Disponível') juntamente com o nome e sobrenome de seus respectivos autores, ordenados pelo sobrenome do autor.
SELECT Livros.livro_id, Livros.titulo, Autores.nome, Autores.sobrenome
FROM Livros JOIN Livro_Autor ON Livros.livro_id = Livro_Autor.livro_id
            JOIN Autores ON Livro_Autor.autor_id = Autores.autor_id
            JOIN Exemplares ON Livros.livro_id = Exemplares.livro_id
WHERE Exemplares.status = 'Disponível'
ORDER BY Autores.sobrenome

--Liste o id e o nome dos usuários que realizaram mais empréstimos que a média de empréstimos por usuário.
SELECT U.usuario_id, U.nome
FROM Usuarios U JOIN Emprestimos E ON U.usuario_id = E.usuario_id
GROUP BY U.usuario_id
HAVING COUNT(E.emprestimo_id) > ( SELECT COUNT(emprestimo_id) * 1.0 / COUNT(DISTINCT usuario_id)
    FROM Emprestimos)

--Liste o id e o titulo de todos os livros (ordenados pelo titulo) juntamente com o id de suas respectivas reservas pendentes (Reservas.status='Pendente'), se houver.
SELECT L.livro_id, L.titulo, R.reserva_id
FROM Livros L LEFT JOIN Reservas R ON L.livro_id = R.livro_id
                                    AND R.status = 'Pendente' 
GROUP BY L.titulo

--Calcule o número de livros por categoria e ordene o resultado de forma decrescente pela quantidade.
--Exiba o nome o id da categoria, o nome da categoria e uma coluna chamada total_livros que se refere a quantidade total de livros da categoria
SELECT C.categoria_id, C.nome, COUNT(L.livro_id) AS total_livros
FROM Categorias C JOIN Livros L ON C.categoria_id = L.categoria_id
GROUP BY C.categoria_id
ORDER BY total_livros DESC, C.categoria_id

--Liste o id e o nome das editoras que publicaram mais de 2 livros. Mostre a quantidade de livros publicados pela editora em uma nova coluna chamada total_livros.
SELECT E.editora_id, E.nome, COUNT( L.livro_id) AS total_livros
FROM Editoras E JOIN Livros L ON E.editora_id = L.editora_id
GROUP BY E.editora_id
HAVING total_livros > 2
--Liste o id e o titulo de todos os livros que nunca foram emprestados.
SELECT L.livro_id, L.titulo
FROM Livros L
WHERE L.livro_id NOT IN ( SELECT L.livro_id
FROM Livros L JOIN Exemplares X ON L.livro_id = X.livro_id
        JOIN Emprestimos E ON X.exemplar_id = E.exemplar_id
)
