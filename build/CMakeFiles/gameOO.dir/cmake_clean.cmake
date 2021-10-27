file(REMOVE_RECURSE
  "gameOO.exe"
  "gameOO.exe.manifest"
  "gameOO.pdb"
  "libgameOO.dll.a"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/gameOO.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
