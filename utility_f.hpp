//
//  utility_f.hpp
//  Neural Networks
//
//  Created by Alexis Louis on 17/03/2016.
//  Copyright © 2016 Alexis Louis. All rights reserved.
//

#ifndef utility_f_hpp
#define utility_f_hpp

#include "Header.h"
using namespace std;

vector<vector<float>> readMatFromFile(string str);
deque<deque<int>> readMatFromFileDeq(string str);
sf::Text simpleText(std::string str,int xOrigin, int yOrigin, int charSize);

#endif /* utility_f_hpp */
