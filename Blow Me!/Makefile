output: Blow\ Me\!.o Animation.o Background.o Bubble.o Entity.o Fan.o ScreenManager.o Menu.o
	g++ Blow\ Me\!.o Animation.o Background.o Bubble.o Entity.o Fan.o Menu.o ScreenManager.o -lm -Wall -Wextra -lraylib -lGL -lpthread -ldl -lrt -lX11 -o output

Blow\ Me\!.o:  
	g++ -c Blow\ Me\!.cpp

Animation.o: Animation.cpp Animation.hpp
	g++ -c Animation.cpp

Background.o: Background.cpp Background.hpp
	g++ -c Background.cpp

Bubble.o: Bubble.cpp Bubble.hpp
	g++ -c Bubble.cpp

Entity.o: Entity.cpp Entity.hpp
	g++ -c Entity.cpp

Fan.o: Fan.cpp Fan.hpp
	g++ -c Fan.cpp

ScreenManager.o: ScreenManager.cpp ScreenManager.hpp
	g++ -c ScreenManager.cpp

Menu.o: Menu.cpp Menu.hpp
	g++ -c Menu.cpp

clean:
	rm -r *.o
	rm output
