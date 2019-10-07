/*
 *   This file is part of the MLV Library.
 *
 *   Copyright (C) 2016 Adrien Boussicault 
 *
 *
 *    This Library is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    This Library is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this Library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <string>
#include <cassert>
#include <MLV/MLV_all.h>
#include <sstream>
#include <iostream>


// Uncomment the next line if you use MLV_2.0.2. You can also add this line 
// before including window.hpp in your code
#define MLV_202


namespace mlv {

typedef MLV_Color color_t;

template <typename TYPE>
std::string to_string( const TYPE & value ){
	std::ostringstream s;
	s << value;
	return std::string(s.str());	
}

namespace text {

typedef enum {
	center = MLV_TEXT_CENTER, /**< \~french Le texte est justifié au centre. */
	left = MLV_TEXT_LEFT, /**< \~french Le texte est justifié sur la gauche. */
	right = MLV_TEXT_RIGHT /**< \~french Le texte est justifié sur la doite. */
} justification_t;


typedef enum {
	horizontal_center = MLV_HORIZONTAL_CENTER, /**< \~french Le texte est centrée horizontalement 
	                        * dans la boîte. */
	horizonatl_left = MLV_HORIZONTAL_LEFT, /**< \~french Le texte est positioné sur la droite de 
	                      * la boîte. */
	horizontal_right = MLV_HORIZONTAL_RIGHT /**< \~french Le texte est positioné sur la gauche de
	                      * la boîte. */
} horizontal_position_t;

/** \~french 
 * \brief Énumère les différents types de positions verticales du texte dans une boîte.
 */
typedef enum {
	vertical_center = MLV_VERTICAL_CENTER, /**< \~french Le texte est centré horizonatalement 
	                      * dans la boîte. */
	vertical_top = MLV_VERTICAL_TOP, /**< \~french Le texte est positionné en haut de la
	                   * boîte. */
	vertical_bottom = MLV_VERTICAL_BOTTOM /**< \~french Le texte est positionné en bas de la 
	                     * boîte. */
} vertical_position_t;

};

struct point_t {
	point_t(): x(0), y(0) {}
	point_t(int x, int y): x(x), y(y) {}
	point_t(const point_t & point): x(point.x), y(point.y) {}

	int x;
	int y;
};

void wait_seconds( int seconds ){
	MLV_wait_seconds(seconds);
}

void wait_milliseconds( int milliseconds ){
	MLV_wait_milliseconds(milliseconds);
}

namespace box {

	struct adapted_text_t {
		point_t position;
		std::string message;
		int sizeInterligne;
		color_t borderColor;
		color_t textColor;
		color_t backgroundColor;
		text::justification_t text_justification;

		adapted_text_t(
			const point_t & position, const std::string & message,
			int sizeInterligne,
			color_t borderColor, color_t textColor, color_t backgroundColor,
			text::justification_t text_justification
		):
			position(position),
			message(message),
			sizeInterligne(sizeInterligne),
			borderColor(borderColor),
			textColor(textColor),
			backgroundColor(backgroundColor),
			text_justification(text_justification)
		{}
	};

	struct fixed_text_t {
		point_t position;
		int width;
		int height;
		std::string message;
		int sizeInterligne;
		color_t borderColor;
		color_t textColor;
		color_t backgroundColor;
		text::justification_t text_justification;
		text::horizontal_position_t horizontal_position;
		text::vertical_position_t vertical_position;


		fixed_text_t(
			const point_t & position, int width, int height, 
			const std::string & message, int sizeInterligne,
			color_t borderColor, color_t textColor, color_t backgroundColor,
			text::justification_t text_justification,
			text::horizontal_position_t horizontal_position,
			text::vertical_position_t vertical_position
		):
			position(position),
			width(width),
			height(height),
			message(message),
			sizeInterligne(sizeInterligne),
			borderColor(borderColor),
			textColor(textColor),
			backgroundColor(backgroundColor),
			text_justification(text_justification),
			horizontal_position(horizontal_position),
			vertical_position(vertical_position)
		{}
	};


	struct text_t {

		fixed_text_t* fixed_text;
		adapted_text_t* adapted_text;

		text_t(
			const point_t & position, const std::string & message,
			int sizeInterligne,
			color_t borderColor, color_t textColor, color_t backgroundColor,
			text::justification_t text_justification
		) : fixed_text(0), adapted_text(0) {
			adapted_text = new adapted_text_t(
				position, message, sizeInterligne, borderColor, textColor, 
				backgroundColor, text_justification
			);
		}

		text_t(
			const point_t & position, int width, int height, 
			const std::string & message, int sizeInterligne,
			color_t borderColor, color_t textColor, color_t backgroundColor,
			text::justification_t text_justification,
			text::horizontal_position_t horizontal_position,
			text::vertical_position_t vertical_position
		) : fixed_text(0), adapted_text(0) {
			fixed_text = new fixed_text_t(
				position, width, height, 
				message, sizeInterligne, borderColor, 
				textColor, backgroundColor, text_justification,
				horizontal_position, vertical_position
			);
		}

		~text_t(){
			delete( fixed_text );
			delete( adapted_text );
		}

	};

	struct input_t {
		MLV_Input_box* mlv_input_box;
		point_t top_left_corner;
		int width;
		int height;
		color_t borderColor;
		color_t textColor;
		color_t backgroundColor;
		std::string informativeMessage;

		input_t(
			const point_t & top_left_corner,
			int width, int height,
			color_t borderColor, color_t textColor, color_t backgroundColor,
			const std::string & informativeMessage
		):
			mlv_input_box(0),
			top_left_corner(top_left_corner),
			width(width),
			height(height),
			borderColor(borderColor),
			textColor(textColor),
			backgroundColor(backgroundColor),
			informativeMessage(informativeMessage)
		{ }
	};
};

