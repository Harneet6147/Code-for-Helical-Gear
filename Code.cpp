#include <bits/stdc++.h>
#include <cmath>
using namespace std;
double power, np, gear_ratio, helix_angle, pressure_angle, m, zp = 0, y, sigma_t, BHN, Cs, FOS;
int grade;
long long int C = 11400;

double Pi()
{
    double pi = 2 * acos(0.0);
    return pi;
}

double select_lewis_factor(int z)
{
    if (m == 15)
    {
        y = 0.289;
    }
    if (m == 16)
    {
        y = 0.295;
    }
    if (m == 17)
    {
        y = 0.302;
    }
    if (m == 18)
    {
        y = 0.308;
    }
    if (m == 19)
    {
        y = 0.314;
    }
    if (m == 20)
    {
        y = 0.320;
    }
    if (m == 21)
    {
        y = 0.326;
    }
    if (m == 22)
    {
        y = 0.330;
    }
    if (m == 23)
    {
        y = 0.333;
    }
    if (m == 24)
    {
        y = 0.337;
    }
    if (m == 25)
    {
        y = 0.340;
    }
    if (m == 26)
    {
        y = 0.344;
    }
    if (m == 27)
    {
        y = 0.348;
    }
    if (m == 28)
    {
        y = 0.352;
    }
    if (m == 29)
    {
        y = 0.355;
    }
    if (m == 30)
    {
        y = 0.358;
    }
    if (m == 32)
    {
        y = 0.364;
    }
    if (m == 33)
    {
        y = 0.367;
    }
    if (m == 35)
    {
        y = 0.373;
    }
    if (m == 37)
    {
        y = 0.380;
    }
    if (m == 39)
    {
        y = 0.386;
    }
    if (m == 40)
    {
        y = 0.389;
    }
    if (m == 45)
    {
        y = 0.399;
    }
    if (m == 50)
    {
        y = 0.408;
    }
    if (m == 50)
    {
        y = 0.408;
    }
    if (m == 55)
    {
        y = 0.415;
    }
    if (m == 60)
    {
        y = 0.421;
    }
    if (m == 65)
    {
        y = 0.425;
    }
    if (m == 70)
    {

        y = 0.429;
    }
    if (m == 75)
    {
        y = 0.433;
    }
    if (m == 80)
    {
        y = 0.436;
    }
    if (m == 90)
    {
        y = 0.442;
    }
    if (m == 100)
    {
        y = 0.446;
    }
    if (m == 150)
    {
        y = 0.458;
    }
    if (m == 200)
    {
        y = 0.463;
    }
    if (m == 300)
    {
        y = 0.484;
    }
    return y;
}

double select_Cv(double velocity)
{
    double cv;
    cv = 5.6 / (5.6 + sqrt(velocity));

    return cv;
}

double calc_Pd(double velocity, double e, double Helix, double Pt)
{
    double num = (21 * velocity * (C * e * (10 * m) * pow(cos(Helix), 2) + Pt) * cos(Helix));
    double den = (21 * velocity + (sqrt(C * e * (10 * m) * pow(cos(Helix), 2) + Pt)));

    return (num / den);
}

double calc_e(double phi)
{
    double e;
    if (grade == 1)
    {
        e = 0.8 + 0.06 * phi;
    }
    if (grade == 2)
    {
        e = 1.25 + 0.1 * phi;
    }
    if (grade == 3)
    {
        e = 2 + 0.16 * phi;
    }
    if (grade == 4)
    {
        e = 3.2 + 0.25 * phi;
    }
    if (grade == 5)
    {
        e = 5 + 0.4 * phi;
    }
    if (grade == 6)
    {
        e = 8 + 0.63 * phi;
    }
    if (grade == 7)
    {
        e = 11 + 0.9 * phi;
    }
    if (grade == 8)
    {
        e = 16 + 1.25 * phi;
    }
    if (grade == 9)
    {
        e = 22 + 1.8 * phi;
    }
    if (grade == 10)
    {
        e = 32 + 2.5 * phi;
    }
    if (grade == 11)
    {
        e = 45 + 3.55 * phi;
    }
    if (grade == 12)
    {
        e = 63 + 5.00 * phi;
    }
    return e;
}

double calc_Phi(double d)
{
    return (m + 0.25 * (sqrt(d)));
}

