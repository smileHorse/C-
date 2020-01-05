# gSoap起步

## 1 起步

gSoap发布包中提供了两个工具：

- wsdl2h：WSDL/schema转换器和数据绑定工具
- soapcpp2：stub/skeletion编译器和代码生成器

## 2 开发一个WebService客户端程序

​	gSoap工具通过使用由高级XML模式分析器和源码到源码的代码生成工具实现了C和C++的XML数据绑定，最大限度地减少了构建WebService应用程序的适应工作。gSoap的**wsdl2h**工具导入一个或多个**WSDL**和XML模式，并使用大家所熟悉的C/C++语法生成gSoap头文件，以定义WebService操作和C/C++数据类型。然后，gSoap的**soapcpp2**编译器获取此头文件，并为数据类型(soapH.h和soapC.cpp)、客户端存根(soapClient.cpp)、服务端框架(soapServer.cpp)生成XML序列化程序。

​	gSoap的**soapcpp2**编译器还可以生成用于从头开始实现服务的WSDL定义，即不用首先定义WSDL。这将“关闭循环”，因为它可以从WSDL开始进行WEB服务开发，也可以从定义在一个头文件中的一系列C/C++操作进行开发，而不用用户去分析WEB服务的详细信息。

​	只需按照几个步骤从命令行或Makefile文件中执行工具。例如，要为计算器WEB服务生成代码，我们在命令行中对WSDL的URL运行wsdl2h工具，并使用-o选项指定输出文件

~~~
wsdl2h -o calc.h http://www.genivia.com/calc.wsdl
~~~

​	这将生成**calc.h**服务定义头文件，其中包含服务操作定义和操作数据的类型。然后使用**soapcpp2**处理此头文件以生成存根stub和/或框架skeleton代码，和XML序列化例程。**calc.h**文件包含所有的文档，因此可以使用Doxygen自动生成开发的文档页面。

​	wsdl2h生成的服务定义头文件还包含有关服务使用的信息，例如应用时的WS-Policy断言。

​	在这个例子中，我们为计算器服务开发一个C++API。默认情况下，gSoap默认使用带有STL的C++，如果是不使用STL的情况，请使用选项-s：

~~~
wsdl2h -s -o calc.h http://www.genivia.com/calc.wsdl
~~~

​	要构建纯C应用程序，请使用选项-c：

~~~
wsdl2h -c -o calc.h http://www.genivia.com/calc.wsdl
~~~

​	**注意：**Visual Studio用户应确保以C++编译模式编译所有的gSoap源文件。如果需要迁移到项目文件.vcproj，请在.vcproj文件中设置CompileAs=“2”。目前还没有为C/C++API生成存根，为此，请运行soapcpp2编译器：

~~~
soapcpp2 -i -C -limport calc.h
~~~

​	选项-i(和备选选项-j)表示我们需要包含客户端和服务端代码的C++代理和服务对象。-C表示只需要客户端文件(soapcpp2默认生成客户端存根和服务端框架)。选项-l需要从gSoap包中的import目录导入stl  vector.h文件，以支持STL Vectors的序列化。

​	假设我们使用 `wsdl2h -o calc.h http://www.genivia.com/calc.wsdl `和`soapcpp2 -i -C calc.h `为计算器服务开发一个C++客户端。我们使用生成的soapcalcProxy类和calc.nsmap XML命名空间映射表来访问WEB服务。soapcalcProxy类是调用服务的代理：

~~~c++
#include "soapcalcProxy.h"
#include "calc.nsmap"
int main()
{
    calcProxy service;
    double result;
    if (service.add(1.0, 2.0, result) == SOAP_OK)
    	std::cout << "The sum of 1.0 and 2.0 is " << result << std::endl;
    else
    	service.soap_stream_fault(std::cerr);
    service.destroy(); // delete data and release memory
}
~~~

​	要完成构建，我们需要上面的代码并使用生成的soapC.cpp、soapcalcProxy.cpp和运行时gSoap引擎-lgsoap++(如果没有安装libgsoap++，请使用stdsoap2.cpp源文件)进行编译和链接。

​	假设我们使用 `wsdl2h -c -o calc.h http://www.genivia.com/calc.wsdl `和`soapcpp2 -C calc.h `为计算器服务开发一个C客户端。这种情况下，我们的代码使用一个简单的C函数调用来调用服务，我们还需要使用soap_end和soap_free显示删除数据和上下文。

