#include <bits/stdc++.h>

using namespace std;

class Car
{
    private:
        string make;
        string model;
        int year;
        int speed_x;
        int speed_y;
        int speed_z;
        int x;
        int y;
        int z;
    public:
        Car(string make, string model, int year, int speed_x, int speed_y, int speed_z, int x, int y, int z)
       {
            this->make = make;
            this->model = model;
            this->year = year;
            this->speed_x = speed_x;
            this->speed_y = speed_y;
            this->speed_z = speed_z;
            this->x = x;
            this->y = y;
            this->z = z;
        }
        //to increase speed in x axis
        void accelerate_x(int speed_increment)
        {
            this->speed_x += speed_increment;
        }
        //to increase speed in y axis
        void accelerate_y(int speed_increment)
        {
            this->speed_y += speed_increment;
        }
        //to increase speed in z axis
        void accelerate_z(int speed_increment)
        {
            this->speed_z += speed_increment;
        }
        //to decrease speed of car
        void brake_x(int speed_decrement)
        {
            this->speed_x -= speed_decrement;
        }

        void brake_y(int speed_decrement)
        {
            this->speed_y -= speed_decrement;
        }
        
        void brake_z(int speed_decrement)
        {
            this->speed_z -= speed_decrement;
        }
        //move function takes the time and updates the car's position after that time.
        void move(int time)
        {
            this->x += speed_x*time;
            this->y += speed_y*time;
            this->z += speed_z*time;
        }
        //return true if two cars collide otherwise return false
        bool detect_collision(Car car2)
        {
            int dx = this->x - car2.x;
            int dy = this->y - car2.y;
            int dz = this->z - car2.z;
            if (dx == 0 && dy == 0 && dz == 0)
            { 
                return true;
            }
            else
            {
                return false;
            }
        }
        double time_to_collision(Car car2)
        {
            double rel_speed_x = speed_x - car2.speed_x;
            double rel_speed_y = speed_y - car2.speed_y;
            double rel_speed_z = speed_z - car2.speed_z;
            double dist_x = car2.x - x;
            double dist_y = car2.y - y;
            double dist_z = car2.z - z;
            if ((dist_x/rel_speed_x)==(dist_y/rel_speed_y) && (dist_y/rel_speed_y)==(dist_z/rel_speed_z))
            {
                return (dist_y/rel_speed_y);
            }
            else return -1;
        }
    };
    int main()
    {
        Car car1("BMW", "City", 2021, 1, 3, 2, 90, 90, 90);
        Car car2("Maruti", "Alto", 2020, 4, 5, 3, 60, 70, 75);
        
        double ttc = car1.time_to_collision(car2);
        if (ttc >= 0)
        {
            cout << "Time for collision: " << ttc << " seconds" << endl;
        }
        else
        {
            cout << "No collision possible." << endl;
        }
        car1.move(6);
        car2.move(6);
        if(car1.detect_collision(car2))
        {
            cout<<"Colloided"<<endl;
        }
        return 0;
}
