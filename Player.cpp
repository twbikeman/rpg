void Player::load(int x, int, y, int width, int height, std::string textureID)
{
	GameObject::load(x, y, width, height, textureID);
}

void Player::draw(SDL_Renderer*)
{	
	GameObject::draw(pRenderer);
}