namespace keyboard {
	typedef enum {
		none = MLV_KEYBOARD_NONE,
		first = MLV_KEYBOARD_FIRST,
		backspace = MLV_KEYBOARD_BACKSPACE,
		tab = MLV_KEYBOARD_TAB,
		clear = MLV_KEYBOARD_CLEAR,
		return_ = MLV_KEYBOARD_RETURN,
		pause = MLV_KEYBOARD_PAUSE,
		escape = MLV_KEYBOARD_ESCAPE,
		space = MLV_KEYBOARD_SPACE,
		exclaim = MLV_KEYBOARD_EXCLAIM,
		quotedbl = MLV_KEYBOARD_QUOTEDBL,
		hash = MLV_KEYBOARD_HASH,
		dollar = MLV_KEYBOARD_DOLLAR,
		ampersand = MLV_KEYBOARD_AMPERSAND,
		quote = MLV_KEYBOARD_QUOTE,
		leftparen = MLV_KEYBOARD_LEFTPAREN,
		rightparen = MLV_KEYBOARD_RIGHTPAREN,
		asterisk = MLV_KEYBOARD_ASTERISK,
		plus = MLV_KEYBOARD_PLUS,
		comma = MLV_KEYBOARD_COMMA,
		minus = MLV_KEYBOARD_MINUS,
		period = MLV_KEYBOARD_PERIOD,
		slash = MLV_KEYBOARD_SLASH,
		k0 = MLV_KEYBOARD_0,
		k1 = MLV_KEYBOARD_1,
		k2 = MLV_KEYBOARD_2,
		k3 = MLV_KEYBOARD_3,
		k4 = MLV_KEYBOARD_4,
		k5 = MLV_KEYBOARD_5,
		k6 = MLV_KEYBOARD_6,
		k7 = MLV_KEYBOARD_7,
		k8 = MLV_KEYBOARD_8,
		k9 = MLV_KEYBOARD_9,
		colon = MLV_KEYBOARD_COLON,
		semicolon = MLV_KEYBOARD_SEMICOLON,
		less = MLV_KEYBOARD_LESS,
		equals = MLV_KEYBOARD_EQUALS,
		greater = MLV_KEYBOARD_GREATER,
		question = MLV_KEYBOARD_QUESTION,
		at = MLV_KEYBOARD_AT,

		leftbracket = MLV_KEYBOARD_LEFTBRACKET,
		backslash = MLV_KEYBOARD_BACKSLASH,
		rightbracket = MLV_KEYBOARD_RIGHTBRACKET,
		caret = MLV_KEYBOARD_CARET,
		underscore = MLV_KEYBOARD_UNDERSCORE,
		backquote = MLV_KEYBOARD_BACKQUOTE,
		a = MLV_KEYBOARD_a,
		b = MLV_KEYBOARD_b,
		c = MLV_KEYBOARD_c,
		d = MLV_KEYBOARD_d,
		e = MLV_KEYBOARD_e,
		f = MLV_KEYBOARD_f,
		g = MLV_KEYBOARD_g,
		h = MLV_KEYBOARD_h,
		i = MLV_KEYBOARD_i,
		j = MLV_KEYBOARD_j,
		k = MLV_KEYBOARD_k,
		l = MLV_KEYBOARD_l,
		m = MLV_KEYBOARD_m,
		n = MLV_KEYBOARD_n,
		o = MLV_KEYBOARD_o,
		p = MLV_KEYBOARD_p,
		q = MLV_KEYBOARD_q,
		r = MLV_KEYBOARD_r,
		s = MLV_KEYBOARD_s,
		t = MLV_KEYBOARD_t,
		u = MLV_KEYBOARD_u,
		v = MLV_KEYBOARD_v,
		w = MLV_KEYBOARD_w,
		x = MLV_KEYBOARD_x,
		y = MLV_KEYBOARD_y,
		z = MLV_KEYBOARD_z,
		delete_ = MLV_KEYBOARD_DELETE,

		world_0 = MLV_KEYBOARD_WORLD_0,
		world_1 = MLV_KEYBOARD_WORLD_1,
		world_2 = MLV_KEYBOARD_WORLD_2,
		world_3 = MLV_KEYBOARD_WORLD_3,
		world_4 = MLV_KEYBOARD_WORLD_4,
		world_5 = MLV_KEYBOARD_WORLD_5,
		world_6 = MLV_KEYBOARD_WORLD_6,
		world_7 = MLV_KEYBOARD_WORLD_7,
		world_8 = MLV_KEYBOARD_WORLD_8,
		world_9 = MLV_KEYBOARD_WORLD_9,
		world_10 = MLV_KEYBOARD_WORLD_10,
		world_11 = MLV_KEYBOARD_WORLD_11,
		world_12 = MLV_KEYBOARD_WORLD_12,
		world_13 = MLV_KEYBOARD_WORLD_13,
		world_14 = MLV_KEYBOARD_WORLD_14,
		world_15 = MLV_KEYBOARD_WORLD_15,
		world_16 = MLV_KEYBOARD_WORLD_16,
		world_17 = MLV_KEYBOARD_WORLD_17,
		world_18 = MLV_KEYBOARD_WORLD_18,
		world_19 = MLV_KEYBOARD_WORLD_19,
		world_20 = MLV_KEYBOARD_WORLD_20,
		world_21 = MLV_KEYBOARD_WORLD_21,
		world_22 = MLV_KEYBOARD_WORLD_22,
		world_23 = MLV_KEYBOARD_WORLD_23,
		world_24 = MLV_KEYBOARD_WORLD_24,
		world_25 = MLV_KEYBOARD_WORLD_25,
		world_26 = MLV_KEYBOARD_WORLD_26,
		world_27 = MLV_KEYBOARD_WORLD_27,
		world_28 = MLV_KEYBOARD_WORLD_28,
		world_29 = MLV_KEYBOARD_WORLD_29,
		world_30 = MLV_KEYBOARD_WORLD_30,
		world_31 = MLV_KEYBOARD_WORLD_31,
		world_32 = MLV_KEYBOARD_WORLD_32,
		world_33 = MLV_KEYBOARD_WORLD_33,
		world_34 = MLV_KEYBOARD_WORLD_34,
		world_35 = MLV_KEYBOARD_WORLD_35,
		world_36 = MLV_KEYBOARD_WORLD_36,
		world_37 = MLV_KEYBOARD_WORLD_37,
		world_38 = MLV_KEYBOARD_WORLD_38,
		world_39 = MLV_KEYBOARD_WORLD_39,
		world_40 = MLV_KEYBOARD_WORLD_40,
		world_41 = MLV_KEYBOARD_WORLD_41,
		world_42 = MLV_KEYBOARD_WORLD_42,
		world_43 = MLV_KEYBOARD_WORLD_43,
		world_44 = MLV_KEYBOARD_WORLD_44,
		world_45 = MLV_KEYBOARD_WORLD_45,
		world_46 = MLV_KEYBOARD_WORLD_46,
		world_47 = MLV_KEYBOARD_WORLD_47,
		world_48 = MLV_KEYBOARD_WORLD_48,
		world_49 = MLV_KEYBOARD_WORLD_49,
		world_50 = MLV_KEYBOARD_WORLD_50,
		world_51 = MLV_KEYBOARD_WORLD_51,
		world_52 = MLV_KEYBOARD_WORLD_52,
		world_53 = MLV_KEYBOARD_WORLD_53,
		world_54 = MLV_KEYBOARD_WORLD_54,
		world_55 = MLV_KEYBOARD_WORLD_55,
		world_56 = MLV_KEYBOARD_WORLD_56,
		world_57 = MLV_KEYBOARD_WORLD_57,
		world_58 = MLV_KEYBOARD_WORLD_58,
		world_59 = MLV_KEYBOARD_WORLD_59,
		world_60 = MLV_KEYBOARD_WORLD_60,
		world_61 = MLV_KEYBOARD_WORLD_61,
		world_62 = MLV_KEYBOARD_WORLD_62,
		world_63 = MLV_KEYBOARD_WORLD_63,
		world_64 = MLV_KEYBOARD_WORLD_64,
		world_65 = MLV_KEYBOARD_WORLD_65,
		world_66 = MLV_KEYBOARD_WORLD_66,
		world_67 = MLV_KEYBOARD_WORLD_67,
		world_68 = MLV_KEYBOARD_WORLD_68,
		world_69 = MLV_KEYBOARD_WORLD_69,
		world_70 = MLV_KEYBOARD_WORLD_70,
		world_71 = MLV_KEYBOARD_WORLD_71,
		world_72 = MLV_KEYBOARD_WORLD_72,
		world_73 = MLV_KEYBOARD_WORLD_73,
		world_74 = MLV_KEYBOARD_WORLD_74,
		world_75 = MLV_KEYBOARD_WORLD_75,
		world_76 = MLV_KEYBOARD_WORLD_76,
		world_77 = MLV_KEYBOARD_WORLD_77,
		world_78 = MLV_KEYBOARD_WORLD_78,
		world_79 = MLV_KEYBOARD_WORLD_79,
		world_80 = MLV_KEYBOARD_WORLD_80,
		world_81 = MLV_KEYBOARD_WORLD_81,
		world_82 = MLV_KEYBOARD_WORLD_82,
		world_83 = MLV_KEYBOARD_WORLD_83,
		world_84 = MLV_KEYBOARD_WORLD_84,
		world_85 = MLV_KEYBOARD_WORLD_85,
		world_86 = MLV_KEYBOARD_WORLD_86,
		world_87 = MLV_KEYBOARD_WORLD_87,
		world_88 = MLV_KEYBOARD_WORLD_88,
		world_89 = MLV_KEYBOARD_WORLD_89,
		world_90 = MLV_KEYBOARD_WORLD_90,
		world_91 = MLV_KEYBOARD_WORLD_91,
		world_92 = MLV_KEYBOARD_WORLD_92,
		world_93 = MLV_KEYBOARD_WORLD_93,
		world_94 = MLV_KEYBOARD_WORLD_94,
		world_95 = MLV_KEYBOARD_WORLD_95,

		kp0 = MLV_KEYBOARD_KP0,
		kp1 = MLV_KEYBOARD_KP1,
		kp2 = MLV_KEYBOARD_KP2,
		kp3 = MLV_KEYBOARD_KP3,
		kp4 = MLV_KEYBOARD_KP4,
		kp5 = MLV_KEYBOARD_KP5,
		kp6 = MLV_KEYBOARD_KP6,
		kp7 = MLV_KEYBOARD_KP7,
		kp8 = MLV_KEYBOARD_KP8,
		kp9 = MLV_KEYBOARD_KP9,
		kp_period = MLV_KEYBOARD_KP_PERIOD,
		kp_divide = MLV_KEYBOARD_KP_DIVIDE,
		kp_multiply = MLV_KEYBOARD_KP_MULTIPLY,
		kp_minus = MLV_KEYBOARD_KP_MINUS,
		kp_plus = MLV_KEYBOARD_KP_PLUS,
		kp_enter = MLV_KEYBOARD_KP_ENTER,
		kp_equals = MLV_KEYBOARD_KP_EQUALS,

		up = MLV_KEYBOARD_UP,
		down = MLV_KEYBOARD_DOWN,
		right = MLV_KEYBOARD_RIGHT,
		left = MLV_KEYBOARD_LEFT,
		insert = MLV_KEYBOARD_INSERT,
		home = MLV_KEYBOARD_HOME,
		end = MLV_KEYBOARD_END,
		pageup = MLV_KEYBOARD_PAGEUP,
		pagedown = MLV_KEYBOARD_PAGEDOWN,

		f1 = MLV_KEYBOARD_F1,
		f2 = MLV_KEYBOARD_F2,
		f3 = MLV_KEYBOARD_F3,
		f4 = MLV_KEYBOARD_F4,
		f5 = MLV_KEYBOARD_F5,
		f6 = MLV_KEYBOARD_F6,
		f7 = MLV_KEYBOARD_F7,
		f8 = MLV_KEYBOARD_F8,
		f9 = MLV_KEYBOARD_F9,
		f10 = MLV_KEYBOARD_F10,
		f11 = MLV_KEYBOARD_F11,
		f12 = MLV_KEYBOARD_F12,
		f13 = MLV_KEYBOARD_F13,
		f14 = MLV_KEYBOARD_F14,
		f15 = MLV_KEYBOARD_F15,

		numlock = MLV_KEYBOARD_NUMLOCK,
		capslock = MLV_KEYBOARD_CAPSLOCK,
		scrollock = MLV_KEYBOARD_SCROLLOCK,
		rshift = MLV_KEYBOARD_RSHIFT,
		lshift = MLV_KEYBOARD_LSHIFT,
		rctrl = MLV_KEYBOARD_RCTRL,
		lctrl = MLV_KEYBOARD_LCTRL,
		ralt = MLV_KEYBOARD_RALT,
		lalt = MLV_KEYBOARD_LALT,
		rmeta = MLV_KEYBOARD_RMETA,
		lmeta = MLV_KEYBOARD_LMETA,
		lsuper = MLV_KEYBOARD_LSUPER,
		rsuper = MLV_KEYBOARD_RSUPER,
		mode = MLV_KEYBOARD_MODE,
		compose = MLV_KEYBOARD_COMPOSE,

		help = MLV_KEYBOARD_HELP,
		print = MLV_KEYBOARD_PRINT,
		sysreq = MLV_KEYBOARD_SYSREQ,
		break_ = MLV_KEYBOARD_BREAK,
		menu = MLV_KEYBOARD_MENU,
		power = MLV_KEYBOARD_POWER,
		euro = MLV_KEYBOARD_EURO,
		undo = MLV_KEYBOARD_UNDO,

		last = MLV_KEYBOARD_LAST
	} key_t;

	typedef enum {
		kmod_none = MLV_KEYBOARD_KMOD_NONE,
		kmod_lshift = MLV_KEYBOARD_KMOD_LSHIFT,
		kmod_rshift = MLV_KEYBOARD_KMOD_RSHIFT,
		kmod_lctrl = MLV_KEYBOARD_KMOD_LCTRL,
		kmod_rctrl = MLV_KEYBOARD_KMOD_RCTRL,
		kmod_lalt = MLV_KEYBOARD_KMOD_LALT,
		kmod_ralt = MLV_KEYBOARD_KMOD_RALT,
		kmod_lmeta = MLV_KEYBOARD_KMOD_LMETA,
		kmod_rmeta = MLV_KEYBOARD_KMOD_RMETA,
		kmod_num = MLV_KEYBOARD_KMOD_NUM,
		kmod_caps = MLV_KEYBOARD_KMOD_CAPS,
		kmod_mode = MLV_KEYBOARD_KMOD_MODE,
		kmod_reserved = MLV_KEYBOARD_KMOD_RESERVED
	} modifier_t;
}

namespace color {
	color_t rgba( Uint8 red, Uint8 green, Uint8  blue, Uint8 alpha ){
		return MLV_rgba( red, green, blue, alpha );
	}