~~~c
#include "soapH.h"
#include "calc.nsmap"
int main()
{
    struct soap *soap = soap_new();
    double result;
    if (soap_call_ns_add(soap, 1.0, 2.0, &result) == SOAP_OK)
    	printf("The sum of 1.0 and 2.0 is %lg\n", result);
    else
    	soap_print_fault(soap, stderr);
    soap_end(soap);
    soap_free(soap);
}
~~~

## 3 开发WEB服务端

​	假设我们实现了一个基于CGI的服务，该服务返回GMT格式的时间。通用网关接口CGI是一种在网站上发布服务的简单机制。

​	这里我们从一个包含服务定义的gSoap头文件currentTime.h开始。当WSDL可用时，可以使用wsdl2h从WSDL获取此类文件。当WSDL不可用时，可以新建一个头文件，并使用C/C++定义服务，然后使用gSoap工具生成源码和WSDL。

​	currentTime服务只有一个输出参数，它是currentTime.h gSoap服务规范中定义的当前时间：

~~~c++
// File: currentTime.h
//gsoap ns service name: currentTime
//gsoap ns service namespace: urn:currentTime
//gsoap ns service location: http://www.yourdomain.com/currentTime.cgi
int ns__currentTime(time_t& response);
~~~

​	请注意，我们将XML命名空间前缀ns和命名空间名称currentTime与服务WSDL和SOAP/XML消息相关联。gSoap工具对作为命名空间一部分的标识符名称使用特殊约定：命名空间前缀(本例中为ns)后跟双下划线。此约定用于解析命名空间和避免名称冲突。ns命名空间前缀使用//gsoap指令绑定到urn:currentTime命名空间名称。//gsoap指令用于设置服务的属性，在本例中为名称、名称空间和位置端点。

​	CGI的服务实现需要在使用soap_new创建的soap上下文中进行soap服务调用。服务操作作为函数实现，由RPC调度程序调用soap_server:

~~~c++
// File: currentTime.cpp
#include "soapH.h" // include the generated declarations
#include "currentTime.nsmap" // include the XML namespace mappings
int main()
{
    // create soap context and serve one CGI-based request:
    return soap_serve(soap_new());
}
int ns__currentTime(struct soap *soap, time_t& response)
{
    response = time(0);
    return SOAP_OK;
}
~~~

​	请注意，我们将带有gSoap上下文信息的soap结构传递给服务例程。这可以用来确定连接的属性，并使用soap_malloc(soap, num_bytes)动态分配数据，这些数据将在服务完成时自动删除。

​	我们在头文件上运行soapcpp2编译器来生成服务器端的代码：

~~~
soapcpp2 -S currentTime.h
~~~

​	然后编译二进制CGI：

~~~
c++ -o currentTime.cgi currentTime.cpp soapC.cpp soapServer.cpp stdsoap2.cpp
~~~

​	或者安装了libgsoap++的情况下，使用链接代替stdsoap2.cpp源文件：

~~~
c++ -o currentTime.cgi currentTime.cpp soapC.cpp soapServer.cpp -lgsoap++
~~~

​	要激活服务，请使用适当的文件权限将currentTime.cgi文件复制到bin-cgi目录中。

​	soapcpp2工具生成了WSDL定义文件currentTime.wsdl。可以使用它来宣传你的服务。不需要使用这个WSDL来开发gSoap客户端。可以使用带有-C选项的soapcpp2对currentTime.h文件来生成客户端代码。

​	CGI的一个方便之处在于它通过标准输入/输出交换信息。因此可以运行CGI二进制程序，在自动生成的示例上请求XML文件来测试这个服务：

~~~
./currentTime.cgi < currentTime.currentTime.req.xml
~~~

​	这将在SOAP XML中显示服务器的响应。

​	上述方法同样适用于纯C程序。除了-S选项外，使用-c选项来生成ANSI C代码。在C中我们使用指针来代替引用，并且调整currentTime.h文件以使用纯C类型。

