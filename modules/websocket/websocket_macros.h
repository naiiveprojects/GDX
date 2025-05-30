/**************************************************************************/
/*  websocket_macros.h                                                    */
/**************************************************************************/
/*                         This file is part of:                          */
/*                             GODOT ENGINE                               */
/*                        https://godotengine.org                         */
/**************************************************************************/
/* Copyright (c) 2014-present Godot Engine contributors (see AUTHORS.md). */
/* Copyright (c) 2007-2014 Juan Linietsky, Ariel Manzur.                  */
/*                                                                        */
/* Permission is hereby granted, free of charge, to any person obtaining  */
/* a copy of this software and associated documentation files (the        */
/* "Software"), to deal in the Software without restriction, including    */
/* without limitation the rights to use, copy, modify, merge, publish,    */
/* distribute, sublicense, and/or sell copies of the Software, and to     */
/* permit persons to whom the Software is furnished to do so, subject to  */
/* the following conditions:                                              */
/*                                                                        */
/* The above copyright notice and this permission notice shall be         */
/* included in all copies or substantial portions of the Software.        */
/*                                                                        */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,        */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF     */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. */
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY   */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,   */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE      */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                 */
/**************************************************************************/

#ifndef WEBSOCKET_MACROS_H
#define WEBSOCKET_MACROS_H

#define WSC_IN_BUF PNAME("network/limits/websocket_client/max_in_buffer_kb")
#define WSC_IN_PKT PNAME("network/limits/websocket_client/max_in_packets")
#define WSC_OUT_BUF PNAME("network/limits/websocket_client/max_out_buffer_kb")
#define WSC_OUT_PKT PNAME("network/limits/websocket_client/max_out_packets")

#define WSS_IN_BUF PNAME("network/limits/websocket_server/max_in_buffer_kb")
#define WSS_IN_PKT PNAME("network/limits/websocket_server/max_in_packets")
#define WSS_OUT_BUF PNAME("network/limits/websocket_server/max_out_buffer_kb")
#define WSS_OUT_PKT PNAME("network/limits/websocket_server/max_out_packets")

#define GDCICLASS(CNAME)              \
public:                               \
	static CNAME *(*_create)();       \
                                      \
	static Ref<CNAME> create_ref() {  \
		if (!_create)                 \
			return Ref<CNAME>();      \
		return Ref<CNAME>(_create()); \
	}                                 \
                                      \
	static CNAME *create() {          \
		if (!_create)                 \
			return NULL;              \
		return _create();             \
	}                                 \
                                      \
protected:

#define GDCINULL(CNAME) \
	CNAME *(*CNAME::_create)() = NULL;

#define GDCIIMPL(IMPNAME, CNAME)                                      \
	GDSOFTCLASS(IMPNAME, CNAME)                                       \
public:                                                               \
	static CNAME *_create() { return memnew(IMPNAME); }               \
	static void make_default() { CNAME::_create = IMPNAME::_create; } \
                                                                      \
protected:

#endif // WEBSOCKET_MACROS_H
