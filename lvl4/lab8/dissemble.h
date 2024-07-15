#ifndef DISSEMBLE_H
#define DISSEMBLE_H

#include <string>
#include <unordered_map>
#include <vector>

class Dissembler {
public:
    Dissembler();
    void dissemble(const std::string& inputFile, const std::string& outputFile = "outputDef.txt");
};

#endif // DISSEMBLE_H
