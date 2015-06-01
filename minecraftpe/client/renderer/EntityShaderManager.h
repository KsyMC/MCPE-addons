#pragma once

class EntityShaderManager
{
public:
	EntityShaderManager();
	virtual ~EntityShaderManager();
	virtual void getOverlayColor(Entity &, float) const;
};
