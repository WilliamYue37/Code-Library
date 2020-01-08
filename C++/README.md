My C++ Compile Flag:\
g++ -std=c++17 -Wshadow -Wall -o "$1" "$1".cpp -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -g
