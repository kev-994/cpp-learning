#include <print>

class ResourceHandle
{
public:
    ResourceHandle(int val)
    {
        m_res = new int{val};
    }

    ~ResourceHandle()
    {
        delete m_res;
    }

    ResourceHandle(const ResourceHandle&) = delete; // disable copy constructor
    ResourceHandle& operator=(const ResourceHandle&) = delete; // disable copy assignment

    ResourceHandle(ResourceHandle&& other) noexcept
    {
        m_res = other.m_res;
        other.m_res = nullptr;
    }

    ResourceHandle& operator=(ResourceHandle&& other) noexcept
    {
        if (&other == this)
            return *this;
        
        delete m_res;
        m_res = other.m_res;
        other.m_res = nullptr;
        return *this;
    }

    auto get() const {return *m_res;}


private:
    int* m_res;
};

int main()
{
    ResourceHandle handle1{1};
    ResourceHandle handle2{2};
    ResourceHandle handle3{std::move(handle2)};
    ResourceHandle handle4{4};

    std::println("Handle1: {}", handle1.get());
    std::println("Handle3: {}", handle3.get());
    std::println("Handle4: {}", handle4.get());

    handle4 = std::move(handle1);
    std::println("Handle4: {}", handle4.get());

    return 0;
}