//
//  Draw_window.hpp
//  Draw-n-Guess
//
//  Created by Alexis Louis on 05/04/2016.
//  Copyright © 2016 Alexis Louis. All rights reserved.
//

#ifndef Draw_window_hpp
#define Draw_window_hpp

#include <Header.h>
using namespace std;


class Draw_window
{
public:
    Draw_window();
    std::deque<std::deque<int>> *get_draw_mat(){return draw_mat;};
    void run();
    void set_active(bool b);
    void set_guess_text(string str);
    
private:
    sf::RenderWindow *window;
    sf::Texture *draw_zone_tex;
    sf::Sprite *draw_zone;
    std::deque<std::deque<int>> *draw_mat;
    sf::Uint8 *pixels;
    sf::Text guessText;
    bool drawing;
    bool active;
};


#endif /* Draw_window_hpp */
