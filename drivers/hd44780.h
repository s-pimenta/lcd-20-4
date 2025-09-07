#ifndef HD44780_H
#define HD44780_H

#include "pico/stdlib.h" // Pico Standard Library

// ### YOU CAN CHANGE AFTER THIS LINE ###

// Defining pins (values accepted: 0-29)
#define RS_PIN 1 // Register Select pin
#define E_PIN 2  // Enable pin
#define D4_PIN 4 // Data 4 pin
#define D5_PIN 5 // Data 5 pin
#define D6_PIN 6 // Data 6 pin
#define D7_PIN 7 // Data 7 pin

// ### DO NOT CHANGE AFTER THIS LINE ###

// Creates a bitmask of the pins will be used to the LCD screen
#define PINS_BITMASK ((1u << RS_PIN) | (1u << E_PIN) | (1u << D4_PIN) | (1u << D5_PIN) | (1u << D6_PIN) | (1u << D7_PIN))   

// Instructions to initialize the LCD
#define MODE_8BIT 0x03
#define MODE_4BIT 0x02

// Function set
// |0|0|1|DL|N|F|-|-|
// DL: 1 -> 8-bits    | 0 -> 4-bits (Data Length)
// N:  1 -> 2 lines   | 0 -> 1 line (Number display lines)
// F:  1 -> 5x10 dots | 0 -> 5x8 dots (Character Font)
//                                    D
//                                 001LNF--
#define MODE_4BIT_2LINES_5X8FONT 0b00101000 //0x28

// Display on/off control
// |0|0|0|0|1|D|C|B|
// D: 1 -> Display on | 0 -> Display off
// C: 1 -> Cursor on  | 0 -> Cursor off
// B: 1 -> Blink on   | 0 -> Blink off
//                                    00001DCB
#define DISPLAY_OFF                 0b00001000 //0x08
#define DISPLAY_ON_NOCURSOR_NOBLINK 0b00001100 //0x0C
#define DISPLAY_ON_CURSOR_BLINK     0b00001111 //0x0F
#define DISPLAY_ON_NOCURSOR_BLINK   0b00001101 //0x0D
#define DISPLAY_ON_CURSOR_NOBLINK   0b00001110 //0x0E

// Clear display
// Clears entire display and sets the DDRAM address to 0
#define CLEAR_DISPLAY 0x01

// Entry mode set
// |0|0|0|0|0|1|I/D|S|
// I/D: 1 -> Increment | 0 -> Decrement
#define ENTRY_MODE_INCREMENT_NOSHIFT 0b00000110 // 0x06
#define ENTRY_MODE_DECREMENT_NOSHIFT 0b00000100 // 0x04

