# Activity Corrections: Shell Script and Python

Responsible mentor: Rodrigo

---

## Round 1 (2026-10-09)

### 1. Word frequency (`grep`, `sort`, `uniq`): Correct

**Prompt:** Using `grep`, `sort` and `uniq`, build a routine that analyzes a log file and shows which words appear most frequently.

**Student's answer:**

```bash
echo "Insira o caminho do arquivo"
read arquivo 

if [ ! -f "$arquivo" ]; then 
    echo "Arquivo nao encontrado"
    exit 1
fi 

grep -oE '[a-zA-Z]+' "$arquivo" | sort | uniq -c | sort -nr | head -n 15
```

**Expected:**

```bash
#!/bin/bash

read -p "Insira o caminho do arquivo: " arquivo

if [ ! -f "$arquivo" ]; then
    echo "Arquivo nao encontrado"
    exit 1
fi

grep -oE '[a-zA-Z]+' "$arquivo" | tr 'A-Z' 'a-z' | sort | uniq -c | sort -nr | head -n 15
```

**Corrections:**
- The pipeline solves the prompt; the syntax errors from the previous submission were fixed.
- The `#!/bin/bash` shebang is missing (optional here).
- Suggestion (does not invalidate): use `tr` to lowercase, so "Error" and "error" are not counted separately.

---

### 2. Sync directories with `rsync`: Correct

**Prompt:** Build a Shell script that automatically syncs two directories using `rsync`. The script must show in the terminal which files were updated.

**Student's answer:**

```bash
echo "caminho de origem"
read origem

echo "caminho de destino"
read destino 

origem="${origem%/}/"

rsync -avh --update "$origem" "$destino"
```

**Expected:**

```bash
#!/bin/bash

read -p "Caminho de origem: " origem
read -p "Caminho de destino: " destino

if [ ! -d "$origem" ] || [ ! -d "$destino" ]; then
    echo "Diretorio de origem ou destino nao encontrado"
    exit 1
fi

origem="${origem%/}/"

rsync -avh --update "$origem" "$destino"
```

**Corrections:**
- `rsync -avh --update` updates the destination and lists the files in the terminal.
- The trailing slash on the source was handled well.
- Missing check that the directories exist.
- 94% similarity: check for real improvement over the previous submission.

---

### 3. Copy files containing a keyword: Wrong

**Prompt:** Search the current directory for a keyword (passed as a variable parameter) inside text files, create a folder, copy all matching files into it, and print how many files were copied. All in a single `.sh` script.

**Student's answer:**

```bash
echo "palavra-chave a ser buscada:"
read palavra_chave 

echo "pasta que sera criada"
read pasta 

mkdir -p "$pasta"

contador=0

while IFS= read -r arquivo; do
    cp "$arquivo" "$pasta/"
    contador=$((contador+1))
done <<(grep-1 "$palavra_chave" *.txt 2>/dev/null)
```

**Expected:**

```bash
#!/bin/bash

read -p "Palavra-chave a ser buscada: " palavra_chave
read -p "Pasta que sera criada: " pasta

mkdir -p "$pasta"

contador=0

while IFS= read -r arquivo; do
    cp "$arquivo" "$pasta/"
    contador=$((contador+1))
done < <(grep -l "$palavra_chave" *.txt 2>/dev/null)

echo "$contador arquivos copiados"
```

**Corrections:**
- The idea is right (search, create folder, copy with a counter).
- `grep-1` should be `grep -l` (letter L, with a space).
- `<<(` should be `< <(`.
- The final `echo` printing how many files were copied is missing (a requirement of the prompt).

---

### 4. Arithmetic calculator: Wrong

**Prompt:** Create a small arithmetic calculator in Shell Script that performs the basic operations.

**Student's answer:**

