#include <iostream>

using namespace std;

class SingleInstance {
public:
    void print(){cout << "print me:" << mSingle << "\n";}
    static SingleInstance * getInstance() {return mSingle;}
    void deleteInstance();
private:
    // forbid outside construct or destruct
    SingleInstance();
    ~SingleInstance();
    // forbid outside call copy construct and assignment construct.
    SingleInstance(const SingleInstance &single);
    const SingleInstance &operator=(const SingleInstance &single);

private:
    static SingleInstance * mSingle;
};

//Initialize instance when process start.This is an thread safe mode.
SingleInstance * SingleInstance::mSingle = new SingleInstance;

void SingleInstance::deleteInstance() {
    if (mSingle) {
        delete mSingle;
        mSingle = NULL;
        cout << "delete instance.\n";
    }
}

SingleInstance::SingleInstance() {cout <<"SingleInstance.\n";}
SingleInstance::~SingleInstance() {cout << "~SingleInstance.\n";}


int main() {

    SingleInstance::getInstance()->print();
    SingleInstance::getInstance()->deleteInstance();
    return 0;
}
