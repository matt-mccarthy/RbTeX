#include "../header/futil.h"
#include "../header/texer.h"
#include "../header/includes.h"

using namespace std;

int main(int argc, const char** argv){
	if(argc != 2){
		cout << "No TeX file provided :(" << endl << "Exiting with code -1" << endl;
		return -1;
	}
	Texer* texer = new Texer(string(argv[1]));
	texer->scan();
	texer->cleanup();
	delete texer;
	return 0;
}
