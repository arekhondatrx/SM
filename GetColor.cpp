#include "GetColor.h"


GetColor::GetColor()
{
	while_counter = 0;
	square_counter = 0;
	histSize = 256;
	uniform = true;
	accumulate = false;
	hist_counter = 0;

}

GetColor::GetColor(Mat *src)
{
	while_counter = 0;
	square_counter = 0;
	this->src = src;
	histSize = 256;
	uniform = true;
	accumulate = false;
	hist_counter = 0;
	maxB = 0;
	maxG = 0;
	maxR = 0;

	for (int i = 0; i < 9; i++)
	{
		collllor[i] = new char[6];
	}

}


GetColor::~GetColor()
{
}

void GetColor::initialize(int **tab)
{
	rubic_colors = tab;
}

void GetColor::avarageValueRGB(Mat src)
{
	int temp_color[] = { 0, 0, 0 };

	for (int i = 0; i < src.rows; i++)
	{
		for (int j = 0; j < src.cols; j++)
		{
			temp_color[0] += src.at<Vec3b>(i, j)[0];
			temp_color[1] += src.at<Vec3b>(i, j)[1];
			temp_color[2] += src.at<Vec3b>(i, j)[2];
		}
	}

	for (int i = 0; i < 3; i++)
	{
		temp_color[i] = temp_color[i] / (src.rows * src.cols);
		color[square_counter][i] = temp_color[i];
	}
}

void GetColor::getWall()
{
	square_counter = 0;
	Mat temporary;
	int c = 0;

	drawRectangles();

	for (int i = 0; i < 9; i++)
	{
		avarageValueRGB(square[i]);
		square_counter++;
	}
}

void GetColor::drawRectangles()
{
	text = new char[1];
	while_counter = 0;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			rect[i][j].x = (*src).cols *0.34;
			rect[i][j].y = (*src).rows *0.26;
			rect[i][j].width = (*src).cols *0.07;
			rect[i][j].height = (*src).cols *0.07;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			rect[i][j].x += j * (*src).cols *0.18;
			rect[i][j].y += i * (*src).rows *0.235;

			temp = (*src)(rect[i][j]);
			square[while_counter] = temp.clone();
			while_counter++;
		}
	}
}

void GetColor::showGetColorArea(Mat *src)
{
	int cntr = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cntr++;
			sprintf(text, "%d", cntr);

			Point pkt(rect[i][j].x + square[0].rows * 0.25, rect[i][j].y + square[0].cols * 0.75);
			rectangle((*src), rect[i][j], Scalar(0, 0, 0), 2);
			cv::putText((*src), text, pkt, 2, 1, Scalar(0, 0, 0));
		}
	}
}

