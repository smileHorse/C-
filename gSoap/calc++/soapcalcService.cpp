/* soapcalcService.cpp
   Generated by gSOAP 2.8.72 for calc.h

gSOAP XML Web services tools
Copyright (C) 2000-2018, Robert van Engelen, Genivia Inc. All Rights Reserved.
The soapcpp2 tool and its generated software are released under the GPL.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
--------------------------------------------------------------------------------
A commercial use license is available from Genivia Inc., contact@genivia.com
--------------------------------------------------------------------------------
*/

#include "soapcalcService.h"

calcService::calcService()
{	this->soap = soap_new();
	this->soap_own = true;
	calcService_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
}

calcService::calcService(const calcService& rhs)
{	this->soap = rhs.soap;
	this->soap_own = false;
}

calcService::calcService(struct soap *_soap)
{	this->soap = _soap;
	this->soap_own = false;
	calcService_init(_soap->imode, _soap->omode);
}

calcService::calcService(soap_mode iomode)
{	this->soap = soap_new();
	this->soap_own = true;
	calcService_init(iomode, iomode);
}

calcService::calcService(soap_mode imode, soap_mode omode)
{	this->soap = soap_new();
	this->soap_own = true;
	calcService_init(imode, omode);
}

calcService::~calcService()
{	if (this->soap_own)
		soap_free(this->soap);
}

void calcService::calcService_init(soap_mode imode, soap_mode omode)
{	soap_imode(this->soap, imode);
	soap_omode(this->soap, omode);
	static const struct Namespace namespaces[] = {
        {"SOAP-ENV", "http://schemas.xmlsoap.org/soap/envelope/", "http://www.w3.org/*/soap-envelope", NULL},
        {"SOAP-ENC", "http://schemas.xmlsoap.org/soap/encoding/", "http://www.w3.org/*/soap-encoding", NULL},
        {"xsi", "http://www.w3.org/2001/XMLSchema-instance", "http://www.w3.org/*/XMLSchema-instance", NULL},
        {"xsd", "http://www.w3.org/2001/XMLSchema", "http://www.w3.org/*/XMLSchema", NULL},
        {"ns", "urn:calc", NULL, NULL},
        {NULL, NULL, NULL, NULL}
    };
	soap_set_namespaces(this->soap, namespaces);
}

void calcService::destroy()
{	soap_destroy(this->soap);
	soap_end(this->soap);
}

void calcService::reset()
{	this->destroy();
	soap_done(this->soap);
	soap_initialize(this->soap);
	calcService_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
}

#ifndef WITH_PURE_VIRTUAL
calcService *calcService::copy()
{	calcService *dup = SOAP_NEW_UNMANAGED(calcService);
	if (dup)
	{	soap_done(dup->soap);
		soap_copy_context(dup->soap, this->soap);
	}
	return dup;
}
#endif

calcService& calcService::operator=(const calcService& rhs)
{	if (this->soap != rhs.soap)
	{	if (this->soap_own)
			soap_free(this->soap);
		this->soap = rhs.soap;
		this->soap_own = false;
	}
	return *this;
}

int calcService::soap_close_socket()
{	return soap_closesock(this->soap);
}

int calcService::soap_force_close_socket()
{	return soap_force_closesock(this->soap);
}

int calcService::soap_senderfault(const char *string, const char *detailXML)
{	return ::soap_sender_fault(this->soap, string, detailXML);
}

int calcService::soap_senderfault(const char *subcodeQName, const char *string, const char *detailXML)
{	return ::soap_sender_fault_subcode(this->soap, subcodeQName, string, detailXML);
}

int calcService::soap_receiverfault(const char *string, const char *detailXML)
{	return ::soap_receiver_fault(this->soap, string, detailXML);
}

int calcService::soap_receiverfault(const char *subcodeQName, const char *string, const char *detailXML)
{	return ::soap_receiver_fault_subcode(this->soap, subcodeQName, string, detailXML);
}

void calcService::soap_print_fault(FILE *fd)
{	::soap_print_fault(this->soap, fd);
}

#ifndef WITH_LEAN
#ifndef WITH_COMPAT
void calcService::soap_stream_fault(std::ostream& os)
{	::soap_stream_fault(this->soap, os);
}
#endif

char *calcService::soap_sprint_fault(char *buf, size_t len)
{	return ::soap_sprint_fault(this->soap, buf, len);
}
#endif

void calcService::soap_noheader()
{	this->soap->header = NULL;
}

