# 目录
- [目录](#目录)
- [建造者模式](#建造者模式)
  - [建造者模式代码实例](#建造者模式代码实例)
  - [建造者模式总结](#建造者模式总结)
- [原型模式](#原型模式)
  - [原型模式结构](#原型模式结构)
- [装饰模式](#装饰模式)
  - [装饰模式结构](#装饰模式结构)
  - [装饰模式总结](#装饰模式总结)
- [观察者模式](#观察者模式)
  - [观察者模式结构](#观察者模式结构)
- [总结](#总结)

设计模式
# 建造者模式
建造者模式的结构包含以下几个角色：

**抽象建造者（AbstractBuilder）**  
创建一个Product对象的各个部件指定的抽象接口；

**具体建造者（ConcreteBuilder）**  
实现AbstractBuilder的接口，实现各个部件的具体构造方法和装配方法，并返回创建结果。

**产品（Product）**  
具体的产品对象

**指挥者（Director）**  
构建一个使用Builder接口的对象，安排复杂对象的构建过程，客户端一般只需要与Director交互，指定建造者类型，然后通过构造函数或者setter方法将具体建造者对象传入Director。它主要作用是，隔离客户与对象的生产过程，并负责控制产品对象的生产过程。

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


## 装饰模式总结
**优点**
- 对于扩展一个类的新功能，装饰模式比继承更加灵活；
- 动态扩展一个对象的功能；
- 可以对一个对象进行多次装饰（如上述例子第二个手机和第三个手机）；
- 具体构件类和具体装饰类可以独立变化和扩展，符合开闭原则。

**缺点**
- 装饰模式中会增加很多小的对象，对象的区别主要在于各种装饰的连接方式不同，而并不是职责不同，大量小对象的产生会占用较多的系统资源；
- 装饰模式比继承模式更灵活，但也更容易出错，更难于排错。

**适用场景**
- 在不影响其他对象的情况下，给单个对象动态扩展职责； 
- 不适宜采用继承的方式进行扩展的时候，可以考虑使用装饰模式。


# 观察者模式
软件系统中的对象并不是孤立存在的，一个对象行为的改变可能会引起其他所关联的对象的状态或行为也发生改变，即“牵一发而动全身”。观察者模式建立了一种一对多的联动，一个对象改变时将自动通知其他对象，其他对象将作出反应。观察者模式中，发生改变的对象称为“观察目标”，被通知的对象称为“观察者”。一个观察目标可以有很多个观察者。

> **观察者模式** : 定义对象之间的一种一对多的依赖关系，使得每当一个对象状态发生改变时，其相关依赖对象都得到通知并被自动更新。

观察者模式又被称为发布-订阅模式（Publish-Subscribe）、模型-视图模式（Model-View）、源-监听器模式（Source-Listener）、从属者模式（Dependents）。 

## 观察者模式结构
**Subject（目标）**  
是被观察的对象，目标中定义了一个观察者的集合，即一个目标可能会有多个观察者，通过attach()和detach()方法来增删观察者对象。目标声明了通知方法notify()，用于在自身状态发生改变时通知观察者。  

**ConcreteSubject（具体目标）**  
具体目标实现了通知方法notify()，同时具体目标有记录自身状态的属性和成员方法；

**Observer（观察者）**  
观察者将对接收到的目标发生改变的通知做出自身的反应，抽象层声明了更新方法update()；  

**ConcreteObserver（具体观察者）**  
实现了更新方法update()，具体观察者中维护了一个具体目标对象的引用（指针），用于存储目标的状态。



# 总结
**创建**
- **单例（Singleton）模式**  
  某个类只能生成一个实例，该类提供了一个全局访问点供外部获取该实例，其拓展是有限多例模式。
- **原型（Prototype）模式**  
  将一个对象作为原型，通过对其进行复制而克隆出多个和原型类似的新实例。
- **工厂方法（Factory Method）模式**  
  定义一个用于创建产品的接口，由子类决定生产什么产品。
- **抽象工厂（AbstractFactory）模式**  
  提供一个创建产品族的接口，其每个子类可以生产一系列相关的产品。
- **建造者（Builder）模式**  
  将一个复杂对象分解成多个相对简单的部分，然后根据不同需要分别创建它们，最后构建成该复杂对象。

**结构**
- **代理（Proxy）模式**  
  为某对象提供一种代理以控制对该对象的访问。即客户端通过代理间接地访问该对象，从而限制、增强或修改该对象的一些特性。
- **适配器（Adapter）模式**  
  将一个类的接口转换成客户希望的另外一个接口，使得原本由于接口不兼容而不能一起工作的那些类能一起工作。
- **桥接（Bridge）模式**  
  将抽象与实现分离，使它们可以独立变化。它是用组合关系代替继承关系来实现，从而降低了抽象和实现这两个可变维度的耦合度。
- **装饰（Decorator）模式**  
  动态的给对象增加一些职责，即增加其额外的功能。关键点是装饰，所以实际场景是不想对原有类进行较大改动，而只是装饰。
- **外观（Facade）模式**  
  为多个复杂的子系统提供一个一致的接口，使这些子系统更加容易被访问。
- **享元（Flyweight）模式**  
  运用共享技术来有效地支持大量细粒度对象的复用。
- **组合（Composite）模式**  
  将对象组合成树状层次结构，使用户对单个对象和组合对象具有一致的访问性。
  
**行为**
- **模板方法（TemplateMethod）模式**  
  定义一个操作中的算法骨架，而将算法的一些步骤延迟到子类中，使得子类可以不改变该算法结构的情况下重定义该算法的某些特定步骤。
- **策略模式（Strategy）**  
  定义了一系列算法，并将每个算法封装起来，使它们可以相互替换，且算法的改变不会影响使用算法的客户。
- **命令（Command）模式**  
  将一个请求封装为一个对象，使发出请求的责任和执行请求的责任分割开。
- **职责链（Chain of Responsibility）模式**  
  把请求从链中的一个对象传到下一个对象，直到请求被响应为止。通过这种方式去除对象之间的耦合。
- **状态（State）模式**  
  允许一个对象在其内部状态发生改变时改变其行为能力。
- **观察者（Observer）模式**  
  多个对象间存在一对多关系，当一个对象发生改变时，把这种改变通知给其他多个对象，从而影响其他对象的行为。
- **中介者（Mediator）模式**  
  定义一个中介对象来简化原有对象之间的交互关系，降低系统中对象间的耦合度，使原有对象之间不必相互了解。
- **迭代器（Iterator）模式**  
  提供一种方法来顺序访问聚合对象中的一系列数据，而不暴露聚合对象的内部表示。
- **访问者（Visitor）模式**  
  在不改变集合元素的前提下，为一个集合中的每个元素提供多种访问方式，即每个元素有多个访问者对象访问。
- **备忘录（Memento）模式**  
  在不破坏封装性的前提下，获取并保存一个对象的内部状态，以便以后恢复它。
- **解释器（Interpreter）模式**  
  提供如何定义语言的文法，以及对语言句子的解释方法，即解释器。
 

**7种重点模式**

>这7种模式，基本涵盖了开闭思想的绝大部分体现。掌握这7种模式。就可以说知道了23中模式吧。
- **工厂模式**  
  是开闭原则的最佳体现。 工厂内部对修改开放也就是对变化开发。使用工厂的地方对修改关闭。
- **桥接模式**  
  代表了多维变化的处理思路。
- **装饰模式**  
  让原类不变的前提下，动态的扩展原类的某方法。是组合优于继承的体现。继承就像一个专属模板 hardcode，而装饰这种就是活字印刷。
- **观察者**  
  代表了 类之间基本的事件处理。回调这个是现代语言的基础。
- **状态模式**  
  代表了把行为本身对象化的思想，方便状态增删的情况下扩展行为。
- **命令模式**  
  行为不再属于一个对象的方法。而是把方法作为一个类，方法的执行者反而是一个参数。这样方便一起需要把动作作为对象的场景，如，动作的排序，组合，撤销等以动作为主体的场景。
- **迭代器模式**  
  代表通过组合让变化移除原类的思路。