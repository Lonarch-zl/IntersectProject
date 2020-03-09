#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
using namespace std;

typedef struct LINE           // 直线的解析方程 a*x+b*y+c=0  为统一表示，约定 a >= 0
{
    double a;
    double b;
    double c;	LINE(double a1 = 1, double b1 = -1, double c1 = 0) { a = a1; b = b1; c = c1; }
}LINE;

const double EP = 1E-10;
// 根据已知两点坐标，求过这两点的直线解析方程： a*x+b*y+c = 0  (a >= 0) 
LINE makeline(double x1,double y1,double x2,double y2)
{
    LINE tl;
    int sign = 1;
    tl.a = y2 - y1;
    if (tl.a < 0) {
        sign = -1;
        tl.a = sign * tl.a;
    }
    tl.b = sign * (x1 - x2);
    tl.c = sign * (y1 * x2 - x1 * y2);
    return tl;
}

typedef struct Point2d
{
    double x;
    double y;

    Point2d(double x1, double y1) { x = x1; y = y1; }

}Point2d;
// 如果两条直线 l1(a1*x+b1*y+c1 = 0), l2(a2*x+b2*y+c2 = 0)相交，返回true，且返回交点p 
bool lineintersect(LINE l1, LINE l2, Point2d &p)
{
    double d = l1.a * l2.b - l2.a * l1.b;
    if (abs(d) < EP)
    {
        return false;
    }
    p.x = (l2.c * l1.b - l1.c * l2.b) / d;
    p.y = (l2.a * l1.c - l1.a * l2.c) / d;
    return true;
}



int calculateCrossPointsNum(vector<LINE> lines)
{
    if (lines.size() < 2)
    {
        return 0;
    }
    vector<Point2d> pnts;
    for (int i = 0; i < lines.size() - 1; i++)
    {
        for (int j = i + 1; j < lines.size(); j++)
        {
            Point2d p(0,0);
            if (lineintersect(lines[i], lines[j], p))
            {
                pnts.push_back(p);
            }
        }
    }

    // 去掉重复点
    for (int i = 0; i < pnts.size() - 1; i++)
    {
        for (int j = i + 1; j < pnts.size(); j++)
        {
            if (pnts[i].x == pnts[j].x && pnts[i].y == pnts[j].y)
            {
                pnts.erase(pnts.begin() + j);
                j--;
            }
        }
    }
    return pnts.size();
}

int main(int argc, char* argv[])
{
    // 输入的直线数据
	ifstream in;
	ofstream out;
	for (int i = 0; i < argc; i++) {
		if ((string)argv[i] == "-i") {
			in.open(argv[i + 1]);
		}
		else if ((string)argv[i] == "-o") {
			out.open(argv[i + 1]);
		}
	}

    int N; // 直线个数
	in >> N;
	
	char ch;
	vector<LINE> lines;
	for (int i = 0; i < N; i++) {
		in >> ch;
		int num1, num2, num3, num4;
		in >> num1 >> num2 >> num3 >> num4;
		LINE line = makeline(num1, num2, num3, num4);
		lines.push_back(line);
	}
    
    /*LINE line1 = makeline(0, 0, 1, 1);
    LINE line2 = makeline(0, 0, 0, 1);
    LINE line3 = makeline(0, 0, -1, 0);

    lines.push_back(line1);
    lines.push_back(line2);
    lines.push_back(line3);*/
	
    int n = calculateCrossPointsNum(lines);

    std::cout << n << endl; 

	out << n;

    return 0;
}


