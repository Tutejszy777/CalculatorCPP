if(EXISTS "C:/Users/Murav/Documents/GitHub/Calculator/out/build/mypreset/hello_test[1]_tests.cmake")
  include("C:/Users/Murav/Documents/GitHub/Calculator/out/build/mypreset/hello_test[1]_tests.cmake")
else()
  add_test(hello_test_NOT_BUILT hello_test_NOT_BUILT)
endif()
