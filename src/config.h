#pragma once


#define INSTRUMENT_TYPE_MIDI        0
#define INSTRUMENT_TYPE_VSTI        1

#define OUTPUT_TYPE_AUTO            0
#define OUTPUT_TYPE_DSOUND          1
#define OUTPUT_TYPE_WASAPI          2
#define OUTPUT_TYPE_ASIO            3

#define MIDI_REMAP_ORIGIN           0
#define MIDI_REMAP_LEFT             1
#define MIDI_REMAP_RIGHT            2

struct key_bind_t {
  byte a;
  byte b;
  byte c;
  byte d;

  key_bind_t() : a(0), b(0), c(0), d(0) {}
  key_bind_t(byte a, byte b, byte c, byte d) : a(a), b(b), c(c), d(d) {}
};

struct midi_input_config_t {
  bool enable;
  int remap;
};

// initialize config
int config_init();

// close config
void config_shutdown();

// load
int config_load(const char *filename);

// save
int config_save(const char *filename);

// get media path
void config_get_media_path(char *buff, int buff_size, const char *path);

// get relative path
void config_get_relative_path(char *buff, int buff_size, const char *path);

// update midi input params
void config_set_midi_input_config(const char *device, const midi_input_config_t &config);

// get midi input enable.
bool config_get_midi_input_config(const char *device, midi_input_config_t *config);

// select output
int config_select_output(int type, const char *device);

// get output type
int config_get_output_type();

// get current output type
int config_get_current_output_type();

// get output device
const char* config_get_output_device();

// get output delay
int config_get_output_delay();

// set output delay
void config_set_output_delay(int value);

// get volume
int config_get_output_volume();

// set volume
void config_set_output_volume(int volume);

// select instrument
int config_select_instrument(int type, const char *name);

// get instrument type
int config_get_instrument_type();

// get instrument
const char* config_get_instrument_path();

// get enable resize window
bool config_get_enable_resize_window();
void config_set_enable_resize_window(bool enable);

// get enable resize window
bool config_get_enable_hotkey();
void config_set_enable_hotkey(bool enable);

// get display midi type
bool config_get_midi_transpose();
void config_set_midi_transpose(bool value);

// get keymap
const char* config_get_keymap();

// set keymap
int config_set_keymap(const char *mapname);

// save keymap
char* config_save_keymap();

// parse keymap
int config_parse_keymap(const char *command, byte override_key = 0, uint version = 0);

// dump key bind
char* config_dump_keybind(byte code);

// clear key binding
void config_bind_clear_keydown(byte code);
void config_bind_clear_keyup(byte code);

// get key binding
int config_bind_get_keydown(byte code, key_bind_t *buffer, int size);
int config_bind_get_keyup(byte code, key_bind_t *buffer, int size);

// add key binding
void config_bind_add_keydown(byte code, key_bind_t bind);
void config_bind_add_keyup(byte code, key_bind_t bind);

// set label
void config_bind_set_label(byte code, const char *label);

// get keyboard label
const char* config_bind_get_label(byte code);

// clear key setting
void config_clear_key_setting();

// copy key setting
void config_copy_key_setting();

// paste key setting
void config_paste_key_setting();

// default key setting
void config_default_key_setting();

// set key signature
void config_set_key_signature(char key);

// get key signature
char config_get_key_signature();

// set key transpose
void config_set_key_transpose(byte channel, char transpose);

// get key transpose
char config_get_key_transpose(byte channel);

// set oct shift
void config_set_key_octshift(byte channel, char shift);

// get oct shift
char config_get_key_octshift(byte channel);

// set velocity
void config_set_key_velocity(byte channel, byte velocity);

// get velocity
byte config_get_key_velocity(byte channel);

// get channel
int config_get_key_channel(byte channel);

// get channel
void config_set_key_channel(byte channel, byte value);

// get program
byte config_get_program(byte channel);

// set midi program
void config_set_program(byte channel, byte value);

// get program
byte config_get_controller(byte channel, byte id);

// set midi program
void config_set_controller(byte channel, byte id, byte value);

// get setting group
uint config_get_setting_group();

// set setting group
void config_set_setting_group(uint id);

// insert setting group
void config_insert_setting_group(uint pos);

// delete settting group
void config_delete_setting_group(uint id);

// get setting group count
uint config_get_setting_group_count();

// set setting group count
void config_set_setting_group_count(uint count);

// get auto pedal time
char config_get_auto_pedal();

// set auto pedal time
void config_set_auto_pedal(char value);

// set keyup mode
void config_set_delay_keyup(byte channel, char value);

// get keyup mode
char config_get_delay_keyup(byte channel);

// get key name
const char* config_get_key_name(byte code);

// instrument show midi 
bool config_get_instrument_show_midi();
void config_set_instrument_show_midi(bool value);

// instrument show midi 
bool config_get_instrument_show_vsti();
void config_set_instrument_show_vsti(bool value);

// fixed doh
bool config_get_fixed_doh();
void config_set_fixed_doh(bool value);

// key fade speed
int config_get_key_fade();
void config_set_key_fade(int value);

// gui transparency
void config_set_gui_transparency(byte value);
byte config_get_gui_transparency();