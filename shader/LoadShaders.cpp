#include <cstdlib>
 
#include "LoadShaders.h"
 
NT_USING_NAMESPACE
 
const GLchar* readShader(const char* filename)
{
#ifdef WIN32
    FILE* infile;
    fopen_s( &infile, filename, "rb" );
#else
    FILE* infile = fopen( filename, "rb" );
#endif // WIN32
 
    if ( !infile ) {
        std::cerr << "Unable to open file '" << filename << "'" << std::endl;
        return NULL;
    }

    fseek( infile, 0, SEEK_END );
    int len = ftell( infile );
    fseek( infile, 0, SEEK_SET );
 
    GLchar* source = new GLchar[len+1];
 
    fread( source, 1, len, infile );
    fclose( infile );
 
    source[len] = 0;
 
    return const_cast<const GLchar*>(source);
}
 
void Shader::createShaderByFile(const char* fileName)
{
    char vertFileName[512] = "";
    char fragFileName[512] = "";
    strcpy(vertFileName, fileName);
    strcpy(fragFileName, fileName);
    int success;
    char infoLog[512];
    // 创建shader程序段
    _programID = glCreateProgram();

    // 创建定点着色器
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    const GLchar* vertCode = readShader(strcat(vertFileName, ".vert"));
    glShaderSource(vertexShader, 1, &vertCode, NULL);
    glCompileShader(vertexShader);
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    // 编译错误
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR:SHADER::VERTEX::COMPLIATION_FAILED\n" << infoLog << std::endl;
    }
    
    // 创建片元着色器
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    const GLchar* fragCode = readShader(strcat(fragFileName, ".frag"));
    glShaderSource(fragmentShader, 1, &fragCode, NULL);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    // 编译错误
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR:SHADER::FRAGMENT::COMPLIATION_FAILED\n" << infoLog << std::endl;
    }

    // 附加到program上
    glAttachShader(_programID, vertexShader);
    glAttachShader(_programID, fragmentShader);
    // 链接
    glLinkProgram(_programID);

    // 获取链接结果
    glGetProgramiv(_programID, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(_programID, 512, NULL, infoLog);
        std::cout << "ERROR:SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
    
    // 删除shader片段
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void Shader::createShaderByChars(const char* vert, const char* frag)
{
    int success;
    char infoLog[512];
    // 创建shader程序段
    _programID = glCreateProgram();

    // 创建定点着色器
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vert, NULL);
    glCompileShader(vertexShader);
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    // 编译错误
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR:SHADER::VERTEX::COMPLIATION_FAILED\n" << infoLog << std::endl;
    }
    
    // 创建片元着色器
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &frag, NULL);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    // 编译错误
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR:SHADER::FRAGMENT::COMPLIATION_FAILED\n" << infoLog << std::endl;
    }

    // 附加到program上
    glAttachShader(_programID, vertexShader);
    glAttachShader(_programID, fragmentShader);
    // 链接
    glLinkProgram(_programID);

    // 获取链接结果
    glGetProgramiv(_programID, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(_programID, 512, NULL, infoLog);
        std::cout << "ERROR:SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
    
    // 删除shader片段
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void Shader::use()
{
    glUseProgram(_programID);
}

void Shader::setUniformBool(const char* name, bool value)
{
    GLuint location = glGetUniformLocation(_programID, name);
    glUniform1i(location, (int)value);
}

void Shader::setUniform3f(const char* name, Vec3 vec)
{
    GLuint location = glGetUniformLocation(_programID, name);
    glUniform3f(location, vec.x, vec.y, vec.z);
}

void Shader::setUniform1f(const char* name, float value)
{
    GLuint location = glGetUniformLocation(_programID, name);
    glUniform1f(location, value);
}