#ifndef ASSEMBLE_H
#define ASSEMBLE_H

#include <string>

// The 'assemble' class handles the conversion of machine code to assembly instructions.
class assemble {
public:
    // Constructor
    assemble();

    // Assembler function: Converts the machine code from inputFile to human-readable 
    // assembly instructions and writes it to outputFile (default: "outputDef.txt").
    void assembler(const std::string& inputFile, const std::string& outputFile);

};

#endif // ASSEMBLE_H
