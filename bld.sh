if [[ -z $1 ]]; then
  echo "Specify source file"
  exit 1
fi

src=$1
echo "Building $src"
g++ -std=c++11 $src

if [[ $? -eq 0 ]]; then
  ./a.out
fi
