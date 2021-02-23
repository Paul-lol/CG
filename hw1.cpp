/*******************************************************
 * Homework 1: Rasterization                           *
 *-----------------------------------------------------*
 * Here you will implement the circle rasterization    *
 * method decribed in the handout.                                           *
 * To compile this in linux:                           *
 *        g++ hw1.cpp                                  *
 * Then, run the program as follows:                   *
 *        ./a.out 200                                  *
 * to generate a 200x200 image containing a circular   *
 * arc.  Note that the coordinate system we're using   *
 * places pixel centers at integer coordinates and     *
 * has the origin at the lower left.                   *
 * Your code will generate a .ppm file containing the  *
 * final image. These images can be viewed using       *
 * "display" in Linux or Irfanview in Mac/Windows.     *
 *******************************************************/

#include <iostream>
#include <fstream>
#include <cstdio>
#include <cassert>
using namespace std;

// We'll store image info as globals; not great programming practice
// but ok for this short program.
int radius;
bool **image;


//This is the first render function for the first quadrant and its mirror image 
void renderPixel(int x, int y) {
    assert(x >= 0 && y >= 0 && x <= radius && y <= radius);
    image[x][y] = 1;

    // TODO:  light up the pixel's symmetric counterpart
	image[y][x] = 1;
}

//This is the second render function to render the second quadrant and its mirror image 
void renderPixel1(int x, int y) {
	assert(x >= 0 && y >= 0 && x <= radius && y <= radius);
	image[x][radius-y] = 1;

	// TODO:  light up the pixel's symmetric counterpart
	image[y][radius-x] = 1;
}

//This is the third render function to render the fourth quadrant of the smaller semicircle and its mirror image. 
void renderPixel3(int x, int y) {
	assert(x >= 0 && y >= 0 && x <= radius && y <= radius);
	image[radius-x][y] = 1;

	// TODO:  light up the pixel's symmetric counterpart
	image[radius-y][x] = 1;
}


void rasterizeArc(int r) {
    // TODO:  rasterize the arc using renderPixel to light up pixels
	int r2 = r - 50;
	int x = radius/2;
	int y = radius;
	int d = 1 - radius;
	int deltaE = 3;
	int deltaSE = -2*radius + 5;
	renderPixel(x, y); //render method called
	renderPixel1(x, y);
	while (y > x)
	{ //Setting the conditions for d and selecting the deltas
		if (d < 0) {
			d += deltaE;
			deltaE += 4;
			deltaSE += 4;
		}
		// Selecting the value of dE- closest to the circle
		else {
			d += deltaSE;
			deltaE += 4;
			deltaSE += 8;
			y--;
		}
		x++;
		renderPixel(x, y);//render method called first time
		renderPixel1(x, y);//render method called second time 
	}

	//Initialize values and algorithm for the inner semicircle of radius 100
	x = r/2; 
	y = r2; 
	d = 1 - r2;
	deltaE = 3;
	deltaSE = -2 * r2 + 5;
	renderPixel(x, y); //render method called
	renderPixel3(x, y);
	while (y > x)
	{ //conditions for d
	  //Selecting E
		if (d < 0) {
			d += deltaE;
			deltaE += 5;
			deltaSE += 5;
		}
		// Selecting the value of dE- closest to the circle
		else {
			d += deltaSE;
			deltaE += 5;
			deltaSE += 9;
			y--;
		}
		x++;
		renderPixel(x, y);
		renderPixel3(x, y);//render method called
	}
	
}

// You shouldn't need to change anything below this point.

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " circleSize\n";
        return 0;
    }

#ifdef _WIN32
    sscanf_s(argv[1], "%d", &radius);
#else
    sscanf(argv[1], "%d", &radius);
#endif
    if (radius <= 0) {
        cout << "Image must be of positive size.\n";
        return 0;
    }

    // reserve image as 2d array
    image = new bool*[radius+1];
    for (int i = 0; i <= radius; i++) image[i] = new bool[radius+1];

    rasterizeArc(radius);

    char filename[50];
#ifdef _WIN32
    sprintf_s(filename, 50, "circle%d.ppm", radius);
#else
    sprintf(filename, "circle%d.ppm", radius);
#endif

    ofstream outfile(filename);
    outfile << "P3\n# " << filename << "\n";
    outfile << radius+1 << ' ' << radius+1 << ' ' << 1 << endl;

    for (int i = 0; i <= radius; i++)
    for (int j = 0; j <= radius; j++)
        outfile << image[radius-i][j] << " 0 0\n";

    // delete image data
    for (int i = 0; i <= radius; i++) delete [] image[i];
    delete [] image;

	//cin.get();
    return 0;

}
