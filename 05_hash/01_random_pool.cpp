#include <iostream>
#include <unordered_map>
#include <string>
#include <random>

using namespace std;

class RandomPool {
public:
    int insertKey(string key);
    int deleteKey(string key);
    int getRandom(string &key);

private:
    unordered_map<string, int> keytoidx;
    unordered_map<int, string> idxtokey;
    int size = 0;
};

int RandomPool::insertKey(string key)
{
    keytoidx.insert({key, size});
    idxtokey.insert({size++, key});
    return 0;
}

int RandomPool::deleteKey(string key)
{
    int targetIdx, lastIdx;
    string lastKey;

    targetIdx = keytoidx[key];
    lastKey = idxtokey[--size];
    lastIdx = keytoidx[lastKey];
    idxtokey[targetIdx] = lastKey;
    keytoidx[lastKey] = targetIdx;
    keytoidx.erase(key);
    idxtokey.erase(lastIdx);
    return 0;
}

int RandomPool::getRandom(string &key)
{
    default_random_engine e;
    uniform_int_distribution<unsigned> u(0,size);
    int chox = u(e);

    key = idxtokey[chox];

    return 0;
}

int main ()
{
    RandomPool pool;
    string randomKey;

    pool.insertKey("tom");
    pool.insertKey("brain");
    pool.insertKey("apple");
    pool.insertKey("two");

    pool.getRandom(randomKey);
    cout << "random key: " << randomKey << endl;

    pool.deleteKey("apple");
    pool.deleteKey("tom");
    pool.deleteKey("two");

    pool.getRandom(randomKey);
    cout << "random key: " << randomKey << endl;

    return 0;
}