```bash
echo "primeiro numero" 
read x

echo "segundo numero"
read y 

echo "qual operaçao ? +,-,*,/ "
read op 

if[ "$op"  = "/"] && [ "$y" == "0"]; then
    echo "nao pode divisao por 0"
    exit 1
fi

case "$op" in
    +) resultado=$(echo "scale=2; $x + $y" | bc) ;; 
    -) resultado=$(echo "scale=2; $x - $y" | bc) ;;
    "*") resultado=$(echo "scale=2; $x * $y" | bc) ;; 
    /) resultado=$(echo "scale=2; $x / $y" | bc) ;; 
    *)
        echo "Escolha de operaçao invalida"
        exit 1
        ;;
esac

echo "Resultado: $x $op $y = $resultado"
```

**Expected:**

```bash
#!/bin/bash

echo "primeiro numero"
read x

echo "segundo numero"
read y

echo "qual operacao? +,-,*,/"
read op

if [ "$op" = "/" ] && [ "$y" = "0" ]; then
    echo "nao pode divisao por 0"
    exit 1
fi

case "$op" in
    +) resultado=$(echo "scale=2; $x + $y" | bc) ;;
    -) resultado=$(echo "scale=2; $x - $y" | bc) ;;
    "*") resultado=$(echo "scale=2; $x * $y" | bc) ;;
    /) resultado=$(echo "scale=2; $x / $y" | bc) ;;
    *)
        echo "Escolha de operacao invalida"
        exit 1
        ;;
esac

echo "Resultado: $x $op $y = $resultado"
```

**Corrections:**
- The logic is good: `case`, `bc` with `scale`, and division-by-zero handling.
- `if[` needs a space after `if`.
- Spaces are missing before `]` (`"/" ]` and `"0" ]`).
- 95% similarity: check against previous submissions.

---

## Round 2 (2026-10-13)

### 1. Count lines in a file (resubmission): Correct

**Prompt:** Build a Shell Script routine that reads a text file and counts how many lines it has.

**Student's answer:**

```bash
#!/bin/bash

read -p "Insira o nome do arquivo: " arquivo

linhas=$(wc -l < "$arquivo")

echo "O numero de linhas de $arquivo e $linhas"
```

**Expected:**

```bash
#!/bin/bash

read -p "Insira o nome do arquivo: " arquivo

if [ ! -f "$arquivo" ]; then
    echo "Arquivo nao encontrado"
    exit 1
fi

linhas=$(wc -l < "$arquivo")

echo "O numero de linhas de $arquivo e $linhas"
```

**Corrections:**
- The shebang was fixed to `#!/bin/bash` and the script works.
- The 99.7% similarity is with the student's own previous submission.
- Optional improvement: check that the file exists before running `wc`.

---

### 2. Arithmetic calculator: Correct

**Prompt:** Create a small arithmetic calculator in Shell Script that performs the basic operations.

**Student's answer:**

```bash
#!/bin/bash

read -p "Digite o primeiro numero: " n1
read -p "Digite o segundo numero: " n2
read -p "Escolha a operacao a ser realizada (+, -, *, /): " op

case "$op" in 
    "+")
        resultado=$((n1+n2))
        ;;
    "-")
        resultado=$((n1-n2))
        ;;
    "*")
        resultado=$((n1*n2))
        ;;
    "/")
        resultado=$((n1/n2))
        ;;
    *) 
        echo "Operacao invalida"
        exit
        ;;
esac

echo "Resultado: $resultado"
```

**Expected (optional improvements):**

```bash
#!/bin/bash

read -p "Digite o primeiro numero: " n1
read -p "Digite o segundo numero: " n2
read -p "Escolha a operacao a ser realizada (+, -, *, /): " op

case "$op" in
    "+") resultado=$(echo "scale=2; $n1 + $n2" | bc) ;;
    "-") resultado=$(echo "scale=2; $n1 - $n2" | bc) ;;
    "*") resultado=$(echo "scale=2; $n1 * $n2" | bc) ;;
    "/")
        if [ "$n2" = "0" ]; then
            echo "Nao pode dividir por 0"
            exit 1
        fi
        resultado=$(echo "scale=2; $n1 / $n2" | bc)
        ;;
    *)
        echo "Operacao invalida"
        exit 1
        ;;
esac

echo "Resultado: $resultado"
```

