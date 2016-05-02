#include "Cone.h"


Cone::Cone()
{
	for (int i = 0; i < 360; ++i)
	{	
		vertices.push_back(0.f);
		vertices.push_back(0.f);
		vertices.push_back(0.f);

		vertices.push_back(cos(2 * i*PI / 360));
		vertices.push_back(0.f);
		vertices.push_back(sin(2 * i*PI / 360));
		

		vertices.push_back(cos(2 * ((1 + i) % 360)*PI / 360));
		vertices.push_back(0.f);
		vertices.push_back(sin(2 * ((1 + i) % 360)*PI / 360));
		

		//the sides
		vertices.push_back(cos(2 * i*PI / 360));
		vertices.push_back(0.f);
		vertices.push_back(sin(2 * i*PI / 360));

		vertices.push_back(0.f);
		vertices.push_back(3.f);
		vertices.push_back(0.f);

		vertices.push_back(cos(2 * (1 + i % 360)*PI / 360));
		vertices.push_back(0.f);
		vertices.push_back(sin(2 * (1 + i % 360)*PI / 360));	
		
	}

	/*for (int i = 0; i < vertices.size(); ++i)
	{
		colors.push_back(1.f);
		//normals.push_back(1.f);
	}*/

	for (int i = 0; i < vertices.size() / 3; ++i)
	{
		indices.push_back(i);
		colors.push_back(1.f);
		colors.push_back(1.f);
		colors.push_back(1.f);
	}
	//not using normals for it
	normals.push_back(1.f);
}


Cone::~Cone()
{
}