void GetColor::RGBHist(Mat one_square)
{
	float tmp[] = { 0, 0, 0 };
	float range[] = { 0, 256 };
	const float* histRange = { range };
	maxB = 0; maxG = 0; maxR = 0;
	split(one_square, bgr_planes);

	/// Compute the histograms:
	calcHist(&bgr_planes[0], 1, 0, Mat(), b_hist, 1, &histSize, &histRange, uniform, accumulate);
	calcHist(&bgr_planes[1], 1, 0, Mat(), g_hist, 1, &histSize, &histRange, uniform, accumulate);
	calcHist(&bgr_planes[2], 1, 0, Mat(), r_hist, 1, &histSize, &histRange, uniform, accumulate);

	// Draw the histograms for B, G and R
	int hist_w = 600; int hist_h = 400;
	int bin_w = cvRound((double)hist_w / histSize);

	Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(255, 255, 255));

	/// Normalize the result to [ 0, histImage.rows ]
	normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());

	drawRectangles();

	///////////////////////////
	Mat histogram(500, 700, CV_8UC3);
	histogram.setTo(Scalar(255, 255, 255));
	//histImage.copyTo((histogram)(cv::Rect(48, 80, histImage.cols, histImage.rows)));
	// Y axis
	line(histogram, Point(40, 70), Point(48, 60), Scalar(0, 0, 0), 2, 8, 0);
	line(histogram, Point(56, 70), Point(48, 60), Scalar(0, 0, 0), 2, 8, 0);
	// X axis
	line(histogram, Point(histogram.cols - 130, histogram.rows - 27), Point(histogram.cols - 120, histogram.rows - 19), Scalar(0, 0, 0), 2, 8, 0);
	line(histogram, Point(histogram.cols - 130, histogram.rows - 13), Point(histogram.cols - 120, histogram.rows - 19), Scalar(0, 0, 0), 2, 8, 0);
	line(histogram, Point(histogram.cols - 141, histogram.rows - 13), Point(histogram.cols - 141, histogram.rows - 25), Scalar(0, 0, 0), 2, 8, 0);
	line(histogram, Point(48, histogram.rows - 13), Point(48, histogram.rows - 25), Scalar(0, 0, 0), 2, 8, 0);
	line(histogram, Point(histogram.cols - 141, 80), Point(histogram.cols - 141, histogram.rows - 26), Scalar(210, 210, 210), 1, 8, 0);
	cv::putText(histogram, "0", Point(44, histogram.rows - 2), 1, 0.8, Scalar(0, 0, 0));
	cv::putText(histogram, "255", Point(histogram.cols - 151, histogram.rows - 2), 1, 0.8, Scalar(0, 0, 0));

	char *zzz;
	zzz = new char[3];
	int lll = 16;

	for (float t = 15; t < 225; t += 14.8)
	{
		float xxx;


		sprintf(zzz, "%d", int(lll));
		lll += 16;
		xxx = (t / 256) * 558 + 48;
		line(histogram, Point(xxx, histogram.rows - 13), Point(xxx, histogram.rows - 25), Scalar(0, 0, 0), 2, 8, 0);
		line(histogram, Point(xxx, histogram.rows - 26), Point(xxx, histogram.rows - 419), Scalar(210, 210, 210), 1, 8, 0);
		if (t<100)cv::putText(histogram, zzz, Point(xxx - 7, histogram.rows - 2), 1, 0.8, Scalar(0, 0, 0));
		else cv::putText(histogram, zzz, Point(xxx - 12, histogram.rows - 2), 1, 0.8, Scalar(0, 0, 0));

	}

	for (float t = 0; t <= 400; t += 40)
	{
		//float xxx;

		sprintf(zzz, "%d", int(t));
		line(histogram, Point(42, histogram.rows - 19 - t), Point(54, histogram.rows - 19 - t), Scalar(0, 0, 0), 2, 8, 0);
		if (t>0)line(histogram, Point(55, histogram.rows - 19 - t), Point(histogram.cols - 140, histogram.rows - 19 - t), Scalar(210, 210, 210), 1, 8, 0);
		if (t<10)cv::putText(histogram, zzz, Point(30, histogram.rows - 15 - t), 1, 0.8, Scalar(0, 0, 0));
		else if (t<100)cv::putText(histogram, zzz, Point(22, histogram.rows - 15 - t), 1, 0.8, Scalar(0, 0, 0));
		else cv::putText(histogram, zzz, Point(14, histogram.rows - 15 - t), 1, 0.8, Scalar(0, 0, 0));

	}
	//

	for (int i = 1; i < histSize; i++)
	{
		line(histogram, Point((bin_w*(i - 1)) + 48, hist_h + 80 - cvRound(b_hist.at<float>(i - 1))),
			Point((bin_w*(i)) + 48, hist_h + 80 - cvRound(b_hist.at<float>(i))),
			Scalar(255, 0, 0), 2, 8, 0);


		if (cvRound(b_hist.at<float>(i)) > tmp[0])
		{
			tmp[0] = cvRound(b_hist.at<float>(i));
			distance[0] = i;
		}

		line(histogram, Point(bin_w*(i - 1) + 48, hist_h + 80 - cvRound(g_hist.at<float>(i - 1))),
			Point(bin_w*(i)+48, hist_h + 80 - cvRound(g_hist.at<float>(i))),
			Scalar(0, 255, 0), 2, 8, 0);


		if (cvRound(g_hist.at<float>(i)) > tmp[1])
		{
			tmp[1] = cvRound(g_hist.at<float>(i));
			distance[1] = i;
		}

		line(histogram, Point(bin_w*(i - 1) + 48, hist_h + 80 - cvRound(r_hist.at<float>(i - 1))),
			Point(bin_w*(i)+48, hist_h + 80 - cvRound(r_hist.at<float>(i))),
			Scalar(0, 0, 255), 2, 8, 0);


		if (cvRound(r_hist.at<float>(i)) > tmp[2])
		{
			tmp[2] = cvRound(r_hist.at<float>(i));
			distance[2] = i;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		if (tmp[i] == 0)
		{
			distance[i] = 0;
		}
	}

	line(histogram, Point(48, histogram.rows - 19), Point(histogram.cols - 120, histogram.rows - 19), Scalar(0, 0, 0), 2, 8, 0);
	line(histogram, Point(48, 60), Point(48, histogram.rows - 20), Scalar(0, 0, 0), 2, 8, 0);


}

