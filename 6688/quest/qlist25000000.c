#include <ansi.h>
inherit SKILL;

mapping *quest = ({
	([	"quest":	"[1;34m殷开山[2;37;0m",
		"quest_type":	"杀",
		"exp_bonus":	160,
		"shen_type":	-1,
	]),
	([	"quest":	"[1;33m不痴大师[2;37;0m",
		"quest_type":	"杀",
		"exp_bonus":	160,
		"shen_type":	-1,
	]),
	
	([	"quest":	"刘麻子",
		"quest_type":	"杀",
		"exp_bonus":	160,
		"shen_type":	0,
	]),
	
	([	"quest":	"凤凰",
		"quest_type":	"杀",
		"exp_bonus":	160,
		"shen_type":	-1,
	]),

	([	"quest":	"人灵「区冥」",
		"quest_type":	"杀",
		"exp_bonus":	160,
		"shen_type":	1,
	]),
	
	([	"quest":	"达摩老祖",
		"quest_type":	"杀",
		"exp_bonus":	160,
		"shen_type":	1,
	]),
	([	"quest":	"风清扬",
		"quest_type":	"杀",
		"exp_bonus":	160,
		"shen_type":	1,
	]),
	([	"quest":	"张无忌",
		"quest_type":	"杀",
		"exp_bonus":	160,
		"shen_type":	1,
	]),
	([	"quest":	"圆真",
		"quest_type":	"杀",
		"exp_bonus":	160,
		"shen_type":	1,
	]),
	([	"quest":	"成昆",
		"quest_type":	"杀",
		"exp_bonus":	160,
		"shen_type":	1,
	]),

	([	"quest":	"萧峰",
		"quest_type":	"杀",
		"exp_bonus":	160,
		"shen_type":	0,
	]),

});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
