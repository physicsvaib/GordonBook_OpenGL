#version 430
out vec4 color;

void main(void)
{
    color = vec4(gl_FragCoord.xy/600, 1.0, 1.0);
}
