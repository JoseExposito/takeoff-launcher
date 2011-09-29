FILE(REMOVE_RECURSE
  "CMakeFiles/translations"
  "pl.gmo"
  "ca.gmo"
  "es.gmo"
  "tr.gmo"
  "gl.gmo"
  "it.gmo"
  "ru.gmo"
  "el.gmo"
  "de.gmo"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang)
  INCLUDE(CMakeFiles/translations.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