	color_t snow = rgba(255,250,250,255);
	color_t ghost_white = rgba(248,248,255,255);
	color_t ghostwhite = rgba(248,248,255,255);
	color_t white_smoke = rgba(245,245,245,255);
	color_t whitesmoke = rgba(245,245,245,255);
	color_t gainsboro = rgba(220,220,220,255);
	color_t floral_white = rgba(255,250,240,255);
	color_t floralwhite = rgba(255,250,240,255);
	color_t old_lace = rgba(253,245,230,255);
	color_t oldlace = rgba(253,245,230,255);
	color_t linen = rgba(250,240,230,255);
	color_t antique_white = rgba(250,235,215,255);
	color_t antiquewhite = rgba(250,235,215,255);
	color_t papaya_whip = rgba(255,239,213,255);
	color_t papayawhip = rgba(255,239,213,255);
	color_t blanched_almond = rgba(255,235,205,255);
	color_t blanchedalmond = rgba(255,235,205,255);
	color_t bisque = rgba(255,228,196,255);
	color_t peach_puff = rgba(255,218,185,255);
	color_t peachpuff = rgba(255,218,185,255);
	color_t navajo_white = rgba(255,222,173,255);
	color_t navajowhite = rgba(255,222,173,255);
	color_t moccasin = rgba(255,228,181,255);
	color_t cornsilk = rgba(255,248,220,255);
	color_t ivory = rgba(255,255,240,255);
	color_t lemon_chiffon = rgba(255,250,205,255);
	color_t lemonchiffon = rgba(255,250,205,255);
	color_t seashell = rgba(255,245,238,255);
	color_t honeydew = rgba(240,255,240,255);
	color_t mint_cream = rgba(245,255,250,255);
	color_t mintcream = rgba(245,255,250,255);
	color_t azure = rgba(240,255,255,255);
	color_t alice_blue = rgba(240,248,255,255);
	color_t aliceblue = rgba(240,248,255,255);
	color_t lavender = rgba(230,230,250,255);
	color_t lavender_blush = rgba(255,240,245,255);
	color_t lavenderblush = rgba(255,240,245,255);
	color_t misty_rose = rgba(255,228,225,255);
	color_t mistyrose = rgba(255,228,225,255);
	color_t white = rgba(255,255,255,255);
	color_t black = rgba(0,0,0,255);
	color_t dark_slate_gray = rgba(47,79,79,255);
	color_t darkslategray = rgba(47,79,79,255);
	color_t dark_slate_grey = rgba(47,79,79,255);
	color_t darkslategrey = rgba(47,79,79,255);
	color_t dim_gray = rgba(105,105,105,255);
	color_t dimgray = rgba(105,105,105,255);
	color_t dim_grey = rgba(105,105,105,255);
	color_t dimgrey = rgba(105,105,105,255);
	color_t slate_gray = rgba(112,128,144,255);
	color_t slategray = rgba(112,128,144,255);
	color_t slate_grey = rgba(112,128,144,255);
	color_t slategrey = rgba(112,128,144,255);
	color_t light_slate_gray = rgba(119,136,153,255);
	color_t lightslategray = rgba(119,136,153,255);
	color_t light_slate_grey = rgba(119,136,153,255);
	color_t lightslategrey = rgba(119,136,153,255);
	color_t gray = rgba(190,190,190,255);
	color_t grey = rgba(190,190,190,255);
	color_t light_grey = rgba(211,211,211,255);
	color_t lightgrey = rgba(211,211,211,255);
	color_t light_gray = rgba(211,211,211,255);
	color_t lightgray = rgba(211,211,211,255);
	color_t midnight_blue = rgba(25,25,112,255);
	color_t midnightblue = rgba(25,25,112,255);
	color_t navy = rgba(0,0,128,255);
	color_t navy_blue = rgba(0,0,128,255);
	color_t navyblue = rgba(0,0,128,255);
	color_t cornflower_blue = rgba(100,149,237,255);
	color_t cornflowerblue = rgba(100,149,237,255);
	color_t dark_slate_blue = rgba(72,61,139,255);
	color_t darkslateblue = rgba(72,61,139,255);
	color_t slate_blue = rgba(106,90,205,255);
	color_t slateblue = rgba(106,90,205,255);
	color_t medium_slate_blue = rgba(123,104,238,255);
	color_t mediumslateblue = rgba(123,104,238,255);
	color_t light_slate_blue = rgba(132,112,255,255);
	color_t lightslateblue = rgba(132,112,255,255);
	color_t medium_blue = rgba(0,0,205,255);
	color_t mediumblue = rgba(0,0,205,255);
	color_t royal_blue = rgba(65,105,225,255);
	color_t royalblue = rgba(65,105,225,255);
	color_t blue = rgba(0,0,255,255);
	color_t dodger_blue = rgba(30,144,255,255);
	color_t dodgerblue = rgba(30,144,255,255);
	color_t deep_sky_blue = rgba(0,191,255,255);
	color_t deepskyblue = rgba(0,191,255,255);
	color_t sky_blue = rgba(135,206,235,255);
	color_t skyblue = rgba(135,206,235,255);
	color_t light_sky_blue = rgba(135,206,250,255);
	color_t lightskyblue = rgba(135,206,250,255);
	color_t steel_blue = rgba(70,130,180,255);
	color_t steelblue = rgba(70,130,180,255);
	color_t light_steel_blue = rgba(176,196,222,255);
	color_t lightsteelblue = rgba(176,196,222,255);
	color_t light_blue = rgba(173,216,230,255);
	color_t lightblue = rgba(173,216,230,255);
	color_t powder_blue = rgba(176,224,230,255);
	color_t powderblue = rgba(176,224,230,255);
	color_t pale_turquoise = rgba(175,238,238,255);
	color_t paleturquoise = rgba(175,238,238,255);
	color_t dark_turquoise = rgba(0,206,209,255);
	color_t darkturquoise = rgba(0,206,209,255);
	color_t medium_turquoise = rgba(72,209,204,255);
	color_t mediumturquoise = rgba(72,209,204,255);
	color_t turquoise = rgba(64,224,208,255);
	color_t cyan = rgba(0,255,255,255);
	color_t light_cyan = rgba(224,255,255,255);
	color_t lightcyan = rgba(224,255,255,255);
	color_t cadet_blue = rgba(95,158,160,255);
	color_t cadetblue = rgba(95,158,160,255);
	color_t medium_aquamarine = rgba(102,205,170,255);
	color_t mediumaquamarine = rgba(102,205,170,255);
	color_t aquamarine = rgba(127,255,212,255);
	color_t dark_green = rgba(0,100,0,255);
	color_t darkgreen = rgba(0,100,0,255);
	color_t dark_olive_green = rgba(85,107,47,255);
	color_t darkolivegreen = rgba(85,107,47,255);
	color_t dark_sea_green = rgba(143,188,143,255);
	color_t darkseagreen = rgba(143,188,143,255);
	color_t sea_green = rgba(46,139,87,255);
	color_t seagreen = rgba(46,139,87,255);
	color_t medium_sea_green = rgba(60,179,113,255);
	color_t mediumseagreen = rgba(60,179,113,255);
	color_t light_sea_green = rgba(32,178,170,255);
	color_t lightseagreen = rgba(32,178,170,255);
	color_t pale_green = rgba(152,251,152,255);
	color_t palegreen = rgba(152,251,152,255);
	color_t spring_green = rgba(0,255,127,255);
	color_t springgreen = rgba(0,255,127,255);
	color_t lawn_green = rgba(124,252,0,255);
	color_t lawngreen = rgba(124,252,0,255);
	color_t green = rgba(0,255,0,255);
	color_t chartreuse = rgba(127,255,0,255);
	color_t medium_spring_green = rgba(0,250,154,255);
	color_t mediumspringgreen = rgba(0,250,154,255);
	color_t green_yellow = rgba(173,255,47,255);
	color_t greenyellow = rgba(173,255,47,255);
	color_t lime_green = rgba(50,205,50,255);
	color_t limegreen = rgba(50,205,50,255);
	color_t yellow_green = rgba(154,205,50,255);
	color_t yellowgreen = rgba(154,205,50,255);
	color_t forest_green = rgba(34,139,34,255);
	color_t forestgreen = rgba(34,139,34,255);
	color_t olive_drab = rgba(107,142,35,255);
	color_t olivedrab = rgba(107,142,35,255);
	color_t dark_khaki = rgba(189,183,107,255);
	color_t darkkhaki = rgba(189,183,107,255);
	color_t khaki = rgba(240,230,140,255);
	color_t pale_goldenrod = rgba(238,232,170,255);
	color_t palegoldenrod = rgba(238,232,170,255);
	color_t light_goldenrod_yellow = rgba(250,250,210,255);
	color_t lightgoldenrodyellow = rgba(250,250,210,255);
	color_t light_yellow = rgba(255,255,224,255);
	color_t lightyellow = rgba(255,255,224,255);
	color_t yellow = rgba(255,255,0,255);
	color_t gold = rgba(255,215,0,255);
	color_t light_goldenrod = rgba(238,221,130,255);
	color_t lightgoldenrod = rgba(238,221,130,255);
	color_t goldenrod = rgba(218,165,32,255);
	color_t dark_goldenrod = rgba(184,134,11,255);
	color_t darkgoldenrod = rgba(184,134,11,255);
	color_t rosy_brown = rgba(188,143,143,255);
	color_t rosybrown = rgba(188,143,143,255);
	color_t indian_red = rgba(205,92,92,255);
	color_t indianred = rgba(205,92,92,255);
	color_t saddle_brown = rgba(139,69,19,255);
	color_t saddlebrown = rgba(139,69,19,255);
	color_t sienna = rgba(160,82,45,255);
	color_t peru = rgba(205,133,63,255);
	color_t burlywood = rgba(222,184,135,255);
	color_t beige = rgba(245,245,220,255);
	color_t wheat = rgba(245,222,179,255);
	color_t sandy_brown = rgba(244,164,96,255);
	color_t sandybrown = rgba(244,164,96,255);
	color_t tan = rgba(210,180,140,255);
	color_t chocolate = rgba(210,105,30,255);
	color_t firebrick = rgba(178,34,34,255);
	color_t brown = rgba(165,42,42,255);
	color_t dark_salmon = rgba(233,150,122,255);
	color_t darksalmon = rgba(233,150,122,255);
	color_t salmon = rgba(250,128,114,255);
	color_t light_salmon = rgba(255,160,122,255);
	color_t lightsalmon = rgba(255,160,122,255);
	color_t orange = rgba(255,165,0,255);
	color_t dark_orange = rgba(255,140,0,255);
	color_t darkorange = rgba(255,140,0,255);
	color_t coral = rgba(255,127,80,255);
	color_t light_coral = rgba(240,128,128,255);
	color_t lightcoral = rgba(240,128,128,255);
	color_t tomato = rgba(255,99,71,255);
	color_t orange_red = rgba(255,69,0,255);
	color_t orangered = rgba(255,69,0,255);
	color_t red = rgba(255,0,0,255);
	color_t hot_pink = rgba(255,105,180,255);
	color_t hotpink = rgba(255,105,180,255);
	color_t deep_pink = rgba(255,20,147,255);
	color_t deeppink = rgba(255,20,147,255);
	color_t pink = rgba(255,192,203,255);
	color_t light_pink = rgba(255,182,193,255);
	color_t lightpink = rgba(255,182,193,255);
	color_t pale_violet_red = rgba(219,112,147,255);
	color_t palevioletred = rgba(219,112,147,255);
	color_t maroon = rgba(176,48,96,255);
	color_t medium_violet_red = rgba(199,21,133,255);
	color_t mediumvioletred = rgba(199,21,133,255);
	color_t violet_red = rgba(208,32,144,255);
	color_t violetred = rgba(208,32,144,255);
	color_t magenta = rgba(255,0,255,255);
	color_t violet = rgba(238,130,238,255);
	color_t plum = rgba(221,160,221,255);
	color_t orchid = rgba(218,112,214,255);
	color_t medium_orchid = rgba(186,85,211,255);
	color_t mediumorchid = rgba(186,85,211,255);
	color_t dark_orchid = rgba(153,50,204,255);
	color_t darkorchid = rgba(153,50,204,255);
	color_t dark_violet = rgba(148,0,211,255);
	color_t darkviolet = rgba(148,0,211,255);
	color_t blue_violet = rgba(138,43,226,255);
	color_t blueviolet = rgba(138,43,226,255);
	color_t purple = rgba(160,32,240,255);
	color_t medium_purple = rgba(147,112,219,255);
	color_t mediumpurple = rgba(147,112,219,255);
	color_t thistle = rgba(216,191,216,255);
	color_t snow1 = rgba(255,250,250,255);
	color_t snow2 = rgba(238,233,233,255);
	color_t snow3 = rgba(205,201,201,255);
	color_t snow4 = rgba(139,137,137,255);
	color_t seashell1 = rgba(255,245,238,255);
	color_t seashell2 = rgba(238,229,222,255);
	color_t seashell3 = rgba(205,197,191,255);
	color_t seashell4 = rgba(139,134,130,255);
	color_t antiquewhite1 = rgba(255,239,219,255);
	color_t antiquewhite2 = rgba(238,223,204,255);
	color_t antiquewhite3 = rgba(205,192,176,255);
	color_t antiquewhite4 = rgba(139,131,120,255);
	color_t bisque1 = rgba(255,228,196,255);
	color_t bisque2 = rgba(238,213,183,255);
	color_t bisque3 = rgba(205,183,158,255);
	color_t bisque4 = rgba(139,125,107,255);
	color_t peachpuff1 = rgba(255,218,185,255);
	color_t peachpuff2 = rgba(238,203,173,255);
	color_t peachpuff3 = rgba(205,175,149,255);
	color_t peachpuff4 = rgba(139,119,101,255);
	color_t navajowhite1 = rgba(255,222,173,255);
	color_t navajowhite2 = rgba(238,207,161,255);
	color_t navajowhite3 = rgba(205,179,139,255);
	color_t navajowhite4 = rgba(139,121,94,255);
	color_t lemonchiffon1 = rgba(255,250,205,255);
	color_t lemonchiffon2 = rgba(238,233,191,255);
	color_t lemonchiffon3 = rgba(205,201,165,255);
	color_t lemonchiffon4 = rgba(139,137,112,255);
	color_t cornsilk1 = rgba(255,248,220,255);
	color_t cornsilk2 = rgba(238,232,205,255);
	color_t cornsilk3 = rgba(205,200,177,255);
	color_t cornsilk4 = rgba(139,136,120,255);
	color_t ivory1 = rgba(255,255,240,255);
	color_t ivory2 = rgba(238,238,224,255);
	color_t ivory3 = rgba(205,205,193,255);
	color_t ivory4 = rgba(139,139,131,255);
	color_t honeydew1 = rgba(240,255,240,255);
	color_t honeydew2 = rgba(224,238,224,255);
	color_t honeydew3 = rgba(193,205,193,255);
	color_t honeydew4 = rgba(131,139,131,255);
	color_t lavenderblush1 = rgba(255,240,245,255);
	color_t lavenderblush2 = rgba(238,224,229,255);
	color_t lavenderblush3 = rgba(205,193,197,255);
	color_t lavenderblush4 = rgba(139,131,134,255);
	color_t mistyrose1 = rgba(255,228,225,255);
	color_t mistyrose2 = rgba(238,213,210,255);
	color_t mistyrose3 = rgba(205,183,181,255);
	color_t mistyrose4 = rgba(139,125,123,255);
	color_t azure1 = rgba(240,255,255,255);
	color_t azure2 = rgba(224,238,238,255);
	color_t azure3 = rgba(193,205,205,255);
	color_t azure4 = rgba(131,139,139,255);
	color_t slateblue1 = rgba(131,111,255,255);
	color_t slateblue2 = rgba(122,103,238,255);
	color_t slateblue3 = rgba(105,89,205,255);
	color_t slateblue4 = rgba(71,60,139,255);
	color_t royalblue1 = rgba(72,118,255,255);
	color_t royalblue2 = rgba(67,110,238,255);
	color_t royalblue3 = rgba(58,95,205,255);
	color_t royalblue4 = rgba(39,64,139,255);
	color_t blue1 = rgba(0,0,255,255);
	color_t blue2 = rgba(0,0,238,255);
	color_t blue3 = rgba(0,0,205,255);
	color_t blue4 = rgba(0,0,139,255);
	color_t dodgerblue1 = rgba(30,144,255,255);
	color_t dodgerblue2 = rgba(28,134,238,255);
	color_t dodgerblue3 = rgba(24,116,205,255);
	color_t dodgerblue4 = rgba(16,78,139,255);
	color_t steelblue1 = rgba(99,184,255,255);
	color_t steelblue2 = rgba(92,172,238,255);
	color_t steelblue3 = rgba(79,148,205,255);
	color_t steelblue4 = rgba(54,100,139,255);
	color_t deepskyblue1 = rgba(0,191,255,255);
	color_t deepskyblue2 = rgba(0,178,238,255);
	color_t deepskyblue3 = rgba(0,154,205,255);
	color_t deepskyblue4 = rgba(0,104,139,255);
	color_t skyblue1 = rgba(135,206,255,255);
	color_t skyblue2 = rgba(126,192,238,255);
	color_t skyblue3 = rgba(108,166,205,255);
	color_t skyblue4 = rgba(74,112,139,255);
	color_t lightskyblue1 = rgba(176,226,255,255);
	color_t lightskyblue2 = rgba(164,211,238,255);
	color_t lightskyblue3 = rgba(141,182,205,255);
	color_t lightskyblue4 = rgba(96,123,139,255);
	color_t slategray1 = rgba(198,226,255,255);
	color_t slategray2 = rgba(185,211,238,255);
	color_t slategray3 = rgba(159,182,205,255);
	color_t slategray4 = rgba(108,123,139,255);
	color_t lightsteelblue1 = rgba(202,225,255,255);
	color_t lightsteelblue2 = rgba(188,210,238,255);
	color_t lightsteelblue3 = rgba(162,181,205,255);
	color_t lightsteelblue4 = rgba(110,123,139,255);
	color_t lightblue1 = rgba(191,239,255,255);
	color_t lightblue2 = rgba(178,223,238,255);
	color_t lightblue3 = rgba(154,192,205,255);
	color_t lightblue4 = rgba(104,131,139,255);
	color_t lightcyan1 = rgba(224,255,255,255);
	color_t lightcyan2 = rgba(209,238,238,255);
	color_t lightcyan3 = rgba(180,205,205,255);
	color_t lightcyan4 = rgba(122,139,139,255);
	color_t paleturquoise1 = rgba(187,255,255,255);
	color_t paleturquoise2 = rgba(174,238,238,255);
	color_t paleturquoise3 = rgba(150,205,205,255);
	color_t paleturquoise4 = rgba(102,139,139,255);
	color_t cadetblue1 = rgba(152,245,255,255);
	color_t cadetblue2 = rgba(142,229,238,255);
	color_t cadetblue3 = rgba(122,197,205,255);
	color_t cadetblue4 = rgba(83,134,139,255);
	color_t turquoise1 = rgba(0,245,255,255);
	color_t turquoise2 = rgba(0,229,238,255);
	color_t turquoise3 = rgba(0,197,205,255);
	color_t turquoise4 = rgba(0,134,139,255);
	color_t cyan1 = rgba(0,255,255,255);
	color_t cyan2 = rgba(0,238,238,255);
	color_t cyan3 = rgba(0,205,205,255);
	color_t cyan4 = rgba(0,139,139,255);
	color_t darkslategray1 = rgba(151,255,255,255);
	color_t darkslategray2 = rgba(141,238,238,255);
	color_t darkslategray3 = rgba(121,205,205,255);
	color_t darkslategray4 = rgba(82,139,139,255);
	color_t aquamarine1 = rgba(127,255,212,255);
	color_t aquamarine2 = rgba(118,238,198,255);
	color_t aquamarine3 = rgba(102,205,170,255);
	color_t aquamarine4 = rgba(69,139,116,255);
	color_t darkseagreen1 = rgba(193,255,193,255);
	color_t darkseagreen2 = rgba(180,238,180,255);
	color_t darkseagreen3 = rgba(155,205,155,255);
	color_t darkseagreen4 = rgba(105,139,105,255);
	color_t seagreen1 = rgba(84,255,159,255);
	color_t seagreen2 = rgba(78,238,148,255);
	color_t seagreen3 = rgba(67,205,128,255);
	color_t seagreen4 = rgba(46,139,87,255);
	color_t palegreen1 = rgba(154,255,154,255);
	color_t palegreen2 = rgba(144,238,144,255);
	color_t palegreen3 = rgba(124,205,124,255);
	color_t palegreen4 = rgba(84,139,84,255);
	color_t springgreen1 = rgba(0,255,127,255);
	color_t springgreen2 = rgba(0,238,118,255);
	color_t springgreen3 = rgba(0,205,102,255);
	color_t springgreen4 = rgba(0,139,69,255);
	color_t green1 = rgba(0,255,0,255);
	color_t green2 = rgba(0,238,0,255);
	color_t green3 = rgba(0,205,0,255);
	color_t green4 = rgba(0,139,0,255);
	color_t chartreuse1 = rgba(127,255,0,255);
	color_t chartreuse2 = rgba(118,238,0,255);
	color_t chartreuse3 = rgba(102,205,0,255);
	color_t chartreuse4 = rgba(69,139,0,255);
	color_t olivedrab1 = rgba(192,255,62,255);
	color_t olivedrab2 = rgba(179,238,58,255);
	color_t olivedrab3 = rgba(154,205,50,255);
	color_t olivedrab4 = rgba(105,139,34,255);
	color_t darkolivegreen1 = rgba(202,255,112,255);
	color_t darkolivegreen2 = rgba(188,238,104,255);
	color_t darkolivegreen3 = rgba(162,205,90,255);
	color_t darkolivegreen4 = rgba(110,139,61,255);
	color_t khaki1 = rgba(255,246,143,255);
	color_t khaki2 = rgba(238,230,133,255);
	color_t khaki3 = rgba(205,198,115,255);
	color_t khaki4 = rgba(139,134,78,255);
	color_t lightgoldenrod1 = rgba(255,236,139,255);
	color_t lightgoldenrod2 = rgba(238,220,130,255);
	color_t lightgoldenrod3 = rgba(205,190,112,255);
	color_t lightgoldenrod4 = rgba(139,129,76,255);
	color_t lightyellow1 = rgba(255,255,224,255);
	color_t lightyellow2 = rgba(238,238,209,255);
	color_t lightyellow3 = rgba(205,205,180,255);
	color_t lightyellow4 = rgba(139,139,122,255);
	color_t yellow1 = rgba(255,255,0,255);
	color_t yellow2 = rgba(238,238,0,255);
	color_t yellow3 = rgba(205,205,0,255);
	color_t yellow4 = rgba(139,139,0,255);
	color_t gold1 = rgba(255,215,0,255);
	color_t gold2 = rgba(238,201,0,255);
	color_t gold3 = rgba(205,173,0,255);
	color_t gold4 = rgba(139,117,0,255);
	color_t goldenrod1 = rgba(255,193,37,255);
	color_t goldenrod2 = rgba(238,180,34,255);
	color_t goldenrod3 = rgba(205,155,29,255);
	color_t goldenrod4 = rgba(139,105,20,255);
	color_t darkgoldenrod1 = rgba(255,185,15,255);
	color_t darkgoldenrod2 = rgba(238,173,14,255);
	color_t darkgoldenrod3 = rgba(205,149,12,255);
	color_t darkgoldenrod4 = rgba(139,101,8,255);
	color_t rosybrown1 = rgba(255,193,193,255);
	color_t rosybrown2 = rgba(238,180,180,255);
	color_t rosybrown3 = rgba(205,155,155,255);
	color_t rosybrown4 = rgba(139,105,105,255);
	color_t indianred1 = rgba(255,106,106,255);
	color_t indianred2 = rgba(238,99,99,255);
	color_t indianred3 = rgba(205,85,85,255);
	color_t indianred4 = rgba(139,58,58,255);
	color_t sienna1 = rgba(255,130,71,255);
	color_t sienna2 = rgba(238,121,66,255);
	color_t sienna3 = rgba(205,104,57,255);
	color_t sienna4 = rgba(139,71,38,255);
	color_t burlywood1 = rgba(255,211,155,255);
	color_t burlywood2 = rgba(238,197,145,255);
	color_t burlywood3 = rgba(205,170,125,255);
	color_t burlywood4 = rgba(139,115,85,255);
	color_t wheat1 = rgba(255,231,186,255);
	color_t wheat2 = rgba(238,216,174,255);
	color_t wheat3 = rgba(205,186,150,255);
	color_t wheat4 = rgba(139,126,102,255);
	color_t tan1 = rgba(255,165,79,255);
	color_t tan2 = rgba(238,154,73,255);
	color_t tan3 = rgba(205,133,63,255);
	color_t tan4 = rgba(139,90,43,255);
	color_t chocolate1 = rgba(255,127,36,255);
	color_t chocolate2 = rgba(238,118,33,255);
	color_t chocolate3 = rgba(205,102,29,255);
	color_t chocolate4 = rgba(139,69,19,255);
	color_t firebrick1 = rgba(255,48,48,255);
	color_t firebrick2 = rgba(238,44,44,255);
	color_t firebrick3 = rgba(205,38,38,255);
	color_t firebrick4 = rgba(139,26,26,255);
	color_t brown1 = rgba(255,64,64,255);
	color_t brown2 = rgba(238,59,59,255);
	color_t brown3 = rgba(205,51,51,255);
	color_t brown4 = rgba(139,35,35,255);
	color_t salmon1 = rgba(255,140,105,255);
	color_t salmon2 = rgba(238,130,98,255);
	color_t salmon3 = rgba(205,112,84,255);
	color_t salmon4 = rgba(139,76,57,255);
	color_t lightsalmon1 = rgba(255,160,122,255);
	color_t lightsalmon2 = rgba(238,149,114,255);
	color_t lightsalmon3 = rgba(205,129,98,255);
	color_t lightsalmon4 = rgba(139,87,66,255);
	color_t orange1 = rgba(255,165,0,255);
	color_t orange2 = rgba(238,154,0,255);
	color_t orange3 = rgba(205,133,0,255);
	color_t orange4 = rgba(139,90,0,255);
	color_t darkorange1 = rgba(255,127,0,255);
	color_t darkorange2 = rgba(238,118,0,255);
	color_t darkorange3 = rgba(205,102,0,255);
	color_t darkorange4 = rgba(139,69,0,255);
	color_t coral1 = rgba(255,114,86,255);
	color_t coral2 = rgba(238,106,80,255);
	color_t coral3 = rgba(205,91,69,255);
	color_t coral4 = rgba(139,62,47,255);
	color_t tomato1 = rgba(255,99,71,255);
	color_t tomato2 = rgba(238,92,66,255);
	color_t tomato3 = rgba(205,79,57,255);
	color_t tomato4 = rgba(139,54,38,255);
	color_t orangered1 = rgba(255,69,0,255);
	color_t orangered2 = rgba(238,64,0,255);
	color_t orangered3 = rgba(205,55,0,255);
	color_t orangered4 = rgba(139,37,0,255);
	color_t red1 = rgba(255,0,0,255);
	color_t red2 = rgba(238,0,0,255);
	color_t red3 = rgba(205,0,0,255);
	color_t red4 = rgba(139,0,0,255);
	color_t deeppink1 = rgba(255,20,147,255);
	color_t deeppink2 = rgba(238,18,137,255);
	color_t deeppink3 = rgba(205,16,118,255);
	color_t deeppink4 = rgba(139,10,80,255);
	color_t hotpink1 = rgba(255,110,180,255);
	color_t hotpink2 = rgba(238,106,167,255);
	color_t hotpink3 = rgba(205,96,144,255);
	color_t hotpink4 = rgba(139,58,98,255);
	color_t pink1 = rgba(255,181,197,255);
	color_t pink2 = rgba(238,169,184,255);
	color_t pink3 = rgba(205,145,158,255);
	color_t pink4 = rgba(139,99,108,255);
	color_t lightpink1 = rgba(255,174,185,255);
	color_t lightpink2 = rgba(238,162,173,255);
	color_t lightpink3 = rgba(205,140,149,255);
	color_t lightpink4 = rgba(139,95,101,255);
	color_t palevioletred1 = rgba(255,130,171,255);
	color_t palevioletred2 = rgba(238,121,159,255);
	color_t palevioletred3 = rgba(205,104,137,255);
	color_t palevioletred4 = rgba(139,71,93,255);
	color_t maroon1 = rgba(255,52,179,255);
	color_t maroon2 = rgba(238,48,167,255);
	color_t maroon3 = rgba(205,41,144,255);
	color_t maroon4 = rgba(139,28,98,255);
	color_t violetred1 = rgba(255,62,150,255);
	color_t violetred2 = rgba(238,58,140,255);
	color_t violetred3 = rgba(205,50,120,255);
	color_t violetred4 = rgba(139,34,82,255);
	color_t magenta1 = rgba(255,0,255,255);
	color_t magenta2 = rgba(238,0,238,255);
	color_t magenta3 = rgba(205,0,205,255);
	color_t magenta4 = rgba(139,0,139,255);
	color_t orchid1 = rgba(255,131,250,255);
	color_t orchid2 = rgba(238,122,233,255);
	color_t orchid3 = rgba(205,105,201,255);
	color_t orchid4 = rgba(139,71,137,255);
	color_t plum1 = rgba(255,187,255,255);
	color_t plum2 = rgba(238,174,238,255);
	color_t plum3 = rgba(205,150,205,255);
	color_t plum4 = rgba(139,102,139,255);
	color_t mediumorchid1 = rgba(224,102,255,255);
	color_t mediumorchid2 = rgba(209,95,238,255);
	color_t mediumorchid3 = rgba(180,82,205,255);
	color_t mediumorchid4 = rgba(122,55,139,255);
	color_t darkorchid1 = rgba(191,62,255,255);
	color_t darkorchid2 = rgba(178,58,238,255);
	color_t darkorchid3 = rgba(154,50,205,255);
	color_t darkorchid4 = rgba(104,34,139,255);
	color_t purple1 = rgba(155,48,255,255);
	color_t purple2 = rgba(145,44,238,255);
	color_t purple3 = rgba(125,38,205,255);
	color_t purple4 = rgba(85,26,139,255);
	color_t mediumpurple1 = rgba(171,130,255,255);
	color_t mediumpurple2 = rgba(159,121,238,255);
	color_t mediumpurple3 = rgba(137,104,205,255);
	color_t mediumpurple4 = rgba(93,71,139,255);
	color_t thistle1 = rgba(255,225,255,255);
	color_t thistle2 = rgba(238,210,238,255);
	color_t thistle3 = rgba(205,181,205,255);
	color_t thistle4 = rgba(139,123,139,255);
	color_t gray0 = rgba(0,0,0,255);
	color_t grey0 = rgba(0,0,0,255);
	color_t gray1 = rgba(3,3,3,255);
	color_t grey1 = rgba(3,3,3,255);
	color_t gray2 = rgba(5,5,5,255);
	color_t grey2 = rgba(5,5,5,255);
	color_t gray3 = rgba(8,8,8,255);
	color_t grey3 = rgba(8,8,8,255);
	color_t gray4 = rgba(10,10,10,255);
	color_t grey4 = rgba(10,10,10,255);
	color_t gray5 = rgba(13,13,13,255);
	color_t grey5 = rgba(13,13,13,255);
	color_t gray6 = rgba(15,15,15,255);
	color_t grey6 = rgba(15,15,15,255);
	color_t gray7 = rgba(18,18,18,255);
	color_t grey7 = rgba(18,18,18,255);
	color_t gray8 = rgba(20,20,20,255);
	color_t grey8 = rgba(20,20,20,255);
	color_t gray9 = rgba(23,23,23,255);
	color_t grey9 = rgba(23,23,23,255);
	color_t gray10 = rgba(26,26,26,255);
	color_t grey10 = rgba(26,26,26,255);
	color_t gray11 = rgba(28,28,28,255);
	color_t grey11 = rgba(28,28,28,255);
	color_t gray12 = rgba(31,31,31,255);
	color_t grey12 = rgba(31,31,31,255);
	color_t gray13 = rgba(33,33,33,255);
	color_t grey13 = rgba(33,33,33,255);
	color_t gray14 = rgba(36,36,36,255);
	color_t grey14 = rgba(36,36,36,255);
	color_t gray15 = rgba(38,38,38,255);
	color_t grey15 = rgba(38,38,38,255);
	color_t gray16 = rgba(41,41,41,255);
	color_t grey16 = rgba(41,41,41,255);
	color_t gray17 = rgba(43,43,43,255);
	color_t grey17 = rgba(43,43,43,255);
	color_t gray18 = rgba(46,46,46,255);
	color_t grey18 = rgba(46,46,46,255);
	color_t gray19 = rgba(48,48,48,255);
	color_t grey19 = rgba(48,48,48,255);
	color_t gray20 = rgba(51,51,51,255);
	color_t grey20 = rgba(51,51,51,255);
	color_t gray21 = rgba(54,54,54,255);
	color_t grey21 = rgba(54,54,54,255);
	color_t gray22 = rgba(56,56,56,255);
	color_t grey22 = rgba(56,56,56,255);
	color_t gray23 = rgba(59,59,59,255);
	color_t grey23 = rgba(59,59,59,255);
	color_t gray24 = rgba(61,61,61,255);
	color_t grey24 = rgba(61,61,61,255);
	color_t gray25 = rgba(64,64,64,255);
	color_t grey25 = rgba(64,64,64,255);
	color_t gray26 = rgba(66,66,66,255);
	color_t grey26 = rgba(66,66,66,255);
	color_t gray27 = rgba(69,69,69,255);
	color_t grey27 = rgba(69,69,69,255);
	color_t gray28 = rgba(71,71,71,255);
	color_t grey28 = rgba(71,71,71,255);
	color_t gray29 = rgba(74,74,74,255);
	color_t grey29 = rgba(74,74,74,255);
	color_t gray30 = rgba(77,77,77,255);
	color_t grey30 = rgba(77,77,77,255);
	color_t gray31 = rgba(79,79,79,255);
	color_t grey31 = rgba(79,79,79,255);
	color_t gray32 = rgba(82,82,82,255);
	color_t grey32 = rgba(82,82,82,255);
	color_t gray33 = rgba(84,84,84,255);
	color_t grey33 = rgba(84,84,84,255);
	color_t gray34 = rgba(87,87,87,255);
	color_t grey34 = rgba(87,87,87,255);
	color_t gray35 = rgba(89,89,89,255);
	color_t grey35 = rgba(89,89,89,255);
	color_t gray36 = rgba(92,92,92,255);
	color_t grey36 = rgba(92,92,92,255);
	color_t gray37 = rgba(94,94,94,255);
	color_t grey37 = rgba(94,94,94,255);
	color_t gray38 = rgba(97,97,97,255);
	color_t grey38 = rgba(97,97,97,255);
	color_t gray39 = rgba(99,99,99,255);
	color_t grey39 = rgba(99,99,99,255);
	color_t gray40 = rgba(102,102,102,255);
	color_t grey40 = rgba(102,102,102,255);
	color_t gray41 = rgba(105,105,105,255);
	color_t grey41 = rgba(105,105,105,255);
	color_t gray42 = rgba(107,107,107,255);
	color_t grey42 = rgba(107,107,107,255);
	color_t gray43 = rgba(110,110,110,255);
	color_t grey43 = rgba(110,110,110,255);
	color_t gray44 = rgba(112,112,112,255);
	color_t grey44 = rgba(112,112,112,255);
	color_t gray45 = rgba(115,115,115,255);
	color_t grey45 = rgba(115,115,115,255);
	color_t gray46 = rgba(117,117,117,255);
	color_t grey46 = rgba(117,117,117,255);
	color_t gray47 = rgba(120,120,120,255);
	color_t grey47 = rgba(120,120,120,255);
	color_t gray48 = rgba(122,122,122,255);
	color_t grey48 = rgba(122,122,122,255);
	color_t gray49 = rgba(125,125,125,255);
	color_t grey49 = rgba(125,125,125,255);
	color_t gray50 = rgba(127,127,127,255);
	color_t grey50 = rgba(127,127,127,255);
	color_t gray51 = rgba(130,130,130,255);
	color_t grey51 = rgba(130,130,130,255);
	color_t gray52 = rgba(133,133,133,255);
	color_t grey52 = rgba(133,133,133,255);
	color_t gray53 = rgba(135,135,135,255);
	color_t grey53 = rgba(135,135,135,255);
	color_t gray54 = rgba(138,138,138,255);
	color_t grey54 = rgba(138,138,138,255);
	color_t gray55 = rgba(140,140,140,255);
	color_t grey55 = rgba(140,140,140,255);
	color_t gray56 = rgba(143,143,143,255);
	color_t grey56 = rgba(143,143,143,255);
	color_t gray57 = rgba(145,145,145,255);
	color_t grey57 = rgba(145,145,145,255);
	color_t gray58 = rgba(148,148,148,255);
	color_t grey58 = rgba(148,148,148,255);
	color_t gray59 = rgba(150,150,150,255);
	color_t grey59 = rgba(150,150,150,255);
	color_t gray60 = rgba(153,153,153,255);
	color_t grey60 = rgba(153,153,153,255);
	color_t gray61 = rgba(156,156,156,255);
	color_t grey61 = rgba(156,156,156,255);
	color_t gray62 = rgba(158,158,158,255);
	color_t grey62 = rgba(158,158,158,255);
	color_t gray63 = rgba(161,161,161,255);
	color_t grey63 = rgba(161,161,161,255);
	color_t gray64 = rgba(163,163,163,255);
	color_t grey64 = rgba(163,163,163,255);
	color_t gray65 = rgba(166,166,166,255);
	color_t grey65 = rgba(166,166,166,255);
	color_t gray66 = rgba(168,168,168,255);
	color_t grey66 = rgba(168,168,168,255);
	color_t gray67 = rgba(171,171,171,255);
	color_t grey67 = rgba(171,171,171,255);
	color_t gray68 = rgba(173,173,173,255);
	color_t grey68 = rgba(173,173,173,255);
	color_t gray69 = rgba(176,176,176,255);
	color_t grey69 = rgba(176,176,176,255);
	color_t gray70 = rgba(179,179,179,255);
	color_t grey70 = rgba(179,179,179,255);
	color_t gray71 = rgba(181,181,181,255);
	color_t grey71 = rgba(181,181,181,255);
	color_t gray72 = rgba(184,184,184,255);
	color_t grey72 = rgba(184,184,184,255);
	color_t gray73 = rgba(186,186,186,255);
	color_t grey73 = rgba(186,186,186,255);
	color_t gray74 = rgba(189,189,189,255);
	color_t grey74 = rgba(189,189,189,255);
	color_t gray75 = rgba(191,191,191,255);
	color_t grey75 = rgba(191,191,191,255);
	color_t gray76 = rgba(194,194,194,255);
	color_t grey76 = rgba(194,194,194,255);
	color_t gray77 = rgba(196,196,196,255);
	color_t grey77 = rgba(196,196,196,255);
	color_t gray78 = rgba(199,199,199,255);
	color_t grey78 = rgba(199,199,199,255);
	color_t gray79 = rgba(201,201,201,255);
	color_t grey79 = rgba(201,201,201,255);
	color_t gray80 = rgba(204,204,204,255);
	color_t grey80 = rgba(204,204,204,255);
	color_t gray81 = rgba(207,207,207,255);
	color_t grey81 = rgba(207,207,207,255);
	color_t gray82 = rgba(209,209,209,255);
	color_t grey82 = rgba(209,209,209,255);
	color_t gray83 = rgba(212,212,212,255);
	color_t grey83 = rgba(212,212,212,255);
	color_t gray84 = rgba(214,214,214,255);
	color_t grey84 = rgba(214,214,214,255);
	color_t gray85 = rgba(217,217,217,255);
	color_t grey85 = rgba(217,217,217,255);
	color_t gray86 = rgba(219,219,219,255);
	color_t grey86 = rgba(219,219,219,255);
	color_t gray87 = rgba(222,222,222,255);
	color_t grey87 = rgba(222,222,222,255);
	color_t gray88 = rgba(224,224,224,255);
	color_t grey88 = rgba(224,224,224,255);
	color_t gray89 = rgba(227,227,227,255);
	color_t grey89 = rgba(227,227,227,255);
	color_t gray90 = rgba(229,229,229,255);
	color_t grey90 = rgba(229,229,229,255);
	color_t gray91 = rgba(232,232,232,255);
	color_t grey91 = rgba(232,232,232,255);
	color_t gray92 = rgba(235,235,235,255);
	color_t grey92 = rgba(235,235,235,255);
	color_t gray93 = rgba(237,237,237,255);
	color_t grey93 = rgba(237,237,237,255);
	color_t gray94 = rgba(240,240,240,255);
	color_t grey94 = rgba(240,240,240,255);
	color_t gray95 = rgba(242,242,242,255);
	color_t grey95 = rgba(242,242,242,255);
	color_t gray96 = rgba(245,245,245,255);
	color_t grey96 = rgba(245,245,245,255);
	color_t gray97 = rgba(247,247,247,255);
	color_t grey97 = rgba(247,247,247,255);
	color_t gray98 = rgba(250,250,250,255);
	color_t grey98 = rgba(250,250,250,255);
	color_t gray99 = rgba(252,252,252,255);
	color_t grey99 = rgba(252,252,252,255);
	color_t gray100 = rgba(255,255,255,255);
	color_t grey100 = rgba(255,255,255,255);
	color_t dark_grey = rgba(169,169,169,255);
	color_t darkgrey = rgba(169,169,169,255);
	color_t dark_gray = rgba(169,169,169,255);
	color_t darkgray = rgba(169,169,169,255);
	color_t dark_blue = rgba(0,0,139,255);
	color_t darkblue = rgba(0,0,139,255);
	color_t dark_cyan = rgba(0,139,139,255);
	color_t darkcyan = rgba(0,139,139,255);
	color_t dark_magenta = rgba(139,0,139,255);
	color_t darkmagenta = rgba(139,0,139,255);
	color_t dark_red = rgba(139,0,0,255);
	color_t darkred = rgba(139,0,0,255);
	color_t light_green = rgba(144,238,144,255);
	color_t lightgreen = rgba(144,238,144,255);


};



