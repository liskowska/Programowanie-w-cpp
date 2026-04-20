#include "mapVisualizer.hpp"
#include "vector2d.hpp"
#include <sstream>
#include <iomanip>
#include <format> // Wymaga C++20

MapVisualizer::MapVisualizer(RectangularMap& map) : map(map) {}

std::string MapVisualizer::draw(Vector2d lowerLeft, Vector2d upperRight) {
    std::stringstream builder;

    for (int i = upperRight.y() + 1; i >= lowerLeft.y() - 1; i--) {
        if (i == upperRight.y() + 1) {
            builder << drawHeader(lowerLeft, upperRight);
        }

        // Odpowiednik String.format("%3d: ", i)
        builder << std::setw(3) << i << ": ";

        for (int j = lowerLeft.x(); j <= upperRight.x() + 1; j++) {
            if (i < lowerLeft.y() || i > upperRight.y()) {
                builder << drawFrame(j <= upperRight.x());
            } else {
                builder << CELL_SEGMENT;
                if (j <= upperRight.x()) {
                    Vector2d drawVector;
                    drawVector.x(j);
                    drawVector.y(i);
                    builder << drawObject(drawVector);
                }
            }
        }
        builder << "\n";
    }
    return builder.str();
}

std::string MapVisualizer::drawFrame(bool innerSegment) {
    if (innerSegment) {
        return FRAME_SEGMENT + FRAME_SEGMENT;
    } else {
        return FRAME_SEGMENT;
    }
}

std::string MapVisualizer::drawHeader(Vector2d lowerLeft, Vector2d upperRight) {
    std::stringstream builder;
    builder << " y\\x ";
    for (int j = lowerLeft.x(); j < upperRight.x() + 1; j++) {
        builder << std::setw(2) << j;
    }
    builder << "\n";
    return builder.str();
}

std::string MapVisualizer::drawObject(Vector2d currentPosition) {
    if (this->map.isOccupied(currentPosition)) {
        // Zakładamy, że objectAt zwraca wskaźnik lub obiekt, 
        // który można wyrenderować do stringa
        auto object = this->map.objectAt(currentPosition);
        if (object != nullptr) {
            // W C++ musisz upewnić się, że Twoje obiekty mają metodę toString() 
            // lub przeciążony operator <<
            return object->toString(); 
        }
    }
    return EMPTY_CELL;
}