::SOAP_ENV__Header *calcService::soap_header()
{	return this->soap->header;
}

#ifndef WITH_NOIO
int calcService::run(int port)
{	if (!soap_valid_socket(this->soap->master) && !soap_valid_socket(this->bind(NULL, port, 100)))
		return this->soap->error;
	for (;;)
	{	if (!soap_valid_socket(this->accept()))
		{	if (this->soap->errnum == 0) // timeout?
				this->soap->error = SOAP_OK;
			break;
		}
		if (this->serve())
			break;
		this->destroy();
	}
	return this->soap->error;
}

#if defined(WITH_OPENSSL) || defined(WITH_GNUTLS)
int calcService::ssl_run(int port)
{	if (!soap_valid_socket(this->soap->master) && !soap_valid_socket(this->bind(NULL, port, 100)))
		return this->soap->error;
	for (;;)
	{	if (!soap_valid_socket(this->accept()))
		{	if (this->soap->errnum == 0) // timeout?
				this->soap->error = SOAP_OK;
			break;
		}
		if (this->ssl_accept() || this->serve())
			break;
		this->destroy();
	}
	return this->soap->error;
}
#endif

SOAP_SOCKET calcService::bind(const char *host, int port, int backlog)
{	return soap_bind(this->soap, host, port, backlog);
}

SOAP_SOCKET calcService::accept()
{	return soap_accept(this->soap);
}

#if defined(WITH_OPENSSL) || defined(WITH_GNUTLS)
int calcService::ssl_accept()
{	return soap_ssl_accept(this->soap);
}
#endif
#endif

int calcService::serve()
{
#ifndef WITH_FASTCGI
	this->soap->keep_alive = this->soap->max_keep_alive + 1;
#endif
	do
	{
#ifndef WITH_FASTCGI
		if (this->soap->keep_alive > 0 && this->soap->max_keep_alive > 0)
			this->soap->keep_alive--;
#endif
		if (soap_begin_serve(this->soap))
		{	if (this->soap->error >= SOAP_STOP)
				continue;
			return this->soap->error;
		}
		if ((dispatch() || (this->soap->fserveloop && this->soap->fserveloop(this->soap))) && this->soap->error && this->soap->error < SOAP_STOP)
		{
#ifdef WITH_FASTCGI
			soap_send_fault(this->soap);
#else
			return soap_send_fault(this->soap);
#endif
		}
#ifdef WITH_FASTCGI
		soap_destroy(this->soap);
		soap_end(this->soap);
	} while (1);
#else
	} while (this->soap->keep_alive);
#endif
	return SOAP_OK;
}

static int serve_ns__add(struct soap*, calcService*);
static int serve_ns__sub(struct soap*, calcService*);
static int serve_ns__mul(struct soap*, calcService*);
static int serve_ns__div(struct soap*, calcService*);
static int serve_ns__pow(struct soap*, calcService*);

int calcService::dispatch()
{	return dispatch(this->soap);
}

int calcService::dispatch(struct soap* soap)
{
	calcService_init(soap->imode, soap->omode);

	soap_peek_element(soap);
	if (!soap_match_tag(soap, soap->tag, "ns:add"))
		return serve_ns__add(soap, this);
	if (!soap_match_tag(soap, soap->tag, "ns:sub"))
		return serve_ns__sub(soap, this);
	if (!soap_match_tag(soap, soap->tag, "ns:mul"))
		return serve_ns__mul(soap, this);
	if (!soap_match_tag(soap, soap->tag, "ns:div"))
		return serve_ns__div(soap, this);
	if (!soap_match_tag(soap, soap->tag, "ns:pow"))
		return serve_ns__pow(soap, this);
	return soap->error = SOAP_NO_METHOD;
}