namespace event {

	typedef enum {
		pressed = MLV_PRESSED, /**< \~french Le bouton est en position appuyée */
		released = MLV_RELEASED /**< \~french Le bouton est en position relachée */
	} button_state_t;

	typedef enum {
		none = MLV_NONE, /**< \~french Aucun évènement */
		key = MLV_KEY, /**< \~french  Evnènement provenant du clavier */
		input_box = MLV_INPUT_BOX, /**< \~french Évènement provenant de la validation d'un texte dans 
						 *   une boîte de saisie. */
		mouse_button = MLV_MOUSE_BUTTON, /**< \~french  Évènement provenant d'un clique de souris. */
		mouse_motion = MLV_MOUSE_MOTION /**< \~french  Évènement provenant du déplacement de la souris.*/
	} event_t;

	struct mouse_t {
		point_t position;
		button_state_t button;
		mouse_t():
			position(0,0), button(released)
		{ }
		mouse_t(
			const point_t & position, button_state_t button
		):
			position(position), button(button)
		{ }
	};

	struct keyboard_t {
		keyboard::key_t key;
		keyboard::modifier_t modifier;
		int unicode;
		keyboard_t(): 
			key(mlv::keyboard::none), modifier(mlv::keyboard::kmod_none), 
			unicode(0)
		{ }

