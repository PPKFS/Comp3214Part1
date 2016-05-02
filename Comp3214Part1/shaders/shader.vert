#version 420 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 inColor;
layout(location = 2) in vec3 normal;
layout(location = 3) in vec2 inUVs;
out vec3 outColor;
out vec2 uvs;

uniform mat4 viewprojection;
uniform mat4 model;
uniform vec3 camera;
uniform bool isLit;

void main()
{ 
   float cosTheta = dot(normalize(normal), normalize(camera));
   gl_Position = viewprojection * model * vec4(position, 1.0);
   if(isLit)
   {
       outColor = inColor * vec3(1, 1, 1) * cosTheta;
   }
   else
   {
      outColor = inColor;
   }
   uvs = inUVs;
} 