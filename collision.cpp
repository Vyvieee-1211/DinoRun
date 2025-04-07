#include<SDL.h>
#include"collision.h"

bool Collision::check(MainObject& mainObject, HandleCactus& obstacles)
{
	dino = mainObject.getRect();
	for (auto& o : obstacles.VectorObstacle)
	{
		obstacle = o.getRect();
		if (dino.x + dino.w - 28 >= obstacle.x && dino.x + dino.w - 28 <= obstacle.x + obstacle.w
			&& dino.y + dino.h - 28 >= obstacle.y && dino.y + dino.h - 28 <= obstacle.y + obstacle.h)
		{
			return 1;
		}
	}
	return 0;
}