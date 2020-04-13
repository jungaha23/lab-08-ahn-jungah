#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>


#include "imagehelpers.h"
int main() {

  int img[MAX_H][MAX_W];
  int h, w;

  readImage("inImage.pgm",img, h, w); // read it from the file "inImage.pgm"
  // h and w were passed by reference and
  // now contain the dimensions of the picture
  // and the 2-dimesional array img contains the image data

  // Now we can manipulate the image the way we like
  
  // TASK A
  int out[MAX_H][MAX_W];
	
  for(int row = 0; row < h; row++) {
    for(int col = 0; col < w; col++) {
      out[row][col] = invert(img[row][col]);
    }
  }

  // and save this new image to file "taska.pgm"
  writeImage("taska.pgm", out, h, w);
  
  //TASK B
  int invertHalf[MAX_H][MAX_W];
  
  for(int row = 0; row < h; row++) {
    for(int col = 0; col < w/2; col++) { //writes first half of image normally
      invertHalf[row][col] = img[row][col];
    }
    for (int col = w/2; col < w; col++){ //inverts second half
    	invertHalf[row][col] = invert(img[row][col]);
    }
  }

  // and save this new image to file "taskb.pgm"
  writeImage("taskb.pgm", invertHalf, h, w);

  //TASK C
  int box[MAX_H][MAX_W];
  
  for(int row = 0; row < h; row++) {
    for(int col = 0; col < w; col++) { 
      if ((row > h/4 && row < (h/2 + h/4)) && (col > w/4 && col < (w/2 + w/4))){
      	box[row][col] = 255;
      } else {
      	box[row][col] = img[row][col];
      }
    }
  }

  // and save this new image to file "taskc.pgm"
  writeImage("taskc.pgm", box, h, w);
  
  //TASK D
  int frame[MAX_H][MAX_W];
  
  for(int row = 0; row < h; row++) {
    for(int col = 0; col < w; col++) { 
    	if ((row >= h/4 && row <= (h/2 + h/4)) && (col >= w/4 && col <= (w/2 + w/4))){ //checks if it is the same position as box
		   if (row == h/4 || row == (h/4 + h/2) || col == w/4 || col == (w/4 + w/2)){ //checks if it is only the frame
		   	frame[row][col] = 255;
		   } else {
		   	frame[row][col] = img[row][col];
		   }
		} else {
			frame[row][col] = img[row][col];
		}
    }
  }

  // and save this new image to file "taskd.pgm"
  writeImage("taskd.pgm", frame, h, w);
  
  //TASK E
  int scale[MAX_H][MAX_W];
  
  for(int row = 0; row < h*2; row+=2) {
    for(int col = 0; col < w*2; col+=2) { 
			scale[row][col] = img[row][col]; //first box
			scale[row][col+1] = img[row][col]; //box to the right
			scale[row+1][col] = img[row][col]; //box below
			scale[row+1][col+1] = img[row][col]; //box right and down
    }
  }

  // and save this new image to file "taske.pgm"
  writeImage("taske.pgm", scale, h, w);
  
  //TASK F
  int pixelate[MAX_H][MAX_W];
  
  for(int row = 0; row < h; row+=2) {
    for(int col = 0; col < w; col+=2) { 
			pixelate[row][col] = blur(img[row][col], img[row][col+1], img[row+1][col], img[row+1][col+1]);
			pixelate[row][col+1] = blur(img[row][col], img[row][col+1], img[row+1][col], img[row+1][col+1]);
			pixelate[row+1][col] = blur(img[row][col], img[row][col+1], img[row+1][col], img[row+1][col+1]);
			pixelate[row+1][col+1] = blur(img[row][col], img[row][col+1], img[row+1][col], img[row+1][col+1]);
    }
  }

  // and save this new image to file "taskf.pgm"
  writeImage("taskf.pgm", pixelate, h, w);
<<<<<<< HEAD
=======
  
>>>>>>> fa87c3c88b589d89b8873b5a1eb8772717599d18

}




