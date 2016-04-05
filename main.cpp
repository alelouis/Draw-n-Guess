#include <Header.h>
using namespace std;

int main()
{
    
    
    
    FFN *DIGITnetwork = new FFN();
    DIGITnetwork->initFFN(44, 10, 10);
    
    vector<vector<float>> Xapp = readMatFromFile("/Users/Alexis/Documents/SFML/Draw-n-Guess/sfmlMac/Xapp.txt");
    vector<vector<float>> Ta = readMatFromFile("/Users/Alexis/Documents/SFML/Draw-n-Guess/sfmlMac/TA.txt");
    vector<vector<float>> Xtest = readMatFromFile("/Users/Alexis/Documents/SFML/Draw-n-Guess/sfmlMac/Xtest.txt");
    vector<vector<float>> Tt = readMatFromFile("/Users/Alexis/Documents/SFML/Draw-n-Guess/sfmlMac/TT.txt");
    cout << "Training Neural Network... Please Wait..." << endl;
    DIGITnetwork->train_by_iteration(Xapp,Ta,2000);
    
    while(1){
        Draw_window *w = new Draw_window();
        deque<deque<int>> data32 = *(w->get_draw_mat());
        cout << '\n' << endl;
        deque<deque<int>> data32_centered = center_mat(data32);
        deque<deque<int>> data8 = compress_mat(data32_centered);
        vector<float> draw_variables = pca(normalize(extract_variables(data8)));
        
        DIGITnetwork->sim(draw_variables);
        vector<float> current_output = DIGITnetwork->get_ffn_outputs();
        
        cout << "Best Guess : " << distance(current_output.begin(),
                         max_element(current_output.begin(),
                                     current_output.end()))<< endl;
    }
    return 0;
}