static int serve_ns__add(struct soap *soap, calcService *service)
{	struct ns__add soap_tmp_ns__add;
	struct ns__addResponse soap_tmp_ns__addResponse;
	double soap_tmp_double;
	soap_default_ns__addResponse(soap, &soap_tmp_ns__addResponse);
	soap_default_double(soap, &soap_tmp_double);
	soap_tmp_ns__addResponse.result = &soap_tmp_double;
	soap_default_ns__add(soap, &soap_tmp_ns__add);
	if (!soap_get_ns__add(soap, &soap_tmp_ns__add, "ns:add", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = service->add(soap_tmp_ns__add.a, soap_tmp_ns__add.b, soap_tmp_ns__addResponse.result);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = "";
	soap_serializeheader(soap);
	soap_serialize_ns__addResponse(soap, &soap_tmp_ns__addResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__addResponse(soap, &soap_tmp_ns__addResponse, "ns:addResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__addResponse(soap, &soap_tmp_ns__addResponse, "ns:addResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve_ns__sub(struct soap *soap, calcService *service)
{	struct ns__sub soap_tmp_ns__sub;
	struct ns__subResponse soap_tmp_ns__subResponse;
	double soap_tmp_double;
	soap_default_ns__subResponse(soap, &soap_tmp_ns__subResponse);
	soap_default_double(soap, &soap_tmp_double);
	soap_tmp_ns__subResponse.result = &soap_tmp_double;
	soap_default_ns__sub(soap, &soap_tmp_ns__sub);
	if (!soap_get_ns__sub(soap, &soap_tmp_ns__sub, "ns:sub", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = service->sub(soap_tmp_ns__sub.a, soap_tmp_ns__sub.b, soap_tmp_ns__subResponse.result);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = "";
	soap_serializeheader(soap);
	soap_serialize_ns__subResponse(soap, &soap_tmp_ns__subResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__subResponse(soap, &soap_tmp_ns__subResponse, "ns:subResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__subResponse(soap, &soap_tmp_ns__subResponse, "ns:subResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve_ns__mul(struct soap *soap, calcService *service)
{	struct ns__mul soap_tmp_ns__mul;
	struct ns__mulResponse soap_tmp_ns__mulResponse;
	double soap_tmp_double;
	soap_default_ns__mulResponse(soap, &soap_tmp_ns__mulResponse);
	soap_default_double(soap, &soap_tmp_double);
	soap_tmp_ns__mulResponse.result = &soap_tmp_double;
	soap_default_ns__mul(soap, &soap_tmp_ns__mul);
	if (!soap_get_ns__mul(soap, &soap_tmp_ns__mul, "ns:mul", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = service->mul(soap_tmp_ns__mul.a, soap_tmp_ns__mul.b, soap_tmp_ns__mulResponse.result);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = "";
	soap_serializeheader(soap);
	soap_serialize_ns__mulResponse(soap, &soap_tmp_ns__mulResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__mulResponse(soap, &soap_tmp_ns__mulResponse, "ns:mulResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__mulResponse(soap, &soap_tmp_ns__mulResponse, "ns:mulResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve_ns__div(struct soap *soap, calcService *service)
{	struct ns__div soap_tmp_ns__div;
	struct ns__divResponse soap_tmp_ns__divResponse;
	double soap_tmp_double;
	soap_default_ns__divResponse(soap, &soap_tmp_ns__divResponse);
	soap_default_double(soap, &soap_tmp_double);
	soap_tmp_ns__divResponse.result = &soap_tmp_double;
	soap_default_ns__div(soap, &soap_tmp_ns__div);
	if (!soap_get_ns__div(soap, &soap_tmp_ns__div, "ns:div", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = service->div(soap_tmp_ns__div.a, soap_tmp_ns__div.b, soap_tmp_ns__divResponse.result);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = "";
	soap_serializeheader(soap);
	soap_serialize_ns__divResponse(soap, &soap_tmp_ns__divResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__divResponse(soap, &soap_tmp_ns__divResponse, "ns:divResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__divResponse(soap, &soap_tmp_ns__divResponse, "ns:divResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve_ns__pow(struct soap *soap, calcService *service)
{	struct ns__pow soap_tmp_ns__pow;
	struct ns__powResponse soap_tmp_ns__powResponse;
	double soap_tmp_double;
	soap_default_ns__powResponse(soap, &soap_tmp_ns__powResponse);
	soap_default_double(soap, &soap_tmp_double);
	soap_tmp_ns__powResponse.result = &soap_tmp_double;
	soap_default_ns__pow(soap, &soap_tmp_ns__pow);
	if (!soap_get_ns__pow(soap, &soap_tmp_ns__pow, "ns:pow", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = service->pow(soap_tmp_ns__pow.a, soap_tmp_ns__pow.b, soap_tmp_ns__powResponse.result);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = "";
	soap_serializeheader(soap);
	soap_serialize_ns__powResponse(soap, &soap_tmp_ns__powResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__powResponse(soap, &soap_tmp_ns__powResponse, "ns:powResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__powResponse(soap, &soap_tmp_ns__powResponse, "ns:powResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}
/* End of server object code */
