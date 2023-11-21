// 【问题描述】
// 复数的加减乘除函数原型已给出，要求完成对应的加减乘除函数

// 【编写要求】
// 1. 完成加减乘除4个函数
// 2. 尽可能使用指针表达字符或者字符串，体会指针的用法
// 3. 除法函数中，若除数为0，除法函数返回0并在屏幕上打印Error信息

#include <stdio.h>

typedef struct{
    double real;    // 复数的实部
    double imag;    // 复数的虚部 
} Complex;

void inputComplex(Complex *complex);
void outputComplex(Complex *complex);
void addComplex(const Complex *x, const Complex *y, Complex *result);
void minusComplex(const Complex *x, const Complex *y, Complex *result);
void multiplyComplex(const Complex *x, const Complex *y, Complex *result);
void divComplex(const Complex *x, const Complex *y, Complex *result);

int main() 
{
    Complex complex1, complex2, result;
    Complex *p1 = &complex1, *p2 = &complex2, *pResult = &result;

    //输入两个复数的值
    inputComplex( p1 );
    inputComplex( p2 );

    //计算加减乘除的结果
    addComplex( p1, p2, pResult );
    printf("两个复数相加的结果为：");
    outputComplex( pResult );

    minusComplex( p1, p2, pResult );
    printf("两个复数相减的结果为：");
    outputComplex( pResult );

    multiplyComplex( p1, p2, pResult );
    printf("两个复数相乘的结果为：");
    outputComplex( pResult );

    divComplex( p1, p2, pResult );
    printf("两个复数相除的结果为：");
    outputComplex( pResult );

    return  0;
}

void inputComplex(Complex *complex)
{
    printf("请输入复数的实部和虚部：");
    scanf("%lf%lf", &complex->real, &complex->imag);
    return;
}

void outputComplex(Complex *complex)
{
    if(complex->imag >=0)
    {
        printf("%.2lf+%.2lfi\n", complex->real, complex->imag);
    } else
    {
        printf("%.2lf%.2lfi\n", complex->real, complex->imag);
    }
    return;
}

// 复数加法
void addComplex(const Complex *x, const Complex *y, Complex *res)
{
    // -----------------------------
    // start of your source code
    //
     res->real = x->real + y->real;
        res->imag = x->imag + y->imag;

    //
    // end of your source code
    // -----------------------------
}

// 复数减法
void minusComplex(const Complex *x, const Complex *y, Complex *res)
{
    // -----------------------------
    // start of your source code
    //
    res->real = x->real - y->real;
        res->imag = x->imag - y->imag;

    //
    // end of your source code
    // -----------------------------

}

// 复数乘法
void multiplyComplex(const Complex *x, const Complex *y, Complex *res)
{
    // -----------------------------
    // start of your source code
    //
   res->real = x->real * y->real - x->imag * y->imag;
        res->imag = x->real * y->imag + x->imag * y->real;

    //
    // end of your source code
    // -----------------------------

}

// 复数除法
void divComplex(const Complex *x, const Complex *y, Complex *res)
{
    // -----------------------------
    // start of your source code
    //
     double denominator = y->real * y->real + y->imag * y->imag;
    if (denominator == 0)
    {
        printf("Error: Division by zero\n");
        res->real = 0;
        res->imag = 0;
    }
    else
    {
        res->real = (x->real * y->real + x->imag * y->imag) / denominator;
        res->imag = (x->imag * y->real - x->real * y->imag) / denominator;
    }

    //
    // end of your source code
    // -----------------------------

}
