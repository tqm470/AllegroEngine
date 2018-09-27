Jeremias: Sources/Main.cpp Allegro.o Janela.o Imagem.o Fonte.o Jogo.o Mouse.o Personagem.o Jogador.o Anime.o Teclado.o
	g++ -std=c++11 -o Jeremias Sources/Main.cpp Allegro.o Janela.o Imagem.o Fonte.o Mouse.o Jogo.o Teclado.o Personagem.o Jogador.o Anime.o -lallegro -lallegro_image -lallegro_font -lallegro_ttf
Allegro.o: Sources/Allegro.cpp Headers/Allegro.h
	g++ -std=c++11 -c Sources/Allegro.cpp
Janela.o: Sources/Janela.cpp Headers/Janela.h
	g++ -std=c++11 -c Sources/Janela.cpp
Imagem.o: Sources/Imagem.cpp Headers/Imagem.h
	g++ -std=c++11 -c Sources/Imagem.cpp
Fonte.o: Sources/Fonte.cpp Headers/Fonte.h
	g++ -std=c++11 -c Sources/Fonte.cpp
Mouse.o: Sources/Mouse.cpp Headers/Mouse.h
	g++ -std=c++11 -c Sources/Mouse.cpp
Jogo.o: Sources/Jogo.cpp Headers/Jogo.h
	g++ -std=c++11 -c Sources/Jogo.cpp
Personagem.o: Sources/Personagem.cpp Headers/Personagem.h
	g++ -std=c++11 -c Sources/Personagem.cpp
Jogador.o: Sources/Jogador.cpp Headers/Jogador.h
	g++ -std=c++11 -c Sources/Jogador.cpp
Anime.o: Sources/Anime.cpp Headers/Anime.h
	g++ -std=c++11 -c Sources/Anime.cpp
Teclado.o: Sources/Teclado.cpp Headers/Teclado.h
	g++ -std=c++11 -c Sources/Teclado.cpp