#pragma once
#include "Panel.h"

class aAnimation1 {
private:
	int x = 0;
	int y = 0;
	vector<int> xVals;
	vector<int> yVals;
	vector<int> xVels;
	vector<int> yVels;
	vector<Shape*> shapes;
	int width = 40;
	int height = 20;
	int xVel = 1;
	int yVel = 1;
	int panelWidth = 200;
	int panelHeight = 60;
	Panel panel;
	int numberOfShapes = 5;
public:
	aAnimation1(int dummy) {
		int magnitude = 2;
		for (int i = 0; i < numberOfShapes; i++) {
			float r1 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (panelWidth - width)));
			float r2 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (panelHeight - height)));
			float r3 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 4));
			float r4 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 4));
			float r5 = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 26));
			r1++;r2++;r3--;r3--;r4--;r4--;
			xVals.push_back(r1);
			yVals.push_back(r2);
			xVels.push_back(r3);
			yVels.push_back(r4);
			shapes.push_back(new Rectangle(xVals[i], yVals[i], width, height, char(int(65 + r5))));
		}
		panel = Panel(0, 0, panelWidth, panelHeight);
		while (true) {
			// std::this_thread::sleep_for(std::chrono::milliseconds(1));
			panel.clear();
			update();
			panel.repaint();
		}
	}

	void update() {
		Rectangle background(0, 0, panelWidth, panelHeight, '.');
		panel.addShape(background);
		for (int i = 0; i < numberOfShapes; i++) {
			shapes[i] = new Ellipse(xVals[i], yVals[i], width, height, shapes[i]->getColor());
			panel.addShape(*shapes[i]);
			if (xVals[i] + width > panelWidth) xVels[i] *= -1;
			if (xVals[i] < 0) xVels[i] *= -1;
			if (yVals[i] + height > panelHeight - 1) yVels[i] *= -1;
			if (yVals[i] < 0) yVels[i] *= -1;
			xVals[i] += xVels[i];
			yVals[i] += yVels[i];
		}
	}
};
