<div style='display: none'>
@tableofcontents @section README

To view this file in the Firefox web browser, download readmeviewer.html from https://www.genivia.com/files/readmeviewer.html.zip, unzip and copy it to the same directory where this soapReadme.md file is located, then open it in Firefox to view the contents of soapReadme.md.

This markdown file is compatible with Doxygen.
</div>

## Overview {#doc-overview}

This report was generated by soapcpp2 v2.8.72 for interface file [calc.h](calc.h) with options -r -c 

Simple calculator service described at https://www.genivia.com/dev.html

### Tools

The **wsdl2h** command line tool takes a set of WSDL and XSD files to generate a data binding interface file.  This interface file is similar to a C/C++ header file and contains declarations of C/C++ types and functions with explanatory comments, directives, and annotations.  Types are declared in this interface file as serializable.  Functions are declared as Web service operations for the client and server sides.

The **soapcpp2** command line tool takes an interface file (i.e. a header file) such as [calc.h](calc.h) to generate the data binding implementation.  This implementation includes XML serializers and source code for the client and server side.  An interface file for soapcpp2 can be a regular C/C++ header file with type and function declarations (without code), and include annotations to declare XML schema-related properties.

### Files

The following C source code files were generated by soapcpp2 for interface file [calc.h](calc.h):

