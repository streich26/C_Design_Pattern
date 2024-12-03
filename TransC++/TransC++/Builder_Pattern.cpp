#include <iostream>
#include <vector>

// Ư�� Product
class Product {
public:
    std::vector<std::string> parts_;
    void ListParts() const {
        std::cout << "Product parts: ";
        for (size_t i = 0; i < parts_.size(); i++) {
            if (parts_[i] == parts_.back()) {
                std::cout << parts_[i];
            }
            else {
                std::cout << parts_[i] << ", ";
            }
        }
        std::cout << "\n\n";
    }
};

// ���� �������̽�
class Builder
{
public:
    virtual ~Builder() {}
    // �������̽��̹Ƿ� ���������� ���������Լ��� ����
    virtual void buildPartA() const = 0;
    virtual void buildPartB() const = 0;
    virtual void buildPartC() const = 0;
};

// Concrete Ŭ���� ����
class ConcreteBuilder : public Builder
{
public:
    // �����ڿ��� ���ο� Product�� �����ϰ�, �Ҹ��ڿ��� Product�� ������ �ڿ� ����
    ConcreteBuilder() { this->Reset(); }
    ~ConcreteBuilder() { delete product; }

    void Reset() {
        this->product = new Product();
    }

    void buildPartA() const override {
        this->product->parts_.push_back("PartA1");
    }

    void buildPartB() const override {
        this->product->parts_.push_back("PartB1");
    }

    void buildPartC() const override {
        this->product->parts_.push_back("PartC1");
    }

    Product* GetProduct() {
        Product* result = this->product;
        this->Reset();
        return result;
    }
private:
    Product* product;
};

// Director�� building steps�� �����ϴ� ���Ҹ� ��.
// �̴� Ư�� configuration�� build �ϴ� ���� ������.
class Director {
public:
    // Ư���� builder�� set�� �� ����
    // ��, ���� ���ο� builder�� �����ؼ� Ȯ���ų �� ����
    void set_builder(Builder* builder) {
        this->builder = builder;
    }

    // A�� ����� �Լ�
    void BuildMinimalViableProduct() {
        this->builder->buildPartA();
    }

    // A, B, C�� ����� �Լ�
    void BuildFullFeaturedProduct() {
        this->builder->buildPartA();
        this->builder->buildPartB();
        this->builder->buildPartC();
    }
private:
    Builder* builder;
};

// Client
void ClientCode(Director& director)
{
    ConcreteBuilder* builder = new ConcreteBuilder();
    director.set_builder(builder);
    std::cout << "One product:\n";
    director.BuildMinimalViableProduct();

    Product* p = builder->GetProduct();
    p->ListParts();
    delete p;

    std::cout << "Full products:\n";
    director.BuildFullFeaturedProduct();

    p = builder->GetProduct();
    p->ListParts();
    delete p;

    std::cout << "Customized product:\n";
    // ���� ���� Ư�� ��Ʈ�� �����ϴ� �͵� ����
    builder->buildPartA();
    builder->buildPartC();
    p = builder->GetProduct();
    p->ListParts();
    delete p;

    delete builder;
}

int main()
{
    Director* director = new Director();
    ClientCode(*director);
    delete director;
    return 0;
}