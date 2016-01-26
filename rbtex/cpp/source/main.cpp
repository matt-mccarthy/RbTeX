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
	try{
		texer->scan();
	} catch (string ex1) {
		cout << "Failed to scan file" << endl;
		return -1;
	}
	try {
		texer->rubify();
	} catch (string ex2) {
		cout << "Failed to rubify code" << endl;
		return -1;
	}
	texer->cleanup();
	delete texer;
	return 0;
}