		keyboard_t(
			keyboard::key_t key, keyboard::modifier_t modifier, int unicode
		): 
			key(key), modifier(modifier), unicode(unicode)
		{ }
	};

	struct input_box_t {
		std::string text;
		box::input_t* input_box;

		input_box_t():
			text(""), input_box(0)
		{}
	};

	struct event_data_t {
		mouse_t mouse;
		keyboard_t key;
		button_state_t button_state;
	};
};




/** \~french 
 * \brief Renvoie 0 ou 1 aléatoirement.
 *
 * \return 0 ou 1 aléatoirement.
 */
int random_boolean(){
	return MLV_get_random_boolean();
}

/** \~french 
 * \brief Renvoie un entier aléatoire choisi dans un intervalle donné en 
 *        paramètre.
 *
 * \param begin Borne inférieur de l'intervalle ( inclusif )
 * \param end Borne supérieur de l'intervalle ( inclusif )
 * \return  Un entier aléatoire choisi dans l'intervalle [begin, end].
 */
int random_integer(int begin, int end){
	return MLV_get_random_integer(begin, end);
}

/** \~french 
 * \brief Renvoie un réel aléatoire choisi dans un intervalle donné en 
 *        paramètre.
 *
 * \param begin Borne inférieur de l'intervalle ( inclusif )
 * \param end Borne supérieur de l'intervalle ( inclusif )
 * \return Un réel aléatoire choisi dans l'intervalle [begin, end].
 */
