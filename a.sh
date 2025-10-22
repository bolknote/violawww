find . -type f -name '*.c' -print0 |
while IFS= read -r -d '' f; do
  echo "$f"
  tmp="$(mktemp "${f##*/}.XXXXXX")" || exit 1
  python3 a.py "$f" > "$tmp" && mv -- "$tmp" "$f" || { rm -f -- "$tmp"; exit 1; }
done