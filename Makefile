build:
	g++ main.cpp ascii/Sprite.cpp ascii/SpriteAnimado.cpp \
	ascii/SpriteBuffer.cpp ascii/ObjetoDeJogo.cpp ascii/TextSprite.cpp \
	entity.cpp player.cpp memory.cpp enemy.cpp projectile.cpp -o main.out -std=c++2a

run:
	./main.out
