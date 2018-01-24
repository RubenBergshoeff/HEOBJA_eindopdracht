//
//  TextBlock.hpp
//  AgendaTool
//
//  Created by Ruben Bergshoeff on 1/9/18.
//

#ifndef TextBlock_hpp
#define TextBlock_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>

#include "GUIBase.hpp"

class TextBlock : public GUIBase {
public:
    TextBlock ();
    
    static TextBlock * setup (ofRectangle rect, ofTrueTypeFont * font);
    static TextBlock * setup (ofRectangle rect, ofTrueTypeFont * font, std::string text);
    static TextBlock * setup (ofRectangle rect, ofTrueTypeFont * font, std::string text, ofColor color);
    static TextBlock * setup (GUIBase * base, ofTrueTypeFont * font, std::string text);
    static TextBlock * setup (GUIBase * base, ofTrueTypeFont * font, std::string text, float padding);
    static TextBlock * setup (GUIBase * base, ofTrueTypeFont * font, std::string text, ofColor color);
    static TextBlock * setup (GUIBase * base, ofTrueTypeFont * font, std::string text, float padding, ofColor color);
    
    virtual void setRect (ofRectangle rect) override;
    
    ~TextBlock() override;
    
protected:
    virtual void render () override;
    virtual void redraw () override;
    
private:
    static const float DEFAULTPADDING;
    ofTrueTypeFont * font;
    vector<std::string> lines;
    std::string text;
    GUIBase * base;
    float padding;
};

#endif /* TextBlock_hpp */
