#version 420 core
in vec3 outColor;
in vec2 uvs;
out vec4 color;

uniform sampler2D sampler;
uniform bool isTexture;

void main()
{
	if(isTexture)
	{
		color = vec4(texture(sampler, uvs).rgb, 1.0);
	}
	else
	{
	color = vec4(outColor, 1.0);
	}
}