void GetColor::colorClassificationHistRGB(int *wall)
{
	drawRectangles();

	for (int i = 0; i < 9; i++)
	{
		temp_square[i] = square[i].clone();
	}

	hist_counter = 0;
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			if ((*wall) > 5) (*wall) = 5;

			RGBHist((*src)(rect[j][i]));
			// recognition colors rules

			// recognition red and orange and yellow color
			if (distance[2] > distance[1] && distance[2] > distance[0])
			{
				if (abs(distance[0] - distance[1]) < 20)
				{
					if (distance[2] < 40 && distance[1] > 6)
					{
						temp_square[hist_counter].setTo(cv::Scalar(0, 0, 255));
						rubic_colors[(*wall)][hist_counter] = 5; // red
						collllor[hist_counter] = "Red";
					}
					else if (distance[2] < 65 && distance[1] > 12 && distance[0] > 4)
					{
						temp_square[hist_counter].setTo(cv::Scalar(64, 128, 255));
						rubic_colors[(*wall)][hist_counter] = 4; // orange
						collllor[hist_counter] = "Orange";
					}
					else
					{
						temp_square[hist_counter].setTo(cv::Scalar(0, 0, 255));
						rubic_colors[(*wall)][hist_counter] = 5; // red
						collllor[hist_counter] = "Red";
					}
				}
				else if (distance[2] - distance[1] > 40 && distance[0] < 125)
				{
					temp_square[hist_counter].setTo(cv::Scalar(64, 128, 255));
					rubic_colors[(*wall)][hist_counter] = 4; // orange
					collllor[hist_counter] = "Orange";
				}
				else if (distance[2] - distance[1] > 10 && distance[1] - distance[0] > 20)
				{
					temp_square[hist_counter].setTo(cv::Scalar(0, 255, 255));
					rubic_colors[(*wall)][hist_counter] = 3; // yellow
					collllor[hist_counter] = "Yellow";
				}
				else
				{
					temp_square[hist_counter].setTo(cv::Scalar(0, 255, 255));
					rubic_colors[(*wall)][hist_counter] = 3; // yellow
					collllor[hist_counter] = "Yellow";
				}
			}
			// recognition grenn  and white color
			else if (distance[1] > distance[0] && distance[1] > distance[2]
				&& abs(distance[1] - distance[2]) > 6)
			{
				if ((abs(distance[0] - distance[1]) < 10 && abs(distance[1] - distance[2]) < 10)
					|| (abs(distance[0] - distance[2]) < 10 && abs(distance[1] - distance[2]) < 10)
					|| (abs(distance[0] - distance[1]) < 10 && abs(distance[0] - distance[2]) < 10))
				{
					temp_square[hist_counter].setTo(cv::Scalar(255, 255, 255));
					rubic_colors[(*wall)][hist_counter] = 1; // white
					collllor[hist_counter] = "White";
				}
				else
				{
					temp_square[hist_counter].setTo(cv::Scalar(0, 255, 0));
					rubic_colors[(*wall)][hist_counter] = 0; // green
					collllor[hist_counter] = "Grenn";
				}
			}

			//recognition white  and yellow color//
			else if (abs(distance[2] - distance[1]) < 40 && abs(distance[0] - distance[1]) < 40)
			{
				if (distance[2] - distance[1] > 6 && distance[1] - distance[0] > 15 && distance[2] > 80)
				{
					temp_square[hist_counter].setTo(cv::Scalar(0, 255, 255));
					rubic_colors[(*wall)][hist_counter] = 3; // yellow
					collllor[hist_counter] = "Yellow";
				}
				else
				{
					temp_square[hist_counter].setTo(cv::Scalar(255, 255, 255));
					rubic_colors[(*wall)][hist_counter] = 1; // white
					collllor[hist_counter] = "White";
				}
			}
			// recognition blue color
			else if (distance[0] > distance[1] && distance[1] > distance[2]
				&& distance[0] - distance[1] > 15)
			{
				temp_square[hist_counter].setTo(cv::Scalar(255, 0, 0));
				rubic_colors[(*wall)][hist_counter] = 2;// blue
				collllor[hist_counter] = "Blue";
			}
			else
			{
				if (abs(distance[1] - distance[2]) < 10)
				{
					temp_square[hist_counter].setTo(cv::Scalar(0, 255, 255));
					rubic_colors[(*wall)][hist_counter] = 3; // yellow
					collllor[hist_counter] = "Yellow";
				}
				else
				{
					temp_square[hist_counter].setTo(cv::Scalar(255, 255, 255));
					rubic_colors[(*wall)][hist_counter] = 1; // white 
					collllor[hist_counter] = "White";
				}
			}
			if(hist_counter < 9)hist_counter++;
		}
	}
	drawRubicWall(temp_square, 0, 0);
}

