#include "Header.h"
using namespace std;

int main()
{
    vector<vector<float>> new_var_data;
    vector<float> new_T_data;
    
    Draw_window *w = new Draw_window();
    float t=0; //Digit to learn
    for(int i=0;i<100;i++){ // 100 : How many digits to draw
        w->set_active(true);
        w->run();
        cout << i << endl;
        deque<deque<int>> data32 = *(w->get_draw_mat());
        deque<deque<int>> data32_centered = center_mat(data32);
        deque<deque<int>> data8 = compress_mat(data32_centered);
        vector<float> newvar = extract_variables(data8);
        new_var_data.push_back(newvar);
        new_T_data.push_back(t);
    }
    
    write_vec_to_file(new_T_data, "newT.txt");  //All t vector
    write_mat_to_file(new_var_data, "newX.txt");// Extracted variables
    return 0;
}
