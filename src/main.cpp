#include "../include/ConverterJSON.h"
#include "../include/InvertedIndex.h"
#include "../include/SearchServer.h"

int main() {

    ConverterJSON converterJson;
    InvertedIndex invertedIndex;
    invertedIndex.UpdateDocumentBase(converterJson);
    SearchServer searchServer(invertedIndex);
    searchServer.search(converterJson);
    return 0;
}

