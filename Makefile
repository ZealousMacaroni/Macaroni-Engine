app: main.cpp
	/usr/bin/clang++ -std=c++20 -I/engine/headers -L/opt/homebrew/lib -L/usr/local/lib -lglew -lglfw -framework OpenGL -O3 -o app main.cpp