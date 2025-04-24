/**************************************************************************/
/*  node_dock.cpp                                                         */
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

#include "node_dock.h"

#include "editor_node.h"
#include "editor_scale.h"

NodeDock *NodeDock::singleton = nullptr;

void NodeDock::update_lists() {
	connections->update_tree();
	connections->show();
}

void NodeDock::set_node(Node *p_node) {
	connections->set_node(p_node);
	groups->set_current(p_node);
	connections->show();
	groups->show();
}

NodeDock::NodeDock() {
	singleton = this;

	set_name("Node");

	split = memnew(VSplitContainer);
	add_child(split);
	split->set_h_size_flags(SIZE_EXPAND_FILL);
	split->set_v_size_flags(SIZE_EXPAND_FILL);

	connections = memnew(ConnectionsDock(EditorNode::get_singleton()));
	connections->set_undoredo(EditorNode::get_undo_redo());
	split->add_child(connections);
	connections->set_v_size_flags(SIZE_EXPAND_FILL);

	groups = memnew(GroupsEditor);
	groups->set_undo_redo(EditorNode::get_undo_redo());
	split->add_child(groups);
	groups->set_v_size_flags(SIZE_EXPAND_FILL);
	groups->set_stretch_ratio(0.3);
}
