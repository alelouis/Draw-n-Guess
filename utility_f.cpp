//
//  utility_f.cpp
//  Neural Networks
//
//  Created by Alexis Louis on 17/03/2016.
//  Copyright © 2016 Alexis Louis. All rights reserved.
//

#include "utility_f.hpp"

vector<vector<float>> readMatFromFile(string str){
    vector<vector<float>> matAPP;
    vector<float> lineAPP;
    float x;
    string line;;
    ifstream APP;
    APP.open(str, ios::in);

    if (!APP)
        std::cout << "Cannot open file \"" << str << "\"" << std::endl;
    else
    {
        std::vector<int> v;

        while (std::getline(APP, line))
        {
            std::istringstream iss(line);
            float n;
            while (iss >> n)
            {
                lineAPP.push_back(n);
            }
            matAPP.push_back(lineAPP);
            lineAPP.clear();
        }
    }

    return matAPP;
}

deque<deque<int>> readMatFromFileDeq(string str){
    deque<deque<int>> matAPP;
    deque<int> lineAPP;
    int x;
    string line;
    ifstream APP;
    APP.open(str, ios::in);
    std::deque<int> v;

    while (std::getline(APP, line))
    {
        std::istringstream iss(line);
        int n;
        while (iss >> n)
        {
            lineAPP.push_back(n);
        }
        matAPP.push_back(lineAPP);
        lineAPP.clear();
    }

    return matAPP;
}

sf::Text text;
sf::Font font;
sf::Text simpleText(std::string str,int xOrigin, int yOrigin, int charSize){

    font.loadFromFile("font.otf");
    text.setFont(font);
    text.setCharacterSize(charSize);
    text.setOrigin(-xOrigin, -yOrigin);
    text.setColor(sf::Color(0, 0, 0));
    text.setString(str);

    return text;
}