void GetColor::colorClassificationRGB(int *wall)
{
	Scalar lowerB = Scalar(90, 40, 0);
	Scalar upperB = Scalar(255, 149, 160);

	Scalar lowerG = Scalar(50, 100, 0);
	Scalar upperG = Scalar(180, 255, 140);

	Scalar lowerP = Scalar(30, 90, 200);
	Scalar upperP = Scalar(170, 160, 255);

	Scalar lowerY = Scalar(0, 150, 160);
	Scalar upperY = Scalar(180, 255, 255);

	Scalar lowerW = Scalar(220, 220, 220);
	Scalar upperW = Scalar(255, 255, 255);

	Scalar lowerR = Scalar(0, 0, 120);
	Scalar upperR = Scalar(110, 70, 255);


	for (int i = 0; i < 9; i++)
	{
		temp_square[i] = square[i].clone();
	}


	for (__int8 j = 0; j < 9; j++)
	{
		if (color[j][0] >= lowerB[0] && color[j][1] >= lowerB[1] && color[j][2] >= lowerB[2] &&
			color[j][0] <= upperB[0] && color[j][1] <= upperB[1] && color[j][2] <= upperB[2])
		{
			rubic_colors[(*wall)][j] = 2;// blue
			temp_square[j].setTo(cv::Scalar(255, 0, 0));
			cout << "Square nr." << int(j) + 1 << " is blue" << endl;
			collllor[j] = "Blue";
		}

		if (color[j][0] >= lowerW[0] && color[j][1] >= lowerW[1] && color[j][2] >= lowerW[2] &&
			color[j][0] <= upperW[0] && color[j][1] <= upperW[1] && color[j][2] <= upperW[2])
		{
			rubic_colors[(*wall)][j] = 1; // white
			temp_square[j].setTo(cv::Scalar(255, 255, 255));
			cout << "Square nr." << int(j) + 1 << " is white" << endl;
			collllor[j] = "White";
		}

		if (color[j][0] >= lowerG[0] && color[j][1] >= lowerG[1] && color[j][2] >= lowerG[2] &&
			color[j][0] <= upperG[0] && color[j][1] <= upperG[1] && color[j][2] <= upperG[2])
		{
			rubic_colors[(*wall)][j] = 0; // green
			temp_square[j].setTo(cv::Scalar(0, 255, 0));
			cout << "Square nr." << int(j) + 1 << " is green" << endl;
			collllor[j] = "Grenn";
		}

		if (color[j][0] >= lowerP[0] && color[j][1] >= lowerP[1] && color[j][2] >= lowerP[2] &&
			color[j][0] <= upperP[0] && color[j][1] <= upperP[1] && color[j][2] <= upperP[2])
		{
			rubic_colors[(*wall)][j] = 4; // orange
			temp_square[j].setTo(cv::Scalar(64, 128, 255));
			cout << "Square nr." << int(j) + 1 << " is orange" << endl;
			collllor[j] = "Orange";
		}

		if (color[j][0] >= lowerY[0] && color[j][1] >= lowerY[1] && color[j][2] >= lowerY[2] &&
			color[j][0] <= upperY[0] && color[j][1] <= upperY[1] && color[j][2] <= upperY[2])
		{
			rubic_colors[(*wall)][j] = 3; // yellow
			temp_square[j].setTo(cv::Scalar(0, 255, 255));
			cout << "Square nr." << int(j) + 1 << " is yellow" << endl;
			collllor[j] = "Yellow";
		}

		if (color[j][0] >= lowerR[0] && color[j][1] >= lowerR[1] && color[j][2] >= lowerR[2] &&
			color[j][0] <= upperR[0] && color[j][1] <= upperR[1] && color[j][2] <= upperR[2])
		{
			rubic_colors[(*wall)][j] = 5; // red
			temp_square[j].setTo(cv::Scalar(0, 0, 255));
			cout << "Square nr." << int(j) + 1 << " is red" << endl;
			collllor[j] = "Red";
		}

	}

	drawRubicWall(temp_square, 0, 0);


}

