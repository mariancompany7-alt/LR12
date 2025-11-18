#include "Firm.h"

Firm::Firm() {
    type = "";
    size = 0;
}

Firm::Firm(QString type, int size) {
    this->type = type;
    this->size = size;
}

Firm::~Firm() {};
