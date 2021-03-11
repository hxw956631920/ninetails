#include <cstdlib>
 
#include "LoadShaders.h"
 
NT_USING_NAMESPACE
 
void Shader::createShaderByFile(std::string fileName)
{
    char vertFileName[512] = "";
    char fragFileName[512] = "";
    int success;
    char infoLog[512];
    // 创建shader程序段
    _programID = glCreateProgram();

    
    // 创建定点着色器
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    const GLchar* vertCode = FileUtils::readFile(fileName+".vert");
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
    const GLchar* fragCode = FileUtils::readFile(fileName+".frag");
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

void Shader::setUniform1i(const char* name, int value)
{
    GLuint location = glGetUniformLocation(_programID, name);
    glUniform1i(location, value);
}