To run this program. Ensure that time-it-ii is also downloaded. The best bet is to download the whole folder hw01.

Time-it-ii is dependent on the StopWatch header inside the time-it-i folder. This program uses a relative path to the header. Therefore, while compiling ensure that you have the StopWatch.hpp and StopWatch.cpp in the right location, or change the source code so that you can keep it in the same folder.

The other files that you'd need for the required multi file compilation is Book.hpp, and Book.cpp

Finally, the file reads the 22680-0.txt, 42357-0.txt, 64317-0.txt pg27507.txt, pg35641.txt. Depending upon the compiler you may need to put it in different locations. If you were to straight up compile in this folder and create the executable here then it will work. Where as running the executable in a location without these text files will crash the program. Thus, ensure that these files are in the appropriate location.

If you want to put your own files, then you may change the source code to read and process your files. 
