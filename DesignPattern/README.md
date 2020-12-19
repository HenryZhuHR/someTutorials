# 目录
- [目录](#目录)
- [建造者模式](#建造者模式)
  - [建造者模式代码实例](#建造者模式代码实例)
  - [建造者模式总结](#建造者模式总结)
- [原型模式](#原型模式)
  - [原型模式结构](#原型模式结构)
- [装饰模式](#装饰模式)
  - [装饰模式结构](#装饰模式结构)

设计模式
# 建造者模式
建造者模式的结构包含以下几个角色：
- **抽象建造者**（AbstractBuilder）:创建一个Product对象的各个部件指定的抽象接口；
- **具体建造者**（ConcreteBuilder）:实现AbstractBuilder的接口，实现各个部件的具体构造方法和装配方法，并返回创建结果。
- **产品**（Product）:具体的产品对象
- **指挥者**（Director）: 构建一个使用Builder接口的对象，安排复杂对象的构建过程，客户端一般只需要与Director交互，指定建造者类型，然后通过构造函数或者setter方法将具体建造者对象传入Director。它主要作用是，隔离客户与对象的生产过程，并负责控制产品对象的生产过程。

## 建造者模式代码实例
考虑这样一个场景，如下图：
> 想要建造一栋简易的房子（地板、墙和天花板）   
> 两个工程师带着各自的方案找上门来，直接给你看方案和效果图。   
> 犹豫再三，你最终选定了一位工程师   
> 交房之日，你很满意的看着建好的房子，开始思考：这房子究竟是怎么建成的呢？这地板、墙和天花板是怎么建造的呢？     
> 工程师笑着说：“It's none of your business”

```cpp
//产品类House
class House 
{
private:
  string floor;
  string wall;
  string roof;
};

//抽象建造者AbstractBall
class AbstractBuilder 
{
public:
  AbstractBuilder();
  virtual ~AbstractBuilder();
  //抽象方法：
  virtual void   buildFloor() = 0;
  virtual void   buildWall()  = 0;
  virtual void   buildRoof()  = 0;
  virtual House* getHouse()   = 0;

  House* house;
};

//具体建造者ConcreteBuilderA
class ConcreteBuilderA :public AbstractBuilder {...};

//具体建造者ConcreteBuilderB
class ConcreteBuilderB :public AbstractBuilder {...};

//指挥者Director
class Director {...};
```
调用
```cpp
int main()
{
  //抽象建造者
  AbstractBuilder* builder;
  //指挥者
  Director* director = new Director();
  //产品：House
  House* house;

  //指定具体建造者A
  builder = new ConcreteBuilderA();
  director->setBuilder(builder);
  house = director->construct();
  house->printfHouseInfo();
  delete builder;

  //指定具体建造者B
  builder = new ConcreteBuilderB();
  director->setBuilder(builder);
  house = director->construct();
  house->printfHouseInfo();


  delete director;
  delete builder;

  return 0;
}
```
从客户端代码可以看到，客户端只需指定具体建造者，并作为参数传递给指挥者，通过指挥者即可得到结果。客户端无需关心House的建造方法和具体流程。如果要更换建造风格，只需更换具体建造者即可，不同建造者之间并无任何关联，方便替换。从代码优化角度来看，其实可以不需要指挥者Director的角色，而直接把construct方法放入具体建造者当中。


## 建造者模式总结
- 优点：
  - 建造者模式中，客户端不需要知道产品内部组成细节，将产品本身和产品的创建过程分离，使同样的创建过程可以创建不同的产品对象；
  - 不同建造者相互独立，并无任何挂链，方便替换。

- 缺点：
  - 建造者模式所创建的产品一般具有较多的共同点，其组成部分相似，如果产品之间的差异性很大，则不适合使用建造者模式，因此其使用范围受到一定的限制。
  - 如果产品的内部变化复杂，可能会导致需要定义很多具体建造者类来实现这种变化，导致系统变得很庞大

- 适用环境：
  - 需要生成的产品对象有复杂的内部结构（通常包含多个成员变量）；
  - 产品对象内部属性有一定的生成顺序；
  - 同一个创建流程适用于多种不同的产品。


# 原型模式
原型模式通过复制一个已有对象来获取更多相同或者相似的对象。原型模式定义如下：

> **原型模式**:
使用原型实例指定待创建对象的类型，并且通过复制这个原型来创建新的对象。

原型模式的工作原理是将一个原型对象传给要发动创建的对象（即客户端对象），这个要发动创建的对象通过请求原型对象复制自己来实现创建过程。  
从工厂方法角度而言，创建新对象的工厂就是原型类自己。软件系统中有些对象的创建过程比较复杂，且有时需要频繁创建，原型模式通过给出一个原型对象来指明所要创建的对象的类型，然后用复制这个原型对象的办法创建出更多同类型的对象，这就是原型模式的意图所在。

## 原型模式结构
原型式的结构包含以下几个角色
- **抽象原型类**（AbstractPrototype）: 声明克隆clone自身的接口
- **具体原型类**（ConcretePrototype）: 实现clone接口
- **客户端**（Client）: 客户端中声明一个抽象原型类，根据客户需求clone具体原型类对象实例


# 装饰模式

**装饰模式**，动态地给一个对象增加一些额外的职责。就扩展功能而言，装饰模式提供了一种比使用子类更加灵活的替代方案。

> 装饰模式是一种用于替代继承的技术。通过一种无须定义子类的方式给对象动态增加职责，使用对象之间的关联关系取代类之间的继承关系。装饰模式中引入了装饰类，在装饰类中既可以调用待装饰的原有对象的方法，还可以增加新的方法，以扩充原有类的功能。

## 装饰模式结构
- **抽象构件**(Component)
  > 是具体构件类和装饰类的共同基类，声明了在具体构件中定义的方法，客户端可以一致的对待使用装饰前后的对象；

- **具体构件**(ConcreteComponent)
  > 具体构件定义了构件具体的方法，装饰类可以给它增加更多的功能；
  
- **抽象装饰类**(Decorator)
  > 用于给具体构件增加职责，但具体职责在其子类中实现。抽象装饰类通过聚合关系定义一个抽象构件的对象，通过该对象可以调用装饰之前构件的方法，并通过其子类扩展该方法，达到装饰的目的；
  
- **具体装饰类**(ConcreteDecorator)
  > 向构件增加新的功能。





