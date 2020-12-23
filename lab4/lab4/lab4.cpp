#include "Interactor.h"
#include <vld.h>
#include <locale.h>
int main() {
    setlocale(LC_ALL, "Ru");
    auto* interactor = new Interactor(new ElectionsRepo());
    interactor->Loop();
    delete interactor;
    return 0;
}
