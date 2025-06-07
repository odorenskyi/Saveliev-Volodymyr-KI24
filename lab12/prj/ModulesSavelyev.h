#ifndef MODULESSAVELYEV_H
#define MODULESSAVELYEV_H

class ClassLab12_Savelyev {
private:
    float length;
    float width;
    float height;

public:
    ClassLab12_Savelyev() : length(0), width(0), height(0) {}

    void setA(float value) { length = value; }   
    void setB(float value) { width = value; }    
    void setH(float value) { height = value; }

    float getSurfaceArea() {
        return 2 * (length * width + length * height + width * height); 
    }
};

#endif