void GetColor::drawRubicWall(Mat square[9], int x_poz, int y_poz)
{
	int c = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			color_rect[i][j].x = x_poz;
			color_rect[i][j].y = y_poz + 5;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			color_rect[i][j].x += j * square[c].rows;
			color_rect[i][j].y += i * square[c].rows - 5;
			Point pkt(color_rect[i][j].x + square[c].rows * 0.05, color_rect[i][j].y + square[c].cols * 0.95);
			square[c].copyTo((*src)(cv::Rect(x_poz + j * square[i].cols, y_poz + +i * square[i].rows, square[i].cols, square[i].rows)));
			rectangle((*src), Rect(x_poz + j * square[i].cols, y_poz + i * square[i].rows, square[i].cols, square[i].rows), Scalar(0, 0, 0), 2);
			cv::putText((*src), collllor[c], pkt, 1, square[c].rows * 0.015, Scalar(0, 0, 0));
			c++;
		}
	}
}


void GetColor::organizeTabColor(int **color, int *cmp_color)
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			organize_color[i][j] = color[i][j];
		}
	}

	// first wall
	for (int j = 0; j < 9; j++)
	{
		color[0][j] = organize_color[1][j];		
	}
	cmp_color[0] = organize_color[1][4];

	// second wall wall
	color[1][0] = organize_color[5][2];
	color[1][1] = organize_color[5][5];
	color[1][2] = organize_color[5][8];
	color[1][3] = organize_color[5][1];
	color[1][4] = organize_color[5][4];
	color[1][5] = organize_color[5][7];
	color[1][6] = organize_color[5][0];
	color[1][7] = organize_color[5][3];
	color[1][8] = organize_color[5][6];
	cmp_color[1] = organize_color[5][4];

	// third wall
	for (int j = 0; j < 9; j++)
	{
		color[2][j] = organize_color[0][j];
	}
	cmp_color[2] = organize_color[0][4];

	// fourth wall
	color[3][0] = organize_color[4][6];
	color[3][1] = organize_color[4][3];
	color[3][2] = organize_color[4][0];
	color[3][3] = organize_color[4][7];
	color[3][4] = organize_color[4][4];
	color[3][5] = organize_color[4][1];
	color[3][6] = organize_color[4][8];
	color[3][7] = organize_color[4][5];
	color[3][8] = organize_color[4][2];
	cmp_color[3] = organize_color[4][4];

	// fifth wall
	color[4][0] = organize_color[2][6];
	color[4][1] = organize_color[2][3];
	color[4][2] = organize_color[2][0];
	color[4][3] = organize_color[2][7];
	color[4][4] = organize_color[2][4];
	color[4][5] = organize_color[2][1];
	color[4][6] = organize_color[2][8];
	color[4][7] = organize_color[2][5];
	color[4][8] = organize_color[2][2];
	cmp_color[4] = organize_color[2][4];

	// sixth wall
	color[5][0] = organize_color[3][2];
	color[5][1] = organize_color[3][5];
	color[5][2] = organize_color[3][8];
	color[5][3] = organize_color[3][1];
	color[5][4] = organize_color[3][4];
	color[5][5] = organize_color[3][7];
	color[5][6] = organize_color[3][0];
	color[5][7] = organize_color[3][3];
	color[5][8] = organize_color[3][6];
	cmp_color[5] = organize_color[3][4];

}

//if ((src.at<Vec3b>(i, j)[0] < BLACK) && (src.at<Vec3b>(i, j)[1] < BLACK) && (src.at<Vec3b>(i, j)[2] < BLACK))
//{
//	black_counter++;
//	if (black_counter >= (src.rows * src.cols)) black_counter *= 0.5;
//}
//else
//{