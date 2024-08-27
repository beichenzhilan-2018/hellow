#include <iostream>
#include <fstream>
using namespace std;

//图像类的定义
class pic
{
     public:
    int wide;
    int high;

    //成员函数
    void set(int w, int h);//指定宽高
    void print(int data[0][0], int w, int h);//画出图像
    void ispicempty(int data[0][0], int w, int h);//判断图像是否为空
    void iszero(int data[0][0], int a, int b);//二值化输出
    void savefile(int data[0][0], int w, int h);//文件保存
    void changepit(int data[0][0],int X, int Y, int VALUE);//更改指定的像素点
    void kuang(int data[0][0], int X, int Y, int W,  int H, int VALUE);//画框
    void thr(int data[0][0], int a, int b, int THR);//阀值化
    void fan(int data[0][0], int w, int h);//左右翻转
    void xuan(int data[0][0], int w, int h);//顺时针旋转90度
};

//指定图像宽度w和高度h
void pic::set(int w, int h)
{
    wide=w;
    high=h;
}

//判断图像是否为空
void ispicempty(int data[0][0], int a, int b)
{
    for (int i=0; i<a; i++)
    {
        for (int j=0; j<b; j++)
        {
            if (data[i][j]!=0) 
            {
                cout << "图像不为空" << endl;
                break;
            }
            else
            {
                cout << "图像为空" << endl;
                break;
            };
        };
    };
}

//画出图像，并以行列排布的形式输出
void print(int data[0][0], int a, int b)
{
    for (int i=0; i<a; i++)
    {
        for (int j=0; j<b; j++)
        {
            cout << data[i][j] << endl;
        };
        //以行列排布形式输出
        cout << "\n" << endl;
    };
}

//二值化显示，等于0输出'.'，不等于0输出‘O’
void iszero(int data[0][0], int a, int b)
{
    if(data[a][b] == 0)
    {
        cout << "." << endl;
    }
    else
    {
        cout << "O" << endl;
    }
}

//打开文件，并保存文件
void savefile(int data[0][0], int a, int b)
{
    //打开文件
    ofstream outfile;
    outfile.open ("pic.txt");
    //写入文件
    for (int i=0; i<a; i++)
    {
        for (int j=0; j<b; j++)
        {
            outfile << data[i][j] << endl;
        };
    };
    //关闭文件
    outfile.close();
}

//绘制点
void changepit(int data[0][0], int X, int Y, int VALUE)
{
    int*a = &data[X][Y];
    *a=VALUE;
}

//绘制框
void kuang(int data[0][0], int X, int Y, int W,  int H, int VALUE)
{
    for(int i=X; i<=(X+W); i++)
    {
        data[i][Y]=VALUE;
        data[i][Y+H]=VALUE;
        cout << data[i][Y] <<  data[i][Y+H] << endl;
    };

    for(int i=Y; i<=(Y+H); i++)
    {
        data[X][i]=VALUE;
        data[X+W][i]=VALUE;
        cout << data[X][i] <<  data[X+W][i]  << endl;
    };
}

//阀值化 使得图像中小于等于THR的值全部变为0
void thr(int data[0][0], int a, int b, int THR)
{
    cout << "输入THR" << endl ;
    cin >> THR;
    for (int i=0; i<a; i++)
    {
        for (int j=0; j<b; j++)
        {
            if(data[i][j] <= THR )
            {
                data[i][j] = 0;
            }
        };
    };
}

//左右翻转
void fan(int data[0][0], int w, int h)
{
    int tmp;
    for (int i=0; i<h; i++)
    {
        for (int j=0; j<(w/2); j++)
        {
            int tmp = data[j][i];
            data[j][i] = data [(w-j)][i];
            data[(w-j)][i] = tmp;
        };
    };
}

//顺时针90度旋转
void xuan(int data[0][0], int w, int h)
{
    int k;
    if (w>=h)
    {
        k=w;
    }
    else
    {
        k=h;
    }
    for(int i=0; i<k; i++)
    {
        for (int j=0; j< k; j++)
        {
            data[j][k-i-1]=data[i][j];
        }
    };
}

int main()
{ 
    //使用类创建图形
    pic A;
    A.set(5,7);
    int B[5][7]={};
    //修改除（0，0）外的其他边缘点为255
    A.kuang(B, 5, 7, 5, 7, 255);
    A.changepit(B, 0, 0, 0);
    //显示修改后的图像
    A.print(B, 5, 7);
    return 0;
    //上下翻转：一次左右翻，两次顺时针旋转
    A.fan(B, 5, 7);
    A.xuan(B, 5, 7);
    A.xuan(B, 5, 7);
    A.print(B, 5, 7);

    return 0;
}