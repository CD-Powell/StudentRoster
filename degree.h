#pragma once
#include <string>
using std::string;

/* Enumerating data types for indexing degree types */
enum DegreeProgram { SECURITY, NETWORK, SOFTWARE, UNDECIDED};

/* Parallel array creating indexable strings from enumerated degree types */
static const std::string degreeProgramStrings[] = { "SECURITY", "NETWORK", "SOFTWARE", "UNDECIDED" };