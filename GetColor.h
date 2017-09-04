#pragma once
#include <opencv2\opencv.hpp>

#define X_POZ 0
#define Y_POZ 10
#define GRENN_RGB 10
#define GRENN_W 35
#define BLUE_RGB 10
#define BLUE_W 55
#define RED_B_G 35
#define YELLOW_R_G 50
#define ORANGE_RGB 30
#define ORANGE_RB 50
#define ORANGE_R 99
#define WHITE_RGB 65

using namespace std;
using namespace cv;

class GetColor
{
public:
	GetColor();
	GetColor(Mat *src);
	~GetColor();

public:
	void colorClassificationRGB(int *wall);
	void colorClassificationHistRGB(int *wall);
	void getWall();
	void showGetColorArea(Mat *src);
	void organizeTabColor(int **,int *);
	void initialize(int **tab);

private:
	void drawRectangles();
	void RGBHist(Mat);
	void avarageValueRGB(Mat src);
	void drawRubicWall(Mat square[9], int x_poz = 0, int y_poz = 0);
	void buildTrueColorWall();
	//void drawRubicWall();

private:
	Mat square[9];
	Mat temp_square[9];
	Mat *src;
	Mat temp;
	Mat b_hist, g_hist, r_hist;
	vector<Mat> bgr_planes;
	Rect rect[3][3];
	Rect color_rect[3][3];
	char *text;
	double maxB, maxR, maxG;
	int while_counter;
	int hist_counter;
	int color[9][3];
	int square_counter;
	int histSize;
	int organize_color[6][9];
	char *collllor[9];
	float distance[3];
	bool uniform;
	bool accumulate;
	int **rubic_colors;

};

