#include "GameRender.h"
#include "Assets.h"

GameRender::GameRender(GameModel* game)
{
	m_game = game;
	Init();
}

GameRender::~GameRender()
{
}

bool GameRender::Init()
{
	setPosition(50.f, 50.f);
	
	m_window.create(sf::VideoMode(600, 600), "15");
	m_window.setFramerateLimit(60);

	m_text = sf::Text("hope?", Assets::Instance().font, 20);
	m_text.setFillColor(sf::Color::Cyan);
	m_text.setPosition(5.f, 5.f);

	sf::Texture PlayerTexture;
	PlayerTexture.loadFromFile("player.png");
	return true;
}

void GameRender::Render()
{
	m_window.clear();
	m_window.draw(*this);
	m_window.draw(m_text);
	m_window.display();
}

void GameRender::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	sf::Color color = sf::Color(200, 100, 200);

	sf::RectangleShape shape(sf::Vector2f(GameModel::FIELD_SIZE, GameModel::FIELD_SIZE));
	shape.setOutlineThickness(2.f);
	shape.setOutlineColor(color);
	shape.setFillColor(sf::Color::Transparent);
	target.draw(shape, states);

	shape.setSize(sf::Vector2f(GameModel::CELL_SIZE - 2, GameModel::CELL_SIZE - 2));
	shape.setOutlineThickness(2.f);
	shape.setOutlineColor(color);
	shape.setFillColor(sf::Color::Transparent);

	sf::Text text("", Assets::Instance().font, 52);

	int* elements = m_game->Elements();
	for (unsigned int i = 0; i < GameModel::ARRAY_SIZE; i++)
	{
		shape.setOutlineColor(color);
		text.setFillColor(color);
		text.setString(std::to_string(elements[i]));
		if (m_game->IsSolved())
		{
			shape.setOutlineColor(sf::Color::Cyan);
			text.setFillColor(sf::Color::Cyan);
		}
		else if (elements[i] == i + 1)
		{
			text.setFillColor(sf::Color::Green);
		}

		if (elements[i] > 0)
		{
			sf::Vector2f position(i % GameModel::SIZE * GameModel::CELL_SIZE + 10.f, i / GameModel::SIZE * GameModel::CELL_SIZE + 10.f);
			shape.setPosition(position);
			
			text.setPosition(position.x + 30.f + (elements[i] < 10 ? 15.f : 0.f), position.y + 25.f);
			target.draw(shape, states);
			target.draw(text, states);
		}
	}
}