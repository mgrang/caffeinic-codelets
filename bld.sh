clang++ -std=c++11 $1
if [[ $? -eq 0 ]]; then
  ./a.out
fi