**Corrections:**
- `case`, quoting and `$(( ))` are correct; all four operations work.
- Points of attention (do not invalidate): division by zero is not handled, it only works with integers (`bc` would fix this), and `exit` has no return code.
- 98.9% similarity: check against previous submissions.

---

### 3. Iterate over a list (Python): Correct

**Prompt:** Write code that iterates over a list and prints each element.

**Student's answer:**

```python
def imprimir_elementos(lista):
    for elemento in lista:
        print(elemento)
itens = [1, 2, 3, 4, 5]
imprimir_elementos(itens)
```

**Expected:** same as the student's answer.

**Corrections:**
- Clear function, expected output. Nothing to fix.

---

### 4. Filter a list by condition (Python): Wrong

**Prompt:** Write code that filters list elements based on a condition.

**Student's answer:**

```python
def filtrar_lista(lista, condicao)
    """Filtra elementos de uma lista com base em uma função de condição."""
    return [item for item in lista if condicao(item)]

numeros = [1, 2, 3, 4, 5, 7, 8, 9, 10]
pares =   filtrar_lista(numeros, lambda x: x % 2 == 0)

print(pares)
```

**Expected:**

```python
def filtrar_lista(lista, condicao):
    """Filtra elementos de uma lista com base em uma função de condição."""
    return [item for item in lista if condicao(item)]

numeros = [1, 2, 3, 4, 5, 7, 8, 9, 10]
pares = filtrar_lista(numeros, lambda x: x % 2 == 0)

print(pares)
```

**Corrections:**
- The logic with list comprehension and `lambda` is great.
- The `:` is missing at the end of `def filtrar_lista(lista, condicao)`, which raises a `SyntaxError`.

---

### 5. Count lines in a file (resubmission with progress): Wrong

**Prompt:** Build a Shell Script routine that reads a text file and counts how many lines it has.

**Student's answer:**

```bash
#! \bin \bash        \\nao consigo usar a outra barra, a metabloom bloqueia 

read -p "Digite o caminho do arquivo:" arquivo

if [! -f "$arquivo"]; then
   echo "Erro: arquivo nao encontrado"
   exit 1
fi

total = $(wc -1 < "arquivo")
echo "O arquivo possui $total linhas"
```

**Expected:**

```bash
#!/bin/bash

read -p "Digite o caminho do arquivo: " arquivo

if [ ! -f "$arquivo" ]; then
   echo "Erro: arquivo nao encontrado"
   exit 1
fi

total=$(wc -l < "$arquivo")
echo "O arquivo possui $total linhas"
```

**Corrections:**
- Progress: now uses `read -p`, has the `fi`, and checks that the file exists.
- `[! -f "$arquivo"]` needs a space after `[` and before `]`.
- `total = $(...)` cannot have spaces around the `=`.
- `wc -1` should be `wc -l` (letter L).
- `"arquivo"` is missing the `$`, so it counts lines of a file literally named "arquivo".
- The shebang must be `#!/bin/bash`. If their environment blocks the slash, the student should report it or try typing it directly in the editor.

---

## Recurring mistakes

| Mistake | Appears in |
|---|---|
| Missing spaces in `[ ]` / `if [` | Calculator (R1), Count lines (R2) |
| Spaces around `=` in assignments | Count lines (R2) |
| Wrong flag (`-1` instead of `-l`) | Copy files (R1), Count lines (R2) |
| Incorrect shebang | Count lines (R2) |
| Forgetting `:` in Python | Filter list (R2) |
| High similarity with previous submissions | Rsync, Copy files, Calculator (R1); Count lines, Calculator (R2) |