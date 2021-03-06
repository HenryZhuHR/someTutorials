#ifndef __DECORATOR_PATTERN_H__
#define __DECORATOR_PATTERN_H__

//抽象构件
class Component
{
public:
  Component() {}
  virtual void operation() = 0;
};

//具体构件类
class Phone : public Component
{
public:
  Phone() {}
  void operation() { printf("Phone\n"); }
};


//抽象装饰类
class Decorator : public Component
{
private:
  Component* component;

public:
  Decorator() {}
  Decorator(Component* c) { this->component = c; }
  void       operation() { this->component->operation(); }
  Component* getComponent() { return this->component; }
  void       setComponent(Component* c) { this->component = c; }
};

//具体装饰类：手机壳
class DecoratorShell : public Decorator
{
public:
  DecoratorShell() {}
  DecoratorShell(Component* c) { this->setComponent(c); }
  void operation()
  {
    this->getComponent()->operation();
    this->newBehavior();
  }
  void newBehavior() { printf("Phone shell\n"); }
};

//具体装饰类：手机贴纸
class DecoratorSticker : public Decorator
{
public:
  DecoratorSticker() {}
  DecoratorSticker(Component* c) { this->setComponent(c); }
  void operation()
  {
    this->getComponent()->operation();
    this->newBehavior();
  }
  void newBehavior() { printf("Phone sticker\n"); }
};

//具体装饰类：手机挂绳
class DecoratorRope : public Decorator
{
public:
  DecoratorRope() {}
  DecoratorRope(Component* c) { this->setComponent(c); }
  void operation()
  {
    this->getComponent()->operation();
    this->newBehavior();
  }
  void newBehavior() { printf("Phone rope\n"); }
};
#endif //__DECORATOR_PATTERN_H__