tinyscan:	main.cpp scan.cpp cam.cpp

	g++ main.cpp scan.cpp cam.cpp  -lcurses -lcxcore -lX11 -lpthread -lcv -lhighgui -o tinyscan

