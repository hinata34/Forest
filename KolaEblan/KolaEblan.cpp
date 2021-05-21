#include "Window.h"
int main() {

	Window* window = new Window({ 245,171,201 });
	window->render();
	return 0;
}