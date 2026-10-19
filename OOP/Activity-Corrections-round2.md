# Activity Corrections Round 2

## 1. Telegram bot (Shell + curl) - Wrong

Submitted:
```bash
#!/bin/bas
curl -sd "chat_id=SEU_ID&text=$1" "https://api.telegram.org/botSEU_TOKEN/sendMes
sage"
```

Issues:
- wrong shebang: `#!/bin/bas` (missing the `h`)
- URL broken across two lines
- didn't explain how to run (prompt asked for it)
- need to add proper URL encoding for special chars in the text

## 2. Merge dicts (Python) - Ok

Good, showed both ways:
- with `{**d1, **d2}` - overwrites
- with loop to keep both values in a list

Got the concept of duplicate keys

## 3. Event manager (Python) - Ok

Class with `adicionar` and `listar` - works
(but arrived without indentation, need to check if export issue or real)

## 4. Calculator (Shell) - Ok

All 4 operations work, handles division by zero, validates input
(integers only, but that's fine)

## 5. Wish list app (Python) - Wrong

Logic is good but syntax errors everywhere:
- `whilr` instead of `while`
- missing `:` in `if not lista_desejos`
- missing `)` in `int(input("..."))`
- period outside quotes in `print("Numero de item inválido".)`
- `exept` instead of `except`

## 6. Inventory app - Ok

App for store inventory, listed reqs well
- offline + sync is nice
- could be more detailed

## 7. rsync sync (round 2) - Ok

Improved a lot
- takes params, validates
- uses `--out-format` to list files
- checks exit status with `$?`
- (has some `\` instead of `/` but seems like escape issue on their end)

## 8. Count lines (Shell) - Ok

Reads file and counts lines
- validates file exists
- uses `while read` correctly
- handles last line without newline

## 9. Count occurrences (Python) - Ok

Dict to count elements
- clear output
- (could use `collections.Counter` but it's good)

## 10. Filter list (Python) - Ok

Filters even numbers
- converts input
- shows before and after
- has a typo but doesn't matter ("Listra")

---

## Summary

Wrong: 1, 5
Ok: 2, 3, 4, 6, 7, 8, 9, 10