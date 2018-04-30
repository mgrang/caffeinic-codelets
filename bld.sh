filename=$1
if [[ -z $filename ]]; then
  filename=`ls *.cpp | tail -1`
fi

export PATH=$PWD/llvm501_x86/bin:$PATH
echo "Building $filename:"
clang++ -std=c++11 $filename

if [[ $? -eq 0 ]]; then
  ./a.out
fi
