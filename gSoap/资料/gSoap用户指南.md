# gSoap用户指南

​	本用户指南提供了快速开始使用gSOAP的方法。 本节需要对SOAP协议有基本的了解，并且需要熟悉C/C ++。 原则上，SOAP客户端和SOAP Web服务可以使用gSOAP soapcpp2编译器在C和C ++中开发，而无需详细了解SOAP协议，当gSOAP客户端 - 服务器应用程序构建为ensamble并且仅在该组内进行通信时（即意味着 您不必担心与其他SOAP实现的互操作性）。 本节旨在说明连接到其他SOAP实现（如Apache Axis，SOAP :: Lite和.NET）并与之互操作的gSOAP Web服务和客户端的实现。 这需要了解SOAP和WSDL协议的一些细节。

## 1 构建SOAP/XML客户端

​	通常，SOAP客户端应用程序的实现需要客户端调用每个服务端操作的Stub(也称为服务代理)。Stub的主要职责是对参数进行编组，将带有参数的请求发送到指定的SOAP服务，等待服务端响应，并在响应到达时对返回的数据进行解组。客户端调用服务端操作的Stub就像调用本地函数一样。手动编写C/C++中的Stub是一项繁琐的工作，特别是服务端操作的输入/输出参数包含复杂的数据结构，比如对象、结构、容器、数组和指针链接的图形结构。幸运的是，gSoap的wsdl2h WSDL解析器工具和soapcpp2 stub/skeleton和序列化代码生成器工具可自动化SOAP/XML WEB服务端和客户端应用程序的开发。

​	soapcpp2工具生成必要的粘合代码(也称为stub/skeleton)以构建WEB服务的服务端和客户端。soapcpp2工具的输入包含一个服务定义注释的C/C++头文件。头文件可以使用gSoap的wsdl2h WSDL解析器工具从服务的WSDL文档生成。如：

~~~
wsdl2h -o calc.h http://www.genivia.com/calc.wsdl
~~~

​	这将在带注释的C++头文件中生成WEB服务描述文件calc.h。WSDL规范(可能由多个导入的WSDL文件和XSD模式文件组成)使用C++数据绑定将SOAP/XML映射到C++。生成的头文件包含用于操作服务的数据类型和消息，以及与WSDL和XML模式相关的元信息。要生成服务定义头文件以开发纯C客户端应用程序，使用`-c`选项：

~~~
wsdl2h -c -o calc.h http://www.genivia.com/calc.wsdl
~~~

​	calc.h头文件由soapcpp2编译器进一步处理，用来生成粘合代码，以从客户端来调用WEB服务。查看calc.h头文件，我们看到SOAP服务方法被指定为函数原型。例如，add函数添加两个double floats:

~~~
int ns2_add(double a, double b, double& result);
~~~

​		ns2_add函数使用XML命名空间前缀将其与其他命名空间中定义的操作区分开来，从而防止名称冲突。向操作、类型、结构和类成员的名称添加XML命名空间前缀的约定由gSoap工具普遍使用并由wsdl2h自动创建，但在将现有C/C++类型和操作转换为Web服务时不是必需的。因此，可以从头文件中定义的类型名称中省略前缀表示法，以运行soapcpp2来创建交换现有数据类型的客户端和服务端。

​	这些函数原型由soapcpp2工具转换为远程调用的存根(stub)和代理(proxy)：

| soapStub.h     | 输入定义的注释副本 |
| -------------- | ------------------ |
| soapH.h        | 序列化器           |
| soapC.cpp      | 序列化器           |
| soapClient.cpp | 客户端调用存根     |

​	因此，生成存根例程的逻辑允许C/C++客户端应用程序与现有的SOAP WEB服务无缝交互。如下一节中的客户端代码示例。

​	SOAP服务端操作的输入/输出可以是原始数据类型和复杂数据类型，如容器和基于指针的链接数据结构。这些是在头文件中定义的，该头文件由WSDL解析器生成或手动编写。soapcpp2工具自动为数据类型生成XML序列化器和反序列化器，以使生成的存根例程能够对SOAP/XML中服务操作的参数进行编码和解码。

