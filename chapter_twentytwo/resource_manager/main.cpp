#include <memory>
#include <print>

class ResourceManager
{
public:
    ResourceManager(int val)
        : m_res{std::make_unique<int>(val)}
    {}

    auto get() const {return *m_res;}
    void set(int val) {*m_res = val;}
    bool hasResource() const {return static_cast<bool>(m_res);}

private:
    std::unique_ptr<int> m_res; // doesn't point to an int yet
};


int main()
{
    ResourceManager manager1{994};
    ResourceManager manager2{std::move(manager1)};
    if (manager1.hasResource())
        std::println("Manager 1 owns a resource.");
    else
        std::println("Manager 1 doesn't own a resource.");

    std::println("Manager 2: {}", manager2.get());

    return 0;
}