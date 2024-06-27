workspaceFolder=$(pwd)

/usr/bin/clang++ -std=c++20 -I$workspaceFolder/engine/headers -L/opt/homebrew/lib -L/usr/local/lib -lglew -lglfw -framework OpenGL -O3 -o $workspaceFolder/app $workspaceFolder/main.cpp

./app