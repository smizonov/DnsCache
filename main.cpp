#include <iostream>
#include <boost/optional.hpp>
#include <vector>
#include <list>
#include <mutex>
#include <map>
#include <atomic>
#include <algorithm>
#include <boost/circular_buffer.hpp>

using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>
#include <mutex>
#include <memory>
#include <DnsCache.h>

int main()
{
    network::DNSCache cash(5);
    cash.update("name", "ip");

    cout << "Hello World! " << cash.resolve("name") << endl;
    return 0;
}

