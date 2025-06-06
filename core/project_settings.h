/**************************************************************************/
/*  project_settings.h                                                    */
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

#ifndef PROJECT_SETTINGS_H
#define PROJECT_SETTINGS_H

#include "core/object.h"
#include "core/os/spin_lock.h"
#include "core/os/thread_safe.h"
#include "core/set.h"

// Querying ProjectSettings is usually done at startup.
// Additionally, in order to keep track of changes to ProjectSettings,
// instead of Querying all the strings every frame just in case of changes,
// there is a signal "project_settings_changed" which objects can subscribe to.

// E.g. (from another Godot object)
// // Call your user written object function to Query the project settings once at creation,
// perhaps in an ENTER_TREE notification:
// _project_settings_changed()
// // Then connect your function to the signal so it is called every time something changes in future:
// ProjectSettings::get_singleton()->connect("project_settings_changed", this, "_project_settings_changed");

// Where for example your function may take the form:
// void _project_settings_changed() {
// _shadowmap_size = GLOBAL_GET("rendering/quality/shadow_atlas/size");
// }

// You may want to also disconnect from the signal in EXIT_TREE notification, if your object may be deleted
// before ProjectSettings:
// ProjectSettings::get_singleton()->disconnect("project_settings_changed", this, "_project_settings_changed");

// Additionally, for objects that are not regular Godot objects capable of subscribing to signals (e.g. Rasterizers),
// you can also query the function "has_changes()" each frame,
// and update your local settings whenever this is set.

class ProjectSettings : public Object {
	GDCLASS(ProjectSettings, Object);
	_THREAD_SAFE_CLASS_

	int _dirty_this_frame = 2;

	// Starting version from 1 ensures that all callers can reset their tested version to 0,
	// and will always detect the initial project settings as a "change".
	uint32_t _version = 1;

public:
	typedef Map<String, Variant> CustomMap;
	static const String PROJECT_DATA_DIR_NAME_SUFFIX;

	enum {
		//properties that are not for built in values begin from this value, so builtin ones are displayed first
		NO_BUILTIN_ORDER_BASE = 1 << 16
	};

protected:
	struct VariantContainer {
		int order;
		bool persist;
		Variant variant;
		Variant initial;
		bool hide_from_editor;
		bool overridden;
		bool restart_if_changed;
#ifdef DEBUG_METHODS_ENABLED
		bool ignore_value_in_docs = false;
#endif

		VariantContainer() :
				order(0),
				persist(false),
				hide_from_editor(false),
				overridden(false),
				restart_if_changed(false) {
		}
		VariantContainer(const Variant &p_variant, int p_order, bool p_persist = false) :
				order(p_order),
				persist(p_persist),
				variant(p_variant),
				hide_from_editor(false),
				overridden(false),
				restart_if_changed(false) {
		}
	};

	bool registering_order;
	int last_order;
	int last_builtin_order;
	uint64_t last_save_time = 0;
	Map<StringName, VariantContainer> props;
	String resource_path;
	Map<StringName, PropertyInfo> custom_prop_info;
	bool disable_feature_overrides;
	bool using_datapack;
	List<String> input_presets;

	Set<String> custom_features;
	Map<StringName, StringName> feature_overrides;

	String project_data_dir_name;

	bool _set(const StringName &p_name, const Variant &p_value);
	bool _get(const StringName &p_name, Variant &r_ret) const;
	void _get_property_list(List<PropertyInfo> *p_list) const;

	static ProjectSettings *singleton;

	Error _load_settings_text(const String &p_path);
	Error _load_settings_binary(const String &p_path);
	Error _load_settings_text_or_binary(const String &p_text_path, const String &p_bin_path);

	Error _save_settings_text(const String &p_file, const Map<String, List<String>> &props, const CustomMap &p_custom = CustomMap(), const String &p_custom_features = String());
	Error _save_settings_binary(const String &p_file, const Map<String, List<String>> &props, const CustomMap &p_custom = CustomMap(), const String &p_custom_features = String());

	Error _save_custom_bnd(const String &p_file);

	void _convert_to_last_version(int p_from_version);

	bool _load_resource_pack(const String &p_pack, bool p_replace_files = true, int p_offset = 0);

	void _add_property_info_bind(const Dictionary &p_info);

	Error _setup(const String &p_path, const String &p_main_pack, bool p_upwards = false, bool p_ignore_override = false);

	static void _bind_methods();

public:
	static const int CONFIG_VERSION = 4;

	void set_setting(const String &p_setting, const Variant &p_value);
	Variant get_setting(const String &p_setting) const;

	bool has_setting(String p_var) const;
	String localize_path(const String &p_path) const;
	String globalize_path(const String &p_path) const;

