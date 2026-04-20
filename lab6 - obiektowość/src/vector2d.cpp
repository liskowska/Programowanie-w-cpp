#include <string>
#include<sstream>

using namespace std;

class Vector2d{
    private:
        int x_;
        int y_;

    public:
    int x() {return x_;}
    int y() {return y_;}

    void x(int new_x){x_ = new_x;}
    void y(int new_y){y_ = new_y;}
    void vector2d(int new_x, int new_y){
        x_ = new_x;
        y_ = new_y;
    }

    bool operator==(Vector2d other){
        if (x_ == other.x_ && y_ == other.y_) return true;
        else return false;
    }

    string toString(){
        ostringstream oss;
        oss << "(" << x_ << ", "<< y_ << ")";
        return oss.str();
    }

    bool precedes(Vector2d other) {
        return (x_ <= other.x_ && y_ <= other.y_);
    }

    bool follows(Vector2d other) {
        return x_ >= other.x_ && y_ >= other.y_;
    }

    Vector2d add(Vector2d other) {
        Vector2d vector2d;
        vector2d.x(x_ + other.x_);
        vector2d.y(y_ + other.y_);
        return vector2d;
    }

    Vector2d substract(Vector2d other) {
        Vector2d vector2d;
        vector2d.x(x_ - other.x_);
        vector2d.y(y_ - other.y_);
        return vector2d;    
    }

    Vector2d upperRight(Vector2d other) {
        int x = x_;
        int y = y_;

        if (other.x_ > x)
            x = other.x_;
        if (other.y_ > y)
            y = other.y_;

        Vector2d vector2d;
        vector2d.x_ = x;
        vector2d.y_ = y;

        return vector2d;
    }

    Vector2d lowerLeft(Vector2d other) {
        int x = x_;
        int y = y_;
        if (other.x_ < x)
            x = other.x_;
        if (other.y_ < y)
            y = other.y_;

        Vector2d vector2d;
        vector2d.x_ = x;
        vector2d.y_ = y;

        return vector2d;
    }

    Vector2d opposite() {
        int x = -x_;
        int y = -y_;

        Vector2d vector2d;
        vector2d.x_ = x;
        vector2d.y_ = y;

        return vector2d;
    }
};



















