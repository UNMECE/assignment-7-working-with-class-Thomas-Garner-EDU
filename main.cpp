#include <iostream>
#include <cmath>


class Electric_Field{
    private:
        double *E;
    public:
        //default constructor
        Electric_Field(){E = new double[3]{0,0,0};}
        
        //parameterized
        Electric_Field(double Ex, double Ey, double Ez){
            E = new double[3];
            E[0] = Ex;
            E[1] = Ey;
            E[2] = Ez;
        }
        
        //deconstructor
        ~Electric_Field(){delete[] E; E = nullptr;}
    
        //setters
        void setEx(double Ex){E[0] = Ex;}
        void setEy(double Ey){E[1] = Ey;}
        void setEz(double Ez){E[2] = Ez;}

        //getters
        double getEx(){return E[0];}
        double getEy(){return E[1];}
        double getEz(){return E[2];}
        
        //magnitude
        double magE(){
            double x2 = std::pow(getEx(), 2.0);
            double y2 = std::pow(getEy(), 2.0);
            double z2 = std::pow(getEz(), 2.0);
            return sqrt(x2 + y2 + z2);
        }
        //inner product
        double innerE(){
            return (std::pow(getEx(), 2.0) + std::pow(getEy(), 2.0) + std::pow(getEz(), 2.0));
        }

};

class Magnetic_Field{
    private:
        double *B;
    public:
        //default constructor
        Magnetic_Field(){B = new double[3]{0,0,0};}
        
        //parameterized
         Magnetic_Field(double Bx, double By, double Bz){
            B = new double[3];
            B[0] = Bx;
            B[1] = By;
            B[2] = Bz;
        }

        //deconstructor
        ~Magnetic_Field(){delete[] B; B = nullptr;}

        //setters
        void setBx(double Bx){B[0] = Bx;}
        void setBy(double By){B[1] = By;}
        void setBz(double Bz){B[2] = Bz;}

        //getters
        double getBx(){return B[0];}
        double getBy(){return B[1];}
        double getBz(){return B[2];}
        
        //magnitude
        double magB(){
            double x2 = std::pow(getBx(), 2.0);
            double y2 = std::pow(getBy(), 2.0);
            double z2 = std::pow(getBz(), 2.0);
            return sqrt(x2 + y2 + z2);

        }

        //unit vector
        double* unitVB(){
            double bMag = magB();

            double* uVector = new double[3];

            // Prevent division by zero
            if (bMag == 0.0) {
                uVector[0] = 0.0;
                uVector[1] = 0.0;
                uVector[2] = 0.0;
            } else {
                uVector[0] = getBx() / bMag;
                uVector[1] = getBy() / bMag;
                uVector[2] = getBz() / bMag;
            }

            return uVector;
        }

};

int main(){

    Electric_Field E_default;
    Electric_Field E_components(3e5, 200.4, 1.63e6);
    E_components.setEx(2e5);
    Magnetic_Field B_default;
    Magnetic_Field B_components(1e3, 18.2, 1.1e3);
    B_components.setBz(2.2e3);
    //E field outputs
    std::cout<<"E_default magnitude: "<<E_default.magE()<<std::endl;
    std::cout<<"E_default inner product: "<<E_default.innerE()<<std::endl;
    std::cout<<"E_components magnitude: "<<E_components.magE()<<std::endl;
    std::cout<<"E_components inner product: "<<E_components.innerE()<<std::endl;
    //B field outputs
    std::cout<<"B_default magnitude: "<<B_default.magB()<<std::endl;
    double* default_UnitB = B_default.unitVB();
    std::cout << "B_default unit vector: [" 
              << default_UnitB[0] << ", " 
              << default_UnitB[1] << ", " 
              << default_UnitB[2] << "]" << std::endl;

    delete[] default_UnitB; 
    default_UnitB = nullptr;
    std::cout<<"B_components magnitude: "<<B_components.magB()<<std::endl;
    double* unitB = B_components.unitVB();
    std::cout << "B_components unit vector: ["
              << unitB[0] << ", "
              << unitB[1] << ", "
              << unitB[2] << "]" << std::endl;

    delete[] unitB; 
    unitB = nullptr;

    return 0;

}