​	通过使用soapcpp2的选项-i(或-j)生成C++客户端代理和服务端的服务对象，作为可用于在C++中构建客户端和服务的类，可以获得C++中更优雅的服务器实现。该选项删除了soapClient.cpp和soapServer.cpp的生成，因为当我们有实现客户端和服务器逻辑的类时，就不再需要这些文件了：

~~~
soapcpp2 -i -S currentTime.h
~~~

​	这将生成soapcurrentTimeService.h和soapcurrentTimeService.cpp文件，以及辅助文件soapStub.h(默认情况下包含在所有代码中)和currentTime.nsmap。

​	使用currentTimeService对象，我们将CGI服务器重写为：

~~~c++
// File: currentTime.cpp
#include "soapcurrentTimeService.h" // include the proxy declarations
#include "currentTime.nsmap" // include the XML namespace mappings
int main()
{
    // create server and serve one CGI-based request:
    currentTimeService server;
    server.serve();
    server.destroy();
}
int currentTimeService::currentTime(time_t& response)
{
    response = time(0);
    return SOAP_OK;
}
~~~

编译命令：

~~~
c++ -o currentTime.cgi currentTime.cpp soapC.cpp soapcurrentTimeService.cpp -lgsoap++
~~~

​	要在端口8080上将服务器作为独立的迭代(非多线程)服务器运行，直到accept()超时或发生错误：

~~~c++
if (server.run(8080))
	server.soap_stream_fault(std::cerr);
~~~

​	要忽略常见的错误，直到发生TCP错误：

~~~C++
while (server.run(8080) != SOAP_OK)
{
    if(server.soap->error == SOAP_TCP_ERROR)
    	break;
    server.soap_stream_fault(std::cerr);
}
~~~

​	要建立一个多线程的服务，请参考其他章节。

## 4 XML 数据绑定

​	即如何将模式（XSD文件）映射到C/C++绑定以自动读取和写入XML数据。

​	gSoap中的XML C/C++数据绑定提供了自动化机制，可以用XML编码任何C和C++数据类型（并将XML解码回C/C++数据）。XML模式（XSD文件）可以转换为一组C或C++定义，这些定义可以很容易的合并到应用程序中，以便比DOM和SAX更轻松地操作XML。实质上，XML模式中的每个XML组件定义都具有C/C++数据类型表示，该表示具有等效的类型属性。当我们查看映射到类的XSD complexType时，这种方法的优势立即显现出来：

XSD：

~~~xml
<complexType name="Address"> 
    <sequence> 
        <element name="name" type="string"/> 
        <element name="home" type="tns:Location" minOccurs="0"/> 
        <element name="phone" type="unsignedLong"/> 
        <element name="dob" type="dateTime"/> 
    </sequence>
    <attribute name="ID" type="int" use="required"/> 
</complexType> g
~~~

C++：

~~~c++
class ns__Address
{
    std::string name;
    ns__Location *home;
    ULONG64 phone;
    time_t dob;
    @int ID;
}
~~~

​	通过这种方式，可以创建XML模式的XML元素与类成员之间的自动映射。不需要DOM遍历或SAX事件。此外，XML C/C++数据绑定使XML操作类型安全。即，C/C++的类型安全性确保只能解析和生成有效的XML文档。

​	wsdl2h工具自动执行WSDL和XML模式到C/C++的映射。wsdl2h的输出是带注释的头文件，其中包含有关在SOAP/XML客户端/服务端应用程序或使用自动生成的序列化程序读取和写入XML的通用应用程序中如何使用C/C++声明的注释和文档。

​	举例说明，假设我们有一个带有book数据的XML文档：

~~~xml
<book isbn="1234567890">
    <title>Farewell John Doe</title>
    <publisher>ABC’s is our Name</publisher>
</book>
~~~

​	定义book元素和类型的XML模式示例可以是：

~~~xml
<schema ...>
    <element name="book">
        <complexType>
            <sequence>
                <element name="title" type="string" minOccurs="1"/>
                <element name="publisher" type="string" minOccurs="1"/>
            </sequence>
            <attribute name="isbn" type="unsignedLong" use="required"/>
        </complexType>
    </element>
</schema>
~~~

​	使用wsdl2h，我们将定义书籍类型和根元素的XML模式转换为类定义：

~~~c++
class book
{
    @ULONG64 isbn;
    std::string title;
    std::string publisher;
}
~~~