	void set_initial_value(const String &p_name, const Variant &p_value);
	void set_restart_if_changed(const String &p_name, bool p_restart);
	void set_hide_from_editor(const String &p_name, bool p_hide_from_editor);
	void set_ignore_value_in_docs(const String &p_name, bool p_ignore);
	bool get_ignore_value_in_docs(const String &p_name) const;
	bool property_can_revert(const String &p_name);
	Variant property_get_revert(const String &p_name);

	String get_project_data_dir_name() const;
	String get_project_data_path() const;
	String get_resource_path() const;

	static ProjectSettings *get_singleton();

	void clear(const String &p_name);
	int get_order(const String &p_name) const;
	void set_order(const String &p_name, int p_order);
	void set_builtin_order(const String &p_name);

	Error setup(const String &p_path, const String &p_main_pack, bool p_upwards = false, bool p_ignore_override = false);

	Error save_custom(const String &p_path = "", const CustomMap &p_custom = CustomMap(), const Vector<String> &p_custom_features = Vector<String>(), bool p_merge_with_current = true);
	Error save();
	void set_custom_property_info(const String &p_prop, const PropertyInfo &p_info);
	const Map<StringName, PropertyInfo> &get_custom_property_info() const;
	uint64_t get_last_saved_time() { return last_save_time; }

	Vector<String> get_optimizer_presets() const;

	List<String> get_input_presets() const { return input_presets; }

	void set_disable_feature_overrides(bool p_disable);

	bool is_using_datapack() const;

	void set_registering_order(bool p_enable);

	bool has_custom_feature(const String &p_feature) const;

	// Either use the signal `project_settings_changed` or query this function.
	// N.B. _dirty_this_frame is set initially to 2.
	// This is to cope with the situation where a project setting is changed in the iteration AFTER it is read.
	// There is therefore the potential for a change to be missed. Persisting the counter
	// for two frames avoids this, at the cost of a frame delay.
	bool has_changes() const { return _dirty_this_frame == 1; }

	// Testing a version allows fast cached GET_GLOBAL macros.
	uint32_t get_version() const { return _version; }

	void update();

	ProjectSettings();
	~ProjectSettings();
};

//not a macro any longer
Variant _GLOBAL_DEF(const String &p_var, const Variant &p_default, bool p_restart_if_changed = false, bool p_ignore_value_in_docs = false);
Variant _GLOBAL_DEF_ALIAS(const String &p_var, const String &p_old_name, const Variant &p_default, bool p_restart_if_changed = false);
#define GLOBAL_DEF(m_var, m_value) _GLOBAL_DEF(m_var, m_value)
#define GLOBAL_DEF_RST(m_var, m_value) _GLOBAL_DEF(m_var, m_value, true)
#define GLOBAL_DEF_NOVAL(m_var, m_value) _GLOBAL_DEF(m_var, m_value, false, true)
#define GLOBAL_DEF_RST_NOVAL(m_var, m_value) _GLOBAL_DEF(m_var, m_value, true, true)
#define GLOBAL_DEF_ALIAS(m_var, m_old_name, m_value) _GLOBAL_DEF_ALIAS(m_var, m_old_name, m_value)
#define GLOBAL_DEF_ALIAS_RST(m_var, m_old_name, m_value) _GLOBAL_DEF(m_var, m_old_name, m_value, true)
#define GLOBAL_GET(m_var) ProjectSettings::get_singleton()->get(m_var)

/////////////////////////////////////////////////////////////////////////////////////////
// Cached versions of GLOBAL_GET.
// Cached but uses a typed variable for storage, this can be more efficient.
// Variables prefixed with _ggc_ to avoid shadowing warnings.
#define GLOBAL_GET_CACHED(m_type, m_setting_name) ([](const char *p_name) -> m_type {\
static_assert(std::is_trivially_destructible<m_type>::value, "GLOBAL_GET_CACHED must use a trivial type that allows static lifetime.");\
static m_type _ggc_local_var;\
static uint32_t _ggc_local_version = 0;\
static SpinLock _ggc_spin;\
uint32_t _ggc_new_version = ProjectSettings::get_singleton()->get_version();\
if (_ggc_local_version != _ggc_new_version) {\
	_ggc_spin.lock();\
	_ggc_local_version = _ggc_new_version;\
	_ggc_local_var = ProjectSettings::get_singleton()->get(p_name);\
	m_type _ggc_temp = _ggc_local_var;\
	_ggc_spin.unlock();\
	return _ggc_temp;\
}\
_ggc_spin.lock();\
m_type _ggc_temp2 = _ggc_local_var;\
_ggc_spin.unlock();\
return _ggc_temp2; })(m_setting_name)

#endif // PROJECT_SETTINGS_H