double random_double(double begin, double end){
	return MLV_get_random_double(begin, end);
}


typedef MLV_Color color_t;

namespace system {

int desktop_height( ){
	return MLV_get_desktop_height();
}
int desktop_width(){
	return MLV_get_desktop_width();
}

} // namespace system

void _copy_array( int ** vx, int **vy, const point_t* array, int nb_points ){
	*vx = new int[ nb_points ];
	*vy = new int[ nb_points ];
	for( int i = 0; i < nb_points; i++ ){
		(*vx)[i] = array[i].x;
		(*vy)[i] = array[i].y;
	}
}

void _free_array( int * vx, int *vy ){
	delete vx;
	delete vy;
}

class image_t {
	private:
		friend class window_t;
		MLV_Image * image;
		void _free(){
			if( image ){
				MLV_free_image( image );
			}
		}
	public:
		image_t(): image(0) {}
		image_t( const std::string & file_path ):
			image( MLV_load_image( file_path.c_str() ) )
		{ }
		image_t( unsigned int width, unsigned int height ):
			image( MLV_create_image( width, height ) )
		{ }
		image_t( const image_t & image ):
			image( ( image.image )? MLV_copy_image( image.image ): 0 )
		{ }
		image_t & operator=( const image_t& image ){
			if( this != &image ){
				_free();
				this->image = MLV_copy_image( image.image );
			}
			return *this;
		}
		#if __cplusplus >= 201100
		image_t( image_t && image ): image( image.image ) {
			image.image = 0;
		}
		image_t & operator=( image_t && image ){
			if( this != &image ){
				_free();
				this->image = image.image;
				image.image = 0;
			}
			return *this;
		}
		#endif
		~image_t(){
			_free();
		}

		/** \~french 
		 * \brief Retourne la largeur d'une image donnée.
		 *
		 * \return La largeur de l'image.
		 */
		int width() const {
			assert( image );
			return MLV_get_image_width( image );
		}

		/** \~french 
		 * \brief Retourne la hauteur d'une image donnée.
		 *
		 * \return La hauteur de l'image
		 */
		int height() const {
			assert( image );
			return MLV_get_image_height( image );
		}

		void set_alpha( MLV_Alpha alpha ){
			MLV_set_alpha_on_image( alpha, image );
		}

		/** \~french 
		 * \brief Redimensionne l'image en ne respectant pas les proportions de l'image
		 *        originale.
		 *
		 * La hauteur et la largeur de la nouvelle image deviennent respectivement la 
		 * hauteur et la largeur passées en paramètres.
		 *
		 * \param width La largeur de l'image.
		 * \param height La hauteur de l'image.
		 */
		void resize( int width, int height ){
			assert( image );
			MLV_resize_image( image, width, height );
		}

		/** \~french 
		 * \brief Modifie l'image en réalisant une réflexion horizontale.
		 */ 
		void horizontal_mirror(){
			MLV_horizontal_image_mirror( image );
		}

		/** \~french 
		 * \brief Modifie l'image en réalisant une réflexion verticale.
		 */ 
		void vertical_mirror(){
			MLV_vertical_image_mirror( image );
		}

		/** \~french 
		 * \brief Cette fonction redimensionne l'image en repsectant les proportions 
		 *        de l'image originale.
		 *
		 * L'image résultat est la plus grande image possible incluse dans le rectangle
		 * de largeur width et de hauteur height.
		 *
		 * L'utilisateur peut entrer un entier négatif pour les champs width et height.
		 * Ces champs ne sont alors pas pris en compte dans le redimensionnement de 
		 * l'image. Dans ce cas, si le paramètre width (resp. height) est 
		 * négatif, alors l'image finale aura pour largeur (resp. hauteur) la taille 
		 * spécifiée dans le paramètre width (resp. height).
		 *
		 * \param width La nouvelle largeur de l'image.
		 * \param height La nouvlle hauteur de l'image.
		 */ 
		void proportional_resize( int width, int height ){
			MLV_resize_image_with_proportions( image, width, height );
		}

		/** \~french 
		 * \brief Modifie l'image à l'aide d'une homotétie ( Étire l'image )
		 *
		 * \param scalar Coefficient de proportionalité de l'homotétie ( >1 l'image est
		 *               agrandie, <1 l'image est rétrécie ). 
		 */
		void scale( double scalar ){
			MLV_scale_image( image, scalar );
		}

		/** \~french 
		 * \brief Éffectue une rotation sur une image donnée.
		 *
		 * \param rotation L'angle de la rotation.
		 */
		void rotate( MLV_Image* image, double rotation ){
			MLV_rotate_image( image, rotation );
		}

		/** \~french 
		 * \brief Étire l'image suivant l'axe X et l'axe Y avec des coefficients de 
		 *        proportionnalité différents pour les deux axes.
		 *
		 * \param scalar_x Le coéfficient de proportionnalité de l'axe X.
		 * \param scalar_y Le coéfficient de proportionnalité de l'axe Y.
		 */
		void scale_xy( double scalar_x, double scalar_y ){
			MLV_scale_xy_image( image, scalar_x, scalar_y );
		}


		/** \~french 
		 * \brief Dessine un cercle à une position et un rayon spécifiés en paramètres.
		 **
		 * \param x La coordonnée en X du centre.
		 * \param y La coordonnée en Y du centre.
		 * \param radius Le rayon du cercle.
		 * \param color La couleur du tracé.
		 */
		void draw_circle(const point_t & point, int radius, color_t color){
			MLV_draw_circle_on_image(point.x, point.y, radius, color, image);
		}

		/** \~french 
		 * \brief Dessine un disque plein dont le centre et le rayon sont passés en 
		 *        paramètres.
		 *
		 * \param x La coordonnée en X du centre.
		 * \param y La coordonnée en Y du centre.
		 * \param radius Le rayon du cercle.
		 * \param color La couleur du tracé.
		 */
		void draw_filled_circle(const point_t & point, int radius, color_t color){
			MLV_draw_filled_circle_on_image(point.x, point.y, radius, color, image);
		}

		/** \~french 
		 * \brief Dessine une ellipse.
		 *
		 * \param x La coordonnée en X du centre de l'ellipse.
		 * \param y La coordonnée en Y du centre de l'ellipse.
		 * \param radius_x Le rayon en X de l'ellipse.
		 * \param radius_y Le rayon en Y de l'ellipse.
		 * \param color La couleur du tracé.
		 */
		void draw_ellipse(const point_t & point, int radius_x, int radius_y, color_t color){
			MLV_draw_ellipse_on_image(point.x, point.y, radius_x, radius_y, color, image);
		}

		/** \~french 
		 * \brief Dessine une ellipse pleine.
		 *
		 * \param x La coordonnée en X du centre de l'ellipse.
		 * \param y La coordonnée en Y du centre de l'ellipse.
		 * \param radius_x Le rayon en X de l'ellipse.
		 * \param radius_y Le rayon en Y de l'ellipse.
		 * \param color La couleur du tracé.
		 */
		void draw_filled_ellipse(const point_t & point, int radius_x, int radius_y, color_t color){
			MLV_draw_filled_ellipse_on_image(point.x, point.y, radius_x, radius_y, color, image);
		}

		/** \~french 
		 * \brief Dessine un polygone à partir d'une liste de sommets.
		 *
		 * \param vx La liste des coordonnées en X des différents sommets du polygone.
		 * \param vy La liste des coordonnées en Y des différents sommets du polygone.
		 * \param nb_points Le nombre de sommets du polygone.
		 * \param color La couleur du tracé.
		 */
		void draw_polygon(const point_t * array, int nb_points, color_t color){
			int *vx, *vy;
			_copy_array( &vx, &vy, array, nb_points );
			MLV_draw_polygon_on_image(vx, vy, nb_points, color, image);
			_free_array( vx, vy );
		}

#ifndef MLV_202
		/** \~french 
		 * \brief Dessine un triangle (vide).
		 *
		 * \param ax La coordonnée en X du premier point du triangle.
		 * \param ay La coordonnée en Y dy premier point du traingle.
		 * \param bx La coordonnée en X du deuxième point du triangle.
		 * \param by La coordonnée en Y dy deuxième point du traingle.
		 * \param cx La coordonnée en X du troisième point du triangle.
		 * \param cy La coordonnée en Y dy troisième point du traingle.
		 * \param color La couleur du triangle.
		 */
		void draw_triangle(int ax, int ay, int bx, int by, int cx, int cy, color_t color){
			MLV_draw_triangle_on_image(ax, ay, bx, by, cx, cy, color, image);
		}
#endif 

