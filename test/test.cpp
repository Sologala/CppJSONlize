#include "CppJSONlize/CppJSONlize.h"
#include <iostream>
#include <nlohmann/json.hpp>
#include <string>

struct Project
{
    std::string projectName = "default_name";
    double score{0};

    CPPJSONLIZE_DEFINE_TYPE_INTRUSIVE(
        Project,                        //
        (projectName, "project_name"),  // read from project_name, use "default_name" if no found in json
        (score, CPPJSONLIZE_FORCE_NEED) // force need, read from "score"
    )
};

struct Person
{
    std::string name;
    int age{0};
    float weight{0};
    std::vector<Project> data;

    CPPJSONLIZE_DEFINE_TYPE_INTRUSIVE(Person, //
                                      (name, CPPJSONLIZE_FORCE_NEED,
                                       "person_name"),                // read from "person_name", force need
                                      (age),                          // read from "age" , use 0 by default
                                      (weight, CPPJSONLIZE_ARG_NOPE), // read from "weight", use 0 by default
                                      (data)                          // read from list of Project named "data"
    )
};

int main(int argc, char *argv[])
{
    Person goodman;
    goodman.name = "good_man";
    goodman.weight = 80;
    goodman.age = 0;
    Project math;
    math.projectName = "algebra";
    math.score = 10;
    goodman.data.push_back(math);

    nlohmann::json goodmanJson = goodman;
    std::string goodmanJsonStr = goodmanJson.dump(4);
    std::cout << "good man \n" << goodmanJsonStr << std::endl;
    {
        std::string badmanJsonStr = R"(
        {
            "person_name": "foo",
            "weight": 100.0
        }
        )";
        Person badman = nlohmann::json::parse(badmanJsonStr);
        std::cout << "bad man \n:" << "name: " << badman.name << "\nage: " << badman.age
                  << "\n weight: " << badman.weight <<std::endl;
    }
    return 0;
}