- [soapStub.h](soapStub.h) contains an annotated copy of [calc.h](calc.h) and of the imported files (if any), where most of the information in this report [soapReadme.md](soapReadme.md) is sourced from (this header file also #includes "stdsoap2.h")
- [soapH.h](soapH.h) declares allocation and (de)serialization functions for each C/C++ type, to #include in projects (this header file also #includes "soapStub.h")
- [soapC.c](soapC.c) defines allocation and (de)serialization functions for each C/C++ type, to compile with a project
- [soapClient.c](soapClient.c) defines client call stub functions for service invocation, to compile with a project
- [soapClientLib.c](soapClientLib.c) combines soapC.c with soapClient.c into one "library" file, intended for combining multiple clients and servers that are separately generated with soapcpp2 option -p, thereby preventing serializer naming conflicts (this makes serialization functions locally visible to the client/server as static functions)
- [soapServer.c](soapServer.c) defines server functions, including the service dispatcher that calls back-end service operations, to compile with a project
- [soapServerLib.c](soapServerLib.c) combines soapC.c with soapServer.c into one "library" file, intended for combining multiple clients and servers that are separately generated with soapcpp2 option -p, thereby preventing serializer function naming conflicts (this makes serialization functions locally visible to the client/server as static functions)

Also compile stdsoap2.c (and dom.c if XML DOM is used) with a project (or link libgsoapssl.a) and use the following compile-time options:

- `-DWITH_OPENSSL` to enable HTTPS with OpenSSL
- `-DWITH_GNUTLS` to enable HTTPS with GNUTLS
- `-DWITH_DOM` is required when using the WS-Security plugin
- `-DWITH_GZIP` to enable message compression

See the gSOAP documentation for additional options.

### Contents

This report has the following contents describing the data binding interface types, and the client- and the server-side operations (if any):

- [struct and union types](#doc-classes)
- [typedefs](#doc-typedefs)
- [summary of serializable types](#doc-types)
- [schemas and namespaces](#doc-namespaces)
- [Web client operations](#doc-client) lists the service operations to call
- [Web server operations](#doc-server) lists the service operations to implement when developing a service

[![][1] To top](#)


## Struct and Union Types {#doc-classes}

The table below lists the structs and unions declared in [calc.h](calc.h) or that are imported:

<table class="doxtable">
<tr><th> Type </th><th> Declared </th><th> Serializable </th></tr>
<tr><td><code><a href="#ns__addResponse"> struct ns__addResponse </a></code></td><td> calc.h:100 </td><td> yes </td></tr>
<tr><td><code><a href="#ns__add"> struct ns__add </a></code></td><td> calc.h:100 </td><td> yes </td></tr>
<tr><td><code><a href="#ns__subResponse"> struct ns__subResponse </a></code></td><td> calc.h:103 </td><td> yes </td></tr>
<tr><td><code><a href="#ns__sub"> struct ns__sub </a></code></td><td> calc.h:103 </td><td> yes </td></tr>
<tr><td><code><a href="#ns__mulResponse"> struct ns__mulResponse </a></code></td><td> calc.h:106 </td><td> yes </td></tr>
<tr><td><code><a href="#ns__mul"> struct ns__mul </a></code></td><td> calc.h:106 </td><td> yes </td></tr>
<tr><td><code><a href="#ns__divResponse"> struct ns__divResponse </a></code></td><td> calc.h:109 </td><td> yes </td></tr>
<tr><td><code><a href="#ns__div"> struct ns__div </a></code></td><td> calc.h:109 </td><td> yes </td></tr>
<tr><td><code><a href="#ns__powResponse"> struct ns__powResponse </a></code></td><td> calc.h:112 </td><td> yes </td></tr>
<tr><td><code><a href="#ns__pow"> struct ns__pow </a></code></td><td> calc.h:112 </td><td> yes </td></tr>
<tr><td><code><a href="#SOAP_ENV__Header"> struct SOAP_ENV__Header </a></code></td><td> calc.h:113 </td><td> yes </td></tr>
<tr><td><code><a href="#SOAP_ENV__Code"> struct SOAP_ENV__Code </a></code></td><td> calc.h:113 </td><td> yes </td></tr>
<tr><td><code><a href="#SOAP_ENV__Detail"> struct SOAP_ENV__Detail </a></code></td><td> calc.h:113 </td><td> yes </td></tr>
<tr><td><code><a href="#SOAP_ENV__Reason"> struct SOAP_ENV__Reason </a></code></td><td> calc.h:113 </td><td> yes </td></tr>
<tr><td><code><a href="#SOAP_ENV__Fault"> struct SOAP_ENV__Fault </a></code></td><td> calc.h:113 </td><td> yes </td></tr>
</table>

<a name="ns__addResponse"></a>

### `struct ns__addResponse`

This struct is declared in [calc.h](calc.h) at line 100, is serialized as XML schema type *`ns:addResponse`* and is internally used as the operation response element *`<ns:addResponse>`* with the response parameters of service operation `ns__add()`.

[![][1] To top](#)


<a name="ns__add"></a>

### `struct ns__add`

This struct is declared in [calc.h](calc.h) at line 100, is serialized as XML schema type *`ns:add`* and is internally used as the operation request element *`<ns:add>`* with the request parameters of service operation `ns__add()`.

[![][1] To top](#)


<a name="ns__subResponse"></a>

### `struct ns__subResponse`

This struct is declared in [calc.h](calc.h) at line 103, is serialized as XML schema type *`ns:subResponse`* and is internally used as the operation response element *`<ns:subResponse>`* with the response parameters of service operation `ns__sub()`.

[![][1] To top](#)


<a name="ns__sub"></a>

### `struct ns__sub`

This struct is declared in [calc.h](calc.h) at line 103, is serialized as XML schema type *`ns:sub`* and is internally used as the operation request element *`<ns:sub>`* with the request parameters of service operation `ns__sub()`.

[![][1] To top](#)


<a name="ns__mulResponse"></a>

### `struct ns__mulResponse`

This struct is declared in [calc.h](calc.h) at line 106, is serialized as XML schema type *`ns:mulResponse`* and is internally used as the operation response element *`<ns:mulResponse>`* with the response parameters of service operation `ns__mul()`.

[![][1] To top](#)


<a name="ns__mul"></a>

### `struct ns__mul`

This struct is declared in [calc.h](calc.h) at line 106, is serialized as XML schema type *`ns:mul`* and is internally used as the operation request element *`<ns:mul>`* with the request parameters of service operation `ns__mul()`.

[![][1] To top](#)


<a name="ns__divResponse"></a>

### `struct ns__divResponse`

This struct is declared in [calc.h](calc.h) at line 109, is serialized as XML schema type *`ns:divResponse`* and is internally used as the operation response element *`<ns:divResponse>`* with the response parameters of service operation `ns__div()`.

[![][1] To top](#)


<a name="ns__div"></a>

### `struct ns__div`

This struct is declared in [calc.h](calc.h) at line 109, is serialized as XML schema type *`ns:div`* and is internally used as the operation request element *`<ns:div>`* with the request parameters of service operation `ns__div()`.

[![][1] To top](#)


<a name="ns__powResponse"></a>

### `struct ns__powResponse`

This struct is declared in [calc.h](calc.h) at line 112, is serialized as XML schema type *`ns:powResponse`* and is internally used as the operation response element *`<ns:powResponse>`* with the response parameters of service operation `ns__pow()`.

[![][1] To top](#)


<a name="ns__pow"></a>

### `struct ns__pow`

This struct is declared in [calc.h](calc.h) at line 112, is serialized as XML schema type *`ns:pow`* and is internally used as the operation request element *`<ns:pow>`* with the request parameters of service operation `ns__pow()`.

[![][1] To top](#)


<a name="SOAP_ENV__Header"></a>

### `struct SOAP_ENV__Header`

This struct is declared in [calc.h](calc.h) at line 113, is the SOAP protocol *`<SOAP-ENV:Header>`* element with message-specific child elements that are mandatory to process when attributed with *`mustUnderstand="true"`*.  Headers are usually added and processed by plugins.  To remove the SOAP Header when sending or returning a message, set `soap->header = NULL`.  Use `soap_header(struct soap *soap)` to allocate a `struct SOAP_ENV__Header` which will be pointed to by `soap->header`, then initialize it with `soap_default_SOAP_ENV__Header(soap, soap->header)` and set one or more of its data members (if any):

*No SOAP headers are applicable*

This struct will be auto-generated when it is not explicitly declared in an interface file, and is declared mutable, meaning that multiple declarations in interface files are collected into one structure, and has the following auto-completed declaration in soapStub.h:

    struct SOAP_ENV__Header {
    };

[![][1] To top](#)


<a name="SOAP_ENV__Code"></a>

### `struct SOAP_ENV__Code`

This struct is declared in [calc.h](calc.h) at line 113, is recursive, meaning it may (in)directly reference itself through its (base or derived class) members, and is the SOAP protocol *`<SOAP-ENV:Code>`* element.  This struct is for internal use and will be auto-generated when not explicitly declared.

[![][1] To top](#)


<a name="SOAP_ENV__Detail"></a>

### `struct SOAP_ENV__Detail`

This struct is declared in [calc.h](calc.h) at line 113, is the SOAP protocol *`<SOAP-ENV:Detail>`* element with details returned by a service that triggered the error.  Fault details are added and processed by plugins by setting the `detail` (for SOAP 1.1) or `SOAP_ENV__Detail` (for SOAP 1.2) member of `struct SOAP_ENV__Fault` and then setting one ore more of the detail members:

- `char *__any` catch-all XML in literal XML string, see also <code><a href="#_XML"> _XML </a></code>
- `int __type` element *`<fault>`* serialized with C/C++ type `__type` = `SOAP_TYPE_Name`


This struct will be auto-generated when it is not explicitly declared in an interface file, and is declared mutable, meaning that multiple declarations in interface files are collected into one structure, and has the following auto-completed declaration in soapStub.h:

    struct SOAP_ENV__Detail {
        char *__any;
        /** Any type of element 'fault' assigned to fault with its SOAP_TYPE_T assigned to __type */
        /** Do not create a cyclic data structure throught this member unless SOAP encoding or SOAP_XML_GRAPH are used for id-ref serialization */
        int __type;
        void *fault;
    };

[![][1] To top](#)


<a name="SOAP_ENV__Reason"></a>

### `struct SOAP_ENV__Reason`

This struct is declared in [calc.h](calc.h) at line 113, is the SOAP protocol *`<SOAP-ENV:Reason>`* element.  This struct is for internal use and will be auto-generated when not explicitly declared.

[![][1] To top](#)


<a name="SOAP_ENV__Fault"></a>

### `struct SOAP_ENV__Fault`

This struct is declared in [calc.h](calc.h) at line 113, is the SOAP protocol *`<SOAP-ENV:Fault>`* element with fault information and details returned by a service that triggered the error.  At the server side, a fault can be explicitly set within a service operation by calling and returning:

- `int soap_sender_fault(struct soap *soap, const char *faultstring, const char *XML)` return this error code when the sender is at fault (irrecoverable)
- `int soap_receiver_fault(struct soap *soap, const char *faultstring, const char *XML)` return this error code when the receiver is at fault (recoverable, sender may retry)

A service operation may also return an HTTP status/error code (201 to 999).

At the client side the (proxy) call returns the error code which is also stored in `soap->error`.  The fault structure is pointed to by `soap->fault`.  The fault can be displayed with:

- `void soap_print_fault(struct soap *soap, FILE *fd)` display fault
- `void soap_print_fault_location(struct soap *soap, FILE *fd)` display the location of the fault in the XML message that caused it
- `void soap_sprint_fault(struct soap *soap, char *buf, size_t len)` write fault to buffer
- `void soap_stream_fault(struct soap *soap, std::ostream&)` write fault to stream
- `const char *soap_fault_subcode(struct soap *soap)` returns the SOAP Fault subcode QName string or NULL when absent
- `const char *soap_fault_string(struct soap *soap)` returns the SOAP Fault string/reason or NULL when absent
- `const char *soap_fault_detail(struct soap *soap)` returns the SOAP Fault detail XML string or NULL when absent
- `const char **soap_faultsubcode(struct soap *soap)` returns a pointer to the SOAP Fault to set this QName string
- `const char **soap_faultstring(struct soap *soap)` returns a pointer to the SOAP Fault string/reason to set this string
- `const char **soap_faultdetail(struct soap *soap)` returns a pointer to the SOAP Fault detail XML string to set this string or returns NULL when not accessible

This struct will be auto-generated when it is not explicitly declared in an interface file and is declared mutable, meaning that multiple declarations in interface files are collected into one structure, and has the following auto-completed declaration in soapStub.h:

    struct SOAP_ENV__Fault {
        /** Optional element 'faultcode' of XML schema type 'xsd:QName' */
        char *faultcode;
        /** Optional element 'faultstring' of XML schema type 'xsd:string' */
        char *faultstring;
        /** Optional element 'faultactor' of XML schema type 'xsd:string' */
        char *faultactor;
        /** Optional element 'detail' of XML schema type 'SOAP-ENV:Detail' */
        struct SOAP_ENV__Detail *detail;
        /** Optional element 'SOAP-ENV:Code' of XML schema type 'SOAP-ENV:Code' */
        struct SOAP_ENV__Code *SOAP_ENV__Code;
        /** Optional element 'SOAP-ENV:Reason' of XML schema type 'SOAP-ENV:Reason' */
        struct SOAP_ENV__Reason *SOAP_ENV__Reason;
        /** Optional element 'SOAP-ENV:Node' of XML schema type 'xsd:string' */
        char *SOAP_ENV__Node;
        /** Optional element 'SOAP-ENV:Role' of XML schema type 'xsd:string' */
        char *SOAP_ENV__Role;
        /** Optional element 'SOAP-ENV:Detail' of XML schema type 'SOAP-ENV:Detail' */
        struct SOAP_ENV__Detail *SOAP_ENV__Detail;
    };

[![][1] To top](#)


## Typedefs {#doc-typedefs}

A typedef type is serializable if its underlying base type is serializable.  Typedefs may declare custom serializers, meaning their underlying types are custom-serialized in XML using serialization rules that differ from the serialization rules of the underlying base type:
<table class="doxtable">
<tr><th> Typedef </th><th> Type </th><th> Declared </th><th> Serializable </th><th> Custom </th></tr>
<tr><td><code><a href="#_XML"> _XML </a></code></td><td><code> char * </code></td><td> (built-in):0 </td><td> yes </td><td> yes </td></tr>
<tr><td><code><a href="#_QName"> _QName </a></code></td><td><code> char * </code></td><td> (built-in):0 </td><td> yes </td><td> yes </td></tr>
</table>

<a name="_XML"></a>

### `_XML`

This typedef is internally generated and is a built-in string type to hold XML that is literally serialized to and from XML

[![][1] To top](#)


<a name="_QName"></a>

### `_QName`

This typedef is internally generated and is a built-in string type to serialize a list of space-separated qualified names (*`xsd:QName`*), such that XML namespace prefixes are normalized to the XML prefixes defined in the [namespace table](#doc-namespaces) or replaced with "URI": when the namespace table has no prefix entry for the URI

[![][1] To top](#)


## Summary of Serializable Types {#doc-types}

Each serializable C *Type* with binding name *Name* has a set of auto-generated functions:

- `Type *soap_new_Name(struct soap*, int n)` managed allocation with default initialization of one *Type* when `n` = 1 or array *Type*`[n]` when `n` > 1
- `void soap_default_Name(struct soap*, Type*)` initialize or reset *Type* to default
- `Type *soap_dup_Name(struct soap*, Type *dst, const Type *src)` requires soapcpp2 option -Ec, deep copy `src` to `dst` managed by context or unmanaged when context is NULL, returning `dst` (if `dst` is NULL then allocates `dst` copy)
- `void soap_del_Name(struct soap*, Type*)` requires soapcpp2 option -Ec, deep delete *Type* which must be unmanaged
- `const char *soap_Name2s(struct soap*, Type)` primitive *Type* only, returns string-converted *Type* in temporary string buffer
- `int soap_s2Name(struct soap*, const char*, Type*)` primitive *Type* only, convert string to value, returns `SOAP_OK` or error code
- `int soap_write_Name(struct soap*, const Type*)` serialize *Type* to XML, returns `SOAP_OK` or error code
- `int soap_PUT_Name(struct soap*, const char *URL, const Type*)` REST PUT *Type* in XML, returns `SOAP_OK` or error code
- `int soap_PATCH_Name(struct soap*, const char *URL, const Type*)` REST PATCH *Type* in XML, returns `SOAP_OK` or error code
- `int soap_POST_send_Name(struct soap*, const char *URL, const Type*)` REST POST send *Type* in XML (MUST be followed by a `soap_POST_recv_OtherName`), returns `SOAP_OK` or error code
- `int soap_read_Name(struct soap*, Type*)` deserialize *Type* from XML, returns `SOAP_OK` or error code
- `int soap_GET_Name(struct soap*, const char *URL, Type*)` REST GET *Type* from XML, returns `SOAP_OK` or error code
- `int soap_POST_recv_Name(struct soap*, Type*)` REST GET *Type* from XML (after a `soap_POST_send_OtherName`), returns `SOAP_OK` or error code
- `(Type *)soap_malloc(struct soap*, sizeof(Type))` raw managed allocation of *Type* without initialization
- `const char *soap_strdup(struct soap*, const char*)` managed allocation and duplication of string
- `const wchar_t *soap_wstrdup(struct soap*, const wchar_t*)` managed allocation and duplication of wide string

Each *Type* also has a unique type id `SOAP_TYPE_Name` that you can use to serialize `void*` in a struct/class by setting the `int __type` member to this type id.

From the toolkit documentation:

- Set `soap->sendfd = fd` to serialize to an `int fd` file descriptor
- Set `soap->os = &cs` to serialize to a string `const char *cs`, which will be assigned by the engine and set to point to a managed string that is automatically deleted
- Set `soap->recvfd = fd` to deserialize from an `int fd` file descriptor
- Set `soap->is = cs` to deserialize from a `const char *cs` string
- All managed allocated data is freed by `soap_end(soap)` with context `soap`

The table below lists the serializable types by *Type*, binding *Name*, *Kind*, and the XSD data binding type and/or element.  Pointers, arrays, and containers of these types are also serializable:

<table class="doxtable">
<tr><th> C Type </th><th> Name </th><th> Kind </th><th> XML schema name </th></tr>
<tr><td><code> char </code></td><td><code> byte </code></td><td> char </td><td> xsd:byte </td></tr>
<tr><td><code> int </code></td><td><code> int </code></td><td> int </td><td> xsd:int </td></tr>
<tr><td><code> double </code></td><td><code> double </code></td><td> double </td><td> xsd:double </td></tr>
<tr><td><code><a href="#SOAP_ENV__Fault"> struct SOAP_ENV__Fault </a></code></td><td><code> SOAP_ENV__Fault </code></td><td> struct </td><td>  </td></tr>
<tr><td><code><a href="#SOAP_ENV__Reason"> struct SOAP_ENV__Reason </a></code></td><td><code> SOAP_ENV__Reason </code></td><td> struct </td><td>  </td></tr>
<tr><td><code><a href="#SOAP_ENV__Detail"> struct SOAP_ENV__Detail </a></code></td><td><code> SOAP_ENV__Detail </code></td><td> struct </td><td>  </td></tr>
<tr><td><code><a href="#SOAP_ENV__Code"> struct SOAP_ENV__Code </a></code></td><td><code> SOAP_ENV__Code </code></td><td> struct </td><td>  </td></tr>
<tr><td><code><a href="#SOAP_ENV__Header"> struct SOAP_ENV__Header </a></code></td><td><code> SOAP_ENV__Header </code></td><td> struct </td><td>  </td></tr>
<tr><td><code><a href="#ns__pow"> struct ns__pow </a></code></td><td><code> ns__pow </code></td><td> struct </td><td> ns:pow </td></tr>
<tr><td><code><a href="#ns__powResponse"> struct ns__powResponse </a></code></td><td><code> ns__powResponse </code></td><td> struct </td><td> ns:powResponse </td></tr>
<tr><td><code><a href="#ns__div"> struct ns__div </a></code></td><td><code> ns__div </code></td><td> struct </td><td> ns:div </td></tr>
<tr><td><code><a href="#ns__divResponse"> struct ns__divResponse </a></code></td><td><code> ns__divResponse </code></td><td> struct </td><td> ns:divResponse </td></tr>
<tr><td><code><a href="#ns__mul"> struct ns__mul </a></code></td><td><code> ns__mul </code></td><td> struct </td><td> ns:mul </td></tr>
<tr><td><code><a href="#ns__mulResponse"> struct ns__mulResponse </a></code></td><td><code> ns__mulResponse </code></td><td> struct </td><td> ns:mulResponse </td></tr>
<tr><td><code><a href="#ns__sub"> struct ns__sub </a></code></td><td><code> ns__sub </code></td><td> struct </td><td> ns:sub </td></tr>
<tr><td><code><a href="#ns__subResponse"> struct ns__subResponse </a></code></td><td><code> ns__subResponse </code></td><td> struct </td><td> ns:subResponse </td></tr>
<tr><td><code><a href="#ns__add"> struct ns__add </a></code></td><td><code> ns__add </code></td><td> struct </td><td> ns:add </td></tr>
<tr><td><code><a href="#ns__addResponse"> struct ns__addResponse </a></code></td><td><code> ns__addResponse </code></td><td> struct </td><td> ns:addResponse </td></tr>
<tr><td><code><a href="#_QName"> _QName </a></code></td><td><code> _QName </code></td><td> string </td><td> xsd:QName </td></tr>
<tr><td><code><a href="#_XML"> _XML </a></code></td><td><code> _XML </code></td><td> string </td><td> (literal XML string) </td></tr>
<tr><td><code> char * </code></td><td><code> string </code></td><td> string </td><td> xsd:string </td></tr>
</table>

[![][1] To top](#)


## Schemas and Namespaces {#doc-namespaces}

The following schemas and namespaces are used in addition to the predefined SOAP and built-in XSD namespaces:

- Prefix `ns` is bound to namespace URI *`urn:calc`* of service WSDL [calc.wsdl](calc.wsdl) and schema [ns.xsd](ns.xsd) with local element and attribute form default *`unqualified`*

The following namespace table is saved to calc.nsmap:

    struct Namespace namespaces[] = {
        {"SOAP-ENV", "http://schemas.xmlsoap.org/soap/envelope/", "http://www.w3.org/*/soap-envelope", NULL},
        {"SOAP-ENC", "http://schemas.xmlsoap.org/soap/encoding/", "http://www.w3.org/*/soap-encoding", NULL},
        {"xsi", "http://www.w3.org/2001/XMLSchema-instance", "http://www.w3.org/*/XMLSchema-instance", NULL},
        {"xsd", "http://www.w3.org/2001/XMLSchema", "http://www.w3.org/*/XMLSchema", NULL},
        {"ns", "urn:calc", NULL, NULL},
        {NULL, NULL, NULL, NULL}
    };

The table binds XML namespace prefixes (first column) to namespace URIs (second column), similar to xmlns:prefix="URI" in XML.  The third column is a URI pattern with `*` wildcards that is also accepted as a valid namespace URI for inbound XML messages.  The fourth column is NULL.  This table is globally defined for the gSOAP engine.  The engine context will look for it unless you compiled the gSOAP source codes with `-DWITH_NONAMESPACES`.  You must assign this or another namespace table with `soap_set_namespaces(struct soap *soap, struct Namespace *namespaces)` after initializing the context and before processing XML.

[![][1] To top](#)


## Web Client Operations {#doc-client}

Simple calculator service described at https://www.genivia.com/dev.html

### Operation `ns__add()`

Sums two values

This service operation is declared in [calc.h](calc.h) at line 100 and has the following properties:

- SOAP 1.1 protocol
- SOAP rpc style
- SOAP encoded
- SOAP action ""
- Default service endpoint URL "http://websrv.cs.fsu.edu/~engelen/calcserver.cgi"
- Operation namespace prefix `ns` and URI "[urn:calc](#doc-namespaces)"

To invoke this service operation, use the following auto-generated function declared in [soapStub.h](soapStub.h) and defined in [soapClient.c](soapClient.c):

    SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__add(struct soap *soap, const char *soap_endpoint, const char *soap_action, double a, double b, double *result);

where:

- `struct soap *soap` is the context
- `const char *soap_endpoint` is the endpoint URL (or list of space-separated URLs) or pass NULL to use the default endpoint(s)
- `const char *soap_action` is the SOAP action header or pass NULL to use the default action (recommended)
- `double a` is required
- `double b` is required
- `double *result` is the service operation response, which is a non-NULL pointer to a `double` that the client provides with the call and is populated by the service operation as the result of the call

This function returns `SOAP_OK` and sets the last parameter `result` to the result, or returns an error code

[![][1] To top](#)


### Operation `ns__sub()`

Subtracts two values

This service operation is declared in [calc.h](calc.h) at line 103 and has the following properties:

- SOAP 1.1 protocol
- SOAP rpc style
- SOAP encoded
- SOAP action ""
- Default service endpoint URL "http://websrv.cs.fsu.edu/~engelen/calcserver.cgi"
- Operation namespace prefix `ns` and URI "[urn:calc](#doc-namespaces)"

To invoke this service operation, use the following auto-generated function declared in [soapStub.h](soapStub.h) and defined in [soapClient.c](soapClient.c):

    SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__sub(struct soap *soap, const char *soap_endpoint, const char *soap_action, double a, double b, double *result);

where:

- `struct soap *soap` is the context
- `const char *soap_endpoint` is the endpoint URL (or list of space-separated URLs) or pass NULL to use the default endpoint(s)
- `const char *soap_action` is the SOAP action header or pass NULL to use the default action (recommended)
- `double a` is required
- `double b` is required
- `double *result` is the service operation response, which is a non-NULL pointer to a `double` that the client provides with the call and is populated by the service operation as the result of the call

This function returns `SOAP_OK` and sets the last parameter `result` to the result, or returns an error code

[![][1] To top](#)


### Operation `ns__mul()`

Multiplies two values

This service operation is declared in [calc.h](calc.h) at line 106 and has the following properties:

- SOAP 1.1 protocol
- SOAP rpc style
- SOAP encoded
- SOAP action ""
- Default service endpoint URL "http://websrv.cs.fsu.edu/~engelen/calcserver.cgi"
- Operation namespace prefix `ns` and URI "[urn:calc](#doc-namespaces)"

To invoke this service operation, use the following auto-generated function declared in [soapStub.h](soapStub.h) and defined in [soapClient.c](soapClient.c):

    SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__mul(struct soap *soap, const char *soap_endpoint, const char *soap_action, double a, double b, double *result);

where:

- `struct soap *soap` is the context
- `const char *soap_endpoint` is the endpoint URL (or list of space-separated URLs) or pass NULL to use the default endpoint(s)
- `const char *soap_action` is the SOAP action header or pass NULL to use the default action (recommended)
- `double a` is required
- `double b` is required
- `double *result` is the service operation response, which is a non-NULL pointer to a `double` that the client provides with the call and is populated by the service operation as the result of the call

This function returns `SOAP_OK` and sets the last parameter `result` to the result, or returns an error code

[![][1] To top](#)


### Operation `ns__div()`

Divides two values

This service operation is declared in [calc.h](calc.h) at line 109 and has the following properties:

- SOAP 1.1 protocol
- SOAP rpc style
- SOAP encoded
- SOAP action ""
- Default service endpoint URL "http://websrv.cs.fsu.edu/~engelen/calcserver.cgi"
- Operation namespace prefix `ns` and URI "[urn:calc](#doc-namespaces)"

To invoke this service operation, use the following auto-generated function declared in [soapStub.h](soapStub.h) and defined in [soapClient.c](soapClient.c):

    SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__div(struct soap *soap, const char *soap_endpoint, const char *soap_action, double a, double b, double *result);

where:

- `struct soap *soap` is the context
- `const char *soap_endpoint` is the endpoint URL (or list of space-separated URLs) or pass NULL to use the default endpoint(s)
- `const char *soap_action` is the SOAP action header or pass NULL to use the default action (recommended)
- `double a` is required
- `double b` is required
- `double *result` is the service operation response, which is a non-NULL pointer to a `double` that the client provides with the call and is populated by the service operation as the result of the call

This function returns `SOAP_OK` and sets the last parameter `result` to the result, or returns an error code

[![][1] To top](#)


### Operation `ns__pow()`

Raises a to b

This service operation is declared in [calc.h](calc.h) at line 112 and has the following properties:

- SOAP 1.1 protocol
- SOAP rpc style
- SOAP encoded
- SOAP action ""
- Default service endpoint URL "http://websrv.cs.fsu.edu/~engelen/calcserver.cgi"
- Operation namespace prefix `ns` and URI "[urn:calc](#doc-namespaces)"

To invoke this service operation, use the following auto-generated function declared in [soapStub.h](soapStub.h) and defined in [soapClient.c](soapClient.c):

    SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__pow(struct soap *soap, const char *soap_endpoint, const char *soap_action, double a, double b, double *result);

where:

- `struct soap *soap` is the context
- `const char *soap_endpoint` is the endpoint URL (or list of space-separated URLs) or pass NULL to use the default endpoint(s)
- `const char *soap_action` is the SOAP action header or pass NULL to use the default action (recommended)
- `double a` is required
- `double b` is required
- `double *result` is the service operation response, which is a non-NULL pointer to a `double` that the client provides with the call and is populated by the service operation as the result of the call

This function returns `SOAP_OK` and sets the last parameter `result` to the result, or returns an error code

[![][1] To top](#)


## Web Server Operations {#doc-server}

Simple calculator service described at https://www.genivia.com/dev.html

Use the service request dispatcher that is auto-generated in [soapServer.c](soapServer.c) to accept and process service requests:

    SOAP_FMAC5 int SOAP_FMAC6 soap_serve(struct soap *soap);

This function serves requests by calling one of the service operations listed further below that matches the request.  Returns `SOAP_OK` or an error code.  This function supports CGI by accepting a request on stdin and sending the response to stdout, and FastCGI.  To serve over HTTP(S), use the following functions to establish a connection:

- `SOAP_SOCKET soap_bind(struct soap *soap, const char *host, int port, int backlog)` returns master socket bound to port (and restricted to host name if not NULL) or `SOAP_INVALID_SOCKET`
- `SOAP_SOCKET soap_accept(struct soap *soap)` accepts connection and returns socket when accepted, or `SOAP_INVALID_SOCKET`
- `int soap_ssl_accept(struct soap *soap)` performs SSL handshake and returns `SOAP_OK` when successful or an error code, call this function after `soap_accept()` to accept SSL/TLS connection

### Service Operation `ns__add()`

Sums two values

This service operation is declared in [calc.h](calc.h) at line 100 and has the following properties:

- SOAP 1.1 protocol
- SOAP rpc style
- SOAP encoded
- SOAP action ""
- Default service endpoint URL "http://websrv.cs.fsu.edu/~engelen/calcserver.cgi"
- Operation namespace prefix `ns` and URI "[urn:calc](#doc-namespaces)"

The following service operation function declared in [soapStub.h](soapStub.h) must be defined in the service back-end code and will be called by the service dispatcher `soap_serve(soap)` defined in [soapServer.c](soapServer.c), and should return `SOAP_OK` with the result value `result` set or return an error code:

    SOAP_FMAC5 int SOAP_FMAC6 ns__add(struct soap*, double a, double b, double *result);

where:

- `struct soap *soap` is the context
- `double a` is required
- `double b` is required
- `double *result` is the service operation response, which is a non-NULL pointer to a `double` that the service operation should populate with the response data

This service function should be implemented as part of the service back-end code and return `SOAP_OK` and set the last parameter `result` to the result, or return an error code

[![][1] To top](#)


### Service Operation `ns__sub()`

Subtracts two values

This service operation is declared in [calc.h](calc.h) at line 103 and has the following properties:

- SOAP 1.1 protocol
- SOAP rpc style
- SOAP encoded
- SOAP action ""
- Default service endpoint URL "http://websrv.cs.fsu.edu/~engelen/calcserver.cgi"
- Operation namespace prefix `ns` and URI "[urn:calc](#doc-namespaces)"

The following service operation function declared in [soapStub.h](soapStub.h) must be defined in the service back-end code and will be called by the service dispatcher `soap_serve(soap)` defined in [soapServer.c](soapServer.c), and should return `SOAP_OK` with the result value `result` set or return an error code:

    SOAP_FMAC5 int SOAP_FMAC6 ns__sub(struct soap*, double a, double b, double *result);

where:

- `struct soap *soap` is the context
- `double a` is required
- `double b` is required
- `double *result` is the service operation response, which is a non-NULL pointer to a `double` that the service operation should populate with the response data

This service function should be implemented as part of the service back-end code and return `SOAP_OK` and set the last parameter `result` to the result, or return an error code

[![][1] To top](#)


### Service Operation `ns__mul()`

Multiplies two values

This service operation is declared in [calc.h](calc.h) at line 106 and has the following properties:

- SOAP 1.1 protocol
- SOAP rpc style
- SOAP encoded
- SOAP action ""
- Default service endpoint URL "http://websrv.cs.fsu.edu/~engelen/calcserver.cgi"
- Operation namespace prefix `ns` and URI "[urn:calc](#doc-namespaces)"

The following service operation function declared in [soapStub.h](soapStub.h) must be defined in the service back-end code and will be called by the service dispatcher `soap_serve(soap)` defined in [soapServer.c](soapServer.c), and should return `SOAP_OK` with the result value `result` set or return an error code:

    SOAP_FMAC5 int SOAP_FMAC6 ns__mul(struct soap*, double a, double b, double *result);

where:

- `struct soap *soap` is the context
- `double a` is required
- `double b` is required
- `double *result` is the service operation response, which is a non-NULL pointer to a `double` that the service operation should populate with the response data

This service function should be implemented as part of the service back-end code and return `SOAP_OK` and set the last parameter `result` to the result, or return an error code

[![][1] To top](#)


### Service Operation `ns__div()`

Divides two values

This service operation is declared in [calc.h](calc.h) at line 109 and has the following properties:

- SOAP 1.1 protocol
- SOAP rpc style
- SOAP encoded
- SOAP action ""
- Default service endpoint URL "http://websrv.cs.fsu.edu/~engelen/calcserver.cgi"
- Operation namespace prefix `ns` and URI "[urn:calc](#doc-namespaces)"

The following service operation function declared in [soapStub.h](soapStub.h) must be defined in the service back-end code and will be called by the service dispatcher `soap_serve(soap)` defined in [soapServer.c](soapServer.c), and should return `SOAP_OK` with the result value `result` set or return an error code:

    SOAP_FMAC5 int SOAP_FMAC6 ns__div(struct soap*, double a, double b, double *result);

where:

- `struct soap *soap` is the context
- `double a` is required
- `double b` is required
- `double *result` is the service operation response, which is a non-NULL pointer to a `double` that the service operation should populate with the response data

This service function should be implemented as part of the service back-end code and return `SOAP_OK` and set the last parameter `result` to the result, or return an error code

[![][1] To top](#)


### Service Operation `ns__pow()`

Raises a to b

This service operation is declared in [calc.h](calc.h) at line 112 and has the following properties:

- SOAP 1.1 protocol
- SOAP rpc style
- SOAP encoded
- SOAP action ""
- Default service endpoint URL "http://websrv.cs.fsu.edu/~engelen/calcserver.cgi"
- Operation namespace prefix `ns` and URI "[urn:calc](#doc-namespaces)"

The following service operation function declared in [soapStub.h](soapStub.h) must be defined in the service back-end code and will be called by the service dispatcher `soap_serve(soap)` defined in [soapServer.c](soapServer.c), and should return `SOAP_OK` with the result value `result` set or return an error code:

    SOAP_FMAC5 int SOAP_FMAC6 ns__pow(struct soap*, double a, double b, double *result);

where:

- `struct soap *soap` is the context
- `double a` is required
- `double b` is required
- `double *result` is the service operation response, which is a non-NULL pointer to a `double` that the service operation should populate with the response data

This service function should be implemented as part of the service back-end code and return `SOAP_OK` and set the last parameter `result` to the result, or return an error code

[![][1] To top](#)





  [1]: https://www.genivia.com/images/go-up.png

--------------------------------------------------------------------------------

_Generated on Sun Dec 02 2018 04:01:37 UTC by soapcpp2 v2.8.72 for calc.h._
_The gSOAP XML Web services tools are Copyright (C) Robert van Engelen, Genivia Inc. All Rights Reserved._
