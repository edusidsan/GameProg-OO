file(REMOVE_RECURSE
  "OgrO.exe"
  "OgrO.exe.manifest"
  "OgrO.pdb"
  "libOgrO.dll.a"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/OgrO.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