//Characters codes
#define SPACE_CHAR "\x20" // [ ]
#define EXCLAMATION_CHAR "\x21" // [!]
#define QUOTE_CHAR "\x22" // ["]
#define HASH_CHAR "\x23" // [#]
#define DOLLAR_CHAR "\x24" // [$]
#define PERCENT_CHAR "\x25" // [%]
#define AMPERSAND_CHAR "\x26" // [&]
#define APOSTROPHE_CHAR "\x27" // [']
#define LEFT_PARENTHESIS_CHAR "\x28" // [(]
#define RIGHT_PARENTHESIS_CHAR "\x29" // [)]
#define ASTERISK_CHAR "\x2A" // [*]
#define PLUS_CHAR "\x2B" // [+]
#define COMMA_CHAR "\x2C" // [,]
#define MINUS_CHAR "\x2D" // [-]
#define PERIOD_CHAR "\x2E" // [.]
#define SLASH_CHAR "\x2F" // [/]
#define ZERO_CHAR "\x30" // [0]
#define ONE_CHAR "\x31" // [1]
#define TWO_CHAR "\x32" // [2]
#define THREE_CHAR "\x33" // [3]
#define FOUR_CHAR "\x34" // [4]
#define FIVE_CHAR "\x35" // [5]
#define SIX_CHAR "\x36" // [6]
#define SEVEN_CHAR "\x37" // [7]
#define EIGHT_CHAR "\x38" // [8]
#define NINE_CHAR "\x39" // [9]
#define COLON_CHAR "\x3A" // [:]
#define SEMI_COLON_CHAR "\x3B" // [;]
#define LESS_THAN_CHAR "\x3C" // [<]
#define EQUALS_CHAR "\x3D" // [=]
#define MORE_THAN_CHAR "\x3E" // [>]
#define QUESTION_CHAR "\x3F" // [?]
#define AT_CHAR "\x40" // [@]
#define UPPER_A_CHAR "\x41" // [A]
#define UPPER_B_CHAR "\x42" // [B]
#define UPPER_C_CHAR "\x43" // [C]
#define UPPER_D_CHAR "\x44" // [D]
#define UPPER_E_CHAR "\x45" // [E]
#define UPPER_F_CHAR "\x46" // [F]
#define UPPER_G_CHAR "\x47" // [G]
#define UPPER_H_CHAR "\x48" // [H]
#define UPPER_I_CHAR "\x49" // [I]
#define UPPER_J_CHAR "\x4A" // [J]
#define UPPER_K_CHAR "\x4B" // [K]
#define UPPER_L_CHAR "\x4C" // [L]
#define UPPER_M_CHAR "\x4D" // [M]
#define UPPER_N_CHAR "\x4E" // [N]
#define UPPER_O_CHAR "\x4F" // [O]
#define UPPER_P_CHAR "\x50" // [P]
#define UPPER_Q_CHAR "\x51" // [Q]
#define UPPER_R_CHAR "\x52" // [R]
#define UPPER_S_CHAR "\x53" // [S]
#define UPPER_T_CHAR "\x54" // [T]
#define UPPER_U_CHAR "\x55" // [U]
#define UPPER_V_CHAR "\x56" // [V]
#define UPPER_W_CHAR "\x57" // [W]
#define UPPER_X_CHAR "\x58" // [X]
#define UPPER_Y_CHAR "\x59" // [Y]
#define UPPER_Z_CHAR "\x5A" // [Z]
#define LEFT_SQUARE_BRACKET_CHAR "\x5B" // "["
#define YEN_CHAR "\x5C" // [¥]
#define RIGHT_SQUARE_BRACKET_CHAR "\x5D" // "]"
#define CARET_CHAR "\x5E" // [^]
#define UNDERSCORE_CHAR "\x5F" // [_]
#define GRAVE_ACCENT_CHAR "\x60" // [`]
#define LOWER_A_CHAR "\x61" // [a]
#define LOWER_B_CHAR "\x62" // [b]
#define LOWER_C_CHAR "\x63" // [c]
#define LOWER_D_CHAR "\x64" // [d]
#define LOWER_E_CHAR "\x65" // [e]
#define LOWER_F_CHAR "\x66" // [f]
#define LOWER_G_CHAR "\x67" // [g]
#define LOWER_H_CHAR "\x68" // [h]
#define LOWER_I_CHAR "\x69" // [i]
#define LOWER_J_CHAR "\x6A" // [j]
#define LOWER_K_CHAR "\x6B" // [k]
#define LOWER_L_CHAR "\x6C" // [l]
#define LOWER_M_CHAR "\x6D" // [m]
#define LOWER_N_CHAR "\x6E" // [n]
#define LOWER_O_CHAR "\x6F" // [o]
#define LOWER_P_CHAR "\x70" // [p]
#define LOWER_Q_CHAR "\x71" // [q]
#define LOWER_R_CHAR "\x72" // [r]
#define LOWER_S_CHAR "\x73" // [s]
#define LOWER_T_CHAR "\x74" // [t]
#define LOWER_U_CHAR "\x75" // [u]
#define LOWER_V_CHAR "\x76" // [v]
#define LOWER_W_CHAR "\x77" // [w]
#define LOWER_X_CHAR "\x78" // [x]
#define LOWER_Y_CHAR "\x79" // [y]
#define LOWER_Z_CHAR "\x7A" // [z]
#define OPEN_BRACE_CHAR "\x7B" // [{]
#define VERTICAL_BAR_CHAR "\x7C" // [|]
#define CLOSE_BRACE_CHAR "\x7D" // [}]
#define RIGHT_ARROW_CHAR "\x7E" // [->]
#define LEFT_ARROW_CHAR "\x7F" // [<-]

