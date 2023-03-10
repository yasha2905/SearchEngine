#include <fstream>
#include <iostream>
#include "ConverterJSON.h"

class FileConfigDoesNotExist: public std::exception{
public:
    const char* what() const noexcept override{ // переопределяем what
        return "Сonfig file is missing";
    }
};

class configFieldIsMissing:public  std::exception{
public:
    const char* what() const noexcept override{ // переопределяем what
        return "Field \"Config\" is missing.";
    }
};

ConverterJSON::ConverterJSON(std::string config, std::string request) {
    // считываем requests.json и config.json в структуру conf
    try {
        readConfigFile(config);
    }
    catch (FileConfigDoesNotExist &x){
        std::cerr << "Wrong configuration: " << x.what() << std::endl;
    }

    std::ifstream readFrom(request);
    std::vector<std::string> req;
    nlohmann::json j;
    readFrom >> j;
    for (auto const& val : j["requests"]){
        conf.requests.push_back(val);
    }
}

int ConverterJSON::GetResponsesLimit() {
    return conf.max_responses;
}

std::vector<std::string> ConverterJSON::GetRequests() {
    return conf.requests;
}

std::vector<std::string> ConverterJSON::GetTextDocuments() {
    return conf.files;
}

void ConverterJSON::readConfigFile(std::string filePath) {
    std::ifstream readFrom(filePath.c_str());
    if(!readFrom.is_open()) {
        throw FileConfigDoesNotExist();
    }
    nlohmann::json j;
    readFrom >> j;
    if (!j.contains("config")) {
        throw configFieldIsMissing();
    }
    conf.name = j["config"]["name"];
    std::cout << "Search Engine " << conf.name << " is running" << std::endl;
    conf.version = j["config"]["version"];
    std::cout << "Search Engine version is " << conf.version << std::endl;
    conf.max_responses = j["config"]["max_responses"];

    if (j.find("files") != j.end()) {
        for (auto const &val: j["files"]) {
            conf.files.push_back(val);
            int i = 0;
        }
    }
    readFrom.close();
    for(int i=0; i < conf.files.size(); ++i){
        // по условию надо указать что файла нет но программу не прерывать
        std::ifstream readFrom(conf.files[i]);
        if(!readFrom.is_open()) {
            std::cout << "Data file " << conf.files[i] << " is missing" << std::endl;
        }
    }
}
