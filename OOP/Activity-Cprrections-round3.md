# Activity Corrections: Round 3 (2026-10-21)


Mentorship topic: Object-Oriented Programming (Orientação a Objetos), T03

Verdicts were given with a lenient approach.

---

## 1. BMVC I (video + repository): Correct, with a caveat

**Prompt:** To reach level BMVC I, the student must record a YouTube video (maximum 3 minutes) showing, on their own machine, the complete working of their BMVC code, serving a static page (HTML or TPL). The page must have readable information and a clear, defined purpose, and must load fully working CSS and JS files. The classroom HTML cannot be reused, so the code must be personalized. Also paste the link to the project repository and make sure it is public.

**Student's answer:**

```
Video: https://youtu.be/DHdPDFdSeiE
Github: https://github.com/omariannab/lista-de-compras-bmvc
```

**Expected:** a public repository with the BMVC project (page with a clear purpose, loading working CSS and JS, personalized HTML) and a video of up to 3 minutes showing it running.

**Corrections:**
- The repository is public and has a `README` with the student's name, the purpose (a shopping list where each product can be marked as bought, with a progress bar) and how to run it (`python3 route.py`, then open `/lista`). It also contains the `app` folder, `route.py` and a `Dockerfile`.
- The video exists on YouTube ("BMVC Nível 1 - Lista de Compras", published 2026-10-19).
- Not verified (could not watch the video or open the `app` folder): video length (up to 3 minutes), the page loading active CSS and JS, and the HTML being personalized rather than the classroom one. Check these before finalizing.
- The "Verificação semântica de vídeo" field came empty.

---

## 2. Wish list app (resubmission, Python): Correct

**Prompt:** Develop a wish list application that allows adding and removing items.

**Student's answer:**

```python
class ListaDesejos:
    def __init__(self):
        self.itens = []
    def adicionar(self, item):
        self.itens.append(item)
    def remover(self, item):
        if item in self.itens:
            self.itens.remove(item)
    def mostrar(self):
        print(self.itens)

lista = ListaDesejos()
lista.adicionar("ps5")
lista.adicionar("fone")
lista.remover("fone")
lista.mostrar()
```

**Expected:** same as the student's answer.

**Corrections:**
- The constructor was fixed (`def_init_` became `def __init__`) and the code now works.
- Adds items, removes them (checking that they exist) and shows the list, with a demonstration at the end.

---

## 3. `Relatorio` using `Impressora` (dependency): Wrong

**Prompt:** Create a `Relatorio` class that uses an `Impressora` class only inside a method to print a message. Do not store the `Impressora` as an attribute. Demonstrate this dependency working.

**Student's answer:**

```python
class Impressora:
    def imprimir(self, texto):
        print(f"[impressora] {texto}")
class Relatorio:
    def __init__(self, titulo):
        self.titulo = titulo
    def gerar(self):
        impressora().imprimir(f"relatorio de {self.titulo}")
Relatorio("Vendas").gerar()
```

**Expected:**

```python
class Impressora:
    def imprimir(self, texto):
        print(f"[impressora] {texto}")

class Relatorio:
    def __init__(self, titulo):
        self.titulo = titulo

    def gerar(self):
        Impressora().imprimir(f"relatorio de {self.titulo}")

Relatorio("Vendas").gerar()
```

**Corrections:**
- The structure is right: `Impressora` is not stored as an attribute, it is only used inside `gerar`, and there is a demonstration.
- `impressora()` is lowercase and raises a `NameError`; it must be `Impressora()`. A one-letter fix.

---

## 4. `Carro` and `Motor` (composition): Correct

**Prompt:** Create two classes in Python: `Carro` and `Motor`. The `Carro` must have a `Motor` as an attribute. Implement a method that shows a message saying the car is running with its engine.

**Student's answer:**

```python
class Motor:
    def __init__(self, potencia):
        self.potencia = potencia

class Carro:
    def __init__(self, modelo, motor):
        self.modelo = modelo
        self.motor = motor

    def exibir(self):
        print(f"{self.modelo} esta funcionando com motor {self.motor.potencia}")

carros = []

while True:
    print("1 - Cadastrar carro")
    print("2 - Exibir carros")
    print("3 - Sair")
    esc = input("Escolha: ")

    if esc== "1":
        model = input("Modelo: ")
        pot = input("Potencia do motor: ")
        mot = Motor(pot)
        car = Carro(model, mot)
        carros.append(car)
    elif esc == "2":
        if len(carros) == 0:
            print("Nenhum carro cadastrado")
        else:
            for c in carros:
                c.exibir()
    elif esc == "3":
        break
    else: 
        print("Opcao invalida")
```

**Expected:** same as the student's answer.

**Corrections:**
- Correct composition (the `Carro` receives and stores the `Motor`) and the `exibir` method prints the requested message.
- Bonus: a menu to register and list cars.
- 74% similarity: worth checking against the previous submission.

---

## Summary

| # | Activity | Verdict |
|---|---|---|
| 1 | BMVC I (video + repo) | Correct (verify video length and CSS/JS) |
| 2 | Wish list app | Correct |
| 3 | Relatorio / Impressora | Wrong (`impressora()` should be `Impressora()`) |
| 4 | Carro / Motor | Correct |