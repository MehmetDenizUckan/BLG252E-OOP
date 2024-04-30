#include <iostream>
#include <string>

using namespace std;


// thx for the hw I love the overall concept I learned a lot from it

class Plant {
protected:
    string name;
    int megawatts;
    int year;

public:
   
    Plant(string name, int megawatts, int year) : name(name), megawatts(megawatts), year(year) {}

    // Pure virtual function
    virtual void plot() = 0;


    // although not in the hw I made a destructor to prevent memory leaks pls dont downgrade me for this
    virtual ~Plant() {};
};

class Coal : public Plant {
private:
    float carbon;

public:
    
    Coal(string name, int megawatts, int year, float carbon) : Plant(name, megawatts, year), carbon(carbon) {}

    void plot() {
        cout << name << "\t" << megawatts << "\t";
        for(int i = 0; i < megawatts / 10; i++) {
            cout << char(254);
        }
        
        cout << endl;
    }
};

class Hydro : public Plant {
private:
    int height;

public:

    Hydro(string name, int megawatts, int year, int height) : Plant(name, megawatts, year), height(height) {}

    void plot() {
        cout << name <<"\t" << megawatts << "\t";
        for(int i = 0; i < megawatts / 100; i++) {
            cout << char(177);
        }
        
        cout << endl;
   
    }
};

int main() {
    // Define polymorphic arrays of pointers for Coal and Hydro plants
    Plant* coal_array[8]; 
    Plant* hydro_array[5]; 

    // Data for Coal plants
    string coal_names[] = {"Baihetan", "Xiangji", "Laisalmer", "Nyabarongo", "Vainey", "Gateway", "Vindhyachal", "Taichung"};
    int coal_years[] = {2024, 2022, 2023, 2024, 2023, 2023, 2023, 2024};
    int coal_megawatts[] = {450, 51, 210, 365, 660, 405, 520, 70};
    float coal_carbons[] = {6.21, 5.37, 5.32, 5.51, 4.00, 5.18, 5.92, 6.13};

    // Create objects of Coal plants using a loop
    for (int i = 0; i < 8; ++i) {
        coal_array[i] = new Coal(coal_names[i], coal_megawatts[i] ,coal_years[i], coal_carbons[i]);
    }

    // Data for Hydro plants
    string hydro_names[] = {"Yeongheung", "Kashiwazaki", "Coulee", "Hongyanhe", "Polaniec"};
    int hydro_years[] = {2023, 2022, 2023, 2024, 2022};
    int hydro_megawatts[] = {1800, 1330, 1209, 702, 672};
    int hydro_heights[] = {173, 210, 135, 195, 63};

    // Create objects of Hydro plants using a loop
    for (int i = 0; i < 5; ++i) {
        hydro_array[i] = new Hydro(hydro_names[i], hydro_megawatts[i] ,hydro_years[i], hydro_heights[i]);
    }

    
    float total_carbon = 0.0;
    cout << "COAL ELECTRIC PLANTS" << endl;
    cout << " " << endl;
    for (int i = 0; i < 8; ++i) {
        coal_array[i]->plot();
        total_carbon += coal_carbons[i];
  }
    float average_carbon = total_carbon / 8;

    cout << "Average Carbon Rate " << average_carbon << endl;
    cout << " " << endl;
    cout << " " << endl;
    float total_height = 0.0;

    cout << "HYDRO ELECTRIC PLANTS" << endl;
    cout << " " << endl;
    for (int i = 0; i < 5; ++i) {
        hydro_array[i]->plot();
        total_height += hydro_heights[i];
    }
    float average_hydro = total_height/ 5;

    cout << "Average Dam Height " << average_hydro << endl;

    cout << " " << endl;
    cout << " " << endl;
    // set all the elements to zero
   int c_year_counts[3] = {0}; 

    for (int i = 0; i < 8; ++i) {
    if (coal_years[i] == 2022) {
     c_year_counts[0]++;
    } 
    else if (coal_years[i] == 2023) {
        c_year_counts[1]++;
    } 
    else {
    c_year_counts[2]++;
  }
}
    // set all the elements to zero
    int h_year_counts[3] = {0}; 

    for (int i = 0; i < 5; ++i) {
    if (hydro_years[i] == 2022) {
     h_year_counts[0]++;
    } 
    else if (hydro_years[i] == 2023) {
        h_year_counts[1]++;
    } 
    else {
    h_year_counts[2]++;
  }
}
 cout << "HISTOGRAMS FOR YEAR DISTRIBUTION" << endl;
    for(int i ; i<3 ; i++){
    
    if(i == 0){
       int amount = h_year_counts[i] + c_year_counts[i];
       cout << "YEAR 2022" << "\t"<< "("<<amount<<")" << "\t";
       for(int j = 0 ; j<=amount ; j++){
            cout << char(219);
       }
    cout << " " << endl;
    cout << " " << endl;
    } 
    if(i == 1){
       int amount = h_year_counts[i] + c_year_counts[i];
       cout << "YEAR 2023" << "\t"<< "("<<amount<<")" << "\t";
       for(int j = 0 ; j<=amount ; j++){
            cout << char(219);
       }
    cout << " " << endl;
    cout << " " << endl;
    } 
    if(i == 2){
       int amount = h_year_counts[i] + c_year_counts[i];
       cout << "YEAR 2024" << "\t"<< "("<<amount<<")" << "\t";
       for(int j = 0 ; j<=amount ; j++){
            cout << char(219);
       }

    } 

    }
    // delete dynamically allocated objects to avoid memory leaks
    for (int i = 0; i < 8; ++i) {
        delete coal_array[i];
    }
    for (int i = 0; i < 5; ++i) {
        delete hydro_array[i];
    }

    return 0;
}
  