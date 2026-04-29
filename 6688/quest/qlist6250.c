#include <ansi.h>
inherit SKILL;

mapping *quest = ({
	([	"quest":	"黑衣人",
		"quest_type":	"杀",
		"exp_bonus":	40,
		"shen_type":	-1,
	]),

	([	"quest":	"飞刀",
		"quest_type":	"寻",
		"exp_bonus":	40,
		"shen_type":	-1,
	]),

	([	"quest":	"化尸粉",
		"quest_type":	"寻",
		"exp_bonus":	40,
		"shen_type":	-1,
	]),

	([	"quest":	"衙役",
		"quest_type":	"杀",
		"exp_bonus":	40,
		"shen_type":	1,
	]),

	([	"quest":	"衙役服",
		"quest_type":	"寻",
		"exp_bonus":	40,
		"shen_type":	1,
	]),

	([	"quest":	"蓝衣家丁",
		"quest_type":	"杀",
		"exp_bonus":	40,
		"shen_type":	-1,
	]),

	([	"quest":	"七星锤",
		"quest_type":	"寻",
		"exp_bonus":	40,
		"shen_type":	-1,
	]),

	([	"quest":	"宝官",
		"quest_type":	"杀",
		"exp_bonus":	40,
		"shen_type":	0,
	]),

	([	"quest":	"[31m李师师[2;37;0m",
		"quest_type":	"杀",
		"exp_bonus":	40,
		"shen_type":	0,
	]),

	([	"quest":	"[30m甜儿[2;37;0m",
		"quest_type":	"杀",
		"exp_bonus":	40,
		"shen_type":	0,
	]),

	([	"quest":	"[33m穆念慈[2;37;0m",
		"quest_type":	"杀",
		"exp_bonus":	40,
		"shen_type":	0,
	]),

	([	"quest":	"土匪喽罗",
		"quest_type":	"杀",
		"exp_bonus":	40,
		"shen_type":	-1,
	]),

	([	"quest":	"杨掌柜",
		"quest_type":	"杀",
		"exp_bonus":	40,
		"shen_type":	0,
	]),

	([	"quest":	"虚通",
		"quest_type":	"杀",
		"exp_bonus":	40,
		"shen_type":	1,
	]),

	([	"quest":	"黄布袈裟",
		"quest_type":	"寻",
		"exp_bonus":	40,
		"shen_type":	1,
	]),

	([	"quest":	"[35m苗心儿[2;37;0m",
		"quest_type":	"杀",
		"exp_bonus":	40,
		"shen_type":	1,
	]),

	([	"quest":	"地保",
		"quest_type":	"杀",
		"exp_bonus":	40,
		"shen_type":	1,
	]),

	([	"quest":	"紫衣家丁",
		"quest_type":	"杀",
		"exp_bonus":	40,
		"shen_type":	-1,
	]),

	([	"quest":	"八楞玄铁锤",
		"quest_type":	"寻",
		"exp_bonus":	40,
		"shen_type":	-1,
	]),

	([	"quest":	"牧羊女",
		"quest_type":	"杀",
		"exp_bonus":	40,
		"shen_type":	0,
	]),

	([	"quest":	"羊毛裙",
		"quest_type":	"寻",
		"exp_bonus":	40,
		"shen_type":	0,
	]),

	([	"quest":	"牧羊鞭",
		"quest_type":	"寻",
		"exp_bonus":	40,
		"shen_type":	0,
	]),

	([	"quest":	"大绵羊",
		"quest_type":	"杀",
		"exp_bonus":	40,
		"shen_type":	0,
	]),

	([	"quest":	"趟子手",
		"quest_type":	"杀",
		"exp_bonus":	40,
		"shen_type":	0,
	]),

	([	"quest":	"游方和尚",
		"quest_type":	"杀",
		"exp_bonus":	40,
		"shen_type":	1,
	]),

	([	"quest":	"长刀",
		"quest_type":	"寻",
		"exp_bonus":	40,
		"shen_type":	0,
	]),

	([	"quest":	"花针",
		"quest_type":	"寻",
		"exp_bonus":	40,
		"shen_type":	0,
	]),

	([	"quest":	"青布僧衣",
		"quest_type":	"寻",
		"exp_bonus":	40,
		"shen_type":	1,
	]),

	([	"quest":	"美珊",
		"quest_type":	"杀",
		"exp_bonus":	40,
		"shen_type":	0,
	]),

	([	"quest":	"惜春",
		"quest_type":	"杀",
		"exp_bonus":	40,
		"shen_type":	0,
	]),

	([	"quest":	"青布袈裟",
		"quest_type":	"寻",
		"exp_bonus":	40,
		"shen_type":	-1,
	]),

	([	"quest":	"杨莲亭",
		"quest_type":	"杀",
		"exp_bonus":	40,
		"shen_type":	-1,
	]),

	([	"quest":	"打铁僧",
		"quest_type":	"杀",
		"exp_bonus":	40,
		"shen_type":	1,
	]),

	([	"quest":	"丝衣",
		"quest_type":	"寻",
		"exp_bonus":	40,
		"shen_type":	-1,
	]),

	([	"quest":	"尹志平",
		"quest_type":	"杀",
		"exp_bonus":	40,
		"shen_type":	1,
	]),

	([	"quest":	"阿美",
		"quest_type":	"杀",
		"exp_bonus":	40,
		"shen_type":	1,
	]),

	([	"quest":	"女流氓",
		"quest_type":	"杀",
		"exp_bonus":	40,
		"shen_type":	-1,
	]),

	([	"quest":	"宫女",
		"quest_type":	"杀",
		"exp_bonus":	40,
		"shen_type":	1,
	]),

});

mapping quest_one =
        ([      "quest":        "烤鸡腿",
                "quest_type":   "寻",
                "exp_bonus":    30,
                "shen_type":    0,
        ]);

mapping query_quest()
{
        object room;

        if( random(4) )
        {
                room = "/adm/daemons/dynamicd"->get_random_room_npc();
                if( objectp(room) )
                {
                        if( room->is_character() )
                        {
                                quest_one["quest"] = room->query("name");
                                quest_one["quest_type"] = "寻人";
                        }
                        else
                        {
                                quest_one["quest"] = room->query("short");
                                quest_one["quest_type"] = "探路";
                        }
                        quest_one["exact"] = base_name(room);
                        return quest_one;
                }
        }
        else
                return quest[random(sizeof(quest))];
}