​	请注意，@等注释用于区分属性和元素。这些注释是gSoap定义的，并由soapcpp2工具处理，以生成用于读取和写入XML的数据类型的序列化程序。

​	soapcpp2工具生成所有必要的代码来解析和生成book对象的XML。验证约束(例如minOccurs="1"和 use="required")作为检查包含在生成的代码中。

​	要编写book的XML表示，我们首先创建一个soap引擎上下文，并将其与soap_write_book(由soapcpp2生成)一起使用，将XML中的对象写入到标准输出：

~~~c++
soap *ctx = soap_new1(SOAP_XML_INDENT); // new context with option
book bk;
bk.isbn = 1234567890;
bk.title = "Farewell John Doe";
bk.publisher = "ABC’s is our Name";
if (soap_write_book(ctx, &bk) != SOAP_OK)
	... error ...
soap_destroy(ctx); // clean up allocated class instances
soap_end(ctx); // clean up allocated temporaries
soap_free(ctx); // delete context
~~~

​	ctx是gSoap引擎上下文，用来控制设置和保持状态。例如XML格式化(SOAP_XML_INDENT)，序列化选项，当前状态和I/O设置。只需设置上下文的输出流(std::ostream)ctx->os即可重定向内容，例如到文件或字符串。此外，在序列化图形而不是XML树(SOAP_XML_TREE强制为XML树)时，XML的输出符合基于id-ref的对象图的SOAP编码。详细信息请参考其他章节。

​	要从标准输入读取XML表示形式到book对象，请使用：

~~~c++
soap *ctx = soap new1(SOAP_XML_STRICT); // new context with option
book bk;
if (soap_read_book(ctx, &bk) != SOAP_OK) 
    ... error ...
else
	cout << bk.isbn << ", " << bk.title << ", " << bk.publisher << endl;
... further use of bk ...
soap_destroy(ctx); // delete deserialized objects
soap_end(ctx); // delete temporaries
soap_free(ctx); // delete context
~~~

​	自动内置的严格XML验证(使用SOAP_XML_STRICT启用)可确保数据成员存在，因此我们可以在示例中安全地打印它们，从而确保数据与XML模式的一致性。设置ctx->is输入流以从文件/字符串而不是标准输入中读取。soap_destroy和soap_end调用取消分配反序列化的内容，因此请小心使用。通常，gSoap中的内存管理是自动的，以避免泄露。

​	除了上面这种简单示例外，gSoap工具包处理所有由XML模式标准定义的XML模式构造。该工具包还能够(反)序列化基于指针的C/C++数据结构(包括循环图)，结构/类，联合，枚举，STL容器，甚至是特殊数据类型，例如tm。因此，该工具包在两个方向上工作：从WSDL/Schema到C/C++，从C/C++到WSDL/Schema。

​	gSoap工具包还处理多个命名空间中定义的多个模式。通常，XML命名空间中的命名空间前缀会添加到C/C++类型定义中，以确保类型唯一。例如，我们在一个应用程序中需要合并两个模式，这两个模式都定义了book对象，我们就需要解决这个冲突。在gSoap中，这是使用命名空间前缀而不是C++命名空间来完成的(研究已经指出XML命名空间不等于C++命名空间)。因此，book类实际上可能绑定到XML命名空间，并且将类命名为ns__book，其中ns绑定到相应的命名空间。以下选项可用来控制序列化：

~~~
soap->encodingStyle = NULL; // to remove SOAP 1.1/1.2 encodingStyle
soap_mode(soap, SOAP XML TREE); // XML without id-ref (no cycles!)
soap_mode(soap, SOAP XML GRAPH); // XML with id-ref (including cycles)
soap_set_namespaces(soap, struct Namespace *nsmap); //to set xmlns bindings
~~~

​	其他标志和有关C/C++的XML数据绑定支持的详细信息，请参考其他章节。

## 5 特性

gSoap的亮点是：

