#include <Header.h>
using namespace std;

int main()
{
    Draw_window *w = new Draw_window();
    deque<deque<int>> data32 = *(w->get_draw_mat());
    cout << '\n' << endl;
    deque<deque<int>> data32_centered = center_mat(data32);
    deque<deque<int>> data8 = compress_mat(data32_centered);
    vector<float> variables = extract_variables(data8);
    //affiche_mat(data8,8,8);
    for(int i=0;i<variables.size();i++){
        cout << " " << variables[i] << endl;
    }
    cout << "norm";
    vector<float> norm_variables = normalize(variables);
    for(int i=0;i<norm_variables.size();i++){
        cout << " " << norm_variables[i] << endl;
    }
    cout << "pca";
    vector<float> pca_variables = pca(norm_variables);
    for(int i=0;i<pca_variables.size();i++){
        cout << " " << pca_variables[i] << endl;
    }
}