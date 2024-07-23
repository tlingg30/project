run:
	@g++ -Wall main.cpp abyssGame.cpp Player.cpp Monster.cpp Machine.cpp Aqua.cpp Titan.cpp Serbine.cpp Dragon.cpp SuperAqua.cpp SuperDragon.cpp SuperTitan.cpp SuperSerbine.cpp -o output
	@./output

test:
	@g++ -Wall unitTests.cpp Player.cpp Monster.cpp Machine.cpp Aqua.cpp Titan.cpp Serbine.cpp Dragon.cpp SuperAqua.cpp SuperDragon.cpp SuperTitan.cpp SuperSerbine.cpp -o utest
	@./utest

clean_output:
	@rm -f output

clean_test:
	@rm -f utest