- 独特的互操作性功能：这些工具生成类型安全的SOAP编码例程，以(反)序列化原生的和用户自定义的C/C++数据结构。
- 支持WSDL 1.1，WSDL 2.0，REST，SOAP 1.1，SOAP 1.2，SOAP RPC编码样式和文档/文字样式。 gSOAP是为数不多的SOAP工具包之一，它支持所有SOAP 1.1 RPC编码功能，包括稀疏多维数组和多态类型。例如，具有基类参数的服务操作可以接受来自客户端的派生类实例。派生类实例通过动态绑定保持其身份。该工具包还支持所有XSD 1.0和1.1模式类型构造，并已针对W3C XML Schema Patterns for Databinding Interoperability工作组和gSOAP版本2.8.x进行了测试，并通过了所有测试。
- 支持WS-Security，WS-Addressing，WS-ReliableMessaging，C14N 独家规范化。使用wsdl2h和soapcpp2生成代码来实现协议。 gSOAP工具可用于为其他WS- *协议生成消息传递协议。
- gSOAP支持XML-RPC和RSS协议。提供了示例。
- JSON支持包含在XML-RPC库中，用于在XML-RPC和JSON协议之间切换。有关更多详细信息，请参阅包中的samples / xml-rpc-json文件夹。
- wsdl2h工具支持WS-Policy。策略断言包含在生成的服务描述头文件中，其中包含建议和使用提示。
- gSOAP支持MIME（SwA），DIME和MTOM附件，并具有流式处理功能，可将数据流引导至资源或从资源引导数据流。 gSOAP是唯一支持流式MIME，DIME和MTOM附件传输的工具包，它允许您以最快的方式（流式传输）交换几乎无限大小的二进制数据，同时确保XML互操作性的有用性。
- gSOAP支持SOAP-over-UDP。
- gSOAP支持IPv4和IPv6。
- gSOAP支持Zlib deflate和gzip压缩（适用于HTTP，TCP / IP， 和XML文件存储）。
- gSOAP使用OpenSSL支持SSL（HTTPS），并可选择使用GNUTLS。
- gSOAP使用插件支持HTTP / 1.0，HTTP / 1.1保持活动，分块，基本身份验证和摘要身份验证。
- gSOAP支持SOAP单向消息传递。
- 特定于模式的XML pull解析器快速而有效，并且不需要中间数据存储来进行解组以节省空间和时间。
- soapcpp2编译器包含一个WSDL和模式生成器，用于方便的Web服务发布。
- soapcpp2编译器生成用于验证和测试的示例输入和输出消息（在编写任何代码之前）。选项（-T）可用于自动实现回显消息服务以进行测试。
- wsdl2h工具将WSDL和XSD文件转换为gSOAP头文件，以进行自动客户端和服务器开发。
- 为独立Web服务和客户端应用程序生成源代码。
- 适用于Palm OS，Symbian，Pocket PC等小型设备，因为内存占用空间小。
- 非常适合构建计算密集型Web服务，因此最好用C和C ++编写。
- 独立于平台：Windows，Unix，Linux，Mac OS X，Pocket PC，Palm OS，Symbian，VXWorks等。
- 支持序列化应用程序的本机C和C ++数据结构，允许您在文件中保存和加载XML序列化数据结构。
- 选择性输入和输出缓冲用于提高效率，但不使用完整的消息缓冲来确定HTTP消息长度。相反，使用三阶段序列化方法来确定消息长度。因此，诸如base64编码图像之类的大型数据集可通过PDA等小型存储设备传输或不传输DIME附件。
- 支持C ++单类继承，动态绑定，重载，任意指针结构，如列表，树，图，循环图，固定大小数组，（多维）动态数组，枚举，内置XSD架构类型，包括base64Binary编码，和hexBinary编码。
- 无需为Web服务部署重写现有的C / C ++应用程序。但是，需要修改使用联合的应用程序部分，指向内存中元素序列的指针和void *，但前提是需要将采用它们的数据结构作为服务操作调用的一部分进行序列化或反序列化。
- 三阶段编组：1）指针分析，单引用，多引用和循环数据结构，2）HTTP消息长度确定，以及3）根据SOAP 1.1编码样式或用户定义的编码样式的序列化。
- 两阶段解组：1）SOAP解析和解码，其涉及从有效载荷重建多参考和循环数据结构，以及2）“前向”指针的解析（即SOAP中前向href属性的解析）。
- 完整且可自定义的SOAP Fault处理（客户端接收和服务发送）。
- 可自定义的SOAP标头处理（发送和接收），例如，它使服务的简单事务处理能够保持状态信息。

