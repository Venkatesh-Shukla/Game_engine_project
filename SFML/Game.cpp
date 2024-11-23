#include "Game.h"

// Private Functions
void Game::initVariables()
{
    this->window = NULL;
}

void Game::initWindow()
{
    this->videoMode.height = 720;
    this->videoMode.width = 1080;
    this->window = new sf::RenderWindow(this->videoMode, "SFML works!", sf::Style::Titlebar | sf::Style::Close);

    this->window->setFramerateLimit(60);

}

void Game::initEnemies()
{
    this->enemy.setPosition(20.f,20.f);
    this->enemy.setSize(sf::Vector2f(100.f, 100.f));
    this->enemy.setScale(sf::Vector2f(0.5f, 0.5f));
    this->enemy.setFillColor(sf::Color::Cyan);
    this->enemy.setOutlineColor(sf::Color::Green);
    this->enemy.setOutlineThickness(1.f);
}

Game::Game() {
    this->initVariables();
    this->initWindow();
    this->initEnemies();
}
Game::~Game() {
    delete this->window;
}

const bool Game::running() const
{
    return this->window->isOpen();
}

// Functions

void Game::pollEvents()
{
    while (this->window->pollEvent(this->ev))
    {
        switch (this->ev.type) {
        case sf::Event::Closed:
            this->window->close();
            break;
        case sf::Event::KeyPressed:
            if (this->ev.key.code == sf::Keyboard::Escape)
                this->window->close();
            break;
        }
    }
}

void Game::update()
{
    this->pollEvents();

    //getting mouse_position relative to screen
    std::cout << "Mouse position(screen):" << sf::Mouse::getPosition().x << "," << sf::Mouse::getPosition().y<<"\n";

    //getting mouse_position relative to window
    std::cout << "Mouse position(window):" << sf::Mouse::getPosition(*this->window).x << "," << sf::Mouse::getPosition(*this->window).y << "\n";

}

void Game::render()
{
    /*
        @return void

        - clear old frame
        - render objects
        - display frame in window

        Renders the game objects.
    */

    this->window->clear();

    //Draw Game Objects
    this->window->draw(this->enemy);

    this->window->display();
}