		/** \~french 
		 * \brief Dessine un polygone plein à partir d'une liste de sommets.
		 *
		 * \param vx La liste des coordonnées en X des différents sommets du polygone.
		 * \param vy La liste des coordonnées en Y des différents sommets du polygone.
		 * \param nb_points Le nombre de sommets du polygone.
		 * \param color La couleur du tracé.
		 */
		void draw_filled_polygon(const point_t * array, int nb_points, color_t color){
			int *vx, *vy;
			_copy_array( &vx, &vy, array, nb_points );
			MLV_draw_filled_polygon_on_image(vx, vy, nb_points, color, image);
			_free_array( vx, vy );
		}

#ifndef MLV_202
		/** \~french 
		 * \brief Dessine un triangle plein.
		 *
		 * \param ax La coordonnée en X du premier point du triangle.
		 * \param ay La coordonnée en Y dy premier point du traingle.
		 * \param bx La coordonnée en X du deuxième point du triangle.
		 * \param by La coordonnée en Y dy deuxième point du traingle.
		 * \param cx La coordonnée en X du troisième point du triangle.
		 * \param cy La coordonnée en Y dy troisième point du traingle.
		 * \param color La couleur du triangle.
		 */
		void draw_filled_triangle(int ax, int ay, int bx, int by, int cx, int cy, color_t color){
			MLV_draw_filled_triangle_on_image(ax, ay, bx, by, cx, cy, color, image);
		}
#endif 


		/** \~french 
		 * \brief Dessine une courbe de Bézier à partir d'une liste de sommets.
		 *
		 * \param vx La liste des coordonnées en X des différents sommets de la courbe.
		 * \param vy La liste des coordonnées en Y des différents sommets de la courbe.
		 * \param nb_points Le nombre de sommets disponibles pour dessiner la courbe de 
		 *                Bézier.
		 * \param color La couleur du tracé.
		 */
		void draw_bezier_curve(const point_t * array,  int nb_points, color_t color){
			int *vx, *vy;
			_copy_array( &vx, &vy, array, nb_points );
			MLV_draw_bezier_curve_on_image(vx, vy, nb_points, color, image);
			_free_array( vx, vy );
		}

		/** \~french 
		 * \brief Dessine un rectangle dont la taille, la couleur et la position du 
		 *        sommet Nord-Ouest sont données en paramètres.
		 *
		 * \param x La coordonnée en X du sommet Nord-Ouest du rectangle.
		 * \param y La coordonnée en Y du sommet Nord-Ouest du rectangle.
		 * \param width La largeur du rectangle.
		 * \param height La hauteur du rectangle.
		 * \param color La couleur du tracé.
		 */
		void draw_rectangle(const point_t & point, int width, int height, color_t color){
			MLV_draw_rectangle_on_image(point.x, point.y, width, height, color, image);
		}

		/** \~french 
		 * \brief Dessine un rectangle plein dont la taille, la couleur et la position 
		 *        du sommet Nord-Ouest sont données en paramètres.
		 *
		 * \param x La coordonnée en X du sommet Nord-Ouest du rectangle.
		 * \param y La coordonnée en Y du sommet Nord-Ouest du rectangle.
		 * \param width La largeur du rectangle.
		 * \param height La hauteur du rectangle.
		 * \param color La couleur du tracé.
		 */
		void draw_filled_rectangle(const point_t & point, int width, int height, color_t color){
			MLV_draw_filled_rectangle_on_image(point.x, point.y, width, height, color, image);
		}

		/** \~french 
		 * \brief Dessine une ligne.
		 *
		 * \param x1 La coordonnée en X de la première extrémité de la ligne.
		 * \param y1 La coordonnée en Y de la première extrémité de la ligne.
		 * \param x2 La coordonnée en X de la deuxième extrémité de la ligne.
		 * \param y2 La coordonnée en Y de la deuxième extrémité de la ligne.
		 * \param color La couleur du tracé.
		 */
		void draw_line(const point_t & point_1, const point_t & point_2, color_t color){
			MLV_draw_line_on_image(point_1.x, point_1.y, point_2.x, point_2.y, color, image);
		}

		/** \~french 
		 * \brief Dessine un pixel dont les coordonnées sont passées en paramètres.
		 *
		 * \param x La coordonnée en X du pixel.
		 * \param y La coordonnée en Y du pixel.
		 * \param color La couleur du tracé.
		 */
		void draw_pixel(const point_t & point, color_t color){
			MLV_draw_pixel_on_image(point.x, point.y, color, image);
		}

		/** \~french 
		 * \brief Dessine un point dont les coordonnées sont passées en paramètres.
		 *        Cette fonction est identique à MLV_draw_pixel.
		 *
		 * \param x La coordonnée en X du point.
		 * \param y La coordonnée en Y du point.
		 * \param color La couleur du tracé.
		 */
		void draw_point(const point_t & point, color_t color){
			MLV_draw_point_on_image(point.x, point.y, color, image);
		}

};


class music_t {
	public:
		music_t( const std::string & music_path ):
			mlv_music( MLV_load_music(music_path.c_str()) )
		{ }

		~music_t(){
			MLV_free_music( mlv_music );
		}

	private:
		MLV_Music* mlv_music;
		friend class audio_center_t;

};

class sound_t {
	public:
		sound_t( const std::string & sound_path ):
			mlv_sound( MLV_load_sound(sound_path.c_str()) )
		{ }

		~sound_t(){
			MLV_free_sound( mlv_sound );
		}

	private:
		MLV_Sound* mlv_sound;
		friend class audio_center_t;

};

class audio_center_t {
	public:
		audio_center_t(): state( MLV_init_audio() ) { }

		~audio_center_t(){ 
			if( is_valid() ){
				MLV_free_audio();
			}
		}

		void play_music( const music_t & music, float volume, int loop ){
			MLV_play_music( music.mlv_music, volume, loop );
		}

		void play_sound( const sound_t & sound, float volume ){
			MLV_play_sound( sound.mlv_sound, volume );
		}

		void stop_all_sounds(){
			MLV_stop_all_sounds();
		}

		void stop_music(){
			MLV_stop_music();
		}

		bool is_valid(){
			return state == 0;
		}

	private:
		int state;

};

class window_t {
	public:
		window_t(
			const std::string & window_name, const std::string & icon_name, 
			unsigned int width, unsigned int height
		){
			MLV_create_window(
				window_name.c_str(), icon_name.c_str(), width, height  
			);
		}
		window_t(
			const std::string & window_name, const std::string & icon_name, 
			unsigned int width, unsigned int height,
			const std::string & path_to_font, unsigned int size_font
		){
			MLV_create_window_with_default_font(
				window_name.c_str(), icon_name.c_str(), width, height,
				path_to_font.c_str(), size_font
			);
		}
		~window_t() {
			MLV_free_window();
		}
		void set_font(
			const std::string & path_to_font, unsigned int size_font 
		){
			MLV_change_default_font( path_to_font.c_str(), size_font );
		}
		void set_full_screen( bool full_screen ){
			if( full_screen ){
				MLV_enable_full_screen();
			}else{
				MLV_disable_full_screen();
			}
		}
		void resize( unsigned int width, unsigned int height ){
			MLV_change_window_size( width, height );
		}
		void set_caption(
			const std::string & window_name, const std::string & icon_name
		){
			MLV_change_window_caption(window_name.c_str(), icon_name.c_str());
		}
		bool full_screen( ) const {
			return MLV_is_full_screen() != 0;
		}
		void update(){
			MLV_update_window();
		}
		int width() const {
			return MLV_get_window_height( );
		}
		int height() const {
			return MLV_get_window_width( );
		}
		void clear( color_t color ){
			MLV_clear_window( color );
		}

		void draw( const image_t& image, const point_t & point){
			MLV_draw_image( image.image, point.x, point.y );
		}
		void partial_draw( 
			const image_t& image, const point_t & position,
			const point_t & top_left, int width, int height 
		){
			MLV_draw_partial_image(
				image.image, top_left.x, top_left.y, width, height, 
				position.x, position.y 
			);
		}


		/** \~french 
		 * \brief Dessine un cercle à une position et un rayon spécifiés en paramètres.
		 **
		 * \param x La coordonnée en X du centre.
		 * \param y La coordonnée en Y du centre.
		 * \param radius Le rayon du cercle.
		 * \param color La couleur du tracé.
		 */
		void draw_circle( const point_t & point, int radius, MLV_Color color){
			MLV_draw_circle( point.x, point.y, radius, color);
		}

		/** \~french 
		 * \brief Dessine un disque plein dont le centre et le rayon sont passés en 
		 *        paramètres.
		 *
		 * \param x La coordonnée en X du centre.
		 * \param y La coordonnée en Y du centre.
		 * \param radius Le rayon du cercle.
		 * \param color La couleur du tracé.
		 */
		void draw_filled_circle( const point_t & point, int radius, MLV_Color color){
			MLV_draw_filled_circle( point.x, point.y, radius, color);
		}

		/** \~french 
		 * \brief Dessine une ellipse.
		 *
		 * \param x La coordonnée en X du centre de l'ellipse.
		 * \param y La coordonnée en Y du centre de l'ellipse.
		 * \param radius_x Le rayon en X de l'ellipse.
		 * \param radius_y Le rayon en Y de l'ellipse.
		 * \param color La couleur du tracé.
		 */
		void draw_ellipse(const point_t & point, int radius_x, int radius_y, MLV_Color color){
			MLV_draw_ellipse( point.x, point.y, radius_x, radius_y, color);
		}

		/** \~french 
		 * \brief Dessine une ellipse pleine.
		 *
		 * \param x La coordonnée en X du centre de l'ellipse.
		 * \param y La coordonnée en Y du centre de l'ellipse.
		 * \param radius_x Le rayon en X de l'ellipse.
		 * \param radius_y Le rayon en Y de l'ellipse.
		 * \param color La couleur du tracé.
		 */
		void draw_filled_ellipse(const point_t & point, int radius_x, int radius_y, MLV_Color color){
			MLV_draw_filled_ellipse( point.x, point.y, radius_x, radius_y, color);
		}

		/** \~french 
		 * \brief Dessine un polygone à partir d'une liste de sommets.
		 *
		 * \param vx La liste des coordonnées en X des différents sommets du polygone.
		 * \param vy La liste des coordonnées en Y des différents sommets du polygone.
		 * \param nb_points Le nombre de sommets du polygone.
		 * \param color La couleur du tracé.
		 */
		void draw_polygon(const point_t* array, int nb_points, MLV_Color color){
			int *vx, *vy;
			_copy_array( &vx, &vy, array, nb_points );
			MLV_draw_polygon( vx,  vy, nb_points, color);
			_free_array( vx, vy );
		}

#ifndef MLV_202
		/** \~french 
		 * \brief Dessine un triangle (vide).
		 *
		 * \param ax La coordonnée en X du premier point du triangle.
		 * \param ay La coordonnée en Y dy premier point du traingle.
		 * \param bx La coordonnée en X du deuxième point du triangle.
		 * \param by La coordonnée en Y dy deuxième point du traingle.
		 * \param cx La coordonnée en X du troisième point du triangle.
		 * \param cy La coordonnée en Y dy troisième point du traingle.
		 * \param color La couleur du triangle.
		 */
		void draw_triangle(int ax, int ay, int bx, int by, int cx, int cy, MLV_Color color){
			MLV_draw_triangle( ax, ay, bx, by, cx, cy, color);
		}
#endif

		/** \~french 
		 * \brief Dessine un polygone plein à partir d'une liste de sommets.
		 *
		 * \param vx La liste des coordonnées en X des différents sommets du polygone.
		 * \param vy La liste des coordonnées en Y des différents sommets du polygone.
		 * \param nb_points Le nombre de sommets du polygone.
		 * \param color La couleur du tracé.
		 */
		void draw_filled_polygon(const point_t* array, int nb_points, MLV_Color color){
			int *vx, *vy;
			_copy_array( &vx, &vy, array, nb_points );
			MLV_draw_filled_polygon( vx,  vy, nb_points, color);
			_free_array( vx, vy );
		}

#ifndef MLV_202
		/** \~french 
		 * \brief Dessine un triangle plein.
		 *
		 * \param ax La coordonnée en X du premier point du triangle.
		 * \param ay La coordonnée en Y dy premier point du traingle.
		 * \param bx La coordonnée en X du deuxième point du triangle.
		 * \param by La coordonnée en Y dy deuxième point du traingle.
		 * \param cx La coordonnée en X du troisième point du triangle.
		 * \param cy La coordonnée en Y dy troisième point du traingle.
		 * \param color La couleur du triangle.
		 */
		void draw_filled_triangle(int ax, int ay, int bx, int by, int cx, int cy, MLV_Color color){
			MLV_draw_filled_triangle( ax, ay, bx, by, cx, cy, color);
		}
#endif

