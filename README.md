# 🐸 CppJSONlize

CppJSONlize provides a series of marcos to intrusively define how a cpp struct load from a json or dump to a json.


# Usage

```c++

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

    CPPJSONLIZE_DEFINE_TYPE_INTRUSIVE(                 //
        Person,                                        //
        (name, CPPJSONLIZE_FORCE_NEED, "person_name"), // read from "person_name", force need
        (age),                                         // read from "age" , use 0 by default
        (weight, CPPJSONLIZE_ARG_NOPE),                // read from "weight", use 0 by default
        (data)                                         // read from list of Project named "data"
    )
};


```
