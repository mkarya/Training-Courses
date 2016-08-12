#ifndef OBJECT_POOL
#define OBJECT_POOL
#include <iostream>
#include <map>
#include "factoryAbstract.h"

class ObjectPool {
        private:
                map<stooze& ,bool> pool;

        public:
                //ObjectPool();
                stooze & getObject(int xx);
                int releaseObject(stooze& );
};

#endif