		/** \~french 
		 * \brief Dessine une courbe de Bézier à partir d'une liste de sommets.
		 *
		 * \param vx La liste des coordonnées en X des différents sommets de la courbe.
		 * \param vy La liste des coordonnées en Y des différents sommets de la courbe.
		 * \param nb_points Le nombre de sommets disponibles pour dessiner la courbe de 
		 *                Bézier.
		 * \param color La couleur du tracé.
		 */
		void draw_bezier_curve(const point_t* array, int nb_points, MLV_Color color){
			int *vx, *vy;
			_copy_array( &vx, &vy, array, nb_points );
			MLV_draw_bezier_curve( vx,  vy, nb_points, color);
			_free_array( vx, vy );
		}

		/** \~french 
		 * \brief Dessine un rectangle dont la taille, la couleur et la position du 
		 *        sommet Nord-Ouest sont données en paramètres.
		 *
		 * \param x La coordonnée en X du sommet Nord-Ouest du rectangle.
		 * \param y La coordonnée en Y du sommet Nord-Ouest du rectangle.
		 * \param width La largeur du rectangle.
		 * \param height La hauteur du rectangle.
		 * \param color La couleur du tracé.
		 */
		void draw_rectangle(const point_t & point, int width, int height, MLV_Color color){
			MLV_draw_rectangle( point.x, point.y, width, height, color);
		}

		/** \~french 
		 * \brief Dessine un rectangle plein dont la taille, la couleur et la position 
		 *        du sommet Nord-Ouest sont données en paramètres.
		 *
		 * \param x La coordonnée en X du sommet Nord-Ouest du rectangle.
		 * \param y La coordonnée en Y du sommet Nord-Ouest du rectangle.
		 * \param width La largeur du rectangle.
		 * \param height La hauteur du rectangle.
		 * \param color La couleur du tracé.
		 */
		void draw_filled_rectangle(const point_t & point, int width, int height, MLV_Color color){
			MLV_draw_filled_rectangle( point.x, point.y, width, height, color);
		}

		/** \~french 
		 * \brief Dessine une ligne.
		 *
		 * \param x1 La coordonnée en X de la première extrémité de la ligne.
		 * \param y1 La coordonnée en Y de la première extrémité de la ligne.
		 * \param x2 La coordonnée en X de la deuxième extrémité de la ligne.
		 * \param y2 La coordonnée en Y de la deuxième extrémité de la ligne.
		 * \param color La couleur du tracé.
		 */
		void draw_line(const point_t & point_1, const point_t & point_2, MLV_Color color){
			MLV_draw_line( point_1.x, point_1.y, point_2.x, point_2.y, color);
		}

		/** \~french 
		 * \brief Dessine un pixel dont les coordonnées sont passées en paramètres.
		 *
		 * \param x La coordonnée en X du pixel.
		 * \param y La coordonnée en Y du pixel.
		 * \param color La couleur du tracé.
		 */
		void draw_pixel(const point_t & point, MLV_Color color){
			MLV_draw_pixel( point.x, point.y, color);
		}

		/** \~french 
		 * \brief Dessine un point dont les coordonnées sont passées en paramètres.
		 *        Cette fonction est identique à MLV_draw_pixel.
		 *
		 * \param x La coordonnée en X du point.
		 * \param y La coordonnée en Y du point.
		 * \param color La couleur du tracé.
		 */
		void draw_point(const point_t & point, MLV_Color color){
			MLV_draw_point( point.x, point.y, color);
		}


		/** \~french 
		 * \brief Imprime un texte donné à une position et une couleur données.
		 * 
		 * Le texte est imprimé à l'aide de la fonte de caractères par default de la 
		 * bibliothèque MLV.
		 *
		 * \param x Coordonnée en X du coin Nord-Ouest du texte
		 * \param y Coordonnée en Y du coin Nord-Ouest du texte
		 * \param text texte à afficher
		 * \param color couleur du tracé
		 */
		void draw_text( const point_t & point, const std::string & text, MLV_Color color ){
			MLV_draw_text( point.x, point.y, text.c_str(), color );
		}

		/** \~french 
		 * \brief Le programme s'intérompt pendant un nombre de secondes.
		 *
		 * \param seconds Le nombre de secondes à attendre.
		 */
		void wait_seconds( int seconds ){
			MLV_wait_seconds(seconds);
		}

		/** \~french 
		 * \brief Le programme s'intérompt pendant un nombre de milli-secondes donné 
		 *        en paramètre.
		 *
		 * \param milliseconds Le nombre de milli-secondes à attendre.
		 */
		void wait_milliseconds( int milliseconds ){
			MLV_wait_milliseconds(milliseconds);
		}

		/** \~french 
		 *
		 * \brief Suspend l'exécution jusqu'à ce que l'utilisateur clique sur le bouton
		 *        gauche de la souris.
		 *
		 * Au moment où l'utilisateur clique, la fonction retourne les
		 * coordonnées de la position de la souris dans la fenêtre.
		 *
		 * \param x Coordonnée en X de la position de la souris dans la fenêtre.
		 * \param y Coordonnée en Y de la position de la souris dans la fenêtre.
		 */
		void wait_mouse( mlv::point_t & point ){
			MLV_wait_mouse(&point.x, &point.y);
		}

		/** \~french 
		 *
		 * \brief Suspend l'exécution jusqu'à ce que l'utilisateur clique sur le bouton
		 *        gauche de la souris.
		 *
		 * Au moment où l'utilisateur clique, la fonction retourne les
		 * coordonnées de la position de la souris dans la fenêtre.
		 *
		 * \return Le point où se situe la souris
		 */
		point_t wait_mouse(){
			point_t point;
			wait_mouse( point );
			return point;
		}

		/** \~french 
		 * \brief Suspend l'exécution jusqu'à ce que l'utilisateur appuie sur une touche
		 *        du  clavier.
		 * 
		 * Lorsque l'utilisateur appuie sur une touche, la fonction remplit le contenu 
		 * des trois paramètres key, modifier et unicode correspondant respectivement au 
		 * code de la touche, au mode dans lequel se trouve le clavier 
		 * (majuscule etc ...) et au caractère unicode obtenu en combinant le mode du 
		 * clavier et le code de la touche appuyée.
		 *
		 * La fonction accepte des valeurs nulles pour les pointeurs key, modifier et 
		 * unicode.
		 * Dans ce cas la fonction ignore les champs en questions.
		 *
		 * \bug Voir les bugs de la fonction MLV_get_event().
		 *
		 * \param key        Le code de la touche.
		 * \param modifier   Le mode dans lequel se trouve le clavier.
		 * \param unicode    Le caractère codé en unicode de la lettre obtenue en combinant
		 *                   le code et le mode précédent.
		 */
		void wait_keyboard( event::keyboard_t & keyboard ){
			MLV_wait_keyboard(
				(MLV_Keyboard_button*) &(keyboard.key), 
				(MLV_Keyboard_modifier*) &(keyboard.modifier),
				&(keyboard.unicode)
			);
		}

		mlv::event::event_t wait_keyboard_or_mouse(
			event::keyboard_t & keyboard, point_t & mouse_position
		){
			return (mlv::event::event_t) MLV_wait_keyboard_or_mouse(
				(MLV_Keyboard_button*) &(keyboard.key), 
				(MLV_Keyboard_modifier*) &(keyboard.modifier),
				&(keyboard.unicode),
				&(mouse_position.x), &(mouse_position.y)
			);
		}

		mlv::event::event_t wait_keyboard_or_mouse_or_seconds(
			event::keyboard_t & keyboard, point_t & mouse_position, int time
		){
			return (mlv::event::event_t) MLV_wait_keyboard_or_mouse_or_seconds(
				(MLV_Keyboard_button*) &(keyboard.key), 
				(MLV_Keyboard_modifier*) &(keyboard.modifier),
				&(keyboard.unicode),
				&(mouse_position.x), &(mouse_position.y),
				time
			);
		}

#ifndef MLV_202
		mlv::event::event_t wait_keyboard_or_mouse_or_milliseconds(
			event::keyboard_t & keyboard, point_t & mouse_position, int time
		){
			return (mlv::event::event_t) MLV_wait_keyboard_or_mouse_or_milliseconds(
				(MLV_Keyboard_button*) &(keyboard.key), 
				(MLV_Keyboard_modifier*) &(keyboard.modifier),
				&(keyboard.unicode),
				&(mouse_position.x), &(mouse_position.y),
				time
			);
		}

		mlv::event::event_t wait_input_box_or_milliseconds(
			const mlv::box::input_t & input_box,
			std::string & text, int time
		){
			char* tmp_text = 0;
			MLV_Event event = MLV_wait_input_box_or_milliseconds(
				time,
				input_box.top_left_corner.x,
				input_box.top_left_corner.y,
				input_box.width,
				input_box.height,
				input_box.borderColor,
				input_box.textColor,
				input_box.backgroundColor,
				input_box.informativeMessage.c_str(),
				&tmp_text
			);
			if( event == MLV_INPUT_BOX ){
				text = tmp_text;
				free(tmp_text);
			}

			return (mlv::event::event_t) event;
		}

		mlv::event::event_t wait_input_box_or_seconds(
			const mlv::box::input_t & input_box,
			std::string & text, int time
		){
			return wait_input_box_or_milliseconds(
				input_box, text, time*1000
			);
		}
#endif



		event::keyboard_t wait_keyboard(){
			event::keyboard_t keyboard;
			wait_keyboard( keyboard );
			return keyboard;
		}

		event::event_t wait_keyboard_or_seconds(
			event::keyboard_t & keyboard, int time 
		){
			return (event::event_t) MLV_wait_keyboard_or_seconds(
				(MLV_Keyboard_button*) &(keyboard.key), 
				(MLV_Keyboard_modifier*) &(keyboard.modifier),
				&(keyboard.unicode),
				time
			);
		}

		event::event_t wait_mouse_or_seconds( point_t& mouse_position, int time ){
			return (event::event_t) MLV_wait_mouse_or_seconds(
				&(mouse_position.x), &(mouse_position.y), time 
			);
		}

		std::string wait_input_box( const mlv::box::input_t & input_box ){
			std::string text;

			char* tmp_text;
			MLV_wait_input_box(
				input_box.top_left_corner.x,
				input_box.top_left_corner.y,
				input_box.width,
				input_box.height,
				input_box.borderColor,
				input_box.textColor,
				input_box.backgroundColor,
				input_box.informativeMessage.c_str(),
				&tmp_text
			);
			text = tmp_text;
			free(tmp_text);

			return text;
		}


		void draw_text_box( const mlv::box::text_t & text_box ){
			if( text_box.adapted_text ){
				MLV_draw_adapted_text_box(
					text_box.adapted_text->position.x,
					text_box.adapted_text->position.y,
					text_box.adapted_text->message.c_str(),
					text_box.adapted_text->sizeInterligne,
					text_box.adapted_text->borderColor,
					text_box.adapted_text->textColor,
					text_box.adapted_text->backgroundColor,
					(MLV_Text_justification) text_box.adapted_text->text_justification
				);
			}else if(text_box.fixed_text ){
				MLV_draw_text_box(
					text_box.fixed_text->position.x,
					text_box.fixed_text->position.y,
					text_box.fixed_text->width,
					text_box.fixed_text->height,
					text_box.fixed_text->message.c_str(),
					text_box.fixed_text->sizeInterligne,
					text_box.fixed_text->borderColor,
					text_box.fixed_text->textColor,
					text_box.fixed_text->backgroundColor,
					(MLV_Text_justification) text_box.fixed_text->text_justification,
					(MLV_Horizontal_position) text_box.fixed_text->horizontal_position,
					(MLV_Vertical_position) text_box.fixed_text->vertical_position
				);
			}else{
				std::cerr << "Error : text_box is empty." << std::endl;
				assert( true );
			}
		}

		#ifndef MLV_202
		void show_leonardo(){
			MLV_show_leonardo();
		}

		void set_leonardo_color( mlv::color_t color ){
			MLV_leonardo_color( color );
		}

		// Time in millisecond
		void set_leonardo_speed( int time ){
			MLV_leonardo_speed( time );
		}

		void leonardo_go_to( const point_t & point ){
			MLV_leonardo_go_to( point.x, point.y );
		}

		// Angle en degrés
		void leonardo_orient_to(double angle){
			MLV_leonardo_orient_to(angle);
		}

		void leonardo_write( bool boolean ){
			MLV_leonardo_write( boolean ? 1 : 0 );
		}

		void leonardo_forward( float distance ){
			MLV_leonardo_forward( distance );
		}
	
		void leonardo_left( double angle ){
			MLV_leonardo_left( angle );
		}

		void leonardo_right( double angle ){
			MLV_leonardo_right( angle );
		}

		#endif


	};

} // namespace mlv