​	请注意，soapcpp2工具还为头文件中指定的每个服务操作生成框架例程soapServer.cpp。框架例程可以很容易的用在新的SOAP WEB服务中实现一个或多个服务操作。这些框架例程不用于在C++中构建SOAP客户端，尽管它们可用于构建混合SOAP客户端/服务端的应用程序。

### 1.1 示例

​	calc.h文件中声明的add操作计算两个浮点数的和。该服务的WSDL描述文件中提供了能够调用的服务操作的端点号和操作所使用的命名空间：

~~~
Endpoint URL: http://websrv.cs.fsu.edu/ engelen/calcserver.cgi
XML namespace: urn:calc
~~~

​	每个服务操作都有一个SOAP action，它是一个可选的字符串，用于标识操作(主要用于WS-Addressing)，操作请求信息和响应信息。SOAP RPC编码服务的请求和响应信息仅由具有输入和输出参数的C函数来表示。对于add操作，SOAP绑定的详细信息为：

~~~
SOAP style: RPC
SOAP encoding: encoded
SOAP action: "" (empty string)
~~~

​	这些信息将转换为带有服务定义的wsdl2h生成的头文件。由wsdl2h生成的calc.h头文件包含了如下指令和声明：

~~~c++
//gsoap ns2  service name:	calc 
//gsoap ns2  service type:	calcPortType 
//gsoap ns2  service port:	http://websrv.cs.fsu.edu/~engelen/calcserver.cgi 
//gsoap ns2  service namespace:	urn:calc 
//gsoap ns2  service transport:	http://schemas.xmlsoap.org/soap/http 

//gsoap ns2  service method-protocol:	add SOAP
//gsoap ns2  service method-style:	add rpc
//gsoap ns2  service method-encoding:	add http://schemas.xmlsoap.org/soap/encoding/
//gsoap ns2  service method-action:	add ""
//gsoap ns2  service method-output-action:	add Response
int ns2__add(
    double    :a,	///< Input parameter, : unqualified name as per RPC encoding
    double    :b,	///< Input parameter, : unqualified name as per RPC encoding
    double    &:result	///< Output parameter, : unqualified name as per RPC encoding
);
~~~

​	soapcpp2工具需要//gsoap指令来生成符合SOAP协议的代码。对于这个服务，使用具有通用"RPC编码样式"的SOAP协议。有关//gsoap命令的详细信息，参阅19.2节。

​	服务操作被声明为函数原型，在头文件中声明所有操作所需的非原始参数类型。

​	add操作带有两个double参数，并返回为和的结果。按照惯例，除最后一个参数外，其他参数全部为输入参数，最后一个参数是输出参数。结构和类用于包装多个输出参数，详细参见7.1.9节。最后一个参数必须是指针或引用。相反，输入参数支持按值传递或按指针传递，不支持传递引用。

​	与服务操作相关联的函数原型总是返回一个int。该值表示成功(0或SOAP_OK)或失败(任何非零值)。有关非零错误码，参见10.2节。

​	命名空间前缀ns2在服务操作名称中的作用会在后面详细讨论。基本上，命名空间前缀被添加到具有一对下划线的函数名称或类型名称中，如ns2__add，其中ns2是命名空间前缀，add是服务操作名称。此机制可确保与服务关联的操作和类型的唯一性。

​	强烈建议将命名空间前缀设置为你自定义的名称。这避免了在多个WSDL上运行wsdl2h时出现的问题，其中前缀ns1、ns2等序列被任意分配给服务。要为服务的所有操作和类型选择前缀名称，例如设置计算器服务的前缀为c__，请将下面的行添加到`typemap.dat`：

~~~
c = "urn:calc"
~~~

​	重新运行wsdl2h。`typemap.dat`配置wsdl2h为服务使用指定的绑定和数据类型。结果是c__add用于唯一标识操作而不是更加任意的名称ns2_add。

​	关于在名称中使用下划线的注意事项：标识符名称中的单个下划线将被转换为XML的破折号，因为与下划线相比，破折号在XML中更常用，参见10.3节。

​	接下来，从命令行中调用soapcpp2工具来处理calc.h服务定义文件：

~~~
soapcpp2 calc.h
~~~

