#pragma once

#include <string>
#include <memory>
#include "vector2d.hpp"
#include "rectangularMap.hpp"

class MapVisualizer {
private:
    const std::string EMPTY_CELL = " ";
    const std::string FRAME_SEGMENT = "-";
    const std::string CELL_SEGMENT = "|";
    
    // Używamy referencji lub wskaźnika, ponieważ C++ nie kopiuje obiektów automatycznie jak Java
    RectangularMap& map;

    std::string drawFrame(bool innerSegment);
    std::string drawHeader(Vector2d lowerLeft, Vector2d upperRight);
    std::string drawObject(Vector2d currentPosition);

public:
    explicit MapVisualizer(RectangularMap& map);
    std::string draw(Vector2d lowerLeft, Vector2d upperRight);
};