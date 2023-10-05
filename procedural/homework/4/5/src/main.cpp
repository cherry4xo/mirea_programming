#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <vector>
#include <math.h>

#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 600

#define BASE_SCALE 300

std::string format(float f, int digits) {
    std::ostringstream ss;
    ss.precision(digits);
    ss << f;
    return ss.str();
}

class Graphics
{
public:
    Graphics(sf::Color pointsColor)
        : pointsColor(pointsColor) {}
    ~Graphics() {}

    void init()
    {
        points.setPrimitiveType(sf::LinesStrip);
        for(float i = 0; i < WINDOW_WIDTH; ++i)
        {   
            sf::Vertex point = sf::Vector2f(i, -WINDOW_HEIGHT / 2 * sin(i * M_PI / BASE_SCALE) + WINDOW_HEIGHT / 2);
            point.color = pointsColor;
            points.append(point);
        }
    }

    void update()
    {
        for(float i = 0; i < WINDOW_WIDTH; ++i)
            points[i].position = sf::Vector2f(i, -WINDOW_HEIGHT / 2 * sin(i * M_PI / BASE_SCALE) + WINDOW_HEIGHT / 2);
    }

    void draw(sf::RenderWindow* window)
    {
        window->draw(points);
    }
private:
    sf::Color pointsColor;
    sf::VertexArray points;
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SIN graph");

    Graphics graph(sf::Color::White);
    graph.init();

    sf::Font font;
    if(!font.loadFromFile("font/arial.ttf"))
    {
        std::cout << "Cannot load font\n";
    }

    std::vector<sf::VertexArray*> coords;
    std::vector<sf::Text*> text;

    int counter = 4;

    for (float y = 0; y <= WINDOW_HEIGHT; y += 75)
    {
        sf::Text* textPiece = new sf::Text();
        textPiece->setString(sf::String(format(counter * 0.25, 4)));
        textPiece->setPosition(sf::Vector2f(5, y));
        textPiece->setFont(font);
        textPiece->setCharacterSize(12);
        textPiece->setFillColor(sf::Color::Green);
        text.push_back(textPiece);
        --counter;
        sf::Vertex pointStart = sf::Vector2f(0, y);
        sf::Vertex pointEnd = sf::Vector2f(WINDOW_WIDTH, y);
        pointStart.color = sf::Color::Green;
        pointEnd.color = sf::Color::Green;
        sf::VertexArray* line = new sf::VertexArray();
        line->append(pointStart);
        line->append(pointEnd);
        line->setPrimitiveType(sf::LinesStrip);
        coords.push_back(line);
    }

    std::vector<std::string> xTextStr = {"0", "pi/6", "pi/3", "pi/2", "2pi/3", "5pi/6", "pi", 
                                         "7pi/6", "4pi/3", "3pi/2", "5pi/3", "11pi/6", "2pi", 
                                         "13pi/6", "7pi/3", "5pi/2", "8pi/3", "17pi/6", "3pi",
                                         "19pi/6", "11pi/3", "7pi/2", "11pi/3", "23pi/6", "4pi"};
    counter = 0;

    for (double x = 0; x < WINDOW_WIDTH; x += 50)
    {
        sf::Text* textPiece = new sf::Text();
        textPiece->setString(xTextStr[counter]);
        textPiece->setPosition(sf::Vector2f(x, WINDOW_HEIGHT / 2 + 5));
        textPiece->setFont(font);
        textPiece->setCharacterSize(12);
        textPiece->setFillColor(sf::Color::Green);
        text.push_back(textPiece);
        ++counter;
        sf::Vertex pointStart = sf::Vector2f(x, 0);
        sf::Vertex pointEnd = sf::Vector2f(x, WINDOW_HEIGHT);
        pointStart.color = sf::Color::Green;
        pointEnd.color = sf::Color::Green;
        sf::VertexArray* line = new sf::VertexArray();
        line->append(pointStart);
        line->append(pointEnd);
        line->setPrimitiveType(sf::LinesStrip);
        coords.push_back(line);
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();
        }

        window.clear(sf::Color::Black);
        for(auto line : coords)
            window.draw(*line);
        for(auto piece : text)
            window.draw(*piece);
        graph.draw(&window);
        window.display();
    }

    return 0;
}