int main()
{
    cout << "Enter the ultimate tensile strength of material:" << endl;
    cin >> sigma_t;
    cout << "Enter the grade of machining:" << endl;
    cin >> grade;
    cout << "Enter the Brinell Hardness Number of:" << endl;
    cin >> BHN;
    cout << "Enter the power produced by gear:" << endl;
    cin >> power;
    cout << "Enter the speed of rotation of pinion in (rpm):" << endl;
    cin >> np;
    cout << "Enter the Gear Ratio:" << endl;
    cin >> gear_ratio;
    cout << "Enter the helix angle (in degrees):" << endl;
    cin >> helix_angle;
    cout << "Enter the pressure angle:" << endl;
    cin >> pressure_angle;
    cout << "Enter the Module:" << endl;
    cin >> m;
    cout << "Enter the Number of teeth of Pinion (if not entered it will be taken as 18):" << endl;
    cin >> zp;
    cout << "Enter the Service factor:" << endl;
    cin >> Cs;

    if (zp == 0)
    {
        zp = 18;
    }
    if (helix_angle == 90)
    {
        cout << "Inavlid";
        return 0;
    }
    sigma_t /= 3;

    double Helix_Angle = helix_angle * Pi() / 180;
    double cos_cube_HelixAngle = cos(Helix_Angle);

    double Mt = (60000000 * power) / (2 * Pi() * np);
    double zg = zp / gear_ratio;
    double z_p = zp / cos_cube_HelixAngle;
    double z_g = zg / cos_cube_HelixAngle;
    double yp = select_lewis_factor(int(z_p)); // Because pinion is weak
    double b = 10 * m;
    double Q = (2 * zg) / (zp + zg);
    double K = 0.16 * (pow(BHN / 100, 2));
    double dp = m * zp;
    double dg = m * zg;
    // Initial condition
    double Sb = m * b * sigma_t * yp; // Beam Strength
    double Sw = b * Q * dp * K;       // Wear Strength
    double Pt = (2 * Mt) / dp;
    double v = (Pi() * dp * np) / (60000);
    double Cv = select_Cv(v);
    double P_eff_Initial = (Cs / Cv) * Pt;
    while (Sb < P_eff_Initial || Sw < P_eff_Initial)
    {
        m++;
        b = 10 * m;
        dp = m * zp;

        Sb = m * b * sigma_t * yp; // Beam Strength
        Sw = b * Q * dp * K;       // Wear Strength
        Pt = (2 * Mt) / dp;
        v = (Pi() * dp * np) / (60000);
        Cv = select_Cv(v);
        P_eff_Initial = (Cs / Cv) * Pt;
        if (m > 5)
        {
            break;
        }
    }
    // Now gear is safe for initial condition

    // Final condition
    double Phi_p = calc_Phi(dp);
    double Phi_g = calc_Phi(dg);
    double e = calc_e(Phi_p) + calc_e(Phi_g);
    double Pd = calc_Pd(v, e, Helix_Angle, Pt);

    double P_eff_Final = (Cs * Pt) + Pd;

    while (Sb < P_eff_Final || Sw < P_eff_Final)

    {
        grade++;
        Phi_p = calc_Phi(dp);
        Phi_g = calc_Phi(dg);
        e = calc_e(Phi_p) + calc_e(Phi_g);
        Pd = calc_Pd(v, e, Helix_Angle, Pt);
        P_eff_Final = Cs * Pt + Pd;
        if (grade > 12)
        {
            break;
        }
    }
    // Now gear is safe for final condition

    cout << "\n\n\n";
    cout << "Design of helical gear is safe for the following specifications:->" << endl;
    cout << "Number of teeth on pinion: " << zp << endl;
    cout << "Number of teeth on gear: " << int(ceil(zg)) << endl;
    cout << "Module: " << m << endl;
    cout << "Face width: " << 10 * m << endl;
    cout << "Pitch circle diameter of pinion: " << dp << "mm" << endl;
    cout << "Pitch circle diameter of gear: " << m * zg << "mm" << endl;
    cout << "Addendum: " << m << "mm" << endl;
    cout << "Dedendum: " << 1.25 * m << "mm" << endl;
    cout << "Clearance: " << 0.25 * m << "mm" << endl;
    cout << "Tooth thickness: " << 1.5708 * m << "mm" << endl;
    cout << "Fillet Radius: " << 1.6 * m << "mm" << endl;
}
