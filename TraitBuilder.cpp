#include <string>

#include "TraitBuilder.h"

using namespace std;

const TraitBuilder& TraitBuilder::place(PlaceableTrait& trait, float x, float y) const  {
    trait.place(x, y);
    return *this;
}

const TraitBuilder& TraitBuilder::scale(SizableTrait& trait, float width, float height) const {
    trait.scale(width, height);
    return *this;
}

const TraitBuilder& TraitBuilder::activate(ClickableTrait& trait, void (*callback)(Widget* src, void* source), string sound) const {
    trait.callback = callback;
    trait.sound = sound;
    return *this;
}

const TraitBuilder& TraitBuilder::scribe(ReadableTrait& trait, std::string text, std::string font, int size) const {
    trait.text = text;
    trait.font = font;
    trait.size = size;
    return *this;
}


const TraitBuilder& TraitBuilder::scribe(ReadableTrait& trait, std::string font, int size) const {
    trait.font = font;
    trait.size = size;
    return *this;
}
