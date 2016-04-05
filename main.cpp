#include <Header.h>
using namespace std;

int main()
{
    Draw_window *w = new Draw_window();
    deque<deque<int>> data32 = *(w->get_draw_mat());
    affiche_mat(data32, 32, 32);
    cout << '\n' << endl;
    deque<deque<int>> data32_centered = center_mat(data32);
    deque<deque<int>> data8 = compress_mat(data32_centered);
    
    affiche_mat(data32_centered, 32, 32);
    return 0;
}