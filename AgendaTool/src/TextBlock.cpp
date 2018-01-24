//
//  TextBlock.cpp
//  AgendaTool
//
//  Created by Ruben Bergshoeff on 1/9/18.
//

#include "TextBlock.hpp"

// ---------------------------------------------- public
TextBlock::TextBlock () {
    base = nullptr;
}

TextBlock * TextBlock::setup (ofRectangle rect, ofTrueTypeFont * font){
    TextBlock * pTextBlock = new TextBlock();
    pTextBlock->rect = rect;
    pTextBlock->color = DEFAULT_COLOR;
    pTextBlock->font = font;
    pTextBlock->text = "default";
    pTextBlock->padding = DEFAULTPADDING;
    pTextBlock->base = nullptr;
    pTextBlock->setNeedsRedraw();
    return pTextBlock;
}

TextBlock * TextBlock::setup (ofRectangle rect, ofTrueTypeFont * font, std::string text){
    TextBlock * pTextBlock = new TextBlock();
    pTextBlock->rect = rect;
    pTextBlock->color = DEFAULT_COLOR;
    pTextBlock->font = font;
    pTextBlock->text = text;
    pTextBlock->padding = DEFAULTPADDING;
    pTextBlock->base = nullptr;
    pTextBlock->setNeedsRedraw();
    return pTextBlock;
}

TextBlock * TextBlock::setup (ofRectangle rect, ofTrueTypeFont * font, std::string text, ofColor color){
    TextBlock * pTextBlock = new TextBlock();
    pTextBlock->rect = rect;
    pTextBlock->color = color;
    pTextBlock->font = font;
    pTextBlock->text = text;
    pTextBlock->padding = DEFAULTPADDING;
    pTextBlock->base = nullptr;
    pTextBlock->setNeedsRedraw();
    return pTextBlock;
}

TextBlock * TextBlock::setup (GUIBase * base, ofTrueTypeFont * font, std::string text){
    TextBlock * pTextBlock = new TextBlock();
    pTextBlock->rect = base->getRect();
    pTextBlock->color = DEFAULT_COLOR;
    pTextBlock->font = font;
    pTextBlock->text = text;
    pTextBlock->padding = DEFAULTPADDING;
    pTextBlock->base = base;
    pTextBlock->setNeedsRedraw();
    return pTextBlock;
}

TextBlock * TextBlock::setup (GUIBase * base, ofTrueTypeFont * font, std::string text, ofColor color){
    TextBlock * pTextBlock = new TextBlock();
    pTextBlock->rect = base->getRect();
    pTextBlock->color = color;
    pTextBlock->font = font;
    pTextBlock->text = text;
    pTextBlock->padding = DEFAULTPADDING;
    pTextBlock->base = base;
    pTextBlock->setNeedsRedraw();
    return pTextBlock;
}

TextBlock * TextBlock::setup (GUIBase * base, ofTrueTypeFont * font, std::string text, float padding){
    TextBlock * pTextBlock = new TextBlock();
    pTextBlock->rect = base->getRect();
    pTextBlock->color = DEFAULT_COLOR;
    pTextBlock->font = font;
    pTextBlock->text = text;
    pTextBlock->padding = padding;
    pTextBlock->base = base;
    pTextBlock->setNeedsRedraw();
    return pTextBlock;
}

TextBlock * TextBlock::setup (GUIBase * base, ofTrueTypeFont * font, std::string text,float padding, ofColor color){
    TextBlock * pTextBlock = new TextBlock();
    pTextBlock->rect = base->getRect();
    pTextBlock->color = color;
    pTextBlock->font = font;
    pTextBlock->text = text;
    pTextBlock->padding = padding;
    pTextBlock->base = base;
    pTextBlock->setNeedsRedraw();
    return pTextBlock;
}

void TextBlock::setRect (ofRectangle rect){
    GUIBase::setRect(rect);
    if (base != nullptr) {
        base->setRect(rect);
    }
}

TextBlock::~TextBlock() {
    if (base != nullptr) {
        delete base;
    }
    GUIBase::~GUIBase();
}


// ---------------------------------------------- protected
void TextBlock::render () {
    if (base != nullptr) {
        base->draw();
    }
    if (font == nullptr) {
        return;
    }
    ofSetColor(color);
    float y = rect.y + font->getLineHeight() - (font->getLineHeight() - font->stringHeight("D")) + padding;
    for (auto it = lines.begin(); it != lines.end(); ++it) {
        if (y > rect.y + rect.height) {
            break;
        }
        font->drawString(*it, rect.x + padding, y);
        y += font->getLineHeight();
    }
}

void TextBlock::redraw () {
    ofSetColor(color);
    lines.clear();
    istringstream iss(text);
    vector<std::string> words {istream_iterator<std::string> {iss}, istream_iterator<std::string> {}};
    
    float spaceSize = font->stringWidth("p");
    float sentenceSize = 0;
    std::string sentence = "";
    
    for (auto it = words.begin(); it != words.end(); ++it) {
        float wordSize = font->stringWidth(*it);
        if (sentenceSize == 0) {
            sentence += *it;
            sentenceSize += wordSize;
        } else {
            if (sentenceSize + wordSize + spaceSize <= rect.width - padding * 1) {
                sentence += " " + *it;
                sentenceSize += wordSize + spaceSize;
            } else {
                lines.push_back(sentence);
                sentence = *it;
                sentenceSize = wordSize;
            }
        }
    }
    if (sentenceSize > 0) {
        lines.push_back(sentence);
    }
}


// ---------------------------------------------- private
float
const TextBlock::DEFAULTPADDING = 4;
