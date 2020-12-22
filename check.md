- penser a verifier si il segfault pas sur des flags du style `%-10.y` (si le char n'est pas dans le charset) qui pourrait poser probleme sans la verification de `\0` dans la fonction `parse_flags`

- passer les `%x` en `size_t` pour gerer les overflows (ex : `-10` = `fffff6` et pas `-a`)