#version 330 core
out vec4 FragColor;

in vec3 FragPos;
in vec2 TexCoords;
in vec3 Normal;

vec3 position;
vec3 ambient;
vec3 diffuse;
vec3 specular;
vec3 viewPos;
vec3 reflectDir;
vec3 lightDir;
float spec;
float diff;

// uniform vec3 viewPos;
uniform sampler2D texture_diffuse1;
uniform sampler2D texture_specular1;

void main() {    
    // ambient
    vec3 ambient = texture(texture_diffuse1, TexCoords).xyz * vec3(0.2f, 0.2f, 0.2f);

    // diffuse 
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(texture(texture_diffuse1, TexCoords).xyz - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = texture(texture_diffuse1, TexCoords).xyz * diff * texture(texture_diffuse1, TexCoords).xyz;  

    // specular
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 50.0f);
    vec3 specular = vec3(1.0f, 1.0f, 1.0f) * spec * texture(texture_specular1, TexCoords).xyz;

    vec3 result = ambient + diffuse + specular;
    FragColor = vec4(result, 1.0);
    // FragColor = texture(texture_diffuse1, TexCoords);
}