#include <iostream>
#include <string>
#include<math.h>

using namespace std;

class QuadraticEquation{
public:
    double coef_a;
    double coef_b;
    double coef_c;
    double x1;
    double x2;
    int roots_number;
    
    QuadraticEquation(double coef_a_, double coef_b_, 
    double coef_c_, double x1_, double x2_, int roots_number_){
        coef_a = coef_a_;
        coef_b = coef_b_;
        coef_c = coef_c_;
        x1 = x1_;
        x2 = x2_;
        roots_number = roots_number_;
    }


    void ScanCoefficients ()
    {
        double max_coef = NAN;
        max_coef = Max (abs(coef_a), abs(coef_b));
        max_coef = Max (abs(max_coef), abs(coef_c));
        if (max_coef <= 1e-4)   
            cout << "\nThe introduced equation is equivalent to: %.4fX^2 %+.4fX %+.4f = 0 \n" 
            << coef_a/1e-5 << coef_b/1e-5 << coef_c/1e-5;
        else
            cout << "\nIntroduced equation: %.4fX^2 %+.4fX %+.4f = 0 \n" 
            << coef_a << coef_b << coef_c;
        coef_a /= max_coef;
        coef_b /= max_coef;
        coef_c /= max_coef;
    }

    int SolveQuadratic ()
    {
        double Discriminant = NAN;
        double discriminant_root = NAN;
        Discriminant = coef_b*coef_b - 4*coef_a*coef_c;
        if (EpsilonCompare (Discriminant, 0)){
            x1 = -coef_b/(2*coef_a);
            return 1;
        }
        else
            if (Discriminant > 0)
            {
                discriminant_root = sqrt(Discriminant);
                x1 = (-coef_b - discriminant_root)/(2*coef_a);
                x2 = (-coef_b + discriminant_root)/(2*coef_a);
                return 2;
            }
            else
                return 0;

    }


    int EpsilonCompare (double DBL1, double DBL2)
    {
        double EPSILON = 1e-4;
        if (fabs(DBL1 - DBL2)  < EPSILON)
            return 1;
        else
            return 0;
    }


    int SolveLinear ()
    {
        if(EpsilonCompare(coef_b, 0)||isnanf(coef_c))
            return -1;
        else{
            x1 = -coef_c/coef_b;
            return 1;
        }
    }


    void SolveEquation ()
    {
        if (EpsilonCompare (coef_a, 0)||isnanf(coef_a)){
            roots_number = SolveLinear();
        }
        else
        roots_number = SolveQuadratic();
    }


    void PrintRoots ()
    {
        switch  (roots_number)
        {
        case -1:
            cout << "\nThe equation has infinite number of roots\n";
            break;
        case 0:
            cout << "\nThe equation has no roots\n\n";
            break;
        case 1:
            cout << "\nThe equation has one root: X = %.4f\n\n" << x1;
            break;
        case 2:
            cout << "\nThe equation has two roots: X1 = %.4f and X2 = %.4f\n\n" << x1 << x2;
            break;
        default:
            cout << "\nERROR: unexpected number of roots\n";
        }
    }

    double Max (double a, double b)
    {
        if (a > b)
            return a;
        else
            return b;
    }
};



int main ()
{
    int solve_more = 1;
    while (solve_more == 1)
        {
        double coef_a = NAN;
        double coef_b = NAN;
        double coef_c = NAN;
        double x1 = NAN;
        double x2 = NAN;
        int roots_number = 0;
        
        cin >> coef_a >> coef_b >> coef_c;
        QuadraticEquation qe = {coef_a, coef_b, 
        coef_c, x1, x2, roots_number};
        qe.ScanCoefficients();
        qe.SolveEquation();
        qe.PrintRoots();
        }
}



