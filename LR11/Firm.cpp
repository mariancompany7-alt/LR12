#include "Firm.h"

Firm::Firm() {
    type = "";
    size = 0;
}

Firm::Firm(QString type, int size) {
    this->type = type;
    this->size = size;
}

QString Firm::toString() {
    return QString("Firm: %1, size: %2").arg(type).arg(size);
}

Firm::~Firm() {};
