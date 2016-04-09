//
//  Draw_window.cpp
//  Draw-n-Guess
//
//  Created by Alexis Louis on 05/04/2016.
//  Copyright © 2016 Alexis Louis. All rights reserved.
//

#include "Draw_window.hpp"
#include "Header.h"
using namespace std;

Draw_window::Draw_window(){
    window = new sf::RenderWindow(sf::VideoMode(640, 640), "Draw-n-Guess");
    window->setVerticalSyncEnabled(true);
    draw_zone_tex = new sf::Texture;
    draw_zone = new sf::Sprite;
    draw_zone_tex->create(640, 640);
    draw_zone->setTexture(*draw_zone_tex);
    draw_mat = new deque<deque<int>>;;
    draw_mat->resize(32);
    for (int i=0; i<32; i++){
        (*draw_mat)[i].resize(32);
    }
    drawing = false;
    active = false;
    guessText = simpleText("?", 40, 20, 50);
    
}

void Draw_window::run(){
    sf::Uint8 *pixels = new sf::Uint8[640*640*4];
    sf::RectangleShape guess_zone;
    guess_zone.setSize(sf::Vector2f(72, 72));
    guess_zone.setOutlineColor(sf::Color::Black);
    guess_zone.setOutlineThickness(3);
    guess_zone.setPosition(15, 15);
    while (active)
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed){
                window->close();
            }
            if (event.type == sf::Event::MouseButtonPressed){
                drawing = true;
                if (event.mouseButton.button == sf::Mouse::Right)
                {
                    for(int i(0);i<32;i++){
                        for(int j(0);j<32;j++){
                            (*draw_mat)[i][j]=0;
                        }
                    }
                }
            }
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Space)
                {
                    active = false;
                }
            }
            if (event.type == sf::Event::MouseButtonReleased){
                drawing = false;
            }
            if (event.type == sf::Event::MouseMoved){
                event.mouseMove.x = std::min(event.mouseMove.x,619);
                event.mouseMove.x = std::max(event.mouseMove.x,20);
                event.mouseMove.y = std::min(event.mouseMove.y,600);
                event.mouseMove.y = std::max(event.mouseMove.y,20);
                if (drawing){
                    (*draw_mat)[(event.mouseMove.y)/20][(event.mouseMove.x)/20] = 1;
                    (*draw_mat)[(event.mouseMove.y)/20+1][(event.mouseMove.x)/20+1] = 1;
                    (*draw_mat)[(event.mouseMove.y)/20+1][(event.mouseMove.x)/20-1] = 1;
                    (*draw_mat)[(event.mouseMove.y)/20-1][(event.mouseMove.x)/20+1] = 1;
                    (*draw_mat)[(event.mouseMove.y)/20-1][(event.mouseMove.x)/20-1] = 1;
                    (*draw_mat)[(event.mouseMove.y)/20][(event.mouseMove.x)/20+1] = 1;
                    (*draw_mat)[(event.mouseMove.y)/20][(event.mouseMove.x)/20-1] = 1;
                    (*draw_mat)[(event.mouseMove.y)/20+1][(event.mouseMove.x)/20] = 1;
                    (*draw_mat)[(event.mouseMove.y)/20-1][(event.mouseMove.x)/20] = 1;
                }
            }
            
        }
        for(int x = 0; x < 640; x++)
        {
            for(int y = 0; y < 640; y++)
            {
                pixels[(640 * y + x)*4] = !(*draw_mat)[y/20][x/20]*255; // R
                pixels[(640 * y + x)*4 + 1] = !(*draw_mat)[y/20][x/20]*255; // G
                pixels[(640 * y + x)*4+ 2] = !(*draw_mat)[y/20][x/20]*255; // B
                pixels[(640 * y + x)*4 + 3] = !(*draw_mat)[y/20][x/20]*255; // A
            }
        }
        
        draw_zone_tex->update(pixels);
        window->clear();
        window->draw(*draw_zone);
        window->draw(guess_zone);
        window->draw(guessText);
        window->display();
    }
}

void Draw_window::set_active(bool b){
    draw_mat->clear();
    draw_mat = new deque<deque<int>>;
    draw_mat->resize(32);
    for (int i=0; i<32; i++){
        (*draw_mat)[i].resize(32);
    }
    active = b;
}

void Draw_window::set_guess_text(string str){
    guessText = simpleText(str, 40, 20, 50);
}