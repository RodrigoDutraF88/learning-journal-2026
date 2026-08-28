
-- Obtenha a quantidade total de produtos em estoque
SELECT SUM(Quantidade)
FROM Produtos
--Obtenha a quantidade de produtos em estoque agrupados pelo tipo
SELECT Tipo, SUM(Quantidade)
FROM Produtos
GROUP BY Produtos.Tipo
--Obtenha a quantidade de produtos em estoque de acordo com o tipo e fabricante disponíveis.
SELECT Tipo, Fabricante, SUM(Quantidade)
FROM Produtos
GROUP BY Tipo, Fabricante

--Obter a quantidade total em estoque de cada fabricante.
SELECT Fabricante, SUM(Quantidade)
FROM Produtos
GROUP BY Fabricante

--Mostre o nome, fabricante e quantidade do produto que possui a menor quantidade em estoque.
SELECT Nome, Fabricante, Quantidade
FROM Produtos
GROUP BY Fabricante 
ORDER BY Quantidade 
LIMIT 1

--Calcule a média do preço unitário dos produtos por tipo.
SELECT Tipo, AVG(VUnitario)
FROM Produtos
GROUP BY Tipo

--Mostre os tipos de produtos que têm uma quantidade total em estoque superior a 200 (maior que 200)
SELECT Tipo, SUM(Quantidade)
FROM Produtos
GROUP BY Tipo
HAVING SUM(Quantidade) > 200