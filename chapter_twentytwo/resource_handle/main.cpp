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

    auto get() const {return *m_res;}
    auto set(int val) {*m_res = val;}

private:
    int* m_res;
};

void use(ResourceHandle&)
{
    std::println("Called use(ResourceHandle&)");
}

void use(const ResourceHandle&)
{
    std::println("Called use(const ResourceHandle&)");
}

void use(ResourceHandle&&)
{
    std::println("Called use(ResourceHandle&&)");
}

int main()
{
    ResourceHandle res{1};
    const ResourceHandle constRes{2};
    ResourceHandle&& tempRes{3};

    use(res);
    use(constRes);
    use(tempRes); // calls use(ResourceHandle&) as named variable is an l-value expression

    use(std::move(res));
    use(std::move(constRes)); // doesn't call use(ResourceHandle&&) but why? -> because const ResourceHandle is produced
                              // cannot bind a non-const reference to a const object
    use(std::move(tempRes));

    return 0;
}