#define JP_FULL_STOP_CHAR "\xA1" // [。]
#define JP_LEFT_BRACKET_CHAR "\xA2" // [｢]
#define JP_RIGHT_BRACKET_CHAR "\xA3" // [｣]
#define JP_COMMA_CHAR "\xA4" // [､]
#define JP_MIDDLE_DOT_CHAR "\xA5" // [･]
#define JP_WO_CHAR "\xA6" // [ｦ]
#define JP_SMALL_A_CHAR "\xA7" // [ｧ]
#define JP_SMALL_I_CHAR "\xA8" // [ｨ]
#define JP_SMALL_U_CHAR "\xA9" // [ｩ]
#define JP_SMALL_E_CHAR "\xAA" // [ｪ]
#define JP_SMALL_O_CHAR "\xAB" // [ｫ]
#define JP_YA_CHAR "\xAC" // [ｬ]
#define JP_YU_CHAR "\xAD" // [ｭ]
#define JP_YO_CHAR "\xAE" // [ｮ]
#define JP_TU_CHAR "\xAF" // [ｯ]
#define JP_PROLONGED_CHAR "\xB0" // [ｰ]
#define JP_A_CHAR "\xB1" // [ｧ]
#define JP_I_CHAR "\xB2" // [ｲ]
#define JP_U_CHAR "\xB3" // [ｳ]
#define JP_E_CHAR "\xB4" // [ｴ]
#define JP_O_CHAR "\xB5" // [ｵ]
#define JP_KA_CHAR "\xB6" // [ｶ]
#define JP_KI_CHAR "\xB7" // [ｷ]
#define JP_KU_CHAR "\xB8" // [ｸ]
#define JP_KE_CHAR "\xB9" // [ｹ]
#define JP_KO_CHAR "\xBA" // [ｺ]
#define JP_SA_CHAR "\xBB" // [ｻ]
#define JP_SI_CHAR "\xBC" // [ｼ]
#define JP_SU_CHAR "\xBD" // [ｽ]
#define JP_SE_CHAR "\xBE" // [ｾ]
#define JP_SO_CHAR "\xBF" // [ｿ]
#define JP_TA_CHAR "\xC0" // [ﾀ]
#define JP_TI_CHAR "\xC1" // [ﾁ]
#define JP_TU_CHAR "\xC2" // [ﾂ]
#define JP_TE_CHAR "\xC3" // [ﾃ]
#define JP_TO_CHAR "\xC4" // [ﾄ]
#define JP_NA_CHAR "\xC5" // [ﾅ]
#define JP_NI_CHAR "\xC6" // [ﾆ]
#define JP_NU_CHAR "\xC7" // [ﾇ]
#define JP_NE_CHAR "\xC8" // [ﾈ]
#define JP_NO_CHAR "\xC9" // [ﾉ]
#define JP_HA_CHAR "\xCA" // [ﾊ]
#define JP_HI_CHAR "\xCB" // [ﾋ]
#define JP_HU_CHAR "\xCC" // [ﾌ]
#define JP_HE_CHAR "\xCD" // [ﾍ]
#define JP_HO_CHAR "\xCE" // [ﾎ]
#define JP_MA_CHAR "\xCF" // [ﾏ]
#define JP_MI_CHAR "\xD0" // [ﾐ]
#define JP_MU_CHAR "\xD1" // [ﾑ]
#define JP_ME_CHAR "\xD2" // [ﾒ]
#define JP_MO_CHAR "\xD3" // [ﾓ]
#define JP_YA_CHAR "\xD4" // [ﾔ]
#define JP_YU_CHAR "\xD5" // [ﾕ]
#define JP_YO_CHAR "\xD6" // [ﾖ]
#define JP_RA_CHAR "\xD7" // [ﾗ]
#define JP_RI_CHAR "\xD8" // [ﾘ]
#define JP_RU_CHAR "\xD9" // [ﾙ]
#define JP_RE_CHAR "\xDA" // [ﾚ]
#define JP_RO_CHAR "\xDB" // [ﾛ]
#define JP_WA_CHAR "\xDC" // [ﾜ]
#define JP_N_CHAR "\xDD" // [ﾝ]
#define JP_VOICED_SOUND_MARK_CHAR "\xDE" // [ﾞ]
#define JP_SEMI_VOICED_SOUND_MARK_CHAR "\xDF" // [ﾟ]

#define ALPHA_CHAR "\xE0" // [α]
#define A_DIAERESIS_CHAR "\xE1" // [ä]
#define BETA_CHAR "\xE2" // [β]
#define EPSILON_CHAR "\xE3" // [ε]
#define MU_CHAR "\xE4" // [μ]
#define DELTA_CHAR "\xE5" // [δ]
#define RHO_CHAR "\xE6" // [ρ]
#define Q_CHAR "\xE7" // [q]

#define SQUARE_ROOT_CHAR "\xE8" // [√]
#define NEGATIVE_ONE_CHAR "\xE9" // [-1]
#define J_CHAR "\xEA" // [j]
#define SUPERSCRIPT_X_CHAR "\xEB" // [x]
#define CENT_CHAR "\xEC" // [¢]
#define TURKISH_LIRA_CHAR "\xED" //[₺]
#define ENE_CHAR "\xEE" // [ñ]
#define O_DIAERESIS_CHAR "\xEF" // [ö]

#define UPPER_RHO_CHAR "\xF0" // [p]
#define Q_CHAR_2 "\xF1" // [q]
#define THETA_CHAR "\xF2" // [ϴ]
#define F3_CHAR "\xF3" // [~]
#define OMEGA_CHAR "\xF4" // [Ω]

#define U_DIAERESIS_CHAR "\xF5" // [ü]

#define SUMMATION_CHAR "\xF6" // [∑]
#define PI_CHAR "\xF7" // [π]
#define X_BAR_CHAR "\xF8" // [x̄]

#define FA_CHAR "\xFA"
#define FB_CHAR "\xFB"
#define FC_CHAR "\xFC"

#define DIVISION_CHAR "\xFD" // [÷]
#define BLOCK_CHAR "\xFF" // [█]

//Function declarations
void lcd_init(void);
void lcd_write_nibble(uint8_t nibble);
void lcd_write_byte(uint8_t byte, bool is_data);
void lcd_pulse_enable();
void lcd_send_command(uint8_t cmd);
void lcd_send_char(char c);
void lcd_print(const char *text);

#endif