​	这个工具为服务操作生成存根例程。客户端程序可以调用存根例程来调用远程服务操作。生成的存根例程的接口与calc.h定义文件中的函数原型相同，但附加参数用于传递gSoap引擎的运行时上下文soap，端点URL((默认为NULL)和SOAP操作(默认为NULL)。

~~~c++
SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns2__add(struct soap *soap, const char *soap_endpoint, const char *soap_action, double a, double b, double &result);
~~~

​	这个存根例程保存在soapClient.cpp中。soapC.cpp文件包含存根使用的数据类型的序列化程序和反序列化程序。可以使用选项`-c`生成纯C的代码。注意：soap参数必须是指向gSoap运行时上下文的有效指针。可以将设置soap_endpoint去修改默认端点地址(由WSDL定义的端点)，可以设置soap_action去修改缺省SOAP操作。

​	客户端程序调用存根例程的代码：

~~~c++
#include "soapH.h"
#include "calc.nsmap"

#include <iostream>
using namespace std;

int main()
{
	double sum;
	struct soap soap;	// the gSoap runtime context
	soap_init(&soap);	// initialize the context(only once)
	if (soap_call_ns2__add(&soap, NULL, NULL, 1.0, 2.0, sum) == SOAP_OK)
	{
		std::cout << "Sum = " << sum << endl;
	}
	else
	{
		soap_print_fault(&soap, stderr);	//display the SOAP fault message on the stderr stream
	}
	soap_destroy(&soap);
	soap_end(&soap);
	soap_done(&soap);
	return 0;
}
~~~

​	构建该程序，需要包含soapC.cpp、soapClient.cpp和stdsoap2.cpp。

​	该调用在成功时返回SOAP_OK(0)，在失败时返回非零值。发生错误时使用soap_print_fault打印错误信息。或者使用`soap_sprint_fault(struct soap*, char*, size_t)`将错误打印到字符串，使用`soap_stream_fault(struct soap*, std::ostream&)`将错误打印到数据流(仅限C++)。

​	以下函数可用于显示设置gSoap运行时上下文(struct soap)：

| 函数                                                         | 描述                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| soap_init(struct soap *soap)                                 | Initializes a runtime context                                |
| soap_init1(struct soap *soap, soap_mode iomode)              | Initializes a runtime context and set in/out mode flags      |
| soap_init2(struct soap *soap, soap_mode imode, soap_mode omode) | Initializes a runtime context and set in/out mode flags      |
| struct soap *soap_new()                                      | Allocates, initializes, and returns a pointer to a runtime context |
| struct soap *soap_new1(soap_mode iomode)                     | Allocates, initializes, and returns a pointer to a runtime context and set in/out mode flags |
| struct soap *soap_new2(soap_mode iomode, soap_mode omode)    | Allocates, initializes, and returns a pointer to a runtime context and set in/out mode flags |
| struct soap *soap_copy(struct soap *soap)                    | Allocates a new runtime context and copies a context (deep copy, i.e. the new context does not share any data with the other context) |
| soap_done(struct soap *soap)                                 | Reset, close communications, and remove callbacks            |
| soap_free(struct soap *soap)                                 | Reset and deallocate the context created with soap new or soap copy |

​	运行时上下文可根据客户端远程调用的需要重复使用多次，并且不需要重新初始化。每个新线程都需要一个新的上下文，以保证线程对运行时上下文的独占访问。此外，在活动服务方法中使用任何客户端调用都需要一个新的上下文。

​	soapcpp2工具可以使用`-i`或`-j`选项为C++客户端应用程序生成服务代理类：

~~~
soapcpp2 -i calc.h
~~~

​	代理被定义在`soapcalcProxy.h`和`soapcalcProxy.cpp`中。

​	注意：如果没有使用`-i`选项，则只生成旧时服务代理和对象，这些代理和对象灵活性较低，不推荐使用。使用`-j`选项替代`-i`，以生成具有相同功能的类，但不是从struct soap继承并使用指向可与其他代理和服务类共享的struct soap引擎上下文的指针。当服务被链接(chain)时，这种选择也很重要，参见7.2.8节。

​	生成的C++代理类初始化gSoap运行时上下文，并将服务接口作为方法集合提供：

~~~c++
#include "soapcalcProxy.h"
#include "calc.nsmap"

#include <iostream>
using namespace std;

int main() 
{
	calcProxy calc(SOAP_XML_INDENT);
	double sum;
	if (calc.add(1.0, 2.0, sum) == SOAP_OK)
	{
		cout << "Sum: " << sum << endl;
	}
	else
	{
		calc.soap_stream_fault(cerr);
	}
	return calc.error;
}
~~~

​	构建该程序，需要包含soapC.cpp、soapcalcProxy.cpp和stdsoap2.cpp。

​	代理类派生自gSoap运行时上下文结构struct soap，因此继承了运行时的所有状态信息(选项-i)。代理构造函数采用上下文模式参数来初始化上下文，例如本例中的SOAP_XML_INDENT。

​	代理类名称是从WSDL内容中提取的，并不是总是采用短格式。随意更改条目:

~~~
//gsoap ns2 service name: calc
~~~

​	并重新运行soapcpp2以生成使用新名称的代码。

​	调用客户端示例程序时，将执行SOAP请求：

~~~xml
POST / engelen/calcserver.cgi HTTP/1.1
Host: websrv.cs.fsu.edu
User-Agent: gSOAP/2.7
Content-Type: text/xml; charset=utf-8
Content-Length: 464
Connection: close
SOAPAction: ""
<?xml version="1.0" encoding="UTF-8"?>
<SOAP-ENV:Envelope
xmlns:SOAP-ENV="http://schemas.xmlsoap.org/soap/envelope/"
xmlns:SOAP-ENC="http://schemas.xmlsoap.org/soap/encoding/"
xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
xmlns:xsd="http://www.w3.org/2001/XMLSchema"
xmlns:c="urn:calc">
<SOAP-ENV:Body SOAP-ENV:encodingStyle="http://schemas.xmlsoap.org/soap/encoding/">
<c:add>
<a>1</a>
<b>2</b>
</c:add>
</SOAP-ENV:Body>
</SOAP-ENV:Envelope>
~~~

SOAP响应信息为：

~~~xml
HTTP/1.1 200 OK
Date: Wed, 05 May 2010 16:02:21 GMT
Server: Apache/2.0.52 (Scientific Linux)
Content-Length: 463
Connection: close
Content-Type: text/xml; charset=utf-8
<?xml version="1.0" encoding="UTF-8"?>
<SOAP-ENV:Envelope
xmlns:SOAP-ENV="http://schemas.xmlsoap.org/soap/envelope/"
xmlns:SOAP-ENC="http://schemas.xmlsoap.org/soap/encoding/"
xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
xmlns:xsd="http://www.w3.org/2001/XMLSchema"
xmlns:ns="urn:calc">
<SOAP-ENV:Body SOAP-ENV:encodingStyle="http://schemas.xmlsoap.org/soap/encoding/">
<ns:addResponse>
<result>3</result>
</ns:addResponse>
</SOAP-ENV:Body>
</SOAP-ENV:Envelope>
~~~

​	客户端可以调用一系列服务操作：

~~~c++
int main() 
{
	calcProxy calc(SOAP_IO_KEEPALIVE);
	double sum = 0;
	double val[] = { 5.0, 3.5, 7.1, 1.2 };
	for (int i = 0; i < 4; ++i)
	{
		if (calc.add(sum, val[i], sum))
		{
			return calc.error;
		}
	}
	cout << "Sum = " << sum << endl;
	return 0;
}
~~~

​	上面的代码中，删除代理之前不会释放任何数据。要在调用之间释放分配的反序列化数据，请使用：

~~~c++
for (int i = 0; i < 4; ++i)
{
    if (calc.add(sum, val[i], sum))
    {
        return calc.error;
    }
    calc.destroy();
}
~~~

​	在这里重新分配是安全的，因为浮点值被复制并保存在sum中。在其他情况下，必须确保从解除分配链中复制或删除数据：

~~~c++
soap_unlink(struct soap *soap, const void *data)
~~~

​	在销毁被释放的数据之前，要对每个要保留的数据项调用。当删除代理时，也会删除所有的反序列化数据。要将删除委托给另外一个运行时上下文以便后续删除，请使用：

~~~c++
soap_delegate_deletion(struct soap *soap_from, struct soap *soap_to)
~~~

​	例如：

~~~c++
struct soap soap;
soap_init(&soap);
{
    // create proxy
    calcProxy calc;
    //
    // ... data generated ...
    //
    soap_delegate_deletion(&calc, &soap);
} // proxy deleted
//
// ... data used ...
//
soap_destroy(&soap);
soap_end(&soap);
soap_done(&soap);
~~~

​	在纯C代码中，示例程序将写为：

~~~c
#include "soapH.h"
#include "calc.nsmap"

int main()
{
	struct soap soap;
	double sum = 0.0;
	double val[] = {5.0, 3.5, 7.1, 1.2};
	int i;
	for (i = 0; i < 4; ++i)
	{
		soap_init1(&soap, SOAP_IO_KEEPALIVE);
		if (soap_call_ns2__add(&soap, NULL, NULL, sum, val[i], &sum))
		{
			return soap.error;
		}
	}
	printf("Sum = %lg\n", sum);
	soap_end(&soap);
	soap_done(&soap);
	return 0;
}
~~~

​	构建该程序，需要包含soapC.c、soapcalcClient.c和stdsoap2.cpp。

### 1.2 XML 命名空间注意事项

​	ns2_add函数原型的声明使用了服务操作命名空间的命名空间前缀ns2，它由一对下划线进行区分，以将命名空间前缀与服务操作名称分开。命名空间前缀的目的是将服务操作名称与服务相关联，以防止命名冲突。例如，区分不同服务使用的相同服务操作名称。

​	请注意，服务示例的XML响应可能使用不同的命名空间前缀(例如ns)，只要它通过`xmlns:ns="urn:calc"`绑定到相同的命名空间名称`urn:calc`。还需要使用命名空间前缀和命名空间名称来使SOAP应用程序验证SOAP信息的内容。服务响应中的命名空间名称由存根例程通过使用命名空间映射表中提供的信息进行验证，该映射表必须是gSoap客户端和服务端应用程序代码的一部分。在运行时访问该映射表以解析命名空间绑定，包括生成的存根的数据结构序列化器，用于编码客户端请求，以及生成的存根的数据结构反序列化器，用于解码和验证服务端响应。命名空间映射表不应该是soapcpp2工具输入的头文件的一部分。可以在头文件中通过gSoap指令提供包含命名空间绑定的服务详细信息，请参见19.2节。

​	命名空间映射表如下：

~~~xml
struct Namespace namespaces[] =
{ // {"ns-prefix", "ns-name"}
    {"SOAP-ENV", "http://schemas.xmlsoap.org/soap/envelope/"}, // MUST be first
    {"SOAP-ENC", "http://schemas.xmlsoap.org/soap/encoding/"}, // MUST be second
    {"xsi", "http://www.w3.org/2001/XMLSchema-instance"}, // MUST be third
    {"xsd", "http://www.w3.org/2001/XMLSchema"}, // 2001 XML Schema
    {"ns2", "urn:calc"}, // given by the service description
    {NULL, NULL} // end of table
};
~~~

​	表中的前四个命名空间条目由SOAP1.1协议使用的标准命名空间组成。事实上，命名空间映射表是显示声明的，以使程序员能够制定SOAP编码样式，并允许包含带命名空间名称绑定的namespace-prefix以符合特定SOAP服务的命名空间要求。例如命名空间前缀ns2(由上面显示的命名空间映射表绑定到urn:calc)，由生成的存根例程用于编码add请求。这是由soapcpp2工具使用calc.h头文件中指定的ns2__add方法名称的ns2前缀时自动执行的。通常，如果服务操作的函数名、结构名、类名、枚举名或结构/类的字段名具有一对下划线，则该名称必须具有在命名空间映射表定义的命名空间前缀。

​	命名空间映射表将由存根例程作为SOAP Envelope的一部分输出，例如：

~~~
...
<SOAP-ENV:Envelope xmlns:SOAP-ENV="http://schemas.xmlsoap.org/soap/envelope/"
xmlns:SOAP-ENC="http://schemas.xmlsoap.org/soap/encoding/"
xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
xmlns:xsd="http://www.w3.org/2001/XMLSchema"
xmlns:ns2="urn:calc"
SOAP-ENV:encodingStyle="http://schemas.xmlsoap.org/soap/encoding/">
...
~~~

​	SOAP服务将使用命名空间绑定来验证SOAP请求。