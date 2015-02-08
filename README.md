[![Qt Pods](http://qt-pods.org/assets/logo.png "Qt Pods")](http://qt-pods.org)

QtVerbalExpressions
===================

## Qt Regular Expressions made easy

This Qt lib is based off of the C++ [VerbalExpressions](https://github.com/VerbalExpressions/CppVerbalExpressions) library by [whackashoe](https://github.com/whackashoe).

### Testing if we have a valid URL

```cpp
auto expression = QVerbalExpressions()
  .searchOneLine()
  .startOfLine()
  .then("http")
  .maybe("s")
  .then("://")
  .maybe("www.")
  .anythingBut(" ")
  .endOfLine();

qDebug()
  << expression // ^(?:http)(?:s)?(?:://)(?:www.)?(?:[^ ]*)$
  << expression.test("https://www.google.com"); // true
```

##API 

### Terms
* .anything()
* .anythingBut(const QString& value)
* .something()
* .somethingBut(const QString& value)
* .endOfLine()
* .find(const QString& value)
* .maybe(const QString& value)
* .startOfLine()
* .then(const QString& value)

### Special characters and groups
* .any(const QString& value)
* .anyOf(const QString& value)
* .br()
* .lineBreak()
* .range(const std::initializer_list<QString>& args)
* .tab()
* .word()

### Modifiers
* .withAnyCase()
* .searchOneLine()
* .searchGlobal()

### Functions
* .replace(const QString& source, const QString& value)
* .test()

### Other
* .add(expression)
* .multiple(const QString& value)
* .alt()
